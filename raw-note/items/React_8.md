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

Responding to events

State: a component's memory

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
