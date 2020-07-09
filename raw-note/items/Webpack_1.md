## Webpack official document - Concepts
### [Website resource](https://webpack.js.org/concepts/), Webpack

------------------

第一章 - Concepts

第二章 - Entry Points

第三章 - Output

第四章 - Loaders

第五章 - Plugins

第六章 - Configuration

第七章 - Modules

第八章 - Module Resolution

第九章 - Module Federation

第十章 - Dependency Graph

第十一章 - Targets

第十二章 - The Manifest

第十三章 - Hot Module Replacement

第十四章 - Why webpack

第十五章 - Under The Hood


------------------


### 第一章 - Concepts
  * static module bundler
  * 為所有的資源生成 dependency graph 並且生產出一個或多個打包過後的 bundle

#### Entry
  * 進入點, 預設是 `./src/index.js`
  * 通過 config 設定
    ```javascript
    module.exports = {
      entry: './path/to/my/entry/file.js'
    };
    ```

#### Output
  * 輸出 bundle, 預設是 `./dist/main.js`
  * 通過 config 設定
    ```javascript
    const path = require('path');

    module.exports = {
      output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'my-first-webpack.bundle.js'
      }
    };
    ```

#### Loaders
  * 預設的 JavaScript module 只認識 js 檔案
  * Webpack 通過 loaders 擴充 module 模式允許任意的檔案資源被納入 dependency graph 與 bundle，例如 css, images, ...
  * config 設置,
    * `test`, 要轉換的檔案, 使用 regex 或 string 指定
    * `use`, 使用的 loader
    ```javascript
    module.exports = {
      module: {
        rules: [
          { test: /\.txt$/, use: 'raw-loader' }
        ]
      }
    };
    ```

#### Plugins
  * 其他功能擴充, 例如 optimization, uglify, minify, ...
  * `require()` + `new`
  * config 設置,
    ```javascript
    const HtmlWebpackPlugin = require('html-webpack-plugin'); //installed via npm
    const webpack = require('webpack'); //to access built-in plugins

    module.exports = {
      plugins: [
        new HtmlWebpackPlugin({template: './src/index.html'})
      ]
    };
    ```

#### Mode
  * 分成 `development`, `product`, `none`, 預設是 `production`
  * config 設置,
    ```javascript
    module.exports = {
      mode: 'production'
    };
    ```

#### Browser Compatibility and Environment
  * 瀏覽器支援 ES5-compliant (IE8 and below are not supported) 的都試用。
  * 支援更低階的瀏覽器需要額外使用 polyfill
  * webpack 執行在 Node.js 8.x 版以上


------------------------------


### 第二章 - Entry Points
  * 除了指定單一的入口檔案以外，也可以傳入多個入口檔案，生成多個 dependency graph。
  * `entry: ""` 單檔案, `entry: {}` 多檔案
  * 分開處理不同類型的檔案, separation of concerns
  * 多頁網站，每頁有不同的入口檔案
  * 經驗法則是一個 html 頁面，擁有自己的一個入口。


------------------------------


### 第三章 - Output
  * 輸出單個檔案 `output: { filename: '' }`
  * 多個入口時可以依據各個 dependency graph 輸出多個檔案,
    ```javascript
    entry: {
      app: './src/app.js',
      search: './src/search.js'
    },
    output: {
      filename: '[name].js',
      path: __dirname + '/dist'
    }
    ```
  * 配合 CDN 路徑的設置


------------------------------


### 第四章 - Loaders
  * 轉譯匯入 TypeScript, 使用 import 載入 css
  1. 使用 npm 安裝 loaders, 例如 `npm install --save-dev css-loader ts-loader`
  1. 設置 rules,
    ```javascript
    module: {
      rules: [
        { 
          test: /\.css$/, use: [
          // style-loader
          { loader: 'style-loader' },
          // css-loader
          {
            loader: 'css-loader',
            options: {
              modules: true
            }
          },
          // sass-loader
          { loader: 'sass-loader' }
          ] 
        },
        { test: /\.ts$/, use: 'ts-loader' }
      ]
    }
    ```
  * 在 `webpack.config.js` 中設置 configuration 是最好的方式。(其他還有 CLI, inline)
  * 可以撰寫客製化的 loader，只是一個 function

#### Loader Features
  * Loader 以 chain 的方式運作，執行順序是設置順序的倒序
  * Loader 可以為同步 (synchronous) 或非同步 (asynchronous)
  * Loader 運行在 Node.js 上，因此可以執行所有 Node.js 能作到的事情。
  * 利用 `options` 設置各個 loader 的設定
  * plugins 可以增加 loader 的功能
  * loader 可以輸出檔案


------------------------------


### 第五章 - Plugins
  * Webpack 的核心
  * plugin 是一個 JavaScript object 包含一個 `apply(compiler)` 成員函式
  * 由 webpack compiler 呼叫，並且在整個 compile 時期皆可存取


------------------------------


### 第六章 - Configuration
  * 一個 js 檔，輸出一個 config 物件
  * 使用 `require()`, `export.module`, CommonJS 模組模式, 因為被 Node.js 採用。
  * 簡單的範例, `webpack.config.js`
    ```javascript
    var path = require('path');

    module.exports = {
      mode: 'development',
      entry: './foo.js',
      output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'foo.bundle.js'
      }
    };
    ```


------------------------------


### 第七章 - Modules
  * Webpack 通過各種 loader 允許多種不同的 module 實現模式。
  * 對於 Webpack 來說各種不同的 module 模式都是用於呈現 dependencies。


------------------------------


### 第八章 - Module Resolution
  * Wepback 使用 **enhanced-resolve** 實現 module 路徑解析。
  * 分成 absolute paths, relative paths, module paths
  * 執行期檔案系統使用 cache 加快執行, 只有 watch mode 不使用 cache。


------------------------------


### 第九章 - Module Federation
  * Webpack 第5版的實現性新功能，允許一個應用程式動態的載入其他應用程式的程式碼。
  * 一個完整的應用程式分成多個 build，但是互相之間沒有 dependency，因此可以各自獨立的開發與部屬。
  * 企圖實現 Micro-Frontends (微服務概念擴充至前端)
  * 區分成 local module 與 remote module。
  * 分成 container 與 consumer。
  * 非同步的載入遠端的程式碼 (remote module, container)
  * 使用 plugins 實現與設置。


------------------------------


### 第十章 - Dependency Graph
  * 任何檔案之間的引用被視為 dependency
  * 從 entry point 遞迴的建立 dependency graph 最後所有的 module 被打包成單檔案或多檔案 (bundles)
  * 瀏覽器只需要下載打包好的 bundles。


------------------------------


### 第十一章 - Targets
  * 由於 JavaScript 可能是為了 web browser 或者 Node.js server 所撰寫，因此可以使用 target 區分輸出不同的內容。
  * 預設是 web
  * config 設置
    ```javascript
    module.exports = {
      target: 'node'
    };
    ```

#### Multiple targets
  * Webpack target 不支援設置多個 target，因此可以輸出多個 config，
  * 使用 `export.module = []`, 以陣列輸出多個設置


------------------------------


### 第十二章 - The Manifest
  * Webpack 產生 runtime 時的 manifest，在 runtime 實現 Webpack 模組運作機制。
  * 例如模組之間的載入順序與連接, 或者 lazy-loading 的實現。
  * 在最佳化效能時使用的 hash 版本 cache 可能會因為 Manifest 而被破掉，需要額外設置 Output 機制避開這個問題。


------------------------------


### 第十三章 - Hot Module Replacement (HMR)
  * 在 Runtime 改變或新增模組

#### 運作機制
  * 對於 Application, 需要定期詢問 HMR 更新，並且下載更新，完成更新。
  * 對於 Compiler, 需要更新 Manifest (JSON), 與實際的資料 chunks (JavaScript)
  * 對於 Module, HMR 是選用的機制，必須額外引入輔助的程式碼才能實現。
  * 對於 Runtime, 需要追蹤模組的 `parents` 與 `children`，通過管理的函式, `check` 與 `apply`。
    * `check`, 發送 http request 去詢問 HMR 查看 manifest 是否有更新。有更新則下載新的 chunks 直到 `ready`。
    * `apply` 去停止並且更新所有相關的模組。update handler, dispose handler, accept handler, ...


------------------------------


### 第十四章 - Why webpack
  * Browser 上的 JavaScript
    1. 多檔案 JavaScript 產生 network bottleneck, 單一大檔案不容易開發與管理。
    1. 使用 IIFE 串接多檔案 JavaScript 進入單一檔案。單純的串接成大檔案依舊不容易管理，例如更新, 最佳化, lazy-loading。
    1. Node.js 的出現, 與使用 CommonJS 實現模組化。然而瀏覽器不支援這種模組化運作。
    1. ECMAScript module, 標準化的 module 出現，然而瀏覽器支援度目前不佳。
  * Webpack 提供完整的 module 解決方案並且注重效能，有很多最佳化效能的功能選項。


------------------------------


### 第十五章 - Under The Hood
  * bundling 只是一個 function, input 一些檔案, output 一些檔案。
  * Modules 形成 `ModuleGraph` 
  * Module 分割成 chunks
  * Chunks 集合成 chunk groups
  * Chunk groups 形成 `ChunkGraph`

#### Entry points
  * 單一入口的 config, `entry: './index.js'`, 產生 1 個 chunk group 與 1 個 chunk。這個 chunk group 預設的名稱是 `main`
  * 多入口的 config, ` entry: { home: './home.js', about: './about.js' }`, 產生多個 chunk group 並且有指定的名稱。

#### Chunks
  * 分成 `initial` 與 `non-initial` 兩種
    * `initial` chunk 包含所有模組的 dependencies 資訊，預設名稱是 `main.js`
    * `non-initial` chunk 可以被 lazy-loaded 的。預設名稱是 ID，可額外指定名稱。

#### Output
  * `output.filename`, `initial` chunks 輸出的檔案
  * `output.chunkFilename`, `non-initial` chunks 輸出的檔案
  * 常用的 placeholder 
    * `[id]`, chunk id
    * `[name]`, chunk name，如果沒有名稱則會使用 ID
    * `[contenthash]`, 檔案內容的 md4-hash

