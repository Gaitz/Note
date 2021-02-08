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

Overriding styles - `classes` prop

JSS plugins

String templates

CSS injection order

Server-side rendering

Class names

Global CSS

CSS prefixes

Content Security Policy (CSP)

#### API

---

### 第五章 - System

---

### 第六章 - Customization

---

### 第七章 - Guides

---

### 第八章 - Discover More

---

### 第九章 - Versions

---

