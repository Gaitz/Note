## XState youtube tutorials

### [Official recommendation video tutorials](https://xstate.js.org/docs/about/tutorials.html#videos), Frontend/XState

---

第一章 - Introduction to XState, Mar 21, 2019

第二章 - Standing on the Shoulders of Giants. Development With XState, Sep 24, 2019

第三章 - Using Finite State Machines To Develop Your React App - Lucas Reis @ ReactNYC, Sep 5, 2018

第四章 - Improving state representation by using XState in React, Oct 4, 2019

第五章 - React Van | Drawing Apps with XState v4, Nov 26, 2018

第六章 - State Machines Meet React Hooks - Zain Fathoni | JSConf.Asia 2019, Jun 29, 2019

第七章 - Mobx with Xstate && Creating interactive data visualizations w/ React + D3, Sep 18, 2019

---

### 第一章 - [Introduction to XState, Mar 21, 2019](https://www.youtube.com/watch?v=73Ch_EL4YVc)

- Machine, FSM in XState
- Visualize Machine, XState 的優點之一, 有工具協助可視化狀態機
- useMachine in React hook, 提供 React hook 的樣板協助在 React 中使用 XState 狀態機
- Guards, 提供 boolean helper 來協助 XState 之間的狀態移動判別
- Invoking Services, `target`, `actions`, XState 狀態改變時, 可以觸發外部服務, 並且結合狀態機
- Context, 夾帶的資訊
- 範例以簡單的登入狀態為例, 使用 xstate 產生 FSM, 並且結合 React 去切換狀態, 夾帶資訊...

---

### 第二章 - [Managing Complex UI with xState - Xavier Lozinguez, Jun 19, 2019](https://www.youtube.com/watch?v=i0rhP7TTQBg)

- 可以分成 parent 與 sub, FSM 並且互相參照
- `on` event 轉換 state, 配合 `actions` 執行 side effect
- 轉換時可以配合 Guards, `cond` 來決定要移動到的狀態
- State 上可以配合 actions 執行 life cycle function, 例如 `onEntry`, `onExit`
- `Context` 與 state 無關的夾帶資料, 儲存實際需要處理的資料, 受到 `actions` 觸發改變
- 範例中使用 React + TypeScript + XState
- 提供 `useMachine` hook, 回傳 current, send, 如同一般的 useState

---

### 第三章 - [Using Finite State Machines To Develop Your React App - Lucas Reis @ ReactNYC, Sep 5, 2018](https://www.youtube.com/watch?v=p_md9SZEKV8)

- FSM, 可以很好的可視化設計
- 一個系統中可以有多個 FSM, 用階層來區分或者同步執行, 可以更好的局部化與重用 FSM
- FSM 存放與實際資料無關的高階抽象層
- 實際狀態資料放在 `context` 中
- 此影片比較多概念上的描述

---

### 第四章 - [Improving state representation by using XState in React, Oct 4, 2019](https://www.youtube.com/watch?v=hG3UHNCUdzQ)

- 簡易的範例, 以 click fetching data 為例

---

### 第五章 - [React Van | Drawing Apps with XState v4, Nov 26, 2018](https://www.youtube.com/watch?v=jw03YmNffks)

- 利用不同的方式思考**設計**, 使用可視覺化的, Finite State Machine, XState
- 可視覺化的程式邏輯圖, Statecharts, 配合 XState visualizer
- 測試與設計邏輯可以分離 UI 層
- 利用 XState 設計, 實作狀態機 (`Machine`), 儲存資料 (`Context`) 分離 UI 層

---

### 第六章 - [State Machines Meet React Hooks - Zain Fathoni | JSConf.Asia 2019, Jun 29, 2019](https://www.youtube.com/watch?v=ioh7aqrBcs0)

- 範例以同時使用 React useState 與 XState 比較從簡單範例到較複雜的狀態
- XState 底層使用 Redux, 因此可以使用 Redux DevTools 來查看
- Finite State Machine, 可以有階層, 可以有 parent FSM 與 child FSM, 並且可以參考得到
- 重點在於可視化的檢查設計, 更容易測試的程式

---

### 第七章 - [Mobx with XState && Creating interactive data visualizations w/ React + D3, Sep 18, 2019](https://www.youtube.com/watch?v=Va_d5JmDHnA)

- MobX
- XState
  - States,
  - Transitions,
  - Context,
  - Actions,
  - Invoke,
  - Guards,
  - Final State,
- 不推薦觀看, 沒有任何資訊, 只是演講紀錄

---
