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

---

### 第九章 - JSX In Depth

---

### 第十章 - Optimizing Performance

---

### 第十一章 - Portals

---

### 第十二章 - Profiler

---

### 第十三章 - React Without ES6

---

### 第十四章 - React Without JSX

---

### 第十五章 - Reconciliation

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
