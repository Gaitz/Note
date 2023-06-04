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

Importing and exporting components

Writing markup with JSX

JavaScript in JSX with curly braces

Passing props to a component

Conditional rendering

Rendering lists

Keeping components pure

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
