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

- `computed` (annotaion), `computed(options)` (annotaion), `computed(fn, options?)`
- Computed value 只受 observable state 影響, pure function
- 計算值是 lazy 的並且 output 會被 cache
- 應該盡量使用, 由於 computed value 的流程會被效能最佳化
- 只有在配合 reaction 使用時才有效能最佳化, 在外不使用則會被視為一般的值, 因此會被重複觸發計算.

使用方式

- 使用 `class` 與 `makeObservable`, 以 `getter` 函式實現並且標註為 `computed`.
- 可以另外使用 `makeAutoObservable`, `observable`, `extendObservable` 使所有的 getter function 都自動標註為 `computed`

使用規則

- 不可以有 side-effect 包括更新 observables
- 避免建立和新的回傳 observable

其他

- setters 會被自動標註為 `action`

Options

- `name`, debug 使用的名稱
- `equals`, 調整比較算子, 透過 comparer function 決定重新計算的時機, 預設是 `comparer.default`.
  - MobX 有內建 4 種 `comparer` 提供選用
  - `compaper.identity`, `===`
  - `compaper.default`, `===` + `NaN` 與 `NaN` 視為相等
  - `compaper.structural`, deep comparison
  - `compaper.shallow`, shallow comparison
- `requireReaction`, 當 `computed` 非常昂貴時推薦設置為 `true`
  - 在 reaction 外部使用時會跳出警告.
- `keepAlive`, 在不被使用時 `comuted` value 仍會更新, 可能會造成 memeory leak.

---

### 第八章 - Reactions {🚀}

執行含有 side-effect 的工作

- 依據 observable state 自動觸發含有 side-effect 的 reaction
- 應該不常被使用
- 使用方式為 `autorun`, `reaction`, `when`

`autorun`

- 函式簽名 `autorun(effect: (reaction) => void)`, 傳入一個 function
- 每次相關的 `computed` 與 `observable` 變動時自動觸發, 並且在初次定義時也會觸發一次.
- 參考使用[範例](https://mobx.js.org/reactions.html#example)

`reaction`

- 函式簽名 `reaction(() => value, (value, previousValue, reaction) => { sideEffect }, options?)`
- 類似 `autorun` 但是提供更細微的控制, 需傳入 2 個 function,
  - 第一個是 data function, 作為傳入第二個 effect function 的值, 只有在 data function 裡的 `observable` 和 `computed` 值會被追蹤.
  - 第二是個 effect function, 執行 side-effect 的函式
- 使用方式是藉由 data function 去控制 effect function 的觸發時機, 並且與 `autorun` 不同的是在初次宣告時不會觸發.
- 參考使用[範例](https://mobx.js.org/reactions.html#reaction-example)

`when`

- 函式簽名 1 `when(predicate: () => boolean, effect?: () => void, options?)`
- 函式簽名 2 `when(predicate: () => boolean, options?): Promise`
- 只有在 predicate function 回傳 `true` 時會觸發 effect function
- 如果不傳入 effect function 時, `when()` 會回傳一個 Promise
- 利用 `async/await` 與 `when` promise 達到特定時機的執行, 並且可以通過 `cancel()` 提前關閉
- 參考使用[範例](https://mobx.js.org/reactions.html#when)

使用規則

- 受觸發的 reaction 會在相關的 trasaction 完成後**同步**且立即的執行
- 只作用於同步的資料更新, 追蹤不到異步的變化
- action 本身是 untracked

reaction function 的 garbage collection

- reaction function 只有在所有相關的 `observable` 被移除後才會移除.
- `autorun()`, `reaction()`, `when()`, 都會回傳一個停止追蹤的函式
- 強烈建議當不需要持續使用時, 需手動的關閉 reaction 追蹤, 否則可能造成 memory leak.
- 參考[範例](https://mobx.js.org/reactions.html#mem-leak-example)

小心謹慎的使用 reaction 的三個原則

- 只有在 event 與 effect 沒有直接相關的時候使用。
- Reaction 不會更新其他的 observable 的值，有此情況通常可以用 `computed` value 取代。
- Reaction 應該是 indepenant 的，MobX 不保證 reaction 的執行順序。

Options

- `name`, debug 所使用的名稱
- `fireImmediately` (`reaction`), 預設是 `false`
- `delay` (`autorun`, `reaction`), milliseconds, 預設是 0
- `timeout` (`when`), 設置等待時間上限
- `onError`, 預設在 reaction 內部的錯誤, 只會被 log, 並不會丟出錯誤 (throw), 可以使用這個 option 修改預設行為
- `scheduler` (`autorun`, `reaction`), 傳入 scheduler function 設定定期重複執行. 範例 `{ scheduler: run => { setTimeout(run, 1000) }}`
- `equals` (`reaction`), `comparer.default` 為預設值, 用來操作 data function 的比較與觸發 effect function 的時機.

---

MobX and React

---

### 第九章 - React integration

基本連接 React 與 MobX observables

- `import { observer } from 'mobx-react-lite'`, 使用 mobx-react-lite 較輕量化適用於 function components
- `const MyComponent = observer(props => ReactElement)`, observer 作為 HoC 封裝所有會使用到 MobX observables 的 React Component.

External state (global state)

- MobX observable state 可以很自由的作為 global state 傳遞
- 傳遞方式
  - 使用 props, 單純把 observables reference 以 prop 的方式傳遞給要使用的 React component
  - 直接使用 global reference 的方式取得. (較不推薦雖然可以運行但是難以執行單元測試, 因為相依全域資源)
  - 使用 React Context 傳遞, 直接使得整個 React tree 可以跨層取值, (推薦使用)
- 參考[範例](https://mobx.js.org/react-integration.html#using-external-state-in-observer-components)

Local state

- 使用 MobX 的 observables state 作為 local state 的更新機制，MobX observables 配合 `React.useState` 使用
- 參考使用[範例](https://mobx.js.org/react-integration.html#using-local-observable-state-in-observer-components)
- 不推薦使用 MobX observables 來處理 local state.
- 推薦單純使用 React.useState 作為 local state 的解決方案，未來才容易相容於 React Suspense Mode.

注意事項

- 使用 MobX observables 一定要使用 `observer()` component, 才能保證 MobX 運作的正確性. 因此推薦所有的 React component 都用 `observer()` 包裹
- 盡可能在需要的時候才直接讀取 observable state, 不需要從上層傳遞, 才能確保渲染效能最佳化, 讓 MobX 只重新渲染關鍵的 component
- 不要傳遞 observables state 至**非** `observer()` component, 內部不會自動更新.
- inline callback component 可以使用 `<Observer></Observer>` 包裹作為一次性使用.

Tips

- 配合 SSR 使用需開啟 `enableStaticRendering(true)`
- `mobx-react` 作為 `mobx-react-lite` 的超集合, 主要需求在於配合 React class component
- `observer()` component 會自動使用 `React.memo` 因此可以不必要額外包覆.
- 使用命名函式定義 function component 提供 React devtool 的 debug 名稱
- 需要套用多個 HoC 時, `observer()` 需要作為最內層才能正常運作.
- reaction 與 useEffect 一同使用時, 記得處理 reaction 的 **disposer**, 否則在 component unmount 時會造成 memory leak.
- React component re-rendering [troubleshooting](https://mobx.js.org/react-integration.html#troubleshooting)

---

### 第十章 - React optimizations {🚀}

- 切細 component 使用小粒度的 component, 每個 component 只 render 特定的 observables state, 讓 MobX 可以精準的 re-render.
- Render list 時, 由於 React list rendering 本身是相對耗效能的行為, 因此最好自成一個 function component, 避免不必要的觸發重新計算. 參考[範例](https://mobx.js.org/react-optimizations.html#render-lists-in-dedicated-components)
- 不使用 array index 作為 list `key` 使用
- 只在需要的時候才引用需要的 observables state, 減少不必要的 re-rendering.
- 為了精準 re-rendering, 產生多個小粒度的 `observer()` component, 可以改用 function props 的方式協助開發, 參考[範例](https://mobx.js.org/react-optimizations.html#function-props-)

---

Tips & Tricks

---

### 第十一章 - Defining data stores

Stores

- 至少分成兩種 Domain stores 與 UI stores

Domain stores

- 一個應用程式應該有一個或多個 domain stores, 每個 domain store 分別負責一個概念.
- 經驗法則, 如果兩個 stores 具有包含關係的話應該被放在同一個 domain store 中.

Domain objects

- 推薦可以使用 `class` 的方式定義, `class` 可以內聚 action function 和 type,
- 相關的 stores object 可以使用 reference 傳遞
- 參考[範例](https://mobx.js.org/defining-data-stores.html#example-domain-store)

UI stores

- 通常包含所有與 UI 相關的設定值, 例如 session, i18n language, UI 狀態
- 參考[範例](https://mobx.js.org/defining-data-stores.html#ui-stores)

組合 stores

- 使用 `RootStore` 作為初始化和整合所有的 store
- 與 React 使用 context 傳遞 RootStore

---

### 第十二章 - Understanding reactivity

- MobX Reactivity,
- MobX 追蹤的是連結, 而非變數.
- MobX 無法響應在非同步行為中的 observable
- MobX 只能作用在設定追蹤的函式中, 例如 `autorun()`, ...
- 一系列的[範例](https://mobx.js.org/understanding-reactivity.html), 關於會成功響應與不回成功響應, 可以作為 debug 時的參考

---

### 第十三章 - Analyzing reactivity {🚀}

- 使用 mobx 工具協助除錯, `trace()`, `getDebugName()`, `getDependencyTree()`, `getObserverTree()`, `getAtom()`, `spy()`

`trace()`

- 使用[範例](https://mobx.js.org/analyzing-reactivity.html#usage-examples)

`getDebugName()`

- 函式簽名, `getDebugName(thing, property?)`

`getDependencyTree()`

- 函式簽名, `getDependencyTree(thing, property?)`

`getObserverTree()`

- 函式簽名, `getObserverTree(thing, property?)`

`getAtom()`

- 函式簽名, `getAtom(thing, property?)`

`spy()`

- 函式簽名, `spy(listener)`
- 參考[範例](https://mobx.js.org/analyzing-reactivity.html#spy)

---

### 第十四章 - Computeds with arguments {🚀}

- Computed 通常作為單純的 getter 使用，但是如果需要傳入參數時有以下四種方式實現
- 使用 functional component 作為範例，值得參考
- Derivations don't need to be computed,
- Close over the arguments, 把帶有 argument 的計算函式包在明確定義的 `computed()` 中
  - 提供更精準的 re-rendering
  - 推薦使用
- Move to state, 把取值邏輯作為 computed 封裝到 state 中
- Use computedFn {🚀}, 使用 `mobx-utils` 裡的 `computedFn` 來做 memorizing function
  - 不推薦馬上採用，先思考是否真的需要 memorize

---

### 第十五章 - MobX-utils {🚀}

- 另外的函式庫，包含使用 MobX pattern 時常見的工具, [library](https://github.com/mobxjs/mobx-utils)

---

### 第十六章 - Custom observables {🚀}

- 使用 `import { createAtom } from "mobx"` 實現客製化的 observables,
- 包含觸發更新的時機自行控制 `reportChanged()`
- 分別處理 observable 有被觀察時與沒有被觀察時 `reportObserved()`
- 文件中有參考範例

---

### 第十七章 - Lazy observables {🚀}

- 通過 `onBecomeObserved()`, `onBecomeUnobserved()` 來監聽一個 state 開始被 observe 與中止的事件
- 用來執行 lazy behavior 與執行 side-effect
- 例如在被觀察時才開始 fetching 資料並且在不會被觀察時關閉
- 參考文件範例

---

### 第十八章 - Collection utilities {🚀}

- 在沒有 Proxy 支援的情況下，也可以透過使用 `mobx` 中的 collections API 來讓 mobx 取得追蹤
- 提供統一界面的 API 可以使用在任意 collection 上
  - `values()`, `keys()`, `entries()`
  - `set()`, `remove()`, `has()`, `get()`

---

### 第十九章 - Intercept & Observe {🚀}

- `intercept`, `observe` 作為低階工具，不應該被直接使用
- 用來監控單一個 observable 的改變，但是監控不到 nested

---

Fine-tuning

---

### 第二十章 - Configuration {🚀}

- 額外的設定，用來符合特定的 JavaScript 環境
- Proxy Support, MobX 預設使用 proxy 來實現 array 與 object 的 observable
  - 可以通過設定告知 MobX 不要使用 proxy 但是會有使用限制
  - 要額外使用 Mobx collections utilities 來實現追蹤
- Decorator support, 開啟實驗性的 decorator 語法
- Linting options, 啟用 linting 設置，在開發時能更好的符合 Mobx pattern, 警告訊息可以適時的使用，不是嚴格的規定。
  - `enforceActions`, 提醒在更改 state 時必須以 action 的形式執行
  - `computedRequiresReaction`, 提醒在操作 computed 時必須要在 mobx 能知道的情況下，才能提供 cache 機制
  - `observableRequiresReaction`, 提醒在非 observable 環境使用 observable state, 例如在 React function component 中需要包裹在 `observer` 裡
  - `reactionRequiresObservable`, 找出不必要的 reaction
  - `disableErrorBoundaries`, 與 Mobx 處理發生在 reaction 中的 error 行為有關
- Further configuration options, 其他設定
  - `isolateGlobalState`, 在同一頁中有其他函式庫也使用 Mobx 時，會有不必要的共享。可以開啟這個設定來獨立正確的 MobX state

---

### 第二十一章 - Enabling decorators {🚀}

- 使用實驗性的 decorator 語法來操作 Mobx

---

### 第二十二章 - Migrating from MobX 4/5 {🚀}

- MobX 版本升級策略

---
