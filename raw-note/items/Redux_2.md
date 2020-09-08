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
#### Using Redux Data
#### Async Logic and Data Fetching 
#### Performance and Normalizing Data

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

20