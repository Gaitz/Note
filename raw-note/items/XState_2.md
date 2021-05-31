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

- Transition 傳入 current state 與 event 回傳下一個新的 state
- 被定義在 `states`, `on` property 裡
- 定義方式有三種
  - string
  - object
  - array, with guard function

Machine `.transition` Method

- pure function
- Input: `state`, `event`
- Output: `state`

Selecting Enabled Transitions

- 依據 `guard` function 與 current state 定義深度決定, 在不同階層可以有同名的 event, 但是相對深度越深的優先度越高

Event Descriptors

- 對應通常使用 `event.type`
- 特殊的 event descriptors
  - `""`, null, 已棄用, 被 `always` 語法取代
  - `*`, 可以作為 default match

Self Transitions

- 自循環，分成兩種
- 內部的 internal transition, 進入其他 child
- 外部的 external transition, 離開再進入 self

Internal Transitions

- 定義方式 event type 沒有 `target` 或 `.` relate path, 可以明確標明 `internal: true`

External Transitions

- 預設行為,
- 會觸發 `exit`, `entry` actions

Eventless ("Always") Transitions

- `always: []`, 每次進入 event 都會執行 `always` 裡的 guard function

Forbidden Transitions

- 不執行任何行為的特殊 event
- 定義方式為 `target` 為 `undefined`
- 使用情境通常為了不執行 parent 的同名 event

Multiple Targets

- 作為 FSM 一般情況下只有一個狀態
- XState 依循 statechart 可以有 `parallel` type 時可以使用 `target: { [] }` 來多重觸發 parallel machine 裡的 event

SCXML

- 等價於 SCXML `<transition>` element

---

### 第十一章 - Hierarchical State Nodes

- XState 允許 無限層數的 substates
- 提供更細緻的 state, 提高重用性, 聚合, 獨立, 避免單一 states 巨大增長
- states 只是單純的 JavaScript object

---

### 第十二章 - Parallel State Nodes

- Parallel states 代表完全獨立的 states, 可以同時間運作, 並且之間沒有任何的 transition 互相影響
- 藉由 `type: 'parallel'` 標明, states 之間是互相 parallel 的, substates 也可以為個別的 parallel

---

### 第十三章 - Effects

- side-effects 生存的地方

Fire-and-forget effects, 執行同步的 side-effect

- `Actions`
- `Activities`

Invoked effects, 非同步執行的 side-effect

- `Invoked Promises`,
- `Invoked Callbacks`,
- `Invoked Observables`,
- `Invoked Machines`,

---

### 第十四章 - Actions

- 用來處理外部的 side-effect
- 包含三種時機, `entry`, `exit`, transition taken
- 定義方式 `entry: []`, `exit: []`, `actions: []`
- action function implementation 定義在, `createMachine()`, 的 options 參數裡, `actions: {}`

Declarative Actions

- `type`, action type 對應的名稱, `exec`, 實作的函式
- `exec` function 會傳入的參數,
  - `context`, currentState.context
  - `event`,
  - `actionMeta`,
    - `action`,
    - `state`,

Action order

- action 最好不要相依於執行順序

Send Action

- `send(event)`, 特殊的 action 用來發送 event 給自身, `send(event)` 只是一個 pure 的 action creator

Send Targets

- 發送 event 的目標可以從 `target` 與 `to` 來指定

Raise Action

- `raise()`

Respond Action

- `respond()`

Forward To Action

- `forwardTo()`

Escalate Action

- `escalate()`, 發送 error 到父層

Log Action

- `log()`, logger

Choose Action

- `choose()`,

Pure Action

- `pure()`, 動態生成的 action, 例如動態產生 `to` 位置

Actions on self-transitions

- 在自身 state 運作的 transition 分成兩種
- `internal`, 不會離開自身, 因此 `entry`, `exit` 不會觸發, 但是 `actions` 會執行
- `external`, 會離開自身再回來, 因此 `entry`, `exit`, `actions` 皆會觸發

SCXML

- 對應到 `<onentry>`, `<script>`, `<onexit>`, `<transition>`

---

### 第十五章 - Guarded Transitions

- 通過 guarded function 判斷後才決定執行的 transitions

Guards (Condition Functions)

- `cond:`, 會傳入 `context`, `event`, `condMeta` 回傳 boolean

Custom Guards

- 可以客製化傳入的 `cond` metadata

Multiple Guards

- Guards 可以提供多個對應, 並且第一個為 `true` 的 transition 則被採用
- 盡可能先以多個 event type 為優先, 之後才是使用 Guards

"In State" Guards

- `in`,
- 作為一個可以被 refactor 的訊息, 應該盡少採用 `in`

SCXML

- 對應到 `<transition cond>`

---

### 第十六章 - Context

Context

- 實際的資料是有無限組合的, 因此被是為獨立於 FSM 之外的 context
- 只有在配合 context 時才能更適合的把 FSM 運用在真實的 Application 上
- `action` 裡呼叫 `assign` 來實作添加 context 內容

Initial Context

- 定義於 `createMachine` 第一參數裡的 `context`
- Dynamic initial context, 可以把動態參數帶給 `createMachine` 在傳入 `context` 中, 這樣在初始化 machine 時可以一同傳入 dynamic context

Assign Action

- `action` 裡使用 `assign()` 來更新 context 內容, 傳入一個 object 或 function
- 推薦優先使用 object 形式

Action Order

- `assign()` action 會被 batch 且優先執行的

Notes

- 不要在外部以 mutate 的方式修改 context, 應該明確的依據 event 來修改, 才有可預測性
- 優先使用物件模式定義, 可以提供更多的 debug analysis
- `Assign` 是有順序性的
- 最好以 `action` 配合命名函式的方式, 定義 `assign` function
- 理想狀態下 context 是可被序列化成 JSON 的
- assign function 會被 batch 且優先於其他的 actions 之前執行, 要小心順序問題

TypeScript

- 定義 context type, 並且傳入 `createMachine<>`
- assign function 可以帶有 context type 與 event type, `assign<Context, Event>(...)`

Quick Reference

- 實用的 code example

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
