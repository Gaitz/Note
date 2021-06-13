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

- 選用的, `createModel()`, 建立 context 與 event, 提供 event creator helper, 提昇 Typing

`createModel()`

- 傳入: `initialContext`, `creators` (optional), event creators

model context

- model `.initialContext`, 提供建立 machine 時的 initial context
- model `.assign()`, 更新 context

model events

- 使用 model `.events.` eventName 作為 event creator 建立 event

TypeScript

- 使用 createModel 建立時, 會推斷 context 與 events 的型別
- 建立 machine 時, 提供 model type `createMachine<typeof ${model}>`
- 在建立 machine actions 時, 提供選用的 eventType 可以使對應的 action 窄化 typing, `model.assign(assignments, eventType)`

---

### 第十八章 - Activities

- 一些持續時間的 side effect, 具有開始與停止的性質, 依據狀態 (state) 的進入與離開觸發
- 建立方式如同 React.useEffect 提供一個 callback function 且 callback function 的回傳函式為 cleanup 函式, 在 createMachine 時定義 `activities: {}`,
- activities function 會傳入 `context`, 與 `activity`

Restarting Activities

- 希望 restore 舊有的 state 時, 原先狀態內的 activities 預設不會主動重新觸發 (restart)
- 需要針對 state.actions 主動加上 `start()` 去明確表明要 restart

---

### 第十九章 - Invoking Services

- 把整個 app 所有的狀態都使用同一個 machine 表達, 是不切實際的
- 應該使用多個 machine 並且以 actor model 的模式, 發送與處理 messages 作為 machines 間的溝通
- 執行非同步 side-effect

invokes 的類型

- Promises
- Callbacks
- Observables
- Machines

定義在個別 state 裡的 `invoke: {}` 欄位

- 包含 `src`, `id`, `onDone` (選用), `onError`(選用) 等欄位

Invoke Promises

- Promises 可以被視為一個 machine, 分別以 resolve, reject 對應 onDone, onError

Invoke Callbacks

- `src` 定義為 `(context, event) => (callback, onReceive) => {}`, return 作為選用的 cleanup function
- `callback` function 用來發送 event, `onReceive` 用來接收 event
- 無法使用 `async/await` 因為會自動被包裝成 Promise 使用

Invoke Observables

- 作為單向的發送資訊的 stream 發送訊息給 parent
- 配合 RxJS 使用建立 observables
- `src` 定義為 `(context, event) => ()` 回傳一個 observables
- hot observables 可以在外部定義, 使用 reference 帶給 `src`

Invoke Machines

- Machines 是階層式的溝通, 父層 invoke 子代 machine
- 傳向子代 `send(EVENT, { to: '' })`
- 傳向父代 `sendParent(EVENT)`
- 可以藉由選用的 `data` 欄位傳遞資訊

Sending Responses

- 使用 actions `response()` 在 invoke machines 完成時回傳 event

Multiple Services

- `invoke: []` 以 `id` 區分, 可以使用相同的 `src` services

Configuration Services

- 可以定義在 `createMachine` 裡的選用參數 `{ services: {} }`
- invoke 時 `src` 可以使用 `{ type: }` 的方式使用 services

Testing

- 配合 `withConfig()` 提供 mock services

Referencing Services

- 使用 state object 裡的 `children` 可以取得 invoke 的 services

---

### 第二十章 - Actors

- Actor Model, 以 message 為基礎的溝通與計算模型
- 每個 actors 都可以發送, 接收, 與處理 message
- 類似於 invoke services 但是與之不同的是 actors 管理自己的 private state

Actors 類型

- Promises
- Callbacks
- Observables
- Machines

Actor API

- 每個 actor 都有 `id` 與 `send()` 和選用的 `stop()`, `subscribe()`

Spawning Actors

- 在 `assign` function 裡使用 `spawn` 以 `refName: spawn()` 建立 actor

Sending Events to Actors

- 使用 `send()` action 發送 event 給指定的 actors

Syncing and Reading States

- 預設 actor 的 state 是 private 的
- 可以使用 `{ sync: true }` optional 在 `spawn()` 階段, 讓 actor state 改變時 parent 會接收通知
- 然後直接使用 ref `.state` 讀取 actor state

Sending Updates

- 推薦使用 `sendUpdate()` action 主動通知 parent 所需要的狀態改變, 取代由 parent sync + 直接讀取 state

---

### 第二十一章 - Delayed Events and Transitions

- Time 與 delay 也是一種 event, xstate 提供 delayed transition 與 delayed event, 底層使用相同的工具實現

Delayed transition

- transition 會在 delay `after` 後自動發生
- 使用 `after: {}` 標示固定時間的 delay
- 在 `createMachine()` 選用的 `delays` 欄位定義 dynamic delay,
- 使用明確標示的 `delay: (context, event) => ()` 回傳 dynamic delay

Delayed events

- `send()` 發送的 event 可以包含選用的 `{ delay: }` 參數, 固定的 delay 時間或是產生 delay 時間的函式
- 可以配合指定 `id` 與 `cancel()` action 來取消 delayed event

Testing

- 使用 `import { SimulatedClock } from 'xstate/lib/SimulatedClock';`
- 在 `interpret()` 時傳入可控制的 clock

---

### 第二十二章 - Final States

- 使用 `type: 'final'` 標注終結的狀態, 可以搭配 `onDone` event
- Parallel 的 machines 都到達 final state 時, parent 也會被視為 final, 然後觸發 `onDone`, 可以被作為 `Promise.all()` 來處理平行

---

### 第二十三章 - History

- history `state` 作為特殊的 state 來紀錄 machine 的歷史狀態
- 可以分為兩種
  - `shallow`, 只紀錄當前一層的 history
  - `deep`, 紀錄包含子代的 state history
- 以特殊的 `type: 'history'` 作為 configuration, 包含兩個選用參數 `history: 'shallow' | 'deep'`, `target` history 初值

---

### 第二十四章 - Identifying State Nodes

- 指定 state 的方式
- 使用 default ID, absolute path
- 使用相對路徑, `.`
- 使用 custom ID, 在 state 定義時指定 `id` 欄位

Avoid strings

- 不使用 string ID 的方式
- 使用 `get` getter 定義

---

### 第二十五章 - Interpreting Machines

- machine 使用 `.transition()` 作為 pure 的狀態移動
- `interpret()` 初始化 machine, 作為 _service_ 存在
- 可以使用 `.start()` 啟動, `.send()` 傳遞 events, `.stop()` 停止服務, `onTransition()` 註冊 listener 監聽改變

Executing Actions

- 預設在 transition 時觸發定義好的 actions
- 可以通過 `execute: false` 參數停止預設行為, 另外配合 `onTransition()` 指定執行 action 的時機
- 例如 `requestAnimationFrame(() => service.execute(state))`

Custom Interpreters

- 取代使用 xstate 提供的 `interpret()`
- 可以自行定義 interpreter 來執行 machine

---

### 第二十六章 - Testing Machines

- 以 end-to-end 的角度測試 machine, 可以符合 behavior-driven development (BDD) 概念
- 測試: Given 當前狀態 (state), When 觸發 events, Expect 判別結果的 state 是否符合預期

Testing pure logic

- 測試 pure function 不包含 side-effect

Testing services

- 以整個 machine 作為 service 測試, 包含 side-effect

Mocking effects

- 以 machine `.withConfig()` 傳入 mock functions 取代實際的 side-effect

---

### 第二十七章 - Using TypeScript

- XState 使用 TypeScript 實作的, 因此可以良好的與 TypeScript 結合提供 typing 機制
- `createMachine<Context, StateSchema, Events>`, 提供三種 type 給予 machine, `Context`, `StateSchema`, `Events`

MachineConfig Objects

- 推薦使用 `MachineConfig<Context, StateSchema, Events>` 抽離 `createMachine()` 外定義

Actions

- `send()` action 應該使用 object 物件模式呼叫, 才能保證符合 event type

TypeStates

- 更精確定義的 State typing
- 以 union types 精準描述每個 state 的 typing

---

Recipes

---

### 第二十八章 - Using with React

- machine 邏輯應該完全與 React 無關
- 使用 xstate 提供的 `useMachine()` hook 傳入已經 create 出來的 machine (service)

---

### 第二十九章 - Using with RxJS

- `intrepret()` 且 `start()` 的 machine (service) 可以藉由 `from()` 轉換成 observable state

---
