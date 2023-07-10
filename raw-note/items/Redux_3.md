## Redux Official Best Practice

### [Website resource 1: Redux](https://redux.js.org/style-guide/style-guide) [Website resource 2: Redux Toolkit](https://redux-toolkit.js.org/), Redux

---

第一章 - Recipes index

第二章 - FAQ index

第三章 - Style Guide

第四章 - Redux Toolkit overview

第五章 - Redux Toolkit Introduction

第六章 - Redux Toolkit Tutorials Overview

第七章 - Redux Toolkit Tutorials Quick Start

第八章 - Redux Toolkit Tutorials TypeScript Quick Start

第九章 - Redux Toolkit Tutorials RTK Query Quick Start

第十章 - Redux Toolkit Usage Guide

第十一章 - Redux Toolkit Usage with TypeScript

第十二章 - Redux Toolkit Writing Reducers with Immer

第十三章 - Redux Toolkit APIs Store Setup

第十四章 - Redux Toolkit APIs Reducers and Actions

第十五章 - Redux Toolkit APIs Other

第十六章 - Redux Toolkit RTK Query Overview

第十七章 - Redux Toolkit Comparison with Other Tools

第十八章 - Redux Toolkit Examples

第十九章 - Redux Toolkit Usage With TypeScript

第二十章 - Redux Toolkit Using RTK Query

第二一章 - Redux Toolkit API Reference

第二二章 - Redux Toolkit 舊文件

---

### 第一章 - Recipes index

常見的情境與解決方案

- Configuring Your Store,
  - 建置 store 的方法
- Using With TypeScript,
  - 配合 TypeScript 使用
- Migrating to Redux,
  - 從 Flux 或 Backbone 轉移到 Redux
- Using Object Spread Operator
  - 使用 `...` Object Spread Operator 進行 state 複製
  - `...` 是 shallow clone
- Reducing Boilerplate
  - 減少重複的行為
- Server Rendering
  - 配合伺服器端渲染
- Writing Tests
  - 使用 Jest 測試 Redux 相關內容
- Computing Derived Data
  - 效能優化, 使用 `Reselect` 解決 selector function 不必要的重複計算
- Implementing Undo History
  - 實作 Undo 與 Redo 功能
- Isolating Redux Sub-Apps
  - 切割完全獨立的 App 各自擁有獨立的 Redux state
- Using Immutable.JS with Redux
  - 使用 `Immutable.JS` library
- Code Splitting
  - Redux 與 JavaScript bundle 分割
- Structuring Reducers
  - 建構 Reducers 相關使用情境

---

### 第二章 - FAQ index

- General
  - 關於為何使用 Redux 相關
- Reducers
  - 使用 Reducer 相關問題
- Organizing State
  - 關於 State, 重複的資料, 資料類型相關問題
- Store Setup
  - Store 建立, Middleware, Subscription 相關問題
- Actions
  - Action, 非同步 Action, Action Creator 相關問題
- Immutable Data
  - Immutability 與 Redux 相關問題
- Code Structure
  - Redux 專案檔案結構, 各類型功能存放位置相關問題
- Performance
  - Redux 效能, Memory 相關疑問
- Design Decisions
  - Redux 本身設計上的選擇以及原因
- React Redux
  - react-redux 函式庫相關問題
- Miscellaneous
  - 其他, 實際專案問題, 例如實作權限管理

---

### 第三章 - Style Guide

- 官方所推薦的 Redux Best Practices
- Redux 函式庫與多數文件是沒有限制的
- 依據專案類型選擇是否要遵循指南

Rule Categories

- 規則分成三類
- Priority A: Essential, 可以避免錯誤的規則, 盡可能遵循
- Priority B: Strongly Recommended, 提升使用者體驗與可閱讀性, 盡可能遵循
- Priority C: Recommended, 可依據一致性選用

Priority A Rules: Essential

- Do Not Mutate State
  - 在任何時候不要直接修改 state
  - 可以使用工具 [`redux-immutable-state-invariant`](https://github.com/leoasis/redux-immutable-state-invariant), [`Immer`](https://immerjs.github.io/immer/docs/introduction) 協助保持不變性
- Reducers Must Not Have Side Effects
  - Reducer 函式不可以有副作用, 必須是純函式 (pure function)
  - Reducer 函式裡只能依據 `state` 與 `action`, 不可以包含非同步處理, 隨機數, 變動外部變數等等副作用
- Do Not Put Non-Serializable Values in States or Actions
  - State 與 Action 裡避免包含不可續列化的型別, 例如 Promises, Symbols, Maps/Sets, functions, class instance
  - Action 的例外是在配合 middleware 時可以確保在傳遞給 reducer 的時候已經被轉換成可續列化類型資料, 例如 `redux-thunk` 實現非同步 action
- Only On Redux Store Per App
  - 每個應用程式裡只能擁有唯一一個 store
  - 實務上常常被定義且初始化在 `store.js` 裡
  - Store 多數時候不應該直接被引入應用程式中, 通常需要配合其他連接工具, 例如 `react-redux`

Priority B Rules: Strongly Recommended

- Use Redux Toolkit for Writing Redux Logic
  - 建議使用 Redux Toolkit 來協助建立 Redux 相關程式碼
  - 內建最佳實務
- Use Immer for Writing Immutable Updates
  - 手動撰寫 immutable state update 容易有錯誤
  - 建議使用工具 `Immer` 或其他工具協助實作
  - Redux Toolkit 已經內建 `Immer`
- Structure Files as Feature Folders or Ducks
  - 應用程式檔案結構依循 ducks pattern, Feature based
  - 區分成 `common/`, `features/`, 同一個 feature 相關的程式碼放置在同一個資料夾或檔案中
- Put as Much Logic as Possible in Reducers
  - 盡可能把所有的邏輯放在適當的 reducer 中, 而非其他位置 (actions, prepares)
  - 使得程式碼更容易測試且追蹤錯誤
- Reducers Should Own the State Shape
  - Redux root state 從單一個 root reducer 建立
  - 為了維護性, 實務上常將 reducer 切分成小的 `slice reducer` 並且擁有屬於自己的 initial state 以及更新方式 (reducer function)
  - 盡可能減少在 reducer 中回傳任意值, reducer 應該控制且建立 state 應有樣子, 而非放棄控制權.
  - reducer function 控制傳來的 action 如何影響 state, 精準的控制 state 的內容.
- Name State Slices Based On the Stored Data
  - `slice reducer` 的命名應該依據儲存的檔案內容, 並且省略 `reducer` 關建字作為名稱的一部分
  - 例如直接命名為 `posts`, `users`
- Treat Reducers as State Machines
  - 把 reducer 是為有限狀態機, 計算值必須依據前一個狀態, 不能無條件的只依據 action 就計算 state
  - 依據現有的 state 在加上 action 來計算新的狀態可以避免出現 bug, 例如在情況不允許的狀態下執行 action
- Normalize Complex Nested/Relational State
  - 正規化關聯資料, 提升取值時的效能
  - [教學](https://redux.js.org/recipes/structuring-reducers/normalizing-state-shape)
  - 或使用 Redux Toolkit 裡的 `createEntityAdapter()`, [範例](https://redux.js.org/tutorials/essentials/part-6-performance-normalization#normalizing-data)
- Model Actions as Events, Not Setters
  - action type 應該視為 event, 而非 setter
  - action 應該描述事件的發生與狀態
  - 這樣建立的 action 名稱會更有可閱讀性
- Write Meaningful Action Names
  - `action.type` 主要的目的是 1. 供 reducer 判別, 執行對應的工作 2. 作為 Redux DevTools history log 除錯資訊的一部分
  - Action 需要寫的具有意義, 且有描述性, 理想上可以直接閱讀 history log 的 action 名稱了解發生的事情
- Allow Many Reducers to Respond to the Same Action
  - 允許多個 reducer 處理相同的 action
  - 把 action 視為 event 的時候, 就理應允許有多個處理函式 (reducers)
  - 這樣作使得 codebase 更具有可擴充性
- Avoid Dispatching Many Actions Sequentially
  - 避免連續的觸發 dispatch 多個 actions 用來處理單一個 transaction
  - 這樣作可能會造成 UI 渲染時的效能浪費
  - 應該視為單一個 action 事件, 由多個 reducers 一次性處理, 減少 state 分次的更新導致的重新渲染
  - 或者使用 `batch` 功能 (`react-redux`)
- Evaluate Where Each Piece of State Should Live
  - 決定不同類性的 state 應該存放的位置, global or local
  - Redux store 不需要保存應用程式中所有的狀態, 而是只有需要被全域共享的 (global, app-wide)
- Use the React-Redux Hooks API
  - 使用 `react-redux` 的 hook API 來與 React 互動, 例如 `useSelector`, `useDispatch`
  - 比起舊的 `connect()` 更簡單使用
- Connect More Components to Read Data from the Store
  - 允許更多的 component 直接從 Redux store 中取值, 避免使用 component 傳遞的方式
  - Component 只取需要的值, 可以確保 component 只在需要變動的情況下重新渲染, 避免不必要的渲染
- Use the Object Shorthand Form of `mapDispatch` with `connect`
  - 使用 react-redux `connect()` 傳遞 `dispatch` 時, 應該使用 object 形式的 `mapDispatch`, [參考文件](https://react-redux.js.org/using-react-redux/connect-mapdispatch#defining-mapdispatchtoprops-as-an-object)
- Call `useSelector` Multiple Times in Function Components
  - 減小 `useSelector` 取值時的粒度, 並且可以呼叫多個 `useSelector` 取代單一個巨大的 `useSelector`
  - 目的是精準的讓 component 只在需要的時候重新渲染
- Use Static Typing
  - 使用 `TypeScript` 或 `Flow` 來作靜態型別檢查
  - 更容易提前抓出錯誤, 並且程式碼可閱讀性會更好
  - Redux Toolkit 是使用 `TypeScript` 撰寫, 所以可以很容易的配合使用達到更好的型別安全
- Use the Redux DevTools Extension for Debugging
  - 善用 Redux DevTools Extension 來協助除錯
  - 使用 Redux DevTools 是採用 Redux 一個很大的優勢
- Use Plain JavaScript Objects for State
  - State 應該使用純粹的 JavaScript Object 與 Array 所組成
  - 不要使用第三方函式庫的資料結構取代 State
  - 不需要使用 Immutable.js 因為太複雜且 bundle 太大等等原因, [Immutable.js 的利弊說明](https://redux.js.org/style-guide/style-guide#use-plain-javascript-objects-for-state)

Priority C: Recommend

- Write Action Types as `domain/eventName`
  - Action Type 的命名方式, 建議使用 `domain/eventName`
  - Redux Toolkit 的 `createSlice()` 已經內建自動生成這種類型命名的 action type
- Write Actions Using the Flux Standard Action Convention
  - 除了 `action` 必須擁有 `type` 欄位以外
  - Flux Standard Actions:
    - 放置資料在 `payload` 欄位下
    - 可以擁有 `meta` 欄位儲存額外的資訊
    - 可以擁有 `error` 欄位說明這個 action 代表某種錯誤
- Use Action Creators
  - 來自於 Flux
  - 提供一致性, 推薦使用 action creator function 取代直接撰寫 `action`
  - Redux Toolkit 的 `createSlice()` 會自動生成 action type 與 action creators
- Use Thunks for Async Logic
  - Redux 提供 middleware 達到擴充, 使用者如果不需要的話不必學習 RxJS
  - 預設使用 `Redux Thunk` middleware 來實現非同步邏輯
  - 推薦使用 `async/await` 語法提升 Thunk 的可閱讀性
  - 更複雜的非同步需求可以考慮採用 `Redux-Saga` 或 `Redux-Observable`
- Move Complex Logic Outside Components
  - 盡可能讓複雜的邏輯遠離 component 本身, 讓 component 只單純負責渲染對應的 UI
  - 資料與複雜的非同步行為, 交由 Redux 架構處理
  - 或者使用 `Redux Hook` 把複雜的邏輯包成 custom hook 函式
- Use Selector Functions to Read from Store State
  - 使用 selector functions 封裝取值邏輯 (getter)
  - 使用 `Reselect` library 提供 memorized selector function 提升取值效能
  - 強烈建議使用 memorized selector function
- Avoid Putting Form State In Redux
  - 避免存放表單資料到 Redux 裡, 這些資料不應該是全域使用的
  - 並且容易造成效能問題

---

### 第四章 - Redux Toolkit overview

- Redux Toolkit 是官方工具庫, 提升 Redux 開發體驗並且依循最佳實務
- 包含 Store 建立
- 定義 Reducers
- Immutable update
- 一次性建立 Slice 自動生成 actions 與 action creators
- 包含常用工具, 例如 Redux Thunk 處理非同步, Reselect 處理 memorized selector function

Installation

- NPM `npm install @reduxjs/toolkit`
- YARN `yarn add @reduxjs/toolkit`

Purpose

- Redux core 本身是非常隨意的, 可以自行處理任何的事情
- 靈活性有時候並不是必須的
- Redux Toolkit 協助處理三個主要的問題
  - 建立 Redux Store 太過複雜
  - 必需要引入很多外部資源才能讓 Redux 更容易使用
  - Redux 需要太多的樣板程式碼
- 提供官方推薦的最佳實務, 減少設定與決策

Why You Should Use Redux Toolkit

- 更容易撰寫好的 Redux 應用程式, 加速開發, 遵循最佳實務

What's Included

- `configureStore()`, 簡易設定, 自動組合 slice 與引入常用 middleware 例如 `redux-thunk`
- `createReducer()`, 建立 reducer 不需要使用 switch, 並且使用 `Immer` 處理 immutable updates
- `createAction()`, 自動建立 action creator
- `createSlice()`, 快速建立 slice, 需傳入 reducer, slice name, initial state, 自動生成 action 與 action creators
- `createAsyncThunk`, 快速建立常見的非同步呼叫 thunk, 自動生成 action
- `createEntityAdapter`, 協助生成 normalized data 並且生成對應的 selectors 與 reducer
- `createSelector`, 使用 `Reselect` 建立 memorized selector function

RTK Query

- 額外選用的 Addon, 用來處理 data fetching, caching
- 建立在 RTK 與 Redux 之上, 但可以獨立使用
- 相關的 APIs
  - `createApi()`, 最主要的 API
  - `fetchBaseQuery()`, 簡單的 fetch wrapper 可以用於 `createApi()` 中
  - `<ApiProvider />`, 如果沒有使用 Redux 單獨使用時, 需要加上 Provider
  - `setupListeners()`, 用來開啟 `refetchOnMount`, `refetchOnReconnect` 的 utility

Documentation

- [連結](https://redux-toolkit.js.org/)

---

### 第六章 - Redux Toolkit Tutorials Overview

---

### 第七章 - Redux Toolkit Tutorials Quick Start

---

### 第八章 - Redux Toolkit Tutorials TypeScript Quick Start

---

### 第九章 - Redux Toolkit Tutorials RTK Query Quick Start

---

### 第十章 - Redux Toolkit Usage Guide

---

### 第十一章 - Redux Toolkit Usage with TypeScript

---

### 第十二章 - Redux Toolkit Writing Reducers with Immer

---

### 第十三章 - Redux Toolkit APIs Store Setup

---

### 第十四章 - Redux Toolkit APIs Reducers and Actions

---

### 第十五章 - Redux Toolkit APIs Other

---

### 第十六章 - Redux Toolkit RTK Query Overview

---

### 第十七章 - Redux Toolkit Comparison with Other Tools

---

### 第十八章 - Redux Toolkit Examples

---

### 第十九章 - Redux Toolkit Usage With TypeScript

---

### 第二十章 - Redux Toolkit Using RTK Query

---

### 第二一章 - Redux Toolkit API Reference

---

### 第二二章 - Redux Toolkit 舊文件

#### Redux Toolkit Introduction

Purpose

- 嘗試標準化建立 Redux
- 解決以下問題
  - Redux store 建置太過複雜
  - Redux 需要引入很多其他的工具才能符合常見需求
  - Redux 需要太多樣版程式碼

What's Included

- `configureStore()`, 簡易設定, 自動組合 slice 與引入常用 middleware 例如 `redux-thunk`
- `createReducer()`, 建立 reducer 不需要使用 switch, 並且使用 `Immer` 處理 immutable updates
- `createAction()`, 自動建立 action creator
- `createSlice()`, 快速建立 slice, 需傳入 reducer, slice name, initial state, 自動生成 action 與 action creators
- `createAsyncThunk`, 快速建立常見的非同步呼叫 thunk, 自動生成 action
- `createEntityAdapter`, 協助生成 normalized data 並且生成對應的 selectors 與 reducer
- `createSelector`, 使用 `Reselect` 建立 memorized selector function

Installation

- Using Create React App, 通過 Create React App 的 redux Template, 快速生成專案且引用 redux toolkit
  - `npx create-react-app "app-name" --template redux`
- NPM 安裝或 YARN 安裝
  - `npm install @reduxjs/toolkit`

Help and Discussion

- 使用 `Reactiflux` Discord 討論群
- 在 Stack Overflow 使用 #redux 問問題

---

#### Redux Toolkit Basic Tutorial

Introduction: Writing a Counter Application

Redux "Counter-Vanilla" Example

- 使用純 redux library
- [範例程式碼](https://redux-toolkit.js.org/tutorials/basic-tutorial#redux-counter-vanilla-example)

A More Typical Counter Example

- 純 Redux library 實作
- 使用 ES6
- dispatch action 以 dispatch action creator 取代
- 以 constants 建立 action type

Introducing: `configureStore`

- 使用 `configureStore` 取代 `createStore`, `combineReducers`
- 並且自動啟用 ReduxDevTool 與使用數個 [middleware](https://redux-toolkit.js.org/api/getDefaultMiddleware)
- `configureStore()`
  - Input: 一個物件, 物件包含各個 slice reducers
  - Output: Redux `store`
- [範例](https://redux-toolkit.js.org/tutorials/basic-tutorial#introducing-configurestore)

Introducing: `createAction`

- 使用 `createAction` 取代手動建立 action 與 action creator
- `createAction()`
  - Input: Action Type 的字串
  - Output: 該 Action 的 Action Creator function
- 生成的 action creator function 的 `toString` 被 override 成回傳 action type 字串
- 生成的 action creator function 含有 `type` property 會回傳 action type 字串
- [範例](https://redux-toolkit.js.org/tutorials/basic-tutorial#introducing-createaction)

Introducing: `createReducer`

- 使用 `createReducer` 取代手動建立 reducer 函式
- `createReducer()`
  - Input: initial state, 處理 object
  - Output: reducer function
- 使用 object 取代 switch case 來處理 action 分類
  - key 為 action type
  - value 為 handle function
- 使用 ES6 Computed properties 語法 `[]` 可以直接把 `createAction()` 生成的 action creator function 傳入作為 key
- [範例](https://redux-toolkit.js.org/tutorials/basic-tutorial#introducing-createreducer)

Introducing: `createSlice`

- 使用 `createSlice` 取代 `createAction`, `createReducer` 一次建立完成整個 slice
- `createSlice()`
  - Input: 一個 object 包含 name, initialState, reducers
  - Output: 一個 object 含有 `reducer`, `actions` property
- 通常使用 ES6 destructing syntax 取值成類似
  - `const { actions, reducer } = createSlice()`
  - `const { actionCreator1, actionCreator2 } = actions`
- [範例](https://redux-toolkit.js.org/tutorials/basic-tutorial#introducing-createslice)

Summary

- Redux Toolkit 提供建立 redux 相關的程式碼

---

#### Redux Toolkit Intermediate Tutorial

- 使用 Redux Toolkit 建立 React Redux Todos example app

#### Reviewing the Redux Todos Example

- 現有的 todos example 程式碼類型描述與改進方向

#### Initial Conversion Steps

Adding Redux Toolkit to the Project

- 使用 NPM 加入 dependency, `npm install @reduxjs/toolkit`

Converting the Store to Use `configureStore`

- 使用 `configureStore()` 取代 `createStore()`
- 自動啟用 Redux DevTools

#### Creating the Todos Slice

- 建立 Slice

Understanding Slices

- 配合 duck pattern 整合 action 與 reducer 在同一個檔案裡
- 直接使用 `createSlice()` 一次建立 reducer 與 action
- 每個 slice 都放置在 `/features/` 下個別的資料夾中

Writing the Slice Reducer

- `createSlice()` input:
  - `name`, 字串, slice 的名稱
  - `initialState`, slice 的初值
  - `reducers`, 物件, key 為 action type, value 為處理函式 (handle function)
- `createSlice()` 的 reducer 如果被 dispatch 未定義的 action 時預設是回傳當前的 state
- `createSlice()` 裡的 reducers 區塊, 等同於 `createReducer()` 內部的函式可以使用 mutable 語法, 會透過 `Immer` 自動轉換成 immutable update
- `export default` 為創建出來的 `reducer`
- `export const` 自動創建出的 `action creators`
- [duck pattern](https://github.com/erikras/ducks-modular-redux)

Updating the Todos Tests

- 修改舊的測試, 以符合 `createSlice()` 所生成出來的 action type 與結構

Implementing Todo IDs

- 使用 `createAction()` 裡選用的 `prepare` callback function
- `prepare` callback function 會回傳一個含有 `payload` 的物件, `meta` 則是選用的欄位 (依循 Flux 標準)
- 如果使用 `createSlice()` 建立時使用 `prepare` function, 則在 `reducers` object 中該 action 對應的 value 改成 object 包含兩個函式 `reducer` 與 `prepare`
- [範例](https://redux-toolkit.js.org/tutorials/intermediate-tutorial#implementing-todo-ids)

#### Using the New Todos Slice

Updating the Root Reducer

Updating the Add Todo Component

- 使用 `react-redux` `connect()`

Updating the Todo List

#### Creating and Using the Filters Slice

- 實現塞選功能

Writing the Filters Slice

- 作為新功能, 因此創建另外的 slice 來處理所屬的邏輯
- [範例](https://redux-toolkit.js.org/tutorials/intermediate-tutorial#writing-the-filters-slice)

Using the Filters Slice

#### Optimizing Todo Filtering

- 解決 selector function 每次都回傳不同的 reference 產生多餘的 re-rendering 問題
- 使用 `createSelector()` 內建 `Reselect` 實現 memorized selector function
- `createSelector()`, input:
  - 一個 array, 包含所有相依的值, 以 selector functions 方式表示
  - 一個 function, 實際的 selector 邏輯
- 回傳 memorized selector function

#### Cleanup

- 移除不必要的檔案
- 專案從 folder-by-type 改成 feature folder 結構了

#### Summary

- 使用 RTK 在 React 專案中
- 知道如何使用 mutable reducer, prepare function, memorized selector function
- 使用 feature folder 檔案結構

---

#### Redux Toolkit Advanced Tutorial

- 關於採用 Redux 在一般的 React 專案中
- 使用 RTK 撰寫 async logic
- 同時使用 RTK 與 TypeScript
- 採用 react-redux hook API 取代傳統的 `connect()`

#### Reviewing the Starting Example Application

- 範例應用程式是 GitHub Issue viewer
- 使用 React, TypeScript, CSS Modules
- 使用 feature folder structure
  - `/api`,
  - `/app`, React top component
  - `/components`, shared component
  - `/features`,
  - `/utils`,

#### Setting up the Redux Store

- 首次引入 Redux
- 安裝 Redux Toolkit, React-Redux
- 因為使用 TypeScript 所以需要引入 `@types/react-redux`
- 設置 root reducer, Redux store, `<Provider>` context
- 啟用 React 的 Hot Module Replacement 協助開發流程
- 設置 `app/rootReducer.ts`, `app/store.ts`, `index.ts`, [範例](https://redux-toolkit.js.org/tutorials/advanced-tutorial#setting-up-the-redux-store)

Creating the Root Reducer

- 使用 TypeScript 的 `ReturnType` 功能指定 state 的 Type

Store Setup and HMR

- 在 `app/store.ts/` 配合 `module.hot` HMR 與 `store.replaceReducer` store 自動載入開發時新的 reducer

Rendering the `Provider`

- 在 `index.ts` 配合 `module.hot` HMR 在開發時自動重新渲染 ReactDOM

#### Converting the Main App Display

- 分辨哪些值應該被放入 Redux, 哪些應該保留在 local

Creating the Initial State Slices

- 抽出 initialState 與 Types 建立第一個 slice, `features/issueDisplay/issuesDisplaySlice.ts`
  - `import { PayloadAction } from '@reduxjs/toolkit'` 使用 RTK `createSlice` 時可以使用 RTK 提供的 Type 協助實現 type-safe
- 改寫 React component, 通過 `import { useSelector, useDispatch } from 'react-redux'` hooks 與 Redux store 互動
- 確認更改後的行為與預期相同並且開啟 Redux DevTools 查看 Redux 如期運作

#### Converting the Issues List Page

- 原本的 fetch 使用 `React.useEffect` 與資料儲存使用 `React.useState`
- 把兩個邏輯試著使用 Redux 抽離出 component 交由 Redux 處理

Review the Issues List Component

- [範例](https://redux-toolkit.js.org/tutorials/advanced-tutorial#reviewing-the-issues-list-component)

Thinking in Thunks

- Redux store 原生是 synchronous, 預設所有的 asynchronous logic 應該存放在 store 之外
- 如果要整合 asynchronous logic 到 Redux 中則需要 Redux Middleware 協助介入 store dispatch action 時的行為
- 最常見的 middleware 是 `redux-thunk` 也是 Redux Toolkit 預設的作法
- Thunk 是用來延遲執行的函式 (lazy), 在處理非同步 action 時則是延遲到非同步行為完成後才實際 dispatch action
- 概念上以 thunk function 取代 action; 實務上則是以 function return thunk function 取代 action creator function
- 細節可參考 [redux-thunk 文件](https://github.com/reduxjs/redux-thunk#why-do-i-need-this)
- 另外兩個常見的非同步處理 middleware 是 `redux-saga` (使用 generator 語法), `redux-observable` (使用 Rx 概念)
- RTK 裡 thunk function 無法被定義在 `createSlice()` 中需要另外定義
  - 遵循 duck pattern 因此 thunk function 也定義在相同的 slice file 裡

Logic for Fetching Github Repo Details

- Adding a Reusable Thunk Function Type
  - `import { ThunkAction } from 'redux-thunk'` 使用 `redux-thunk` 提供的 Type
- Adding the Repo Details Slice
  - 建立新的 slice 處理 details 頁 `features/repoSearch/repoDetailsSlice.ts`
- Async Error Handling Logic in Thunks
  - `async/await` 配合 `try/catch` 處理 error handling

Fetching Repo Details in the Issue List

- 把 `useEffect` 中原本的 fetch Github repo 改成使用 dispatch async action 的方式實現

Logic for Fetching Issues for a Repo

- 建立新 slice 處理 issue list, `features/issuesList/issueSlice.ts`
- 手動建立 lookup table 儲存 issue data 成 normalized data

Fetching Issues in the Issues List

- `useEffect` 中移除 fetch issues 的實作, 改成 dispatch async action
  - 因此 `useEffect` 只剩下 dispatch async action
- 實現的方式沒有對錯之分, 取決於 logic 與 data 應該被存放在哪裡, 作法容不容易維護

#### Converting the Issue Details Page

Reviewing the Issue Details Component

- 類似 `IssueDetailsPage`, 以 `useState` 保存資料, `useEffect` 並且實作 async function 來發送 API 取值

Fetching the Current Issue

- 改用 Redux store, `useSelector`, `useDispatch` 取代 `useState`
- 在重新載入新的 issues list 時渲染並且自動拉到頁首 `window.scrollTo({ top: 0 })`

Logic for Fetching Comments

- 一貫作法, 建立新的 slice `features/issueDetails/commentsSlice.ts` 處理
- `createSlice()`, initialState, async 行為用 thunk function

Fetching the Issue Comments

- 處理 `useSelector` 時的效能問題, 解決方案有
  - 使用各個分別的 `useSelector`
  - 通過 RTK `createSelector()` 使用 `Reselect` 實現 memorized selector function
  - 使用 React-Redux `shallowEqual` 作為選用參數傳遞給 `useSelector()`

#### Summary

---

#### Redux Toolkit Usage Guide

#### Store Setup

常見流程

- 建立 root reducer
- 設定處理 async logic 的 middleware
- 啟用 Redux DevTools
- 其他設定, 例如開發時期的 HMR

Manuel Store Setup

- 使用 `createStore()` 的設定
- [範例](https://redux-toolkit.js.org/usage/usage-guide#manual-store-setup)

Simplifying Store Setup with `configureStore`

- Input 使用 object 方式, 需指定明確的 key, 因此有更好的可閱讀性
- 引用 middleware 只需要傳入 middleware array 其他細節由 `configureStore` 處理
- 自動啟用 Redux DevTool
- 預設使用 `redux-thunk` middleware
- 預設在 development 階段啟用檢查常見錯誤, 例如 mutating update, non-serializable values
- 使用 `configureStore` 建立 store 的[範例](https://redux-toolkit.js.org/usage/usage-guide#simplifying-store-setup-with-configurestore)
- 提供簡單設定也提供擴充性

#### Writing Reducers

常見流程

- 依據 action `type` 去區分更新的機制, 最常見的實現方式是 `switch`, 再來是使用 object 實現 lookup table
- 藉由複製 state 實現 immutable update

Simplifying Reducers with `createReducer`

- 由於 lookup table 方式受到歡迎, 因此 RTK 內部也使用相同的作法
- Immutable update 則藉由 `Immer` library 提供的功能, 可以撰寫 mutable 語法, 會通過 proxy 自動轉成 immutable update
  - 由於使用 copy 時實作往往過於複雜, 並且表達能力上也沒有 mutable 語法來的清楚

Defining Functions in Objects

- 各種定義 JavaScript object key 與 function value 的方式, 參考[範例](https://redux-toolkit.js.org/usage/usage-guide#defining-functions-in-objects)
  - `"Key": () => {}`, 明確的字串 key 與 arrow function
  - `Key: function () {}`, 隱性 key 與 function 實字
  - `Key () {}`, 命名函式, 名稱即為 key
  - `[Key]: () => {}`, 可計算的 key

Considerations for Using `createReducer`

- mutable update 只能用在 `createReducer` 裡才會正確轉換成 immutable update
- Immer 並不會實際汙染 state

#### Writing Action Creators

- Redux 十分推薦使用 action creator 取代手動撰寫 action
- 依循 Flux Standard Action, Action 函有 `type`, `payload`

Defining Action Creators with `createAction`

- RTK `createAction` 傳入 action type 字串, 會字動生成 action creator.
- 生成的 action creator 傳入的值會被存放在 action `payload` 裡
- `createAction` 可以傳入選用的 `prepare` function, 允許客製化一些 `payload` 內容, 也可以傳入選用的 `meta` 欄位

Using Action Creators as Action Types

- `createAction` 創建的 action creator function 被 override `toString()` 改成回傳 action `type` string, 也可以明確使用 `type` 欄位取得
- 因此使用 RTK `createReducer` 時, action key 的欄位可以直接使用 `createAction` 創造出來的 action creator 取代, `createReducer({}, { [actionCreator]: (state, action) => { doSomething() }})`

#### Creating Slices of State

- Redux state 常常會依據 feature 被切成各個 slices
- duck pattern 讓我們把 slice 定義在單一個 JavaScript 檔案中

Simplifying Slices with `createSlice`

- 使用 `createSlice()` 協助建立 reducer 與 actions
- `createSlice()`, 需要傳入一個 object 含有欄位 `name`, `initialState`, `reducers`, Example: `{ name, initialState, reducers }`
- reducers 建立如同 RTK 的 `createReducer()`, 並且內部會呼叫 `createAction()` 自動生成與 reducer key 相同的 action creators 與 actions

Exporting and Using Slices

- 從 `createSlice()` 回傳的物件中取值的方式, 推薦使用 ES6 destructing 方式
- `{ actions, reducer } = createSlice()`, `{ action1, action2 } = actions`
- 可以配合 `export` 與 `export default` 使用
- 需注意如果不同檔案的 reducer 參照其他檔案裡的 action 時, 可能會造成 `circular reference` 導致 dispatch 時的行為不正常
  - 解決方案通常為取出共用的部份存為另外的檔案, 在共同引用該檔案
  - [參考文章](https://medium.com/visual-development/how-to-fix-nasty-circular-dependency-issues-once-and-for-all-in-javascript-typescript-a04c987cf0de)

#### Asynchronous Logic and Data Fetching

Using Middleware to Enable Async Logic

- 常見的解決方案 middlewares
  - `redux-thunk`, 直接實作 thunk function 傳入 dispatch, 由 `redux-thunk` 控制執行時機
  - `redux-saga`, 使用 generator
  - `redux-observable`, 使用 RxJS observable
- RTK 推薦使用 `redux-thunk` 作為標準作法, 可以配合 `async/await` 語法取得更好的閱讀性
- RTK 的 `configureStore()` 預設已經載入 `redux-thunk` middleware, 可以直接使用

Defining Async Logic in Slices

- RTK 目前沒有提供其他快速建置 thunk function 的方式, 並且無法定義在 `createSlice()` 中, 需要自行撰寫
- 配合 duck pattern, thunk function 應該實作在同個 slice 檔案裡集中管理

Redux Data Fetching Patterns

- 由於使用非同步 fetching 的邏輯有固定的模式, [範例](https://redux-toolkit.js.org/usage/usage-guide#redux-data-fetching-patterns)
- 因此 RTK `createAsyncThunk` 提供快速建置這個 fetching pattern

Async Requests with `createAsyncThunk`

- `createAsyncThunk` 需要傳入 action type string 作為前墜, 回傳一個 Promise 的 payload callback function
- `createAsyncThunk` 會回傳一個 thunk function 並且含有定義好的 action, `fulfilled`, `pending`, `rejected` 可以使用在 `createSlice()` 裡的 `extraReducers` 欄位, 撰寫對應的 reducer 行為

#### Managing Normalized Data

- 大部份應用程式處理的資料是 nested 或者 relational 的, 可以通過 normalize 成 table 的形式, 提升使用方便性與效能

Normalizing by hand

- 手動把資料轉換成 object key-value 的模式, 轉換成 `state.entities`, `state.ids` 的形式
- [範例](https://redux-toolkit.js.org/usage/usage-guide#normalizing-by-hand)

Normalizing with `normalizr`

- 使用受歡迎的函式庫 `normalizr`, `import { normalize, schema } from 'normalizr'`
- [範例](https://redux-toolkit.js.org/usage/usage-guide#normalizing-with-normalizr)

Normalizing with `createEntityAdapter`

- 使用 RTK 的 `createEntityAdapter` 把資料轉換成 `{ ids: [], entities: {} }` 的形式
- [範例](https://redux-toolkit.js.org/usage/usage-guide#normalizing-with-createentityadapter)

Using `createEntityAdapter` with Normalization Libraries

- 使用 `createEntityAdapter` 配合其他的 normalization 函式庫
- [範例](https://redux-toolkit.js.org/usage/usage-guide#using-createentityadapter-with-normalization-libraries)

Using selectors with `createEntityAdapter`

- `createEntityAdapter` 會自動生成幾個常用的 selector functions,
  - `selectById`,
  - `selectIds`,
  - `selectEntities`,
  - `selectAll`,
  - `selectTotal`,
- 可以直接配合 React-Redux 的 `useSelector` 從 Redux store 中取值
- [範例](https://redux-toolkit.js.org/usage/usage-guide#using-selectors-with-createentityadapter)

Specifying Alternate ID Fields

- `createEntityAdapter` 假定資料中已經有 `id` 欄位
- 指定客製化的欄位作為 id, 可以在 `createEntityAdapter()` 傳入 `selectId` 來指定特定的欄位
- [範例](https://redux-toolkit.js.org/usage/usage-guide#specifying-alternate-id-fields)

Sorting Entities

- `createEntityAdapter` 提供 `sortComparer` 欄位, 可以指定排序函式 (sort function) 來客製化資料的排序
- [範例](https://redux-toolkit.js.org/usage/usage-guide#sorting-entities)

#### Working with Non-Serializable Data

- 原生 Redux 不允許在 state 與 action 中使用 non-serializable 的值
- 但是實務上是有可能發生的, 但使用時機應該非常的少
- RTK 的 `configureStore()` 預設包含的 `serializableCheck` middleware 會出警告, 可以客製化指定忽視

Use with Redux-Persist

- 使用 `redux-persist` 函式庫
- [範例與討論](https://redux-toolkit.js.org/usage/usage-guide#use-with-redux-persist)

Use with React-Redux-Firebase

- 使用 React-Redux-Firebase (RRF)
- [範例](https://redux-toolkit.js.org/usage/usage-guide#use-with-react-redux-firebase)

---

#### Redux Toolkit Usage With TypeScript

- Redux Toolkit 是使用 TypeScript 實作的, 因此 RTK API 很容易與 TypeScript 應用程式合作
- 提供同時使用 Redux Toolkit 與 TypeScript 時的範例

#### Using `configureStore` with TypeScript

#### `createAction`

#### `createReducer`

#### `createSlice`

#### `createAsyncThunk`

#### `createEntityAdapter`

---
