## 忍者 JavaScript 開發技巧探祕
### BOOK resource, JavaScript

------------------

第一章 - 無所不在的 JavaScript

第二章 - 在執行期產生網頁

第三章 - 初探頭等函式：定義與引數

第四章 - 老手看函式：理解函式呼叫

第五章 - 大師級函式：閉包與範圍

第六章 - 未來的函式：生成器與約定

第七章 - 以原型來實現物件導向

第八章 - 控制物件存取

第九章 - 處理資料集合

第十章 - 正規表達式

第十一章 - 程式模組化技術

第十二章 - 文件物件模型

第十三章 - 搞懂事件

第十四章 - 跨瀏覽器開發策略

附錄A - ES6 的額外功能

附錄B - 用測試和除錯技術裝備自己

------------------


### 第一章 - 無所不在的 JavaScript

#### 了解 JavaScript 程式語言
  * function is first-class object
  * function closure
  * 變數範圍 (scope)
  * 基於原型的物件導向 (prototype-based)

#### JavaScript 的演化
  * ECMAScript 每年持續小部份的增加
  * 使用前先查詢新功能在各平台的支援度
  * 使用轉譯器 (transpiler), Babel, Traceur

#### 瀏覽器環境
  * Document Object Model (DOM), 
  * 事件 (Event), 
  * 瀏覽器 API,  

#### 使用的最佳實務
  * Debug, 善用各瀏覽器的開發者工具 DevTools
  * Testing,
  * Performance analysis, `console.time()`,`console.timeEnd()`, 計時器, 可以用來紀錄執行時間，做效能分析。

#### JavaScript 其他平台
  * 桌面應用程式, NW.js, Electron
  * 行動裝置, Apache Cordova, React Native
  * 伺服器端程式, Node.js


------------------------------


### 第二章 - 在執行期產生網頁

#### 網頁程式生命週期
  * 如同一般 GUI 應用程式一樣, 1. 建立使用者界面 2. 處理事件。
  * 頁面建立, 交替執行
    * 分析 HTML 建立 DOM, HTML是藍圖, DOM 由瀏覽器製作不一定完全依照 HTML, 可能會自行修正潛在的問題。
    * 執行 JavaScript, 遇到 `<script>` 則會停止解析 HTML 並且立即執行 JavaScript 內容。
  * 參考 HTML 規格書, DOM 規格書

#### 瀏覽器上執行 JavaScript
  * JavaScript 執行引擎, Chrome (V8), Firefox (Spidermonkey), ...
  * 瀏覽器環境上的全域物件, `window`, 頁面所屬的視窗
  * 參考 瀏覽器 API

#### 事件處理
  * 瀏覽器執行環境中是單一執行續的 (single-threaded execution model)
  * 事件等待佇列 (event queue), 瀏覽器會持續檢查 event queue 中是否有在等待處理的事件, 並且一次只能處理一個事件, 其他事件仍會在 event queue 中持續等待。
  * 瀏覽器事件, 網路事件, 使用者事件, 計時器事件

#### 註冊事件處理器
  1. 執行函式指定給特殊屬性 (attribute), 一個事件只能有一個事件處理, **不推薦使用**
  1. 使用 `addEventListener()`, 一個事件可以註冊多個處理函式。


------------------------------


### 第三章 - 初探頭等函式：定義與引數

#### 函式作為頭等物件
  * 函式即物件，因此可以
    * 指派給變數, 存入其他資料結構中
    * 作為引數傳入其他函式
    * 作為函式回傳值
    * 為函式新增屬性
  * 函式是可被呼叫執行的物件 (callable)

#### 回呼函式 (callback function)

#### 儲存函式

#### 自我記憶函式 (self-memoizing function)
  * 利用函式即物件, 在函式物件上新增屬性作為 cache 儲存空間。

#### 定義函式
  * 函式宣告 (declaration), `function functionName () {}`
  * 函式表達式 (expression), `var functionName = function () {}`
  * 箭頭函式 (arrow function, lambda function), `() => {}`
  * 函式物件建構子 (constructor), `new Function()`, **不要使用，有安全疑慮** 
  * 生成器函式 (generator function), `function* functionName() { yield }`

#### 立即執行函式 (immediately invoked function expression, IIFE)
  * 函式定義後立即呼叫執行
  * `(function () {})();`
  * 配合一元算子的 IIFE, `+function(){}();`, `-function(){}();`, `!function(){}();`, `~function(){}();`

#### 箭頭函式 (arrow function)
  * param `=>` expression
  * `( parameters )`, 單個引數可省略
  * `{ multiple expressions }`, 單個表達式可省略, 並且自動回傳結果 `return` 

#### 不定參數 (rest parameter)
  * `function functionName(namedParameters, ...restParameters)`
  * `...`, 把多餘數量的引數存放到陣列中


#### 預設參數 (default parameter)
  * `function functionName (parameters , parameter = defaultValue)`
  * `=`, 放置預設值
  * 未傳入引數時, 原生預設值是 `undefined`


------------------------------


### 第四章 - 老手看函式：理解函式呼叫
  * 隱含參數, `this`, `arguments`

#### `arguments`
  * 傳入函式的引數集合, **類**陣列物件, 具有 `length` 屬性
  * arguments 中存放的是引數的變數參考 (reference), 修改時會有邊際效應。
  * 嚴格模式下 `"use strict"`, arguments 取得的參數並非 reference 而是值。

#### `this`
  * function context
  * `this` 由 function 的呼叫決定，而非定義時決定。

#### 函式呼叫
  * 作為函式, `functionName()`, `this` 是全域變數, 嚴格模式下是 `undefined`
  * 作為成員函式, `objectName.memberFunction()`, `this` 是所屬的物件
  * 作為建構子, `new FunctionName()`,
    * `new`, 1. 建立空物件, 2. this 指向新物件, 3. 回傳 (return) 新物件
    * 如果建構子函式中明確回傳 `return` 其他物件， `new` 回傳值會放棄新物件使用明確回傳的物件。
  * 通過函式方法 `apply`, `call` 呼叫, 明確指定 `this`

#### 一勞永逸的修正 `this`
  1. 箭頭函式 (arrow function), `this` 自動綁定函式建立時的 this，而非呼叫時決定。
    * 小心物件實字時的 `this` 是全域變數
  1. `bind`, 綁定指定的 this 並且回傳新函式。


------------------------------


### 第五章 - 大師級函式：閉包與範圍

#### 閉包 (closure)
  * 讓函式能存取及操作在函式定義時所有作用範圍內的變數及其他函式。
  * 操作函式外部但是作用域內的變數，即產生閉包並且生成獨立的字彙環境，因此會延長閉包內的變數存活期。
  * 閉包產生各自獨立的字彙環境 (lexical environment), 因此閉包會造成額外的 memory 消耗。

#### 模擬私有變數
  * 通過雙層函式的 closure 產生私有變數，即從函式外部無法直接存取。

#### 回呼函式與閉包作用
  * 利用閉包在定義回呼時產生各自的變數生存範圍。(每個閉包內就算同名的變數也不會互相影響)
  * 讓在實際呼叫時，仍有正確的變數資料。(需要區分 定義時 與 執行時 的變數差別)

#### 執行背景空間堆疊 (execution context stack / call stack)
  * JavaScript 執行時有兩種執行環境, 
    1. 全域環境 global execution context
    1. 函式執行環境 function execution context 

#### 字彙環境 (lexical environment)
  * 即 variable scope
  * 每個函式被建立時的字彙環境，存在內部屬性 `[[Environment]]` 中。

#### JavaScript 中的變數類型
  * `const`, block scope, 必須被初始化, 並且只能被賦值一次 (即初始化時)。
  * `var`, function scope, 變數是被定義在**最近的函式或者全域**字彙環境中。 
  * `let`, block scope, 

#### Hoisting
  * JavaScript
    1. 建立字彙環境, 會註冊所有範圍中的宣告, 因此在執行時可以被直接使用。
    1. 執行
  * 簡化說法為 JavaScript 建立字彙環境時，會自動提昇**宣告**至範圍的開頭。只有宣告會被拉到開頭，而賦值不會。

#### 探索閉包 (closure) 與字彙環境 (lexical environment) 和執行空間 (execution context)


------------------------------


### 第六章 - 未來的函式：生成器與約定


------------------------------


### 第七章 - 以原型來實現物件導向


------------------------------


### 第八章 - 控制物件存取


------------------------------


### 第九章 - 處理資料集合


------------------------------


### 第十章 - 正規表達式


------------------------------


### 第十一章 - 程式模組化技術


------------------------------


### 第十二章 - 文件物件模型


------------------------------


### 第十三章 - 搞懂事件


------------------------------


### 第十四章 - 跨瀏覽器開發策略


------------------------------


### 附錄A - ES6 的額外功能


------------------------------


### 附錄B - 用測試和除錯技術裝備自己


478