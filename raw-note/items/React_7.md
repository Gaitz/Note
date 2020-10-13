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

- React 設計 diffing 演算法與控制 UI 更新的決策

Motivation

-

---

### 第十六章 - Refs and the DOM

---

### 第十七章 - Render Props

---

### 第十八章 - Static Type Checking

---

### 第十九章 - Strict Mode

---

### 第二十章 - Typechecking with PropTypes

---

### 第二十一章 - Uncontrolled Components

---

### 第二十二章 - Web Components

---

### 第一章 - React

---

### 第二章 - React.Component

---

### 第三章 - ReactDOM

---

### 第四章 - ReactDOMServer

---

### 第五章 - DOM Elements

---

### 第六章 - SyntheticEvent

---

### 第七章 - Test Utilities

---

### 第八章 - Test Renderer

---

### 第九章 - JS Environment Requirements

---

### 第十章 - Glossary

---

22 + 10 = 32
