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

#### React 資料流
  * 單向, 由父層到子層


------------------------------


### 第二章 - 漫談 React


------------------------------


### 第三章 - 解讀 React 原始程式


------------------------------


### 第四章 - 認識 Flux 架構模式


------------------------------


### 第五章 - 深入 Redux 應用架構


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