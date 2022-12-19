## Redux Saga

### [Redux Saga Official documentation](https://redux-saga.js.org/), Redux

---

第一章 - About

Introduction

第二章 - Getting Started

第三章 - Beginner Tutorial

第四章 - Saga Background

Basic Concepts

第五章 - Declarative Effects

第六章 - Dispatching Actions

第七章 - Effect

第八章 - Error Handling

第九章 - Using Saga Helpers

Advanced Concepts

第十章 - Channels

第十一章 - Composing Sagas

第十二章 - Concurrency

第十三章 - Fork Model

第十四章 - Future Actions

第十五章 - Non-Blocking Calls

第十六章 - Racing Effects

第十七章 - Root Saga

第十八章 - Running Tasks In Parallel

第十九章 - Task Cancellation

第二十章 - Testing

第二十一章 - Using Run Saga

第二十二章 - Recipes

第二十三章 - External Resources

第二十四章 - Troubleshooting

第二十五章 - Glossary

第二十六章 - API Reference

---

### 第一章 - About

- `redux-saga` 是一個用來處理 side effects 的函式庫
- 概念上 saga 像是分了一個 thread 用來處理 side effect
- 是一個 redux middleware, 像是用一個額外的 thread 來管理有 side effect 的 redux action
- 語法上使用 ES6 的 generator function, 讓非同步 (asynchronous) 函式可以在語法上接近同步式 (synchronous) 語法
- Redux-saga 使用 generator function 取代 `async/await` 來處理非同步行為

---

Introduction

---

### 第二章 - Getting Started

Install

- `npm install redux-saga`
- `yarn add redux-saga`

範例: UI 按鈕點擊後會發送 http request 取得使用者資料

- Saga 會監聽有 side effect 的 action 並且觸發對應的函式
  - `takeEvery`, 監聽到的特定 action 每次都會執行
  - `takeLatest`, 監聽到的特定 action 只會執行完成最後一次呼叫, 先前的 action 如果在執行中會被 cancel
- Setup
  - `import createSagaMiddleware from 'redux-saga'`
  - `const sagaMiddleware = createSagaMiddleware()`
  - `const store = createStore(reducer, applyMiddleware(sagaMiddleware)`
  - `sagaMiddleware.run(mySaga)`

---

### 第三章 - Beginner Tutorial

- 以小範例使用 redux-saga 並且包含如何測試

---

### 第四章 - Saga Background

- 文件 WIP

---

Basic Concepts

---

### 第五章 - Declarative Effects

- Redux saga 使用 Generator function 實現
- 每次 generator function yield 都會回傳一個單純的物件 object
- 這些物件被稱為 Effects, 物件中提供足夠的資訊可以被 middleware 所執行
- 這些產生 Effects 的 helper function 來自 `redux-saga/effects` package
- 為了更容易測試, 使用 Effects 時, 呼叫每次的 generator function 所得的值 (yield) 都僅僅是一個單純的 object, 因此可以很容易地使用 `equal` 去測試, 而不用管實際執行的 side-effect
- 換句話說在, saga generator function 中, 每次的回傳值都只是 object, 即給予 saga middleware 的指令 (instructions)
- 執行時間由 saga middleware 決定, generator function 只負責宣告
  - 因此測試 saga generator function 實際上只測試到宣告, 因此不需要 mock 任何 side-effect
- `import { call } from 'redux-saga/effects'`
  - `call()` 代表 function call 的 Effect helper
- `import { cps } from 'redux-saga/effects`
  - `cps()` 適用於 Node.js 風格的 function call, `cps` Continuation Passing Style

---

### 第六章 - Dispatching Actions

- 在 generator function 中發送 action 到 store (dispatch)
- 如同 function call 一樣, dispatch 呼叫也有對應的 Effect function 來保持 generator function 只管理宣告的一致性
- `import { put } from 'redux-saga/effects'`
  - 使用 `put()` 取代直接呼叫 `dispatch`

---

### 第七章 - Effect

- 一般來說在 Saga 中執行任何 side effect 都是通過宣告式的 (declarative) Effect 實現
- 目標在於使用這些宣告式的方式, 實現等同於 `redux-thunk` 處理非同步的功能, 並且提供更好的可測試性

---

### 第八章 - Error Handling

- 在 Saga generator function 內可以使用 `try...catch` 來捕捉錯誤
  - 在測試上, 可以通過 Generator `.throw()` 帶一個 fake error 給 generator function, [docs: Generator.prototype.throw()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Generator/throw)
- 處理客製化的 Promise reject 可以通過回傳值在 Saga generator 做處理
  - [參考範例](https://redux-saga.js.org/docs/basics/ErrorHandling)
- `onError` hook
  - 作為最終防護, 為 Saga root 加上 `onError` hook, 來捕捉那些沒有預期到的嚴重錯誤
  - 加在 `createSagaMiddleware` `options` 裡, [文件](https://redux-saga.js.org/docs/api/#createsagamiddlewareoptions)

---

### 第九章 - Using Saga Helpers

- 通過 helper function 來指定 Saga action 的觸發方式
- `import { takeEvery } from 'redux-saga/effects`
  - `takeEvery`, 行為如同 `redux-thunk` 一樣
  - 每次收到非同步行為的 action 都會同步執行, 因此 store 最終的結果可能會依據個個非同步行為執行完成的順序而定
- `import { takeLatest } from 'redux-saga/effects`
  - `takeLatest`, 只希望依據最新的非同步 action
  - 意思是在遇到前一個 action 還沒結束時, 又接到新的 action 會把前項 action 自動 cancel

---

Advanced Concepts

---

### 第十章 - Channels

- Channel 用來溝通外部 event sources 或者多個 Saga 之間的溝通

Using the `actionChannel` Effect

- **watch-and-fork** pattern
  - `import { fork } from 'redux-saga/effects`

...

---

### 第十一章 - Composing Sagas

...

---

### 第十二章 - Concurrency

- 底層的 Effects
  - `import { fork, take, cancel } from 'redux-saga/effects'`
- 高階層的 Effects
  - `import { takeEvery, takeLatest } from 'redux-saga/effects`
- 高階層的 Effects 也可以通過低階層的方式實現
  - [參考文件](https://redux-saga.js.org/docs/advanced/Concurrency)

---

### 第十三章 - Fork Model

- redux-saga 裡面可通過兩種 Effects 來控制工作在背景執行
- `fork`, `spawn`

Attached forks `fork`

Detached forks `spawn`

---

### 第十四章 - Future Actions

- 實現 non-trivial flow
- `import { select, takeEvery } from 'redux-saga/effects`
  - `takeEvery('*')`
  - `select()`
- `import { select, take } from 'redux-saga/effects`
  - `take('*')`
  - `select()`
- takeEvery 是一種 push, 使用的 generator function 永遠不會結束
- take 是一種 pull, 讓 generator function 會結束, 因此可以被 garbage collection
- 範例:
  - 在 push 模式下的 LOGIN, LOGOUT 通常會變成兩個 action 分開實作
  - 在 pull 模式下可以實現 flow 在同一個 generator function 裡面
    - 因為 pull 模式更可以控制流程, 可以實現類似狀態機的功能

---

### 第十五章 - Non-Blocking Calls

- 以 `take`, `call`, `put` 實現 login flow 的範例
- `call()` 除了一般 function call 之外, 也可以用來呼叫其他的 generator function
  - 來實現進入 sub flow 的概念
  - 但是使用 `call()` 的呼叫是會 blocking 的, 像是同步的行為
- 以 pull 模式實現, 可以讓 flow 呈現在同一個地方
  - 產生 code 即文件的用處, 可以很清楚地呈現 flow 的流程
- 以 `fork()` 實現非同步的行為, non-blocking call
  - 但是要自行控制非同步流動, 並且在需要的時候使用 `cancel` 來關閉執行中的 fork task
- 配合 `finally` 與 `cancelled()`
  - 來客製化 cancel 之後的行為

---

### 第十六章 - Racing Effects

- `import { race } from 'redux-saga/effects`
  - 不等全部結束, 而是 race
  - 更重要的是 race 會自動 cancel 其他輸的 effects
- 可以配合 `import { delay } from 'redux-saga/effects`
  - 與 delay 進行 race 實現 timeout 功能

---

### 第十七章 - Root Saga

- Root Saga Patterns
  - 以 `all()` 包含所有的 sub saga 形成一個 root saga 作為 saga middleware 的入口
  - `all()` 裡的 saga 是平行執行的 (parallel)
- Non-blocking fork effects
  - 以 `fork()` 取代 `all()` 實現 root saga
  - 差異之處在於 `fork()` 會回傳 task descriptor 可以提供更多的控制機會
- Nesting fork effects in all effect
  - 同時使用 `all` 與 `fork`
  - `const [task1, task2, task3] = yield all([ fork(saga1), fork(saga2), fork(saga3) ])`
  - 壞處是 fork 產生的 uncaught error 會浮出來影響到 root 並且無法被捕捉處理
- Avoid nesting fork effects in race effect
  - 不要在 `race` 裡使用 `fork`, fork 永遠會立刻贏,
- Keeping the root alive
  - 避免讓 sub saga 的預期外錯誤影響到 root saga
  - 以 `spawn()` 取代 `fork()`
  - 以 `spawn()` 實現類似 React Error Boundaries 的功能避免 root saga 壞掉
  - 在沒有實現 recovery 功能之前, `spawn()` 會導致出問題的 saga 在 app lifetime 永遠失去功能
- Keeping everything alive
  - 並不推薦直接讓任何壞掉的 saga 自動重啟
  - 重點在於該壞掉的時候壞掉, 並且讓我們知道

---

### 第十八章 - Running Tasks In Parallel

- `yield` 是循序的
- 平行處理非同步呼叫
  - 把 `call` function 放在 `all([])` 裡面

---

### 第十九章 - Task Cancellation

- 一個 `fork` task 可以通過 `yield cancel(task)` 來取消
- [文件中有範例](https://redux-saga.js.org/docs/advanced/TaskCancellation), 使用 `cancel`, `finally`, `cancelled`
  - 底層實現方式是通過 [Generator.prototype.return](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Generator/return)
- `cancel` 是會自動傳遞的, 因此多層的呼叫都能成功地被 cancel
- 測試 `fork` Effect
  - 可以使用 `import { createMockTask } from '@redux-saga/testing-utils' `
  - 可以配合 `setRunning`, `setResult`, `setError` 等工具
  - [參考範例](https://redux-saga.js.org/docs/advanced/TaskCancellation#testing-generators-with-fork-effect)
- 補充 `cancel` 並不會等待 `cancelled` task 完全工作完成
  - 如同 `fork` 一樣是 non-blocking 的
- Automatic cancellation
  - `race` Effect 會自動關閉輸家
  - `all()` Effect 會自動關閉如果任何的錯誤發生, 等同於 `Promise.all` 的行為

---

### 第二十章 - Testing

Testing the Saga Generator Function

- 依序測試, 因為 Saga Generator function 每次的回傳值都是 object 因次可以簡單的判別

Branching Saga

- `import { cloneableGenerator } from '@redux-saga/testing-utils`
  - 生成出一個可以 clone 的 generator 協助測試 branching 時候的行為
  - 而不用重新建立並且移動到分支的位置
  - [參考範例](https://redux-saga.js.org/docs/advanced/Testing#branching-saga)

Testing the full Saga

- 測試完整的 Saga 可以不需要 Redux
- 而是使用 mock 然後配合 `runSaga()` 取得 saga
  - [參考範例](https://redux-saga.js.org/docs/advanced/Testing#testing-the-full-saga)

Testing libraries

- 各種不同的第三方測試庫, 來協助撰寫 Saga test, 包含 unit test 和 integral test

---

### 第二十一章 - Using Run Saga

---

---

### 第二十二章 - Recipes

---

### 第二十三章 - External Resources

---

### 第二十四章 - Troubleshooting

---

### 第二十五章 - Glossary

---

### 第二十六章 - API Reference

---
