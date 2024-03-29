## Software Interview Questions

### Computer Science

---

第零章 - 準備資源

第一章 - 題目清單

第二章 - 分類解答 JavaScript 相關

第三章 - 分類解答 React 相關

第四章 - 分類解答 前端常見問題

第五章 - 分類解答 Network 相關

第六章 - 分類解答 後端相關

第七章 - 分類解答 演算法實作

第八章 - 分類解答 其他技術問題

第九章 - 面試時的提問

---

### 準備資源

- [tech-interview-handbook](https://github.com/yangshun/tech-interview-handbook)

  - 履歷撰寫, 準備演算法問題, 技術面試考驗重點與應對方式, 演算法分類 cheat sheet (edge cases, 常用技巧), Behavior questions

- [前端开发面试题 2018](https://github.com/markyun/My-blog/tree/master/Front-end-Developer-Questions)

- [React Fiber 淺談](https://medium.com/happy-friday/react-fiber-%E6%B7%BA%E8%AB%87-1f18b5859298)

---

### 題目清單

JavaScript 相關

- [x] closure 與 this?
- [x] event loop, macro task 與 micro task? Promise 的同步與非同步? 執行順序? then 的執行順序
- [x] JavaScript type converse, `==` algorithm?
- [x] V8 Garbage Collections, scavenge, young generation?
- [x] Decorator pattern in JavaScript
- [x] Implements curried multiple function
- [x] Custom implements `Promise.all()`
- [x] setTimeout, scope, closure
- [x] rest operator, spread operator
- [x] setTimeout in for loop 的觸發時間

---

React 相關

- [x] Redux Reselect 的 selector 做了什麼?
- [ ] Hook 實作倒數? useState, setTimeout, clearTimeout
- [ ] setState 與 React 執行流程?
- [ ] React 核心, diff 演算法? diff 演算法比較什麼
- [x] Redux, how to diff state change and trigger notification?
- [x] useState render issues
- [x] PureComponent, Component, functional component
- [x] React 'key' attribute
- [ ] useMemo 與 useCallback 區別
- [ ] React diff 是 dfs 還是 bfs?
- [ ] Redux 為什麼 dispatch 必須是 pure function
- [ ] Next.js 有沒有遇到什麼問題
- [x] 在同一個 event handler 中重複 `setState()` 會發生什麼事情
- [ ] Why React initial render twice in dev mode?

---

CSS 相關

- [x] CSS 置中方法? flexbox, absolute + relative, grid
- [x] `visibility: hidden;` 與 `display: none;` 的差別
- [x] `position` 的選項與差別
- [ ] CSS triangle
- [ ] CSS em vs rem

---

前端常見問題

- [x] 前端儲存資訊的地方? (cookies, local store, sessions, indexDB)
- [ ] Cookie, localStorage, sessionStorage 存在時間差異與控制方式
- [x] 如何判斷使用者語系? (IP detect, User Agent)
- [x] Bundle size minify 的方法? Webpack minify, tree shaking, dynamic import 與 CommonsChuckPlugin
- [ ] 如何最佳化 Web
- [ ] SEO tuning
- [ ] RWD 與 AWD 分別是什麼, 使用時機是什麼
- [ ] CSS selector 有哪些, 權重如何計算
- [x] Event phase, event flow and how to interrupt
- [ ] Cross site messaging 如何做？
- [x] defer, async
- [ ] What is CORS? CORB?
- [x] debounce 與 throttle 的差別與如何實作或使用
- [x] jpg 與 SVG 的容量差異
- [x] PWA data sync
- [ ] XSS, CSRF 是什麼與如何防禦
- [x] Browser Render 的流程與可以優化的地方
- [ ] How to page lazy loading
- [ ] 從瀏覽器輸入 URL 到完成渲染中間發生的事情

---

Network 相關

- [x] Browser cache policy, service worker, http cache?
- [x] http headers, etag v.s. Last-Modified?
- [x] Prevent XSS with http header (Content Security Policy, CSP)?
- [x] Http status codes
- [ ] Http methods and different between POST, PUT, PATCH
- [ ] cookie attributes: httponly, secure, session, samesite
- [ ] browser cross origin solutions

---

後端相關

- [x] SSR with 'isitc', 'service mesh'
- [x] Restful API naming convention
- [x] Restful API design guidelines

---

演算法實作

- [x] Leetcode 1. two sum, 2. three sum
- [x] function `compose` 實作?
- [x] Algorithm 1. 生成 `()` tree 與 backtracking algorithm
- [x] Algorithm 2. check linked list is recursion?

---

其他技術問題

- [ ] 用過的 Design Patterns?
- [ ] Open Source project understanding & experience?
- [ ] Design Principles, SOLID
- [x] Event-driven Design
- [ ] Logging, Monitoring, 應該針對什麼
- [x] git rebase 與 merge 的差別與範例
- [ ] RxJS, error handling

---

### 分類解答 - JavaScript 相關

---

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

- Event loop 的 event system 與 function execution context
- `new Promise((resolve, reject) => {})` 是同步的, 包含傳進 `new Promise()` 的 function,
  - 因此 `(resolve, reject) => {}` 的整個 function body 同步的先執行, 包含了 `resolve()` 或 `reject()` 之後的程式碼
  - `.then()` 是非同步並且是 micro task
- 兩個無關連, 沒有持有 reference 的 Promise job 的順序是不定的, 取決於 promise job queue
- Promise 的執行順序範例

```javascript
async function bfunc() {
  console.log("2 - b func")
}

async function afunc() {
  await bfunc() // rest of function pushed to event queue
  console.log("4 - a func")
}

const prom = new Promise((resolve, reject) => {
  console.log("1 - inside promise")
  resolve("5 - foo")
  afunc()
}).then((value) => {
  // this is also pushed to the event queue
  console.log(value)
})

console.log("3 - last thing")
```

Reference 1. [Event loop mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/EventLoop)

Reference 2. [我知道你懂 Event Loop，但你了解到多深？](https://yeefun.github.io/event-loop-in-depth/?fbclid=IwAR1Q-4-8N2zdGEgcilB6mkgKGG_8wsDFRr48F5hajUBim4LXCPTiJM7bn0I)

Reference 3. [Microtask mdn](https://developer.mozilla.org/en-US/docs/Web/API/HTML_DOM_API/Microtask_guide)

Reference 4. [Event loop queueing order example and description](https://stackoverflow.com/questions/67863820/event-loop-queueing-order)

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

#### Question: Decorator pattern in JavaScript

Answer:

取代創建 subclass 的方式，使用傳入原始物件的方式擴充功能。在 JavaScript 中可以非常容易地做到，因為 JavaScript 中的物件是 runtime 可修改的並且 member function 可以被重新賦值

Reference 1. [The Decorator Pattern - Learning JavaScript Design Patterns by Addy Osmani](https://www.oreilly.com/library/view/learning-javascript-design/9781449334840/ch09s14.html)

---

#### Question： Implements curried function

- `Function.length`, The length property indicates the number of parameters expected by the function.
- 在傳入的值數量還沒達到原本 Function.length 時, 持續蒐集傳入值並且傳遞下去.

---

#### Question: Custom implements `Promise.all()`

```javascript
const PromiseAll = (promises) => {
  const result = new Array(promise.length)
  let resolveTimes = 0
  return new Promise((resolve, reject) => {
    promises.forEach((promise, index) => {
      promise()
        .then((res) => {
          resolveTimes++
          result.push(res)
          if (resolveTimes === promises.length) {
            resolve(result)
          }
        })
        .catch((error) => {
          reject(error)
        })
    })
  })
}
```

---

#### Question: setTimeout, scope, closure

- problem

```javascript
for (var i = 0; i < 5; i++) {
  setTimeout(function () {
    console.log(i)
  }, 0)
}
```

- solve by IIFE closure

```javascript
for (var i = 0; i < 5; i++) {
  setTimeout(
    (function (index) {
      console.log(index)
    })(i),
    0
  )
}
```

---

#### Question: rest operator, spread operator

- share the same operator `...`
- rest operator example `function (a, b, ...rest)`
- spread operator example `...arrayName`, `...stringName`, `...objectName`
  - can expand any **iterable**

Reference [JavaScript Rest vs Spread Operator – What’s the Difference?](https://www.freecodecamp.org/news/javascript-rest-vs-spread-operators/#:~:text=The%20main%20difference%20between%20rest,expands%20iterables%20into%20individual%20elements.)

---

#### Question: setTimeout in for loop 的觸發時間

- callback function 觸發的時間間隔

```javascript
for (var i = 0; i < 3; i++) {
  setTimeout(() => {
    console.log(new Date(Date.now()).toUTCString())
  }, 1000)
}

for (var i = 0; i < 3; i++) {
  setTimeout(() => {
    console.log(new Date(Date.now()).toUTCString())
  }, 1000 * i)
}
```

---

### 分類解答 - React 相關

---

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

---

#### Question: Redux, how to diff state change and trigger notification?

Answer:

- Redux store 中每次 dispatch 時所有的 listener 都會被呼叫,
- React-Redux 中 state change 預設使用 `===` 並且有實作 subscription 與 listener pattern 並且通過 `onstatechange` 時會呼叫 `forceRender()` 來強制 component 重新執行，因此可以取得新的 state value 和更新 UI

Reference 1. [Redux createStore.ts](https://github.com/reduxjs/redux/blob/master/src/createStore.ts#L264)

Reference 2. [React-Redux useSelector.js](https://github.com/reduxjs/react-redux/blob/df36f4efa47a32954b9d14c2c3b5c3e9c0cc795d/src/hooks/useSelector.js#L7)

Answer:

---

#### Question: useState render issues

- `useState()` 的 setState 傳遞如果是 reference 的話, 會直接比較 reference 才決定是否渲染

  - 因此如果傳入相同的 object reference 例如 array 的話, 並不會觸發 re-render

- React `key`, react render array 時 item 是使用 `key` 來決定是否 re-render
  - 因此如果 render array 以 index 做 `key` 時, 常會出現 render issue 並沒有更新

---

#### Question: PureComponent, Component, functional component

- `Component`, 最基礎的 React component class
- `PureComponent`, 無法自訂 `shouldComponentUpdate` 的 class component base, 但是會自動以 shallow compare 比較 props 與 states (**shallow compare** `shouldComponentUpdate`)
  - 用來避免不必要的 re-render
- **function component**,
  - 傳統上的 stateless function component 沒有 state, refs, lifecycle functions
  - React 16+ 以上有 React hook 可以在 function component 上實現以上的功能
- `React.memo` is a higher order component
  - 會 cache component render 的結果, 只有在 props, states, context 有變化時才會 re-render
  - 預設是 shallow compare 但是可以傳遞額外的 `areEqual` compare function

Reference 1. [React API](https://reactjs.org/docs/react-api.html#reference)

---

#### Question: React 'key' attribute

- 當 `key` attribute 被加在非 list item 的 component 上時會有什麼表現?
- 參考 React Reconciliation 的判斷流程
- [Recommendation: Fully uncontrolled component with a key](https://reactjs.org/blog/2018/06/07/you-probably-dont-need-derived-state.html#recommendation-fully-uncontrolled-component-with-a-key)

---

#### 在同一個 event handler 中重複 `setState()` 會發生什麼事情

```javascript
export default function App() {
  const [count, setCount] = useState(0)
  const clickHandler = () => {
    setCount(count + 1)
    setCount(count + 1)
  }

  return (
    <div className="App">
      <h1 onClick={clickHandler}>Hello CodeSandbox</h1>
      <h2>{count}</h2>
    </div>
  )
}
```

---

### 分類解答 - CSS 相關

---

#### Question: CSS 置中方法? flexbox, absolute + relative, grid

Answer:

- Flexbox, `display: flex; justify-content: center; align-items: center;`
- Absolute + Relative, parent: `position: relative`, child: `position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%);`
- Grid, `display: grid; place-items: center;`

Reference 1. [Top 3 Ways to Center a DIV with CSS #Shorts](https://www.youtube.com/watch?v=njdJeu95p6s)

---

#### Question: `visibility: hidden;` 與 `display: none;` 的差別

- `visibility` 控制顯示與否但是不影響 layout, 選擇不被繪畫出來但是仍然存在佔位
- `display` 控制該元素被視為 inline 或者 block 影響本身與子代的 layout 行為
  - `display: none` 關閉元素的 display 即關閉他對 layout 的影響, 可以視為不存在 layout 上

Reference: [visibility mdn](https://developer.mozilla.org/en-US/docs/Web/CSS/visibility)

Reference: [display mdn](https://developer.mozilla.org/en-US/docs/Web/CSS/display)

---

#### Question: `position` 的選項與差別

- `position` 控制元素如何被定位在 document 上
  - `static`, 預設值,
  - `relative`, 相對於自己原本的位置 ( static 時) 配合定位屬性來控制定位, 對於 layout 而言等同於 static
  - `absolute`, 從原本的 layout 上移除, 定位於最近的 relative 父層, 抽離原本的 layout 以自由定位
  - `fixed`, 從原本的 layout 上移除, 定位於 viewport
  - `sticky`, 定位於最近的 scroll container 父層中
- 通常配合定位屬性 `top`, `right`, `bottom`, `left`, `z-index` 來協助定位

Reference: [position mdn](https://developer.mozilla.org/en-US/docs/Web/CSS/position)

---

### 分類解答 - 前端常見問題

---

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

#### Question: Cookie, localStorage, sessionStorage 存在時間差異與控制方式

Answer:

---

#### Question: 如何判斷使用者語系? (IP detect, User Agent)

Answer:

- 使用 IP detect 去判斷來源的所在位置
- 使用 HTTP header, `Accept-Language` 判斷使用者偏好語言

Reference 1. [Accept-Language header mdn](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Accept-Language)

---

#### Question: Bundle size minify 的方法? Webpack minify, tree shaking, dynamic import 與 SplitChunksPlugin

Answer:

主要使用 Webpack 作為 bundler, 優化的機制除了最基本的 minify 之外還有 tree shaking, dynamic import, SplitChunksPlugin 等

Reference 1. [CommonsChunkPlugin has been removed](https://webpack.js.org/plugins/commons-chunk-plugin/)

Reference 2. [SplitChunksPlugin](https://webpack.js.org/plugins/split-chunks-plugin/)

Reference 3. [Tree shaking](https://webpack.js.org/guides/tree-shaking/)

Reference 4. [dynamic import](https://webpack.js.org/guides/code-splitting/#dynamic-imports)

---

#### Question: 如何最佳化 Web, Performance tuning

---

#### Question: SEO tuning

---

#### Question: RWD 與 AWD 分別是什麼, 使用時機是什麼

---

#### Question: CSS selector 有哪些, 權重如何計算

---

#### Question: Event phase, event flow and how to interrupt

- DOM Event phase 分成三個步驟
  1. Capturing phase
  2. Target phase
  3. Bubbling phase
- 會影響到相關 DOM Tree element event listener 的觸發順序
- `addEventListener()` Callback function
  - 預設的觸發時機是 bubbling phase
  - 可以通過選用參數讓觸發時機變成 capturing phase
- `event.target` 與 `event.currentTarget` 的差別
  - `event.target` 在 bubbling phase 並不會改變, 代表的是最深處觸發的 element
  - `event.currentTarget` 代表當前觸發 handler 的 element
- `event.stopPropagation()` 停止後續的 bubbling 執行
- `event.eventPhase` 可以取得 readonly 的當前階段分別為
  - `1` capturing, `2` target, `3` bubling

[Ref 1. Phases of JavaScript Event](https://www.geeksforgeeks.org/phases-of-javascript-event/)

[Ref 2. Bubbling and capturing](https://javascript.info/bubbling-and-capturing)

---

#### Question: Cross site messaging 如何做？

---

#### Question: defer, async

- 關於 browser 解析 html, 下載資源, 執行外部 script
- `defer`, 非同步下載, 執行會等到 DOMContentLoaded
- `async`, 非同步下載, 下載回來後即刻執行

Reference [Scripts: async, defer](https://javascript.info/script-async-defer)

---

#### Question: What is CORS? CORB?

Reference: [跨來源資源共用 (CORS) 是什麼? 如何設定 CORS?](https://shubo.io/what-is-cors/)

---

#### Question: debounce 與 throttle 的差別與如何實作或使用

- 兩者都是限制 event 的觸發, 並且都有可能會丟棄事件
- `debounce`, 防抖, 避免"連續"發送, 只發送最後一次
  - 參考 [RxJS debounceTime 彈珠圖](https://rxjs.dev/api/index/function/debounceTime)
- `throttle`, 節流, 限制頻率上限, 一定區間內只會發送一次,
  - 類似有個技能 cool down, CD 的感覺
  - 參考 [RxJS throttleTime 彈珠圖](https://rxjs.dev/api/index/function/throttleTime)
- 簡易實作可以參考 [網頁 DOM 事件的效能優化：Debounce 和 Throttle](https://jacobhsu.github.io/2021/08/04/dom/debounce-throttle/)
- 實務上通常會使用第三方 library, `underscore`, `lodash`, `RxJS` 等等來提供

---

#### Question: jpg 與 SVG 的容量差異

- SVG image is generally larger than JPEG image of same image.

Reference: [Difference between JPEG and SVG](https://www.tutorialspoint.com/difference-between-jpeg-and-svg#:~:text=JPEG%20image%20quality%20decreases%20on,quality%20remains%20same%20on%20zooming.&text=JPEG%20image%20is%20generally%20smaller,JPEG%20image%20of%20same%20image.)

---

#### Question: PWA data sync

- 配合 Service Worker API
- Service Worker Registration
  - `sync` 實驗性 API

Reference [ServiceWorkerRegistration.sync mdn](https://developer.mozilla.org/en-US/docs/Web/API/ServiceWorkerRegistration/sync)

Reference [Background Sync – PWA’s Backbone](https://www.excellarate.com/blogs/background-sync-pwas-backbone/)

---

#### Question: XSS, CSRF 是什麼與如何防禦

---

#### Question: Browser Render 的流程與可以優化的地方

- [瀏覽器原理系列-瀏覽器渲染流程詳解](https://www.gushiciku.cn/pl/gpqt/zh-tw)

---

### 分類解答 - Network 相關

---

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

---

#### Question: Http status codes

Common

- `200` OK
- `301`, Moved Permanently, given new URL in response
- `302`, Found, changed temporarily
- `304`, Not Modified, cache used
- `307`, Temporary Redirect,
- `308`, Permanent Redirect,
- `400`, Bad Request,
- `401`, Unauthorized, 使用者需授權
- `403`, Forbidden, 使用者已授權但是沒有權限
- `404`, Not Found,
- `429`, Too Many Requests,
- `500`, Internal Server Error,
- `502`, Bad Gateway,
- `503`, Service Unavailable, 通常用於維護中

301 vs 302

- 使用時機與對 SEO 的影響參考 Reference 2

Reference 1. [HTTP response status codes](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)

Reference 2. [When to Use a 301 Redirect vs. 302 Redirect](https://www.seoclarity.net/resources/knowledgebase/use-301-redirect-vs-302-redirect-15683/#:~:text=The%20user's%20search%20experience%20may,page%20has%20taken%20over%20permanently.)

---

#### Question: cookie attributes: httponly, secure, session, samesite

- HostOnly, Session, Secure, HttpOnly, Domain, Path, Expiration, SameSite

Reference 1 [什麼是 Cookie？如何用 JS 讀取/修改 document.cookie?](https://shubo.io/cookies/)

---

#### Question: browser cross origin solutions

---

### 分類解答 - 後端相關

---

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

---

#### Question: Restful API design guidelines

- Do not use "physical" URLs, use logical url instead
  - URL 定位不要指向實際的檔案, 而是邏輯意義上的名稱. 例如移除副檔名
- Queries should not return an overload of data.
  - 一次查詢不要帶超量的資訊, 配合 paging 使用, 在 response 中帶上 prev, next 的 url 即可
- well documented, and do not change the output format lightly (since it will break existing clients).
  - 不要輕易的改變 response 的結構, 會破壞現有的客戶端程式碼
- Rather than letting clients construct URLs for additional actions, include the actual URLs with REST responses.
  - 與其讓客戶自行組合 URL 得到更多的功能, 不如直接回傳對應的 URL 給它呼叫
- `GET` access requests should never cause a state change.
  - `GET` method 永遠不會觸發後端狀態的改變, 應該永遠是 read-only 的行為

Reference 1. [9. REST Design Guidelines](http://rest.elkstein.org/2008/02/rest-design-guidelines.html)

---

### 分類解答 - 演算法實作

---

#### Question: Leetcode 1. two sum, 2. three sum

Answer:

- Leetcode [two-sum](https://leetcode.com/problems/two-sum/)

  - cache for searching

- Leetcode [3sum](https://leetcode.com/problems/3sum/)
  - cache for searching
  - sorted to minify searching times, however the time complexity will not change.

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

---

### 分類解答 - 其他技術問題

---

#### Question: 用過的 Design Patterns?

---

#### Question: Open Source project understanding & experience?

---

#### Question: Design Principles, SOLID

---

#### Question: Event-driven Design

- Event-Driven Architecture
  - 常見於微服務 microservice 裡的一種架構
  - JavaScript 甚至就是原生 event-driven 的程式語言
  - 不同於過去的 Request / Response 模式, 同步式溝通
  - 被視為是 asynchronous communication 非同步式溝通
  - 觀點從 data centric model 轉移到 event centric model, 注重的從 data 的完整性移動到 event 的即時處理
- 架構成員分成 Event Producers, Event Brokers, Event Consumers
  - 作到 Event Producers 與 Event Consumers 的解耦合
  - Event Brokers 是選用的, 最單純的 one producer to one consumer 只需要直接發送即可
  - Event Brokers 即 Message Queue 系統, 用來實現 event 的轉發與處理
- 驅動方式可以分成
  - Pub/sub 發送註冊制, 事件發送後 event published 主動給註冊的 subscribers
  - Event streaming 事件串流制, 不主動發送事件給 consumers, 事件以 log-based 的方式, 有嚴格的順序 strictly ordered 與永久性儲存 durable, Consumer 則主動以 pointer 的方式自由的讀取任意時間段的事件
- Event 事件
  - 行為或任務完成後, 拋出事件
  - 事件是任何系統上的狀態變動 a change of state
  - 重要的 event 必須是 immutable 的, 才能實現 replay
- Message Queue
  - 是實現 Event-Driven Architecture 常見的工具, 但是並不是必須的
  - 考慮到不同的使用情境, 選擇不同的 Message Queue 實作
  - 1. 只發送一次, 2. 訂閱機制, 3. 離線訊息, 4. 回放機制
  - Log based message queue 可以實現回放機制
- Event-Driven Architecture 的好處
  - 方便追蹤系統的各種狀態
  - 系統之間的解耦合
  - 資料的解耦合, 可以配合 Command and Query Responsibility Segregation, **CQRS** 實現更好的 throughput
  - 更容易實現微服務 microservice 與分散化 distributed 系統, 高度分散化 distributed 與擴張性 scalable
  - 提昇系統上的平行處理能力 parallel
- Event-Driven Architecture 的挑戰
  - Guaranteed delivery, 如何保證事件被處理 ?
  - Processing events in order or exactly once, 如何確保事件的處理順序 ?, 如何確保事件只被處理一次 ?
- Data 與 Event
  - Event 應該只包含最少的資訊, 例如 Ids, 來加速傳遞 latency 與提昇 throughput
  - Data 應該另外儲存在其他地方, 詳細的資料不應該隨著 Event 傳遞
- Event-driven 的應用
  - 程式語言: JavaScript
  - 使用情境: Browser UI, 其他 UI 設計
  - 程式撰寫風格: Reactive Programming, 實現的函式庫 RxJS, RxJava, ...
  - 系統架構: Event-driven architecture
  - 常配合的中間層: Message Queue

[Reference 1. 落實任務狀態事件化](https://medium.brobridge.com/%E8%90%BD%E5%AF%A6%E4%BB%BB%E5%8B%99%E7%8B%80%E6%85%8B%E4%BA%8B%E4%BB%B6%E5%8C%96-813a9366d42e)

[Reference 2. Event-driven architecture style](https://docs.microsoft.com/en-us/azure/architecture/guide/architecture-styles/event-driven)

[Reference 3. What is Event-driven Architecture?](https://www.tibco.com/reference-center/what-is-event-driven-architecture)

---

#### Question: Logging, Monitoring, 應該針對什麼

---

#### Question: git rebase 與 merge 的差別與範例

- 兩個指令的目的都在於合併分支
- `git merge`, Join two or more development histories together
  - 會產生額外的 merge commit
  - 可以保留個別的歷史紀錄
- `git rebase`, Reapply commits on top of another base tip
  - 會修改歷史紀錄, 並且遺失原本的 branch 紀錄
  - 把 commits 嫁接到目標的最後一個 commit 之後, 因此 commit hash 都會是新的
  - `git rebase -i` 互動模式可以更多的修改指定數量的歷史 commits
  - 產生線性的歷史紀錄

[Reference 1 【Git 教學】分支合併: merge 與 rebase 差異](https://www.maxlist.xyz/2020/05/02/git-merge-rebase/)

[Reference 2 Merging vs. Rebasing](https://www.atlassian.com/git/tutorials/merging-vs-rebasing)

---

### 面試時的提問

---

- 需求, UI/UX, use case, SCRUM / XP / Kanban, Git, Testing, CI/CD pipeline, Lint, Code Review
- Refactoring How and When
- Strategy of third-party library upgrade
- Daily work 應該是怎麼樣的
- 對於好的軟體的看法是什麼?
- 現有的系統架構與責任區分?
- 團隊分工狀況? 工程師的人數?
- 如何與其他團隊合作
- 團隊當前遇到最大的挑戰或最重要的事情
- 團隊未來的規劃?
- How a project is lead? 領導風格與方式
- 該職缺預期的 Impact 與 Scope
- Remote 的溝通管道, 同步與非同步
- 新創: 公司當前的狀態, Funding, 遠景, 目標
