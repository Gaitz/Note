## XState official documentation

### [XState official documentation](https://xstate.js.org/docs/), Frontend/XState

---

第一章 - README.md

About

第二章 - Concepts

第三章 - Goals

Guides

第四章 - Getting Started

第五章 - Installation

第六章 - Machines

第七章 - States

第八章 - State Nodes

第九章 - Events

第十章 - Transitions

第十一章 - Hierarchical State Nodes

第十二章 - Parallel State Nodes

第十三章 - Effects

第十四章 - Actions

第十五章 - Guarded Transitions

第十六章 - Context

第十七章 - Models

第十八章 - Activities

第十九章 - Invoking Services

第二十章 - Actors

第二十一章 - Delayed Events and Transitions

第二十二章 - Final States

第二十三章 - History

第二十四章 - Identifying State Nodes

第二十五章 - Interpreting Machines

第二十六章 - Testing Machines

第二十七章 - Using TypeScript

Recipes

第二十八章 - Using with React

第二十九章 - Using with RxJS

---

### 第一章 - README.md

- JavaScript, TypeScript 都可以使用的 Finite State Machine, Statecharts
- 使用 NPM 安裝 packages `xstate`
- Visualizer 提供 FSM 的視覺化工具
- 利用 FSM 直接定義 application state logic
- Hierarchical (Nested) State Machines, 是可以分層的, 更好的拆解複雜的邏輯與重用
- Parallel State Machines, 一個應用程式中可以擁有多個平行的 FSM

---

About

---

### 第二章 - Concepts

- XState 是一個建立與執行 Finite State Machine 的 library
- 依據電腦科學的 Finite State Machine concepts

Finite State Machine

- 一個描述系統的數學模型, 一只會有一個狀態
- 有限的狀態 (state), 有限的事件 (event), 有初始狀態 (initial state), 包含轉換函式 (transition function), 可有可無的終結狀態 (final state)
- 描述的是狀態 (有限組合) 而非值 (無限組合)

Statecharts

- 提供模組化的 state, 與 reactive, 由 1987 年的論文提出 _Statecharts: A Visual Formalism for Complex Systems_
- 內含的多個概念被 XState 採用
- Guarded transition
- Actions (entry, exit, transition)
- Extended state (context)
- Orthogonal (parallel) states
- Hierarchical (nested) states
- History

Action Model

- 另一個計算模型
- 所有的東西都是一個 `actor` 可以執行以下三件事情
  - Receive message 接收訊息
  - Send message 發送訊息
  - Behavior 處理接收到的訊息

---

### 第三章 - Goals

- 利用 Action Model 建立 event-based architecture
- 相容於各種平台與框架
- Machine definition 可以被序列化成 JSON
- Pure 且 functional 的 API
- 沒有其他外部相依

---

Guides

---

### 第四章 - Getting Started

- 安裝模組 `xstate `
- `import { createMachine } from 'xstate'` 建立 finite state machine
- machine configuration 裡包含 `id` (狀態機 ID), `initial` (初始狀態名稱), `states` (物件 `{ stateName: {} }`)
- `interpret` 執行創建好的 machine, `start()`, `send()` 發送 event

---

### 第五章 - Installation

- 使用 NPM 或 Yarn 安裝
- 使用 CDN script

---

### 第六章 - Machines

- 是一個有限數量的 States 會藉由依據 event 進行 transition
- Statechart 是一個 FSM 的擴充，主要內容是允許 nested state, parallel state, 包含 History states
- Configuration 物件 (`createMachine()` 的第一個參數 ) 通常包含
  - `id`, Machine ID, string
  - `initial`, 初始狀態名稱, string
  - `context`, 共享於整個 machine 的資料, object
  - `states`, 所有的狀態定義, object
- Options 物件 (`createMachine()` 的第二個選用參數 ), 提供整個 machine 所使用的功能, 以物件標註名稱與實作
  - `actions`
  - `activities`
  - `delays`
  - `guards`
  - `services`
- 使用 `.withConfig()` 從現有的 Machine 依據他的 configuration 進行擴充
- 使用 `.withContext()` 改寫 (**replace**) 現有的 Machine context 初始值

---

### 第七章 - States

- machine `.initialState`
- machine `.transition()`

每個 state 是可被序列化成 JSON 的物件包含以下屬性

- `value`,
- `context`,
- `event`,
- `actions`,
- `activities`,
- `history`,
- `meta`,
- `done`,

Methods

- `state.matches(parentStateValue)`, 回傳 boolean
- `state.nextEvents`, 接下來可以被執行的 events, string[]
- `state.changed`, 判斷經過 transition 後是否有改變, initialState 則回傳 `undefined`
- `state.done`, 判斷是否是 final state
- `state.toStrings()`, 回傳所有目前允許的 path string 陣列
- `state.children`, 取得物件, 包含生成的 service / actor ID

Persisting State

- 因為 state 是可以被序列化成 JSON 的因此可以很容易的儲存狀態 (storage) 與傳送狀態 (networking)
- 配合 `State.create()` 與 machine`.resolveState()` 讓 machine 取回儲存的狀態

State Meta Data

- 使用 `meta` 儲存描述當前 state 的 metadata

Notes

- 盡可能把 State 視為 readonly, 只來自 `machine.transition()`, `service.onTransition()`

---

### 第八章 - State Nodes

- state nodes 被定義在 `createMachine({ ... ,states: {} })` 上並且允許 nested
- 有五個內建的 state node types
  - `atomic`, 沒有子代 states
  - `compound`, 具有子代 states
  - `parallel`, 具有子代 states 並且會同時運作視為各自獨立的
  - `final`, 終結狀態
  - `history`,
- 明確的標示 types 可以提供 TypeScript 使用

Transient State Nodes

- 使用 pass-through 的 state 實現動態的 initial state, 配合 `always: []` 與 guarded function 實現

State Node Meta Data

- 使用 `.meta` 儲存 metadata

---

### 第九章 - Events

- FSM 的 transition 是依據 event 發生
- event 包含 `type` property 與其他任意的 property 作為 payload

Sending Events

- event 被定義在 createMachine states 的 `on` 欄位
- 可以由 machine`.transition(currentState, event)` 來執行
- 可以整合 DOM event

SCXML events

- XState event 自動相容於 SCXML events 標準, 內部自動生成所需的 properties

---

### 第十章 - Transitions

---

### 第十一章 - Hierarchical State Nodes

---

### 第十二章 - Parallel State Nodes

---

### 第十三章 - Effects

---

### 第十四章 - Actions

---

### 第十五章 - Guarded Transitions

---

### 第十六章 - Context

---

### 第十七章 - Models

---

### 第十八章 - Activities

---

### 第十九章 - Invoking Services

---

### 第二十章 - Actors

---

### 第二十一章 - Delayed Events and Transitions

---

### 第二十二章 - Final States

---

### 第二十三章 - History

---

### 第二十四章 - Identifying State Nodes

---

### 第二十五章 - Interpreting Machines

---

### 第二十六章 - Testing Machines

---

### 第二十七章 - Using TypeScript

---

Recipes

---

### 第二十八章 - Using with React

---

### 第二十九章 - Using with RxJS

---
