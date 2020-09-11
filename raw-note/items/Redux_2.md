## Redux official tutorials

### [Website resource](https://redux.js.org/tutorials/tutorials-index), Redux

---

第一章 - Tutorials Index

第二章 - Redux Essentials

第三章 - Basic Tutorial

第四章 - Advanced Tutorial

---

### 第一章 - Tutorials Index

- Redux Essentials tutorial 是 top-down tutorial, 推薦優先
- Basic tutorial, Advanced tutorial 是 bottom-up tutorial, 內容可能較舊, 需注意更新

---

### 第二章 - Redux Essentials

#### Redux Overview and Concepts

Introduction

- 教學流程 Key concepts and terms -> Basic React + Redux App -> Real world features
- Prerequisites 前置需求, HTML/CSS, JavaScript ES6, React, asynchronous JavaScript and Ajax request
- 安裝開發者工具 Install React DevTools and Redux DevTools extensions

What is Redux?

- Redux 是一個模式與函式庫, 解決管理與更新應用程式狀態, 透過 `actions` 事件
- Why, Redux 使 state 的改變變得容易管理與預測
- When, Redux 在以下情境中很適用
  - 應用程式中有大量的狀態被分享
  - 應用程式的狀態會隨著時間而改變
  - 更新狀態的邏輯相對複雜
  - 應用程式擁有中等以上的 codebase 並且多人一起開發
- Redux libraries and tools, Redux 是極小的函式庫, 通常需要與其他工具一起運作, 例如
  - React-Redux, 連接 React library 的工具
  - Redux Toolkit, Redux 工具組合包
  - Redux DevTools Extension, 開發者工具

Redux Terms and Concepts

- State Management, 
  - state -> view -> action -> state, View 層依據 state 渲染, View 層觸發 action, Action 改變 state
  - 多個 View 層可能會依據相同的 State 用來渲染, 一般作法需要 Lifting state up 然後再由共同父層傳遞, 一層一層傳遞下去
  - 另一個解決方式是把狀態都存放在相同的地方, 把整個應用程式是唯一個巨大的 View 層
  - Redux 的基本概念就是把 state 集中在單一的地方, 利用這種方式讓更新 state 變成可預測性的

- Immutability
  - 不可變性
  - Array 與 Object 的複製可以使用 spread operator `...` 達成
  - Redux 預期所有的 state 變化都是 immutability 的完成, state 視為 read-only, reducer function 需為純函式

- Terminology
  - Actions, 一個 JavaScript Object 擁有 `type` property. 
    - 可以把 Action 視為一個事件的描述
    - `type` 是字串, 可以用 `"domain/eventName"` 的方式描述
    - Action object 可以含有其他資訊欄位, `payload`
  - Action Creators, 一個用來生成 `action` 的函式
    - 通常使用這種模式來生成正確的 `action`
  - Reducers, 一個輸入 `state` 與 `action` 並且回傳新的 `state` 的函式
    - `(state, action) => newState`
    - 命名由來因為與 `Array.reduce()` 有類似行為
    - `reducers` 必須: 只依據 `state` 與 `action` 計算新的 state
    - `reducers` 必須: 不能修改舊的 `state`, 要是不可變 (immutable) 的更新
    - `reducers` 必須: 不可以有非同步或其他副作用
  - Store, Redux `state` 存在於 `store` 中
  - Dispatch, 唯一更新 `state` 的方式, 就是通過 `dispatch` 函式觸發 `action`
    - 實務上常用呼叫 `action creators` 來傳遞 `action` 給 `dispatch`
  - Selectors, 一種傳入 `state` 回傳所需要的值的函式, getter 函式

- Redux Application Data Flow
  - 從原本的 one-way data flow
  - [改成 Redux 模式](https://redux.js.org/tutorials/essentials/part-1-overview-concepts#redux-application-data-flow), 也是一種 one-way data flow, 只是抽離成各個部份

#### Redux App Structure

The Counter Example App

- 使用 Create-React-App 配合 Redux template 生成專案, 已經包含了 `Redux Toolkit` 與 `React-Redux`
  - `npx create-react-app redux-essentials-example --template redux`
- 從 Redux DevTools 查看 `State`, `Diff`, `Action`
- Redux DevTools, `Trace` 追蹤 Action 觸發時的程式碼, 協助除錯

Application Contents

- 檔案結構, `/src` ->
  - `index.js`, 入口 js
  - `App.js`, Top React component
  - `/app/store.js`, 生成 Redux store instance 的程式碼
  - `/features`, 配合 duck pattern 

Create the Redux Store

- `configureStore()`, Redux Toolkit, 輸入包含 `reducer` 的物件, 取代 `createStore` 與 `combineReducers`
  - 利用此函式組合 `reducers` 會自動使用一些 middleware 提供更好的開發體驗, 取代 `combineReducers()`
- Redux Slices, 一個 `slice` 存放一個 Feature 所擁有的 Redux `reducer` 邏輯與 `actions`
  - 通常放在同一個檔案裡, duck pattern

Creating Slice Reducers and Actions

- `createSlice()`, Redux Toolkit, 輸入一個物件, 包含 `name`, `initialState`, `reducers`, 協助生成 slice 所需要的其他部份, 甚至 reducer 內部可以使用 mutating 寫法會自動優化成 immutable
- action 不需要自行撰寫, 通過 `createSlice()` 的 slice `.actions`, 直接取得 `action` 物件
  - `type` 由 slice name 與 reducer name 組成
- `createSlice()` 的 slice `.reducer`, 取得所需要的 reducer
- Action Creators 不需要自行撰寫, 也由 `createSlice()` 自動生成, 函式名稱等同於 reducer name

Rules of Reducers

- Reducer 必須要是 pure function 的原因
  - Redux 目標是讓程式碼可預測, 只有 pure function 能確保輸出
  - Pure function 讓函式與呼叫時間去耦合
  - 有些 Redux DevTools 的功能假定 reducer 是 pure function 才能正確運行
  - immutable update 至關重要

Reducers and Immutable Updates

- Reducer 需要複製一份舊的 `state` 修改後回傳新的內容, 永遠不直接修改舊的狀態 (side-effect)
- 在 reducer 裡不小心操作到舊的 `state` 是常見的錯誤
- Redux Toolkit, `createSlice()` 內部使用 [immer](https://immerjs.github.io/immer/docs/introduction) 利用 `Proxy` 實現使用 mutate state 寫法自動轉換成 immutable 寫法, **只有在 Redux Toolkit 裡的函式才有用**

Writing Async Logic with Thunks

- Thunk, 是一種特殊的函式, 用來封裝非同步邏輯, 需要配合 `redux-thunk` 這個 Redux middleware
- Redux toolkit, `configureStore()` 已經自動包含 `redux-thunk`
- Thunk 外層 (thunk creator) 傳入所需的資訊, Thunk 內層 (thunk function) 傳入 `(dispatch, getState)` 內部執行非同步邏輯

The React Counter Component

- `React-Redux` 提供一些 custom hook, 讓 React component 與 Redux store 互動, 例如
  - `useSelector`, 用來取值, 取代 context 與取值邏輯
  - `useDispatch`, 用來取得 `dispatch()` 觸發 action, 取代 `store.dispatch()`
  - 把 store 隔開只通過 custom hook 取得必要功能

Component State and Forms

- 只有全域或者會與其他 component 共用的 state 才需要存進 Redux store 中
- React component 仍然可以有 local state, 例如表單運作狀態

Providing the Store

- React-Redux 提供 `Provider`, context element 包含 `store`

#### Basic Redux Data Flow

Project Setup

- Social Media Feed App 範例 setup, 可以 clone github repository
- 新專案推薦使用 Create-React-App Redux template
- 範例檔案結構 `/src`
  - `index.js`, 入口檔案, 包含呼叫 App element 與 Redux store
  - `App.js`, React Top component
  - `index.css`, 共用樣式
  - `/api/client.js`, AJAX request API methods
  - `/api/server.js`, mock server-side api
  - `/app`
    - `/Navbar.js`
    - `store.js`, Redux store 實體化

Creating the Posts Slice

- 需求: 取得 posts data, 儲存在 Redux store, 渲染 data 到頁面上
- 使用 `import { createSlice } from '@reduxjs/toolkit'`, 利用 `createSlice()` 建立
  - slice 的 `export default` 為該 slice 的 `reducer` (duck pattern)
- 在 `app/store.js` 中使用 `import { configureStore } from '@reduxjs/toolkit'`, 利用 `configureStore()` 組合 reducers 且建立 store
  - `store.js` 的 `export default` 為 store, 即 `configureStore()` 的回傳值

Showing the Posts List

- 使用 `import { useSelector } from 'react-redux'`, 利用 `useSelector` hook 取得 Redux store 裡的資料
  - `useSelector` 需要傳入一個 selector function 協助從整個 state 中取得特定的資料 (getter function)
- 在 `App.js` 中利用 `react-router-dom` 設定 Router

Adding New Posts

- 需求: 給予表單能新增內容, 新內容需要存入 Redux store, 渲染新內容到頁面上
- 使用 `import { createSlice } from '@reduxjs/toolkit'`, 利用 `createSlice()` 新增 `reducer`
  - 會自動產生 `action` 與 `action creator`
  - `action` 使用 `payload` 傳遞相關資訊
- 使用 `import { useDispatch } from 'react-redux'`, 利用 `useDispatch()` hook 取得 store `dispatch` 函式
- 使用 `import { nanoid } from '@reduxjs/toolkit'`, 利用 `nanoid()` 取得隨機 id

#### Using Redux Data

- 為範例新增新 Features, 查看單一文章內容, 編輯舊文章, 查看使用者與文章, 排序, 按讚

Show Single Posts

- 需求: 一次查看一個完整的文章
- `useSelector()` 所取得的 store state 如果更新, component 也會自動重新渲染
  - 因此 component 應該只引用會使用到的 state, 避免不必要的 re-rendering
- React Router, `<Router>`
  - `<Switch>`
  - `<Route>`
  - `<Redirect>`
  - `<Link>`
  - 渲染的 component 通過 `match` 取得 routing request parameters

Editing Posts

- 需求: 修改過去文章
- 擴充 postSlice 增加新的 `reducer`
- 使用 `import { useHistory } from 'react-router-dom'`, 利用 `useHistory()` hook 取得 history 利用 `push` API routing 到新的顯示頁
- 使用 `import { Link } from 'react-router-dom'`, 利用 `<Link>` element 引導到編輯頁, 渲染編輯 component
- 使用 `createSlice` 定義 `reducer` 通過選用的 `prepare()`, callback function 客製化 `action creator`
  - `prepare()` callback function 需要回傳一個含有 `payload` 的物件
  - 通過 `prepare()` 函式準備 `payload` 把可能會有 `side-effect` 的行為在這裡處理, 而非 reducer 內部 (需保持為純函式)
  - 例如, 生成隨機數產生 id

Users and Posts

- 需求: 使用者功能
- 創造新的 slice, `features/users/userSlice.js`
- 在 `app/store.js` 裡的 `configureStore()` 裡新增新創造的 `reducer`
- 在實際的 App 中會需要固定追蹤 `currentUser` state
- 把 component 切小使用 `useSelector` 取得盡可能少的資料, 精準控制每個 component 必要的渲染期

More Post Features

- 需求: 排序 (sorting)
- Redux state 應該存放的內容只有 primitives, 物件, 陣列, 能被序列化的值. 其他不允許
- 因此 Date 的值應該被序列化與反序列化, `new Date().toISOString()`
  - 使用 `import { parseISO, formatDistanceToNow } from 'date-fns'` 協助時間的計算與反序列化

- 需求: 按讚功能
- 盡可能的讓 `action.payload` 越小越好, 沒有副作用的計算放在 `reducer` 中做, 有副作用的準備放在 `prepare()` callback function 裡
  - `reducer` 應該放置最多的邏輯

#### Async Logic and Data Fetching 

-  設置 mock server-side api

Thunks and Async Logic

- Redux store 是同步的, 非同步的行為不應該發生在 store 裡, 
  - 包含 `dispatch` 呼叫 `reducer`, 
  - `reducer` 運算且更新 `state`, 
  - `store` 通知 listeners `state` 改變
- 藉由 `Redux middleware` 去介入以上 store 的運作流中間
  - 可以存在非同步邏輯與 store 互動的空間
  - 最常見的 Redux middleware 是 `redux-thunk`, Redux Toolkit 的 `configureStore` 已經預設使用, 推薦做為處理非同步邏輯的標準方式
- Thunk Functions, 引入 `redux-thunk` middleware 之後, 允許傳遞 thunk function 給 `dispatch`
  - thunk function, input: `(dispatch, getState)`
  - thunk function 做為處理函式用來介入 `dispatch` 的觸發時間
  - 為了維持一致性, 同步但是需要傳值的 `dispatch` 也可以通過 thunk function 來實現
  - thunk functions 通常存放在相關的 slice 檔案裡 (duck pattern)
- 非同步的 thunk function, 
  - thunk function 允許包含非同步邏輯, 例如 `setTimeout`, `Promise`, `async/await`
  - 常見的非同步取的資料的處理流程,
    1. 觸發開始, 並且修改 request 狀態為進行中
    1. 執行取得資料的非同步 request,
    1. 依據非同步的回傳結果, 分別處理成功 (success) 與失敗 (failure) 的狀態
- Redux Toolkit 裡的 `createAsyncThunk` API, 提供實作 async thunk function 的協助
  - 由於非同步行為常見的流程, async thunk function 實作上很相似, 因此 Redux Toolkit 提供方便建置的方法 (`createAsyncThunk`)

Loading Posts

- 需求: 由 API 取得 component 初始化的狀態, 並且實現 progressing
- `useSelect()` 所需要的 selector function 也可以實作在 slice 裡共用相同的邏輯
  - 減少取值時重複的程式碼
  - 甚至常用函式可以使用 `useMemo` 或 `useCallback` 做效能最佳化
- selector function 是需求導向, 只有需要使用到特定的值才實作, 不需要為了 state 實作沒用到的函式
- Request 狀態分成四種, 尚未開始, 進行中, 成功, 失敗
  - 狀態的保存與錯誤訊息保存, 可以使用 enum 與物件而非單純的 boolean
- 使用 async thunk function 實現非同步 fetching 資料, [範例](https://redux.js.org/tutorials/essentials/part-5-async-logic#fetching-data-with-createasyncthunk)
- 使用 `async/await` 配合 `try/catch` 取代 `Promise` 與 `then/catch`
- component dispatch 非同步的 action, 如同其他的 action 一樣, [範例](https://redux.js.org/tutorials/essentials/part-5-async-logic#dispatching-thunks-from-components)
- 使用 `import { createAsyncThunk } from '@reduxjs/toolkit'`, 利用 `createAsyncThunk` 自動生成非同步 request 所需的 dispatch function
  - [範例](https://redux.js.org/tutorials/essentials/part-5-async-logic#fetching-data-with-createasyncthunk)
  - `createAsyncThunk()`, 
    - input: action type 的字串前綴, 
    - input: 非同步的 payload creator function, 回傳 `Promise` 的結果
- 當一個 reducer function 是依據其他 action 觸發的時候, 需要使用額外的欄位 `extraReducers`, 用來監聽 action 的觸發並且執行對應的工作, 例如修改 state
  - 例如, 需要監聽執行中狀態 (in progress), 非同步成功後把資料存進 state, 非同步失敗後的處理
  - `extraReducers` 物件中的 key 需為監聽的 `action type` string, value 為一般的 reducer function
  - 如果使用 `createAsyncThunk` 所生成的 action 在 `extraReducers` 可以使用 ES2015 的實字計算 key 語法, 與自動生成的 action creators, `pending`, `fulfilled`, `rejected`, 作為 key, [範例](https://redux.js.org/tutorials/essentials/part-5-async-logic#reducers-and-loading-actions)

Loading Users

- 需求: 載入使用者
- 一樣使用 `async thunk` 實現, 但是只需要在 `index.js` 入口呼叫一次該 dispatch 即可

Adding New Posts

- 需求: 實際把新增的內容送到後端
- 一樣使用 `async thunk` 實現非同步 request 來傳遞資訊給後端, 使用 `POST`, [範例](https://redux.js.org/tutorials/essentials/part-5-async-logic#sending-data-with-thunks)
- 需求: 控制儲存按鈕, 在觸發過一次並且 request 還在執行時, 需暫時取消按鈕功能
- 使用 `import { unwrapResult } from '@reduxjs/toolkit'`, 利用 `unwrapResult` 處理 `createAsyncThunk()` 所產生的 `action` 結果

#### Performance and Normalizing Data

- 最佳化效能
- 資料正規化

Adding User Pages

- 需求: 建立使用者頁
- 建立新的 `slice` 來處理 user feature

Adding Notifications

- 需求: 通知功能, 實務上會由後端伺服器傳送通知
- 建立新 feature, notification 與對應的新 slice `features/notifications/notificationSlice.js`
- 使用 `createAsyncThunk()` 建立 thunk function 的話, 可以通過隱含的 `thunkAPI` 取得一些常用的工具, 例如
  - `dispatch`, `getState`, thunk function 預設的函式
  - `extra`, `requestId`, `signal`, `rejectWithValue`
- 問題: `dispatch()` 有多餘的呼叫, 雖然不影響功能

Improving Render Performance

- 針對 component re-rendering 的最佳化
- 調查現有的 rendering 行為
  - 使用 React DevTool 裡的 Profiler record 調查更新 state 時的 re-rendering 狀
  - 特別注意使用 `useSelector()` 時的行為, 因為在回傳值的不嚴格等於時都會重新渲染. 注意回傳值的 reference
- 問題: `useSelector()` 在 selector function input 沒有變動時仍重新渲染
- 解決方案: 使用 memorization 避免 `selector` function 不必要的渲染時機
  - 確保在真正變動值的時候才重新計算, 而非每次呼叫時. (functional programming 裡面純函式是可以使用回傳值取代函式呼叫)
  - [Reselect](https://github.com/reduxjs/reselect) 函式庫, 提供 selector function 的 memorization 實現, Redux Toolkit 已經預設包含這個函式庫
  - 使用 `import { createSelector } from '@reduxjs/toolkit'`, 利用來自 Reselect 的 `createSelector` function, 會自動依據 input 作到 memorization
  - `createSelector` function, input: 1. input selectors, 2. output selector, 只有在 input selectors 的回傳值變動時, 才會重新執行 output selector
  - 使用 memoized selector function 是很有價值的效能最佳化實務, 避免不必要的重新渲染
- React 的預設行為, 當父層 component 被渲染時, 所有子代 component 也會被重新渲染
- 問題: 不必要的子代重新渲染
- 解決方案: 使用 `React.memo()`, 包裝子代 component, 使得只有在該 component 的 props 改變時才重新渲染
- Redux Toolkit 裡有 `createEntityAdapter` 函式協助最佳化效能

Normalizing Data

- 為資料建立 index, 避免每次取值都要依序尋找, 提升取值時的效率
- Normalize 正規化資料, 避免重複的資料出現, 並且建立 lookup table, 讓取值變成 `O(1)`
- 使用 Redux Toolkit 裡的 `createEntityAdapter` 協助 lookup table 的建置與管理
  - `createEntityAdapter`, 可以傳入一個客製化物件, 包含 `sortComparer` 指定排序函式
  - 回傳值是一個物件, 包含 adding, updating, removing 的 `reducers`, `getInitialState()`, `getSelectors()`
  - [使用範例](https://redux.js.org/tutorials/essentials/part-6-performance-normalization#updating-the-posts-slice)
  - Normalized state 像是 `{ids: [], entities: {}}` 的結構

---

### 第三章 - Basic Tutorial

#### Basic Tutorial: Intro
#### Actions
#### Reducers
#### Store
#### Data flow
#### Usage with React
#### Example: Todo List

---

### 第四章 - Advanced Tutorial
#### Advanced Tutorial: Intro
#### Async Actions
#### Async Flow
#### Middleware
#### Usage with React Router
#### Example: Reddit API
#### Next Steps

---

6.6 + 20 = 26.6