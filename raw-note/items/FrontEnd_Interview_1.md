## FrontEnd Interview Questions 2020 - 2021

### FrontEnd_Interview

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

- closure 與 this?

  closure, 藉由函式產生的 lexical environment (變數環境), 讓內層函式可以存取外層函式的值

  closure 應用

  - private member
  - 在沒有 let 與 const 之前，使用 closure 產生 scope 綁定正確的值

  Reference 1. [closure mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Closures)

  `this`, 呼叫時期才動態綁定的 pointer

  Reference 1. [this mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this)

- event loop, macro task 與 micro task? Promise 的同步與非同步? 執行順序? then 的執行順序

  `new Promise()` 是同步的, `.then()` 是非同步並且是 micro task

  Reference 1. [Event loop mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/EventLoop)

  Reference 2. [我知道你懂 Event Loop，但你了解到多深？](https://yeefun.github.io/event-loop-in-depth/?fbclid=IwAR1Q-4-8N2zdGEgcilB6mkgKGG_8wsDFRr48F5hajUBim4LXCPTiJM7bn0I)

  Reference 3. [Microtask mdn](https://developer.mozilla.org/en-US/docs/Web/API/HTML_DOM_API/Microtask_guide)

- JavaScript type converse, `==` algorithm?

  概略:

  1. 都是 object 時比較 reference,
  1. `null` 與 `undefined` 為 `true`
  1. number 與 string 比較時, 會先將 string 轉換成數字 (`ToNumber()`)
  1. boolean 會轉換成 `true` -> `1`, `false` -> `+0`
  1. object 與 string 或 number 比較時會呼叫 `valueOf()` 與 `toString()`

  Reference 1. [== mdn](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Equality)

- V8 Garbage Collections, `scavenge algorithm`, `young generation`?

  V8 引擎中的 GC 分成 `young generation` 與 `old generation`

  - 分別使用不同的 garbage collection algorithm
  - young generation 重點在於快速的 GC, 採用 `scavenge algorithm` 使用複製的方式從 from-space 到 to-space 一次性處理完清除與重排
  - 當一組資源在 young generation 被執行過數次 GC 之後仍存在的話，會被搬移到 old generation
  - old generation 使用 Mark-Sweep 和 Mark-Compact 演算法來處理清除與整理

  Reference 1. [Node.js 內存管理和 V8 垃圾回收機制](https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/665962/)

  Reference 2. [Trash talk: the Orinoco garbage collector](https://v8.dev/blog/trash-talk)

- Decorator pattern in JavaScript

  取代創建 subclass 的方式，使用傳入原始物件的方式擴充功能。在 JavaScript 中可以非常容易地做到，因為 JavaScript 中的物件是 runtime 可修改的並且 member function 可以被重新賦值

  Reference 1. [The Decorator Pattern - Learning JavaScript Design Patterns by Addy Osmani](https://www.oreilly.com/library/view/learning-javascript-design/9781449334840/ch09s14.html)

### 分類解答 - React 相關

- Redux Reselect 的 selector 做了什麼?

  Reference 1. [reselect GitHub repository](https://github.com/reduxjs/reselect)

- Hook 實作倒數? useState, setTimeout, clearTimeout
- setState 與 React 執行流程?
- React 核心, diff 演算法?
- Redux, how to diff state change and trigger notification?

### 分類解答 - 前端常見問題

- 前端儲存資訊的地方? (cookies, local store, sessions, indexDB)
- 如何判斷使用者語系? (IP detect, User Agent)
- CSS 置中方法? flexbox, absolute + relative, grid
- Bundle size minify 的方法? Webpack minify, tree shaking, dynamic import 與 CommonsChuckPlugin

### 分類解答 - Network 相關

- Browser cache policy, service worker, http cache?
- http headers, etag v.s. Last-Modified?
- Prevent XSS with http header (Content Security Policy, CSP)?
- SSR with 'isitc', 'service mesh'

### 分類解答 - 後端相關

- Restful API naming convention

### 分類解答 - 演算法實作

- Leetcode 1. two sum, 2. three sum
- function `compose` 實作?
- Algorithm 1. 生成 `()` tree 與 backtracking algorithm
- Algorithm 2. check linked list is recursion?

### 分類解答 - 其他技術問題

- 用過的 Design Patterns?
- Open Source project understanding & experience?

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
