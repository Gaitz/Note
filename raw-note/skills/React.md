## React

### Computer Science

---

- 第一章 - Common Questions

---

### 第一章 - Common Questions

- React controlled component 與 uncontrolled component

  - 取決於 Real DOM 上的行為是否會傳達給 React 處理

- React Event

  - JSX 寫法如同 inline event listener, 但是 React 會統一處理 event 差異並且全部註冊到 root node 上, 並且替我們處理 remove listener

- React rendering

  - lifecycle function -> reconciliation -> virtual DOM -> diff -> real DOM

- React **key**

  - 用來加速 tree diff

- React **Hook**

- React **Context**

  - 跨 React Component 的傳值空間
  - React-Redux 即使用此方法
  - `React.createContext()`, `useContext()`, `Provider` component

- React `ref` 與 `useRef()`

  - 兩者所代表的 **ref** 是不一樣的, 不一定要一起使用
  - React `ref` 代表指向 real DOM node 的 reference. `React.createRef()`, `React.forwardRef()`
  - React `useRef()` 代表跨 lifecycle 的 variable (object) reference, 因為把物件生成放在 React Component 中每次 re-render 都會是新的. 但是 `useRef()` 的值變化並不會產生 re-render

- React **memo**, **useMemo()**

  - 兩者也是不同的 API 使用地方完全不一樣
  - `React.memo()`, 是一個 HoC 讓 React Component 變成只判斷 props, default 是 shallow compare 來決定 render
  - `React.useMemo()`, 是一個記憶 value 的地方, 來避免 re-render 時的 lifecycle 每次都計算

- React **lazy** 與 **Suspense**

  - Dynamic Import
  - Component Suspense 尚未準備好的 Component 先提供 fallback 直到完成

- **React Fiber**

  - **React reconciliation** in React 16+
  - 把原本 reconciliation 的工作分成多個 chunk 分散到多個 frame 裡, 避免影響效能
  - React 16 之前的 reconciliation 使用的是 JavaScript call stack 來處理 DOM tree
  - 在處理大型的 call stack 時無法中斷會導致 drop frames 影響互動
  - React Fiber 分割且分類 reconciliation 中的工作, 並且賦予優先順序, 例如動畫優先
  - React Fiber 以自訂的資料結構處理
  - 把**每個 component node 視為一個 Fiber** 因此 tree 會被分成多個 Fiber 在不同的 frame 中進行更新
  - 整個行為被分成兩個階段 reconciliation + render phase 與 commit phase
  - **reconciliation + render phase** 用來建立, 排程, 存取 Virtual DOM (Fiber), 允許非同步處理
  - **commit phase** 進行更新到 Real DOM 上, 需一次完成

React v17

- 沒有新功能主要是輔助未來的升級
- Event delegation 綁定 event 的位置從 `document` 改成 React root node, 這樣在混合使用 React 與其他程式時可以減少衝突
- JSX Transform, 在底層解除 JSX 與 React 的耦合 (decouple), 提供 JSX 未來有更多應用的可能

React v18

- **新的 render API**, `import { render } from 'react-dom'` to `import { createRoot } from 'react-dom/client'`
- **新的 server-side hydrate render API**, `import { hydrate } from 'react-dom'` to `import { hydrateRoot } from 'react-dom/client'`
- `<StrictMode>` 更新, 更嚴格, 並且協助檢查 React 未來的 mount 與 unmount 回復功能
- **新的 server-side rendering API**, 在使用 SSR + Suspense Mode 時需要使用新的 API
- **新的 Feature** **Automatic Batching**, 效能增加
  - 原本只自動支援 React event handler 會自動 batching render.
  - 現在會支援 `Promise`, `setTimeout`, native event handlers 自動進行 batching render
  - 要強置 render 需要使用 API, `flushSync()`
- 在測試環境開啟 `globalThis.IS_REACT_ACT_ENVIRONMENT = true;` 會提供更多 log 資訊
- React 18+ 開始不支援 IE
- 最重要的更新 Concurrent React
  - 主要是 React 底層的更新, 比較多的是第三方 library 需要更新
  - 從上層的理解是 React render 變成可中斷的 (interruptible), 可以實現狀態的重用 reusable state,
  - 新功能例如 **Suspense**, transitions, streaming server rendering
- 目前 `Suspense` + `React.lazy` 適用於 code split, 但是未來的遠景是包含 code, data, image, 等非同步的行為
- 未來有 **Server Component** 提供更好的 client-side, server-side 一致性
- **新的 Feature** **Transitions**
  - 把更新分成兩種類型 Urgent updates (通常是使用者行為相關) 與 Transition updates (後續處理, 例如資料取得)
  - `import { startTransition } from 'react`, `startTransition()` 內傳入一個 transition update function
  - `useTransition` 配合 hook 去取得 transition update 中的狀態, 因此可以在使用者即時更變後停止或者改變 transition update function 的執行, 來避免錯誤的 re-rendering 與 performance
- **新的 Feature** **Suspense**
  - `<Suspense fallback={}></Suspense>`, 在高階層就明確定義, component 需要時間建置, 先渲染 fallback 的 component
  - 可以配合 **Transition** 使用, React 會避免 transition 中還沒完成的資訊被渲染到頁面上並且保留舊的
- **新的 Hook functions**
  - `useId()`, 生成於 client-side /server-side 同步的 unique id, 避免 hydration 時的錯誤
  - `useTransition()` + `startTransition`, 啟用 transition
  - `useDeferredValue()`, 用來延遲渲染 non-urgent part
  - `useSyncExternalStore()`, 讓外部 store 可以 concurrent 讀取, 來讓 store 保持同步狀態, 給 library 使用的 hook
  - `useInsertionEffect()`, 關於 CSS-in-JS 的樣式注入, 給 library 使用的 hook
