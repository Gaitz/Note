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

第四十一章 - Migrating to Next.js

第四十二章 - FAQ

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
- 有兩種方式, 直接使用路徑, 或者使用 URL object, [範例](https://nextjs.org/docs/routing/introduction#linking-to-dynamic-paths)

Injecting the router
- 使用 `useRouter` hook 取得 router

---

### 第十二章 - Dynamic Routes

- 藉由 `[]` 命名配對 dynamic routes 
- 可以從 `useRouter` hook 中取得 `query` object 拿到參數
- 使用 `[...param]`, 取得所有子代的 dynamic route, 此時 `query` object 參數會用 array 儲存
- Route 碰撞時, 優先順序為實名 Route, Dynamic Route (`[]`), catch all Route (`[...]`)

---

### 第十三章 - Imperatively

- 一般情況 client-side routing 使用 `next/link` 即可完成
- 特殊情況可以通過 `useRouter` 取得 router 後操作 client-side routing, 例如 `router.push()`

---

### 第十四章 - Shallow Routing

- Shallow Routing, 在同一頁面上以 `useRouter` hook 的 `push()` 作 navigation 時, 可以開啟 shallow 參數 `{ shallow: true }` 以這種方式移動時, 頁面不會被更新也不會再次觸發 `getServerSideProps`, `getStaticProps`, `getInitialProps` 等等, 可以保留頁面狀態 (state)
- Shallow Routing 只是用於同一個 URL 時, 即 query 可以不同

---

API Routes

---

### 第十五章 - API Routes Introduction

- API Routes 提供直接的方式建立 API
- 在 `pages/api/` 下的 Route 會對應到 `/api/`
- 結構
  ```javascript
  export default function handler(req, res) {}
  ```
- 預設的 API Routes 不會特別設置 CORS headers, 預設是 same-origin only. 其他 CORS 設置要配合 middleware 使用

---

### 第十六章 - Dynamic API Routes

- Dynamic API Routes 等同於 Dynamic Page Routes 規則

---

### 第十七章 - API Middlewares

- Next.js 有預設使用 `req.cookies`, `req.query`, `req.body` middleware 協助 parsing
- 每個 API Route 都可以使用 `export const config = {}` 的方式自訂 config
- 可以配合 express middleware 使用, 參考[文件](https://nextjs.org/docs/api-routes/api-middlewares#connectexpress-middleware-support)

---

### 第十八章 - Response Helpers

- `res` 包含了一系列的 Express-like 函式協助建立 API
- `res.state(code)`, 設定狀態碼
- `res.json(json)`, 回傳 JSON
- `res.send(body)`, 設置回傳 body
- `res.redirect([status,] path)`, 使用 redirect, 預設狀態碼為 `307`

---

### 第十九章 - Deployment

- 推薦使用 Vercel 平台, 由 Next.js 作者建立的部屬平台, 包含很多最佳化實務.
- 或者任意可執行 Node.js 的平台

---

### 第二十章 - Authentication

Authentication Patterns
- 依據資料獲取的時機, client-side or server-side

Authenticating Statically Generated Pages
- SSG + Client-side fetching data

Authenticating Server-Rendered Pages
- SSR + `getServerSideProps` 取得授權
- 要注意 `getServerSideProps` 取得授權會 block response, 因此要足夠快才行

Bring Your Own Database
- 如果已經有使用的權限資料庫, 可以配合權限機制使用不同的 Next.js packages
- 參考[文件](https://nextjs.org/docs/authentication#bring-your-own-database)

Firebase
- 如果使用 Firebase 時推薦使用 SSG + client-side fetching 的模式
- 可以配合 Firebase Client SDK 或 FirebaseUI

Others
- `Magic`, `Auth0`, `Supabase`, `Userbase`, ..., 參考說明[文件](https://nextjs.org/docs/authentication#magic-passwordless)

---

Advanced Features

---

### 第二十一章 - Preview Mode

- SSG 配合 headless CMS 使用時的資料 Preview Mode 設定

---

### 第二十二章 - Dynamic Import

- dynamic `import()` 在需要時才載入模組, 提高更好的效能
- 可以使用 Next.js 提供的 `import dynamic from 'next/dynamic'` 協助封裝成 dynamic component
- 可以客製化加上 loading component
- 可以選用 NoSSR 在 server-side 不會額外載入

---

### 第二十三章 - Automatic Static Optimization

- 在沒有 `getServerSideProps`, `getInitialProps` 需要 SSR 時, Next.js 會自動使用 statically optimization 預先渲染成 static HTML 並且重複使用
- 在 build time 頁面會建置在 `.next/server/pages/` 下, Static Optimization 會產生 `html`, 如果是需要 SSR 時會產生 `js`

---

### 第二十四章 - Static HTML Export

- 使用 `next export` 可以生成純 HTML 檔案, 而不需要配合 Node.js server 使用
- 用於整個 Next 專案都不需要 SSR 時, 整個 App 為純 client-side 使用.
- `next build && next export` 會生成在 `out/` 資料夾下
- 使用時要注意有些 Next.js 的功能沒有完全運作, 參考[文件](https://nextjs.org/docs/advanced-features/static-html-export#caveats)

---

### 第二十五章 - Absolute Imports and Module Path Aliases

- Next.js 支援 `tsconfig.json`, `jsconfig.json` 的 `paths`, `baseUrl` 選項
- 因此可以配合使用達到 module import 的縮寫
- 參考[範例](https://nextjs.org/docs/advanced-features/module-path-aliases)

---

### 第二十六章 - AMP Support

- Next.js 支援轉換成 AMP page 的功能
- 藉由 `next/amp` 啟動
- styling 只有 CSS-in-JS 支援, CSS Modules 沒有支援 AMP 轉換
- AMP 也尚未與 TypeScript 作整合, 但是未來可能會支援
- 參考[細節](https://nextjs.org/docs/advanced-features/amp-support/introduction), 使用 AMP components, AMP validation 整合, AMP static export.

---

### 第二十七章 - Customizing Babel Config

- Next.js 使用 `next/babel` preset 作為 babel 設定
- Babel config 允許手動客製化
- 新增 `.babelrc`, 在 presets 使用 `next/babel` 後, 其他可以客製化使用
- 參考[範例](https://nextjs.org/docs/advanced-features/customizing-babel-config)

---

### 第二十八章 - Customizing PostCSS Config

- Next.js CSS 會自動經過 Autoprefixer, ... 對於目標瀏覽器的支援
- Next.js 允許在 `package.json` 手動設置目標瀏覽器 `browserslist`, 可以影響 compiled css 時的選擇
- CSS Modules 不需要任何額外的設定即可啟用
- 如果要手動設置 PostCSS 的 configuration 時, Next.js 會關閉原本的所有設定, 因此都要自行設置, 參考[文件](https://nextjs.org/docs/advanced-features/customizing-postcss-config#customizing-plugins)

---

### 第二十九章 - Custom Server

- 自行設置 server 取代 `next start`
- 注意自行設置的 server 會沒有 serverless function 與 automatic static optimization 的最佳化功能, 只有在 `next start` 無法達成需求時才考慮使用
- 由於自行設置 server, 可以關閉 `pages` routes 設定
- 參考[文件](https://nextjs.org/docs/advanced-features/custom-server)

---

### 第三十章 - Custom `App`

- 藉由客製化 `App` 可以影響所有的 pages 初始化過程
- 可以作到跨 pages 的功能, 例如保持資料, 使用全域資料, 共用 error handling, ...
- 在 `./pages/_app.js` 中可以 override App
- 客製化 App 無法使用 `getStaticProps`, `getServerSideProps`
- 如果在客製化 App 中使用 `getInitialProps`, 會停止所有頁面的 Automatic Static Optimization 除非頁面明確標示 Static Generation

---

### 第三十一章 - Custom `Document`

- 藉由客製化 `Document` 可以控制頁面的 `<html>` 與 `<body>` 結構
- 藉由建立 `./pages/_document.js` 並且 extend `Document` 
- 參考[文件範例](https://nextjs.org/docs/advanced-features/custom-document)

---

### 第三十二章 - Custom Error Page

- 自訂 404 頁, `pages/404.js`
- 自訂伺服器錯誤頁 5xx, `pages/_error.js`
- 可以重用內建的 `Error` page, `import Error from 'next/error'`
- 參考[範例](https://nextjs.org/docs/advanced-features/custom-error-page)

---

### 第三十三章 - `src` Directory

- `pages/` 資料夾可以改成 `src/pages/` 以符合專案的檔案結構

---

### 第三十四章 - Multi Zones

- 整合不同的 apps 進入單一個 app
- 藉由設定 basePath 與 Http proxy 或 Next.js [Rewrites config](https://nextjs.org/docs/api-reference/next.config.js/rewrites) 設定轉導

---

### 第三十五章 - Measuring performance

- Next.js Analytics 提供分析檢測效能各項指標
- Vercel 平台可以直接使用
- 手動建立藉由在 `pages/_app.js` 中增加 `export function reportWebVitals(metric) { }` 可以讀取數值
- 內建數值包含 Time to First Byte (TTFB), First Contentful Paint (FCP), Largest Contentful Paint (LCP), First Input Delay (FID), Cumulative Layout Shift (CLS)
- Next.js 提供的數據包含 `Next.js-hydration`, `Next.js-route-change-to-render`, `Next.js-render`
- 並且可以發送分析結果到指定的 endpoint 或 Google Analytics 後台
- 參考[文件](https://nextjs.org/docs/advanced-features/measuring-performance)

---

### 第三十六章 - Debugging

- 使用 Chrome DevTools, VSCode debugger 或 Node.js debugger

1. 啟動 Next.js debug mode
  - `NODE_OPTIONS='--inspect' next dev` 
1. 連結 debugger
  - Chrome DevTools, `chrome://inspect`
  - VSCode 要設定 `attach mode`, 參考文件[設定](https://nextjs.org/docs/advanced-features/debugging#using-the-debugger-in-visual-studio-code)
1. 使用 breakpoints
  - `debugger` statement

---

### 第三十七章 - Source Maps

- 在 development 時預設開啟, Production build 預設關閉以提昇效能
- 可以藉由 config 在 production build 時也開啟 Source Maps
  - 參考[設定](https://nextjs.org/docs/advanced-features/source-maps)

---

### 第三十八章 - Codemods

- Next.js 提供 `@next/codemod` 指令, 可以自動化升級棄用的語法
- 參考[文件](https://nextjs.org/docs/advanced-features/codemods)

---

### 第三十九章 - Internationalized Routing

- Next.js 在 v10.0.0 版以上原生支援 i18n
- 設定 locales 後 Next.js 可以自動處理 i18n Routing 

Getting Started
- 在 `next.config.js` 中設定 `i18n: { locales:[], defaultLocale, domains }`
- Locales 命名採用 UTS Locales Identifiers 標準
- 參考文件[設定](https://nextjs.org/docs/advanced-features/i18n-routing#getting-started)

Locale Strategies
- i18n 的 Routing 策略可以分成兩種, 
  - Sub-path Routing, 增加 locale 在現有的 URL path 中
  - Domain Routing, 不同 locale 對應不同的 domain
- 參考文件[設定](https://nextjs.org/docs/advanced-features/i18n-routing#locale-strategies)

Automatic Locale Detection
- 如果使用者訪問 `/` 根目錄時會自動依據 `Accept-Language` header 和現在 domain 去作偵測 locale.
- 如果不是 default locale 時會依據策略執行 redirect
- 可以在 i18n config 中關閉 automatic locale detection 的 redirect 功能, 參考[設定](https://nextjs.org/docs/advanced-features/i18n-routing#disabling-automatic-locale-detection)

Accessing the locale information
- 從 `useRouter()` 中可以取得 locale 相關資訊
- 從 `getStaticProps`, `getServerSideProps` 中的 context 物件也可以取得 locale 相關資訊

Transition between locales
- 使用 `next/link` 或 `next/router` 可以達成在 locales 之間移動, 兩者 API 皆有 `locale` 參數可以設置
- 參考[範例](https://nextjs.org/docs/advanced-features/i18n-routing#transition-between-locales)

Leveraging the NEXT_LOCALE cookie
- Next.js 藉由 `NEXT_LOCALE` cookie 值作為使用者設定

Search Engine Optimization
- Next.js 會依據使用者語言在 `<html>` 標籤上加入對應的 `lang` 屬性
- 可以手動增加 `hreflang` meta 在 `<head>` 中, 參考 [hreflang](https://developers.google.com/search/docs/advanced/crawling/localized-versions?visit_id=637493400736385326-3138786548&rd=1) 說明

How does this work with Static Generation?
- i18n routing 無法使用在 `next export` 的靜態檔案中

Automatically Statically Optimized Pages
- 頁面會依據各 locale 依據 automatically statically optimized 生成對應的 html

Non-dynamic getStaticProps Pages, Dynamic getStaticProps Pages
- 可以在 `getStaticProps()` 與 `getStaticPaths()` 函式中取得 locales 資訊然後處理
- 參考[文件](https://nextjs.org/docs/advanced-features/i18n-routing#non-dynamic-getstaticprops-pages)

---

### 第四十章 - Upgrade Guide

- React 16 to 17
- Upgrading from version 9 to 10
- Upgrading from version 8 to 9
- Breaking Changes
- Deprecated Features

---

### 第四十一章 - Migrating to Next.js

移植策略
- Incrementally Adopting Next.js, 漸進式採用策略與 Routing
- Migrating from Gatsby
- Migrating from Create React App
- Migrating from React Router

---

### 第四十二章 - FAQ

- 問題關於系統整合等等

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