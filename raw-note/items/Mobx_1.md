## Mobx Official Documents

### [Mobx official document](https://mobx.js.org/README.html), Mobx

---

Introduction

第一章 - README
第二章 - About this documentation
第三章 - Installation
第四章 - The gist of MobX

MobX core

第五章 - Observable state
第六章 - Actions
第七章 - Computeds
第八章 - Reactions {🚀}

MobX and React

第九章 - React integration
第十章 - React optimizations {🚀}

Tips & Tricks

第十一章 - Defining data stores
第十二章 - Understanding reactivity
第十三章 - Analyzing reactivity {🚀}
第十四章 - Computeds with arguments {🚀}
第十五章 - MobX-utils {🚀}
第十六章 - Custom observables {🚀}
第十七章 - Lazy observables {🚀}
第十八章 - Collection utilities {🚀}
第十九章 - Intercept & Observe {🚀}

Fine-tuning

第二十章 - Configuration {🚀}
第二十一章 - Enabling decorators {🚀}
第二十二章 - Migrating from MobX 4/5 {🚀}

---

Introduction

---

### 第一章 - README

Introduction

- 所有東西都應該受 state 自動的驅動
- 使用 functional reactive programming 的方式管理 state

三個理想

- Straightforward, 最簡化, 不需要多於的樣板程式碼
- Effortless optimal rendering, 渲染最佳化, 不需要手動設置, 例如 memoization 與 reselect 機制
- Architectural freedom, 程式結構分離, 完全分離 state management 跟 UI 層

單向流

- event 觸發 -> Actions -> update 更新 -> Observable State -> notify 通知 -> Computed Values -> Side-effects (re-render) -> event 觸發

---

### 第二章 - About this documentation

- 使用 {🚀} 標示的代表進階內容，在不需要使用的前提下可以跳過。
- 文件是最新版的 MobX 6, 以下的版本有另外的 API 文件。主要概念相同，但是有些 syntax 有所不同。

Guided tour

- 推薦閱讀順序
- 以及 API reference [連結](https://mobx.js.org/api.html#core-apis)


---

### 第三章 - Installation

- 可以運行在任何 ES5 以上環境，包含瀏覽器與 Node.js
- 與 React 連結的函式庫分別為 `mobx-react-lite` 用於 functional component, `mobx-react` 用於 class component
- 可以使用 Yarn, NPM, CDN 安裝

配合 TypeScript, Babel, 與 `class` syntax 使用時

- Babel 與 TypeScript 需要針對 `class` syntax 做額外設定值

MobX 在不支援 `Proxy` 的環境中

- MobX 使用 `Proxy` 用來優化效能，在不支援的環境中需要設定值關掉這項功能。

MobX 與 Decorators 使用

- MobX 6 預設不使用 Decorators 語法，如果要使用時需要額外設定開啟。

MobX 在其他框架與平台

- MobX 可以配合 Flutter/Dart, lit-element, Angular, Vue 使用

---

### 第四章 - The gist of MobX

#### 三個概念

- State
- Actions
- Derivations

順序

1. 建立 state 並且設置成 observable
    - State 是應用程式的狀態資料，多數時是與應用程式 domain 直接相關的
    - MobX 可以支援多種不同的資料結構
    - 只要標註成 `observable` 則 MobX 就會開始追蹤使用
1. 使用 action 更新 state
    - action 是任何會改變 state 的程式碼
    - 藉由主動標記成 `action` 讓 MobX 做效能最佳化
1. 建立 derivations 在 state 改變時自動反應
    - 任何單純受到 state 影響的行為就是 derivations
    - 例如 UI 更新, 重新計算值, 呼叫其他 API

MobX 把 derivations 分成兩種

- `Computed values`, state 改變觸發 pure function
- `Reactions`, state 改變觸發 impure function (含有 side-effect)
- 盡可能的優先使用 Computed values, (pure function)

Computed value

- 配合 `class` syntax 與 `get` syntax 同時標記為 `computed` 

Reactions 

- 觸發 side-effect function

Reactive React components

- 配合 React 使用時可以對 component 使用 `observer()`，自動讓 component 受 MobX derivation 並且最佳化 re-rendering 時機

Custom reactions

- 配合 `autorun()`, `reaction()`, `when()` 建立 custom reaction

#### 原則

- MobX 使用單向資料流
- Actions -> Observable State -> Derived Values -> Reactions
- 所有的 derivations 會依據 state 改變自動觸發
- 所有的 derivations 是同步的觸發, 因此不用擔心資料更新的順序會錯亂
- Computed values 的更新是 lazy 的，只有真正需要被用到時才會觸發更新
- Computed values 是 pure 的，也不會再次改變 state

可以開啟 [linting](https://mobx.js.org/configuration.html#linting-options) 協助採用 MobX


---

MobX core

---

### 第五章 - Observable state

建立 observable state

- 多種資料結構例如 object, array, Map, Set 都可以被設為 observable
- 主要使用 `makeObservable` 並且配合標註 `observable`, `action`, `computed`

`makeObservable`

- 函式簽名 `makeObservable(target, annotations?, options?)`
- 主要用於 `class` syntax 的 `constructor()` 裡
- `target` 綁定 `this`, `annotations` 標註 class members 的類型 (`observable`, `computed`, `action`)

`makeAutoObservable`

- 函式簽名 `makeAutoObservable(target, overrides?, options?)`
- 主要用於物件實字 `{}`, 配合 factory function 自動建立 observable state
- 依據[規則](https://mobx.js.org/observable-state.html#makeautoobservable)自動註記 members 類型
- 可以藉由 `overrides` 欄位，手動改變註記型別
- 無法使用在 `class` syntax 上

`observable`

- 函式簽名 `observable(source, overrides?, options?)`
- 主要用於各種資料結構, 例如 array, set, map, object, **clone** 資料後自動標註所有的 members 成為 observable 並且回傳
- 可透過 `overrides` 欄位改寫註記型別
- 透過 `Proxy` 實現, 因此要確定 `Proxy` syntax 可以使用

Annotations 型別清單

- `observable`, `observable.deep`, 遞迴的標註成 observable, 可以用在 object, array, Map, Set
- `observable.ref`, 只有在 reassignment 時才會觸發, 常用於配合 immutable data
- `observable.shallow`, 等同於 `observable.ref` 但是做用於 collection 資料結構上, 例如 object, array, Map, Set
- `observable.struct`, 等同於 `observable.deep` 但是在 assign 完全相等的結構資料時, 不會觸發 observable
- `action`, 會改變 state 的 methods
- `action.bound`, 會自動綁定 `this` 的 `action`
- `computed`, 可以被設置成 getter 並且會被 cached, 由 state 改變後觸發
- `computed.struct`, 等同於 `computed` 但是在重新計算後發現值完全相等時, 不會觸發 observable
- `true`, 使用 `makeAutoObservable` 規則自動標註型別
- `false`, 明確指定不標註任何 annotations
- `flow`, 管理非同步行為
- `autoAction`, `makeAutoObservable` 內部使用，不能手動標註

限制

- `make(Auto)Observable`, 只能作用於事先定義的 properties
- `makeObservable`, 只標註 `class` 本身的 properties, 不包含 super 與 sub class
- 使用 TypeScript 時需要特別標註型別
- JavaScript 的 private member syntax `#field` 不被支援, TypeScript 則需使用 `private`

`options` 選項

- `autoBind: true`, 自動綁定所有的 action 到 instance 上。`this` binding
- `deep: false`, 預設改成使用 `observable.ref`
- `name: <String>`, 提供 debug 工具使用的 `name`

observables 轉換成原始的 JavaScript collections

- shallow convert, 通過 deconstructing assignment, array `slice()`, `new Map()` 實現
- deep convert, 可以通過 `toJS` utility, class 則需要實作 `toJSON()` 藉由 `JSON.stringify`

關於 `class` syntax 用法

- 官方推薦使用 `class` 定義 observable state，用來提供更多的最佳化
- 但是不要使用過多層的 inheritance，讓 `class` 盡量簡單

---

### 第六章 - Actions

更新 state 的 actions

- 使用 `action` (annotation), `action(fn)`, `action(name, fn)`
- 在主要時候 `action` 都是由 event 所觸發
- 明確的定義 action 讓程式碼更易讀，並且讓 MobX 提供效能最佳化的機會
- 預設只有 `action` 能夠改變 state
- 只有會改變 state 的函式應該被標註為 `action`
- 透過 `makeObservable`, `makeAutoObservable`, `action.bound`, `action(fn)` 標註 action, `runInAction(fn)` 觸發一次性的 action

`action(fn)` higher-order function

- `action(fn)` 被做為 higher-order function 封裝會改變 state 的任何 event handler function。
- MobX 的交易性 (transactional) 同步式的改變一組值，避免更新一半的 state 產生

`action.bound`

- Annotation 
- 自動綁定 `this` 到 instance
- 在配合使用 `makeAutoObservable` 時可以使用 arrow function 取代 action.bound 定義

`runInAction`

- 函式簽名: `runInAction(fn)`
- 一次性的執行 action

非同步 actions

- 參考[範例](https://mobx.js.org/actions.html#asynchronous-actions)
  - Promise
  - Promise in class
  - async/await + `runInAction`
  - `flow` annotation + generator function
- 主要想法 MobX 的 action 不需要因為非同步而特殊設定，只需要確定改變 state 時的 function 有被標註成 action 即可。(例如使用 `action(fn)`, `runInAction(fn)`)

使用 `flow` + generator function 取代 async/await

- annotation `flow` 
- 函式簽名 `flow(function* (args) {})`
- 使用 `flow` annotation 與 `flow()` 函式傳入 generator function，取代 async/await。
- 程式碼效果類似 async/await 但是 action 不需要額外標註，在 generator function 內的 action 會自動被 `flow()` 標註
- 另一個特點是 `flow` 可以被中途取消 (cancelling flows), `flow()` function 回傳的 Promise 會額外附帶 `cancel()` 函式可以停止 generator function 繼續執行。

---

### 第七章 - Computeds

---

### 第八章 - Reactions {🚀}

---

MobX and React

---

### 第九章 - React integration

---

### 第十章 - React optimizations {🚀}

---

Tips & Tricks

---

### 第十一章 - Defining data stores

---

### 第十二章 - Understanding reactivity

---

### 第十三章 - Analyzing reactivity {🚀}

---

### 第十四章 - Computeds with arguments {🚀}

---

### 第十五章 - MobX-utils {🚀}

---

### 第十六章 - Custom observables {🚀}

---

### 第十七章 - Lazy observables {🚀}

---

### 第十八章 - Collection utilities {🚀}

---

### 第十九章 - Intercept & Observe {🚀}

---

Fine-tuning

---

### 第二十章 - Configuration {🚀}

---

### 第二十一章 - Enabling decorators {🚀}

---

### 第二十二章 - Migrating from MobX 4/5 {🚀}

---
