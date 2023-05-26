## Vite official document, v4

### [Vite](https://vitejs.dev/), ComputerScience/Front-end

---

Guide

第一章 - Why Vite

第二章 - Getting Started

第三章 - Features

第四章 - CLI

第五章 - Using Plugins

第六章 - Dependency Pre-Bundling

第七章 - Static Asset Handling

第八章 - Building for Production

第九章 - Deploying a Static Site

第十章 - Env Variables and Modes

第十一章 - Server-Side Rendering (SSR)

第十二章 - Backend Integration

第十三章 - Comparisons

第十四章 - Troubleshooting

第十五章 - Migration from v3

APIs

第十六章 - Plugin API

第十七章 - HMR API

第十八章 - JavaScript API

第十九章 - Coding Reference

Config

第二十章 - Configuring Vite

第二一章 - Shared Options

第二二章 - Server Options

第二三章 - Build Options

第二四章 - Preview Options

第二五章 - Dep Optimization Options

第二六章 - SSR Options

第二七章 - Worker Options

---

Guide

---

### 第一章 - Why Vite

The Problems

- 以盡可能使用原生 ES modules 的功能來實現更快速好用的工具

Slow Server Start

- 解決開發環境啟動過慢的問題
- Vite 把模組分成兩個類型
- Dependencies
  - 大多數是 JavaScript 並且在開發階段不會改變
  - 有些 dependencies 很大, 並且有時候使用不同的 module 格式 (ESM or CommonJS)
  - **Vite** 的 pre-bundles dependencies 流程使用 [esbuild](https://esbuild.github.io/), 一個使用 Go 撰寫的 bundler 工具, 快過於其他以 JavaScript 撰寫的 bundler
- Source code
  - 大多數不是 JavaScript 而是需要轉譯的語法 (JSX, CSS, components)
  - 在開發階段會是時常改變
  - 並不是所有的 source code 都需要在同個時間被載入 (dynamic import)
  - **Vite** 使用原生的 ESM, 讓 browser 取代 bundler 部分的工作, 並且只有在 browser 發出請求時才動態的進行處理, 不需要在同一時間處理所有的 bundle 工作

Slow Updates

- 在開發檔案越來越多的情況下, 即時更新改變的程式碼變得很慢
- **Vite** 盡可能地利用瀏覽器的功能, 包含 cache (304, Cache-Control)
- **Vite** 使用原生的 ESM 只讓修改的 module 更新至最近的 HMR boundary

Why Bundle for Production

- 儘管 ESM 已經被瀏覽器直接支援, 但是使用 unbundled ESM 檔案給瀏覽器
- 一樣會造成額外的網路效能消耗, (nested imports)
- 因此針對 Production 環境, 提前進行 bundle 工作並做最佳化, (tree-shaking, lazy-loading, common chunk splitting)

Why not Bundle with esbuild?

- **Vite** 目前的 plugin API 是改編 Rollup 的 plugin API 系統, esbuild 並無法支援
- 雖然 esbuild 的速度更快, 但是目前 **Vite** 仍在平衡效能和彈性的取捨

---

### 第二章 - Getting Started

Overview

- 一個 build tool, 目標是提供更快速簡潔的開發者體驗
- 主要來自兩個部分
  - dev server 以原生的 ES modules 為基礎提供, 豐富的功能, 例如 HMR
  - build command, 提供預設設定檔, 最佳化 production 時的資源
- 仍然可以通過 Plugin API, JavaScript API 進行客製化

Browser Support

- 編譯目標是已經原生支援 **ES Modules**, **ESM dynamic import**, `import.meta` 功能的瀏覽器
- 要支援其他舊版瀏覽器需要安裝額外的 plugin (`@vitejs/plugin-legacy`)

Trying Vite Online

- 可以在瀏覽器版嘗試使用

Scaffolding Your First Vite Project

- **Vite**, 要求 Node.js 版本在 14.18+, 16+, 有些 template 會要求更高的版本
- create-vite 工具支援多個不同的模板, 例如
- vanilla, vanilla-ts, vue, vue-ts, react, react-ts, react-swc, react-swc-ts, preact, preact-ts, lit, lit-ts, svelte, svelte-ts

Community Templates

- 也有社群版的 template 和自製 template

`index.html` and Project Root

- **Vite** 視為是一個 server 以 `index.html` 為所有前端應用程式的入口
- Vite 把 `index.html` 視為是一個 source code 作為 module graph 的一部分 (而非 public static file)
  - 讓 `index.html` 裡的 `<script type="module">`, `<link>` 都可以使用到 Vite 的功能
  - 並且會在最佳化時調整好 URL, 因此不需要再額外添加類似 `%PUBLIC_URL%` 的 placeholder
- 類似 static http servers 的想法, Vite 也有 root directory 的概念
  - 因此檔案引入的 absolute URLs 其實是依據 project root 作為基礎
  - Vite 也有支援脫離 root based 的位置, 能自動支援 monorepo 的環境
- Vite 也提供建置 multi-page apps, 因此可以使用多個 `.html` 作為不同的入口
- 以 `vite` 啟動 dev server 時, 預設以執行的當前資料夾作為 root
  - 可以提供額外的參數指定 root

Command Line Interface

- scripts:
- dev: `vite`, 開啟 dev server, 等同於指令 `vite dev`, `vite serve`
- build: `vite build`, 編譯 production 版本,
- preview: `vite preview`, 在本地端檢視 production build

Using Unreleased Commits

- 使用尚未發布的測試版 Vite
- 需要配合 pnpm 使用
- 從 git repo 拉原始碼, 進行編譯 (build) 和連結 (link)

Community

- 有 Discord 和 GitHub 可以進行討論

---

### 第三章 - Features

- 可以把 Vite 視為 static file server

NPM Dependency Resolving and Pre-Bundling

- Pre-bundle, 提升讀取速度, 轉譯 CommonJS or UMD 模組到 ESM
- Rewrite valid URLs, 改寫成瀏覽器能讀取得到的路徑
- Dependencies 使用 Cache, 依據 HTTP headers

Hot Module Replacement

- Vite 內建提供 Vue 與 React 的 HMR, 不需要額外安裝或設定

TypeScript

- 直接支援 `.ts`
- Transpile Only,
  - Vite 只進行轉譯不進行 type checking
  - 要開啟更多提示功能需要使用, `tsc --noEmit --watch` 或者安裝 `vite-plugin-checker`
- TypeScript Compiler Options
  - 在 `tsconfig.json` 裡的 `compilerOptions` 有些設定需要特別注意
  - `isolatedModules`, 必須設為 `true`
  - `useDefineForClassFields`, 預設設定為 `true`
  - 其他可能會影響編譯結果的設定, `extends`, `importsNotUsedAsValues`, `preserveValueImports`, `jsxFactory`, `jsxFragmentFactory`
- Client Types
  - 加上 `tsconfig.json` -> `compilerOptions` -> `types: ['vite/client']`
  - 會提供 Vite 功能的對應 types

Vue

JSX

- `.jsx` `.tsx` 直接支援
- JSX helpers, 以 config: `jsxInject` 開啟自動帶上 `import React from 'react'`,

CSS

- 如果專案裡有 PostCSS 設定則會自動使用
- 如果專案裡有 CSS Modules 也會自動使用
- 直接支援 `.scss` `.sass` `.less` `.styl` `stylus`

Static Assets

- import static assets 會自動轉譯成對應的 public URL
- 可以通過額外的 `?` 特殊語法指定載入的方式
  - `?url` `?raw` `?worker` `?worker&inline`

JSON

- 可以載入 `.json` 檔案變成 object,
- 同時也支援 named import (適用 tree-shaking)

Glob Import

- 通過 `import.meta.glob()` 語法載入檔案系統中的 packages
- Glob import As
  - 以 string 的方式載入
  - 以 url 的方式載入
- Multiple Patterns
  - 傳入 array
- Negative Patterns
  - 以 `!` 指定忽略特定檔案
- Named Imports
- Custom Queries
- Glob Import Caveats
  - 這個是 Vite 獨有的功能語法, 並非 web 或 ES 標準
  - 適用 fast-glob 路徑語法
  - 可以是相對路徑, 絕對路徑, 或設置 alias

Dynamic Import

- 支援 `await import()`
- 類似 Glob import

WebAssembly

- `.wasm` 可以通過 `?init` 語法進行 pre-compiled 後載入
- 使用範例參考[文件](https://vitejs.dev/guide/features.html#webassembly)

Web Workers

- 可以使用 `new Worker()` 和 `new SharedWorker()` 載入
- [參考使用範例](https://vitejs.dev/guide/features.html#web-workers)

Build Optimizations

- 自動使用的 build optimizations
- CSS Code Splitting
  - 轉換成 `<link>`
- Preload Directives Generation
  - 自動生成 `<link rel='modulepreload'>`
- Async Chunk Loading Optimization
  - 自動最佳化載入順序並以非同步的方式進行加速載入速度

---

### 第四章 - CLI

Dev server

- `vite`, 在當前目錄啟動 dev server
  - `--host`
  - `--port`
  - `https`
  - `--open`
  - `--cors`
  - `--strictPort`

Build

- `vite build`, 建置 production 版本

Others

- `vite optimize`, Pre-bundle dependencies.
- `vite preview` 在本地端預覽 production build 的版本

---

### 第五章 - Using Plugins

- 可以通過使用 **Rollup** 的 plugin 整合其他服務或者提供更多功能
  - 像是 SSR

Adding a Plugin

- 安裝 dev package, 然後再 `vite.config.js` 中設定 `plugins`

Finding Plugins

- Vite 希望提供即開即用的服務, 因此大多數功能應該已經被含在內, 先確認 Vite features 沒有支援才使用 plugin
- plugins 分成官方支援, 社群支援, Rollup 移植

Enforcing Plugin Ordering

- 為了相容一些 Rollup plugin, 可以設定 plugin 執行的時機
- 在 vite.config.js 中可以設定 plugins `enforce`

Conditional Application

- 在多數時候 plugin 會同時運作在 serve 和 build, 但是可以通過 `apply` 選擇特定時機

Building Plugins

- 參考 plugins 文件

---

### 第六章 - Dependency Pre-Bundling

- 在第一次執行 `vite` 時, 會自動進行 prebundles

The Why

- 這個流程在 vite 被稱作是 dependency pre-bundling
- 主要有兩個目的
  - CommonJS and UMD 相容,
  - Performance 效能提升, 把多個 output 轉換成多個檔案, 用來明確的指定, 以提升效能

Automatic Dependency Discovery

- 如果 cache 找不到會通過 `esbuild` 自動去尋找 package 並且更新

Monorepos and Linked Dependencies

- 作為 monorepos 會有跨 package import 的可能, 因此如果 node_modules 找不到則會變成 linked dep

Customizing the Behavior

- 可以通過 config 中的 `optimizeDeps.include` 和 `optimizeDeps.exclude`
  - 控制提早進行 pre-building 或者延後來加速啟動 dev server

Caching

- File System Cache,
  - pre-builded 檔案系統 cache 在 `node_modules/.vite`
- Browser Cache,
  - 會通過 HTTP headers `max-age=31536000,immutable`
  - 會自動進行 revalidating
  - 如果要強制破壞 cache 可以通過, 從 browser Network 中關閉 cache, 重啟 server + `--force` flag, reload 頁面

---

### 第七章 - Static Asset Handling

Importing Asset as URL

Importing Asset as String

- `?raw`

Import Script as a Worker

- `?worker`
- `?sharedworker`
- `?worker&inline`

The `public` Directory

new URL

- `new URL(url, import.meta.url)`
- `import.meta.url `
- 不支援 SSR, 因為 `import.meta.url` 在 browser 與 Node 上有不同的行為

---

### 第八章 - Building for Production

- `vite build` 預設使用 `<root>/index.html` 作為入口

Browser Compatibility

- 預設的目標瀏覽器都支援 native `ES Modules`, native `ESM dynamic import`, `import.meta`
- 可以通過 config `build.target` 設定
- vite 只會進行轉譯, 不會進行 polyfill, 需要自行安裝, 可以參考 Polyfill.io

Public Base Path

- 可以通過 config or flag `base` 改變 public 的預設路徑

Customizing the Build

- 在 config 中可以設定 `build.rollupOptions`, 採用 Rollup options

Chunking Strategy

- 可以通過 config `build.rollupOptions.output.manualChunks`
  - 依據 Rollup options 設定策略
- Vite 2.9 以後需要手動設定
  - 可以先使用 `plugins: [splitVendorChunkPlugin()]`

Rebuild on files changes

- `vite build --watch`
- 或者通過 config 設定 `build.watch`

Multi-Page App

- 需要在 config 中明確指定
  - `build.rollupOptions.input` 各自的 index.html 位置

Library Mode

- 通過 config 設定
- 讓同個 project 內有 example page 和自製的 library

Advanced Base Options

---

### 第九章 - Deploying a Static Site

- 預設輸出在 `dist`, 可以通過 config 設定 `build.outDir`
- 作為靜態網頁輸出並且部屬在常見的幾個服務上

Building the App

- `npm run build`

Testing the App Locally

- `npm run build`
- `npm run preview`

GitHub Pages

GitLab Pages and GitLab CI

Netlify

Vercel

Cloudflare Pages

Google Firebase

Surge

Azure Static Web Apps

Render

---

### 第十章 - Env Variables and Modes

Env Variables

- 通過特殊的物件 `import.meta.env` 取得
- 內建預設的幾個變數
  - import.meta.env.MODE: {string}
  - import.meta.env.BASE_URL: {string}
  - import.meta.env.PROD: {boolean}
  - import.meta.env.DEV: {boolean}
  - import.meta.env.SSR: {boolean}

Production Replacement

`.env` Files

- Vite 使用 `dotenv` library
- 因此可以把 `.env` 分成不同環境

```
.env                # loaded in all cases
.env.local          # loaded in all cases, ignored by git
.env.[mode]         # only loaded in specified mode
.env.[mode].local   # only loaded in specified mode, ignored by git
```

- 為了避免外洩環境變數, 因此給予 Vite 使用的需要加上前墜 `VITE_`
- Vite 使用 `dotenv-expand` library 因此允許使用語法連結

IntelliSense for TypeScript

- 通過設定檔案 `src/env.d.ts` 來實現環境變數的 Type

HTML Env Replacement

- 在 html 檔案裡使用環境變數替換
- `%` 來包裹環境變數名稱

Modes

- 預設, `dev` 開啟 development mode, `build` 開啟 production mode
- 也可以通過 flag `--mode` 改變
- 或者在環境變數中設定 `NODE_ENV=development`

---

### 第十一章 - Server-Side Rendering (SSR)

- 作為前後端實現 hybrid 的方案

Example Projects

- 範例以 Vue 和 React 為例

Source Structure

Conditional Logic

Setting Up the Dev Server

Building for Production

Generating Preload Directives

Pre-Rendering / SSG

SSR Externals

SSR-specific Plugin Logic

SSR Target

SSR Bundle

Vite CLI

SSR Format

---

### 第十二章 - Backend Integration

- 讓 Vite 單純作為 static assets 的 server

---

### 第十三章 - Comparisons

WMR

@web/dev-server

Snowpack

---

### 第十四章 - Troubleshooting

CLI

Dev Server

HMR

Build

Optimized Dependencies

Others

---

### 第十五章 - Migration from v3

Rollup 3

Modern Browser Baseline change

General Changes

Advanced

---

APIs

---

### 第十六章 - Plugin API

Authoring a Plugin

Conventions

Plugins config

Simple Examples

Virtual Modules Convention

Universal Hooks

Vite Specific Hooks

Plugin Ordering

Conditional Application

Rollup Plugin Compatibility

Path Normalization

Client-server Communication

---

### 第十七章 - HMR API

Required Conditional Guard

IntelliSense for TypeScript

---

### 第十八章 - JavaScript API

---

### 第十九章 - Coding Reference

---

Config

---

### 第二十章 - Configuring Vite

Configuring Vite

Config Intellisense

Conditional Config

Async Config

Using Environment Variables in Config

---

### 第二一章 - Shared Options

---

### 第二二章 - Server Options

---

### 第二三章 - Build Options

---

### 第二四章 - Preview Options

---

### 第二五章 - Dep Optimization Options

---

### 第二六章 - SSR Options

---

### 第二七章 - Worker Options

---
