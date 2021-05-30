## XState youtube tutorials

### [Official recommendation video tutorials](https://xstate.js.org/docs/about/tutorials.html#videos), Frontend/XState

---

第一章 - Introduction to XState, Mar 21, 2019

第二章 - Standing on the Shoulders of Giants. Development With XState, Sep 24, 2019

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
