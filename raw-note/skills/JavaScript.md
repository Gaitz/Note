## JavaScript

### Computer Science

---

第一章 - Common Questions

第二章 - Study

---

### 第一章 - Common Questions

- JavaScript data types

- JavaScript predefined objects

- JavaScript prototype chain

  - instance`.constructor.prototype`, 即 ConstructorFunction prototype
  - instance`.__proto__` 即 instance 所使用的 ConstructorFunction prototype
  - instance`.prototype` add member functions and members
  - JavaScript 物件導向, 是原形鍊模式

- JavaScript inheritance

  - Child`.prototype = new` Parent`()`
  - Child`.prototype.constructor =` Child

- JavaScript create object

  - `{}`
  - constructor function + `new` 記得命名慣例要大寫
  - empty function + `prototype`

- JavaScript scope

  - lexical scope, **lexical environment**, `[[Environment]]`
  - **Execution Context**, Call Stack, Global Execution Context and Function Execution Context

- JavaScript `this`

  - 指向呼叫者 caller
  - 所以通常會以慣例 **self** 另存
  - 使用 `bind()` 強置綁定
  - 使用 arrow function `=>` 強置綁定
  - 在全域的部份呼叫得到的 `this` 會是指向 runtime 的 global object, 例如: browser `Window`, Node.js

- JavaScript **closure**

  - 建立 scope, lexical scope
  - 原本的 JavaScript 只有 function scope, 因此使用 nested function 形成 scope 來保護值不會被任意變動
  - 注意到 JavaScript 所謂的 function scope 是指 assigned parameters
  - 在擁有 `let` 與 `const` 後較少用
  - ```javascript
    // compare these two cases

    for (var i = 0; i < 3; i++) {
      var execFunction = (function () {
        return function () {
          console.log(i)
        }
      })()
      arr.push(execFunction)
    }

    for (var i = 0; i < 3; i++) {
      var execFunction = (function () {
        return function (i) {
          console.log(i)
        }
      })(i)
      arr.push(execFunction)
    }
    ```

- JavaScript `use strict`

  - 嚴格模式, 避免使用舊有的 JavaScript bad pattern

- JavaScript `new` 的執行流程

  - 建立空物件 -> 綁定 `__proto__`, prototype -> 回傳 `this`

- **Ajax**, Asynchronous JavaScript and XML

- JavaScript module

  - module pattern, 以 closure 封裝避免全域污染
  - AMD 與 CMD 規範
  - JavaScript 原生 module

- JavaScript Event loop + JavaScript Runtime,

  - [Ref: 我知道你懂 Event Loop，但你了解到多深？](https://yeefun.github.io/event-loop-in-depth/?fbclid=IwAR1Q-4-8N2zdGEgcilB6mkgKGG_8wsDFRr48F5hajUBim4LXCPTiJM7bn0I)
  - JavaScript 可以建立在不同的 host runtime 上, 例如 Browser, Node.js, 並且自行實踐不同的 event loop 實作
  - 建立在 JavaScript single thread 實現非同步行為與不阻塞 non-blocking
  - JavaScript 是 single thread 但是 JavaScript runtime 不一定是 single thread
  - 依據 runtime 不同會有 Web APIs 的工作, 丟給 browser 專門負責的 thread 執行
  - event loop 也會分成 **window event loop**, **worker event loop**, **worklet event loop** 在各自的 thread 進行
  - **window event loop** Callback queue (**macro tasks**) 會分成多個不同類型的 queue, 例如 DOM queue (包含 user events, HTML parsing), Network queue, Timer queue, 為此每個 queue 會有不同的優先權
  - **micro task queue**, 會盡可能的執行完成, 在同一個 event loop 裡會清空, 屬於此類的有 `Promise.then()`, `queueMicrotask` API, `MutationObserver`
  - 並不是每輪 event loop 都會觸發 rendering, 取決於運算時間受 browser 後台控制, fps,
  - 瀏覽器藉由降頻 60fps 到 30 fps 甚至 4 fps, 讓每個 frame 能有更長的執行時間, 但換取的是螢幕刷新率
  - **只有對於會渲染 rendering 的 frame** 才會依序執行或發送 event,
    1. **resize**,
    1. **scroll**,
    1. **requestAnimationFrame** callback,
    1. **IntersectionObserver**,
    1. **reflow**,
    1. **repaint**
  - 並且結束後在 marco queue 與 micro queue 皆空時, 會觸發 `requestIdleCallback`

- JavaScript `requestAnimationFrame`, `requestIdleCallback`

  - [Ref: 面試官：請說說 EventLoop 和瀏覽器渲染、幀動畫、空閒回撥的關係](https://www.gushiciku.cn/pl/pEI7/zh-tw)
  - `requestAnimationFrame`, 會在 repaint 之前執行, 並且可能會因為執行 macro task 而被省略,
  - 導致使用 marco task 撰寫的動畫會有卡頓的問題, 因此推薦動畫使用 `requestAnimationFrame` callback 來實作, 確保每個 frame 如果要渲染前都會執行到動畫運算, 因此更流暢
  - `requestIdleCallback`, 在渲染後並且沒有其他工作時, 允許使用者使用的時間, 會依據繁忙程度來決定是否執行

- JavaScript Hoisting

  - [Ref: 我知道你懂 hoisting，可是你了解到多深？](https://blog.techbridge.cc/2018/11/10/javascript-hoisting/)
  - function define hoisting 優先於 variable
  - **Temporal Dead Zone** 對於 `let`, `const` hosting 後, 使用前的錯誤參照期, V8 實作上使用 **Hole** 取代 `undefined`

- V8 Garbage Collection
  - [Ref: 干货：浏览器渲染引擎 Webkit 和 V8 引擎工作原理](https://segmentfault.com/a/1190000018806562)
  - **New generation** and **Old generation**, 新生代與舊生代
  - 新生代被視為可能會更快清除的, 在新生代經過數次 garbage collection 後仍存活會被移動到 **Old generation**
  - New generation, 使用 **Scavenge** algorithm, 把空間分成兩半 **semispace**, 以區塊整體複製移動為基礎, 減少 memory fragment
  - Old generation, 使用 **Mark-Sweep** algorithm, 全部空間都使用記憶與清除模式, 可能會造成 memory fragment 但是空間利用率高

---

第二章 - study

---

WeakRef

- 特性
  - weak ref 意味著物件並不會影響所持有的成員的 garbage collection
  - 換句話說, 他不會佔用 ref 而讓 garbage collection 無法執行
- 用途
  - 多用於即使被 garbage collection 也沒關係的情況
  - 例如: cache 的實作, 資源的 manager (像是 event 的集中管理)
- Object `WeakRef`
  - `deref()` 取值
- `WeakMap`
- `WeakSet`
- `FinalizationRegistry`
  - 註冊物件被 garbage collection 時, 執行 callback
