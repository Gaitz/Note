## Create React App official documents

### [Website resource](https://create-react-app.dev/docs/getting-started), React

---

第一章 - Setup

第二章 - Getting started

第三章 - Development

第四章 - Style and assets

第五章 - Build your App

第六章 - Testing

第七章 - Back-End Integration

第八章 - Development

第九章 - Advanced Usage

---

#### 第一章 - Setup

安裝 Node.js

1. `nvm`
1. `nvm install node`

建立

- `npx create-react-app`, 使用 npm
- `npm init react-app`
- `yarn create react-app`, 使用 yarn

選擇套用模板 (template)

- 建立時配合參數 `--template`
- 例如使用 TypeScript, `--template typescript`

- [nvm](https://github.com/nvm-sh/nvm)
- [create-react-app](https://facebook.github.io/create-react-app/)
- [create-react-app GitHub](https://github.com/facebook/create-react-app#creating-an-app)

---

#### 第二章 - Getting started

Scripts

- `npm start` or `yarn start`, 啟動開發模式 development mode
- `npm test` or `yarn test`, 執行測試, 在交互模式下 interactive mode, 自動會 watch
- `npm run build` or `yarn build`, 編譯到 `build` 資料夾下產生 production ready 最佳化過的程式碼
- `npm run eject`

Folder Structure

- `public/index.html` html 模板
- `src/index.js` 入口
- 只有在 `src/` 下的程式碼才受到 Webpack 控制

Available Scripts

- `npm start`
- `npm test`
- `npm run build`
- `npm run eject`

Supported Browsers and Features

- 支援所有的現代瀏覽器
  - 如果要支援 IE9, 10, 11 需要額外的 polyfill, 使用 `react-app-polyfill`
- 支援的語法

  - includes **no polyfills** by default
  - 支援所有最新版的 JavaScript 標準
  - 也支援 JSX, Flow, TypeScript
  - 和少數在 proposal 的語法例如 Dynamic import, Class Fields, Static Properties

- Configuring Supported Browsers

  - 可以在 `package.json` 裡設定 `browserslist` 來決定支援程度
  - config [browserslist](https://github.com/browserslist/browserslist) checkout your code in browser support.

Updating to New Releases

- 更新到最新版
- Create React App 所使用到的的工具被分在兩個 packages 中
  - `create-react-app`, 只在第一次建立時使用
  - `react-scripts`, 提供 development 時的工具
- 已經存在的 CRA project 只需要更新 `react-scripts` 到最新版即可

#### 第三章 - Development

Setting Up Your Editor

- Syntax highlighting

  - syntax highlighting with [babel](https://babeljs.io/docs/en/editors/)

- Lint

  - Extend default ESlint config
  - Prettier

- Debugging

  - VSCode with Chrome Debugger Extension

- Formatting Code Automatically
  - `husky`, `lint-staged`, `prettier`

Developing Components in Isolation

- 可以自行加入
- Storybook for React
  - `npx -p @storybook/cli sb init`
- React Styleguidist
  - `npm install --save react-styleguidist` or `yarn add react-styleguidist`
  - `npm run styleguide`

Analyzing the Bundle Size

- 需要自行安裝 **Source map explorer**
- `npm install --save source-map-explorer` or `yarn add source-map-explorer`
- `npm run build` -> `npm run analyze`

Using HTTPS in Development

- 在開發模式就啟用 HTTPS 的方法
- 需要配合參數依據不同終端用不同的參數 `HTTPS=true` for Bash
- Custom SSL certificate, 設定簽章

#### 第四章 - Style and assets

Adding a Stylesheet

Webpack based, `import .css` (直接 import CSS)

CSS Module, `import .module.css`

work with Sass, are not recommended.

- 不推薦使用太多 CSS preprocessors 功能,
- 不推薦 CSS 層級的重用, 會造成樣式的耦合不容易修改
- 推薦以 React Component 實現樣式重用

Adding a CSS Reset

- add normalize.css `@import-normalize;`, any `.css`, duplicate will be removed.

Post-Processing CSS

- 目前會自動處理

Adding Images, Fonts, and Files,

- using Webpack way, `import logo from './logo.png';`
- image less than 10,000 bytes return [Data URI](https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Data_URIs) base64.

Add SVG,

- import as ReactComponent, 可以直接作為 React component import
- `import { ReactComponent as Logo } from './logo.svg';`, `<Logo />`

Loading `.graphql` Files

- 使用 GraphQL 需要安裝
- `npm install --save graphql graphql.macro` or `yarn add graphql graphql.macro`
- 之後即可使用 `graphql.macro` 的功能

Using the Public Folder, without Webpack and its benefit,

- using in `.html` as `href="%PUBLIC_URL%/favicon.ico"`
- using in `.js` as `<img src={process.env.PUBLIC_URL + '/img/logo.png'} />;`

Code splitting,

- 在需要的時候使用 dynamic import 的功能實現, [dynamic import()](https://2ality.com/2017/01/import-operator.html#loading-code-on-demand)
- 配合 client-side routing 工具 `React Router` 以 routing base 做 code splitting

#### 第五章 - Building your App

Installing a Dependency

- 可以在自行安裝所需要的 packages

Importing a Component

- 可以設置 jsconfig.json 或 tsconfig.json 實現絕對路徑 import

Using Global Variables,

1. `const $ = window.$;`
2. `// eslint-disable-line`

Adding Bootstrap

Adding Flow

- 已經內建可以直接使用

Adding TypeScript

- 可以在建立時使用 `--template typescript`
- 如果是已經存在的 project 則需要手動安裝
  - `typescript`, `@types/node`, `@types/react`, `@types/react-dom`, `@types/jest`

Adding Relay

- 已經內建可以直接使用
- 需要安裝 `npm install --save babel-plugin-relay`

Adding a Router,

- client-side routing, 推薦使用 React Router
- `npm install --save react-router-dom`

Adding Custom Environment Variables

- 使用不同類型的 `.env`, `.env.local`, `.env.development`, `.env.test`, `.env.production`
- 存在不同時期的環境變數需要配合慣用開頭
  - `REACT_APP_` runtime 存活
  - 其他環境變數是 build time 存活
- 使用 `process.env.` 語法取值

Making a Offline-first Progressive Web App

- 建立時可以使用 `--template cra-template-pwa` or `--template cra-template-pwa-typescript` 提供更完整的服務
- 預設是內建的, `src/service-worker.js`

Measuring Performance

- 配合指令 `reportWebVitals(console.log)` 可以取得一些測量值
- Web Vitals
  - 一套好用的測量值提供衡量更好的使用者體驗
- 整合 GA 發送報表

Creating a Production Build

- 說明 `build/` 下的檔案與命名規則
- Static File Caching 推薦提供 HTTP `Cache-Control` 增加快取使用率
- Profiling
  - 在 production 也啟用 profiling
  - `npm run build -- --profile` or `yarn build --profile`
  - 會多一點點 loading

#### 第六章 - Testing

Running Tests

- 預設使用 Jest
- Using [Jest](https://jestjs.io/) run on node environment
- Jest is intended to be used for unit tests of your logic and your components
- Create React App do not include end-to-end test
- Jest test work with
  - Files with `.js` suffix in `__tests__` folders.
  - Files with `.test.js` suffix.
  - Files with `.spec.js` suffix.
- `npm test` work in watch mode.
- Jest will only run the tests related to files changed since the last commit.
- Press a in the watch mode to force Jest to run all tests.
- [Testing Components](https://create-react-app.dev/docs/running-tests#testing-components)
  - Option 1: Shallow Rendering with [Enzyme](https://airbnb.io/enzyme/)
  - Option 2: [React Testing Library](https://github.com/testing-library/react-testing-library)
- Initializing test environment with browser API mock
- Coverage Reporting, `npm test -- --coverage`
- Continuous Integration, CI servers
- [Travis CI](https://docs.travis-ci.com/user/tutorial/), [CircleCI](https://medium.com/@knowbody/circleci-and-zeits-now-sh-c9b7eebcd3c1)
- [Disabling jsdom if do not need it](https://create-react-app.dev/docs/running-tests#disabling-jsdom)
- Snapshot Testing with [jest](https://jestjs.io/blog/2016/07/27/jest-14.html)
- Visual Studio Code [extension](https://github.com/jest-community/vscode-jest)

Debugging Tests

- Debugging Tests in Chrome
  - 可以增加 `scripts`, `"test:debug": "react-scripts --inspect-brk test --runInBand --no-cache`
  - 執行 `npm run test:debug`
  - 在 Chrome 裡的 `about:inspect` 察看結果
- Debugging Tests in Visual Studio Code
  - 新增 `launch.json` configuration file
  - 參考文件: https://create-react-app.dev/docs/debugging-tests#debugging-tests-in-visual-studio-code

#### 第七章 - Back-End Integration

Proxying API Requests in Development

- 使用內建方式, 在 `package.json` 可以提供 `"proxy": "http://localhost:4000"` 指定 domain 回 localhost 來避免 CORS
- 自行客製化
  - 推薦使用工具 `http-proxy-middle`, 以 `src/setupProxy.js` 的方式建立

Fetching Data with AJAX Requests

- 沒有限制使用方式, 推薦方式原生的 `fetch` 或 `axios`

Integrating with an API Backend

Title and Meta Tags

#### 第八章 - Development

Static Server,

- 配合 Node.js 實現簡單的 static server
- `npm install -g serve`, `serve -s build`

`Express` Node.js

AWS Amplify

Azure

Firebase

GitHub Pages

Heroku

Netlify

Vercel

Render

AWS S3 and CloudFront

Surge

#### 第九章 - Advanced Usage

Custom Templates

- 自訂 Create React App template

Can I Use Decorators

- Create React App 不支援 decorators 語法並說明為什麼

Pre-Rendering into Static HTML Files

- 可以配合 `react-snapshot` or `react-snap` 實現不同的 route 產生不同的 html

Advanced Configuration

- 通過環境變數設定

Alternatives to Ejecting

- Ejecting 讓你脫離並且自行控制, 推薦可以仍然掛勾一個 fork 版的 `react-scripts` package 可以在需要的時候提供升級或客製化
