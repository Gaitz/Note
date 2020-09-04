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

---

### 第七章 - Learning Resources

---

### 第八章 - Ecosystem

---

### 第九章 - Examples


