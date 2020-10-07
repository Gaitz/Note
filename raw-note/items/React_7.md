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

Context.Provider

- Context 物件中的 Provider component, `<CustomContext.Provider value={}>`

---

### 第四章 - Error Boundaries

---

### 第五章 - Forwarding Refs

---

### 第六章 - Fragments

---

### 第七章 - Higher-Order Components

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
