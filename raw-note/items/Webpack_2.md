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


------------------------------


### 第七章 - Authoring Libraries


------------------------------


### 第八章 - Build Performance