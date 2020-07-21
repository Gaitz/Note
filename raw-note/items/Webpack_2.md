## Webpack official document - Guides
### [Website resource](https://webpack.js.org/guides/), Webpack

------------------

第一章 - Getting Started

第二章 - Asset Management

第三章 - Output Management

第四章 - Development

第五章 - Code Splitting

第六章 - Caching

第七章 - Authoring Libraries

第八章 - Build Performance

第九章 - Content Security Policies

第十章 - Development - Vagrant

第十一章 - Dependency Management

第十二章 - Installation

第十三章 - Scaffolding

第十四章 - Hot Module Replacement

第十五章 - Tree Shaking

第十六章 - Production

第十七章 - Lazy Loading

第十八章 - Shimming

第十九章 - TypeScript

第二十章 - Progressive Web Application

第二十一章 - Public Path

第二十二章 - Integrations

第二十三章 - Asset Modules

第二十四章 - Advanced entry


------------------


### 第一章 - Getting Started
  * Webpack 從入口檔案去打包，因此只有被使用到的模組才會被增加到 dependency graph，不需要自行輸入相依性。

#### 基礎設置教學
  1. `npm install webpack webpack-cli --save-dev`
  1. 新增 `index.html`, `src/index.js`
  1. `index.html` 移動至 `dist/index.html`
  1. 使用 npm 安裝未來需要使用到的函式庫, Example: `npm install --save lodash`
  1. 在 `src/index.js` 中引用函式庫, `import _ from 'lodash';`
  1. 在 `dist/index.html` 中移除原本的 `index.js` 與 lodash，改成只引用未來打包後的名稱 `<script src="main.js"></script>`
  1. 執行 webpack 實現打包，`npx webpack`

#### Modules
  * 模組語法推薦使用 ES6 的 `import` 與 `export`。當然也支援 CommonJS 與 AMD。
  * `import()` runtime 時的動態載入可以使用 webpack 約定的 magic comment 做額外設定。

#### 使用設定檔 configuration
  * Webpack version 4 以後設定檔是選用的。
  * `webpack.config.js`
    * 基礎設定範例
    ```javascript
    const path = require('path');

    module.exports = {
      entry: './src/index.js',
      output: {
        filename: 'main.js',
        path: path.resolve(__dirname, 'dist'),
      },
    };
    ```
  * 更複雜的功能需要參考 CLI 文件與 Configuration 文件

#### 使用 NPM Scripts
  * 在 `package.json` 加入 `"scripts": { "build": "webpack"}` 後即可使用 `npm run build` 來執行。


------------------------------


### 第二章 - Asset Management
  * 通過 webpack loaders 引用 JavaScript 以外的資源。
  * Webpack 透過 loaders 自動把資源放置到對的位置。

#### Loading CSS 範例
  1. 安裝需要的 loaders `npm install --save-dev style-loader css-loader`
  1. 設定 `webpack.config.js`
      ```javascript
      module: {
        rules: [
          {
            test: /\.css$/, // 使用 regular expression
            use: [
              'style-loader',
              'css-loader',
            ],
          },
        ],
      },
      ```
  1. 新增 `src/style.css`
  1. 在 `src/index.js` 中引用 `import './style.css'`

#### Loading Images
  1. `npm install --save-dev file-loader`
  1. 設定 `webpack.config.js`
      ```javascript
      {
        test: /\.(png|svg|jpg|gif)$/,
        use: [
          'file-loader',
        ],
      }
      ```

#### Loading Fonts
#### Loading Data

#### Global Assets
  * 透過 Webpack 資料夾結構可以從以檔案類型分類變成以元件分類。


------------------------------


### 第三章 - Output Management
  * 多個入口與多個輸出

#### HtmlWebpackPlugin / html-webpack-template
  * 自動生成所需要的 `dist/index.html`
  * 安裝 `npm install --save-dev html-webpack-plugin`
  * 設定 `webpack.config.js`
      ```javascript
      const HtmlWebpackPlugin = require('html-webpack-plugin');
        
      plugins: [
        new HtmlWebpackPlugin({
          title: 'Output Management',
        }),
      ],
      ```

#### clean-webpack-plugin
  * 在每次 build 之前都會先清除 `dist/`。
  * 設定 `webpack.config.js`
    ```javascript
    const { CleanWebpackPlugin } = require('clean-webpack-plugin')
    plugins: [
      new CleanWebpackPlugin()
    ]
    ```

#### WebpackManifestPlugin
  * 通過此 plugin 了解且控制 manifest
  * 最佳化 cache 時會用到。


------------------------------


### 第四章 - Development
  * 設定 `webpack.config.js` 成 `mode: 'development'`

#### source maps
  * 讓錯誤訊息更容易定位到原本的 js 中
  * `webpack.config.js` 中設定 `devtool: 'inline-source-map'`

#### Development tool
  * 避免每次都手動觸發 webpack，可以利用以下方式自動編譯
    * webpack's Watch Mode, 仍需手動重新整理瀏覽器
    * webpack-dev-server
    * webpack-dev-middleware
  * Webpack's Watch Mode,  如果使用 CleanWebpackPlugin 需設定
    ```javascript
    plugin: [
      new CleanWebpackPlugin({ cleanStaleWebpackAssets: false })
    ]
    ```
    * CLI: `webpack --watch`
  * webpack-dev-server, 安裝 `npm install --save-dev webpack-dev-server`, `webpack.config.js` 設定
    ```javascript
    devServer: {
      contentBase: './dist'
    }
    ```
    * CLI: `webpack-dev-server --open`
  * webpack-dev-middleware, 被 webpack-dev-server 內部使用，也可以配合其他 Node.js server 例如 express 框架。


------------------------------


### 第五章 - Code Splitting
  * 效能最佳化
  * 實現方式分為
    * Entry points, 手動設置多個 `entry`, 因此會產生多個 chunks group, 但是無法避免重複載入相同模組。因為是完全獨立的。
    * Prevent Duplication, 使用 `SplitChunksPlugin`
    * Dynamic imports, 使用動態 `import()`
  * `SplitChunksPlugin`, 明確的設置 `dependOn` modules。`webpack.config.js` 設置
    ```javascript
    entry: {
      index: { import: '', dependOn: 'shared' },
      another: {import: '', dependOn: 'shared' },
      shared: 'lodash'
    },
    optimization: {
      splitChunks: {
        chunks: 'all'
      }
    }
    ```
    * 相關的 plugin, `mini-css-extract-plugin`, CSS 相關程式碼的分割。
  * Dynamic imports
    * 使用 ECMAScript 標準的動態引入 `import()`, 會自動生成 `non-initial` chunk, 可以額外指定名稱
      ```javascript
      // webpack.config.js
      output: {
        chunkFilename: '[name].bundle.js'
      }
      ```
    * 從文件中查看更多細節

#### Prefetching/Preloading modules
  * webpack 4.6.0+ 開始支援
  * prefetch, 呼叫層完成後預先下載, 需等待瀏覽器 idle; preload, 呼叫層下載時平行下載, 優先度較高
  * 通過動態引入 `import(/* webpackPrefetch: true */ 'ModuleName')`, 
    * 會自動轉譯成 `<link ref='prefetch' href />` 放置在 `<head>` 中
  * 通過動態引入 `import(/* webpackPreload: true */ 'ModuleName')`, 
    * 會自動轉譯成 `<link ref='preload' href />` 放置在 `<head>` 中
  * 非必要的濫用反而會造成效能問題

#### Bundle Analysis
  * Bundle 分析以提供最佳化的根據
  * 可以參考文件有更多的推薦


------------------------------


### 第六章 - Caching

#### Output filenames
  * 把輸出檔案加上 hash, 使用 substitutions, `[contenthash]` 

    ```javascript
    output: {
      filename: '[name].[contenthash].js'
    }
    ```

#### 避免 Webpack 內建工作破壞 cache
  * 明確的區分打包 vendor pacakges 
    ```javascript
    optimization: {
      runtimeChunk: 'single',
      splitChunks: {
        cacheGroups: {
          vendor: {
            test: /[\\/]node_modules[\\/]/,
            name: 'vendors',
            chunks: 'all'
          }
        }
      }
    }
    ```
  * 避免 Module Identifiers 破壞 vendor cache
    ```javascript
    optimization: {
      moduleIds: 'hashed'
    }
    ```


------------------------------


### 第七章 - Authoring Libraries
  * 打包 library
  * 明確的設置 externals libraries, 設置單個 object 或者 array
    ```javascript
    externals: {
      lodash: {
        commonjs: 'lodash',
        commonjs2: 'lodash',
        amd: 'lodash',
        root: '_'
      }
    }
    ```


------------------------------


### Environment Variables
  * 從 webpack CLI 傳入環境變數給 webpack.config.js 使用
  * `webpack --env.NODE_ENV=local --env.production --progress`
  * ```javascript
    const path = require('path');

    module.exports = env => {
      // Use env.<YOUR VARIABLE> here:
      console.log('NODE_ENV: ', env.NODE_ENV); // 'local'
      console.log('Production: ', env.production); // true

      return {
        entry: './src/index.js',
        output: {
          filename: 'bundle.js',
          path: path.resolve(__dirname, 'dist'),
        },
      };
    };
    ```


------------------------------


### 第八章 - Build Performance

#### General
  1. 使用最新版的 webpack 和最新版的 npm 
  1. 盡可能減少 loader test 的作用域，例如指定檢查的路徑 `include`
  1. 每個 loader 或 plugin 都會增加啟動時間，使用盡可能少的工具
  1. Resolving 效能, 
    * 減少 Node.js 的 filesystem 呼叫，
    * 沒用到 symlinks (`npm link`)則設置 `resolve.symlinks: false`, 
    * 如果使用客製化的 resolving plugins 可以考慮設置 `resolve.cacheWithContext: false`
  1. 使用 `DllPlugin` 分割較少改變的程式碼, 壞處是增加複雜度
  1. **Smaller = Faster**,
    * 減少或更小的函式庫
    * Multi-Page Applications 啟用 `SplitChunksPlugin`, 並且設置成 `async`
    * 移除廢碼 (unused code)
    * 只編譯正在開發的程式碼
  1. Worker Pool, 適度的使用 `thread-loader` 把負擔重的 loader 丟給 worker 執行。過多的 worker 和 IPC 仍然會導致效能問題。
  1. Persistent cache, `cache-loader`, package.json `postinstall`
  1. 自製的 plugins/loaders 小心效能問題
  1. 停用 `ProgressPlugin` 也會提高效能，但不顯著，需衡量利弊。

#### Development
  1. 使用 webpack 原生的 watch mode, 減少其他類似的功能。
  1. Compile in Memory, 使用任一種皆可
    * `webpack-dev-server` 
    * `webpack-hot-middleware`
    * `webpack-dev-middleware`
  1. `stats.toJson()` speed 優化, 使用 `webpack-dev-server`, 
  1. 注意各種 Devtool 之間的效能差異, 大多數情況使用 `eval-cheap-module-source-map` 是最佳選擇
  1. 關閉那些只有在 production 才需要的工具, 例如 `TerserPlugin`, `ExtractTextPlugin`, `[hash] / [chunkhash]`, `AggressiveSplittingPlugin`, `AggressiveMergingPlugin`, `ModuleConcatenationPlugin`
  1. 避免在 development 不需要的 optimization, 例如
      ```javascript
      optimization: {
        removeAvailableModule: false,
        removeEmptyChunks: false,
        splitChunks: false
      }
      ```
  1. 關閉 Output path info
      ```javascript
      output: {
        pathinfo: false
      }
      ```
  1. 使用新版的 Node.js, ES6 中新的資料結構 Map, Set 被 webpack 所使用並且有效能提昇功能。
  1. TypeScript loader, 避免在 loader 階段做 type checking, 使用 `ForkTsCheckerWebpackPlugin` 取代。更多細節要參考 `ts-loader` 文件
      ```javascript
      {
        loader: 'ts-loader',
        options: {
          transpileOnly: true
        }
      }
      ```

#### Production
  * 不要犧牲品質換取執行效能, 在 production 階段尤其重要。
  1. 平行處理, `parallel-webpack`, `cache-loader`

#### 注意各工具的效能選項
  * Babel 減少 preset/plugins
  * TypeScript,
  * Sass,


------------------------------


### 第九章 - Content Security Policies
  * `nonce`
  * `__webpack_nonce__` 必須是 base64-encoded 字串
  * Content-Security-Policy (CSP) 並不是預設啟用, 需要自行增加 meta header
    * CSP 提供瀏覽器一些限制指示, 希望降低 XSS 被執行的風險。


------------------------------


### 第十章 - Development - Vagrant
  * 開發的時候使用 Vagrant 或 nginx proxy server


------------------------------


### 第十一章 - Dependency Management
  * ES6 modules, commonjs, amd
  * Dynamic `require()`, 單純用字串組合變數
  * `require.context()`, 明確設置 context
    * ```javascript
      require.context(directory, useSubdirectories = true, rexExp = /^\.\/.*$/, mode = 'sync');
      ```
    * context module API, `resolve` function, `keys` function, `id`


------------------------------


### 第十二章 - Installation
  * Prerequisties, Node.js
  * Local installation, (most cases)
    * `npm install --save-dev webpack`
    * `npm install --save-dev webpack@<version>`, 安裝特定版本
    * `npm install --save-dev webpack-cli`, 安裝 webpack CLI
    * package.json, 
      ```javascript
      "scripts": { 
        "build": "webpack --config webpack.config.js" 
      }
      ```
  * Global installation
    * 不推薦, 因為會綁定 webpack 版本
  * Beta 版本安裝
    * `npm install --save-dev webpack@next`
    * `npm install --save-dev webpack/webpack#<tagname/branchname>`


------------------------------


### 第十三章 - Scaffolding
  * 通過 webpack-cli 客製化 config 建立的 scaffold。需要釐清為何需要使用。
  * 建立: 參考 CONTRIBUTE 中的 [Writing a Scaffold](https://webpack.js.org/contribute/writing-a-scaffold/)
  * 使用: `webpack-cli init <your-scaffold>`


------------------------------


### 第十四章 - Hot Module Replacement
  * Hot Module Replacement (HMR), 在 runtime 更新 module
  * 此功能主要用在 development 環境
  * 啟用, 通過 `webpack-dev-server` 或 `webpack-hot-middleware`
  * webpack.config.js
    ```javascript
    devServer: {
      contentBase: '',
      hot: true
    }
    ```
  * `webpack-dev-server --hotOnly`
  * ```javascript
    if (module.hot) {
      module.hot.accept()
    }
    ```

#### 或配合 Node.js API 啟動
  * [dev-server.js](https://webpack.js.org/guides/hot-module-replacement/#via-the-nodejs-api)

#### HMR with Stylesheets
  1. `npm install --save-dev style-loader css-loader`, 安裝 loaders
  1. webpack.config.js 使用 loaders
      ```javascript
      devServer: {
        contentBase: '',
        hot: true
      },
      module: {
        rules: [
          {
            test: /\.css$/,
            use: ['style-loader', 'css-loader']
          }
        ]
      }
      ```

#### 其他支援 HMR 的工具
  * React Hot Loader
  * Vue Loader
  * Elm Hot webpack loader
  * Angular HMR
  * Svelte Loader


------------------------------


### 第十五章 - Tree Shaking
  * 偵測未 import 使用到的廢碼 (dead code) 並且自動從 bundle 中移除。
  * 注意事項, 
    1. 必須使用 ES2015 modules `import()`, `export()`,
    1. 小心不要被 babel 轉義成 commonjs
    1. `mode` 設置成 `production` 實現打包最佳化。(tree shaking)
    1. 在 `package.json` 中提供 `sideEffects` array

#### Development mode
  * 啟動 webpack.config.js
    ```javascript
    mode: 'development',
    optimization: {
      usedExports: true
    }
    ```
  * 輸出後會在 bundle.js 中看到未被使用的程式碼被加上註解, Ex. `unused harmony export`

#### 處理 side-effect function
  * 如果整個專案的 export 都是 pure 則可以在 package.json 中設置 `"sideEffect": false`
  * 如果有 sideEffect 則可以提供檔案路徑的 array, `"sideEffect": [ "*.css" ]`, 允許相對路徑/絕對路徑/glob 語法。
  * `sideEffects` 與 `usedExport` optimizations
  * 設置註解提供 webpack 知道是 pure, `/*#__PURE__*/`


------------------------------


### 第十六章 - Production


------------------------------


### 第十七章 - Lazy Loading


------------------------------


### 第十八章 - Shimming


------------------------------


### 第十九章 - TypeScript


------------------------------


### 第二十章 - Progressive Web Application


------------------------------


### 第二十一章 - Public Path


------------------------------


### 第二十二章 - Integrations


------------------------------


### 第二十三章 - Asset Modules


------------------------------


### 第二十四章 - Advanced entry

------------------------------

