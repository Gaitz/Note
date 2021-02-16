## Next.js Official Documents

### [next.js official](https://nextjs.org/), Frontend Framework/Next.js

---

Learn

第一章 - Create a Next.js App

第二章 - Navigate Between Pages

第三章 - Assets, Metadata, and CSS

第四章 - Pre-rendering and Data Fetching

第五章 - Dynamic Routes

第六章 - API Routes

第七章 - Deploying Your Next.js App

第八章 - TypeScript

Documents

第一章 - Getting Started

Basic Features

第二章 - Pages

第三章 - Data Fetching

第四章 - Built-in CSS Support

第五章 - Image Optimization

第六章 - Static File Serving

第七章 - Fast Refresh

第八章 - TypeScript

第九章 - Environment Variables

第十章 - Supported Browsers and Features

Routing

第十一章 - Introduction

第十二章 - Dynamic Routes

第十三章 - Imperatively

第十四章 - Shallow Routing

API Routes

第十五章 - Introduction

第十六章 - Dynamic API Routes

第十七章 - API Middlewares

第十八章 - Response Helpers

第十九章 - Deployment

第二十章 - Authentication

Advanced Features

第二十一章 - Preview Mode

第二十二章 - Dynamic Import

第二十三章 - Automatic Static Optimization

第二十四章 - Static HTML Export

第二十五章 - Absolute Imports and Module Path Aliases

第二十六章 - AMP Support

第二十七章 - Customizing Babel Config

第二十八章 - Customizing PostCSS Config

第二十九章 - Custom Server

第三十章 - Custom `App`

第三十一章 - Custom `Document`

第三十二章 - Custom Error Page

第三十三章 - `src` Directory

第三十四章 - Multi Zones

第三十五章 - Measuring performance

第三十六章 - Debugging

第三十七章 - Source Maps

第三十八章 - Codemods

第三十九章 - Internationalized Routing

第四十章 - Upgrade Guide

Migrating to Next.js

第四十一章 - Incrementally Adopting Next.js

第四十二章 - Migrating from Gatsby

第四十三章 - FAQ

API Reference

第一章 - CLI

第二章 - Create Next App

第三章 - next/router

第四章 - next/link

第五章 - next/image

第六章 - next/head

第七章 - next/amp

Data Fetching

第八章 - getInitialProps

next.config.js

第九章 - Introduction

第十章 - Environment Variables

第十一章 - Base Path

第十二章 - Rewrites

第十三章 - Redirects

第十四章 - Custom Headers

第十五章 - Custom Page Extensions

第十六章 - CDN Support with Asset Prefix

第十七章 - Custom Webpack Config

第十八章 - Compression

第十九章 - Runtime Configuration

第二十章 - Disabling x-powered-by

第二十一章 - Disabling ETag Generation

第二十二章 - Setting a custom build directory

第二十三章 - Configuring the Build ID

第二十四章 - Configuring onDemandEntries

第二十五章 - Ignoring TypeScript Errors

第二十六章 - exportPathMap

第二十七章 - Trailing Slash

第二十八章 - React Strict Mode

---

Learn

### 第一章 - Create a Next.js App

Next.js 是一個 React framework 有以下特色
- 頁面 Server-side routing
- 同時支援 static generation (SSG) 與 server-side rendering (SSR)
- 自動的 code splitting
- 可以配合 client-side routing
- 內建 CSS, Sass, 並且可以與任何 CSS-in-JS 工具結合
- 開發期有 fast refresh
- 支援 API routes 提供建立 API
- 高度可擴充性

官方範例
- Next.js dev mode 有自動 fast refresh (watch mode)

---

### 第二章 - Navigate Between Pages

官方範例

Pages in Next.js
- 每個頁面都會放在 `pages` 資料夾下, 並且依據路徑與檔案名稱轉換成 Route
- `pages/index.js` 即根目錄 `/` Route
- page component 可以任意命名, 重要是使用 `export default` 匯出

Link Component
- Next.js 提供 Link component `import Link from 'next/link`
- 協助頁面的 `<a>` link 到其他頁面
- 結構為
  ```javascript
  <Link href=''>
    <a></a>
  </Link>
  ```

Client-Side Navigation
- Next.js Link component 以 client-side navigation 的方式
- 使用 JavaScript 渲染新頁面並修改 history 
- 自動擁有 code splitting 只會下載該頁所需的 JavaScript
- 並且在 production mode 在 `<Link>` component 出現在 viewport 時, Next.js 會自動 prefetches 所需的 JavaScript
- Next.js 自動最佳化並且使用 `<Link>` 就不需要使用其他 routing libraries

---

### 第三章 - Assets, Metadata, and CSS

官方範例
- Next.js 內建 CSS 與 Sass

Assets
- 使用 `public` 資料夾實現靜態檔案資料取得路徑

Image component
- 使用 Next.js 提供的 Image component, `import Image from 'next/image'`
- 提供適應式圖片壓縮跟 Lazy load 等最佳化功能
- 結構範例為
  ```javascript
  <Image
    src=''
    height='' // 提供高度與寬度讓壓縮時有正確的比例
    width=''
    alt=''
  />
  ```

Metadata in `<head>`
- 使用 Next.js 提供的 `<Head>` component, `import Head from ''next/Head`
- 允許在 page component 中設置該頁的 metadata

CSS Styling
- 

---

### 第四章 - Pre-rendering and Data Fetching

---

### 第五章 - Dynamic Routes

---

### 第六章 - API Routes

---

### 第七章 - Deploying Your Next.js App

---

### 第八章 - TypeScript

---

Documents

### 第一章 - Getting Started

---

Basic Features

---

### 第二章 - Pages

---

### 第三章 - Data Fetching

---

### 第四章 - Built-in CSS Support

---

### 第五章 - Image Optimization

---

### 第六章 - Static File Serving

---

### 第七章 - Fast Refresh

---

### 第八章 - TypeScript

---

### 第九章 - Environment Variables

---

### 第十章 - Supported Browsers and Features

---

Routing

---

### 第十一章 - Introduction

---

### 第十二章 - Dynamic Routes

---

### 第十三章 - Imperatively

---

### 第十四章 - Shallow Routing

---

API Routes

---

### 第十五章 - Introduction

---

### 第十六章 - Dynamic API Routes

---

### 第十七章 - API Middlewares

---

### 第十八章 - Response Helpers

---

### 第十九章 - Deployment

---

### 第二十章 - Authentication

---

Advanced Features

---

### 第二十一章 - Preview Mode

---

### 第二十二章 - Dynamic Import

---

### 第二十三章 - Automatic Static Optimization

---

### 第二十四章 - Static HTML Export

---

### 第二十五章 - Absolute Imports and Module Path Aliases

---

### 第二十六章 - AMP Support

---

### 第二十七章 - Customizing Babel Config

---

### 第二十八章 - Customizing PostCSS Config

---

### 第二十九章 - Custom Server

---

### 第三十章 - Custom `App`

---

### 第三十一章 - Custom `Document`

---

### 第三十二章 - Custom Error Page

---

### 第三十三章 - `src` Directory

---

### 第三十四章 - Multi Zones

---

### 第三十五章 - Measuring performance

---

### 第三十六章 - Debugging

---

### 第三十七章 - Source Maps

---

### 第三十八章 - Codemods

---

### 第三十九章 - Internationalized Routing

---

### 第四十章 - Upgrade Guide

---

Migrating to Next.js

---

### 第四十一章 - Incrementally Adopting Next.js

---

### 第四十二章 - Migrating from Gatsby

---

### 第四十三章 - FAQ

---

API Reference

### 第一章 - CLI

---

### 第二章 - Create Next App

---

### 第三章 - next/router

---

### 第四章 - next/link

---

### 第五章 - next/image

---

### 第六章 - next/head

---

### 第七章 - next/amp

---

Data Fetching

---

### 第八章 - getInitialProps

---

next.config.js

---

### 第九章 - Introduction

---

### 第十章 - Environment Variables

---

### 第十一章 - Base Path

---

### 第十二章 - Rewrites

---

### 第十三章 - Redirects

---

### 第十四章 - Custom Headers

---

### 第十五章 - Custom Page Extensions

---

### 第十六章 - CDN Support with Asset Prefix

---

### 第十七章 - Custom Webpack Config

---

### 第十八章 - Compression

---

### 第十九章 - Runtime Configuration

---

### 第二十章 - Disabling x-powered-by

---

### 第二十一章 - Disabling ETag Generation

---

### 第二十二章 - Setting a custom build directory

---

### 第二十三章 - Configuring the Build ID

---

### 第二十四章 - Configuring onDemandEntries

---

### 第二十五章 - Ignoring TypeScript Errors

---

### 第二十六章 - exportPathMap

---

### 第二十七章 - Trailing Slash

---

### 第二十八章 - React Strict Mode

---

78 = 8 + 42 + 28