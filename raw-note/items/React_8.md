## React 18 new official documentation

### [React dev](https://react.dev/), Front-end/React

---

第一章 - Get started

第二章 - Tutorial: Tic-Tac-Toe

第三章 - Thinking in React

第四章 - Installation

第五章 - Start a New React Project

第六章 - Add React to an Existing Project

第七章 - Editor Setup

第八章 - React Developer Tools

Learn React

第九章 - Describing the UI

第十章 - Adding Interactivity

第十一章 - Managing State

第十二章 - Escape Hatches

API Reference

react

第十三章 - Hooks

第十四章 - Components

第十五章 - APIs

react-dom

第十六章 - Components

第十七章 - APIs

第十八章 - Client APIs

第十九章 - Server APIs

第二十章 - Legacy APIs

---

https://react.dev/blog/2023/03/16/introducing-react-dev

### 第一章 - Get started

creating and nesting component

- React App 是由 component 所組成的
- 每個 component 都是一個 UI 組件, 包含了一些自己的邏輯和樣式
  - component 可以小到一個 button 大到一整個頁面
- React component 只是一個 JavaScript function 回傳一些 markup
- React component 必須以大寫字母開頭, 原生的 html element 則使用小寫字母開頭

Writing markup with JSX

Adding styles

Displaying data

Conditional rendering

Rendering lists

Responding to events

Updating the screen

- 讓 component 記住某些資訊然後展示
- state, `useState`
- set state 觸發 render 整個 component function

Using Hooks

- 有很多內建的 hook function
- 也可以自訂 custom hook function
- hook function 比一般的 function 更嚴格
  - 必須放置於 component 的開頭處
  - 不允許 nested, 和 conditional
- 如果要實現 in a loop 或 conditional 只能讓他放至於另外一個 component 內

Sharing data between components

- share data, 通過把 state 宣告於上層分享

Next steps

---

### 第二章 - Tutorial: Tic-Tac-Toe

---

### 第三章 - Thinking in React

start with the mockup

step 1. break the UI into a component hierarchy

step 2. build a static version in React

step 3. Find the minimal but complete representation of UI state

- props, 外部傳遞給 component 的狀態
- states, component 本身內部記住的狀態

step 4. Identify where your state should live

step 5. Add inverse data flow

Where to go from here

---

### 第四章 - Installation

---

### 第五章 - Start a New React Project

使用 Frameworks

- Next.js
- Remix
- Gatsby (靜態網站, 可以做為 headless CMS 的前端)
- Expo (for native apps)

Bleeding-edge React frameworks

- Next.js (App router)

---

### 第六章 - Add React to an Existing Project

---

### 第七章 - Editor Setup

Your editor

- vscode
- WebStorm
- Sublime Text
- Vim

Recommended text editor features

- Linting
  - ESLint
- Formatting
  - Prettier

---

### 第八章 - React Developer Tools

Browser extension

- Chrome, Edge, Firefox
- Safari and others
- Mobile (React Native)

---

Learn React

---

### 第九章 - Describing the UI

- React 是一個用來渲染 UI 的 JavaScript library

Your first component

- 所有的 component 應該獨立定義
  - Pitfall: 在一個 component 內部在定義一個 component 是容易會有 bug, 因為會影響 React state 的管理
- Components all the way down
  - React App 是由 components 組成
  - 會依據需要可能掛在一個或多個 DOM root 上 (多數時候只有一個 root 作為入口)

Importing and exporting components

- Default vs named exports
  - 都可以使用, 但是記得給 component 一個適當的名字, 使用匿名宣告會更難 debug

Writing markup with JSX

- 使用 JSX 讓 markup element 與 logic 存在同一個地方, JavaScript, React component
- JSX 與 React 是分開的兩項工具, 只是通常一同使用
  - 因此也可以獨立使用

JavaScript in JSX with curly braces

Passing props to a component

- component 通過 props 來溝通
  - 通過 props 傳遞來分離 parent 與 children 的責任
- props 是 immutable, 因此 React 是單向綁定, 只能由上到下傳遞
  - 不要試圖直接修改 props, 而是使用 React state 來產生新的內容

Conditional rendering

- `if..else`
- `return null` 則不會 render 任何東西
- `..?..:..`
- `&&`,
  - Pitfall, 記得左側必須是 boolean

Rendering lists

- 渲染 array
- `key` prop
  - string 或 number 用來區分 array 中的彼此
  - 最好來自於 database 或本地以 uuid 等方式生成
- rules of keys
  - 必須與相鄰的元素區別
  - key 不能在 render 中改變
- React 為何需要 `key`
  - 用與 array order 無關的方式來區別子元素, 避免全部 re-render
- `key` prop 無法主動取得, 只給 React 內部機制使用

Keeping components pure

- pure function 讓程式更有可預測性
- pure function:
  - 相同的輸入必得到相同的輸出
  - 沒有 side-effect 產生
- React component
  - 作為 pure function 時
  - 相同的 props 產生相同的 JSX output
  - 只應該回傳 JSX 並不產生 side-effect (**修改在 render 前就生成的其他任何變數**)
- React 在 render 時, 能取得的 inputs: `props`, `state`, `context` 並且應該作為 read-only 存在
  - 為了抓出是否有在 render 時期, 修改到 inputs, React 在 development mode 會自動 render 兩次來偵測
  - 換句話說因為 component 應該是 pure 的, 所以 render 兩次應該不會對輸出有任何差別
  - `<React.StrictMode>` 開啟這項功能, 很多框架會預設使用
- side effect 必定會存在
  - 像是更新 DOM 來觸發 render screen
  - 在 React 中這些 side effect 應該只存在 event handler 中
- 對於 React 在 render 時應該是 pure 的
  - 所有的 side-effect 應該在 event handler 中觸發
- 盡可能地讓 component 只進行 UI 的 pure rendering
- Pure function 對於 React 帶來的好處
  - 可以安心的讓 component 在任何環境中執行
  - 可以安心進行 output cache
  - 非同步的進行 rendering

What's next?

---

### 第十章 - Adding Interactivity

- 會隨著時間改變的資料在 React 中被稱為 state
- event handler 去回應使用者操作
- State, 屬於 component 的記憶空間
  - hook React 中特殊的 function 用來操作 React 的其他功能
  - 以 `useState` 操作 state
- Render and commit, React 的渲染流程
  - Triggering, 觸發階段, 觸發 render 啟動
  - Rendering, 渲染階段, 產生 Virtual DOM
  - Committing, 發送階段, 把渲染結果發送給 Real DOM
- State as snapshot,
  - 把 state 視為 component 每次渲染時的儲存空間 snapshot
  - 換句話說 setState 並不會馬上修改 state 的狀態, 而是觸發 re-render 機制
- Queuing a series of state updates
  - 一次觸發多個 set state 時的處理
- Updating objects in state
  - 處理 object 型態的 state
  - reference, immutable, create a new object, `Immer` library

Responding to events

- event handler function 通常定義在 React component 內部
- 慣例以 `handle` 作為命名前綴
- 各種 JavaScript function 定義方式皆可使用
- event handler function 也可以從上層 component 以 props 的方式傳遞給其他 component 呼叫
- 原生的 html element events
- event propagation
  - React 裡所有的 event 都會進行 propagation 只有 `onScroll` 除外
- stop propagation
  - 如同 html event 一樣通過 event handler callback 傳入的 event 來呼叫 `stopPropagation()`
- Capture phase events
  - Event 的三階段
  - 儘管 child event 呼叫 stop propagation 仍然可以通過 `Capture` 階段 event 觸發
  - 使用時機通常用於 logging 和分析
- prevent default behavior
  - event `preventDefault()`, 停止瀏覽器的預設行為, 只有幾個 event 有預設行為並非全部
  - event `stopPropagation()`, 停止後續的 event propagation 觸發
- event handler 可以擁有 side effect
  - event handler function 與 React render function 不同是適合觸發 side effect 的地方

State: a component's memory

- Component 的渲染很多時候需要依據使用者互動的結果來呈現不同的內容
  - 使用者互動的結果必須存在某些地方讓 component 能取得, 這樣專屬於 component 的空間就是 `state`
- local variable 的限制
  - 修改 local variable 不會觸發 re-render
  - 每次 re-render 都會是新的 local variable
- 因此 state 應該要能達成這兩件事情
  - 更新 state 會觸發 re-render
  - 在每次 render 時 state 會保持不變
- 通過 `useState` hook
  - 取得兩樣東西, state 與 setState function
- Hooks
  - 特殊的 React function 用來觸發 React 的其他功能
  - 必須以 `use` 作為前綴開頭
  - 只能放置在 component 的第一層和 custom hook 中
- multiple state
  - 如果 state 之間沒有關係, 推薦使用多個 state 分別存放
  - 選擇適合的 state 資料結構
- React 如何知道多個 state 分別是誰
  - 依據宣告時的順序, 並且被存放在 array 中
  - 因此, hook 必須宣告在第一層, 不允許條件宣告, 才能保持正確的順序
  - React 底層以 variable array 實現 state
- State is private and isolated
  - State 是專屬於各自的 component instance 並不會互相影響

Render and commit

State as a snapshot

Queueing a series of state updates

Updating objects in state

Updating arrays in state

What's next?

---

### 第十一章 - Managing State

Reacting to input with state

Choosing the state structure

Sharing state between components

Preserving and resetting state

Extracting state logic into a reducer

Passing data deeply with context

Scaling up with reducer and context

What's next?

---

### 第十二章 - Escape Hatches

Referencing values with refs

Manipulating the DOM with refs

Synchronizing with Effects

You might not need an effect

Lifecycle of reactive effects

Separating events from Effects

Removing Effect dependencies

Reusing logic with custom Hooks

What's next?

---

### API Reference

---

react

---

### 第十三章 - Hooks

State Hooks

Context Hooks

Ref Hooks

Effect Hooks

Performance Hooks

Other Hooks

Your own Hooks

---

### 第十四章 - Components

Built-in components

---

### 第十五章 - APIs

- `createContext`
- `forwardRef`
- `lazy`
- `memo`
- `startTransition`

---

react-dom

---

### 第十六章 - Components

Common components

Form components

All HTML components

All SVG components

---

### 第十七章 - APIs

APIs

Entry points

---

### 第十八章 - Client APIs

Client APIs

Browser support

---

### 第十九章 - Server APIs

Server APIs for Node.js Streams

Server APIs for Web Streams

Server APIs for non-streaming environments

Deprecated server APIs

---

### 第二十章 - Legacy APIs

Legacy APIs

- `Children`
- `cloneElement`
- `Component`
- `createElement`
- `createRef`
- `isValidElement`
- `PureComponent`

Deprecated APIs

---
