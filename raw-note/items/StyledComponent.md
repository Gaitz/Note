## Styled-component official documentation

### [styled-components](https://styled-components.com/), CSS

---

第一章 - Index page, README

Basics

第二章 - Motivation

第三章 - Installation

第四章 - Getting Started

第五章 - Adapting based on props

第六章 - Extending styles

第七章 - Styling any component

第八章 - Passed props

第九章 - Coming from CSS

第十章 - Attaching additional props

第十一章 - Animations

第十二章 - React Native

Advanced

第十三章 - Theming

第十四章 - Refs

第十五章 - Security

第十六章 - Existing CSS

第十七章 - Tagged Template Literals

第十八章 - Server Side Rendering

第十九章 - Referring to other components

第二十章 - Style Objects

API Reference

第二十一章 - Primary

第二十二章 - Helpers

第二十三章 - Test Utilities

第二十四章 - Supported CSS

第二十五章 - Flow

第二十六章 - TypeScript

第二十七章 - Previous APIs

Tooling

第二十八章 - Babel Plugin

第二十九章 - Babel Marco

第三十章 - TypeScript Plugin

第三十一章 - Jest Integration

第三十二章 - Stylelint

第三十三章 - Styled Theming

第三十四章 - Syntax Highlighting

---

### 第一章 - Index page, README

Install

- `npm install --save styled-components`

Usage, [Your first styled component](https://styled-components.com/#your-first-styled-component)

- `import styled from 'styled-components'`
- 語法上使用，新語法 function + template string 的方式實現 [Tagged templates mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Template_literals#tagged_templates), 使用 **`** 執行 function
- 基礎用法: styled library 呼叫對應 html element name 的 method, 例如 `styled.button` 在配合 **`** 帶入 css 語法在 template string 裡，回傳值是 React component
- 進階用法: 傳入參數提供作為判斷提供不同的樣式, 利用 `props` 與 `css` function in `styled-components`

---

Basics

---

### 第二章 - Motivation

- 提供 React component 的 styling

Features

- 自動達到 code splitting, 只載入需要的 styles
- Class name 自動生成, 不會有 collision
- CSS code 與使用到的 component 綁在一起, 可以更好的定位 styling 並且在 component 被移除時一同移除 css 廢碼
- CSS code 被綁定 component 並且只出現在一個地方, 更好維護, 減少樣式的相依性
- 自動加上 css vendor prefixing

---

### 第三章 - Installation

安裝模組

- `yarn add styled-components`, `nmp install --save styled-component`

- 在使用支援 package.json `resolutions` 時 (例如 `yarn`) 推薦使用, 避免多版本問題.
- 另有 CDN 的安裝模式

---

### 第四章 - Getting Started

- `styled-components` 使用 tagged template literals 語法實現
- 基礎範例, [參考](https://styled-components.com/docs/basics#getting-started)

---

### 第五章 - Adapting based on props

- 使用 `${props => }` 基於 component props 提供不同的樣式
- 參考[範例](https://styled-components.com/docs/basics#adapting-based-on-props)

---

### 第六章 - Extending styles

- 使用 `styled()` input 一個 React component 後 override 樣式
- 利用 `styled-component` 建立的 React component, 帶有參數 `as` 可以修改內部渲染相依的 component, 例如 `as='a'`, `as={CustomComponent}`
- 參考[範例](https://styled-components.com/docs/basics#extending-styles)

---

### 第七章 - Styling any component

- 使用 `styled()` 把樣式套在任意的 component 上, 會傳遞 `className` 作為 props 只需要帶入在所需的 component 上
- 參考[範例](https://styled-components.com/docs/basics#styling-any-component)

---

### 第八章 - Passed props

- `styled` 生成的 React component 會自動傳遞所有的 props 到實際的 component 或者 DOM element 上, 不會改變行為.
- 並且會濾掉所有不合法的 attributes

---

### 第九章 - Coming from CSS

- 從 `css modules` 改寫成 `styled-component`, 參考[範例](https://styled-components.com/docs/basics#how-do-styled-components-work-within-a-component)
- styled component 必須要定義在 render function 外部, 避免重新創造
- 使用 Pseudoelements, pseudoselectors, 使用 `&` 代表第一層的 element 選擇器, 可以配合其他標準的 css selectors 去建立樣式, 參考[範例](https://styled-components.com/docs/basics#pseudoelements-pseudoselectors-and-nesting)

---

### 第十章 - Attaching additional props

- 傳遞 element attributes 到 DOM 層
- 使用 `.attrs()`
- [範例](https://styled-components.com/docs/basics#attaching-additional-props), 跨層傳遞 input `type`

---

### 第十一章 - Animations

- 建立 `@keyframes` 相關 CSS 並且避免 name collisions
- 使用 `keyframes` function 建立
- 在 version 3 以上時, `keyframes` function 建立的內容會被 code-split, 因此使用上需要額外被 `css` helper function 包裹, 才能正確執行.

---

### 第十二章 - React Native

- 也支援 React Native 上使用

---

Advanced

---

### 第十三章 - Theming

- 支援建立 theme 與 `<ThemeProvider>` 使用 context 來傳遞
- 傳遞 theme 物件提供被 `<ThemeProvider>` 包裹的 styled component 以 `props.theme` 取用
- 參考[範例](https://styled-components.com/docs/advanced#theming)

Function theme

- `theme` 改以 function 方式存在，以此可以取得上層 `ThemeProvider` 的值, 並且產生新的 inner theme 在近層使用。
- 提供更 contextual 的 theming
- 參考[範例](https://styled-components.com/docs/advanced#function-themes)

Getting the theme without styled components

- 在 JavaScript 中取用 theme context 的值

1. 使用 `import { withTheme } from 'styled-components'` HoC 方式
2. 使用 `React.useContext` 配合 `import { ThemeContext } from 'styled-components'`的 hook 方式

The `theme` prop

- 直接傳遞 `theme` prop 給 styled-component 可以 override 或者不使用 ThemeProvider 來提供 theme

---

### 第十四章 - Refs

- styled-component v4 以上支援使用 `ref` props 與 `React.createRef()`
- 參考[範例](https://styled-components.com/docs/advanced#refs)

---

### 第十五章 - Security

- styled-component 允許任意 JavaScript 變數植入 CSS 中
- 如果樣式的變數值, 是來自使用者或其他不可信任的來源時, 會產生 CSS injection 的攻擊機會
- 必須額外使用 CSS.escape, ... 工具來跳脫攻擊語法, 參考[文件](https://styled-components.com/docs/advanced#security)

---

### 第十六章 - Existing CSS

使用 styled-component 配合其他 CSS 檔案時的注意事項

- styled-component 使用 class name 並且通過 `className` JSX attribute 傳入, 並且生成樣式檔在 `<head>` 的最後

Styling normal React components

- styled 作用在一般的 React component 時記得傳遞 `className` 才能正確的帶上樣式的 class
- 注意樣式的優先性問題, 因為 styled component 生成的樣式檔放置在 `<head>` 的最後, 因此在同級的情況下, 通常會勝出採用, 否則需要提昇 selector 層級優先度

同頁上的第三方 style 碰撞問題

- 可以配合 `babel-plugin-styled-components-css-namespace` 以提供 `id` container 的方式來提昇 styled-component 的 selector 層級
- 遇到同頁上使用兩組以上的 styled-component 碰撞問題可以利用 `process.env.SC_ATTR` 來區隔, 參考[文件](https://styled-components.com/docs/advanced#avoiding-conflicts-with-thirdparty-styles-and-scripts)

---

### 第十七章 - Tagged Template Literals

- 在 ES6 上的新語法, 提供執行函式的新方式
- 並且在 styled-component 的使用上會跳脫 falsy 的 parameter value, 例如 `undefined`, `null`, `false`, `''`
- 深入閱讀 [The magic behind 💅 styled-components](https://mxstbr.blog/2016/11/styled-components-magic-explained/)
- [Template literals, mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Template_literals#tagged_templates)

---

### 第十八章 - Server Side Rendering

- 支援 SSR, 需要額外做設定來帶入 `ServerStyleSheet`
- 配合專用的 babel plugin, 來避免 className hash unstable 的問題, 參考[文件](https://styled-components.com/docs/advanced#tooling-setup)
- 設定 `import { ServerStyleSheet, StyleSheetManager } from 'styled-components'` 參考[文件](https://styled-components.com/docs/advanced#example)
- [文件](https://styled-components.com/docs/advanced#nextjs)提供 Next.js, Gatsby, Streaming Rendering 的設定方式

---

### 第十九章 - Referring to other components

- web-specific, react-native 無法使用
- `styled()` factory function 會提供 stable 的 class name, 因此可以在 styled-component styling 上直接引用其他的 styled-component 作為 selector reference.
- 參考[範例](https://styled-components.com/docs/advanced#referring-to-other-components)
- 限制, 這個行為只能作用在都是 styled-component 上, 無法直接參考其他 React component, 但是可以通過 styled(OtherReactComponent)`` 快速把一般的 React component 變成 styled component

---

### 第二十章 - Style Objects

- Styled component 允許樣式除了使用 string 的方式表達之外, 也支援傳入 style object 的方式來實現
- 非常適合在移植已經有 style object 的情況下使用

---

API Reference

---

### 第二十一章 - Primary

`styled`, 低階的 factory function 有兩種格式

- `styled.{tagName}`, 建立一般的 DOM element styled component
- `styled(ComponentName)`, 建立其他 React Component styled component

Tagged Template Literal

- 傳遞 CSS Rule 或是其他相依的字串變數與函式 (Ex. theme)

Styled Component

- 經過 `styled` factory function 轉換形成的 styled component
- 可以傳遞任何合法的 attributes 與 className 到實際的 React component 或 DOM component 上
- 使用 `.attrs()` 來傳遞定義樣式所使用的參數 (不適合合法的 DOM attributes)
- 使用 `as` attribute 來改變實際渲染的 DOM element 類型
- 使用 `$` 作為 attribute prefix, 形成只在 styled component 樣式使用的參數, 類似 `.attrs()` 的作用
- `shouldForwardProp` 適用於多層的 HoC 使用相同的參數名稱時的解決方案

`ThemeProvider`

- React context 的 helper function 用來傳遞 theme object

`css` Prop

- 必須配合 Babel plugin 使用
- 避免使用 `styled` 轉換成 styled component 的語法糖
- 配合 TypeScript 需要加上 `import {} from 'styled-components/cssprop'` 與安裝 `@types/styled-components`

---

### 第二十二章 - Helpers

`createGlobalStyle` helper function

- Web 專用
- 一次性建立 global style 形成對應的 Styled component 使用上類似 CSS resets, base stylesheet

`css` helper function

- 用來分離複雜的 style 邏輯到獨立的函式定義上

`keyframes` helper function

- Web 專用
- 實現 CSS animations 時使用, 可配合 `css` helper function 更進一步分離定義

`StyleSheetManager` helper function

- 客製化定義 processor 行為
- 例如配合 SSR 使用的 `sheet`, 或是關閉 vendor prefix 等等

`isStyledComponent` helper function

- 判斷一個 component 是否是 styled component

`ThemeConsumer` helper function

- 如果要在與樣式無關的 JavaScript 中取得 theme object 時使用

---

### 第二十三章 - Test Utilities

`find`, `findAll`

- 在 DOM 上搜尋指定的 styled component

`enzymeFind`

- 配合 `enzyme`, `mount` 使用時的 `find` function

---

### 第二十四章 - Supported CSS

- 配合 `&` 實現複雜的 CSS selectors

---

### 第二十五章 - Flow

- 可以支援 Flow typing

---

### 第二十六章 - TypeScript

- 可以支援 TypeScript typing
- `@types/styled-components`
- 配合 theming 的 TypeScript 定義, 參考文件[範例](https://styled-components.com/docs/api#create-a-declarations-file)
- 實現 styling 使用的 attributes 時的定義方式, 參考[文件](https://styled-components.com/docs/api#using-custom-props)

---

### 第二十七章 - Previous APIs

- 棄用的 APIs
- `.extend`, `injectGlobal`, `innerRef`

---

Tooling

---

### 第二十八章 - Babel Plugin

- 協助 SSR, 最小化樣式檔, debug
- 安裝 `babel-plugin-styled-components`
- SSR,
- Debugging, `displayName`, `fileName`
- Minification, 可以關閉 `minify`, `transpileTemplateLiterals`
- Dead Code Elimination, 開啟 `pure` 來移除
- 更聰明的 template literals 語法轉譯到不支援的 browsers
- Namespace, 配合 `namespace` 為 class name 提供 namespace 減少 name collision 的發生 (通常在 **mircofrontend** 的情境下)

---

### 第二十九章 - Babel Marco

- ?

---

### 第三十章 - TypeScript Plugin

- `typescript-plugin-styled-components` 提供 webpack 環境下的 TypeScript plugin

---

### 第三十一章 - Jest Integration

- 安裝 `jest-styled-components` 來協助 Jest testing
- Snapshot Testing 時要載入否則會遇到 unstable class name
- `toHaveStyleRule` helper function

---

### 第三十二章 - Stylelint

- 安裝 `stylelint` 來協助 styled component linting
- linting 細節請參考[文件](https://styled-components.com/docs/tooling#stylelint)

---

### 第三十三章 - Styled Theming

- 安裝 styled component 專用的 `styled-theming` 協助建立 theme
- 更結構化的方式建立 theme object
- 範例參考[文件](https://styled-components.com/docs/tooling#styled-theming)

---

### 第三十四章 - Syntax Highlighting

- 在各家 editor 上啟動 styled component 的 CSS 高亮

---
