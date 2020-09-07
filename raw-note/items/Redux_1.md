## Redux official introduction

### [Website resource](https://redux.js.org/introduction/getting-started), React/Redux

---

第一章 - Getting Started with Redux

第二章 - Installation

第三章 - Motivation

第四章 - Core Concepts

第五章 - Three Principles

第六章 - Prior Art

第七章 - Learning Resources

第八章 - Ecosystem

第九章 - Examples

---

### 第一章 - Getting Started with Redux

- Predictable state container, 可預測的狀態容器
- 讓行為一致並且容易測試
- 提供 Redux 開發者工具, 容易除錯
- 可配合任意的顯示層函式庫, 例如 React
- 容量小, 2kB

#### Installation

Redux Toolkit

- 官方推薦使用的方式
- NPM 安裝, `npm install @reduxjs/toolkit`
- Yarn 安裝

Create React App 

- 使用 Create React App 的 Redux template 建立專案
- `npx create-react-app "name_of_App" --template redux`

Redux Core

- Redux 核心庫, 通過 NPM 或 Yarn 安裝
- `npm install redux`

#### Basic Example

- 應用程式的所有狀態 (state) 儲存在單一的 *store* 中
- 所有的狀態改變通過發送 *action*, 一個描述發生什麼事情的物件
- 依據 *action* 實際改變 state 的是純函式 *reducers*
- Redux 中只有單一的 store 和單一的 reducer (root reducer),
- 在實務上 reducer 會被切成多個小的 reducers 再由 API 組出 root reducer

#### Learn Redux

[Redux Essential Tutorial](https://redux.js.org/tutorials/essentials/part-1-overview-concepts)

- Top-down, 使用最新推薦的 API 與最佳實務

Additional Tutorials

- 官方的 Basic tutorial 與 Advanced tutorial 提供 bottom-up 的教學
- 其他教學影片與文件, [links](https://redux.js.org/introduction/getting-started#additional-tutorials)

Other Resources

- [links](https://redux.js.org/introduction/getting-started#other-resources)

Help and Discussion

- `Reactiflux` discord
- Stack Overflow `#redux`
- Github issue

#### Should You Use Redux?

- 有足夠數量隨著時間變化的資料 (state)
- 集中管理狀態
- 儲存所有的狀態在 top-level component 已經不適合時

---

### 第二章 - Installation

Redux Toolkit

- 包含 Redux Core, 與其他常用的 Redux Tools, 例如 Redux Thunk, Reselect
- 使用 NPM 或 Yarn 安裝, 
- `npm install @reduxjs/toolkit`

Redux Core

- 只安裝 Redux 核心, 通過 NPM 或 Yarn
- `npm install redux`
- 可以通過打包工具配合, 或者直接使用
- Redux core 使用 ES2015 實作, 因此可以不需要 Babel 即可在常用的瀏覽器上執行

Complementary Packages

- React bindings, 連接 React, `npm install react-redux`
- The Developer tools, Redux 開發者工具, `npm install --save-dev redux-devtools`

Create a React Redux App

- 在 create-react-app 使用 redux template
- `npx create-react-app "app_name" --template redux`
- 包含 Redux Toolkit

---

### 第三章 - Motivation

- SPA 越來越複雜, 有更多的狀態需要被管理
- 持續改變並且互相影響的狀態, 會越來越失去管理
- 不透明的系統會導致越來越難除錯

Difficult

- mutation 變動性
- asynchronicity 非同步性

React

- 試圖解決非同步性與直接修改 DOM (由 virtual DOM 與 React 控制)

Redux

- 解決狀態管理問題
- 試著讓狀態變化 (state mutations) 變為可預測的 (predictable)
- 藉由數個限制來規範如何 (How) 與何時 (when) 改變狀態
- 產生 3 個 Redux 的核心準則

---

### 第四章 - Core Concepts

- 所有的狀態受到單一的 plain object 管理, 但是不允許有 setters, 因為任意修改值會導致難以追蹤
- 所有狀態的修改都要通過 action 的觸發, 而 action 也是 plain object 描述發生的事情, 即 `action.type` 與 payload, 借由明確的 action 觸發狀態的改變, 讓變動變為可追蹤預測的
- 讓 action 能實際影響 state 藉由 `reducer` pure function, 
  - 輸入 (input), state object 與 action 
  - 輸出 (output) 另一個 state object
- 撰寫一個巨大的 reducer 來實現狀態改變, 不易管理. 因此實務上會切成多個小的 reducers 再調用 API 組合 (`combineReducers()`)

---

### 第五章 - Three Principles

Single source of truth

- 應用程式中全域的狀態保存在單一的 store 中
- 容易檢查與除錯應用程式
- 讓過去很難實作的 Undo/Redo 變得相當容易

State is read-only

- 唯一修改狀態的方式是透過觸發 action
- 確保 state 不會在不知不覺中被任意修改
- 讓資料修改被集中並且有序的管理, 避免 race condition 等問題
- 由於 action 只是個 plain object, 因此可以被 log, 任意儲存, ..., 更有彈性的能去測試

Changes are made with pure functions

- 讓 state 修改有預測性, 因此修改狀態的函式 (reducer) 是個純函式 (pure function)
- Input, 先前狀態與一個 action; Output, 新的狀態
- 由於 `reducer` 只是單純的函式, 可以通過 functional programming 的技巧, 更容易擴充, 重用與測試

---

### 第六章 - Prior Art

- 相關但不同的技術與模式

Flux

- 抽離狀態邏輯
- Redux 也是一種 Flux 架構
- Redux 增加了 **pure function** `reducer` 的限制
- Redux 假定 `state` 是不可變的, 每次 reduce 的結果都是新的一份, (符合 pure function 定義)

Elm

- 一種函數式程式語言, (會轉譯成 JavaScript, 使用於瀏覽器上), 強型別, Immutable data, pure functional language
- 強制使用 model view update architecture, updaters 等同於 Redux 中的 reducer
- Redux 受到 Elm 的啟發, 學習 Elm 有助於撰寫更好的 Redux 

Immutable

- 實現 immutable data structure 的 JavaScript library
- Immutable 與 Redux 很適合一起使用
- Redux 本身並不規範 state 是如何儲存的, 不管是用一般物件或者其他資料結構, 重要的是 state 是不可變並且唯讀的

Baobab

- 實現 immutable data structure 的 JavaScript library
- Baobab 沒有效能最佳化, 因此與 Redux 一同使用並沒有得到額外的好處

RxJS

- 管理非同步複雜度的一種 pattern 實現, `observable`
- Redux 可以與 RxJS 一起運作得很好
- 但是 Redux 與 RxJS 一起使用並不是必須的, 甚至直接在 RxJS 上實現 Redux pattern 是容易的

---

### 第七章 - Learning Resources

外部學習資源, 分類成

- Basic Introductions, 基本原則與基本使用
- Using Redux With React, React-Redux binding 介紹與使用
- Project-Based Tutorials, 實作類型的 tutorial
- Redux Implementation, 解釋 Redux 的實作細節
- Reducers, 討論如何撰寫 Reducer function
- Selectors, 為什麼使用 selector function 與如何使用
- Normalization, 如何對 Redux store 作資料正規化
- Middleware, Redux middleware 如何使用與實作
- Side Effects - Basic, 如何在 Redux 中處理非同步
- Side Effects - Advanced, 進階的工具與技巧處理非同步
- Thinking in Redux, 探討如何使用 Redux 以及何時使用
- Redux Architecture, 大型 Redux 專案中的模式與實務
- Apps and Examples, 
- Redux Docs Translations, 文件翻譯
- Books, 書籍
- Courses, 課程
- More Resources,

---

### 第八章 - Ecosystem

Redux 是個小型的函式庫, 擁有很多外部的工具與擴充

Ecosystem 的分類

- Library Integration and Bindings, 與其他前端框架的整合工具
- Reducers, Reducer 相關工具
- Actions, Actions 相關工具
- Utilities, 工具庫, 例如 selector 相關, Normalize 相關
- Store, 儲存庫相關工具, 例如 subscriptions, batching, persistence
- Immutable Data, 不可變資料相關工具, 例如 data structures, immutable update utilities, immutable/redux interop
- Side Effects, 處理副作用, 非同步的工具, 工具簡介與推薦使用時機
- Middleware, Redux Middleware 相關, 例如 networks and sockets, async behavior, analytics
- Entities and Collections, 資料 CRUD 相關工具
- Component State and Encapsulation, 元件狀態與封裝相關工具
- Dev Tools, 開發者工具, 例如 debuggers and viewers, DevTools monitors, logging, mutation detection
- Testing, 測試工具
- Routing, 整合 routing 狀態的工具
- Forms, 表單相關工具
- Higher-Level Abstractions, 
- Community Conventions, 慣例, 例如符合 Flux 標準, Duck pattern,

---

### 第九章 - Examples

範例與其程式碼

- Counter 類型
- Todos 類型
- Shopping Cart 類型
- Tree View
- Async
- Universal
- Real World
