## 忍者 JavaScript 開發技巧探祕
### BOOK resource, JavaScript

非常不錯的 JavaScript 進階書籍，內容包含 ES6，並且深入底層講解原理。

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
  * 生成器函式 (generator), 特殊的函式, 在 Python, PHP, C# 中也有此功能。
  * 約定 (promise), 對未來的封裝。

#### 生成器函式 (generator)
  * 可以生成多個值，但是每次請求只會回傳一個。
  * 每次回傳值之後，函式只是暫停，等待下一個請求後才繼續執行。
  * `function* generatorFunction() { }`, 
  * `function*`,
  * `yield`, 回傳值
  * generator 函式可被用在 `for...of`。 `for (let aValue of generatorFunction())`

#### 呼叫生成器函式 (generator)
  * 呼叫生成器函式，會產生新的一個 iterator 用來與 generator 互動。
  * `const aIterator = generatorFunction();`
  * `next()`, 取得下一個 `yield` 的值
  * `done`, 屬性確認是否結束

#### 生成器回傳另一個生成器 (generator)
  * `function* outerGenerator() { yield* otherGenerator(); }`
  * `yield*`, 串接另一個生成器

#### 生成器使用範例 (generator)
  * id 生產器，yield 配合無窮迴圈。
  * 走訪 DOM, 遞迴的生成器, yield, yield*, 配合 for...of 取值。

#### 生成器函式引數 (generator)
  * 如同一般函式一樣，生成器函式也能傳入引數，藉此可以達到雙向溝通。
  * 傳入時機
    1. 第一次呼叫生成器函式時, `generatorFunction(  )`;
    1. 呼叫 `next()` 函式時, `next(  )`

#### 生成器函式與例外處理 (generator)
  * 通過 `iterator.throw()` 傳遞例外給生成器函式，因此在生成器函室內也能捕捉到外部傳入的例外。

#### 生成器原理 (generator)
  * 使用 function execution context 與 lexical environment 解析生產器原理。
  * 與一般函式不同在於 yield 後 execution context 從 stack pop 出來後並沒有消失。
  * iterator 抓著執行到一半的 lexical environment 所以不會被垃圾回收，直到下次呼叫 `next()` 又會生成一次 function execution context 放到 stack 上配合 iterator 先前暫存的 lexical environment。

#### 約定 (promise)
  * 用來處理非同步行為 (asynchronous)
  * `new Promise( (resolve, reject) => { resolve(); reject(); })`
  * 以簡單的 callback function 實作非同步功能時的缺點， 1. 錯誤不好捕捉, 2. 具有相依性時的 callback hell, 3. 等待多個同步執行後的結果不易
  * 未解決狀態 -> 通過 resolve 或 reject 變為已完成狀態。只會則一觸發並且不會多次觸發。

#### resolve()
  * 對應 `.then()`

#### reject()
  * 對應 `.catch()`
  1. 使用 `reject()` 明確的拒絕
  1. 當例外發生並且沒有被 try-catch 捕捉處理時，隱含的拒絕

#### Promise 的串接
  * 利用 `then()` 的串接解決非同步的相依性產生的 callback hell。

#### 等待多個 Promise 完成
  * `Promise.all([])`, 解決多個平行的非同步呼叫時的等待。
  * Promise.all() 回傳的也是一個 Promise 因此可以使用 `then()`, `catch()` 繼續處理。
  * `Promise.all()`, 會等待所有的 Promise 都完成。
  * `Promise.race([])`, 只要其中有一個 Promise 被 resolve 或 reject 則 `race()` 回傳的 promise 也會完成。

#### Promise 與 generator 共同使用

#### `async` 與 `await`
  * `async` 指出函式是非同步的
  * `await` 指出此處需要等待回傳，但是程式不應該被停下來。 


------------------------------


### 第七章 - 以原型來實現物件導向
  * 重用程式碼的方法之一，繼承

#### 了解原型 (prototype)
  * 每個物件都有一個原型 (reference)
  * 物件原型 `[[prototype]]` 是內部屬性，無法直接存取。
  * `Object.setPrototypeOf`, 可以指定物件的原型
  * 原型鍊 (prototype chain), 物件原型之間互相連接，因此可以在原型練上搜尋所要的屬性，以實現繼承功能。

#### 建立物件
  * 實字建立 `{ }`
  * 建構子函式建立 `function ConstructorName() { }`, 配合 `new` 創建。
  * 在建構子函式中 `this.` 所創建的是 instance 屬性，屬於各個物件自己的。
  * 建構子函式的 `prototype` 屬性 (只有函式才有的屬性)，可以直接存取原型，並且會影響所有原型鍊上的物件。因此共用的方法最好放在原型上。

#### 動態修改建構子函式原型時的副作用
  * `ConstructorFunction.prototype = {}`
  * 直接覆蓋建構子函式的 prototype 時，並**不會影響到**已經被建構出來的舊物件。
  * 只有在新建立的物件才會使用新的原型

#### 物件的 constructor 屬性
  * 每個物件上都有 `constructor` 屬性指向他的建構子函式。
  * 可以被任意修改, 呼叫。
  * 甚至呼叫用來創建另一個物件 `const object2 = new object1.constructor()`

#### 實現繼承
  * `ChildConstructor.prototype = new ParentConstructor();`
  * 藉由原型鍊的串接產生正確的繼承關係。可由 `instanceof` 正確判斷繼承關係。
  * 缺點是子物件的 constructor 變成了父物件建構子函式。

#### 物件屬性的細節控制項 (property descriptor)
  * configurable,
  * enumerable, 
  * value,
  * writable,
  * get, getter function
  * set, setter function
  * 使用 `Object.defineProperty()` 設定以上屬性控制項
  * 通過手動補上 `constructor` 解決子物件的建構子連結關係, `Object.defineProperty(Child.prototype, "constructor", { enumerable: false, value: Child, writable: true });`, 重點在於 `value` 指向子物件建構子函式。

#### JavaScript `instanceof`
  * `instanceof` 檢查的是原型鍊 (prototype chain)，而非 `constructor` 屬性
  * 因此當原型鍊被動態修改時, `instanceof` 的結果可能會跟著改變。 

#### JavaScript `class`
  * ES6 語法糖, `class`,  `constructor()`, `static`
  * `class ClassName { constructor () {} static aStaticMethod () {} }`,
  * static method 在 ES5 中只是在建構子函式物件上的新增方法。`ConstructorFunction.aStaticMethod = function () {}`

#### JavaScript `extends`
  * ES6 語法糖, `extends` 實現繼承, `super()` 呼叫父層建構子函式
  * `class Child extends Parent {}`


------------------------------


### 第八章 - 控制物件存取
  * getter, setter, proxy

#### 定義 getters 和 setters
  * 以函式的方式定義，以屬性的方式操作。關鍵字 `get`, `set`, 同時是方法也是屬性。隱性的呼叫函式
  1. 物件實字建立, `obj = { get name() {}, set name() {} }`, `obj.name`, `obj.name = `
  1. `class` 建立, `class ClassName { get name(){} set name(){} }`
  1. `Object.defineProperty()` 建立屬性並賦予 getter 和 setter 函式, 在建構子函式中 `Object.defineProperty(this, name, { get: () => {}, set: () => {} });`
  * 使用時機之一: 如果一個值是依據物件內部狀態，可以把他視為一個屬性，而非方法取用。

#### 使用 Proxy 控制物件的存取和擴充功能
  * 更全面的 getter 與 setter 攔截並且控制物件, 與一般的 getters, setters 無異, 都是隱含的函式呼叫。
  * 建立一個代理物件, `new Proxy(target, { get: ,set: })`
  * 使用時機為整個物件添加功能，例如 logger, 處理 null 自動建立, 插入效能檢測, ..., 類似 middleware
  * handlers, 
    * `get`, 攔截所有屬性的 getter
    * `set`, 攔截所有屬性的 setter
    * `apply`, 攔截所有的成員函式呼叫

#### 使用 Proxy 的成本
  * 因為每次都需要經過 proxy 中的函式呼叫，會產生大量的效能成本。
  * proxy 需小心使用，避免造成效能問題。


------------------------------


### 第九章 - 處理資料集合

#### 陣列 (array)
  * 建立陣列
    * 建構子建立, `new Array()`
    * 實字建立, `[]`, 推薦使用
  * 自動擴張, 取邊界外的值只會回傳 `undefined` 而非報錯，因為 JavaScript 中的 array 只是個物件。
  * 新增與移除元素
    * `push`
    * `unshift`
    * `pop`
    * `shift`
    * 效能考量, (push, pop) 只修改最後一位效能明顯比 (unshift, shift) 快速。
  * 隨機新增與移除
    * by index, `[index]`
    * `delete`
  * 陣列迭代
    * `for (let i = 0; i < anArray.length; i++) {}`
    * `forEach( function )`
  * 陣列對應
    * `map( function )`
  * 測試陣列資料
    * `every( function )`, 全部都符合則 true
    * `some( function )`, 其中有一項符合則 true
  * 搜尋陣列
    * `find( function )`
    * `filter( function )`
    * `indexOf( element )`
    * `lastIndexOf( element )`
    * `findIndex( function )`
  * 陣列排序
    * `sort( function )`
  * 陣列資料整合
    * `reduce( function )`
  * 在其他物件中重複使用陣列內建函式
    * `Array.prototype.functionName.call()`
    * `Array.prototype.functionName.apply()`

#### 對應表 (Map)
  * 使用物件 (object) 作為對應表時的缺點,
    1. key 只能是字串, 使用非字串時也會隱含的呼叫 `toString()`
    1. 可能會遇到名稱與原生屬性重複的狀況, 例如 `constructor`, ... 
  * 建立 `Map`
    * `new Map()`
    * `set()`
    * `get()`
    * `size`
    * `has()`
    * `delete()`
  * 迭代 `Map`
    * `for...of`

#### 集合 (Set)
  * 不重複的資料集合
  * 建立 `Set`
    * `new Set()`
    * `add()`
    * `has()`
  * 迭代 `Set`
    * `for...of`
  * 聯集 (union)
    * `unionSet = new Set([...setA, ...setB])`
  * 交集 (intersection)
    * `intersectionSet = new Set([...setA].filter(e => setB.has(e) ))`
  * 差集 (difference)
    * `differenceSet = new Set([...setA].filter(e => !setB.has(e) ))`


------------------------------


### 第十章 - 正規表達式

#### 建立正規表達式 (regular expression)
  * 實字建立, `/ /`, 推薦使用
  * 建構子建立, `new RegExp()`, 只有當表達式是執行期才動態決定的時候才使用。(runtime)

#### 旗標 (flags)
  * `i`, case insensitive, 不區分大小寫 
  * `g`, global, 全部匹配
  * `m`, multiple line, 多行文字匹配
  * `y`, sticky matching, 
  * `u`, 對 Unicode point 跳脫

#### 詞彙 (term) 與 運算子 (operator)
  * `[]`
  * `[^]`
  * `[-]`
  * `\`, 跳脫字元
  * `^`, 行首
  * `$`, 行尾
  * `^$`, 同時使用時則表示要比對整個字串
  * 量詞
    * `?`, 0, 1
    * `+`, > 1
    * `*`, >= 0
    * `{}`, 
    * `{,}`
    * greedy mode 預設是貪婪的, 量詞配合 `?` 變成不貪婪模式 (nongreedy), 例如 `a+?`
  * 預設字彙集合
    * `.`, 換行字元 (\n, \r, \u2028, \u2029) 以外的所有字元
    * `\d`, `[0-9]`
    * `\D`, `[^0-9]`
    * `\w`, `[A-Za-z0-9_]`
    * `\W`, `[^A-Za-z0-9_]`
    * `\s`, 任意空白, 空格, tab, 換行等等
    * `\S`, 空白字元以外的字元
  * 分組, `()`
  * 或, `|`
  * 分組參照, `\1`, `\2`, ...

#### 編譯與執行
  * 每個正規表達式的宣告都是獨一無二的就算內容相同也是。
  * 每一次的宣告都會進行一次編譯。因此如果需要重複使用的正規表達式，最好存為變數以提昇效能。

#### 捕捉 (capture) 與分組 (grouping)
  * `match()` 配合 `()`, 會把捕捉到的內容存為陣列。
  * 全域 flag `g` 與多次捕捉 `exec`
  * `replace()` 中使用參照, `$1`, `$2`, ... 
  * 分組與捕捉共用相同的語法 `()`, 可以使用 `(?:)` 被動次表達式 (passive subexpression) 強制指定為分組而非捕捉
  * 使用 `(?:)` 強制區分捕捉與分組，可以減少不必要的記憶體儲存。

#### `replace()` 使用函式取代
  * `replace( regularExpression, function )`, 取代的內容可以傳入一個函式而非固定的字串。
  * 延伸功能可以使用 replace 傳入函式作為字串的迭代, `sourceString.replace(, function () { return ""; })`, 搜尋+處理但是不改寫。

#### 常見問題與解法
  * 匹配全部字元包含換行字元, `[\S\s]` 或 `(?:.|\s)`


------------------------------


### 第十一章 - 程式模組化技術
  * 其他語言通過名稱空間 (namespace, C++, C#) 或者套件 (package, Java)解決模組化問題

#### ES6 以前
  * 使用物件提供界面, 閉包與立即執行函式提供隱藏實作。
  * 缺點 1. 擴充時無法使用先前的細節, 2. 無法自動化管理相依性
  * module pattern

####  AMD 與 CommonJS 模組標準
  * Asynchronous Module Definition (AMD), 特別針對瀏覽器環境
  * CommonJS, 更適合一般性執行環境, 例如 Node.js
  * AMD, 
    * 適用於瀏覽器環境
    * 最受歡迎的實作 RequireJS, 
    * `define`, 
    * 自動解析相依性, 
    * 非同步載入模組, 
    * 可把多個模組定義在單一檔案內
  * CommonJS, 
    * 一個模組一個檔案, 
    * `require`, `module.exports`, 
    * 模組同步載入, 
    * Node.js 預設的模組格式, 
    * 無法直接使用在瀏覽器環境上

#### ES6 之後原生的模組語法
  * 類似 CommonJS 的語法, 並且也是一個檔案一個模組
  * 類似 AMD 的非同步載入。
  * 新語法 `export`, `import`
  * `export` 慣例是在檔案結尾一次匯出
  * `import` 慣例是在檔案開頭一次匯入
  * `import * as  from `
  * `import {} from `, 具名匯入
  * `import from `, 預設匯入
  * `import { A as B} from`, as 更名匯入
  * `export default `, 預設匯出
  * `export `, 具名匯出
  * `export { A as B}`, as 更名匯出


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