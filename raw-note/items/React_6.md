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

Basic

- 基本的三頁 routing

URL Parameters

- 通過 `useParams()` 取得 URL 資訊

Nesting

- 通過子代 component 擁有自己的 Routing 設定 `<Switch>`, `<Route>` 實現 nested routing
- 使用 `{ path, url } = useRouteMatch()` 取得 `path` 與 `url` 用來協助實作 nested routing

Redirect (Auth)

- 實現授權與 Login Redirect
- 使用 `useHistory()` 取的 history object, 利用 `history.push` 與 `history.replace` 改變路由狀態
- 使用 Dynamic routing 實現授權與非授權的 Routing 差別

Custom Link

- 客製化 `<Link>` 標籤
- 使用 `useRouteMatch()` API 取得 Routing 狀態, 協助渲染不同樣式

Preventing Transitions

- 使用 `import { Prompt } from "react-router-dom";` 實現 navigation blocking

No Match (404)

- 使用 `<Route path="*"></Route>` 提供 404 頁
- 使用 `useLocation()` 取得 location 資訊協助呈現 404 資訊 (`location.pathname`)

Recursive Paths

- 通過 dynamic routing 在動態依據資料產生新的 routing 設定
- 使得 URL 可以持續的成長成 recursive paths
- 例如檔案系統的路由實現

Sidebar

- 兩個 component 共用相同的 routing 設定, 實現分開但是同步的

Animated Transitions

- 利用 Location 的參數實現動態渲染
- 範例使用 URL 參數的顏色生產器

Route Config

- 通過自訂的 Route config 實現實際的路由行為
- 由於 Route Config 只是單純的設定資料, React Router 即 React Component, 因此只需要傳遞給 `<Route>` 即可實現

Modal Gallery

- 前後視窗互動同時改變 URL 路由

StaticRouter Context

- 試用 StaticRouter 並且以 staticContext 協助傳遞訊息
- 通常在 server-side rendering 時使用

Query Parameters

- 使用瀏覽器內建的 `new URLSearchParams()` API 協助分析 query string
- 使用 `useLocation().search` 取的 query string 的值

### 第三章 - API

#### Hooks

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/Hooks)

`useHistory`

- 取得 history 物件

`useLocation`

- 取得 location 物件, 代表當前的 URL
- 可以利用動態改變的 location 值配合 `useEffect(, [location])`, 實現 page view tracking

`useParams`

- 取得當前 URL 的參數 key value pair 的值
- 用來讀取當前 `<Route>` 的 `match.params` 資訊

`useRouteMatch`

- 使用 `useRouteMatch` 來嘗試驗證當前路由狀態, 等同於 `<Route>` 的路由驗證
- 可以使 component 在不需要 `<Route>` 的情況下進行路由驗證

#### `<BrowserRouter>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/BrowserRouter)

描述

- `<BrowserRouter>` 使用 HTML5 history API (`pushState()`, `replaceState()`, `popState` event) 實現路由

參數

- 參數 `basename`, string, 提供 base URL
- 參數 `getUserConfirmation`, function, 預設是 `window.confirm`
- 參數 `forceRefresh`, boolean, 在 navigation 時會全頁重新整理
- 參數 `keyLength`, number, `location.key` 的長度, 預設是 6
- `children`, node, 渲染的子元件

#### `<HashRouter>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/HashRouter)

描述

- `<HashRouter>` 使用 `window.location.hash` 實現路由
- 不支援 `location.key`, `location.state`
- 提供給舊的瀏覽器使用為主

參數 

- 參數 `basename`, string, 提供 base URL
- 參數 `getUserConfirmation`, function, 預設是 `window.confirm`
- 參數 `hashType`, string, 提供 hash 路由的選擇, 預設是 slash
- `children`, node, 渲染的子元件 

#### `<Link>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/Link)

描述

- 宣告式, 可互動的 navigation 

參數

- 參數 `to`, string, 連結到的 location 字串
- 參數 `to`, object, 連結到的 location 以物件表示 `{ pathname, search, hash, state }`
  - `pathname`, 連結到的 path
  - `search`, 連結到的 query string
  - `hash`, 連結到的 #
  - `state`, 維護 `location` 用的參數
- 參數 `to`, function, `location => {}`, 自動帶入當前的 location, 回傳值為上述說明的 string 或 object 
- 參數 `replace`, boolean, 值為 `true` 時, 會修改當前的 history stack 而非加入一個新的
- 參數 `innerRef`, function, React > 16 以後不需使用, 可以通過 [Forwarding Refs](https://reactjs.org/docs/forwarding-refs.html) 取得
- 參數 `innerRef`, ref object, React > 16 以後不需使用, 可以通過 [Forwarding Refs](https://reactjs.org/docs/forwarding-refs.html) 取得
- 參數 `component`, 實現客製化 navigation component 時使用
- 其他參數, 所有 `<a>` element 的參數都可以傳遞給 `<Link>`

#### `<NavLink>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/NavLink)

描述

- 特殊版本的 `<Link>` 當 match 時會自動加上樣式

參數

- 參數 `activeClassName`, string, 當 match 時會加上的 class name, 預設是 `active`
- 參數 `activeStyle`, object, 當 match 時會加上的 style
- 參數 `exact`, boolean, 只有當嚴格 match 時才會觸發, 預設是 `false`
- 參數 `strict`, boolean, 對應 `<Route strict>` 驗證方式, 預設是 `false`
- 參數 `isActive`, function, `(match, location) => {}`, 客製化驗證函式
- 參數 `location`, object, 在 `isActive` function 的 location 可以客製化傳遞其他的 location 物件
- 參數 `aria-current`, string, 提供無障礙字串 `aria-current` attribute, 預設是 `page`, 參考[規格](https://www.w3.org/TR/wai-aria-1.1/#aria-current)

#### `<Prompt>`

- API 文件含有範例, [文件連結](https://reactrouter.com/core/api/Prompt)

描述

- 移動前的提示視窗

參數

- 參數 `message`, string, 描述字串
- 參數 `message`, function, `(location, action) => {}`, 回傳值為 string 描述字串, `true` 允許移動
- 參數 `when`, boolean, 取代條件渲染 `<Prompt>`, 可以通過參數 `when` 啟用或關閉功能

#### `<MemoryRouter>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/MemoryRouter)

描述

- 使用 memory 實現路由
- 通常使用在測試或非瀏覽器環境, 例如 React Native

參數

- 參數 `initialEntries`, array, 初始化 history stack, 可以用字串或者物件表示
- 參數 `initialIndex`, number, 初始化 history 位置
- 參數 `getUserConfirmation`, function, 使用到 `<Prompt>` 時需要提供
- 參數 `keyLength`, number, `location.key` 長度, 預設是 6
- `children`, node, 渲染的子元件

#### `<Redirect>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/Redirect)

描述

- 渲染 `<Redirect>` 會觸發 navigate 到新的 location, 並且改寫當前的 history stack, 類似 server-side redirect (HTTP 3xx)

參數

- 參數 `to`, string, 要轉導到的 URL
- 參數 `to`, object, 使用物件描述的轉導 URL, 可攜帶 `state: { referrer }`
- 參數 `push`, boolean, 新增到 history stack 取代改寫
- 參數 `from`, string, 使用 `from` 取代 `<Route>` 作為 `<Switch>` 的直接子代, 達到 match 與 redirect 的功能
- 參數 `exact`, boolean, `from` 的比對參數, 等同於 `<Route exact>`
- 參數 `strict`, boolean, `from` 的比對參數, 等同於 `<Route strict>`
- 參數 `sensitive`, boolean, `from` 的比對參數, 等同於 `<Route sensitive>`

#### `<Route>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/Route)

描述

- React Router 中最重要的 component
- 提供 path 的 match 並且渲染對應的 UI
- 當 match 時會渲染直接子代 component (children)
- 如果當相同的 component 被不同的 `<Route>` 所指定時, 預設是固定的同一個 component, 即 state 會被保存並不會被重新創造
  - 可以通過給予 `<Route>` 不同的 `key` 來觸發每次都是新建的 component 並且各自獨立 (類似 React key 的用途)

Route render methods

- 提供渲染 component 的三種方式, 推薦使用 children 直接子代的方式
- `<Route component>`
- `<Route render>`
- `<Route children>`

Route props

- 預設的三個 props
- `match`
- `location`
- `history`

參數

- 參數 `component`, component element, 指定渲染 component 的一種方式
  - 使用 `component` 參數作為 render component 指定時, 每一次 match 都會呼叫一次 `React.createElement` 創建新的 component
  - 在切換時每次都會創建新的 component 並且 unmount 舊的, 取代修改舊的 component (`render` 與 `children` 方法)
- 參數 `render`, function, 指定渲染 component 的一種方式
  - 提供 render function, 避免類似 `component` 參數的創建新的並且 remounting
  - render function, 會自動夾帶 `routeProps` (`{ match, location, history }`), 可以藉此傳遞給實際渲染的 component
  - `component` 參數優先於 `render` 避免在同一個 `<Route>` 同時使用
- 參數 `children`, function, 指定渲染 component 的一種方式
  - 不管有沒有 match 都會渲染回傳的 component, 
  - children function 會自動夾帶 `routeProps`, (`{ match, location, history }`), 可以藉由 match 給予不同的行為, 因為回傳的 component 不管有沒有 match 都會被渲染出來
- 參數 `path`, string / string[], 指定 match 的路徑, 如果沒有帶 `path` 參數則一定會 match
- 參數 `exact`, boolean, match 時的 path 需要完全相等
- 參數 `strict`, boolean, match 時的結尾 `/` 是否比對, `strict` true 時, 嚴格比對結尾的 `/`
- 參數 `location`, object, 客製化 match 時的 location, 如果 `<Switch>` 有指定 location 則會覆蓋 `<Route>` 的設定
- 參數 `sensitive`, boolean, 是否區分大小寫, 預設是 false

#### `<Router>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/Router)

描述

- 各種 Router component 的基本 interface
- 使用時機通常在整合 state management 時才會使用 `<Router>`
- 一般情形會選用 `<BrowserRouter>`, `<HashRouter>`, `<MemoryRouter>`, `<NativeRouter>`, `<StaticRouter>` 則一

參數

- 參數 `history`, object, 指定使用的 history 物件
- 參數 `children`, node, 渲染的子代

#### `<StaticRouter>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/StaticRouter)

描述

- 一種永遠不改變 location 的 `<Router>`
- 通常在 server-side rendering 或測試時使用

參數

- 參數 `basename`, string, base URL
- 參數 `location`, string, 目前收到的 location, 在 node 上通常是 `req.rul`
- 參數 `location`, object, 指定 location 的物件類型 (`{ pathname, search, hash, state }`)
- 參數 `context`, object, 純 JavaScript 物件, 在渲染時可以把值帶給 context 未來在取用, 可以藉此取得渲染結果狀態
- 參數 `children`, node, 渲染的子代

#### `<Switch>`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/Switch)

描述

- 渲染第一個 match 的 `<Route>` 或 `<Redirect>`
- `<Switch>` 是用來則一渲染的, 必定只有一個路由渲染會觸發
- 不使用 `<Switch>` 時的連續 `<Route>`, 會渲染所有 match 的

參數

- 參數 `location`, object, 指定 match 時的 location, 預設是 current history location, 
  - 如果 `<Switch>` 的 location 有被額外指定時, 所有子代使用的 location 都會被複寫, 優先權較高
- 參數 `children`, node, 子代只能是 `<Route path>` 或 `<Redirect from>` 並且只有第一個 match 的子代會被渲染

#### `history`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/history)

描述

- React Router 所指的 history 都是來自函式庫 [history](https://github.com/ReactTraining/history)
- 作為各個平台統一的 `history` 介面
  - `browser history`, HTML5 history API, 較新的瀏覽器使用
  - `hash history`, 較舊的瀏覽器使用
  - `memory history`, 用於測試或沒有 DOM 的環境, 例如 React Native

`history`

- 屬性 `length`, number, history stack 目前擁有的數量
- 屬性 `action`, string, 目前的動作, `PUSH`, `REPLACE`, `POP`
- 屬性 `location`, object, 目前的 location 包含以下屬性
  - `pathname`, string, URL 路徑
  - `search`, string, URL query string
  - `hash`, string, URL #
  - `state`, object, 額外夾帶的資料
- 方法 `push(path, [state])`, 加入新的 entity 到 history stack
- 方法 `replace(path, [state])`, 修改 history stack 當前的 entity
- 方法 `go(n)`, 指標位移 history stack 中 n 項
- 方法 `goBack()`, 等價於 `go(-1)`
- 方法 `goForward()`, 等價於 `go(1)`
- 方法 `block(prompt)`, 防止移動

history is mutable

- 由於 history 是時常變動的, 因此在使用 location 時, 最好使用 `<Route>` 所代的 props, 而非從 `history.location` 取用
- history 細節可以參考函式庫[文件](https://github.com/ReactTraining/history/tree/master/docs)

#### `location`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/location)

描述

- 表達目前的位置, 並且夾帶一些資訊, 結構類似於 `{ key, pathname, search, hash, state: {}}`

取得 location

- `<Router>` 會複製並且傳遞 location
  - `<Route component>`, 作為 props 傳遞, `this.props.location`
  - `<Route render>`, 作為 function input 傳遞, `({ location }) => ()`
  - `<Route children>`, 作為 function input 傳遞, `({ location }) => ()`
  - withRouter, `this.props.location`
- 以上方式取得的 location 是 immutable 的, 因此可以放心的使用


接收 location 物件

- `<Link to={location}>`, 作為 `to` 的值
- `<Redirect to={location}`, 作為 `to` 的值
- `history.push(location)`, 作為 function input
- `history.replace(location)`, 作為 function input
- `<Route location>`, 作為 `location` 的值, 用來執行渲染但是不實際移動
- `<Switch location>`, 作為 `location` 的值, 用來執行渲染但是不實際移動

#### `match`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/match)

描述

- match object, 包含 `<Route path>` 在進行 match 時的資訊, `{ params, isExact, path, url }`
  - `params`, object, 比對時的路徑參數
  - `isExact`, boolean, 是否符合 exact match
  - `path`, string, 用來比對的 path, 即 `<Route path>`
  - `url`, string, 受驗證的 URL

取得 match object

- `<Route component>`, 以 `this.props.match`
- `<Route render>`, 以 `({ match }) => ()`
- `<Route children>`, 以 `({ match }) => ()`
- withRouter, 以 `this.props.match`
- `matchPath` 的回傳值
- `useRouteMatch` 的回傳值
- 當 `<Route>` 沒有 path 屬性時, 會取得最近的父層 match

null matches

- `<Route>`, 一定會呼叫 `children` function 就算 path 沒有 match, 這時候 `match` 的值會是 `null`
- 當使用 `match.url` 組合 nested path 時, 可能會因為 `null` 產生 TypeError
- 並且這種 `null` match 會被傳遞到所有子代 `<Route>` 的 `match`, 需要額外處理

#### `matchPath`

- API 文件含有範例, [文件連結](https://reactrouter.com/web/api/matchPath)

描述

- 取得 `<Route>` 的 path match 驗證方式
- 可以在不新增 `<Route>` 的情況下測試路徑
- `match matchPath(pathname, props)`, function, 

參數

- 參數 `pathname`, string, 想要驗證的 path
- 參數 `props`, object, 驗證標準, 即 `<Route path>` 欄位, props 物件結構為 `{ path, strict, exact }`
  - `path`, 等同於 `<Route path>`
  - `strict`, 選用, 比對時的 strict mode
  - `exact`, 選用, 比對時的 exact mode
- 回傳值, `match` object, 驗證成功時回傳 `{ params, isExact, path, url }`
  - 驗證失敗時回傳 `null`

#### `withRouter`

- API 文件含有範例, [文件連結](

描述

- `withRouter`, function, React 的 hight-order component (HOC), 提供連結 React Router `history` 與最近的 `<Route> match` 的能力
- 使用 `withRouter` 連結 React Router 的資訊, 在變動時不會觸發 re-rendering, 即資料與 `setState` 無關, 為單純的取值功能

Component.WrappedComponent

- 使用 `withRouter` 包覆回傳的 component, 可以通過 `.WrappedComponent` 取得原始的 Component
- 可以用在測試

wrappedComponentRef

- 通過 `wrappedComponentRef` 參數取得原始物件的 ref, 以 callback function input 的方式取得
- Example: `<OuterComponent wrappedComponentRef={( componentRef ) => ()} />`
