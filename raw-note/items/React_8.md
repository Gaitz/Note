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

- Trigger -> Render -> Commit
  - 觸發 -> 渲染 virtual DOM -> 傳給 Real DOM
- Trigger
  - 第一次渲染, initial render, `createRoot` 時呼叫的 `render()`
  - 重新渲染, 因為狀態改變的 re-render ( component 本身或任何祖先 ), 因為 set state 改變的狀態
- Rendering
  - 遞迴的進行, 直到整個 component tree 該改變的部分都渲染過
  - Initial render 是產生出對應的 HTML element
  - Re-rendering, 則是判斷是否需要改變
  - rendering 的進行必須是 pure 的, 1. 相同的輸入有相同的輸出, 2. 只管理自己內部, 沒有 side-effect
  - 啟用 React Strict Mode 進行重複兩次的渲染來偵測是否有 side effect 產生
- 效能調教, 預設的 rendering 是會重新渲染所有的子元件, 沒有針對效能做最佳化
  - 切勿提早最佳化, 只有在遇到效能瓶頸時才進行調教
- Commit
  - Initial render, 會呼叫 `appendChild()` 掛載到 DOM 上
  - Re-rendering, 會進行盡可能少的改動, 由 rendering 階段已經計算過
  - React 只有在需要的時候才會調整 DOM 的刪減與生成, 大多時候會利用現有的 element
- 在 React 進行完 render 與 commit 後, 交由瀏覽器會進行實際的渲染 (reflow, repaint 等)

State as a snapshot

- 把 React state 視為 snapshot 而非 variable
  - 觸發的是 re-render, 而非變數改變, 發送 set state 讓 React 知道要 re-render
- 區分 event handler 與 set state (snapshot) 觸發的 re-rendering 在時間軸上的不同
  - React 不是直接響應 event handler, 而是響應 snapshot 的改變 (state 的改變觸發 re-render)
  - 流程是使用者觸發 event -> event handler 執行 -> 通知 React state 需要更新 (set state) -> State 更新後觸發 re-rendering
  - React rendering 僅僅只是 function 的執行
  - React state 則是存活在 rendering 過程之外的空間

Queueing a series of state updates

- 更新 state 的 queue 與 batch update
- 同個 event handler 中多個 set state 只會觸發一次 re-render (batch update)
- set state 除了直接傳值之外, 還能夠傳遞 update function
  - 如果是一個 event handler 中的多個 set update function 都會進入 queue 因此可以產生在同一個 event handler 中觸發修改多次的效果
  - 但是仍然只會觸發一次 re-render
  - **遇到非同步程式碼則會產生多次 re-render**
- Event handler 中的 set state 會以 queue 的方式儲存, 並且在執行完 event handler 後依序執行, 都執行完才進行 re-render

Updating objects in state

- React useState 中的 set state 是取代 (replace) 而非更新 (mutate, update)
- 應該把 React state 視為 read-only 就算是 Object 也是一樣
- `...`
- `Immer` library 協助建立新物件
  - 使用 `useImmer` 取代 React 原生 `useState`

Updating arrays in state

- 等同於 object

---

### 第十一章 - Managing State

Reacting to input with state

- 宣告式與命令式
  - React 是宣告式, 告訴 React UI 應該是什麼樣子, 但是不描述如何實現
- React 中思考如何宣告 UI
  1. 思考 UI 是由哪些不同版本的 state 產生的
  2. 哪些行為會觸發 state 改變 (trigger)
  3. 通過 useState 觸發 re-render
  4. 移除不必要的 state
  5. 連結 event handler
- React 的想法來自於 computer science 與 designer
  - Finite state machine 有限狀態機的狀態改變
  - Designer 依據不同狀態產生的 storybook
- React state 盡可能減少, 使用 reducer 或 finite state machine 讓 state 更限制在合理的邏輯裡, 沒有奇怪的中間狀態的可能

Choosing the state structure

- Group 相關的 state, 如果這些 state 通常會同時更新時
- 避免互斥的 state
- 避免多餘的, 重複的 state
- 避免使用 nested state

Sharing state between components

- Lifting state up
- 把 state 提升到父層, 再以 props 的方式傳遞

Preserving and resetting state

- React state 是否保存或移除, 是依據 React Virtual DOM 的判斷, 節點是否仍然掛在上面或者移除後重新掛載
- 判斷依據是 component `return` 的 DOM 結構產生對應的位置 position of virtual DOM tree
- 善用 React `key` prop
  - 不只是可以用在 list 上
  - 可以用於其他 component 上, 讓 React 判斷時直接採用 `key` 判斷是否為同個 position 會不會移除後更新
  - 記得 `key` prop 是指定於呼叫的父層
  - 指定不同的 `key` prop, 讓 React 每次都移除重新掛載

Extracting state logic into a reducer

- `useState` 與 `useReducer` 的比較
  - Code size, 程式碼數量, useReducer 會明顯比 useState 更多
  - Readability, 可閱讀性, useReducer 更容易看懂整個邏輯
  - Debugging, 除錯能力, useReducer 更容易除錯, 可以直接介入 action 觸發與執行的函式
  - Testing, 可測試, reducer function 是 pure function 因此更容易進行測試
  - 個人偏好, 兩個方式皆可以, 並且之間可以隨時互相轉換
- `useImmerReducer`, `import { useImmerReducer } from 'use-immer';`
  - 使用 Immer 語法定義 reducer
- Action type name 應該以使用者的角度命名動作名稱, 使用者角度的事件名稱

Passing data deeply with context

- Context
  - Create, Use, Provide
- 在使用 Context 之前應該盡可能使用 props 傳遞
  - explicit 明確的傳遞, 可維護性更高
- 善用 `children` prop 傳遞 component 取代中間層傳遞 props
  - _補_: 多嘗試這種方式
- Context 常見的使用時機
  - Theme, current account, routing, managing state

Scaling up with reducer and context

- 使用 context 傳遞 reducers
  - 讓程式組織的更容易閱讀

---

### 第十二章 - Escape Hatches

Referencing values with refs

- `ref` 提供 component 一個不會受 render 影響, 也不會觸發 re-render 的空間
- `import { useRef } from 'react';`
- 用來存放與 render 無關的值
  - 像是 timeout id, browser API, real DOM element, 等等
- 可以通過 JSX `ref` prop 取得底層 element 的 real DOM element ref

Manipulating the DOM with refs

- JSX 原生 element 的 `ref` prop
  - 通過存放在 React ref `useRef` 中以利後續利用
  - `ref` prop 可以傳入 callback function 進行運算後指定, 實現把 real DOM element refs 存在特別的資料結構中
- `forwardRef()` function 讓客製化的 React component 也允許傳遞 `ref` prop
- `useImperativeHandle` hook 讓你介入回覆給父層的 `ref` prop, 劫持 ref 並且修改後回傳物件
  - 可以用來限制父層取得的 `ref` 權限
- setState 一般來說要經過 render 和 commit 兩個階段才會影響到 real DOM
  - 因此在 setState 後立即使用的 DOM ref 不會是最新狀態 (要等待 React 做渲染)
  - 可以通過 `flushSync()` from `react-dom`, 包裹相關的 setState 讓更新 real DOM 變成同步的, 立即更新完 real DOM 才執行後續
- 要注意通過 ref 手動操作 real DOM 可能會導致 React 出錯, 尤其是在進行新增或移除節點的操作
  - 因為手動操作會影響到 real DOM 與 virtual DOM 的狀態不一致

Synchronizing with Effects

You might not need an effect

Lifecycle of reactive effects

Separating events from Effects

Removing Effect dependencies

Reusing logic with custom Hooks

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
