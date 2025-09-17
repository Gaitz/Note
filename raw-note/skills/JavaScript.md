## JavaScript

### Computer Science

---

第一章 - Interview Common Questions

第二章 - Dive into Javascript

---

第一章 - Interview Common Questions

---

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

第二章 - Dive into Javascript

---

String

- `charCodeAt` vs `codePointAt`
  - **關鍵 JavaScript String 的 length 與 index 數的是 UTF-16 的 code units, 而非 code points**
    - 因此在字元中包含 BMP 以外的字元時, UTF-16 會需要 2 個 code units 來實現 (16 \* 2 = 32 bits),
    - 此時 index 與 length 就會在 code units 與 code points 上具有區別
  - `charCodeAt`, 取得指定位置的 UTF-16 code unit, (UTF-16 code unit = 16 bits, 因此值的範圍在 2^16 = 65536, 0..65535)
  - `codePointAt`, 分成兩個情況,
    - 如果指定位置是 UTF-16 中的 leading surrogate 則回傳相對應的 Unicode code point
    - 如果指定位置是 UTF-16 中的 tail surrogate 則回傳該 tail surrogate 的 code unit 值
  - `charAt`, 回傳指定 index 位置的一個字串,
    - 如果此時 index 位置是屬於 UTF-16 中的 BMP 字串, 則回傳該字串
    - 如果此時 index 指向的 code unit 並非是 BMP 內的字元, 則回傳值是以字串表達的該 code unit 的值, 以開頭 `\u` 加上他的編號
  - `at`, 輸入值允許正整數與負整數, 負整數時則是反向尋找, 輸出值是一個字串
    - 效果等同於 `charAt`, 但是允許負數從反向數; 而 `charAt` 的輸入值只允許正整數
- 關鍵字 UTF-8, UTF-16, Unicode
  - 電腦編碼, 持續擴張與統一標準
  - Unicode, 統一標準與擴充
  - UTF, Unicode Transformation Format
  - UTF-8 編碼系統, 為 Unicode 標準的一種表示方式, 多數網路協定的預設編碼, 也是多數軟體與程式語言的預設編碼
  - UTF-16 編碼系統, 為 Unicode 標準的一種表示方式
- 關鍵字 Unicode Plane
  - 一個 plane 大小為 2^16 (65536) 個 code points
  - Unicode 標準中可以被分為 17 個 plane, plane 0 ~ plane 16
  - `U+` 標示的前兩個 16 bits 代表的就是 plane 編號
  - 17 planes 限制是因為 UTF-16 的容量上限所導致
  - 目前並不是所有的 planes 都已經被使用, 仍有很多 plane 尚未規劃用途
- 關鍵字 code point, code unit
  - code point 代表 unique number for each character
  - code unit 代表一個編碼系統中最小的長度單位
    - UTF-8, 8 bits 即 1 byte 為最小單位,
    - UTF-16, 16 bits 即 2 bytes 為最小單位
- 關鍵字 ASCII code, 範圍在 2^7 = 128 個 code points
- 關鍵字 Endianness
  - Big-endian, 高位元組 (byte) 放置於低記憶體位置
    - 網路協定主流使用
  - Small-endian, 低位元組 (byte) 放置於低記憶體位置
    - 多數 CPU 使用
- 關鍵字 Byte Order Mark, BOM
  - 用來標示文字是 big-endian 還是 small-endian
  - 通常使用 Unicode 中的 `U+FEFF` 來做標示, `FE FF` 為 big-endian ; `FF FE` 為 small-endian
- 編碼標準中通常是長度可變的, 為了向下相容和節省空間, 麻煩點在於會帶來額外的計算
- UTF-8, 長度範圍在 1 ~ 4 bytes, 甚至可以持續擴充
  - **向下相容 ASCII code**, 因此最開始的 `0x00` ~ `0x7F` 完全等同於 ASCII 編碼
  - 由前幾個位元決定, 此次是以幾個 bytes 為單位形成的 code point
  - 第一個 bit 以 `0` 開頭則為 ASCII, 只需要 1 個 byte, 除去最高位剩下的 7 位元剛好符合 ASCII 的需求, 因此完全相等
  - 開頭為 `110` 代表 2 個 bytes, `1110` 代表 3 bytes, 以此類推
  - 並且每個 byte 除了首個 byte 之外的, 數值都以 `10` 開頭
  - 理論上 UTF-8 可以允許的 code points 範圍比 UTF-16 更廣
- UTF-16, 長度範圍則是 2 or 4 bytes
  - 支援 1,112,064 個 Unicode 中的 code points
  - 向下相容和最常用的部分 (Unicode 中的 Base Multilingual Plane, BMP), 每個 code point 只需要 2 個 bytes (16 bits) 即可
    - 此時等價於 UCS-2
  - 擴充的部分 (U+10000 ~ U+10FFFF, Supplementary Planes) 才需要 4 個 bytes (32 bits) 組成 surrogate pair
  - surrogate pair 可以被分為 lead surrogate 與 tail surrogate,
    - 針對 Unicode 序號 - `0x10000` 取得的 20 bits 二進制, 分成前 10 bits 與後 10 bits
    - 前 10 bits + `0xD800` 加上前綴的 `110110` 即得 16 bits 的 lead surrogate
    - 後 10 bits + `0xDC00` 加上前綴的 `110111` 即得 16 bits 的 tail surrogate
    - 附註: `0xD800` 的前 8 bits 為 `1101 1000`; `0xDC00` 的前 8 bits 為 `1101 1100`
  - 因為在 Unicode 中的 `0xD800` ~ `0xDFFF` 在 BMP 中為保留區塊, 不會有 code point 對應,
    - 因此 UTF-16 把這個範圍的值作為 lead surrogate 與 tail surrogate 的範圍使用
  - UTF-16 中 BMP 的 16bits, lead surrogate 與 tail surrogate 的值範圍剛好是互斥的,
    - 因此具備 self-synchronizing, 可以從單一個 16 bits 就能得知他是屬於哪個部分
- 選用 UTF-8 還是 UTF-16 取決於所需字元的範圍
  - 在過去 May 2019 以前 Windows 和 Qt 只支援 UTF-16, 在此之後 UTF-8 幾乎是最推薦使用的編碼系統也是預設的編碼系統
  - 通常英文字母多的情況下使用 UTF-8 有空間優勢
  - 在中文字比較多的情況下使用 UTF-16 比較有空間優勢
  - 這是因為在 BMP 中的中文字, 在 UTF-8 以 3 bytes 來表示, 而 BMP 中所有的字在 UTF-16 都是 2 bytes 來表示
- 1 byte = 8 bits
- a hex can represent 4 bits, 2^4 = 16
- a byte = 8 bits, 2 個 hex 可以表示, 其範圍在 2^8 = 256
- 2 bytes = 16 bits, 4 個 hex 可以表示, 其範圍在 2^16 = 65536
- 在看程式語言時, 可以關注一下他們的 String 中的函式支援的是 UTF-8 還是 UTF-16
