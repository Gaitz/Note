## React official documents - Advanced Guides and API reference

### [Website resource](https://reactjs.org/docs/accessibility.html), React

---

Advanced Guides

第一章 - Accessibility

第二章 - Code-Splitting

第三章 - Context

第四章 - Error Boundaries

第五章 - Forwarding Refs

第六章 - Fragments

第七章 - Higher-Order Components

第八章 - Integrating with Other Libraries

第九章 - JSX In Depth

第十章 - Optimizing Performance

第十一章 - Portals

第十二章 - Profiler

第十三章 - React Without ES6

第十四章 - React Without JSX

第十五章 - Reconciliation

第十六章 - Refs and the DOM

第十七章 - Render Props

第十八章 - Static Type Checking

第十九章 - Strict Mode

第二十章 - Typechecking with PropTypes

第二十一章 - Uncontrolled Components

第二十二章 - Web Components

API Reference

第一章 - React

第二章 - React.Component

第三章 - ReactDOM

第四章 - ReactDOMServer

第五章 - DOM Elements

第六章 - SyntheticEvent

第七章 - Test Utilities

第八章 - Test Renderer

第九章 - JS Environment Requirements

第十章 - Glossary

---

### 第一章 - Accessibility

- `a11y`, 網站可用性, 網站設計給任何使用者與任何操作裝置
- React 有良好的支援

Standards and Guidelines (標準與指引)

- WCAG ([Web Content Accessibility Guidelines](https://www.w3.org/WAI/standards-guidelines/wcag/)),

  - w3c 提供的指引
  - 可以使用 checklist 協助, [WCAG checklist from Wuhcag](https://www.wuhcag.com/wcag-checklist/), [WCAG checklist from WebAIM](https://webaim.org/standards/wcag/checklist), [Checklist from The A11Y Project](https://www.a11yproject.com/checklist/)

- WAI-ARIA ([Web Accessibility Initiative - Accessible Rich Internet Applications](https://www.w3.org/WAI/standards-guidelines/aria/))
  - `aria-*` HTML 屬性可以完整的在 JSX 裡使用, 使用 **hyphen-cased** 而非 JSX 常見的 camelCased, Examples `aria-required`

Semantic HTML

- 選用語意標籤是 a11y 的基礎

Accessible Forms

- Labeling, 所有的輸入表單都需要有配合的 `label` 元素並且配合 `htmlFor` JSX 屬性
  - 參考文件: [The W3C shows us how to label elements](https://www.w3.org/WAI/tutorials/forms/labels/), [WebAIM shows us how to label elements](https://webaim.org/techniques/forms/controls), [The Paciello Group explains accessible names](https://developer.paciellogroup.com/blog/2017/04/what-is-an-accessible-name/)
- Notifying the user of errors, 提供表單錯誤訊息
  - 參考文件: [The W3C demonstrates user notifications](https://www.w3.org/WAI/tutorials/forms/notifications/), [WebAIM looks at form validation](https://webaim.org/techniques/formvalidation/)

Focus Control

- 正確的管理 `focus` 是重要的 `a11y` 特性
- 確保網站可以只通過鍵盤操作 (keyboard only)
  - 參考文件: [WebAIM talks about keyboard accessibility
    ](https://webaim.org/techniques/keyboard/)
- Keyboard focus and focus outline, 使用鍵盤操作 `focus` 移動到可以輸入的 input 並且提供 `outline` 樣式
- Mechanisms to skip to desired content, 提供 Skip Navigation Links 與使用 landmark elements 協助鍵盤操作
  - 參考文件: [WebAIM - Skip Navigation Links](https://webaim.org/techniques/skipnav/), [Accessible Landmarks
    ](https://www.scottohara.me/blog/2018/03/03/landmarks.html)
- Programmatically managing focus, 由於 React 會不斷的操作 DOM 因此需要使用程式協助管理 focus 在正確的元素上
  - 在 React 中使用 `refs` 去取得正確的 DOM element 並且管理 `focus`
  - 參考範例: [react-aria-modal](https://github.com/davidtheclark/react-aria-modal)
  - 參考文件: [MDN keyboard-navigable JavaScript widgets](https://developer.mozilla.org/en-US/docs/Web/Accessibility/Keyboard-navigable_JavaScript_widgets)

Mouse and pointer events

- 確保所有使用 mouse 與 pointer 的功能也能使用 keyboard 作到
- 常見問題在於 `click` event 可以配合 `onBlur` 與 `onFocus` 得到更好的 a11y
- 重點是時常使用 keyboard 操作檢查設計

More Complex Widgets

- 複雜的功能不代表需要犧牲 `a11y` 而是應該透過 HTML 盡可能取得 `a11y`
- 例如學習 [ARIA Roles](https://www.w3.org/TR/wai-aria/#roles) 與 [ARIA States and Properties](https://www.w3.org/TR/wai-aria/#states_and_properties)
- 可以參考範例 [WAI-ARIA Authoring Practices - Design Patterns and Widgets](https://www.w3.org/TR/wai-aria-practices/#aria_ex), [Heydon Pickering - ARIA Examples](https://heydonworks.com/article/practical-aria-examples/), [Inclusive Components
  ](https://inclusive-components.design/)

Other Points for Consideration

- Setting the language, 讓螢幕閱讀器有正確的語言, 需要精準的設定 [document language](https://webaim.org/techniques/screenreader/#language)
- Setting the document title, 正確的設定 `<title>` 描述該頁面的內容
  - 參考文件 [WCAG - Understanding the Document Title Requirement](https://www.w3.org/TR/UNDERSTANDING-WCAG20/navigation-mechanisms-title.html)
  - 可以通過 hook 或者第三方的 React Document Title Component 協助改變 `<title>` 的值
- Color contract, 確保網頁中能被閱讀的內容具有良好的顏色對比
  - 參考文件 [WCAG - Understanding the Color Contrast Requirement](https://www.w3.org/TR/UNDERSTANDING-WCAG20/visual-audio-contrast-contrast.html), [Everything About Color Contrast And Why You Should Rethink It](https://www.smashingmagazine.com/2014/10/color-contrast-tips-and-tools-for-accessibility/), [A11yProject - What is Color Contrast](https://www.a11yproject.com/posts/2015-01-05-what-is-color-contrast/)
  - 可以通過第三方[工具](https://jxnblk.github.io/colorable/) `Colorable` 協助計算顏色對比
  - 可以使用的顏色對比檢查 [WebAIM - Color Contrast Checker](https://webaim.org/resources/contrastchecker/), [The Paciello Group - Color Contrast Analyzer](https://developer.paciellogroup.com/resources/contrastanalyser/)

Development and Testing Tools

- The keyboard, 最簡單與重要的測試是只使用 keyboard 操作,
  - 移除滑鼠, 只使用 `Tab` 與 `Shift+Tab` 移動, 使用 `Enter` 觸發, 特定時候使用上下左右鍵選擇
- Development assistance
  - 使用 `eslint-plugin-jsx-a11y` [plugin](https://github.com/jsx-eslint/eslint-plugin-jsx-a11y) 做自動測試, 設定 `.eslintrc` `extends: ["plugin:jsx-a11y/recommended"]` 與 `plugins: ["jsx-a11y"]`
- Testing accessibility in the browser, 在瀏覽器中做測試
  - 測試工具 [`aXe`](https://www.deque.com/axe/), [`aXe-core`](https://github.com/dequelabs/axe-core), [`react-axe`](https://github.com/dequelabs/react-axe), [`WebAIM WAVE`](https://wave.webaim.org/extension/), [The Accessibility Tree](https://www.paciellogroup.com/blog/2015/01/the-browser-accessibility-tree/), [`Accessibility Inspector in Firefox`](https://developer.mozilla.org/en-US/docs/Tools/Accessibility_inspector), [`Accessibility Inspector in Chrome`](https://developers.google.com/web/tools/chrome-devtools/accessibility/reference#pane), [`Accessibility Inspector in OS X Safari`](https://developer.apple.com/library/archive/documentation/Accessibility/Conceptual/AccessibilityMacOSX/OSXAXTestingApps.html)
- Screen readers, 使用螢幕閱讀器測試
  - [常見的瀏覽器螢幕閱讀器](https://reactjs.org/docs/accessibility.html#commonly-used-screen-readers)

---

### 第二章 - Code-Splitting

- 如果使用 Create React App, Next.js, Gatsby 等工具, 已經內建 webpack 打包工具

Code Splitting

- 當單一個 bundle 太大時造成效能問題, 因此需要 Code Splitting 拆解成多個 bundle. 並且實現 lazy-load

Dynamic `import()`

- 主動使用 dynamic `import()` 由 webpack 所支援的 module lazy load
- Create React App 與 Next.js 有內建啟動. 自行使用 Webpack 則需要參考[設定](https://webpack.js.org/guides/code-splitting/)
- 配合 Babel 使用實則需要開啟 `@babel/plugin-syntax-dynamic-import`

React.lazy

- `React.lazy` 與 Suspense 目前並不支援 SSR. SSR 的 code splitting 推薦使用第三方的 [Loadable components](https://github.com/gregberge/loadable-components), [教學文件](https://loadable-components.com/docs/server-side-rendering/)
- 使用 `React.lazy()` 配合 dynamic `import()` 自動在第一次渲染時載入相關程式碼達到 lazy load 與 code splitting
- `React.lazy()` input: 動態呼叫 import() 的函式
- 被 `React.lazy()` 所載入 component 使用時需要被 `React.Suspense` component 所包住, 並且使用 fallback function 達到 lazy load 時的預設值或預設 component.
- 使用 `Error Boundaries` 捕捉 lazy load 時產生的錯誤
- [範例程式碼](https://reactjs.org/docs/code-splitting.html#reactlazy)

Route-based code splitting

- 決定如何分割 bundle 希望分割的比較平均並且不影響使用者體驗
- code splitting 的理想起點是配合 route 做 lazy load, 因為在切換 route 時, 通常代表頁面的切換, 因此使用者有可預期的等待空間.
- 參考使用 React.lazy 與 React Router 的[程式碼範例](https://reactjs.org/docs/code-splitting.html#route-based-code-splitting)

Named Exports

- `React.lazy()` 目前只支援讀取 default export 的 component
- 如果想要 lazy load 的 component 是 named export 時需要做中間處理, 轉換成 default export.
- [參考範例](https://reactjs.org/docs/code-splitting.html#named-exports)

---

### 第三章 - Context

- Context 提供一個跨層 component 傳遞資料的方式
- React 傳統上使用一層一層的父層傳遞給子層的單向資料流達成 component 資料傳遞.

When to Use Context

- Context 被設計用來傳遞被視為 global 的資料, 例如權限狀態, 使用者偏好設定

Before You Use Context

- 小心使用 Context 因為會造成副作用導致降低重用性, 不要僅僅因為傳遞資料太麻煩而選用.
- 傳遞資訊的方法可以參考 [Composition vs Inheritance](https://reactjs.org/docs/composition-vs-inheritance.html)

#### API

`React.createContext()`

- Input: 預設值, 只有在使用時找不到 Provider 才會提供.
- Output: Context object

`Context.Provider`

- Context 物件中的 Provider component, `<CustomContext.Provider value={}>`
- Input: `value`, 傳遞給 consumers 的值
- 所有 consumers 在 Provider 的 `value` 變化時都會觸發 re-render, 並且不受 `shouldComponentUpdate` 影響
- `value` 的比較函式是 `Object.is`

`Class.contextType`

- Consumer class component 使用 `Class.contextType` 指定註冊 context, 在 consumer class 內部可以使用 `this.context` 取得

`Context.Consumer`

- Consumer function component 使用 `<Context.Consumer>{() => {}}</Context.Consumer>` 註冊 context 並且取用

`Context.displayName`

- 創造出來的 Context 可以指定 displayName 字串, 協助 React DevTool 除錯時使用

#### Examples

- Dynamic Context, 基本用法 (class), `React.createContext()`, `Class.contextType`, `Context.Provider`
- Updating Context from a Nested Component, 基本用法 (function), `React.createContext()`, `Context.Consumer`, `Context.Provider`
- Consuming Multiple Contexts, 使用多組 Context

#### Caveats

- 由於 context 會依據 reference 去處發 re-render, 因此有很多陷阱會造成不必要的 renders
- `Provider` 的 value 要小心不要每次都是創建新的 Object

---

### 第四章 - Error Boundaries

- React 16 之後提供的錯誤處理功能, `Error Boundary`
- 是一種 React component 用來捕捉子代的 JavaScript Error, 避免造成整個 React App 崩潰
- Error Boundary 不可以處理的例外
  - 事件處理 Event handlers
  - 非同步程式碼 Asynchronous code
  - 伺服器端渲染 SSR
  - 由 Error Boundary component 自己丟出的錯誤

Class component

- 通過 `static getDerivedStateFromError()` 處理錯誤並且觸發渲染 fallback UI
- 通過 `componentDidCatch()` 產生 log 並且印出錯誤訊息
- 利用自建的 Error Boundary component 包裹一般的 component
- 使用概念類似於 JavaScript 的 `catch()`

Where to Place Error Boundaries

- 放置 Error Boundary 的位置可以自行決定, 依據想要處理的錯誤粒度

New Behavior for Uncaught Errors

- React 16 增加的 Error Boundary 帶來更好的使用者體驗
- 並且更容易捕捉錯誤並且修正

Component Stack Traces

- React DevTool 會在 console 中印出錯誤發生時的 component tree 協助除錯與放置 Error Boundary
- 如果使用 Create React App 會附加印出錯誤的檔案與行數
- 或者通過 [Babel Plugin](https://www.npmjs.com/package/@babel/plugin-transform-react-jsx-source) 在 development 環境開啟

How About try/catch?

- try/catch 只適合使用在執行命令式的情況 (imperative)
- React 的概念是宣告式的, 因此使用宣告式的 Error Boundary 更為適合

How About Event Handlers?

- Error Boundary 捕捉不到在 event handler 裡產生的錯誤
- 因為 event handler 發生時機不會在 React render method 或 lifecycle methods 裡, 因此 React component 本身仍舊能使用 `try/catch` 捕捉的到
- Event handler 對於 React 來說就是一般的 function 可以在 function 內部使用 JavaScript 的 `try/catch` 處理錯誤

---

### 第五章 - Forwarding Refs

- 一種技術用於自動傳遞 `ref` 到子代 component, 大多數應用程式不需要用到此功能, 多使用於函式庫

Forwarding refs to DOM components

- React component 包裹實際的 DOM element 多數時不用通過 `ref` 從外部操作 component 內部的 DOM element, 提昇封裝與去耦合
- 通過內建的 `Ref Forwarding` 機制, 可以在外部使用 `React.createRef()` 與內部建立 `React.forwardRef()` 實現取得 `ref` 來操作底層的 DOM element
- forwarding 代表向子代傳遞
- 要使用 `ref forwarding` 必須配合 `React.forwardRef()` 定義才有效
- 範例與建立步驟[參考](https://reactjs.org/docs/forwarding-refs.html#forwarding-refs-to-dom-components)

Note for component library maintainers

- library 啟用 `forwardRef` 應該視為破壞性更新, 因為會改變程式行為.

Forwarding refs in higher-order components

- Forwarding refs 在配合 HOC 使用時, `ref` 並不會像 props 一樣被傳遞
- `ref` 與 `key` 類似是 props 外的屬性, 由 React 另外控管
- 需要在 HOC 裡明確的使用 `React.forwardRef` 傳遞 `ref` 才能正常運作,
- [參考範例](https://reactjs.org/docs/forwarding-refs.html#forwarding-refs-in-higher-order-components)

Displaying a custom name in DevTools

- `React.forwardRef()` input: 一個 render function, 如果使用命名函式定義, 則名稱會出現在 DevTools 裡.

---

### 第六章 - Fragments

- 在不生成額外的 DOM element 的情況下打包一組 element
- `<React.Fragment></React.Fragment>` or `<></>` for short syntax

Motivation

- 因為 React component 只能回傳一個 render element, 因此在分割 component 的時候無論如何都必須包裹成一個 element, 可能會因此在 DOM 上產生不必要的 element.
- 以上問題可以藉由 React Fragment 解決

Keyed Fragments

- `<React.Fragment key={}></React.Fragment>`, 目前唯一允許的屬性是 `key`

---

### 第七章 - Higher-Order Components

- React component 進階用法,
- Higher-order component 是一個 function
  - Input: 一個 component
  - Output: 一個新的 component
- 在第三方函式庫時常使用

Use HOCs for Cross-Cutting Concerns

- 舊時 React 使用 Mixin 來切割功能, 但是有很多壞處已經被棄用
- 為了從 component 中抽出常用的邏輯, 可以使用 HOC 的方式把共用邏輯寫在 HOC 裡來分離關注點.
- HOC 是 pure function, 使用 compose 來實現重用

Don't Mutate the Original Component. Use Composition.

- 不要試圖改變傳入的 component, HOC 應該要是 pure function
- 有 side-effect 會破壞封裝, 讓使用者必須了解副作用後才能安全的使用
- Higher-order component 與 container component pattern, 在解決相同的問題.

Convention: Pass Unrelated Props Through to the Wrapped Component

- HOC 不應該改變傳入 component 的 interface, 必須讓他保有原本的功能.
- 因此在 HOC 沒有使用到的 `props` 也要依舊傳遞給新生成的 component 繼續帶給下層 component.
- 確保 `props` 在通過 HOC function 時不會漏掉

Convention: Maximizing Composability

- 善用大量的函式組合 (function composition)
- 以 Relay 和 React-Redux function 為例
- 可使用第三方提供的 `compose` 來協助實現 functional programming 最重要的函式組合功能, 例如 `Redux`, `Ramda` 都有提供這個函式。

Convention: Wrap the Display Name for Easy Debugging

- 盡可能的提供有意義的名稱給 React Developer Tools 可以協助除錯

#### Caveats

Don't Use HOCs Inside the render Method

- React 核心通過 diff 演算法比較 `render()` 回傳的結果來判斷，要如何改變 DOM
- 如果在 `render()` 裡呼叫 HOCs 會導致每次都會重新 unmount 與 mount, 導致效能問題並且影響整個 subtree
- 因此要注意 HOCs 所呼叫的位置, 讓 component 只建立一次並且在每次 render 時保持一致性.

Static Methods Must Be Copied Over

- 由於 static methods 是跟著定義的 class, 因此使用 HOCs 時, 回傳的 component 會無法使用原本的 static methods.
- 所以必須明確的在 HOCs 中複製 static methods 到新的 component 上。
- 可以使用第三方的 [hoist-non-react-statics](https://github.com/mridgway/hoist-non-react-statics) 協助複製 static methods
- 或者不把 static method 綁定在 class 上, 而是直接 export function

Refs Aren't Passed Through

- 與 Static Methods 類似的問題也會發生在 `ref` 上
- 解決方案要參考 `React.forwardRef` API 文件

---

### 第八章 - Integrating with Other Libraries

Integrating with DOM Manipulation Plugins

- 當有其他函式庫調整 DOM 時會導致 React 無法變識
- 常見的作法是建立 React 永遠不需要更新的 DOM element 然後再操作. 例如 `<div />` 空的 `div` element

How to Approach the Problem

- 建立一個獨立的 element 並且配合 `ref` 傳遞 DOM element 給第三方的 library
- 以 [jQuery 為例](https://reactjs.org/docs/integrating-with-other-libraries.html#how-to-approach-the-problem)
- 需要注意 component unmount 時的 cleanup, 避免 event listener 產生的 memory leak

Integrating with jQuery Chosen Plugin

- React 仍舊推薦盡可能的使用 React component 去實現功能, 對於 React application 會有更好的整合與重用性
- 在配合第三方函式庫的時候, 必須注意要讓 React 無法去處碰到被第三方函式庫所操作的 DOM
- 讓 React component 與第三方函式庫有 listener 的雙向綁定
- 參考 `Chosen` [範例](https://reactjs.org/docs/integrating-with-other-libraries.html#integrating-with-jquery-chosen-plugin)

Integrating with Other View Libraries

- 藉由靈活的 `ReactDOM.render()` 可以很容易的把 React 整合在其他頁面中, `ReactDOM.render()` 甚至可以呼叫多次, 生成多個 React piece.
- 很容易與 server-side rendered 頁面互動
- 更靈活的去思考 React 與網頁應用程式的實作

Replacing String-Based Rendering with React

- 移植 jQuery 類型的網頁應用程式到 React component
- 一次移植一點到 React component, 建立多個 React piece 之後在整合成大的 React piece

Embedding React in a Backbone View

- 移植 Backbone View 實作到 React component

Integrating with Model Layers

- 推薦使用單向流的狀態管理, 例如 React state, Flux, Redux,
- 在 React component 中註冊外部的 value onChange 並且手動觸發 re-render
- 讓資料集中管理, React 通過 HOC 或 Hook 去連結外部資料

---

### 第九章 - JSX In Depth

- JSX 就是 `React.createElement(component, prpos, ...children)` 的語法糖.
- JSX syntax 通過 babel 編譯成 `React.createElement()`

React Must Be in Scope

- 為了要讓 JSX 編譯成 `React.createElement`, React library 必須能被引用得到, 不管是 bundle import 或者 global

Using Dot Notation for JSX Type

- JSX element 是一個單純的 function, 因此可以被包含在 object 裡作為 function member, 所以可以使用 `Class.Method` 作為 React component 呼叫

User-Defined Components Must Be Capitalized

- 使用小寫開頭的 element 會被 JSX 視為內建的 HTML element 而傳遞給 `React.createElement()`
- 使用大寫開頭的 element 會被視為客製化的 element, 並且在傳遞給 `React.createElement()` 時會 import 定義的 JavaScript
- 因此客製化的 element 必須使用大寫開頭作為 element 的命名

Choosing the Type at Runtime

- 動態建立 element Type, 無法直接把表達式寫在 JSX 括號中
- 可以把表達式令存為大寫開頭的變數, 就可以使用動態變數選擇 element Type
- [範例參考](https://reactjs.org/docs/jsx-in-depth.html#choosing-the-type-at-runtime)

#### Props in JSX

JavaScript Expressions as Props

- 可以使用 JavaScript 表達視作為 Props, 使用 `{}` 包裹
- if/else 與 loops 可以作為 function 的內部使用並且回傳 JSX element 即可. (Everything is JavaScript)

String Literals

- 字串作為 Props, 使用 `""` 或 `{""}` 都可以

Props Default to "True"

- 當 Props 只有名稱沒有給值時, 預設是 `{true}`
- JSX 不推薦不給值, 預設是 `true` 只是為了與原生的 HTML 行為一致

Spread Attributes

- 使用 object 儲存 props 時可以直接使用 ES6 的 spread operator `...` 展開賦值, `<CustomElement {...propObject} />`
- 配合 ES6 spread operator, 可以方便的塞選父層傳來的 props 並且傳遞不需處理的部份.
- [參考範例](https://reactjs.org/docs/jsx-in-depth.html#spread-attributes)

#### Children in JSX

- 特殊的 `props.children` 用來傳遞 children

String Literals

- 字串作為 JSX element 的 children
- JSX 中的字串不需要做 HTML 跳脫字元, 會自動轉義
- 如同 HTML 一般 JSX 會自動移除換行與開頭結尾的空白

JSX Children

- 其他的 JSX element 作為 children

JavaScript Expressions as Children

- 使用 `{}` 包裹 JavaScript 表達式作為 children
- 可以善用 JavaScript 的能力, 動態的產生不同的 children

Functions as Children

- 傳入 function 作為 children
- 即使用 `props.children` 傳遞函式
- 使用情況不多, 不過也代表了 JSX 可以最大限度的使用 JavaScript 達成各種不同的應用
- [參考範例](https://reactjs.org/docs/jsx-in-depth.html#functions-as-children)

Booleans, Null, and Undefined Are Ignored

- 如果 children 傳入 `{false}`, `{null}`, `{undefined}`, `{true}` element 都會被視為不渲染
- 非常適合在條件渲染時使用, 可以配合 `&&` 達成條件渲染
- 小心有些 JavaScript 的 `falsy` values, 也會被渲染, 例如 `0`

---

### 第十章 - Optimizing Performance

- 雖然 React 已經有針對 DOM 操作做優化, 仍然有些方式可以進一步提昇 React Application 的效能

#### Use the Production Build

- 在做效能調校時, 確定測試的是 minified 過的 production build
- React 在開發者環境 (development) 會有很多協助開發的功能, 相對的會讓程式變大與變慢, 需要正確的區分 production 與 development build
- 通過 React Developer Tools Chrome extension 可以協助判斷目前使用的 React 環境

Create React App

- 使用 Create React App 時, `npm run build` 會產生 production 版本, `npm start` 會產生 development 版本

Single-File Builds

- 使用 `.production.min.js` 版本的 React 與 ReactDOM CDN

Brunch

- 使用 Brunch 建置時
- 使用 [terser-brunch](https://github.com/brunch/terser-brunch) plugin 協助建立 production build

Browserify

- 使用 Browserify 建置時
- 依序使用 `envify`, `uglifyify`, `terser` plugins 協助產生 production build, 順序是重要的

Rollup

- 使用 Rollup 建置時
- 依序使用 `rollup-plugin-replace`, `rollup-plugin-commonjs`, `rollup-plugin-terser` plugins 協助產生 production build, 順序是重要的
- 詳細設定可以參考[文件](https://reactjs.org/docs/optimizing-performance.html#rollup)

Webpack

- 使用 Webpack 建置時
- 使用 Create React App 已經設置只需要使用正確的指令即可
- 自行設定 webpack 則需要使用 `optimization` 設定 `TerserPlugin`, 詳細設置參考[文件](https://webpack.js.org/guides/production/)

#### Profiling Components

Profiling Components with the Chrome Performance Tab

- 使用 Chrome DevTools 的 Performance 功能協助效能調校
  - 使用步驟參考[文件](https://reactjs.org/docs/optimizing-performance.html#profiling-components-with-the-chrome-performance-tab)
- 偵測是否有不必要的 component mount, update, unmount 行為

Profiling Components with the DevTools Profiler

- 使用 React DevTool 裡的 Profiler 協助效能調校
- 參考[文件](https://reactjs.org/blog/2018/09/10/introducing-the-react-profiler.html)與[影片](https://www.youtube.com/watch?v=nySib7ipZdk)

#### Virtualize Long Lists

- 大量資料載入時, 可以配合 lazy load 提昇效能
- 可以使用函式庫 [react-window](https://react-window.now.sh/#/examples/list/fixed-size) 或 [react-virtualized](https://bvaughn.github.io/react-virtualized/#/components/List)
- 參考 Twitter 針對 React 頁面做的性能調校[文章](https://medium.com/@paularmstrong/twitter-lite-and-high-performance-react-progressive-web-apps-at-scale-d28a00e780a3)

#### Avoid Reconciliation

- 通過 `shouldComponentUpdate(nextProps, nextState)` 避免特定情況的 re-render 以提昇效能
- 使用 React Hooks 時可以參考[文件](https://reactjs.org/docs/hooks-faq.html#performance-optimizations)使用 `useCallback` 與 `useMemo` 實現類似的效能優化
- 使用 `React.PureComponent` 等同於在 `shouldComponentUpdate()` 做 shallow comparison
- [shouldComponentUpdate In Action](https://reactjs.org/docs/optimizing-performance.html#shouldcomponentupdate-in-action)

Examples

- [範例](https://reactjs.org/docs/optimizing-performance.html#examples)
- 在 `shouldComponentUpdate()` 只是單純的使用 shallow comparison 可以利用 `extends React.PureComponent` 協助自動實現
- 如果需要比較的是更複雜的資料結構, 例如 object, array 時要小心 PureComponent 的 shallow comparison 可能帶來錯誤的結果, 因為使用 mutating 資料結構時 reference 沒有改變, 會導致 shallow comparison 永遠都是 true 而不會正確的 re-render.

The Power Of Not Mutating Data

- 使用 shallow comparison 提昇效能時, 改變 props 或 states 值時, 必須使用 immutable data, 使用複製取代 mutating.
- 使用 ES6 spread operator `...` 可以協助快速複製 array 與 object
- 或者使用 `Object.assign()` 實現 object 複製與賦值
- 或者使用第三方函式庫 [Immer](https://github.com/immerjs/immer), [immutability-helper](https://github.com/kolodny/immutability-helper) 協助實現 immutable 操作

---

### 第十一章 - Portals

- `ReactDOM.createPortal(child, container)`

Usage

- 直接放置 props.children 到指定的 DOM 位置
- 通常使用時機在於包裹的 element 擁有不必要的 `overflow: hidden` 或者 `z-index` 可以避開父層元素
- 需要特別注意 keyboard focus 是否正確

Event Bubbling Through Portals

- React Event 運作仍舊是依據 Virtual DOM 上的 React tree 而非實際的 DOM tree
- 因此使用 Portals 時實際的 DOM tree 會沒有預期的 element 導致無法正確的捕捉到 event 發生
- 解決方式參考[文件範例](https://reactjs.org/docs/portals.html#event-bubbling-through-portals)

---

### 第十二章 - Profiler

- 通過 Profiler API 協助觀察 React 應用程式 render 時的效能消耗, 找到瓶頸可以使用 memoization 做效能最佳化
- Profiler 不應該在 production build 中使用

Usage

- `<Profiler id={string} onRender={function}></Profiler>`
- 可以任意放置單個或多個在 React Tree 裡, input: id 與 onRender callback function

`onRender` Callback

- 通過 onRender callback function 會傳入些有用的值協助偵測效能瓶頸
  - `(id, phase, actualDuration, baseDuration, startTime, commitTime, interactions) => {}`
  - `id`: 字串, Profiler 的名稱
  - `phase`: mount 或 update 字串, 協助知道階段
  - `actualDuration`: 數字, 子代更新所花的時間, 也代表如果使用 memorization (`React.memo`, `useMemo`, `shouldComponentUpdate`) 可以提昇的時間
  - `baseDuration`, 數字, 渲染時所花的時間, 也代表 worst-case, 通常是指 initial mount 時所花的時間
  - `startTime`, 數字, 開始時間戳
  - `commitTime`, 數字, commit 更新的時間戳
  - `interactions`, 集合, 透過 interactions 可以追蹤 update 的原因, 參考[文章](https://gist.github.com/bvaughn/8de925562903afd2e7a12554adcdda16),

---

### 第十三章 - React Without ES6

- 通常使用 `class` 語法協助定義 React component
- 不使用 ES6 時, 可以使用 `createReactClass()` 取代, 但是有些許不同.

Declaring Default Props

- `class` 時使用 `.defaultProps = {}` 協助定義
- `createReactClass()` 時使用 `getDefaultProps: function () {}` 協助定義

Setting the Initial State

- `class` 時使用 `constructor(props) { this.state = {} }` 協助定義
- `createReactClass()` 時使用 `getInitialState: function () {}` 協助定義

Autobinding

- `class` 時需注意 method `this` binding 問題
- `createReactClass()` 時不需要特別 binding `this`
- 在 `class` 的 `constructor` 階段一次性綁定好 `this` 在大型應用程式中可以提昇些許效能
- `class` 時的 `this` 多種解決方案可以參考[文件](https://reactjs.org/docs/react-without-es6.html#autobinding)

---

### 第十四章 - React Without JSX

- 使用 JSX 是建立 React component 最方便的方式
- 然而 JSX 只是語法糖, 仍然可以手動撰寫 `React.createElement(component, props, ...children)` 取代 JSX 編譯

---

### 第十五章 - Reconciliation

- React 設計 diffing 演算法與控制 UI 更新的設計決策

Motivation

- `render()` 會產生一個 React element 的 tree, 在 state 或 props 更新時 `render()` 會在產生另一個 React element tree, 在相互比較後才決定用最有效率的方式更新實際的 UI
- 樹狀結構的轉換 tree transformation, 在一般的狀態需要 `O(n^3)` 的複雜度 (太慢了)
- 在 2 個前提之下 React 把複雜度降到 `O(n)` 足夠使用的程度
  - 不同 type 的 element 即產生不同的 tree
  - 讓使用者通過設置 `key` 作為提示子代可是不需要改變的
- 在實務上, 對於 DOM tree 的變化, 上面兩個假設是合理的。

The Diffing Algorithm

- 首先比較 root 的 type

Elements of Different Types

- 如果 root 的型別 (type) 不同, React 會直接放棄舊的 tree 建立新的 tree (rebuild), 不管是 HTML 原生的 element 或者是 custom 的 React element 都是如此
- 移除舊的 DOM tree 並且觸發所有相關的 `componentWillUnmount()` 並且移除所有舊的 state
- 建立新的 DOM tree 並且依序觸發 `componentWillMount()` 與 `componentDidMount()`

DOM Elements of The Same Type

- 當型別 (type) 一樣時, 會比較 element attributes, 保持一樣的 DOM node 然後更新有差異的 attribute.
- 之後 React 會遞迴的往子代比較

Component Elements of The Same Type

- 在型別 (type) 一樣的客製化 component 更新時, 會依序觸發 `componentWillReceiveProps()` 與 `componentWillUpdate`, 然後才觸發 `render()`
- 之後 React diff 演算法會遞迴的像子代執行

Recursing On Children

- DOM node 的子代預設是依序比較並且更新差異 (mutate), 因此如果是插入元素在最前頭, 會產生 worst-case.
- 為了解決這個問題, 使用者必須提供 `key` 來優化更新流程

Keys

- 提供 `key` attribute 讓 React diff 演算法通過比較 `key` 來判斷更新
- `key` 值不需要是全域唯一 (globally unique), 只要能區別相連的元素即可.
- 由於 `key` 是作為 React diff 演算法更新的依據, 因此如果使用 index 作為 `key` 時, 在很多操作例如 Reorder 時, 會產生不好的效能或者不預期的行為.
- 因此盡量不要使用 index 作為 `key` 值

Tradeoffs

- React Diff 演算法, 目標是在一般情況下能取得最快的效能.
- 因此在不符合兩個前提的情況下, 效能可能會受影響
  - 在切換 type 時會導致子代全部 re-render
  - Key 應該要是穩定且獨特的, 不適當的 key 會導致不必要的 recreated 會造成效能問題並且所有子代的 state 會因此而遺失.

---

### 第十六章 - Refs and the DOM

- `Ref` 是 React 提供取得實際 DOM node 的方式
- 一般的 React dataflow 中, 父層 component 只會使用 `props` 與子代 component 互動

When to Use Refs

- 常見的使用案例
  - 管理 focus 狀態, text selection,
  - 觸發命令式的 animation
  - 整合其他第三方 DOM library
- 在能使用宣告式的 React component 時就不要使用 `ref`

Don't Overuse Refs

- 避免濫用 `ref` 在使用之前應該先思考 state 最適合的存放位置

Creating Refs

- 使用 `React.createRef()` 建立並且透過 `ref` attribute 傳遞給子代.
- [範例](https://reactjs.org/docs/refs-and-the-dom.html#creating-refs)

Accessing Refs

- 當在 `render()` 階段時, `ref` 變數可以通過 `current` attribute 取值
- [範例](https://reactjs.org/docs/refs-and-the-dom.html#accessing-refs)
- 依據型別 (type) 的不同, `ref` 的值也會不同
  - 如果 `ref` 被連接在 HTML element 上, 則會取得 DOM element.
  - 如果 `ref` 被連接在 custom class component 上, 則會取得該 component 的 mount 實體
  - `ref` 不應該被用在 function component 上, 因為沒有 instance

Adding a Ref to a DOM Element

- [參考範例](https://reactjs.org/docs/refs-and-the-dom.html#adding-a-ref-to-a-dom-element)

Adding a Ref to a Class Component

- [參考範例](https://reactjs.org/docs/refs-and-the-dom.html#adding-a-ref-to-a-class-component)

Refs and Function Components

- 一般情況不能把 `ref` attribute 加在 function component 上
- 但是可以使用 `forwardRef()` 與 `useRef()` 達到類似的功能

Exposing DOM Refs to Parent Components

- 在少數的情況下父層希望能取得子代的 DOM node
  - 使用案例: focus 管理, size 偵測
- 這是不推薦的模式, 因為會破壞 React component 的封裝, 讓狀態改變不可預期.
- `Ref` 使用在 custom component 時, 最好使用 `ref forwarding` 技術手動綁定 `ref`
- 最差的情況還有 React `findDOMNode()` 可以使用, 但是這個作法在 `StrictMode` 下不被允許.

Callback Refs

- 不使用 `React.createRef()` 而是在 `ref` attribute 傳遞一個 callback function, 讓 React 在適當的時機呼叫.
- 注意事項: 如果 `ref` 傳遞的 callback function 使用 inline function 的形式, 在更新時會被呼叫兩次, 可以使用 class 預先定義 method 的方式傳遞.

---

### 第十七章 - Render Props

- `render prop` 是一個共用程式邏輯的技巧, 在 prop 中傳遞 render function
- Component 傳遞 `render` attribute 是一個回傳 React element 的 function, 取代實際實作的 `render()`

Use Render Props for Cross-Cutting Concerns

- Component 作為 React 裡主要的元件, 有時候要共用邏輯並不適合單純的使用 component 組合.
- 單純使用 component 共用邏輯時, 會需要因應不同需求一直建立新的 component
- 因此讓 `render()` 不必寫死, 而是由外部傳入 (`this.props.render(this.state)`), 只利用該 component 中的其他邏輯與 state.
-
- Render Props 與 Higher-order component (HOC) 解決類似的問題, 並且可以交互使用.
- [參考範例](https://reactjs.org/docs/render-props.html#use-render-props-for-cross-cutting-concerns)

Using Props Other Than render

- `render props` 這個技術不一定要透過 `render` attribute, 任何的 props 傳遞 function 都可以達成.
- 甚至可以使用隱性的 `props.children` 直接傳遞 function 在 children 的位置.

Caveats: Be careful when using Render Props with React.PureComponent

- 由於 `React.PureComponent` 使用 props 做 shallow comparison, 因此如果 `render props` 使用 inline function 定義時永遠都會是 `false` 即每次都會更新 component.
- 解決方式: render function 不使用 inline function 定義, 或不使用 `React.PureComponent`

---

### 第十八章 - Static Type Checking

- Static type checking, 可以協助編譯期除錯, 和 auto-completion 自動補完功能.
- 在大型專案中推薦使用 `Flow` 或 `TypeScript` 取代 React 內建的 `PropTypes` 功能

#### Flow

- 由 Facebook 開發的 JavaScript static type checker
- [Flow Document](https://flow.org/en/docs/getting-started/)

Adding Flow to a Project

- 使用 `Yarn` 或 `npm` 加入 dev dependency, `flow-bin`
- 使用 `flow` script 執行
- flow 初始化執行 `init`

Stripping Flow Syntax from the Compiled Code

- 在 production build 中移除 flow 語法
- Create React App, 已經內建正確的 production build.
- Babel, 手動設置 babel 時, 需要配合 `@babel/preset-flow` 並且在 `babelrc` 中的 `presents` 加入 `@babel/preset-flow`
- 其他編譯工具可以通過第三方工具 [`flow-remove-types`](https://github.com/facebookarchive/flow-remove-types) 協助去除

Running Flow

- 通過 `npm run flow` 或 `yarn flow` 執行 Flow 檢查

Adding Flow Type Annotations

- Flow 預設只會檢查包含 `// @flow` 的 JavaScript 檔案
- 可以通過 option 設置檢查所有的檔案

Documents

- Flow documents [Type Annotations](https://flow.org/en/docs/types/), [Editors](https://flow.org/en/docs/editors/), [React](https://flow.org/en/docs/react/)
- [Linting in Flow](https://medium.com/flow-type/linting-in-flow-7709d7a7e969)

#### TypeScript

- Microsoft 所開發的程式語言, 是 JavaScript 的超集合, 擁有自己的 compiler
- 在 React 使用 TypeScript 參考[文件](https://github.com/Microsoft/TypeScript-React-Starter#typescript-react-starter)

Using TypeScript with Create React App

- 使用 `npx create-react-app --template typescript`
- 或參考[文件設置](https://create-react-app.dev/docs/adding-typescript/)

Adding TypeScript to a Project

- 手動設定 TypeScript 通過 `Yarn` 或 `npm` 增加 dev dependency `typescript`
- 取得使用 `tsc` typescript compiler 的指令

Configuring the TypeScript Compiler

- 設定 `tsconfig.json`
- 初始化 TypeScript 使用 `tsc --init` 指令
- 參考 option [文件](https://www.typescriptlang.org/docs/handbook/tsconfig-json.html)設置其他選項
- 設置入口與編譯後的資料夾 `rootDir`, `outDir`
- 把 build 後的檔案加入 `.gitignore` 中

File extensions

- `.ts` 作為 TypeScript 預設的副檔名
- `.tsx` 作為使用 TypeScript + JSX 時的副檔名

Running TypeScript

- 執行 `yarn build` 或 `npm run build`

Type Definitions

- 加入定義檔 (declaration file)
- Bundled, 有些函式庫已經包含了定義檔方便直接使用, 可以通過查看 `index.d.ts` 或 `package.json` 下的 `typings/types` 欄位
- [DefinitelyTyped](https://github.com/DefinitelyTyped/DefinitelyTyped), 查詢由 Microsoft 所管理的 type repository, 直接安裝相關的 `@types/`
- Local Declarations, 通過建立 `declarations.d.ts` 手動設定定義檔

Documents

- TypeScript Documents, [Basic Types](https://www.typescriptlang.org/docs/handbook/basic-types.html), [Migrating from JavaScript](https://www.typescriptlang.org/docs/handbook/migrating-from-javascript.html), [React and Webpack](https://webpack.js.org/guides/typescript/)

#### Others

Reason

- 新的語法, 以類似 `OCaml` 的語法, 由 Facebook 所開發

Kotlin

- 由 JetBrains 所開發的強形別語言, 可以編譯成 JVM, Android, LLVM, JavaScript

Other Languages

- 也有其他型別語言可以編譯成 JavaScript 使用

---

### 第十九章 - Strict Mode

- 概念類似 JavaScript 的 `"use strict"`, 使用一個不影響 UI 的 element, `<React.StrictMode></React.StrictMode>`, 協助抓出潛在錯誤, 並且不影響 production build.
- `StrictMode` element 可以插入在任何地方, 只會協助抓出子代的錯誤.
- 目前支援抓出
  - 使用不安全的 lifecycle function
  - 使用過時的 string ref 功能
  - 使用過時的 findDOMNode 功能
  - 偵測不預期的 side effects
  - 偵測使用過時的 context API

Identifying unsafe lifecycles

- 有些舊的 lifecycle function 對於非同步的 React 應用程式會有錯誤
- [參考文章](https://reactjs.org/blog/2018/03/27/update-on-async-rendering.html)

Warning about legacy string ref API usage

- 舊的 ref 有兩種使用方式 string ref 與 ref callback function
- string ref 有很多不好的地方, [參考文件](https://github.com/facebook/react/issues/1373)

Warning about deprecated findDOMNode usage

- `findDOMNode` 不好用且有害, 相同的問題使用 `ref` 相關解法更好

Detecting unexpected side effects

- 原則上來說, React 的工作分成兩個階段, render (呼叫生成 React DOM 與 diffing) 與 commit (實際更新 DOM, 與 `componentDidMount`, `componentDidUpdate`)
- commit 階段通常很快, 但是 render 階段有可能很慢
- 未來的 `concurrent` mode 希望解決 render 階段可能很慢的問題
- Render 階段包含了呼叫以下的函式
  - `constructor`,
  - `componentWillMount`
  - `componentWillReceiveProps`
  - `componentWillUpdate`
  - `getDerivedStateFromProps`
  - `shouldComponentUpdate`
  - `render`
  - `setState`
- 由於 render 階段的函式有可能被呼叫數次, 因此要確保這些函式沒有 side-effect 否則會造成不可預期的問題 (包含 memory leak, 不正確的 state 等等)
- StrictMode 沒有辦法直接偵測是否有不可預期的 side effects, 所以是利用在 development 時直接呼叫兩次以上的函式, 希望能提早觸發問題發生.

Detecting legacy context API

- 舊的 context API 容易產生問題, 並且會在未來的版本淘汰, 因此會偵測是否使用

---

### 第二十章 - Typechecking with PropTypes

- `React.PropTypes` 已經從核心函式庫移出, 移到 `prop-types` [函式庫](https://www.npmjs.com/package/prop-types)
- 當應用程式越來越複雜時, static type checking 機制可以協助提早抓出很多問題.
- 常用的 static type checking 機制, `Flow`, `TypeScript`, React 內建的 `PropTypes`
- proTypes 檢查機制只會在 development 階段檢測

PropTypes

- 參考[文件](https://reactjs.org/docs/typechecking-with-proptypes.html#proptypes)定義型別

Requiring Single Child

- 指定必須含有單一個 children 欄位
- [參考範例](https://reactjs.org/docs/typechecking-with-proptypes.html#requiring-single-child)

Default Prop Values

- 使用 `defaultProps` 定義 component 預設的 props 值
- 實現語法參考[範例](https://reactjs.org/docs/typechecking-with-proptypes.html#default-prop-values)

---

### 第二十一章 - Uncontrolled Components

- 在多數的情況下, 推薦使用 controlled components 去管理 form, 即 React 會管理 form data
- Uncontrohttps://goshakkk.name/controlled-vs-uncontrolled-inputs-react/以參考[文件](https://goshakkk.name/controlled-vs-uncontrolled-inputs-react/)

Default Values

- 針對 uncontrolled component 的預設值, 可以使用 `defaultValue` attribute 讓 React 協助提供.
- 參考[範例](https://reactjs.org/docs/uncontrolled-components.html#default-values)

The file input Tag

- `<input type="file">` 通過 `File API` 讓使用者上傳單個或多個檔案至瀏覽器
- 在 React 中 file input 一定是 uncontrolled component, 因此需要自行通過 `ref` 和 File API 去處理
- 參考[範例](https://reactjs.org/docs/uncontrolled-components.html#the-file-input-tag)

---

### 第二十二章 - Web Components

- React 與 Web Components 標準, 試圖解決不同的問題.
- Web Components 提供封裝並且重用 component.
- React 提供宣告式的函式庫協助處理 DOM 與資料
- 兩者是互補的, 因此可以同時使用

Using Web Components in React

- 在 React component 中使用 Web Component element
- 需要自行管理 Web Component 產生的 DOM, 並且連接 React component

Using React in your Web Components

- 自行定義的 HTMLElement 即 Web Components, 內部也可以呼叫 `ReactDOM.render()` 來連接 React component

---

### 第一章 - React

- 整個 React 函式庫的 entry point

#### Overview

Components

- 分割 UI 成獨立可重用的獨立區塊
- 可以繼承 (extends) `React.Component` 或 `React.PureComponent` 創建
- 或者使用 `create-react-class()` 函式建立
- React component 也可以使用 `React.memo` 函式建立

Creating React Elements

- 推薦使用 JSX 語法糖取代 `React.createElement()` 的呼叫
- 不使用 JSX 時使用 `React.createElement()`, `React.createFactory()` 函式建立 React element

Transforming Elements, React 提供一些 API 可以操作 elements

- `cloneElement()`
- `isValidElement()`
- `React.Children`

Fragments, 打包多個 elements

- `React.Fragment`

Refs, `ref` 相關 API

- `React.createRef`
- `React.forwardRef`

Suspense, 渲染前的等待 API, 目前只用於 component lazy load

- `React.lazy`
- `React.Suspense`

Hooks, React 16.8+ 才提供的功能

- `useState`
- `useEffect`
- `useContext`
- `useReducer`
- `useCallback`
- `useMemo`
- `useRef`
- `useImperativeHandle`
- `useLayoutEffect`
- `useDebugValue`

#### Reference

React.Component

- React component 的基礎, 通常使用 `class extends` 語法互動

React.PureComponent

- 類似 `React.Component`, 但是不包含 `shouldComponentUpdate()`, 取得代之的是使用 shallow prop and state comparison 決定是否 re-render
- 如果 React component 的 `render()` 結果只依據 prop 與 state 時, 可以使用 `React.PureComponent` 提昇效能
- shallow prop and state comparison, 只單純比較值, 因此深度的資料結構例如 Array, Object, 比較時需要額外注意
  - 解決方式可以使用 `immutable objects`, `forceUpdate()`
- 使用 `React.pureComponent` 時, shallow comparison 的判斷更新會影響整個 subtree, 因此最好要確保所有子代都是 pure component, 才不會有無法正常更新的問題出現

React.memo

- `React.memo` 是一個 higher order component
- 如果一個 function component 是 pure 的, 即 `render()` 的結果只依據傳入的 props 時, 可以通過 `React.memo` 包裹提供 memoizing 以提昇效能.
- 如果 `React.memo` 包裹的 function component 中, 使用到 `useState` 或 `useContext` 時, 在 state 與 context 改變時, 也會正常的重新計算 `render()`.
- 預設 `React.memo` 的 props compare function, 是一般的 shallow compare, 因此如果 props 是 object 時, 可以傳入自訂的 compare function 取代 `function areEqual (prevProps, nextProps) {}`, 回傳 boolean
- `React.memo` 這個功能只能視為效能最佳化的方式, 不保證一定能避免 render 的觸發. (不可以把邏輯建立在 `React.memo` 一定會避免 render 上)

createElement()

- `React.createElement(type, [props], [...children]`
- 創造 React element
- 使用 JSX 語法糖會自動轉譯為 `createElement()` 呼叫

cloneElement()

- `React.cloneElement(element, [props], [...children])`
- clone 且回傳 React element
- 新的 children 會取代舊的, `key` 與 `ref` 會被保留, `props` 會做 shallow merge
- 幾乎等價於 `<element.type {...element.props} {...props}>{children}</element.type>`

createFactory()

- `React.createFactory(type)`
- 類似 `React.createElement()`
- 推薦使用 JSX 或者 `React.createElement()` 即可

isValidElement()

- `boolean React.isValidElement()`
- 判斷是否是 React element 回傳 boolean

React.Children

- 提供處理 `this.props.children` 的操作工具
- `React.Children.map(children, function([thisArg]))`, 回傳 array / `null` / `undefined`
- `React.Children.forEach(children, function[(thisArg)])`,
- `React.Children.count(children)`, children component 的數量
- `React.Children.only(children)`, 判斷是否只有唯一一個 React element 並且回傳該 element, 否則會丟初例外
- `React.Children.toArray(children)`, 把 children 轉換成 flat array
- children 是 Fragment 時會被視為單個 element

React.Fragment

- 包裹多組 elements 並且在 render 時不會生成額外的 DOM element
- `<React.Fragment></React.Fragment>`, 或 `<></>`

React.createRef

- 生成 `ref` 變數並且可以通過 `ref` attribute 傳遞給其他 element

React.forwardRef

- `React.forwardRef()` 是一個 function,
  - Input: `(props, ref) => {}` function component,
  - Output: React node
- 協助明確定義 `ref` 參數的綁定對象, 上層函式可以通過 `React.createRef()` 與 `ref.current` 創建且取值

React.lazy()

- React lazy load component
- `const SomeComponent = React.lazy(() => import('./SomeComponent'));`
- 定義 component 成動態載入, 作為 code splitting 的實現方式之一
- 參考 [code splitting 文件](https://reactjs.org/docs/code-splitting.html#reactlazy) 與[說明文章](https://medium.com/hackernoon/lazy-loading-and-preloading-components-in-react-16-6-804de091c82d)
- 需配合 `React.Suspense` 一起使用

React.Suspense

- `<React.Suspense fallback={}></React.Suspense>`
- 代表子代可能尚為準備好 render 需要等待, 目前唯一使用案例是配合 `React.lazy()` 實現 component 動態載入
- `React.lazy()` 產生的 component 不需要是直接子代
- `React.Suspense` 放置的位置, 推薦在任何想要看到 loading 提示的地方
- 在未來會提供除了 component 動態載入以外的使用案例, 例如 data fetching 時的等待.

---

### 第二章 - React.Component

#### Overview

- React component 可以使用 function 或 class 定義
- 使用 class 定義 React component 目前擁有更多功能
- `class extends React.Component { render() {} }`
- class 裡必須擁有 `render()` function, 其他函式都是選用的
- 在 React 世界裡高度推薦只使用 composition 取代任何的 inheritance
- 語法上使用 ES6 `class` 或者 `create-react-class()` 皆可

The Component Lifecycle

- 每個 component 都有各自的 lifecycle functions, 可以任意的 override 注入行為

Mounting, 初始階段, component 建置並且 insert 到 DOM

- `constructor()`, 常用
- `static getDerivedStateFromProps()`
- `render()`, 常用
- `componentDidMount()`, 常用

Updating, 更新階段, 當 props 或 state 改變時, 會觸發以下流程

- `static getDerivedStateFromProps()`
- `shouldComponentUpdate()`
- `render()`, 常用
- `getSnapshotBeforeUpdate()`
- `componentDidUpdate()`, 常用

Unmounting, 移除階段, component 將從 DOM 中移除

- `componentWillUnmount()`, 常用

Error Handling, 在 rendering, lifecycle, constructor 階段出現錯誤時會觸發

- `static getDerivedStateFromError()`
- `componentDidCatch()`

Other APIs

- `setState()`
- `forceUpdate()`

Class Properties

- `defaultProps`
- `displayName`

Instance Properties

- `props`
- `state`

#### Reference

- [React lifecycle diagram](https://projects.wojtekmaj.pl/react-lifecycle-methods-diagram/)

render(), 常用

- `render()`
- 對於 class component 來說唯一必要的 method
- `render()` 應該要是 pure 的, 只依據 `this.props` 和 `this.state` 去產生以下類型的結果
  - React elements, 通常通過 JSX 語法定義, 會被 React 渲染到 DOM 中
  - Array and fragments, 多數個 elements
  - Portals, 直接渲染 children 到指定的 DOM subtree 中
  - String and numbers, 作為 text nodes 被渲染到 DOM 中
  - Booleans or `null`, 不會渲染任何東西, 可以作為條件渲染的實現方式之一
- 保持 `render()` 的 pure 性質, 需要與瀏覽器互動的功能需要寫在其他 lifecycle methods 中, 例如 `componentDidMount()`

constructor(), 常用

- 如果不需要初始化 state 和綁定 methods, 可以不額外建立 constructor()
- 建立 `constructor(props) { super(props); }` 必須呼叫 `super(props)`, 讓 `React.Component` class 先行初始化
- 常用情境
  - 初始化 local state, `this.state = {}`,
  - 綁定 event handler, `bind(this)`
- 不應該在 `constructor()` 裡呼叫 `setState()`, 必須使用 assign `=` 去初始化, 並且也是唯一可以合法使用 assign `this.state` 的地方
  - 在其他情況, 修改 `state`, 就需要呼叫 `setState()`
- 不要讓 `constructor()` 有副作用
- 常見錯誤, 複製 props 到 state 中, 會導致更新錯誤, 參考[文件說明](https://reactjs.org/docs/react-component.html#constructor)

componentDidMount(), 常用

- `componentDidMount()`
- 在 component 被 insert 到 DOM 之後會立即執行 `componentDidMount()`
- 需要配合 DOM tree 的初始化可以放在這個函式中,
  - 像是發送請求取值 (request)
  - 註冊 event handler, 記得在 `componentWillUnmount()` 裡執行 unsubscribe 避免產生 memory leak
- 在 `componentDidMount()` 裡可以呼叫 `setState()`, 並且更新會在下一次 UI 更新時一起實現,
  - 使用案例: 需要測量 DOM node 的 size 或 position 時

componentDidUpdate(), 常用

- `componentDidUpdate(prevProps, prevState, snapshot)`
- 在更新玩後會立即觸發, 在第一次 render 時不會觸發
- 一樣可以作為操作 DOM 和發送 request 的地方, 並且可以呼叫 `setState()` 但是必須要有條件式的呼叫不然會產生無窮迴圈 (infinite loop)
- 如果 component 有實作 `getSnapshotBeforeUpdate()` 時, 也會接收到 snapshot 參數
- 如果 `shouldComponentUpdate()` 回傳 false 時, 不會觸發 `componentDidUpdate()`

componentWillUnmount(), 常用

- `componentWillUnmount()`
- 在 component 被從 DOM 移除或消除之前, 會先觸發. 通常作為 cleanup 的處理時機
- 在 `componentWillUnmount()` 呼叫 `setState()` 是不必要且無意義的

shouldComponentUpdate()

- `shouldComponentUpdate(nextProps, nextState)`, 預設是回傳 `true`
- 藉由此函式告知 React 依據當前的 props 與 state 可以不重新渲染 UI (re-render / update)
- 此函式在 initial render 和 `forceUpdate()` 的情況下不會觸發
- 這個函式唯一的用途是效能最佳化, 多數情況可以使用 `extends React.PureComponent` 取代手動撰寫 `shouldComponentUpdate()`
- `React.PureComponent` 會自動使用 shallow compare 作為比較函式, 只依據 props 與 state 的 shallow comparison 作為更新的依據
- 當 `shouldComponentUpdate()` 回傳 `false` 時會一同影響所有的子代 component
- 非常不推薦使用 deep comparison 在這個函式中, 會造成效能問題
- 在未來的 React 中 `shouldComponentUpdate()` 只會被作為效能提昇的"參考", 而不保證一定會被執行.

static getDerivedStateFromProps()

- `static getDerivedStateFromProps(props, state)`
- 在 `render()` 被呼叫之前會先呼叫 `getDerivedStateFromProps`, 包含第一次 render, 會回傳 object 或 `null`
- 只有非常少的使用案例, [參考文件](https://reactjs.org/blog/2018/06/07/you-probably-dont-need-derived-state.html#when-to-use-derived-state), 例如實現 transition 的動畫觸發
- 作為 pure function 和 static function, 因此並不允許讀取當前的 component instance

getSnapshotBeforeUpdate()

- `getSnapshotBeforeUpdate(prevProps, prevState)`
- 在 render 產生 output 放到 DOM 後會呼叫 `getSnapshotBeforeUpdate()`, 通常用來取得 DOM 上的資訊, 取得的資訊會被傳遞給 `componentDidUpdate()`
- 使用案例非常少, 通常用來操作 UI 時使用, 例如依據 DOM 做 scroll

Error boundaries

- 用來捕捉 JavaScript error
- 如果一個 class component 實作了 `static getDerivedStateFromError()` 或 `componentDidCatch()` 時, 就會形成 error boundary
- 只能捕捉子代的 error 不包含本身, 只作為錯誤處理使用, 而非作為正常流程的一部分
- 參考 [Error Handling 文件](https://reactjs.org/blog/2017/07/26/error-handling-in-react-16.html)

static getDerivedStateFromError()

- `static getDerivedStateFromError(error)`
- 捕捉到任何子代 component 丟出的錯誤, 並且回傳一個值來更新 state, 影響 UI 顯示

componentDidCatch()

- `componentDidCatch(error, info)`
- 任何子代丟出 error 時觸發, 會接收 error 參數與 info 參數 (物件包含 `componentStack` 的資訊)
- `componentDidCatch()` 會在 commit 階段觸, 因此可以有 side-effect 例如 log 錯誤訊息
- 在這個函式裡使用 `setState` 影響 UI 在未來會被移除, 使用 `static getDerivedStateFromError()` 取代呼叫 `setState()`

Other APIs

- 另外可以在 class component 中呼叫的函式 `setState()` 與 `forceUpdate()`

setState()

- `setState(updater, [callback])`, 這是 React 最主要觸發更新與回應的方式
- 會把改變放進佇列中 (enqueue), 告知 React 這個 component 與子代需要更新了.
- `setState()` 視為 request, 而非立即執行的命令, 為了效能, React 可能會延遲並且整合數個更新才一次執行. 因此 React 並不保證更新會立即執行.
- 因為可能會延遲執行導致 `setState()` 與 `this.state` 的值改變可能會不可預期的時間差, 因此可以通過 `componentDidUpdate` 或 `setState(updater, callback)` 的方式保證在更新後執行取得預期中的 state
- `setState()` 一定會觸發 re-render 除非 `shouldComponentUpdate()` 回傳 `false`.
- updater function: `(state, props) => stateChange`, Input 的 state 與 props 保證是最新的, Output 會與 `state` 做 shallow merge
- 選用的 callback function 基本上等價於 `componentDidUpdate()` 的觸發時機與使用情境
- `setState()` 是非同步執行的, 因此在同個 cycle 裡的 `setState()` 可能會被合併後一起執行, 合併是 shallow merge

forceUpdate()

- `component.forceUpdate(callback)`
- 預設 component 是依據 state 和 props 的改變來觸發 re-render, 但是可以通過 `forceUpdate()` 主動告知 React 需要執行 re-render
- 使用 `forceUpdate()` 會忽略 `shouldComponentUpdate()` 的觸發, 但是所有子代的 lifecycle methods 包含 `shouldComponentUpdate()` 仍然會正常執行.
- 並不推薦使用 `forceUpdate()` 破壞 React 原本的工作流程

Class Properties: defaultProps

- 通過 `defaultProps` 參數設定, component 的預設 props

Class Properties: displayName

- 通過設定 `displayName`, 提供 React debugger 資訊

Instance Properties: props

- `this.props`, 包含 component 被呼叫時傳入的 props 值
- `this.props.children` 則是特殊的 prop, 代表 element 所包裹的子代

Instance Properties: state

- `this.state`, 代表 component 內在所包含的狀態, 可能會隨著時間改變, 通常是單純的 JavaScript object.
- 與 UI 顯示無關的資料, 不應該放在 state 中, 可以作為 component instance 中的其他變數
- 永遠不要直接修改 `this.state`, 應該要透過 `setState()`, 並且把 `this.state` 視為 immutable 的資料

---

### 第三章 - ReactDOM

#### Overview

- `react-dom` 提供 DOM 相關的方法, 用來與 React model 溝通
- `render()`
- `hydrate()`
- `unmountComponentAtNode()`
- `findDOMNode()`
- `createPortal()`

Browser Support

- React 支援主流的瀏覽器, 包含 IE9+, IE9 和 IE10 需要其他的補釘
- 並且不直接支援不提供 ES5 以上語法的瀏覽器, 需要額外加裝補釘

#### Reference

render()

- `ReactDOM.render(element, container[, callback])`
- 觸發 React element 渲染到指定的 DOM `container` 上, 並且回傳 reference 或者 `null`
- 如果已經觸發過一次, 再次呼叫相同的 `ReactDOM.render()` 到相同的 `container` 時會變成更新
- 選用的 callback function 會在 component 完成渲染或更新後執行
- React DOM 更新是通過 React diffing 演算法比較後執行的
- `ReactDOM.render()` 並不會影響 container DOM 本身, 只是修改 container 的子代
- 回傳值的 reference 功能在未來會被淘汰, 不要使用
- 在 server-side 使用 `ReactDOM.render()` 的功能在未來也會淘汰, 使用 `hydrate()` 取代.

hydrate()

- `ReactDOM.hydrate(element, container[, callback])`
- 類似於 `render()`, 但是注入的 container 是由 ReactDOMServer 產生的, 而非純瀏覽器的 DOM element.
- React 希望渲染的內容可以達到前後端一致, 只需要補上差異的地方
- 在 development mode, React 在 `hydrate()` 前後端不一致的情況下會提供警告, 並且應該修正.
- 如果有些值, 前後端本來就會不一樣時, 可以關閉警告 `suppressHydrationWaring={true}`
- 其他情況如果前後端渲染必須不同時, 可以通過在 `componentDidMount()` 裡使用 `this.state.isClient` 去做條件渲染, 但是這種方式會造成效能問題, 因為會觸發 render 兩次
- 主要考慮使用者體驗與連線問題

unmountComponentAtNode()

- `ReactDOM.unmountComponentAtNode(container)`
- 從指定的 DOM container 中移除 React component 並且 cleanup event listener 與 state.
- 如果 container 裡沒有 React element 則不會有反應, 並且回傳 `false`, 反之成功移除則回傳 `true`

findDOMNode()

- `ReactDom.findDOMNode(component)`
- 取得指定的 React element 的 DOM reference
- 無法使用在 function component 上
- 不推薦使用 `findDOMNode()`, 相同的需求可以使用 `ref` 相關解決方案

createPortal()

- `ReactDOM.createPortal(child, container)`
- 建立 portal, 提供直接渲染 child 到指定的 DOM container 中
- [參考文件](https://reactjs.org/docs/portals.html)

---

### 第四章 - ReactDOMServer

- 提供渲染 component 到靜態頁面上, 通常運行在 Node.js 上
- `import ReactDOMServer from "react-dom/server`

#### Overview

- 可以同時使用在 server 與 browser 的渲染
  - `renderToString()`
  - `renderToStaticMarkup()`
- 配合 `Stream` 並且只能運行在 server 上的渲染
  - `renderToNodeStream()`
  - `renderToStaticNodeStream()`

#### Reference

renderToString()

- `ReactDOMServer.renderToString(element)`
- 渲染成 HTML string, 可以在 server-side 快速渲染出基本的 html 以提昇 SEO
- 如果在 node 上使用 `ReactDOM.hydrate()` 已經渲染出 server-rendered markup 時, React 會重用並且註冊 event handler 以提昇使用者體驗

renderToStaticMarkup()

- `ReactDOMServer.renderToStaticMarkup(element)`
- 類似於 `renderToString()`, 但是不會創造使用在 React 內部的額外 DOM 屬性,
- 常用於生成純靜態的頁面 (simple static page generator), 頁面上不需要 React 再去互動
- 如果希望 React 能在 client-side 繼續運作的話, 使用 `renderToString` 在 server-side 配合 `ReactDOM.hydrate()` 在 client-side.

renderToNodeStream()

- 生成初始化的 HTML 並且回傳承 [Readable Stream](https://nodejs.org/api/stream.html#stream_readable_streams) 的格式
- 生成的結果等同於 `ReactDOMServer.renderToString`
- 使用情境也類似於 `ReactDOMServer.renderToString`, 在 server-side 動態生成 HTML 後作為 response 回傳提昇 SEO.
- 可以配合 `ReactDOM.hydrate()` 使用達成前後端一致的 React application
- Stream 預設是 `utf-8`, 這個 API 只能使用在 server-side

renderToStaticNodeStream()

- 類似於 `renderToNodeStream`, 但是輸出結果等同於 `ReactDOMServer.renderToStaticMarkup`, 回傳的結果不包含 React 相關的屬性, 因此在 client-side 無法使用 React 功能.

---

### 第五章 - DOM Elements

- React 自行實作了 DOM elements 解決跨瀏覽器相容性與效能問題
- 在 React 中所有的 DOM 屬性都要使用 camelCased, 除了 `aria-*` 和 `data-*` 之外

#### Differences In Attributes

- React element 與 HTML element 不同之處

checked

- `checked`, 作為 `<input>` type `checkbox` 和 `radio` 使用
- 可以用於 controlled component,
- 使用 `defaultChecked` 屬性則是 uncontrolled, 可以提供 first mount 並且在 React 接管以前的預設值

className

- `className`, 主要用於提供樣式 class, 可以作用於所有常見的 DOM element 與 SVG element
- 在 React 與 Web Components 一同使用時, 要改回使用 `class`

dangerouslySetInnerHTML

- `dangerouslySetInnerHTML`, 等價於 `innerHTML`.
- React 取名為 `dangerouslySetInnerHTML`, 因為直接放入 html 會產生被 cross-site scripting (XSS) 攻擊的機會
- 因此在 React 中呼叫時, 有更繁瑣的宣告, 用來提醒工程師, 參考[範例](https://reactjs.org/docs/dom-elements.html#dangerouslysetinnerhtml)

htmlFor

- `htmlFor`, 等價於 `for`
- 由於 `for` 是 JavaScript 的保留字, 因此 React 命名為 `htmlFor`

onChange

- `onChange`, 只要任意的 form 表單內容改變都會觸發
- 屬於 controlled component 由 React 所控制的 form

selected

- 配合 `<option>` 使用, [參考文件](https://reactjs.org/docs/forms.html#the-select-tag)

style

- `style` 在 React 中接收 object 包含 camelCased 的樣式名稱
- 實務上樣式比較推薦使用 `className` 去綁定, 而非 inline 的 `style`
- 樣式名稱並不會自動加上瀏覽器的 prefix, 如果需要支援舊版的瀏覽器需要自行加上前綴, [參考文件](https://www.andismith.com/blogs/2012/02/modernizr-prefixed/)
- React 會自動加上 `px` 給數值, 如果使用其他單位需要明確撰寫, 除了[清單](https://github.com/facebook/react/blob/4131af3e4bf52f3a003537ec95a1655147c81270/src/renderers/dom/shared/CSSProperty.js#L15-L59)內的樣式例外

suppressContentEditableWarning

- `suppressContentEditableWarning`, 會關閉 `contentEditable` 警告
- 當 element 被設置 `contentEditable` 時會出現警告
- 除非是要建立自行管理 `contentEditable` 的函式庫, 否則不應該關閉這個警告

suppressHydrateWarning

- `suppressHydrateWarning`, 關閉 mismatches 警告
- 在使用 server-side rendering 時, 配合 `ReactDOM.hydrate()` 渲染 client-side, 如果不一致時會提出警告.
- 只有當值真正無法在前後端一致時才需要關閉, 例如 timestamp

value

- `value`, 給 `<input>`, `<select>`, `<textarea>` 使用的 attribute.
- 用來提供 controlled component 的值
- 對於 uncontrolled component 則使用 `defaultValue` 作為預設值指定

#### All Supported HTML Attributes

- 對於 React 16+ 幾乎所有的標準 attributes 都有支援, 參考說明[文件](https://reactjs.org/blog/2017/09/08/dom-attributes-in-react-16.html)
- 包含一般的 element 與 SVG

---

### 第六章 - SyntheticEvent

- React 處理 event 的方式

#### Overview

- 所有的 event handler 會接收到的是 `SyntheticEvent` 的 instance, 作為跨瀏覽器 event 的解決方案會包裹瀏覽器原生的 event.
- 提供跨瀏覽器一致的 `stopPropagation()`, `preventDefault()` 函式
- 可以通過 `nativeEvent` 取的瀏覽器原生的 event
- 在 React 14+, event handler 回傳 `false` 不再會停止 propagation, 需要明確的呼叫 `stopPropagation()` 或 `preventDefault()`

Event Pooling

- `SyntheticEvent` 作為類似 String pool 的方式存在 (pooled), 意思是 `SyntheticEvent` 會因為效能最佳話而重複使用, 因此 `event` 無法被非同步的方式使用 (asynchronous)
- 配合 `event.persist()` 則可以使用非同步方式處理 event

Supported Events

- React 實作跨平台的 event 保持統一的界面
- Event handlers 會在 bubbling 的階段被觸發, 如果需要在 capture 階段觸發, 則需要使用另外的 event name, 例如 `onClick` => `onClickCapture`
- 支援以下類型 events
  - Clipboard Events, Composition Events, Keyboard Events, Focus Events, Form Events, Generic Events, Mouse Events, Pointer Events, Selection Events, Touch Events, UI Events, Wheel Events, Media Events, Image Events, Animation Events, Transition Events, Other Events

#### Reference

- [參考文件](https://reactjs.org/docs/events.html#reference) 包含 event name 與攜帶的 properties

---

### 第七章 - Test Utilities

- 作為獨立測試 React 相關程式的測試工具
- React 的測試推薦使用 React testing library 以類似使用者實際操作的方式測試
- `import ReactTestUtils from "react-dom/test-utils";`

#### Overview

- 協助測試 React component 的測試工具
- 官方更推薦使用 React Testing Library 來測試 React application

#### Reference

---

### 第八章 - Test Renderer

- `import TestRenderer from "react-test-renderer";`

#### Overview

- 函式庫提供渲染 React element 成單純的 JavaScript object 方便測試使用
- 協助方便取得 snapshot 而不需要使用 `jsdom`
- 可以被 React Testing Library 取代

---

### 第九章 - JS Environment Requirements

- React 16+ 需要使用到 `Map` 與 `Set`
- 在不支援 ES6 的版本需要另外加裝 polyfill, 例如 `core-js`, `babel-polyfill`

---

### 第十章 - Glossary

Single-page Application, (SPA)

- SPA 代表一個應用程式只使用單一個 HTML 其他所有的操作都不會讓 page reload, 而是使用 JavaScript 控制
- React library 非常容易的與任意的 HTML 部份互動, 因此可以良好的與任何工具合作, 不管是 server-side 或 client-side.

ES6, ES2015, ES2016, etc

Compilers

- 從 JavaScript 轉換成另外一種形式的 JavaScript, 例如 `Babel`

Bundlers

- 讓前端程式可以以模組化的方式撰寫, 通過把打包工具轉換成瀏覽器能方便讀取的資料集合
- 打包工具例如 `Webpack`, `Browserify`

Package Managers

- 用來管理相依性的工具, 例如 `npm`, `Yarn`

CDN

- Content Delivery Network, 提供 cached 的資料, 並且存在世界各地的伺服器中, 提供更快的讀取時間

JSX

- JavaScript 的語法擴充, 類似於模板語言 (template language), 可以充分的使用 JavaScript 語法並且轉譯成 `React.createElement()`
- attribute 使用 camelCased 取代原本 HTML 的 attribute name

Elements

- React element 作為 React component 的基礎, `React.createElement()`
- React elements 是 immutable 的

Components

- React component 是小型且可重複使用的 UI 渲染邏輯
- 可以分成 function component 與 class component
- 客製化的 component, 都需要使用大寫開頭

props

- 作為 React component 的 input, 單一向的傳遞資料從父層到子層
- `props` 是唯獨的 (readonly)

props.children

- `props.children`, 特殊的 props, 用來取得父層包裹的子代內容.

state

- `state`, component 內部會隨著時間改變並且影響 UI 的狀態
- 一個 component 無法改變 props, 但是可以通過 `setState` 改變自身的 state 狀態
- 當有 component 需要共用 state 時應該透過 [lift it up](https://reactjs.org/docs/lifting-state-up.html) 技術拉到共用的祖先, 然後透過 `props` 傳遞進去.

Lifecycle Methods

- 提供介入 component 不同階段的函式

Controlled vs. Uncontrolled Components

- React 處理 form `input` 的兩種方式
- 如果一種 `input` 可以完全由 React 所控制則稱為 controlled component
- React 無法控制需要自行控制的 `input` 則稱為 uncontrolled component

Keys

- 作為特別的字串屬性 (attribute), 用來提示 React 清單中項目的處理方式,
- Keys 只需要相鄰的獨立 (unique among sibling) 不需要全域獨特.
- 不要使用 `Math.random()` 作為 Keys, Keys 應該要是穩定的, 用來影響清單中的新增, 移除, 排序的處理

Refs

- React 中特別的 attribute, `ref` 屬性可以為使用 `React.createRef()` 所創造或者是 callback function
- 作為 callback function 會取得所呼叫的 DOM reference
- 盡可能減少使用 `ref` 破壞封裝, 使用 React 正常的流程操作 component 為上

Events

- React event handler 使用 camelCase
- JSX 傳遞 function 作為 event handler

Reconciliation

- React component 通過 props 與 state 改變, 去決定 DOM UI 需要更新, 實際更新會通過比較舊的 tree 與新的 tree 是否相等 (React diffing algorithm), 然後 React 才會去更新必要的 DOM.
- 以上過程在 React 中稱為 `reconciliation`

---

22 + 10 = 32
