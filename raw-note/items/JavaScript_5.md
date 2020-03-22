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