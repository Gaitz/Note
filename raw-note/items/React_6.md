## React Router Official Documents

### [Website resource](https://reactrouter.com/), React/React_Router

---

第一章 - Guides

第二章 - Examples

第三章 - API

---

### 第一章 - Guides

#### Quick Start

Installation

- NPM or YARN, `npm install react-router-dom`

1st Example: Basic Routing

- 在三個頁面中路由
- 使用 `import { BrowserRouter as Router, Switch, Route, Link } from "react-router-dom";`
- `<Link to=""></Link>`, 實際會渲染成 `<a>` link, 並且導向對應的 `<Route>`
- 標籤結構
  ```html
  <Router>
    <Link to></Link>
    <Switch>
      <Route path>
      </Route>
    </Switch>
  </Router>
  ```

2nd Example: Nested Routing

- 巢狀路由, 路由的子頁面可以擁有自己的路由設定
- 使用 `import { BrowserRouter as Router, Switch, Route, Link, useRouteMatch, useParams } from "react-router-dom";`
- [範例](https://reactrouter.com/web/guides/quick-start)

#### Primary Components

三種主要的 components

- routers, `<BrowserRouter>`, `<HashRouter>`
- route matchers, `<Route>`, `<Switch>`
- navigation, `<Link>`, `<NavLink>`, `<Redirect>`

Routers

- `react-router-dom`, 提供兩種 routers `<BrowserRouter>`, `<HashRouter>`, 提供環境
- `<BrowserRouter>`, 建立出最正常的 URL, 但是伺服器端需要一模一樣的設定, Create-React-App 有相關的[設定](https://create-react-app.dev/docs/deployment/#serving-apps-with-client-side-routing)
- `<HashRouter>`, 目前位置存在 URL 的 `#` 之後
- 確保 router 正常運作, router component 應該為應用程式的 top component, 
  - ```html
    <BrowserRouter>
      <App />      
    </BrowserRouter>
    ```

Route Matchers

- 兩個 components `<Switch>`, `<Route>`, 提供路由條件
- 當 `<Switch>` 被渲染時會自動從 `<Route>` 則一比對目前的 URL, 當比較成功後則渲染, 並且忽略之後的 `<Route>`
  - 因此 `<Route>` 的排放順序是重要的, 越嚴格的排越前面, 否則永遠不會被 match 到
  - 如果沒有任何的 `<Route>` 符合則會渲染 `null`
- 可以使用 `<Route path="/">` 放置在最後一項作為 default 渲染設定, 任何情況的 URL 都會符合這項條件
- 優先使用 hook 功能

Navigation (Route Changers)

- 三個 components `<Link>`, `<NavLink>`, `<Redirect>`, 提供改變路由狀態
- `<Link to>` 實際會渲染出 `<a>`, 當使用者觸發時會改變路由狀態
- `<NavLink to>`, 特殊的 `<Link>`, 當 URL 對應到時會主動切換路由狀態
- `<Redirect to>`, 強制切換路由狀態

#### Server Rendering

- React server-side rendering, 由於伺服器端的 React 並沒有 state, 因此只能用 context 取的 request 資訊然後正確的渲染
- `<StaticRouter location context>`, 配合 `context.url` 判斷是否在 client-side 被 redirect
- [範例](https://reactrouter.com/web/guides/server-rendering)

Adding app specific context information

- 通過客製化 staticContext 提供路由資訊, 用來判斷且回傳正確的頁面或處理
- 範例通過客製化資訊區分 `301`, `302` redirect

404, 401 or any other status

- 處理未 match 的狀態並且通過 staticContext 取得狀態

Putting it all together

- 較為完整的範例, 利用 react-router-dom 整合 server-side rendering 與 client-side routing

Data Loading

- 有很多作法可以做到, 目前沒有標準化做法
- 在伺服器端動態載入資料

#### Code Splitting

- 使用 `webpack`, `@babel/plugin-syntax-dynamic-import`, `loadable-components`
- 在 client-side 做動態載入
- 利用 babel plugin `@babel/plugin-syntax-dynamic-import` 指示 webpack 如何做 code splitting
- `loadable-components` 函式庫提供處理 code spitting 的 component 細節處理
- loadable-components [文件](https://loadable-components.com/docs/getting-started/)

#### Scroll Restoration

- 瀏覽器可以通過 `history.pushState` 做到 scroll restoration 如同載入新頁面一樣

Scroll to top

- 實作 `ScrollToTop` component, 當 URL 改變時自動 scroll to top
- [範例](https://reactrouter.com/web/guides/scroll-restoration)

Generic Solution

- 希望解決的問題是
  - 在切換路由時會回到最上方
  - overflow 的 scroll 也回復到初始位置
- 通過把 scroll 位置儲存在 sessionStorage 中, 可以從 router `location.key` 取得並且在使用者載入時 scroll 到儲存位置
- 由於 scroll 行為有不同的需求, 因此需要自行實作, React Router 並沒有提供 API

#### Philosophy

- React Router 思想是 Dynamic Routing 

Static Routing

- Rails, Express, Ember, Angular 等框架會在 App 尚未渲染的初始化時設置 static routing
- 參考 Express, Angular, Embar 的 static routing 範例

Backstory

- React Router, 是一個與 React 緊密結合的 Routing 解決方案

Dynamic Routing

- 與 static routing 不同, dynamic routing 被定義在 app 渲染裡
- Dynamic Routing 作為運行中的 App 的一部分
- 因此 React Router 幾乎所有的東西都是以 React component 樣貌實現

Nested Routes

- 實現 Nested Route 的方式, 不需要額外的設定
- 由於 Route 是以 React component 的方式實現, 因此就如同 component 的組合一樣, `<Route>` 是可以嵌套的
- 任何 component 都可以擁有自己的 Route, 這樣使用子代 component 的 Route 即可實現 nested routes

Responsive Routes

- 讓 RWD 轉換 Routing 設定, 由於 React Route 即是 React component, 因此 dynamic routing 意味著可以動態的改變 routing 設定
- 思考解決方案時把 React Router 視為 React component 的一部分, 而不是 static routing 才是 React Router 的作法
- [範例](https://reactrouter.com/web/guides/philosophy#responsive-routes) 實現依據畫面大小 (media query) 轉換 routing 設定, 來渲染出不同的 layout 的頁面與內容

#### Testing

- React Router 是通過 React Context API 來運作

Context

- 直接測試含有 React Router components 的元件會出現錯誤
- 在測試時需要使用 `<MemoryRouter>` 包覆協助 mock 必要的功能

Starting at specific routes

- 通過 `<MemoryRouter>` 的參數 `initialEntires`, `initialIndex` 指定路由狀態來測試

Navigating

- 自行測試 navigating
- 參考[範例](https://reactrouter.com/web/guides/testing#navigating)

Checking location in tests

- 檢查 history 或 location 物件狀態
- 在測試時加上額外的 `<Route>` 把資訊帶出來
- 參考範例

React Testing Library

- React 測試的 recipes
- [參考文件](https://testing-library.com/docs/example-react-router)

#### Deep Redux Integration

- 整合 Redux 與 React Router 狀態
- React Router 作者推薦不要把 Routing 資訊放入 Redux store 中, 理由如下

1. Routing 資訊通常已經作為 prop 被傳入 component 中
1. 非同步的 action 在 dispatch 後希望作到 navigating 由 React Router components 所攜帶的 `history` 物件 API 提供幫忙
1. Navigating 與 Redux DevTool 的 time travel debugging 無關

- 如果有強烈的需求需要整合 React Router 與 Redux 可以通過第三方函式庫 `connected-react-router` 實現, [參考文件](https://github.com/supasate/connected-react-router)

#### Static Routes

- React Router 從 v4 版開始已經從 static routing 轉換成 dynamic routing 
  - 因此 static routing 已經沒有必要
- 在 React Router 使用 static routing config 則[參考 API] (https://github.com/reacttraining/react-router/tree/master/packages/react-router-config)

### 第二章 - Examples

### 第三章 - API
