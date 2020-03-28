## JavaScript 學習手冊
### BOOK resource, JavaScript

------------------

第一章 - 你的第一個應用程式

第二章 - JavaScript 開發工具

第三章 - 常值、變數、常數與資料型態

第四章 - 控制流程

第五章 - 運算式與運算子

第六章 - 函式

第七章 - 範圍

第八章 - 陣列與陣列處理

第九章 - 物件與物件導向程式設計

第十章 - Map 與 Set

第十一章 - 例外與錯誤處理

第十二章 - 迭代器與生產器

第十三章 - 函式與抽象思考的威力

第十四章 - 非同步程式設計

第十五章 - 日期與時間

第十六章 - 數學

第十七章 - 正規表達式

第十八章 - 瀏覽器中的 JavaScript

第十九章 - jQuery

第二十章 - Node

第二十一章 - 物件特性設置與代理器

第二十二章 - 其他資源

------------------


### 第一章 - 你的第一個應用程式


------------------


### 第二章 - JavaScript 開發工具
  * Terminal
  * Git
  * npm
  * Node.js
  * Gulp, Grunt
  * Babel, Traceur
  * ESLint


------------------


### 第三章 - 常值、變數、常數與資料型態

#### 宣告
  * `var`
  * `const`, (ES6)
  * `let`, (ES6)
  * 優先使用常數

#### 命名慣例
  * 常數, 全大寫。
  * 類別, 大寫開頭。
  * 底線開頭, 代表不希望被修改。
  * Camel case 或者 Snake Case。

#### 基本型別
  * 數字
  * 字串
  * 布林
  * Null
  * 未定義
  * 符號

#### 內建物件
  * 除了基礎型別外都是物件
  * Function
  * Array
  * Date
  * RegExp
  * Map, WeakMap, (ES6)
  * Set, WeakSet, (ES6)
  * Number, String, Boolean

#### 字串
  * `` `${}` ``, 字串樣板, (ES6)
  * `""`, `''`

#### 符號 Symbol (ES6)
  * 類似常數是唯一的，可以形成類似 enum 的功能

#### null 與 undefined
  * 請將 `undefined` 留給系統使用，刻意的空值賦予可以使用 `null`

#### Number, Boolean, String 物件
  * 在操作基本型別的數字, 布林, 字串也可以呼叫所屬物件的方法。
  * 原因是 JavaScript 會臨時創建出一個對應的物件，呼叫方法後則移除。

#### 陣列物件 Array
  * 陣列大小不固定，可隨時增加或移除。
  * 陣列內容可以各自是不同型別的。
  * 陣列大小會自動擴張到最後一個元素。

#### 型別轉換
  * `parseInt()`, 可以傳入 base
  * `parseFloat()`, 可以傳入 base
  * `toString()`
  * `!!`


------------------


### 第四章 - 控制流程
  * while loop
  * if...else
  * do...while loop
  * for loop
  * switch, 刻意使用的 fall-through 最好加上註解說明
  * `break`
  * `continue`
  * `return`
  * `throw`
  * `default`
  * for...in
  * for...of, (ES6)

#### 常用模式
  * 善用 `break`, `return` 減少計算
  * 善用 `continue` 減少 `else` 判斷式
  * 避免迴圈判斷式在迴圈內部被修改，需小心處理。


------------------


### 第五章 - 運算式與運算子

#### 算術運算子
  * 雙元 `+`, `-`, `/`, `*`, `%`
  * 單元 `+`, `-`
  * `++`, `--`

#### 比較運算子
  * `!=`, `==` 隱含的型別轉換
  * `!==`, `===` 盡可能使用嚴格比較算子

#### 數字比較
  * 小心浮點數運算的誤差值
  * 可以配合 `Number.EPSILON` 來比較兩個浮點數是否足夠接近

#### 邏輯運算子
  * `&&`, `||`, `!`
  * Falsy
    * `undefined`, `null`, `false`, `''`, `0`, `NaN`
  * Falsy 之外都是 Truthy
  * 有 short-circuit evaluation，判斷式已能確定真假值之後就不會繼續運算後續的內容。

#### 三元運算子
  * ` ? : `

#### 位元運算子
  * JavaScript 處理位元運算很慢，會先轉為32位元的二補數整數，運算後再轉回 double。
  * 二補數中最左位元 `1` 為負數, `0` 為正數。
  * `&`, AND
  * `|`, OR
  * `^`, XOR
  * `~`, NOT
  * `<<`, 左移
  * `>>`, 有極右移
  * `>>>`, 補零右移

#### typeof
  * `typeof null`, "object"
  * `typeof {}`, "object"
  * `typeof function () {}`, "function"
  * `typeof []`, "object"

#### void 運算子
  * 不應該被使用

#### 解構賦值 (ES6)
  * 陣列或物件的賦值
  * 可以辨識 key 並且自動對應賦值
  * Example: `const {a, b, c} = {b: 2, c:3, d: 4}`, a: "undefined", b: 2, c: 3


------------------


### 第六章 - 函式
  * 預設回傳值是 `undefined`
  * JavaScript 不會依據函式簽章產生新的函式，同名函式只有一個實體。

#### 引數 
  * 解構引數: 解構賦值的應用, `function ({a, b, c}) {}`, (ES6)
  * 引數預設值: `=`, `funciton (a = 'defaultValue')` ,(ES6)
  * 擴張運算子: `...`, `function (a, ...remain)` 最後一個引數可以變成陣列, (ES6)
  * 擴張運算子: 引數傳入 `f(...arrayName)`

#### Arrow function (ES6)
  * 宣告匿名函式
  * `() => {}`
  * 當引數或者回傳值只有單一運算式時可以省略括號。`name => "hello " + name`
  * `this` 綁定與一般函式不同，會依據 context 去綁定 (lexically)。
  * 不能呼叫 `arguments`, 可由擴張運算子取代。

#### call, apply, bind
  * 指定 `this` 的呼叫，`call`: 引數以逗號相隔傳入, `apply`: 引數變為陣列傳入
  * 永久綁定 `this`, `bind`, 回傳綁定過後的新函式
  * 使用 `bind` 產生的新函式, 無法再通過 `call`, `apply`, `bind` 改變 `this` 的值。


------------------


### 第七章 - 範圍
  * global
  * 區塊範圍 `let`, `const` (ES6)
  * closure: 只存在特定範圍的函式
  * Immediately Invoked Function Expression (IIFE): `(function () {})();`
  * 函式範圍 `var` 並且 hoisting 宣告部分。優先選用 `let`, `const`
  * 函式 hositing `function name() {}` 這種類型的會被 hositing。
  * 啟用嚴格模式 `"use strict"`


------------------


### 第八章 - 陣列與陣列處理
  * 要注意陣列方法使用時是否有邊際效應
  * `push`, `pop`, `unshift`, `shift`
  * `concat`
  * `slice`
  * `splice`, 定位, 移除, 加入
  * `copyWithin`, 複製, 貼上, (ES6)
  * `fill`, 填值, (ES6)
  * `reverse`, 反轉
  * `sort`, 排序
  * `indexOf`, `lastIndexOf`,
  * `findIndex`, `find`, 可以指定 `this`
  * `some`, `every`
  * `map`, `filter`
  * `reduce`
  * 如果 `map`, `filter`, `reduce` 遇到 `undefined` 的元素會被跳過。
  * `join`


------------------


### 第九章 - 物件與物件導向程式設計
  * 陣列有序，物件無序。

#### 列舉
  * for...in, 需配合 `hasOwnProperty()`, 不推薦使用。
  * 傳統的 for
  * `Object.keys().forEach()` 

#### 建立類別與實例 (ES6)
  * `class className { constructor() {} methods() {} get propertyName() {} set propertyName() }`, 配合 `new` 建立物件。(建構子函式的語法糖)
  * `class` 裡的原型 prototype method 不需要逗號間隔 (`,`)，配合 `get` 與 `set` 提供慣例語法。
  * `class` 裡的 `static functionName() {}` 靜態方法，直接以 class.method 的方式呼叫。
  * 繼承 `extends` 可以透過 `super()` 呼叫父層的建構子, 使用 `extends` 繼承來的成員也會通過 `hasOwnProperty()` 驗證，小心父層使用 `prototype` 再次新增的原型成員，for...in 配合 `hasOwnProperty()` 會有，但是不存在 `Object.keys()` 裡。
  * ES6 keywords: `class`, `constructor(){}`, `get`, `set`, `static`, `extends`, `super()`
  * override `toString()` 提供有用資訊。

#### Mixin pattern
  * Mixin function, `function mixinName (obj) { obj.mixinMethod = function () {} }`, `mixinName(Class.prototype)`，建立混用函式之後動態掛載給物件。
  * Mixin pattern 無法用 `instanceof()` 判斷，因為只是動態加入成員。只能通過 duck typing 判斷。
  * Mixin pattern 也會有 name collision，需要小心，或者使用 `Symbol` 作為 key，因為 Symbol 是唯一的。


------------------


### 第十章 - Map 與 Set (ES6)

#### 物件的缺點
  * 具有 prototype，不是單純乾淨的資料集。
  * 沒有 size 或 length 方法
  * key 限定為 String 或 Symbol
  * 無序

#### Map (ES6)
  * `new Map()`
  * `set()`
  * `get()`
  * `has()`
  * `size`
  * `keys()`
  * `values()`
  * `entries()`
  * `delete()`
  * `clear()`
  * 配合擴張算子展開城陣列 Example: `[...mapName.keys()]`
 
#### Weak Map (ES6)
  * key 必須為物件 (object)
  * key 會被垃圾回收 (GC)
  * 無法被 delete 或迭代

#### Set (ES6)
  * 不重複的資料集合
  * `add()`
  * `size`
  * `delete()`

#### Weak Set (ES6)
  * 只能存放物件
  * 會被垃圾回收 (GC)
  * 無法迭代


------------------


### 第十一章 - 例外與錯誤處理
  * Error 物件 `new Error("error message here")`
  * `try`
  * `catch`
  * `throw`
  * `finally`
  * 錯誤被丟出但是未被 catch 之前會一直往上傳遞，直到未被 catch 後直接停止程式運行。
  * 可以通過 Error 物件的 `stack` 成員取得 function call stack。
  * **丟出例外必須被捕捉處理，否則程式會中止**
  * 以判斷式 (if..else..) 處理預期的錯誤
  * 無法預期的錯誤則丟出例外


------------------


### 第十二章 - 迭代器與生產器 (ES6)

#### 迭代器 (iterator) (ES6)
  * `for...of` 可以適用於所有擁有 iterator 的物件。
  * `next()`
  * `[Symbol.iterator] () { return { next(){} }}` 實作 iterator，利用 Symbol.iterator 回傳的是擁有 `next()` 函式的物件。

#### 生產器 (generator) (ES6)
  * 提供可以雙向溝通的函式。
  * `function*` 宣告方式如一般函式，只是多了 `*`
  * `yield`, 傳出值並且把執行順序交還給呼叫者。
  * 呼叫生產器函數會回傳一個 iterator 可以通過 `next()` 執行內部工作並且傳值
  * `next()` 傳入，`yield` 傳出。
  * `return` 一樣可以傳出值，但是會中止 `next()` 的運行。但是 `return` 出來的值並不屬於 iterator，所以在使用 `for...of` 時不會取得。
  * 因此使用 `return` 時，最好只當成中止執行，並不回傳有意義的值。


------------------


### 第十三章 - 函式與抽象思考的威力
  * 無回傳的函式
  * 有回傳的函式
  * 純函式
  * Immediately Invoked Function Expression (IIFE)
  * 函式是第一類物件 (functions are first-class objects)
  * 可以通過 `typeof` 確認 JavaScript 函式

#### 純函式 (pure function)
  1. 沒有副作用 side effect
  1. 相同的輸入一定會有相同的輸出
  * 去耦合、容易測試
  * 試著優先使用純函式

#### JavaScript 函式是第一類物件
  * JavaScript 中的函式都是物件，因此可以被傳遞與存放在變數中。
  * 函式存放在物件、陣列、其他資料結構中
  * 函式作為參數傳入另一個函式
  * 函式作為其他函式的回傳值


------------------


### 第十四章 - 非同步程式設計
  * 回呼函式 callback function
  * Promise (ES6)

#### 回呼模式
  * `setTimeout()` 
  * `setInterval()`, `clearInterval()`
  * 注意傳入的回呼函式存在的變數範圍 (scope) 
  * 在 Node.js 中的慣例，呼叫回呼函式的第一個參數為錯誤處理。
  * 如果非同步的回呼函式之間具有相依性，會產生 callback hell。

#### Promise (ES6)
  * Promise 是個物件，resolve 和 reject 只會則一發生並且發生後工作即完成。
  * `new Promise( function (resolve, reject) {} )`
  * `then()`, 傳入處理 resolve 時的函式
  * `catch()`, 傳入處理 reject 時的函式
  * Promise chaining, 壓平 callback hell。
    * 在 `then()` 傳入另一個產生 Promise 的函式，即可再用 `then()` 串接具有相依性的工作。
  * 可以實作一個 `addTimeout` 函式來加工 Promise 用來保證會執行 resolve 與 reject。

#### 生產器 (Generator) (ES6)
  * 通過 generator 函式與 Promise 互動
  * 第三方函式庫, Q promise, co, Koa

#### await, async (ES7)


------------------


### 第十五章 - 日期與時間
  * 內建的 `Date` 物件，無法指定時區。
  * 時區由作業系統
  * 處理時間可以使用的第三方函式庫, `Moments.js`
  * 要在瀏覽器端與伺服器端中傳遞時間，需要特別小心時區問題。
  * Unix Epoch (UTC 1970/1/1)


------------------


### 第十六章 - 數學
  * 沒有整數型別，全部都是 IEEE754 64bits (double)
  * 要計算複數、大數、複雜運算，需要尋求第三方函式庫的幫忙。

#### 數字轉換字串
  * `toFixed()`, 四捨五入
  * `toExponential()`, 四捨五入
  * `toPrecision()`, 四捨五入
  * `toString()`, 可以指定 base

#### Math 物件
  * Math 裡的方法都是靜態方法，Math 類似於 namespace 存在。
  * 各種常數, `E`, `PI`, `LN2`, `LN10`, `LOG2E`, `LOG10E`, `SQRT1_2`, `SQRT2`


------------------


### 第十七章 - 正規表達式

#### 字串處理
  * 字串原生的功能
  * `startWith()`, `endsWith()`, `includes()`, `indexOf()`, `replace()`, 大小寫有別。

#### Regular Expression
  * `/ /`, `new RegExp()`
  * 使用正規表達式的方法
    * 字串呼叫 `match()`, `search()`, `replace()`
    * 正規表達式呼叫 `test()`, `exec()`
  * 正規表達式是消化 (consuming) 非尋找 (finding)
  * `|`, `[]`, `^[]`, 常用集合 `\d`,`\D` (digit), `\s`, `\S` (space), `\w`, `\W` (word)
  * flag `i`, `g`, `m`
  * 次數 `{}`, `{n,}`, `{n, m}`, `?`, `*`, `+`
  * 萬用字元 `.` (換行字元除外), 
  * 跳脫字元 `\`
  * 定位 `^`, `$`
  * 分組 (grouping), 會記憶的分組 `()`, 不會記憶的分組 `(?:)`
  * lazy match, greedy match, 預設是 greedy。
    * greedy match: 尋找最長的
    * lazy match: 遇到符合的即停止。在任何次數選擇後加上問號則進入 lazy match, `*?`, `+?`, `??`, `{n}?`, `{n,}?`, `{n,m}?`
  * 替換群組 `$1`, `$2`, ..., $\` : 符合對象之前所有的, `$&` 符合對象本身, `$'` 符合對象之後所有的。
  * `replace(//, function)`, 替換函式替換的對象可以傳入函式用來與正規表達式互動替換。
  * Lookahead, 辨識但不消化, `(?=)` 包含, `(?!)`, 不包含


------------------


### 第十八章 - 瀏覽器中的 JavaScript
  * DOM 與 DOM API
    * `nodeName`, `nodeType`, `parentNode`, `childNodes`
    * get `document.getElementById`, `document.getElementsByClassName`, `document.querySelector`, `document.querySelectorAll`
    * `textContent`, `innerHTML`
    * `createElement()`, `insertBefore()`, `appendChild()`
    * `classList.add()`, `classList.remove()`
  * 事件
    * `addEventListener`, `preventDefault()`, 控制事件傳遞方向 capturing (外向內) 與 bubbling (內向外), `stopPropagation`
  * Ajax
    * CORS, reponse header: `Access-Control-Allow-Origin`
    * XMLHttpRequest
    * fetch


------------------


### 第十九章 - jQuery
  * 幫忙處理瀏覽器相容性問題
  * `$`, namespace
  * ready `$(function () { });`, `$(document).ready( function (){} );`
  * jQuery Object 與方法


------------------


### 第二十章 - Node
  * 伺服器端的 JavaScript
  * Node 與 npm, `npm install`
  * 模組
    * `module.exports`, `require()`
  * 檔案系統 (fs)、作業系統 (os)、主程序 (process)、子程序 (child_process), 串流 (stream), Web Server 
  * 伺服器端框架 Express, Koa


------------------


### 第二十一章 - 物件特性設置與代理器