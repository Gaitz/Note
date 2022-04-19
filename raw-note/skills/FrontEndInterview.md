## FrontEnd Interview Questions

### Computer Science

---

第一章 - 題目清單 25

第二章 - 分類解答 JavaScript 相關

第三章 - 分類解答 React 相關

第四章 - 分類解答 前端常見問題

第五章 - 分類解答 Network 相關

第六章 - 分類解答 後端相關

第七章 - 分類解答 演算法實作

第八章 - 分類解答 其他技術問題

第九章 - 面試時的提問

---

### 題目清單

- closure 與 this?
- event loop, macro task 與 micro task? Promise 的同步與非同步? 執行順序? then 的執行順序
- JavaScript type converse, `==` algorithm?
- V8 Garbage Collections, scavenge, young generation?
- Decorator pattern in JavaScript

---

- Redux Reselect 的 selector 做了什麼?
- Hook 實作倒數? useState, setTimeout, clearTimeout
- setState 與 React 執行流程?
- React 核心, diff 演算法?
- Redux, how to diff state change and trigger notification?

---

- 前端儲存資訊的地方? (cookies, local store, sessions, indexDB)
- 如何判斷使用者語系? (IP detect, User Agent)
- CSS 置中方法? flexbox, absolute + relative, grid
- Bundle size minify 的方法? Webpack minify, tree shaking, dynamic import 與 CommonsChuckPlugin

---

- Browser cache policy, service worker, http cache?
- http headers, etag v.s. Last-Modified?
- Prevent XSS with http header (Content Security Policy, CSP)?
- SSR with 'isitc', 'service mesh'

---

- Restful API naming convention

---

- Leetcode 1. two sum, 2. three sum
- function `compose` 實作?
- Algorithm 1. 生成 `()` tree 與 backtracking algorithm
- Algorithm 2. check linked list is recursion?

---

- 用過的 Design Patterns?
- Open Source project understanding & experience?

### 分類解答 - JavaScript 相關

#### Question: closure 與 this?

Answer:

closure, 藉由函式產生的 lexical environment (變數環境), 讓內層函式可以存取外層函式的值

closure 應用

- private member
- 在沒有 let 與 const 之前，使用 closure 產生 scope 綁定正確的值

Reference 1. [closure mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Closures)

`this`, 呼叫時期才動態綁定的 pointer

Reference 1. [this mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this)

---

#### Question: event loop, macro task 與 micro task? Promise 的同步與非同步? 執行順序? then 的執行順序

Answer:

`new Promise()` 是同步的, `.then()` 是非同步並且是 micro task

Reference 1. [Event loop mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/EventLoop)

Reference 2. [我知道你懂 Event Loop，但你了解到多深？](https://yeefun.github.io/event-loop-in-depth/?fbclid=IwAR1Q-4-8N2zdGEgcilB6mkgKGG_8wsDFRr48F5hajUBim4LXCPTiJM7bn0I)

Reference 3. [Microtask mdn](https://developer.mozilla.org/en-US/docs/Web/API/HTML_DOM_API/Microtask_guide)

---

#### Question JavaScript type converse, `==` algorithm?

Answer:

概略:

1. 都是 object 時比較 reference,
1. `null` 與 `undefined` 為 `true`
1. number 與 string 比較時, 會先將 string 轉換成數字 (`ToNumber()`)
1. boolean 會轉換成 `true` -> `1`, `false` -> `+0`
1. object 與 string 或 number 比較時會呼叫 `valueOf()` 與 `toString()`

Reference 1. [== mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Equality)

---

#### Question: V8 Garbage Collections, `scavenge algorithm`, `young generation`?

Answer:

V8 引擎中的 GC 分成 `young generation` 與 `old generation`

- 分別使用不同的 garbage collection algorithm
- young generation 重點在於快速的 GC, 採用 `scavenge algorithm` 使用複製的方式從 from-space 到 to-space 一次性處理完清除與重排
- 當一組資源在 young generation 被執行過數次 GC 之後仍存在的話，會被搬移到 old generation
- old generation 使用 Mark-Sweep 和 Mark-Compact 演算法來處理清除與整理

Reference 1. [Node.js 內存管理和 V8 垃圾回收機制](https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/665962/)

Reference 2. [Trash talk: the Orinoco garbage collector](https://v8.dev/blog/trash-talk)

---

#### Decorator pattern in JavaScript

Answer:

取代創建 subclass 的方式，使用傳入原始物件的方式擴充功能。在 JavaScript 中可以非常容易地做到，因為 JavaScript 中的物件是 runtime 可修改的並且 member function 可以被重新賦值

Reference 1. [The Decorator Pattern - Learning JavaScript Design Patterns by Addy Osmani](https://www.oreilly.com/library/view/learning-javascript-design/9781449334840/ch09s14.html)

### 分類解答 - React 相關

#### Question: Redux Reselect 的 selector 做了什麼?

Answer:

- Selector function, 封裝取值邏輯的 helper function
- Reselect library 的 `createSelector()` 提供了 memorize 機制, 協助在 re-rendering 時的效能優化機制
- 預設的 compare function 是 `===`, 對於 object 來說就是只比較 reference

Reference 1. [reselect GitHub repository](https://github.com/reduxjs/reselect)

---

#### Question: Hook 實作倒數? useState, useEffect, setTimeout, clearTimeout

Answer:

---

#### Question: setState 與 React 執行流程?

Answer:

---

#### Question: React 核心, diff 演算法?

Answer:

#### Question: Redux, how to diff state change and trigger notification?

Answer:

- Redux store 中每次 dispatch 時所有的 listener 都會被呼叫,
- React-Redux 中 state change 預設使用 `===` 並且有實作 subscription 與 listener pattern 並且通過 `onstatechange` 時會呼叫 `forceRender()` 來強制 component 重新執行，因此可以取得新的 state value 和更新 UI

Reference 1. [Redux createStore.ts](https://github.com/reduxjs/redux/blob/master/src/createStore.ts#L264)

Reference 2. [React-Redux useSelector.js](https://github.com/reduxjs/react-redux/blob/df36f4efa47a32954b9d14c2c3b5c3e9c0cc795d/src/hooks/useSelector.js#L7)

Answer:

### 分類解答 - 前端常見問題

#### Question: 前端儲存資訊的地方? (cookies, local store, sessions, indexDB)

Answer:

- cookies, 依據 http 協定會儲存在每次的 request 中
- Web Storage API, 分成 sessionStorage 與 localStorage
  - 都是 key-value pair 的儲存方式
  - sessionStorage 在 window 被關閉後會自動清除
- IndexDB API, 瀏覽器上內建的 DB 系統適合處理更複雜的資料
- Cache API, 主要使用於 Web Worker 提供 offline 的 http request/response 儲存

Reference 1. [Client-Side storage mdn](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Client-side_web_APIs/Client-side_storage)

---

#### Question: 如何判斷使用者語系? (IP detect, User Agent)

Answer:

- 使用 IP detect 去判斷來源的所在位置
- 使用 HTTP header, `Accept-Language` 判斷使用者偏好語言

Reference 1. [Accept-Language header mdn](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Accept-Language)

---

#### Question: CSS 置中方法? flexbox, absolute + relative, grid

Answer:

- Flexbox, `display: flex; justify-content: center; align-items: center;`
- Absolute + Relative, `position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%);`
- Grid, `display: grid; place-items: center;`

Reference 1. [Top 3 Ways to Center a DIV with CSS #Shorts](https://www.youtube.com/watch?v=njdJeu95p6s)

---

#### Question: Bundle size minify 的方法? Webpack minify, tree shaking, dynamic import 與 SplitChunksPlugin

Answer:

主要使用 Webpack 作為 bundler, 優化的機制除了最基本的 minify 之外還有 tree shaking, dynamic import, SplitChunksPlugin 等

Reference 1. [CommonsChunkPlugin has been removed](https://webpack.js.org/plugins/commons-chunk-plugin/)

Reference 2. [SplitChunksPlugin](https://webpack.js.org/plugins/split-chunks-plugin/)

Reference 3. [Tree shaking](https://webpack.js.org/guides/tree-shaking/)

Reference 4. [dynamic import](https://webpack.js.org/guides/code-splitting/#dynamic-imports)

### 分類解答 - Network 相關

#### Question: Browser cache policy, service worker, http cache?

Answer:

- Cache 可以大致分為 shared cache (需要額外的 server 提供) 與 private (local) cache (通常由瀏覽器提供)
- Http Header: `Cache-Control` 用來控制 cache 的模式
  - `Cache-Control: no-store`, 無 cache
  - `Cache-Control: no-cache`, 會 cache 但每次都需要 revalidate
  - `Cache-Control: private`, 告知此 cache 不能被共享
  - `Cache-Control: public`, 此 cache 可以被共享
  - `Cache-Control: max-age=<seconds>`, 告知 cache 的持續時間, 可以被 `Expires` header 複寫
  - `Cache-Control: must-revalidate`, 等待 cache 過期後一定需要 revalidate
- Http Header: `Pragma` 舊版的 cache control header
- 當 cache 過期 (max-age 或 Expires) 後重新發送 request 時，Server 可以回應 `304` Not Modified，讓 cache 延長使用
- Revving 技術，有版本號的靜態資源可以永久 cache，利用更動 `html` 拉取新版本號的資源
- Cache Validation, 通過 Http response header, `Etag`或 `Last-Modified` 達成
  - `ETag`, strong validator, 通過檢查對應的 hash 來確認, request 帶 `If-None-Match` header 來查詢是否需要更新
  - `Last-Modified`, weak validator, 通過對應 date 來確認, request 帶 `If-Modified-Since` header 來查詢是否需要更新
- Http Header `Vary` 用來表明不同的 Http header 值需要不同的 cache
  - 通常用於 `Accept-Encoding` 或 `User-Agent` 來提供 mobile 與 pc 版
- Normalization 由於不同的 http header 都會影響到 cache 因此 cache server 上可以通過 normalization 讓 request http header 減少差異，不需要提供多份相同的 cache

Reference 1. [HTTP caching mdn](https://developer.mozilla.org/en-US/docs/Web/HTTP/Caching)

---

#### Question http headers, etag v.s. Last-Modified?

Answer:

與 http caching 相關，用來處理 revalidation

- `Etag` 比較值，配合 `If-None-Match` request header
- `Last-Modified` 比較時間，配合 `If-Modified-Since` request header

Reference 1. [HTTP caching mdn](https://developer.mozilla.org/en-US/docs/Web/HTTP/Caching)

---

#### Question: Prevent XSS with http header (Content Security Policy, CSP)?

Answer:

- Content Security Policy, 是 http response header 主要用來防範 Cross Site Scripting 與 Data injection 攻擊
- `Content-Security-Policy: policy`
- 可以設置規則, 共用 `default-src`, 分別設置 `img-src` (圖片) `style-src`(style), `script-src` (script), `media-src` (media), ...
- `'self'` 為原始 domain
- 可以在 policy 中加上 `report-uri` 來指定違反時會發送報告 (POST)
- 還有測試用的 `Content-Security-Policy-Report-Only: policy` 只會發送報告不會阻擋，可以用來測試 policy

Reference 1. [Content Security Policy (CSP)](https://developer.mozilla.org/en-US/docs/Web/HTTP/CSP)

Reference 2. [Http Header Content-Security-Policy mdn](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Content-Security-Policy)

### 分類解答 - 後端相關

#### Question: SSR with 'istio' and 'service mesh'

Answer:

- 服務部屬架構，與 cloud deployment, Kubernetes 有關
- Service mesh 是一種架構，包含服務與 control plane + data plane。
- Istio 是一個開源的 Service mesh 實現

Reference 1. [Kubernetes and Istio 三十天 系列](https://ithelp.ithome.com.tw/users/20104679/ironman/2825)

Reference 2. [總結：服務網格（Service Mesh）](https://www.mdeditor.tw/pl/gf3z/zh-tw)

Reference 3. [火了 2 年的服务网格究竟给微服务带来了什么？](https://www.sofastack.tech/blog/microservices-service-mesh/)

---

#### Question: Restful API naming convention

Answer:

- Restful API 是一種 API 設計風格，由 http 協定的作者發起的。因此 HTTP 協定可以視為一種 Restful 的實現
- 主要分成動詞、名詞、資料型別
- 動詞可以直接對應 http 的動作，例如 GET, POST, PUT, DELETE, ...
- 名詞為 URI 要互動資源的位置
- 命名慣例可以參考文件 1. [Spring 基础篇（5）-restful 命名规则](https://www.jianshu.com/p/7ac1c40ba0de)

Reference 1. [Spring 基础篇（5）-restful 命名规则](https://www.jianshu.com/p/7ac1c40ba0de)

Reference 2. [表現層狀態轉換 wikipedia](https://zh.wikipedia.org/wiki/%E8%A1%A8%E7%8E%B0%E5%B1%82%E7%8A%B6%E6%80%81%E8%BD%AC%E6%8D%A2)

Reference 3. [什麼是 REST? 認識 RESTful API 路由語義化設計風格](https://tw.alphacamp.co/blog/rest-restful-api)

### 分類解答 - 演算法實作

#### Question: Leetcode 1. two sum, 2. three sum

Answer:

Leetcode [two-sum](https://leetcode.com/problems/two-sum/),
Leetcode [3sum](https://leetcode.com/problems/3sum/)

---

#### Question: function `compose` 實作?

Answer:

Hint: `reduce`, arguments as variable

```javascript
function compose(...funs) {
  return funs.reduce(
    (a, b) =>
      (...args) =>
        a(b(args))
  )
}
```

Redux implement [compose](https://github.com/reduxjs/redux/blob/master/src/compose.ts#L46)

---

#### Question: Algorithm 1. 生成 `()` tree 與 backtracking algorithm

Answer:

Leetcode [generate-parentheses](https://leetcode.com/problems/generate-parentheses/)

---

#### Question: Algorithm 2. check linked list is recursion?

Answer:

Leetcode [linked-list-cycle](https://leetcode.com/problems/linked-list-cycle/)

### 分類解答 - 其他技術問題

#### Question: 用過的 Design Patterns?

---

#### Question: Open Source project understanding & experience?

### 面試時的提問

#### 對 hunter

- 國內市場職缺, 國外市場職缺? 熱門的技術與人才類型? (確定未來方向)
- 我的履歷 - 好壞, 改進?
- 對我的看法? Feedback? 條件如何?
- 對於高階工程師來說好的經驗?

#### 對 engineer

- 對資深工程師的要求與期望?
- 專案目前狀況 (使用的技術, 專案目前的維護者是誰)? 軟體工程實務? CI/CD? Testing?
- 對於好的軟體的看法是什麼?
- 系統架構與責任區分?
- 團隊分工狀況? 需求來源, 如何與後端合作, 如何與 UI/UX 合作, 前端工程師的人數?
- 設備狀況 (電腦, 雙螢幕)? 工時, 上下班時間?
- 職缺開放的原因?
- Daily Work 有哪些, 如何進行?
- 目前使用的技術與架構?
- git 工作流程? (git flow, github flow, ...)
- CI/CD 如何進行?
- Testing 如何進行?

#### 對 Manager

- 團隊未來的規劃?

#### 對 Boss

- 企業文化?
- 營收狀況?
- 資金狀況?
- 未來規劃?
