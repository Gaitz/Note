## Effective JavaScript 
### BOOK resource, JavaScript

------------------

第一章 - 讓你自己習慣 JavaScript

第二章 - 變數範圍

第三章 - 函式的使用

第四章 - 物件和原型

第五章 - 陣列與字典

第六章 - 程式庫與 API 設計

第七章 - 共時性

------------------


### 第一章 - 讓你自己習慣 JavaScript
  * 了解自己使用的 JavaScript 版本與環境
  * 注意 strict-mode 的檔案串接

#### JavaScript 數值與浮點數
  * JavaScript 中只有一種數值型態，全部都是 IEEE 754 標準的 64位元浮點數 (double)。
  * 浮點數計算只是近似值，會有誤差值的累積。需要精確地計算時要避開使用浮點數，調整回整數後再計算是比較安全的做法。

#### 小心隱含的型別轉換
  * `+`, `valueOf` > `toString`
  * truthy,
  * falsy, `false`, `0`, `-0`, `""`, `NaN`, `null`, `undefined`

#### 使用基本型別而不用 wrapper object
  * 使用 primitive values 才能用 typeof 區分，使用 wrapper object 則通通變為 `Object`
  * primitive value 也可以呼叫物件方法，會隱性的零時轉換。

#### 只使用 === 而不用 ==
  * 避開隱性的型別轉換

#### 自動分號插入限制
  * 在 JavaScript 中 `;` 是選用的。在符合規則下會正確的自動加上 `;`。
  * 規則一, 分號只會被自動加入在 `}` 之前或者行尾。
  * 規則二, 只有在與之後的敘述無法被解析 (parse) 才會加入。
    * 小心 `(`, `[`, `+`, `-`, `/` 開頭的句子，簡單的規避方式在行首加上 `;` 截斷語意。
    * 在檔案串接時也會可能會遇到，可以防禦性的在檔案開頭加上 `;` 規避。
  * 規則三, 在 `for ()` 中的 `;` 不會被自動加上，需要明確寫出。

#### JavaScript 字串是 16 bit code units 的序列
  * code point (character) 與 code unit (bytes) 的差別
  * JavaScript 字串的 `length`, `charAt`, `charCodeAt`, 與正規表達式 (regular expressions) 是依據 code units


------------------------------


### 第二章 - 變數範圍
  * 盡可能減少全域變數
  * JavaScript global namespace 會變成 global object
  * 變數永遠先宣告才使用
  * 永遠不使用 `with`
  * 了解並且善用 `closure`

#### 了解 variable hoisting
  * var 變數是 lexical scoping 並沒有 block scoping `{}` 範圍是函式空間 (function-scoped)。
  * 把變數的宣告與賦值變成兩個步驟 (JavaScript 程式碼解析與執行)，宣告會被 hoists 至所屬的函式空間開頭。

#### 利用 IIFE 建立 scope