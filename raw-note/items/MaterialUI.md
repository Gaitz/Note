## Material-UI official documents

### [Material-UI](https://material-ui.com/), Frontend/UI

---

第一章 - Getting Started

第二章 - Components

第三章 - Component API

第四章 - Styles

第五章 - System

第六章 - Customization

第七章 - Guides

第八章 - Discover More

第九章 - Versions

---

### 第一章 - Getting Started

Install

- NPM/Yarn, `@material-ui/core`
- Roboto Font, Font Icons, SVG Icons, 要額外安裝

Usage

- Material-UI Component 不用額外依據其他 CSS file. 每個元件可以獨立運作並且只使用需要的樣式檔
- Quick Start
- Globals, 
  - Material-UI 採用 mobile-first 設計, 記得加上 `<meta name="viewport" content="minimum-scale=1, initial-scale=1, width=device-width" />`
  - Material-UI 提供選用的 `CssBaseline`, 類似 `normalize.css`
- Versions and Documents, 每個版本有各自的文件, 提供最準確的資訊

Example Projects

- Official examples, 使用在各種 React 相關框架的範例
- 付費的 themes & templates
- 免費的範例

React Templates

- 免費的範例, Dashboard, Sign In, Sign-in side, Sign Up, Blog, Checkout, Album, Pricing, Sticky footer
- 付費的 themes

Learn Material-UI

- First Example, Example Projects, Templates,
- Recommended resources, 免費的教學影片與文章
- 付費的文章, 課程, 書籍

FAQ

Supported Components

Supported Platforms

- 支援多數主流的瀏覽器
- 支援 server-side rendering 因此支援 Node.js 
- 提供 CSS prefixing, 參考程式碼[範例](https://material-ui.com/getting-started/supported-platforms/#css-prefixing)
- Material-UI 支援 React 16.8.0 以上的版本
- Material-UI 需要最小版本 3.2 以上的 TypeScript

Support

- 社群支援, StackOverflow, GitHub, Blog, Resources, Twitter, 
- 付費支援

---

### 第二章 - Components

#### Layout

Box

Container

Grid
- 12格線 grid layout
- 採用 Flexbox

Grid List
- 通常用來展示連串的圖片

Hidden
- 可以設置斷點的隱藏

#### Inputs

Button

Button Group
- 相關的按鈕集合

Checkbox

Floating Action Button
- 浮動的按鈕通常用於最常見的功能

Date / Time pickers

Radio

Select

Slider
- 數值拉條

Switch
- 開關

Text Field
- 文字表單

Transfer List
- 選單轉換

#### Navigation

Bottom Navigation
- 3 ~ 5 個在 App 底端的移動按鈕

Breadcrumbs
- 可與 React-Router 整合

Drawer
- 上下左右滑出的 Navigation

Link
- 可客製化的 Link

Menu
- 暫時性彈出的選單

Stepper
- 線性與非線性的步驟移動

Tabs
- 基本的 tabs

#### Surfaces

App Bar
- 展示當前頁面資訊與互動的 App bar

Paper
- 方框背景

Card
- 包含內容與動作的單一小卡

Accordion
- 展開隱藏的資訊區塊

#### Feedback

Progress
- 進行中的 CSS 動畫

Dialog
- 彈出式視窗 (modal), 會暫停其他視窗的功能

Snackbar
- 暫時性的訊息 (toast)

Backdrop
- 提供背景遮罩 (shadow)

#### Data Display

Avatar
- 頭像, 圖, 文字, Icon 皆可

Badge
- 可顯示資訊的 badge 

Chip
- 可互動的資訊碎片, `onClick`, `onDelete`

Divider
- 集合資訊成清單

Icons
- 提供三種方式應用 Icons
  - 標準 SVG icons, `@material-ui/icons`
  - 客製化使用的 Wrapper `SvgIcon`, SVG icons
  - 客製化使用的 Wrapper `Icon`, font icons

Material Icons
- 官方提供的 SVG icons 庫

List

Table
- 可以客製化的資料 table

Tooltip
- 提供 hover, tab, focus 時的浮動資訊, 類似 `alt` 的功能

Typography
- 提供特殊字體的文字資訊

#### Utils

Click Away Listener
- 監聽元素外部的 click 事件

CSS Baseline
- 提供類似 `normalize.css` 的功能, 分成 Global 跟 Scope 版本

Modal
- 彈出視窗資訊, `open`, `onClose`

No SSR
- 減少在 server-side 的工作, 可以配合 `defer` 推遲渲染時機

Popover
- 點擊後在元素旁的彈出, 基於 `Modal`, 彈出時會阻擋 scroll ,點擊外部會消失.

Popper
- 類似於 Popover, 但是彈出時不會阻擋 scroll, 基於第三方函式庫 `Popper.js`

Portal
- 渲染子代到指定的 container 中, 基於 `Modal`, `Popper`

Textarea Autosize
- 會依據內容自動調整 input textarea 的 block size

Transitions
- 提供容易使用的元素顯示動畫, Collapse, Fade, Grow, Slide, Zoom

useMediaQuery
- 依據 Media Query 決定是否渲染, `useMediaQuery` 回傳 boolean, 支援 Server-side rendering 基於 User agent, Client hints.

#### Lab

About The Lab
- 實驗性的 component, 與 core library 分開, `@material-ui/lab`

Alert

Autocomplete

Data Grid

Pagination

Rating

Skeleton

Speed Dial

Timeline

Toggle Button

Tree View

---

### 第三章 - Component API

- 各 Component 的 API 文件, 包含 `@material-ui/core`, `@material-ui/lab`

---

### 第四章 - Styles

#### Basics

- `@material-ui/styles` library, 可獨立於 Material-UI component 使用
- 為了保持 Material-UI 的純粹性, 把 styling solution 切成另外選用的 package.

Why use Material-UI's styling solution?

- 舊版使用 LESS, 但是功能有限, 因此實作另外一個 CSS-in-JS 解決方案
- 快速, 應用 JavaScript 的能力, 類似於 styled-components

Installation

- 只有當不與 Material-UI component 一起使用時才需要獨立安裝 `@material-ui/styles`

Getting started

- 三種應用方式, 底層使用一樣的邏輯, 
- Hook API
- Styled components API
- Higher-order component API

Nesting selectors

- 多層 CSS selectors

Adapting based on props

- Styles 通過 props 傳入變數使用

`@material-ui/core/styles` vs `@material-ui/styles`

- `@material-ui/core/styles`, 含有 default theme
- `@material-ui/styles`, 沒有 default theme

#### Advanced

Theming
- 類似 context 把 theme object 傳遞給各層的 style 使用
- `import { ThemeProvider } from '@material-ui/core/styles'`
- `import { useTheme } from '@material-ui/core/styles'`
- Nested theme 要手動處理 context 複製

Overriding styles - `classes` prop
- 使用 `makeStyles` hook API, `withStyles` HOC API 要附寫同名 className 時的傳遞方式
- 參考[範例](https://material-ui.com/styles/advanced/#overriding-styles-classes-prop)

JSS plugins
- 可以 cherry-pick 想要使用的 plugins, 
- 可以選用官方的 plugins 在 `import { jssPreset } from '@material-ui/core/styles'` 

String templates
- 可以配合 `jss-plugin-template` 使用 string templates 撰寫 CSS, 取代 styles object 的方式

CSS injection order
- 預設 Material-UI style 會被放置在 `<head>` 的最後, 也是在其他的 style tag 之後.
- 可以通過 `StylesProvider` 參數 `injectFirst` 放置在 `<head>` 開始處
- `insertionPoint`, JSS plugin 可以控制 CSS 順序, 參考[範例](https://material-ui.com/styles/advanced/#insertionpoint)

Server-side rendering
- 使用 `import { ServerStyleSheets } from '@material-ui/core/styles'` 生成 SSR 所需的 inline style

Class names
- 預設使用 `@material-ui/core/styles` class name 是含有 id hash 的, 因此每次可能不同.
- 使用 `@material-ui/core` 生成的 class name 是固定的

Global CSS
- 使用 `jss-plugin-global` 生成 global class name

CSS prefixes
- JSS 會自動偵測 feature 並且加上必要的 prefix

Content Security Policy (CSP)
- 利用 HTTP header `Content-Security-Policy` 提供允許執行的網域清單, 協助瀏覽器防止 XSS 攻擊
- 參考[說明](https://material-ui.com/styles/advanced/#what-is-csp-and-why-is-it-useful)

How does one implement CSP?
- 使用 Material-UI (and JSS) 時的 CSP 處理, 需要使用 nonce (隨機字串)
- 參考[範例](https://material-ui.com/styles/advanced/#how-does-one-implement-csp)

#### API

`createGenerateClassName()`
- 可客製化的 class name 生成器

`createStyles()`
- 提供 TypeScript 使用的 Type 驗證

`ServerStyleSheets`
- SSR 的 helper

`makeStyles()`
- Hook pattern

`styled()()`
- Styled components pattern

`withStyles()`
- Higher-order component (HoC) pattern

`withTheme()`
- Higher-order component (HoC) pattern 提供 theme object

---

### 第五章 - System

Basics
- `@material-ui/system`
- 使用 styled component 建立一致性的 design system
- 參考[範例](https://material-ui.com/system/basics/)

Borders
- 快速設置 borders CSS

Display
- 快速設置 Display 可配合 media query 使用
- `inline`, `block`, Hiding elements, Display in print, Overflow, Text Overflow, Visibility, White Space

Flexbox
- 快速設置 Flexbox 相關設定

Palette
- 有語意的顏色設定

Positions
- 快速設定 z-index

Shadows
- 快速設定 shadows

Sizing
- 快速設定 `width`, `height` 相關數值

Spacing
- 快速設定 `margin`, `padding` 相關數值

Typography
- 快速設置 `font` 相關數值

API
- `@material-ui/system` package

---

### 第六章 - Customization

Theming
- 建立客製化的 theme 保持一致性的樣式, 利用 `ThemeProvider` context 傳遞
  - 設定包含 Palette, Typography, Spacing, Breakpoints, z-index, Globals
  - API [reference](https://material-ui.com/customization/theming/#api)
- Palette 設置與預設值
- Typography 設置與預設值
- Spacing 設置與預設值
- Breakpoints 設置與預設值
- Density 設置與預設值
- z-index 設置與預設值
- Globals 設置與預設值

Components
- 客製化 component
- 不同的方式複寫樣式

Color
- 提供具有語意的顏色名稱
- 建立 color system 的[教學](https://material.io/design/color/the-color-system.html)

Default Theme
- 預設 theme 的各項設定值

---

### 第七章 - Guides

API Design Approach
- Component API 設計思想, 正確, 一致性, 盡可能簡單
- Rules
  - Spread, 
  - Native properties, 
  - CSS Classes, 
  - Nested components,
  - Property naming,
  - Controlled components, 
  - Boolean vs enum, 採用選項只有兩個時使用 boolean 設計, 多個時採用 enum 設計
  - Ref, 

TypeScript
- 支援使用 TypeScript
- 配合 `withStyles` 使用時, 需要額外的技巧
- 客製化 `Theme` 時增加屬性需要做 `declare module`
- 配合 `component` prop 使用時, 需要額外的處理, (主要用在 component composition)
- 處理 `value` 與 event handlers 的型別

Style Library Interoperability
- 使用其他的 CSS 樣式解決方案, 有範例說明
- Plain CSS, 
- Global CSS,
- Styled Components,
- CSS Modules,
- Emotion
- React JSS,

Minimizing Bundle Size
- Material-UI 對 Bundle size 嚴格審視, 並且採用 `dangerJS` 整合 CI 在每次 PR 時檢測 bundle size
- Material-UI 可以配合 bundler 直接使用 tree-shaking
- 開發期的 import 效能問題, 有兩個解決方案 
  - 使用路徑 + 預設 import 取代 top level imports
  - 使用 Babel plugin, `babel-plugin-import`, `babel-plugin-transform-imports` 後可以繼續採用 top level imports.

Composition
- Wrapping components
  - 除了傳遞 props 外, 需要針對 `muiName` prop 作手動複製
- `component` prop, 
  - Material-UI 允許使用 `component` prop 更變掛載的 element
  - 注意 inline function component 傳遞時造成的不必要 re-rendering, 可以用 `useMemo()` 解決, 參考[範例](https://material-ui.com/guides/composition/#caveat-with-inlining)
  - 使用自動的 prop forwarding 機制簡化程式碼, 要小心 prop 同名問題.
- Routing libraries, 整合 client-side routing 工具, 以 `react-router` 為[範例](https://material-ui.com/guides/composition/#routing-libraries)
- 整合 Material-UI component 時遇到的 React `refs`, StrictMode warning 解決方案

Server Rendering
- Server-side rendering 時的設置流程與各框架的範例

Responsive UI
- Material-UI 推薦針對各種平台使用統一的 elements
- 實現方式有提供以下幾種 helpers
  - Grid, 會依照螢幕大小改變大小與展示順序
  - Container, 最基礎的水平容器
  - Breakpoints, 客製化 breakpoint API
  - useMediaQuery, CSS media query hook 
  - Hidden, 針對裝置作視覺隱藏
- 參考[文件](https://material-ui.com/guides/responsive-ui/)

Migration From v3
- 版本更新的實務與說明

Migration From v0.x to v1
- 版本更新的實務與說明

Testing
- Material-UI 內部有覆蓋律非常高的測試
- 範例測試使用 `Mocha`
- 分成三種測試有對應的 API 支援 `@material-ui/core/test-utils'`
  - `createMount()` Full DOM rendering
  - `createShallow()` Shallow rendering
  - `createRender()` Render to string

Localization
- 預設語系是 English (US)
- Locale text 有預設的翻譯, 可以通過 `'@material-ui/core/locale'` 取得
- 參考支援語言[列表](https://material-ui.com/guides/localization/#supported-locales)

Right-to-left
- 因應由右至左的語系, 可以通過設定讓 Material-UI components 配合順序

Flow
- 由社群開源支援 flow-typed

---

### 第八章 - Discover More

Showcase
- 實際案例

Related Projects
- 可以一起使用的第三方專案或工具

Roadmap
- 專案開發方向地圖, 優先順序, 包含開發中的新 component 列表與實現階段

Sponsors & Backers
- 社群出資的開源專案, MIT license

Vision
- 願景: 提供優雅的 React 實作的設計準則並且能充分的客製化符合需要
- 提供一般性, 被廣泛使用的 UI 庫

Team
- 核心團隊與社群貢獻者

Changelog
- 版本 changelog

Languages
- 各語言翻譯的文件

---

### 第九章 - Versions

Released versions

- 每個版都有各自的 documentation 與 release note

Latest versions

- 可以從 `master`, `next` branch 取得 source code 與 documentation

Versioning strategy

- 版本開發已穩定性為主, 盡可能的重用, 不任意棄用, 對未來的規劃都是可預期更變.
- 版本號依據 Semantic Versioning 2.0.0 規則

Release frequency

- Major 一年一次, 
- Minor 每個 Major 約 1-3 個
- Patch 每週或任何需要時

Deprecation practices

- 棄用準則, 最小化, 會有移植工具協助
- 會宣佈在 changelog, 甚至 runtime 會有警告
- 會提供最佳的轉換方式
- 相依性函式庫的更新只會發生在 Major 版本

---

