## React 前端開發的涅槃
### BOOK resource, React

------------------

第一章 - 初入 React 世界

第二章 - 漫談 React

第三章 - 解讀 React 原始程式

第四章 - 認識 Flux 架構模式

第五章 - 深入 Redux 應用架構

第六章 - Redux 高階運用

第七章 - React 伺服器端繪製

第八章 - 玩轉 React 視覺化

附錄 A - 開發環境

附錄 B - 程式開發標準

附錄 C - Koa middleware

------------------


### 第一章 - 初入 React 世界
  * View library 

#### Virtual DOM
  * React -> Virtual DOM -> Web DOM, Android app, iOS app (React-Native)

#### Functional Programming
  * UI 生成變為單純的函式對應

#### JSX
  * 真實的 DOM html element -> 對應到 Virtual DOM (json) -> 客製化 React Component (custom element, json) -> React Component 以類 html element 的方式表達 (JSX)
  * 反過來 JSX 需要經過編譯器才能變為瀏覽器認得的 JavaScript。
  * 使用 Babel 做為 JSX 編譯器。
  * 語法規則
    * 只能回傳一個 element，但是可以包裹多個。
    * element 一定要被關閉，`/`。
    * 客製化 component 以大寫開頭，html 原生 element 以小寫開頭。
    * 使用 JavaScript 語法 `{ }`。
    * 註解, 等同於 JavaScript 註解, `{/*  */}`
    * 屬性, `className`, `htmlFor`, 其他原生屬性依舊，客製化屬性使用 camel case 以小寫開頭。
    * boolean 屬性, 不填寫時預設為 `true`。
    * 屬性展開, attributes 以 JavaScript 物件模式儲存時，可以直接使用剩餘算子 `...` 展開且對應。`<Component {...attributesObject} />;`
    * 原生 element 的自訂屬性使用, `data-` 與 `aria-`。 客製化的 element 可以使用任意自定屬性。
    * HTML 自動跳脫防止 XSS。double encoding 時，需直接使用 UTF-8 字元。

#### React Component
  * React component (custom element), 由屬性 (props), 狀態 (state), 生命週期方法組成
  * 與 W3C 的 Web Components 標準不同。
  * HTML in JavaScript 的做法。

#### React Component 建構
  * `const CustomComponent = React.createClass({});`
  * ES6 class 語法, `class CustomComponent extends React.Component {}`
  * stateless pure render function, `function CustomComponent({}) { return (); }`, 只有 props, 沒有 states。
    * 無狀態 component, 在本質上與 class component 不同，不僅僅是使用 function 建構而已。

#### React 資料流
  * 單向, 由父層到子層
  * state, component 內部狀態管理, 通過 `setState()` 會觸發 component view 的更新。
    * 初始化, ES6 classes, 定義在 `constructor` 中的 `this.state`; createClass, 定義在 `getInitialState`
  * props, (properties) component 間的資料傳遞, 可以傳遞任何東西。
    * 使用 `defaultProps` 物件，設定預設值。
    * 定義形別 `propTypes`
  * 操作子元件 sub-components
    * `React.Children.*`
  * `React.cloneElement()`

#### React 生命週期
  * component 掛載 (mount), 移除 (unmount)
    * `componetWillMount()`, `componetDidMount()`, `componentWillUnmount()`
  * componet 更新 (update)
    * `comonentWillReceiveProps()`, `shouldComponetUpdate()`, `componetWillUpdate()`, `componentDidUpdate()`

#### React 與 DOM
  * 為了分離 view 建構邏輯與實際渲染, 分成兩個函式庫 **React**, **ReactDOM**.
  * `ReactDOM` 專注在於 web 上使用。
  * `DOMElement findDOMNode(ReactComponent component)`, 
  * `ReactComponent render(ReactElement element, DOMElement container, [function callback])`,
  * `unmountComponentAtNode()`,
  * `refs`, 一個特殊的 props, 用來取得實際的 DOM references。


------------------------------


### 第二章 - 漫談 React

#### 事件系統
  * Virtual DOM 在記憶體中以物件的形式存在。
  * React 自行處理事件的整合，SyntheticEvent。並且處理跨瀏覽器語法的問題，可以使用統一的介面，不管跨瀏覽器問題。
  * JSX 語法上使用 camel-case 以類似 HTML inline event 的語法綁定事件。
  * 事件委派 (event delegation)
  * 事件處理函式的 `this` 綁定
    * 在 constructor 中一次綁定 `this.handleFunction = this.handleFunction.bind(this)`
    * 使用 arrow function 宣告處理函式 `const handleFunction = (event) => {}`
  * 自行處理事件，使用原生的 DOM 事件處理，必須自行處理 component 移除時的垃圾處理，否則會有 memory leak 的問題。
    * 通過 `this.refs` 取得原生的 DOM 後操作。
  * 避免同時混用 React 合成事件介面與原生事件

#### 表單
  * `onChange` 事件
  * 受控元件 (controlled component), 使用 React `value` props 處理事件的 value 與 change，在實際 DOM 被操作時會同步改變 component 的 state。
    * `value` prop, `checked` prop, `onChange` event。
  * 非受控元件 (uncontrolled component), 表單 value 不受 React component 處理。

#### 樣式處理
  * inline style, `style` prop, 傳入一個物件。
  * 操作 `className`
  * CSS Modules
    * 通過 webpack css-loader 實現
    * 解決全域汙染, 命名混亂, 沒有依賴管理, 無法共用變數, CSS 壓縮不徹底。
    * `:local`, default, 
    * `:global`, 
    * `:composes`, 組合樣式
    * `:expoprt`, 輸出變數給 JavaScript
    * class 依 BEM (block, element, modifier) 命名

#### component 間的通訊
  * 父元件向子元件, 通過 props 
  * 子元件向父元件, 通過 callback functions prop
  * 跨元件溝通, React `context`, 提供一個跨元件的全域變數, 盡可能避免使用。帶來副作用破壞封裝。
  * 使用 event publish and substription pattern。

#### component 抽象層提升
  * mixin 與 higher-order component (HOC)
  * mixin
    * React component mixin, 合併 methods, state, props
    * 已不被推薦使用
    * 缺點, 破壞封裝, 命名衝突, 增加複雜度
  * higher-order component (HOC)
    * 傳入 React component 並且回傳一個 React component
    * component 之間互相包裹，因此生命週期的觸發是有順序的。
    * 應避免影響各自的 `state`
    * 屬性代理 (props proxy)
      * ```JavaScript
        const Wrapper = (WrappedComponent) => 
          class extends React.Component {
            render() {
              return <WrappedComponent {...this.props} />;
            }
          }
        ```
    * 反向繼承 (inheritance inversion)
      * ```JavaScript
        const Wrapper = (WrappedComponent) => 
          class extends WrappedComponent {
            render () {
              return super.render();
            }
          }
        ```
      * 可以做到繪製綁架 (控制 render)
  * 組合式元件開發, 依循 open-close principle, 切分成更細緻的 component 配合 HOC 抽象化邏輯並且組合使用。

#### component 效能最佳化
  * PureRender, 
    * 滿足 pure function 的定義
    * react-addons-pure-render-mixin, `this.shouldComponentUpdate = PureRenderMixin.shouldComponentUpdate.bind(this);`, 只做 shallow equal 比較, 減輕 state 與 props 的比較。
    * 事件綁定放在建構子中。
  * 使用 Immutable data
    * 避免了在 shouldComponentUpdate 時 deep copy 與 deep compare 造成的效能消耗。
    * 使用第三方 **Immutable.js** 函式庫
    * 不可變, 分離 time 與 value。
    * 輕鬆做到 redo, 資料的 time traveling。
    * 節省記憶體, 實現共用結構。
    * 缺點, 名稱不容易與原生資料結構區分。可用型別檢查工具, 約定的變數命名規則, import 時修改名稱來避免。
    * `Immutable.is`, 值比較, 通過內建的 hashCode 比較，效能佳。
    * `Cursor`, 存取深層資料。
  * key prop
    * 比對 key 後重繪, 因此 key 要盡量不變並且獨一無二的。
  * 效能檢測工具
    * **react-addons-perf**

#### 動畫
  * CSS 動畫
    * 功能簡單
  * JavaScript 動畫
    * SVG 動畫, **vivus.js**
    * **React Transition**
  * React Transition
    * componentWillAppear, componentDidAppear, componentWillEnter, componentDidEnter, componentWillLeave, componentDidLeave.
    * 形成約定的 class name, 使用 CSS 實現動畫。
  * 緩動函數
    * linear, ease, spring, ease, ease-in, ease-out, ease-in-out
    * cubic-bezier
    * 動畫物理引擎
  
#### 自動化測試 
  * Mocha + Chai assert library
  * Jest, Facebook 開源的 React 原始碼使用, 基於 Jasmine 架構, JSDOM
    * 需配合 **react-addons-test-utils** 提供的模擬 render, UI 互動
  * Enzyme, Airbnb 開源的, React 測試框架, 類 jQuery 語法
    * 可以取代 **react-addons-test-utils** 的功能。
    * `shallow`, 淺層繪製, 提升測試效能
    * `render`, 
    * `mount`, 
  * Continuous Integration (CI)
    * **Travis CI**, **Circle CI**


------------------------------


### 第三章 - 解讀 React 原始程式
  * React 15.0

#### 檔案架構
  * addons
  * isomorphic
  * shared
  * test
  * core/tests
  * renderers
    * dom: client, server, shared
    * shared: event, reconciler (Virtual DOM 的核心)

#### Virtual DOM 模型
  * Virtual DOM 中的節點稱為 ReactNode, 分成 ReactElement (ReactComponentElement, ReactDOMElement), ReactFragment, ReactText。
  * ReactElement = { type, props, key, ref }
  * 建立 React element `React.createElement()`
    * `ReactElement.createElement = function (type, config, children) { }`
    * `return ReactElement(type, key, ref, self, source, ReactCurrentOwner.current, props)`
  * 初始化 React component, `function inistantiateReactComponent(node, parentCompositeType)` 分類並且初始化 `return instance;`
    * 空元件 **ReactEmptyComponent**, `ReactEmptyComponent.create(instantiateReactComponent);`
    * DOM 原生元素 **ReactDOMComponent**, `ReactNativeComponent.createInternalComponent(element);`
    * 自定義元件 **ReactCompositeComponent**, `new ReactCompositeComponentWrapper();`
    * 字串或數字節點 **ReactTextComponent**, `ReactNativeComponent.createInstanceForText(node);`
  * 文字元件 **ReactTextComponent**
    * ReactTextComponentFactory (mountComponent 掛載, construct 創建, receiveComponent 更新)
      * construct -> transaction.useCreateElement (openingComment + stringText + closingComment, escapedText)
    * `var ReactDOMTextComponent = function (text)`
  * DOM 原生元素 **ReactDOMComponent**
    * mountComponent -> `_createOpenTagMarkupAndPutListeners (transaction, props)` -> `_createContentMarkup`
    * updateComponent -> `_updateDOMProperties (lastProps, nextProps, transaction)` ->  `_updateDOMChildren (lastProps, nextProps, transaction, context)`
    * unmountComponent
  * 自定義元件 **ReactCompositeComponent**
    * 更新方式等同於 ReactDOMComponent
    * 生命週期 

#### 生命週期 (React Component Life Cycle)
  * 元件, 有限狀態機 (FSM), 生命週期
  * 初次掛載, `getDefaultProps()` -> `getInitalState()` -> `componentWillMount()` -> `render()` -> `componentDidMount()`
  * 移除元件, `componentWillUnmount()`
  * 重新掛載, `getInitalState()` -> `componentWillMount()` -> `render()` -> `componentDidMount()`
  * Props 改變, `componentWillReceiveProps()` -> `shouldComponentUpdate()` -> `componentWillUpdate()` -> `render()` -> `componentDidUpdate()`
  * State 改變, `shouldComponentUpdate()` -> `componentWillUpdate()` -> `render()` -> `componentDidUpdate()`
  * 主要的三個階段, mountComponent, updateComponent, unmountComponent
  1. 使用 `createClass` 建立, ReactClass.createClass == extends React.Component
    * `new ReactClassComponent()`
  1. Mounting
    * `mountComponent()`, `performInitialMountWithErrorHandling()`, `performInitialMount()`
    * `_pendingStateQueue`, `_pendingReplaceState`, `_pendingForceUpdate`
    * 遞迴 render
  1. updateComponent, Receive_Props
    * `receiveComponent()`, `updateComponent()`, `_performComponentUpdate()`, `_updateRenderedComponent`
    * 遞迴 render
  1. Unmounting
  * 在 React 中盡可能使用無狀態元件 (stateless component) 以提升效能。

#### 無狀態元件 (stateless component)
  * 只是一個 render 方法，並沒有產生實體過程，也沒有實例回傳。因此沒有狀態、沒有生命週期。
  * 簡單、高效、盡可能使用。

#### `setState()`
  * 使用 `this.state` 讀取，使用 `this.setState()` 寫入。永遠不要直接修改 `this.state`。
  * 使用 queue 來實現 state 批次更新機制。
  * `ReactComponent.prototype.setState`, `enqueueSetState()`
  * `enqueueUpdate()`, `batchingStrategy`, `transaction.perform()`

#### Transaction
  * transaction 與 batching
  * initialize, perform, close, closeAll, notifyAll

#### diff (Virtual DOM)
  * diff 與 Virtual DOM
  * 傳統的 tree diff 演算法效能 O(n^3)
  * 目的是從 Virtual DOM 轉換到 actual DOM 使用最少的操作。
  * O(n^3) -> O(n)
  * tree diff, component diff, element diff
  * tree diff, 分層比較, 不存在即刪除子樹。 
  * component diff, 用 component 類型來分類，Type 不同即刪除。
  * element diff, 同一層的節點使用 key id 去做區別並且新增移動或刪除, `INSERT_MARKUP`, `MOVE_EXISTING`, `REMOVE_NODE`
  * Best Pratice:
    * 保持 DOM 的穩定，盡可能使用 CSS 隱藏或顯示，而非移除或新增節點。
    * 避免最後一個節點移動到開頭的操作。

#### React patch
  * 更新到真實的 DOM 節點。
  * `processUpdates()`


------------------------------


### 第四章 - 認識 Flux 架構模式
  * Facebook 開源的 Application Architecture for Building User Interface
  * 分離顯示邏輯與資料邏輯
  * 視為一種 design pattern
  * 缺點, 有各家實作並且對設計有自己的解釋。

#### React 獨立架構
  1. 分離資料邏輯
      * container component, 含有抽象資料，沒有業務邏輯。
      * presentational component, 沒有資料請求，只有業務邏輯。
  2. 使用 HOC 抽象化，資料請求邏輯。

#### MV* 與 Flux
  * MVC, 
    * Model, 與業務資料有關，負責處理資料同步。
    * View, 目前狀態的顯示。
    * Controller, 連接 View 與 Model。
    * 缺點: 資料流複雜
  * MVVM, (Angular), 使用雙向 data binding 取代 controller
    * View,
    * ViewModel,
    * Model,
  * Flux, 資料和邏輯永遠單向流動
    * Action -> Dispatcher -> Store -> View -> Action
    * React 做為 View 層每次變動都修改 Virtual DOM，可以避免 actual DOM 重覆修改的效能問題。

#### Flux 基本概念
  * 3大部分
    * dispatcher, 分發事件
    * store, 儲存資料
    * view, 依據 store 的資料顯示
  * dispatcher,
    * `register(callback)`
    * `dispatch(action)`
    * action 只是單純的 type 與 payload。
  * store,
    * 負責儲存資料, 並且定義修改資料的邏輯
    * 註冊在 dispatcher 中，讓 `dispatch(action)` 觸發時能收到。
    * 對外只有唯獨的 getters。
  * controller-view, 
    * 監聽 store 能收到更新事件。
    * 通過 store getters 取得資料傳遞給 view
  * view, 
    * 顯示層
    * 限制修改資料，只能通過 dispatcher 發送 action 的方式。
  * actionCreator,
    * 介於 view 與 dispatcher 之間。
    * view 不需要直接呼叫 dispatcher 而是透過 actionCreator。

#### Flux 應用範例
  * 基本檔案結構,
    * css/
    * js/ actions, components, constants, dispatcher, stores, app.js
  * 權衡需要管理的資料 (state) 需不需要透過 flux 系統託管。
  * 單元測試, 模擬 dispatcher 觸發 action ，然後檢查 store 的改變。


------------------------------


### 第五章 - 深入 Redux 應用架構
  * 一個架構思想
  * Flux + Functional Programming
  * Redux = reduce + flux
  * 可預測的狀態容器 (predictable state container)

#### Redux 三大原則
  * 單一資料來源
  * 狀態是唯讀的
    * 狀態由 reducer 生成
  * 狀態修改通過 pure function 完成
    * reducer 皆是 pure function

#### Redux 核心 API
  * 單一 store 由 `createStore(reducers[,initialState])` 產生
  * 回應 action 生成新資料的 reducer，本質上是一個純函式 `reducer(previousState, action)` => newState
  * store 包含四個方法
    * `getState()`, 取得 store 目前狀態
    * `dispatch(action)`, 唯一能改變 store 的地方，發送一個 action 並且回傳這個 action。
    * `subscribe(listener)`, 註冊監聽, 讓 store 改變時能收到通知。與外部系統結合的地方。
    * `replaceReducer(nextReducer)`, 更新 reducer。

#### 與 React 綁定
  * Redux 做到與平台無關, 因此需要使用 **react-redux**。
  * 通過 React component, `<Provider />` 與 `connect()`
    * `<Provider />`, 以 props 傳入 store
    * `connect()`, 取得 store 中的資料

#### Redux middleware
  * 提供介入 dispatch action 與 reducer 之間的能力。
  * middlewares -> dispatch -> action -> reducer
  * `applyMiddleware()`
  * functional programming 中的 currying 與 compose。

#### Redux 非同步流
  * 實現非同步請求
  * 使用 Redux middlewares
  * **redux-thunk**, Thunk 函數型式, 開源
  * **redux-promise**, 開源
  * **redux-composable-fetch**, 自行時做出有 loading 狀態的非同步請求。
  * polling, `setRafTimeout()`
  * 非同步串聯
  * **redux-saga**, 使用 generator 取代 promise。

#### Redux 與 router
  * SPA 中的前端 routing
  * 整合 **React Router** 的狀態到 **Redux** 中。
  * **React Router**
    * 保障 View 與 URL 同步
    * 可以被瀏覽器 history 記錄
    * React, `view component(props)`; 
    * React Router, `view router(location)`
    * 使用 JSX 語法，宣告式設定 Router 與 Route。
    * 支援 hashChange 或 history.pushState
    * 支援巢狀式路由, 配合 SPA 只改變頁面中的部分元件
  * **React Router Redux**
    * 把路由狀態整合到 Redux store 中。
    * `syncHistoryWithStore()`, 連結 
    * `routerMiddleware()`, 創造 middleware 允許 store 發送 routing action。

#### Redux 與 component
  * container component, Flux 中對應 store 的 component; Redux 中使用 connect() 的 component。
  * presentational component, 只管顯示, 不管資料來源。
  * Redux 中的 component 分類,
    * Layouts, 描述頁面結構
    * Views, Routing 入口並且連接 Redux store 。
    * Components, 顯示層的 components

#### Redux SPA 應用實例
  * npm: react, react-dom, redux, react-router, react-redux, react-router-redux
  * 檔案目錄, src/, test/, build/
  * src/, app.js, app.css, views/, components/, containers/, layouts/, redux/, routes/, utils/, styles/
  1. 設計路由 routing
  1. 建立對應的入口 component
  1. ...
  * Redux Devtools, redux-devtools, redux-devtools-log-monitor, redux-devtools-dock-monitor


------------------------------


### 第六章 - Redux 高階運用


------------------------------


### 第七章 - React 伺服器端繪製


------------------------------


### 第八章 - 玩轉 React 視覺化


------------------------------


### 附錄 A - 開發環境


------------------------------


### 附錄 B - 程式開發標準


------------------------------


### 附錄 C - Koa middleware


434 = 58 + 108 + 62 + 30 + 62 + 44 + 16 + 26 + 20 + 4 + 4 