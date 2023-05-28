## SWR official documentation

### [SWR documentation](https://swr.vercel.app/), Front-end/SWR

---

第一章 - Getting Started

第二章 - API

第三章 - Global Configuration

第四章 - Data Fetching

第五章 - Auto Revalidation

第六章 - Arguments

第七章 - Mutation & Revalidation

第八章 - Error Handling

第九章 - Conditional Data Fetching

第十章 - Pagination

第十一章 - Subscription

第十二章 - Prefetching

第十三章 - Next.js SSG and SSR

第十四章 - TypeScript

第十五章 - Suspense

第十六章 - Middleware

Advanced

第十七章 - Understanding SWR

第十八章 - Cache

第十九章 - Performance

第二十章 - React Native

第二一章 - Developer Tools

---

SWR

React Hooks for Data Fetching

### 第一章 - Getting Started

Installation

Quick Start

- `useSWR()`
- fetcher function
- return:
  - `data`
  - `error`
  - `isLoading`

Make It Reusable

- 讓 swr 藏在 custom hook 後面

Example

- 一般來說為了避免不必要的 HTTP request, 會把 fetch 放在最上層的 component
- SWR 提供 cache 讓 HTTP request 存在各個 component 而不用擔心不必要的 HTTP request

---

### 第二章 - API

`const { data, error, isLoading, isValidating, mutate } = useSWR(key, fetcher, options)`

Parameters

- `key`, 唯一的 key 用來重用 cache
- `fetcher`, 選擇性提供的 fetch data promise function
- `options`, 其他選項

Return Values

- `data`, resolve fetcher 後的資料
- `error`, fetcher 丟出的錯誤或者是 `undefined`
- `isLoading`, fetcher 還在運作中
- `isValidating`, 如果是 request 中或者 revalidation 中
- `mutate(data?, options?)`, 提供一個操作 cached data 的函式

Options

- `suspense`, 配合 React Suspense mode
- `fetcher(args)`, fetcher function
- revalidation
  - `revalidateIfStale`,
  - `revalidateOnMount`
  - `revalidateOnFocus`
  - `revalidateOnReconnect`
- `refreshInterval`
- `refreshWhenHidden`
- `refreshWhenOffline`
- `shouldRetryOnError`
- `dedupingInterval`
- `focusThrottleInterval`
- `loadingTimeout`
- `errorRetryInterval`
- `errorRetryCount`
- `fallback`
- `fallbackData`
- `keepPreviousData`
- `onLoadingSlow`
- `onSuccess`
- `onError`
- `onErrorRetry`
- `onDiscarded`
- `compare`
- `isPaused`
- `use`

---

### 第三章 - Global Configuration

- `SWRConfig` context, 通過 context 傳遞 options
  - 所有 useSWR options 都可以一次性地通過 global config 設定

Nesting Configurations

- 可以有多層的 `SWRConfig` context
  - 底層 config 會進行 override 或 merge 依據 option 的不同

Object Configuration Example

- `SWRConfig` context value 傳遞 object 的方式設定

Functional Configuration Example

- `SWRConfig` context value 傳遞 function 的方式設定

Extra APIs

Cache Provider

- SWRConfig 可以傳遞 `provider` 來客製化 cache 的實作

Access To Global Configurations

- `useSWRConfig()` 可以通過 hook 取得 SWRConfig 中的值

---

### 第四章 - Data Fetching

- `const { data, error } = useSWR(key, fetcher)`

Fetch

- 使用 fetch, 可以配合 polyfill 提供更好的相容性

Axios

- 使用 Axios API 進行 HTTP request

GraphQL

- 使用 GraphQL 進行取值

---

### 第五章 - Auto Revalidation

- 如果要手動進行則使用 mutation API

Revalidate on Focus

- 切換頁面, Tab 時
- 預設是開啟的

Revalidate on Interval

- 只有當 on screen 時, 才會依據設定的時間進行重新驗證
- 可以配合 `refreshWhenHidden`, `refreshWhenOffline` 改變不是 on screen 時的行為

Revalidate on Reconnect

- 在網路重連時
- 預設是開啟的

Disable Automatic Revalidations

- 可以通過 options 關閉
- `revalidateIfStale`, `revalidateOnFocus`, `revalidateOnReconnect`

---

### 第六章 - Arguments

- 傳遞給 fetcher function 的參數

Multiple Arguments

- `useSWR`, key 與 fetcher function 改傳遞 array 作為參數, 來帶入多個參數, 才能形成正確的 cache

Passing Objects

- 傳遞物件型參數

---

### 第七章 - Mutation & Revalidation

- `mutate` 與 `useSWRMutation` 來手動操作 cache

mutate

- 兩種類型的 mutate API

Global Mutate

- 通過 `useSWRConfig` 取得 global mutate API
- 也可以通過 `import { mutate } from "swr"` 取得
- 通過 key 來指定

Bound Mutate

- 從各自的 `useSWR` 取得已經綁定 key 的 mutation

Revalidation

- 使用 `mutate(key)` 或 `mutate()` bound
- 不傳遞新的資料, 而是直接觸發 revalidation

API

Parameters

- `key`
- `data`
- `options`
  - `optimisticData`,
  - `revalidate`,
  - `populateCache`,
  - `rollbackOnError`,
  - `thrownOnError`

Return Values

- 回傳 updated `data`
- 可以用 try..catch 處理可能的錯誤

useSWRMutation

- 通過 `useSWRMutation` 手動操作 cache 取代 `useSWR` 內有的 auto revalidation 機制
- `useSWRMutation` 與 `useSWR` 共用同一個 cache pool
  - 會自動避免 race condition

API

Parameters

- `key`
- `fetcher`
- `options`
  - `optimisticData`,
  - `revalidate`,
  - `populateCache`,
  - `rollbackOnError`,
  - `throwOnError`,
  - `onSuccess(data, key, config)`
  - `onError(err, key, config)`

Return Values

- `data`,
- `error`,
- `trigger(arg, options)`, 用來操作 mutate
- `reset`
- `isMutating`

Basic Usage

Defer loading data until needed

- `useSWRMutation` 並不會自動觸發 request, 因此可以延遲觸發 (手動)

Optimistic Updates

- 使用者體驗最佳化, 先反映在前端, 不需要等待 server response
- 以 `optimisticData` 實現
- 配合 `rollbackOnError` 提供錯誤回應時的後續處理

Rollback on Errors

- 使用 `optimisticData` 時, 最好進行 server error 的處理來同步正確的資訊

Update Cache After Mutation

Avoid Race Conditions

- 會自動避免 race condition
- 避免不正確過時的資料產生

Mutate Based on Current Data

- 更新數據同時更新 cache

Mutate Multiple Items

- 同時 mutate 或 revalidate 多個 cache

---

### 第八章 - Error Handling

- 在 `fetcher` 裡的錯誤 (Promise reject) 會通過 `error` object 傳出

Status Code and Error Object

- 在 fetcher function 裡進行錯誤處理 `throw` 客製化的 error
- 通過 uswSWR 自動轉換成 error object

Error Retry

- 錯誤時重試機制

Global Error Report

- 在 `SWRConfig` context 通過 `onError` global 捕捉錯誤統一處理

---

### 第九章 - Conditional Data Fetching

Conditional

- 條件式觸發 request (data fetching)
- 傳遞 key 時, 傳出 `null` 或 error 來避免觸發

Dependent

- 依據其他欄位或 fetch data 來進行自動延遲發送

---

### 第十章 - Pagination

- 可以使用 `useSWRInfinite` 來實現

When to Use useSWR

- 只使用 `useSWR` 實現時
- 一樣可使用 paging index 產生不同的 key
- 大多數情境都可以使用 `useSWR` 實現
- Pagination
  - [參考範例](https://swr.vercel.app/docs/pagination#pagination)
- Infinite Loading
  - [參考範例](https://swr.vercel.app/docs/pagination#infinite-loading)

Advanced Cases

- 進階情境才使用 `useSWRInfinite`

useSWRInfinite

- `import useSWRInfinite from 'swr/infinite'`

API

Parameters

- `getKey` function
- `fetcher` function
- `options` object
  - `initialSize`
  - `revalidateAll`
  - `revalidateFirstPage`
  - `persistSize`
  - `parallel`

Return Values

- `data`
- `error`
- `isLoading`
- `isValidating`
- `mutate`
- `size`
- `setSize`

Example 1: Index Based Paginated API

Example 2: Cursor or Offset Based Paginated API

Parallel Fetching Mode

- 預設是 sequence

Global Mutate with useSWRInfinite

Advanced Features

- 一些範例來實現
- loading states
- show a special UI if it's empty
- disable the "Load More" button if reached the end
- changeable data source
- refresh the entire list

---

### 第十一章 - Subscription

useSWRSubscription

- `useSWRSubscription` hook
- 實現 real-time data sources

API

Parameters

- `key`, swr cache key
- `subscribe` function
  - `key`
  - `options`
    - `next`

Return Values

- `state` object
  - `data`, latest data
  - `error`, object

Usage

- 範例使用 `useSWRSubscription` 去訂閱 Firestore data
- 範例訂閱 WebSocket data

Deduplication

- 通過 key 進行 deduplication, 來實現共用 cache

---

### 第十二章 - Prefetching

Top-Level Page Data

- 最原生的方式
- `<link rel="preload" href="/api/data" as="fetch" crossorigin="anonymous">`
- html `rel="preload"`
- 在之後 SWR 遇到相同的 URL 就不用再次發送

Programmatically Prefetch

- `{ preload } from 'swr'`
- 手動操作 preload 綁定 `key`
- `preload` + Suspense mode
  - 配合 swr options: `suspense`

Pre-fill Data

- 以 `fallbackData` option 傳入預先準備的資料做成 default

---

### 第十三章 - Next.js SSG and SSR

Client Side Data Fetching

- SWR 的使用範圍

Pre-rendering with Default Data

- 通過 server-side preload 或提供 fallback data
- 通過 `SWRConfig` 把資料打進去

Complex Keys

- 以 Array 為 key 的 SWR cache
- SSR 配合 `unstable_serialize()` API 使用

---

### 第十四章 - TypeScript

Basic Usage

useSWR

- 自動形成的 key Type
- 通過 `Fetcher<>` 定義的 response type

useSWRInfinite

- `import type { SWRInfiniteKeyLoader } from 'swr/infinite'`

useSWRSubscription

- `import type { SWRSubscriptionOptions } from 'swr/subscription'`
- `import type { SWRSubscription } from 'swr/subscription'`

Generics

- `import type { SWRConfiguration } from 'swr'`

Middleware Types

-` import type { Middleware, SWRHook } from 'swr'`

---

### 第十五章 - Suspense

- 目前不被 React 官方推薦使用 (2023.5.28)
- https://swr.vercel.app/docs/suspense

---

### 第十六章 - Middleware

- 用來撰寫 SWR 流程中間的客製化邏輯

Usage

- 在 SWR 執行之前或之後

API

- 定義 middleware function
- 在 `SWRConfig` 中以 `use: []` option 傳入 middleware
- 或是在 `useSWR` 以 `use: []` option 傳入

Extend, Multiple Middleware

- 多個 middleware 的執行順序與定義

Examples

Request Logger

- 穿插 logger (AOP)

Keep Previous Result

- 保存舊的狀態

Serialize Object Keys

- 目前版本會自動進行序列化 `key`

---

Advanced

---

### 第十七章 - Understanding SWR

State Machine

- 依據狀態機實現 fetch, loading, validating

Fetch and Revalidate

Key Change

Key Change + Previous Data

Fallback

Key Change + Fallback

Key Change + Previous Data + Fallback

Combining with isLoading and isValidating for better UX

Return previous data for better UX

Dependency Collection for performance

---

### 第十八章 - Cache

- 客製化 Cache 的實作方式

Cache Provider

```typescript
interface Cache<Data> {
  get(key: string): Data | undefined
  set(key: string, value: Data): void
  delete(key: string): void
  keys(): IterableIterator<string>
}
```

Create Cache Provider

- 通過 `SWRConfig` `provider` option 傳入客製化的 cache 實作

Access Current Cache Provider

- 通過 `useSWRConfig()` hook 取得當前的 `cache` object 與 `mutate` function API

Examples

LocalStorage Based Persistent Cache

- 客製化實現 cache 存在 browser local storage

Reset Cache Between Test Cases

- 實現在測試時重置 cache

Modify the Cache Data

---

### 第十九章 - Performance

Deduplication

- SWR 通過 key 減少重複的 network request

Deep Comparison

- SWR 使用 deep comparison data 來避免觸發不必要的 re-render
- 可以通過傳遞 `compare` option, 客製化比較函式

Dependency Collection

- `useSWR`, 回傳四種狀態 `data`, `error`, `isLoading`, `isValidating`
- 盡量只依賴 `data` state 作為 component dependency, 來減少不必要的 re-render

Tree Shaking

- SWR package 可以進行 tree shaking, 只 import 所需要的 function

---

### 第二十章 - React Native

- React Native 與 browser 執行環境的差別

---

### 第二一章 - Developer Tools

- 非官方的瀏覽器 extension 來協助 debug SWR Cache

---
