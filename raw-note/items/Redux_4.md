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

- 以小範例使用 redux-saga

---

### 第四章 - Saga Background

---

Basic Concepts

---

### 第五章 - Declarative Effects

---

### 第六章 - Dispatching Actions

---

### 第七章 - Effect

---

### 第八章 - Error Handling

---

### 第九章 - Using Saga Helpers

---

Advanced Concepts

---

### 第十章 - Channels

---

### 第十一章 - Composing Sagas

---

### 第十二章 - Concurrency

---

### 第十三章 - Fork Model

---

### 第十四章 - Future Actions

---

### 第十五章 - Non-Blocking Calls

---

### 第十六章 - Racing Effects

---

### 第十七章 - Root Saga

---

### 第十八章 - Running Tasks In Parallel

---

### 第十九章 - Task Cancellation

---

### 第二十章 - Testing

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
