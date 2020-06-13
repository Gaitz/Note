## React 啟動與運行
### BOOK resource, React

------------------

第一章 - Hello World

第二章 - 元件的生命

第三章 - Excel: 精心設計的表格元件

第四章 - JSX

第五章 - 設定應用程式開發環境

第六章 - 建置應用程式

第七章 - Lint, Flow, 測試, 重複

第八章 - Flux

------------------


### 第一章 - Hello World
  * react.js
  * react-dom.js
  * `ReactDOM.render()`
  * `React.DOM.*`
  * `className`, `htmlFor`, style object, `fontFamily`
  * chrome extension, React DevTools


------------------------------


### 第二章 - 元件的生命
  * 首先關注於如何渲染該 component 之後才考慮狀態 
  * pure render function -> component with state

#### 建立與使用元件 (custom component)
  * 建立定義, `React.createClass({ render: function () {} })`, 必須有一個 `render` function
  * 創造實例 `React.createElement()`, `ReactDOM.render( React.createElement( customComponentName ), )`
  * 創造實例 `React.createFactory()`, `ReactDOM.render( React.createFactory( customComponentName )(), )`, factory 回傳一個函式

#### 元件特性 (component props)
  * `this.props`, this.props 物件是唯讀的 (read-only), 受到 Object.isFrozen 保護
  * 預先定義型別 `propTypes` (選用的), `propTypes: { propName: React.PropTypes }`, 查詢 `React.PropTypes` 裡可用的型別與特性。
  * 特性預設值設定 `getDefaultProps`, `getDefaultProps: function () { return { propName: defaultValue } }`, getDefaultProps 函式回傳一個特性預設植物件。

#### 狀態 (state) 與事件 (event)
  * 在狀態改變時，React 會批次的更新畫面。`setState()` 觸發時批次更新畫面。
  * `setState()` 時 React 做狀態的合併。
  * `this.state`, 也是唯獨的 (read-only)
  * `getInitialState: function () { return { stateName: initialValue } }`
  * 實作事件處理函式與 `this.setState()`, 傳入一個物件, 狀態值的改變。
  * React 使用類似 inline event handler 的寫法，但是細節使用 React 的事件系統 (event delegation, ...)。
  * 因此 React inline 事件變為 camel case syntax, `onChange`, ...
  * 因為使用 React 事件系統，因此跨瀏覽器相容性的問題已經從底層解決。可以安心使用 `event.target`。

#### 處理元件特性的中途改變
  * 如果預期元件特性 (component props) 可能被從外部更新，並且觸發畫面更新時，需要實作 `componentWillReceiveProps()` 處理函式
  * `componentWillReceiveProps: function (newProps) { this.setState( { oldPropName: newProps.newValue } ) }`

#### 介入元件生命週期的方法
  * React component 的複雜度演進
    1. 只是單純的 render props (pure render function)
    1. 需要處理事件 (event) 與狀態更新 (state change) 時變成具有狀態的元件 (stateful component)
    1. 介入元件生命週期 
  * `componentWillReceiveProps()`, component 的 prop 被傳入新的值時
  * `componentWillUpdate()`, component render() 呼叫前
  * `componentDidUpdate()`, component render() 呼叫後並且 DOM 改變後
  * `componentWillMount()`, component 節點被插入到 DOM 之前
  * `componentDidMount()`, component 節點被插入到 DOM 之後
  * `componentWillUnmount()`, component 節點從 DOM 移除之前
  * `shouldComponentUpdate(newProps, newState)`, 在 componentWillUpdate() 之前提供停止觸發 render() 的機會, 避免不重要的 DOM 操作。 (效能提昇關鍵)

#### React Mixins
  * 已經不推薦使用, 被其他 pattern 所取代。 


------------------------------


### 第三章 - Excel: 精心設計的表格元件
  * Excel 實作範例
  * 實作功能, 
    * 新增, 
    * 排序, 
    * 編輯, 
    * 搜尋, 
    * 儲存, 
    * 復原, 
    * 下載


------------------------------


### 第四章 - JSX
  * 把 `React.DOM.*` 與 `React.createElement()` 改為 JSX 語法
  * 需配合 Babel 使用
  * 變為類似 html element 語法 `<component attribute=''></component>`
  * 使用 JavaScript 超能力 `{ }` 
  * 註解, 
    * `{/* multiple line comments */}`
    * ```
      {
        // single line comment
      }
      ```
  * double encoding, 在 `{ }` 中使用特殊字元需要使用 Unicode 版本來避免 double encoding
  * 自動跳脫字元防止 XSS 攻擊
  * 物件展開屬性 object to attributes,
    * ```
      const attr = { href: '', target: '_blank' };
      return (<a {...attr}></a>);
      ```
  * 元件資訊傳遞, 
    * 元件參數 `{...this.props}`, 
    * 子元件 `{this.props.children}`
  * `render()` function 只能回傳單一個 component，因此多重結構需要被包裹起來。

#### JSX 與 HTML 的差異
  * class 與 for, 變為 `className`, `htmlFor`
  * style 物件，而非字串。CSS 特性名稱變為 camel case
  * 必須正確的關閉元素 `/`
  * 屬性名稱變為 camel case, 除了 `data-`, `aria-`
  * 表單裡的 value 與 `defaultValue` 屬性
  * `<select>` 裡的 selected 改為 `defaultValue` 


------------------------------


### 第五章 - 設定應用程式開發環境
  * build process

#### 檔案與目錄
  * 區分 source 與 build
  * html, css, js, jsx
  * 使用 module
  * `class` 語法的 class component, from `React.createClass({})`, to `class name extends React.Component {}`
  * 使用 Node.js 執行建置工作
    * Babel
    * React
    * React-dom
  * 配合 watch, 自動執行
  1. Babel 轉譯
  1. 打包 bundle
  1. minify, uglify
  1. deploy


------------------------------


### 第六章 - 建置應用程式
  * `this.refs` 跳脫 React 取得原始 DOM 元素

#### ES6 class component
  * `constructor (props) { super(props); this.state = {}; }` 取代 `getInitialState({})`
  * Event handler function bind 的三種方法
    * `this.method.bind(this)`
    * 箭頭函式自動綁定
    * 建構式中一次性綁定, `constructor(props){ this.method = this.method.bind(this); }`


------------------------------


### 第七章 - Lint, Flow, 測試, 重複

#### Node.js
  * package.json, 
  * node.js scripts

#### ESLint
  * 由預設標準開始，慢慢增加客製化標準。

#### Flow
  * 在編譯期檢查型別
  * 可以取代 React propTyps (執行期檢查)

#### 測試
  * React 使用 Jest 測試工具
  * Jest 基於 Jasmine 框架
  * 測試 React 需要配合 `react-addons-test-utils` 工具包, 模擬渲染, 使用者互動, ... 配合 `ReactDOM.findDOMNode()` 來取值 assert
  * Jest 預設全部 mock，需要明確指出不需要 mock 的部分。


------------------------------


### 第八章 - Flux
  * 元件溝通管理, 資料傳遞管理
  * React 做為單向資料流，有時候需要把資料傳遞很多層，會造成很多重覆的程式碼。
  * 傳遞也會讓函式簽名變得複雜並且增加測試複雜度。
  * 把資料傳遞從 React component 中分離，React component 只負責 View 層的渲染。
  * 清楚的管理與界定哪些 component 會有 side-effect (non-pure)

#### 基本想法
  * 所有資料被存在 Store 中
  * View 層即 React component，從 Store 取出資料並且 render。
  * 使用者觸發 Action ， Action 觸發 Store 的資料更新。
  * Store -> View -> Action -> Store

#### Store
  * 初始化資料 (Initialize)
  * 資料更新 (update) 使用 event subscription pattern 達成。
  * 提供資料的 getters 與 setters

#### Action
  * 提供 create, update, delete 的動作，會觸發 Store 的資料更新。
  * 提供任何會影響 Store 的動作，例如搜尋資料, 排序資料, ...

#### 加入 Dispatcher module
  * 把 Action 的權責分解成，定義動作與觸發 Store 改變。
  * 新的 Action 只負責定義動作並且呼叫 dispatcher 。
  * Dispatcher 才負責使 Store 資料更新。

#### 使用 Immutable
  * 移除所有的 side-effect，讓資料全部變成 immutable
  * 使用 Node.js 上的第三方函式庫，提供 immutable data types 與 methods。


210