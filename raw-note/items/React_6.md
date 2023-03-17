## React Router Official Documents

### [Website resource](https://reactrouter.com/), React/React_Router

---

第一章 - Getting Started

第二章 - Upgrading

第三章 - Routers

第四章 - Router Components

第五章 - Route

第六章 - Components

第七章 - Hooks

第八章 - Fetch Utilities

第九章 - Utilities

第十章 - Guides

---

### 第一章 - Getting Started

Feature Overview

- Client Side Routing
  - 提供在切換 route 時不需要發送 request, 可以在不需要後端配合的情況下進行 routing
- Nested Routes
  - 允許巢狀 routing
- Dynamic Segments
  - 動態的 pathname 對應
- Ranked Route Matching
  - 具有權重的 routing 設定
  - 越專精的選擇權重越重, 如同 CSS selector 一樣
- Active Links
  - 提供 API 實現取得當前被觸發的 route 來協助 styling
  - `NavLink` API, `useMatch` API
- Relative Links
  - Link API 允許以 relative path 來指定路徑
- Data Loading
  - 配合 routing 的 data fetching
  - 在 Route 設定時就撰寫 loader 在切換時才呼叫, 並以 `useLoaderData()` API 取值
- Redirects
- Pending Navigation UI
  - 提供 loading 狀態, 用來實作過度時的 fallback component
- Skeleton UI with `<Suspense>`
  - React Router loader + `defer` 配合 React Suspense 實現 Skeleton fallback
- Data Mutations
  - Route 連動 form action, 讓 form action 的 endpoint 可以指向 client-side routing 來處理
- Data Revalidation
- Busy Indicators
  - 配合 form action 時, 可以取得 submitting 狀態, 來協助阻擋重複發送
- Optimistic UI
  - 配合 form submit 時, 不必等待工作結束即可優先提供 UI 狀態
- Data Fetchers
  - 使用 form 的慣例語法但是不必 navigation 並且允許多個同時觸發
- Race Condition Handling
  - 由非同步行為可能產生的錯誤
- Error Handling
  - 由 React Router 來捕捉錯誤, 觸發指定的 component 處理
- Scroll Restoration
  - 自動處理和記錄 scroll 後的正確位置, 在 navigation 後能保持正確的位置
- Web Standard APIs
  - React Router 實作時參考標準 API 的介面
  - 例如 Fetch API 的 Request, Response, 和 Abort Signals
- Search Params
- Location State

Tutorial

- 以範例的 tutorial 練習

Examples

- 提供多個應對不同需求的範例程式碼
- 像是 auth, custom, lazy loading, modal 等等

FAQs

Main Concepts

- 詳細討論 React Router 實作概念
- 當前版本尚未依據 6.4 版而更新
- **可以閱讀依據 6.4 Data APIs 之後的版本**, 來更理解 React Router 的核心抽象概念

---

### 第二章 - Upgrading

Upgrading from v5

- 詳細的升版教學

Migrating from Reach Router to React Router v6

- 從 Reach Router 移植到 React Router v6 的教學

---

### 第三章 - Routers

Picking a Router

- 選擇適當的 Router 機制
- v6.4 Data APIs
  - 有重大的更新, 需要使用特定的 Router 才有支援
  - `createBrowserRouter`, `createMemoryRouter`, `createHashRouter`
- 舊版不支援 v6.4 Data APIs 的 Router
  - `<BrowserRouter>`, `<MemoryRouter>`, `<HashRouter>`, `<NativeRouter>`, `<StaticRouter>`
  - 推薦升版後改用新的 Router
  - 可以通過 API 協助直接轉換 `createRoutesFromElements`
- Web Projects
  - 推薦使用 `createBrowserRouter`, 在 pushState 已經成為標準後應該棄用 HashRouter
  - 再來才依序是 `createHashRouter`, `<BrowserRouter>`, `<HashRouter>`
- Testing
  - 在測試環境可以改用 `createMemoryRouter`, `<MemoryRouter>` 取代直接呼叫 DOM History API
- React Native
  - 目前只能使用 `<NativeRouter>` 直到未來支援 Data APIs

`createBrowserRouter`

- 內部使用 DOM History API 實現
- 並且啟用 v6.4 Data APIs 支援 loaders, actions, fetchers 等功能
- `basename`, 提供額外的前墜
- `window` 替換原生的 window
- `routes` 定義路由並且通過 `children` 允許 nested routes

`createHashRouter`

- 不推薦使用, 只有在完全無法控制 server 時候才有機會使用

`createMemoryRouter`

- 取代 browser History API 改用其他方式記憶, 主要用於測試環境或是其他無法使用 browser 的環境, 例如 Storybook, Jest 等
- 提供額外的參數, 協助測試
  - `initialEntries`, 初始化的 history stack 方便 mock
  - `initialIndex`, 初始化的 index 位置, 方便測試

`<RouterProvider>`

- 所有的 router 都要通過這個 Provider 形成 React context
- `fallbackElement`, 允許使用額外的 fallback component 提升使用者體驗

---

### 第四章 - Router Components

- 先前版本的 Router 並且已經內建 React Context

`<BrowserRouter>`

- 使用瀏覽器原生的 history stack 和 APIs

`<HashRouter>`

- 不推薦使用
- 在無法控制 server-side 的情況下
- 使用 `hash`, (`#`) 在 URL 實現 client-side routing

`<MemoryRouter>`

- 以與瀏覽器無關的實作實現, 因此可以自行控制 stack 和 index
- 通常用於測試環境

`<NativeRouter>`

- 在 React Native 環境也能使用的 React Router

`<Router>`

- 底層的介面, 各個 Router components 都符合

`<StaticRouter>`

- 在 Node.js 環境使用的 React Router
- 可能用於 server-side rendering 時共用相同的 routing 程式碼

---

### 第五章 - Route

`Route`

- 最重要的元件
- 是一個被傳遞給 Router 的物件, 可以以物件的方式存在或者 JSX Component 的方式
- 直接傳遞物件或 JSX + `createRoutesFromElements()` 轉譯成物件的方式傳遞
- `interface RouteObject`, 包含參數
- `path?: string`, 對應的 URL pattern
  - `:` 形成 Dynamic Segments, 會變成 `params` 讓其他元件取得
  - `?` 形成 Optional Segments, 變成選用
  - `*` 形成 Splats (catchall, star segments), 變成任意, 可以從 `params` 中以 `*` 為 key 取值
  - 沒有 `path` 值的 Layout Routes, 配合 `<Outlet />` 指定 child route 渲染的位置
- `index?: boolean`, 指定為 index 時的 route, 不需要有 `path`
- `children?: React.ReactNode` 形成 nested route
- `caseSensitive?: boolean`, 是否大小寫有別, 預設是 `false`
- `loader?: LoaderFunction`, 在 Route 渲染前會呼叫, 以提供資料, 配合 `useLoaderData` 在 element 中取值
- `action?: ActionFunction`, 路徑被 Form submit, fetcher, submission 時會觸發的函式
- `element?: React.ReactNode | null;`, `Component?: React.ComponentType | null;` 渲染時的元件
- `errorElement?: React.ReactNode | null;`, `ErrorBoundary?: React.ComponentType | null;` 錯誤處理時的元件
- `handle?: RouteObject["handle"];`, 配合 `useMatches` 時的特殊值
- `lazy?: LazyRouteFunction<RouteObject>`, lazy load, 配合 dynamic import 實現

`action`

- Data API, Route action 處理 **writes**, Route loader 處理 **reads**
- Action function 會在接收到 `get` method 以外的 HTTP methods 時觸發,
  - 例如 `post`, `put`, `patch`, `delete`
  - 觸發方式有
  - `<Form action>`,
    `<fetcher.Form action>` 的 `fetcher.submit`, -`useSubmit()` 的 `submit`,
- `params`, action function input 會收到 dynamic segments 的 params
- `request`, action function input 會收到 Request object, 可以藉由 `request.formData()` 取值, `formData` 會被序列化, 因此必須要配合 `name` 使用
- Returning Responses, 回傳, 配合 `useActionData` 可以在別地方取得這個回傳值
- Throwing in Actions, 在 action function 裡可以使用 `throw` 進行錯誤處理, React Router 會自動進入錯誤處理流程

`errorElement`

- 當 exceptions 從 loader function, action function, 或 component 被丟出後 (throw) 會進入 Route 中的 `errorElement` 進行錯誤處理程序
- 可以建立一個 ErrorBoundary 以 `useRouteError()` 統一處理錯誤
- Bubbling, 如果當前觸發的 Route 不存在 `errorElement` 時, 錯誤會往上層傳遞
- Default Error Element, 因為有 bubbling 機制因此推薦起碼在最上層有一個 error element 統一處理, 提供更好的使用者體驗
- Throwing Manually
  - 當在 loader function 或 action function 裡處理對外的工作時, 非常有機會會出現不可控制的狀況, 因此可以主動以 `throw` 丟出錯誤, 讓 React Router 進入錯誤處理程序
  - 例如 `throw new Response("Not Found", { status: 404 })`
  - 讓資料沒辦法渲染時, 跳出渲染程序, 進入錯誤處理
  - `throw` 可以丟出任何東西, 包含 `Response`, `error`, 任何物件
- Throwing Responses
  - 如果 `throw` 丟出 `Response` 以外的東西可以使用 `useRouteError()` 取得
  - 如果是 `Response` 時, React Router 會自行 parse 且封裝進 `data` 裡, 配合 `useRouteError` 時更容易取值, 因為有慣例的 pattern
  - 可以配合 `isRouteErrorResponse(error)` 判斷回傳值是否是 Response object
- Abstractions
  - 因為有自動捕捉的錯誤處理, 可以更好的進行抽象化, 讓特定的錯誤處理存在直接相關的地方
  - [範例](https://reactrouter.com/en/main/route/error-element#abstractions)
  - 讓你在任何的處理時, 如果發現不是預期的結果時只要自然地丟出錯誤即可 `throw`
  - 更專注在 happy path 上, 而不用到處進行防禦性程式碼

`lazy`

- 讓程式碼減小 bundle size 並且支援 code splitting
- 使用 `lazy` 傳遞 dynamic import
- 只能作用在已知的 Route
- Lazy load 會發生在 initial load 或 `loading` 或 `submitting` 階段
- Statically Defined Properties
  - 同時動態載入 loader function 和 render function, 並且可以平行下載不會互相等待
  - [參考範例](https://reactrouter.com/en/main/route/lazy#statically-defined-properties)
- Multiple Routes in a single file
  - 可以使用重複的 dynamic import 讓下載集中在同一個檔案中, 並且不會重複觸發
  - [參考範例](https://reactrouter.com/en/main/route/lazy#statically-defined-properties)
  - 可以實現一些動態 preload 的情境

`loader`

- loader function 在觸發 Route 並且進入 render 之前觸發
  - 主要用來取得 render component 所需要的資料
  - render function 可以通過 `useLoaderData()` 取得資料
- loader function input, `params` 取得 dynamic segments 的值
- loader function input, `request` 取得呼叫的 request
- Returning Responses
  - 可以直接回傳 fetch `Response` object
  - 並且 `useLoaderData()` 會自動呼叫 `response.json()`, 因此使用時不用再處理
  - `json()` util 可以協助產生 `Response` object
- Throwing in Loaders
  - 在 loader function 中可以主動 `throw` 錯誤, 讓 React Router 進入錯誤處理模式, 而不用接續的 render

`shouldRevalidate`

- 作為一個效能優化方式, 避免 loader function 不必要的重複觸發
- 有多個機會會自動觸發 loader function 重新觸發來確保資料最新
  - 經過 action function 後
  - URL params 改變
  - URL Search params 改變
  - 重複進入相同的 URL
- 可以在 Route 中定義 `shouldRevalidate` 提供一個回傳 boolean 的函式, 來決定是否觸發 loader function
- 此作法會破壞原本的資料更新機制, 需要小心使用

---

### 第六章 - Components

`<Await>`

- 使用 deferred value 時需要配合使用的 Component
- 利用 `<Await>` 包裹擁有 defer loader function 的子代 component
- 這樣可以在 `<Await>` 的父層使用 `<React.Suspense fallback={}>` 來提供 fallback component
- 參數會包含
- `children`, 有兩種方式實現包裹擁有 defer 的 component
  - 直接在子代以 function 傳遞
  - 渲染一個 Component 並且在該 Component 中以 `useAsyncValue` 來處理後續
- `errorElement`, 進行捕捉 loader function error
- `resolve`, 傳入來自對應 defer loader function 所回傳的 Promise

`<Form>`

- 一個包裹原生 form element 的 Component 來實現擷取 request 轉拋給 React Router 的功能
- 並沒有 Form Validation 的功能, 需要自行實現, 官方推薦使用瀏覽器原生的 validation 配合後端接收資料時的檢查
- **必須確保所有的 input 都有 `name`** 否則 FormData 不會拿到
- `action`
  - 以類似原生的 submit 一樣, 只是變成把 Form Request 轉交由某個 React Router client-side 的 Route 處理
- `method`
  - 提供各種不同的 HTTP methods 包含 `put`, `patch`, `delete`, `post` 也包含 `get`
- Get submissions
  - method 使用 `get` 時, 並不會觸發 action function 而是會像一般的 navigation 一樣
  - [範例](https://reactrouter.com/en/main/components/form#get-submissions), 搜尋功能的實現
- Mutation Submissions
  - 會觸發指定 Route 上的 action function
  - 可以藉由 action function 的 input, `request.method` 來進行不同 method 產生的行為, 因此可以共用同一個 Route path
- `replace`
  - 觸發替換當前 history 而非 push
  - 原本是為了避免使用者使用上一頁功能, 導致重複發送的 request
  - 但是 React Router 的行為並不會觸發重複的 request
  - 因此 `replace` 得使用情境只有在 Get submission 不希望使用者看到舊的資料時
- `relative`
  - 以 relative path 來實現 action 位置, 需要配合 `to` 和 `relative='path'`
- `reloadDocument`
  - 跳脫 React Router 的控管, 觸發原生的 form submission 行為
- `preventScrollReset`
  - 配合 `<ScrollRestoration>` 使用避免 Form submit 後重置的位置

`<Link>`

- 讓使用者實現 client-side routing 的 navigation
- 一個封裝的 `a` link
- `<Link to>` 可以使用絕對路徑和相對路徑
- `relative` 實現相對路徑的 `to`, 配合 `relative='path'`
- `preventScrollReset`
  - 配合 `<ScrollRestoration>` 使用避免 scroll 重置
- `replace` 以 `history.replaceState` 取代 `history.pushState`
- `state` 傳遞特定的值, 可以配合 `useLocation` 取值

`<Link>` (React Native)

`<NavLink>`

- 特殊版的 `<Link>` 可以取得 pending, active 狀態,
- 適合用在 breadcrumb 或多個 tabs 要實現 active 狀態時
- 預設會自動加上 `active` class name
- `className`
  - 配合 className 可以通過 callback function 取得 `isActive` 和 `isPending` 狀態來實現客製化的 class name
- `style`
  - 也可以通過 callback function 取得 `isActive` 和 `isPending` 狀態來實現客製化的 inline style
- `children`
  - 也可以通過 也可以通過 callback function 取得 `isActive` 和 `isPending` 狀態來實現客製化的 child component
- `end`
  - 通常用在 `/` 因為所有的 path 都會符合 `/` 因此無法區分 active
- `caseSensitive`
- `aria-current`
  - 當 NavLink 是 active 時會自動帶入 `aria-current='page'` 提供無障礙功能

`<Navigate>`

- 當 `<Navigate>` 被渲染時直接觸發 navigation 到指定的 URL
- 等價於使用 `useNavigate` hook, 共用相同的 props,
- 只是一個 wrapper component

`<Outlet>`

- 用於 parent route 用來指定 child route 的渲染位置
- 通常用於實作共用 Layout
- 如果是 parent route 被 match 時會一同渲染 child route 的 index route 如果存在的話

`<Routes>`

- 在 v6.4 Data APIs 之後, 如果使用 `createBrowserRouter` 的話應該很少機會會使用到 `<Routes>`
- 用於舊版定義 Routes 時使用
- 作為各個 `<Route>` 的頂層

`<ScrollRestoration>`

- 在 loader function 結束時確保 render component 的 scroll 位置, 避免重智
- 整個 App 裡應該只會有一個, 推薦放置在 root route 的 render component 裡
- `getKey` prop
  - 當一個 App 有多個區塊和 scroll 區塊時, 可以客製化設定
- Preventing Scroll Reset
  - 當 navigation 產生新的 scroll key 時通常會重置
  - 在 `<Link>`, `<Form>` 都有 `preventScrollReset` prop 可以讓 navigation 後不要重置
- Scroll Flashing
  - 在初次渲染時, 因為是 client-side rendering 所以 DOM tree 是動態建立, 可能會導致閃動
  - 解法需要配合 Server-side Rendering framework 在第一時間就提供更完整的 DOM

---

### 第七章 - Hooks

`useActionData`

- 取得前一次的 action function 的回傳值
- 常見的使用情境是處理 form validation error
  - 在 action function 回傳 validation errors 後由 render function 處理提供給使用者

`useAsyncError`

- 取得從 `<Await>` component 中 Promise.reject 時的 error
- 使用於 `<Await>` component 的 `errorElement` 裡

`useAsyncValue`

- 用來取得最近上層的 `<Await>` component 的 resolve 值
- 通常用於分離 component 實作的 `defer`, `<Await>` 情境

`useBeforeUnload`

- 作為 `window.onbeforeunload` 的 helper function
- 提供在 navigation 前, 有機會處理
- 通常用於 navigation 前的資料處理, 例如儲存現有的 form value 到 local storage 的使用情境

`useFetcher`

- 瀏覽器原生的 `<a href>` 和 `<form action>` 就是用來處理 mutation 和 loads 並同時 navigation
  - 對應 React Router 的 `<Link>` 和 `<Form>` components
- `useFetcher` 提供一個機會去觸發 loader function 或 action function **但是不進行 navigation**
- 常見的使用情境有
  - fetch data 但是與 UI routes 無關時
  - submit data 但是不需要 navigating
  - handle multiple concurrent submissions in a list
  - infinite scroll containers, (需要不斷載入資料但是不用 navigation)
- 如果在建立高度互動性的 app 時, 會很常使用到 `useFetcher`
- 很多預設的行為
  - 當 fetch 中斷時自動處理 cancellation
  - 使用 POST, PUT, PATCH, DELETE 等 methods 時會先觸發 action function
  - 當有多個 fetchers 同時進行時, 會正確處理呈現最新資料, 避開資料時間差的問題
  - 捕捉 errors 並渲染最近的 `errorElement` 處理
  - 當呼叫的 action 或 loader function 回傳 redirect 時, 會進行 redirect
- `fetcher.state`
  - `idle`,
  - `submitting`, 已經觸發 POST, PUT, PATCH 或 DELETE 時
  - `loading`, 觸發 loader (fetcher.load) 或 revalidate (submission 結束或 `useRevalidator`) 中
- `<fetcher.Form>`
  - 如同 `<Form>` 只差不會 navigation
- `fetcher.load()`
  - 去觸發指定路徑的 loader function
- `fetcher.submit()`
  - 指令版的 `<fetcher.Form>`, 通常用於不需要使用者介入的 action
- `fetcher.data`
  - 取得 loader 或 action function 的回傳值
- `fetcher.formData`
  - 用來取得當前的 formData, 來自 `<fetcher.Form>` 或 `fetcher.submit()`
  - 可以依據 formData 提供動態的 UI
- `fetcher.formAction`
  - 用來取得對應 `<fetcher.Form action>` 的 action URL
- `fetcher.formMethod`
  - 用來取得對應 `<fetcher.Form method>` 的 method

`useFetchers`

- 用來取得其他 fetcher 的值和狀態, 但是無法控制他們
- 通常用於優化 UI 其他 component 的 UI 可能會建立在一些 fetchers 的狀態上
- 參考實作[範例](https://reactrouter.com/en/main/hooks/use-fetchers#usefetchers)

`useFormAction`

- 由 `<Form>` 內部使用
- 使用情境非常不常見, 但是他允許你直接讓 HTML `<button>` 指定 `formAction` 到 React Router 的 action function

`useHref`

- 儘管在 React Router 以外也能取得指定 `<Link to>` 所對應的 URL

`useInRouterContext`

- 用來辨識當前 component 是否在 React Router context tree 內部
- 回傳 boolean

`useLinkClickHandler`, `useLinkPressHandler`

- 如果要進行客製化 `<Link>` 時, 會需要的 helper function

`useLoaderData`

- 取得當前 route loader function 的回傳值
- 只是取值並不會重複觸發 loader function
- 可以使用在任何的 component 或 hook 中, 他會自動取最近的 route

`useLocation`

- 用來取得當前的 `location` object,
- 用來處理特別的 side-effect, 例如 tracking page view

`useMatch`

- 回傳 match data 依據當前的 location 和指定的 path

`useMatches`

- 回傳當前 route 所有的 matches
- 可以配合 `<Route handle>` 使用傳遞任何值讓 `useMatches()` 可以取得
- `match` 是一個物件包含
  - `id`,
  - `pathname`,
  - `data`, 來自 loader function
  - `params`,
  - `handle`, 來自 `<Route handle>` 的任意值
- 範例用 `<Route handle>` 和 `useMatches()` 實現任何地方都適用的 Breadcrumbs component
- [參考範例](https://reactrouter.com/en/main/hooks/use-matches#breadcrumbs)

`useNavigate`

- 在 loader, action function 裡推薦使用 `redirect` 取代 `useNavigate`
- 回傳一個 `navigate` method, 觸發後會進行 navigation 到指定路徑

`useNavigation`

- 取得當前所有關於 navigation 的資訊
- 用來協助設計過渡時期的 UI
- `navigation.state`
  - `idle`
  - `submitting`
  - `loading`
  - GET: idle -> loading -> idle
  - POST, PUT, PATCH, DELETE: idle -> submitting -> loading -> idle
- `navigation.formData`
  - 取得當前的 formData
- `navigation.location`
  - 取得下一個 location 的位置

`useNavigationType`

- 取得當前的 navigation type 或知道當前使用者如何到達
- `type NavigationType = "POP" | "PUSH" | "REPLACE";`

`useOutlet`

- `<Outlet>` component 內部使用

`useOutletContext`

- 讓父層 component 可以通過 `<Outlet context>` 傳值
- 子代使用 `useOutletContext()` 取值

`useParams`

- 取得當前的 dynamic params 值

`useResolvedPath`

- `<NavLink>` 內部使用, 用來處理 relative path

`useRevalidator`

- React Router 一般會自動觸發 revalidate
- 可以通過 `useRevalidator` 取得然後手動觸發 revalidate
- 很少會需要手動觸發, 如果發現這種情境, 應該思考有沒有正確使用 `<Form>`, `useSubmit`, `useFetcher` 的模式
- `revalidator.state`
  - `idle`, `loading`
- `revalidator.revalidate()`
- useRevalidator 底層實作是 singleton, 因此儘管多次觸發取得仍然只有一個 revalidator 在運作

`useRouteError`

- 用在 `errorElement` 裡, 用來取得捕捉到的 error
- 可以配合 `isRouteErrorResponse` 來決定處理方式

`useRouteLoaderData`

- 用來取得跨層的 loader function data
- 如同一個可以指定的 context 專門用來取得各層的 loader data
- 需要在建立 Route 的時候提供 `id` 方便取值
- 並且只能取得現在有被 rendered 的 component
- 如果不存在會回傳 `undefined`

`useRoutes`

- 函式版的 `<Routes>`, 使用於 v6.4 以前

`useSearchParams`

- 取得和修改當前的 query string

`useSubmit`

- 命令版的 `<Form>` submit
- 提供 Data API 用的 `submit` function
- Submit target
  - 會依據放置的位置不同需要傳入不同的 target
  - [參考範例](https://reactrouter.com/en/main/hooks/use-submit#submit-target)
- Submit options
  - 可以指定 method 和 action

---

### 第八章 - Fetch Utilities

`json`

- 轉換資料封裝成 Response object 的 helper function

`redirect`

- 使用在 loader, action function 裡的 navigation
- 等價於封裝 redirect 的 Response object
- `url` prop, 指定的位置
- `init` prop, 選用的 Response

---

### 第九章 - Utilities

`createRoutesFromChildren`, `createRoutesFromElements`

- 用於喜歡以 JSX 建立 `createBrowserRouter` 時, 所需的 helper function

`createSearchParams`

- 簡化版的 `new URLSearchParams(init)` helper function

`defer`

- 實現 non-blocking loader function 時的 helper function

`generatePath`

- 協助以 dynamic segments 定義進行建立 path 的 helper function
- 提高可閱讀性的方式

`isRouteErrorResponse`

- 用來判斷 error 是否符合 `ErrorResponse` object
- 用來分辨後選用適合的解析方式
- React Router 當 mismatch 時也會自動丟出 404 `ErrorResponse`

`Location`

- an interface

`matchPath`

- `useMatch` hook 內部使用的函式版

`matchRoutes`

- React Router 核心的 matching 演算法呼叫的位置
- 多由 `useRoutes`, `<Routes>` 內部使用

`renderMatches`

- render `matchRoutes()` 的結果成 React element

`resolvePath`

- `useResolvePath` hook 內部使用的函式版

---

### 第十章 - Guides

Server-Side Rendering

- 待更新的文件, 並且只適用於 6.3 版本以下
- Server-Side Rendering 推薦直接使用 Remix
- 否則需要使用 `<StaticRouter>` 自行實現

Contributing to React Router

- 本專案是開源的, 並且歡迎貢獻

Data Library Integration

- React Router 並無異去提供功能並且取代其他資料取得相關的 library, 例如 `React Query`, `useSwr`
- React Router 處理 `when` 資料需要被觸發更新, 並沒有處理 `how`
- 範例中使用 React Query 整合進 React Router Data API 並且取代某些 hook
  - [範例](https://reactrouter.com/en/main/guides/data-libs#loading-data)

Deferred Data Guide

- Loader function 一般會 block 後續的 render function 直到取得資料並回傳
- 當 loader function 可能會處理很久時, 會導致使用者體驗降低
- 因此可以配合 React `Suspense` 提供 fallback component 讓使用者操作
- 需要配合 `defer`, `<Await>`, `useAsyncValue` 三個 API 實現
- 實作[參考範例](https://reactrouter.com/en/main/guides/deferred#using-defer)
- Evaluating the solution
  - 可以利用 await 在 defer 裡面實現回復成會 block 的行為
  - 利用這個特性可以簡單的實現 A/B testing
- Why don't Response objects returned by the loader work anymore?
  - 當使用 `defer` 時, 如果原本 render component 內的 Response 自動解析就會失效, 需要自行手動處理
  - [參考範例](https://reactrouter.com/en/main/guides/deferred#why-dont-response-objects-returned-by-the-loader-work-anymore)

Working With FormData

- 因為 React Router 擁抱原生的 Form Submit, 因此提供一些處理 FormData 的心得
- 文件還在更新中

Index Query Param

- `?index` 來處理特定的 Form action 時的 route matching

---

## 舊版文件 v4, v5

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
