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

---

### 第十一章 - Animations

---

### 第十二章 - React Native

---

Advanced

---

### 第十三章 - Theming

---

### 第十四章 - Refs

---

### 第十五章 - Security

---

### 第十六章 - Existing CSS

---

### 第十七章 - Tagged Template Literals

---

### 第十八章 - Server Side Rendering

---

### 第十九章 - Referring to other components

---

### 第二十章 - Style Objects

---

API Reference

---

### 第二十一章 - Primary

---

### 第二十二章 - Helpers

---

### 第二十三章 - Test Utilities

---

### 第二十四章 - Supported CSS

---

### 第二十五章 - Flow

---

### 第二十六章 - TypeScript

---

### 第二十七章 - Previous APIs

---

Tooling

---

### 第二十八章 - Babel Plugin

---

### 第二十九章 - Babel Marco

---

### 第三十章 - TypeScript Plugin

---

### 第三十一章 - Jest Integration

---

### 第三十二章 - Stylelint

---

### 第三十三章 - Styled Theming

---

### 第三十四章 - Syntax Highlighting

---
