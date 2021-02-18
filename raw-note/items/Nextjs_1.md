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
- 原生支援 `styled-jsx`, 並且可以使用任意 CSS-in-JS 工具 (需另外設置)
- 原生支援 import CSS 與 Sass, 並且支援 CSS Modules
- Next.js code splitting 也支援 CSS Modules 讓 CSS bundle size 最小化
- `pages/_app.js`, 可以影響所有 pages 的檔案入口, 用來引入 global state 與 global CSS 的地方

Styling Tips
- 可以使用 `classnames` [函式庫](https://github.com/JedWatson/classnames)協助修改 className, `cn()`
- Next.js 自動使用 `PostCSS`, 可以額外客製化 PostCSS config
- Next.js 原生支援 Sass 並且可以同時使用 CSS modules 與 Sass, `.module.sass`

---

### 第四章 - Pre-rendering and Data Fetching

Pre-rendering
- Next.js 預設每一頁都會 pre-renders, 到瀏覽器後在 hydration
- 提昇 performance 與 SEO
- 兩種類型的 pre-rendering, Static Generation (SSG), Server-side Rendering (SSR)
- Static Generation 在 `build time` 完成後每個 request 提供相同的 HTML
- Server-side Rendering 在每次 request 後才生成專屬的 HTML
- Next.js 允許每頁使用不同的 pre-rendering 方式
- 推薦優先使用 Static Generation 提供更好的效能, 頁面與使用者請求無關的時候.

Static Generation with and without Data
- 取決於在 build time 是否需要 request 外部資料
- 頁面輸出 `getStaticProps` async function, `export async function getStaticProps() {}` 會在 build time 被觸發, 並且以 `props` 傳遞給 page component
- 參考[範例](https://nextjs.org/learn/basics/data-fetching/with-data)
- `getStaticProps` 只能使用在 `page` 即 `pages/` 下的 page component, 並且只會在 server-side 執行
- 如果資料需要依據 request 才能取得則可以考慮使用 SSR 或直接 client-side 時 request

Server-side Rendering with Data
- 使用 `getServerSideProps` async function, `export async function getServerSideProps(context) {}`
- 這樣在每次 request 時都會在 server-side 執行一次 `getServerSideProps()`
- 速度會慢於 Static Generation 

Client-side Rendering
- 不使用 pre-rendering 在 server-side 取值, 交給瀏覽器發送 request
- 通常用於與 SEO 無關且隨時間變動的資料
- Next.js 提供一個被優化的 React Hook, `SWR` 協助在 client-side 讀取資料

Other Tips:
- markdown 可以提供 metadata 藉由 `gray-matter` library 提供 parse 取得.
- Next.js 內建 `fetch()` polyfills 提供 client 與 server 同時使用.

---

### 第五章 - Dynamic Routes

Page Path Depends on External Data
- 依據外部資料的頁面路徑
- 在 `pages/` 目錄下使用 `[`, `]` 作為檔名的一部分產生 dynamic routes
- 配合 `getStaticPaths` async function, 取得 dynamic route 資訊, 必須配合 `params` key 與 `paths` key
- Dynamic Routes + Static Generation
  1. `getStaticPaths` 解析 dynamic path 並且回傳資訊
  1. `getStaticProps` 依據解析後的資訊 `params`, 取值
- Catch-all Routes, `[...]` 可以捕捉所有的子代 Routes
- 可以藉由 `next/router` 提供的 `useRouter` hook 操作 Next.js Router
- 新增 `pages/404.js` 可以創建客製化的 404 頁面

Other Tips
- Markdown to HTML 可以使用 `remark`, `remark-html` 兩個 library 
- Date formatting 可以使用 `date-fns` library

---

### 第六章 - API Routes

API Routes
- 可以在 `pages/api/`, 形成基本的 API endpoint
- 配合 `export default function handler (req, res) {}`
- API endpoint 也可以如同 pages 一般使用 dynamic route

---

### 第七章 - Deploying Your Next.js App

Tips:
- `Vercel` 平台由 Next.js 作者開發的部屬平台
- `Vercel` 有很多好處, 
  - 包含配合 GitHub 產生 Preview 版本,
  - 自動 Https, 
  - SSG 形成 CDN, 
  - SSR 與 API 形成 serverless function 更容易 scale
  - ...
- Next.js App 可以部屬在任何支援 Node.js 的環境上
  - 配合 `npm run build`, `npm run start` 指令啟動 server

---

### 第八章 - TypeScript

Next.js + TypeScript
- Next.js 可以直接支援 TypeScript
- 創建 `tsconfig.json` 重啟 dev server 後會提醒安裝所需的 packages
- 可以從 `next` 中取得 Next.js 所配合的 Types, 例如 `GetStaticProps`, `GetStaticPaths`, `GetServerSideProps`, ...

---

Documents

### 第一章 - Getting Started

系統需求
- Node.js 10.13 以上
- MacOS, Windows, Linux

Setup
- 推薦使用 `create-next-app` 快速建立

Manuel Setup
- 需安裝 `next`, `react`, `react-dom` packages
- Script 則是 `next dev` 啟動開發模式, `next build` 編譯, `next start` 開啟 production 伺服器

---

Basic Features

---

### 第二章 - Pages

- Page 是一個輸出 React component 放在 `pages/` 目錄下的 `js`, `jsx`, `ts`, `tsx` 檔案
- Routing 則是依據檔案名稱

Pre-rendering
- 預設 pre-renders 所有的頁面
- 分成兩類 Static Generation (SSG), Server-side Rendering (SSR)
- SSG 配合外部資源時 `getStaticProps`, `getStaticPaths`
- SSR 配合外部資源時 `getServerSideProps`

---

### 第三章 - Data Fetching

`getStaticProps` (Static Generation)
- 結構
  ```javascript
  export async function getStaticProps(context) {
    return {
      props: {},
    }
  }
  ```
- 傳入的 `context` 物件, 可以取得 route 資訊, preview mode 資訊, locale 資訊
- 傳出的物件必須包含 `props`, 
  - 其他選用的 `revalidate`, `notFound`, `redirect`

Incremental Static Regeneration
- 配合 `revalidate` key 設置重新生成資料的時間
- 由於 static generation 一般是由 build time 生成一次, 現在可以自動 regeneration 並且不需要重新 build
- 享有好處, 
  - 頁面效能跟 static generation 一樣快, 
  - 就算 regeneration 的資料失敗, 仍然有舊版的可以使用不會停止服務
  - 讀取資料的效能仍就是一次, 並不會依據 request 數量造成後端負擔

使用檔案系統讀檔時, 使用 `process.cwd()` 取代 `__dirname`

`getStaticPaths` (Static Generation)
- 執行 dynamic route
- 結構
  ```javascript
  export async function getStaticPaths() {
    return {
      paths: [
        { params: {} }
      ],
      fallback: true or false or 'blocking'
    }
  }
  ```
- 必須含有 `paths` key, 對應解析的 dynamic routes, 參考[文件](https://nextjs.org/docs/basic-features/data-fetching#the-paths-key-required)
- 必須含有 `fallback` key, 
  - `false` 會有 404 頁, 
  - `true` 則需處理 fallback 頁, 可以在失敗時回應讀取中的資訊給使用者, 並且等候 `getStaticProps` 完成
  - `'blocking'`, 等於一次性的 SSR 

`getServerSideProps` (Server-side Rendering)
- SSR 取得外部資料的方式
- 結構
  ```javascript
  export async function getServerSideProps(context) {
    return {
      props: {}
    }
  }
  ```
- 傳入的 `context` 物件, 可以取得 route 資訊, `req`, `res`, preview mode 資訊, locale 資訊
- 回傳的物件必須包含 `props`,
  - 選用的 `notFound`, `redirect`

Client-side rendering 
- 在瀏覽器端取值, 可以使用 Next.js 提供的 hook, `SWR`, 有內建很多實務

---

### 第四章 - Built-in CSS Support

- 可以單純使用 `import` 傳入 CSS 檔案

Global Stylesheet
- 所有頁面共用的樣式可以在 `pages/_app.js` 中傳入

Import styles from `node_modules`
- 可以從 packages 中直接 import CSS 檔案

Component-Level CSS
- Next.js 原生支援 CSS Modules, 只需要使用檔名 `.module.css`

Sass Support
- Next.js 原生支援 Sass, 並且可以配合 CSS Modules 使用
- 可以直接 import, `.scss`, `.sass`, `.module.scss`, `.module.sass`
- 可以在 `next.config.js` 中使用 `sassOptions` 客製化設定

Less and Stylus Support
- 需要另外安裝 plugins

CSS-in-JS
- 可以參考各種[範例](https://nextjs.org/docs/basic-features/built-in-css-support#css-in-js)包含 `Styled JSX`, `Styled Components`, `Emotion`, `Tailwind CSS + Emotion`, `Styletron`, `Glamor`, `Cxs`, `Aphrodite`, `Fela`

---

### 第五章 - Image Optimization

Image Component
- Next.js 10.0.0 以上提供內建的 `Image` component 提供很多最佳化
- `import Image from 'next/image'`
- 最佳化會觸發在需要時, 支援任一種圖片格式
- 可以在 `next.config.js` 中客製化圖片最佳化的設定, 包含
  - Domains, 作用的網域
  - Loader, 使用第三方的圖片最佳化工具

Caching
- 使用預設的 loader 時 expired time 由 `Cache-Control` header 控制

Advanced
- Device Sizes, 手動設置 breakpoints, 使用在 `layout='responsive'`, `layout='fill'`
- Image Sizes, 手動設置 breakpoints, 使用在 `layout='fixed'`, `layout='intrinsic'`

---

### 第六章 - Static File Serving

Static File Serving
- 把靜態資源放在 `public/` 目錄下則可以從外部 request
- routes 在 `/` 根目錄下, 要注意不要與 `pages` routes 相同
- 只有 build time 時的靜態資源可以讀取得到, 因此無法在 runtime 增加新的靜態資源服務

---

### 第七章 - Fast Refresh

- 在 development mode 可以快速的取得變動的內容, 並且不會讓之前的 component state 消失
- 限制, 
  - Fast Refresh 時的 state 保存並不作用於 class component
  - HoC 修改也會損失 state
  - `export default () => {}` 配合匿名函式時也不會保存 state
- 可以使用 `// @refresh reset` 啟動 reset 而非保存 state

---

### 第八章 - TypeScript

- Next.js 原生支援整合 TypeScript 使用
- 只要在根目錄新增 `tsconfig.json` 並且重新執行 `npm run dev` 後會告知所需的 packages 並且 setup 基本的 tsconfig
- TypeScript `strict` mode 預設是 false, 推薦依據專案在合適的時候改成 `true`

---

### 第九章 - Environment Variables

Loading Environment Variables
- 藉由 `process.env` 讀取環境變數, 檔案為 `.env.local`
- `process.env` Next.js 因為安全性會轉換, 因此無法使用 object destructuring 取值

Exposing Environment Variables to the Browser
- 因為安全性, 讀取的環境變數, 只有在前綴為 `NEXT_PUBLIC_` 時才能被 client-side code 讀取得到

Default Environment Variables
- 預設只有一個 `.env.local` 但是可以依據所需可以分成 `.env.development`, `.env.production`
- 記得 `.env*.local` 需要加到 `.gitignore` 中

Test Environment Variables
- 測試環境中 `NODE_ENV` 設為 `test` 時, `.env.local` 環境資訊並不會被讀取
- 而是使用 `.env.test`

---

### 第十章 - Supported Browsers and Features

Supported Browsers
- 支援 IE11 和所有現代的瀏覽器 

Polyfills
- 針對 IE11 所用的 `fetch()`, `URL`, `Object.assign()`
- 只有在需要時才會被使用, 因此不用擔心 bundle size

Server-Side Polyfills
- Next.js 支援在 Node.js 上使用 `fetch()`, 不需要額外使用 polyfills

JavaScript Language Features
- 支援所有最新版的功能

TypeScript Features
- Next.js 原生支援 TypeScript

Customizing Babel Config (Advanced)
- 可以客製化 Next.js 所使用的 babel 設定

---

Routing

---

### 第十一章 - Routing Introduction

- 依據 `pages/` 檔案路徑作為 Routing 設定

Index Routes
- `index` 會被自動轉為根目錄 `/`

Nested Routes
- 依據目錄可以生成 nested routes

Dynamic Route Segments
- 使用 `[]` 與 `[...]` 作為 dynamic routes

Linking between pages
- Next.js 提供 `Link` component 實現 client-side routing 技術
- 不需要其他第三方工具例如 React Router

Linking to dynamic paths
-

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