## JavaScript 優良部分
### BOOK resource, JavaScript

------------------

第一章 - 優良部分

第二章 - 文法

第三章 - 物件

第四章 - 函式

第五章 - 繼承

第六章 - 陣列

第七章 - 正規運算式

第八章 - 方法

第九章 - 風格

第十章 - 美的功能

附錄A - 糟糕的部分

附錄B - 不良的部分

附錄C - JSLint

附錄D - 語法圖

附錄E - JSON

------------------


### 第一章 - 優良部分

#### JavaScript 特性
  * 函數式
  * 弱型別 (loose typing)
  * 動態物件 (dynamic object)
  * 物件實字註記 (JSON)
  * 原型繼承 (prototypal inheritance)、無類別行物件系統 (class-free)

#### JavaScript 糟糕的部分
  * 全域變數


------------------------------


### 第二章 - 文法

#### 註解
  * `//`
  * `/* */`

#### 數值
  * 只有一種數值型別, 64位元的浮點數。
  * 沒有整數型別
  * `NaN`, 算術失敗的回傳
  * `Infinity`, 大於最大值的所有值

#### 字串
  * 沒有字元 (character) 型別，都是字串 (string)。
  * `' '`
  * `" "`
  * 跳脫字元 `\`
  * Unicode `\u`
  * 字串成員 `length`
  * 字串不變性，運算產生新的字串。(類似 Java String pool)

#### 判斷與流程
  * `if`, `else`
  * `switch`, `case`
  * `do`, `while`,
  * `while`
  * `for`
  * `try`, `throw`, `catch`
  * `continue`, `break`, `return`

#### 真假值
  * falsy 
    * `false`, `null`, `undefined`, `""`, `''`, `0`, `NaN`

#### 運算
  * 三元運算 ` ? : `
  * 數值運算
  * 邏輯運算
  * 位元運算

#### 實字宣告
  * 物件 `{ }`
  * 陣列 `[ ]`
  * 正規表示式 `/ /`

#### 函數宣告
  * `function () {}`


------------------------------


### 第三章 - 物件

#### JavaScript 基礎型別 (primary type)
  * 數值 (number), 字串 (string), boolean `true`, `false`, `null`, `undefined`
  * 基礎型別也有類似物件的方法 (methods) 可以使用，差別在於**不能變動**。

#### 物件基礎介紹
  * 除了基礎型別外，全部都是物件。
  * JavaScript 物件式**可變動**的成員集合 (member set)。
  * 無類別 (class-free) 設計
  * 原型繼承 (prototype inheritance)

#### 物件實字 (object literal)
  * `{ }`
  * string-value pair `memberName: value`
  * 以 `,` 分隔成員。
  * 成員名稱使用 `" "` 字串符號包覆是選用的 (optional)。

#### 物件取值
  * `[ ]`
  * `.`
  * 不存在的成員會回傳 `undefined`
  * 從 `undefined` 取值會得到 `TypeError` 的例外

#### 物件增加值與修改
  * 使用 `[]`, `.` 賦值即可

#### 物件的傳遞
  * 傳遞 `reference` 而非複製值。

#### 原型物件 (prototype) 與繼承
  * 每個物件都有自己的 `prototype` 成員。
  * JavaScript 物件根 `Object.prototype`
  * 每次取值時都會沿著 `prototype chain` 去拿值，
    直到物件根 `Object.prototype` 也沒有值時回傳 `undefined`。
  * 原型 `prototype` 也是物件成員的一部分，因此在 runtime 是可以動態改變的。
  * 物件方法 `hasOwnProperty()`, 只會檢查本身 prototype 上的值。
  * 窮舉成員
    * `for in`，會取出所有的成員包含函式成員，並且沒有順序的取出。

#### 物件刪除
  * 利用 `delete` 移除物件成員，不影響 `prototype`

#### 減少全域變數
  * 使用物件作為 namespace 。


------------------------------


### 第四章 - 函式

#### 函式物件 (Function)
  * JavaScript 中所有的函式都是物件 `Function.prototype`
  * 函式物件中的特殊成員, contenxt, 函式原始碼, `constructor`
  * 因為函式是個物件，因此可以被存在變數中 (save as variable)、傳遞給其他函數 (pass to other function)、從函數中回傳 (return a function)。

#### 創建函式
  * `function functionName () {}`, 函式名稱是選用的，因此可以創建匿名函式 (anonymous function)
  * 可以在任何地方創建函式，包含在另外一個函式內部。
  * 函式中的函式產生 `closure`。

#### 函式呼叫
  * 每個函式在執行時會自動帶入兩個參數 `this`, `argument`
  * `this` 代表的是呼叫者，需要特別注意每次函式呼叫時的 `this` 是誰。
  * 函式呼叫時的參數數量，可以與定義不同。多的會忽略，少的會補上 `undefined`
  * 函式回傳值 `return`，沒定義時的預設是 `undefined`

#### 例外處理
  * 在函式中丟出例外 `throw { name, message }` 丟出一個例外物件 `exception`
  * 捕捉例外事件 `try {} catch (e) {}`， 每個 try 只會有一個 catch 因此有多種例外事件時需要自行處理。

#### 遞迴
  * JavaScript 沒有尾端遞迴最佳化 (tail recursion optimization)

#### 範圍 (scope)
  * JavaScript 只有 `function` 具有變數範圍限制，其他位置都會變成全域。

#### closure
  * 利用巢狀函式，讓外層的函數變式形成私有的 (private) 變數範圍，只允許內層函式呼叫。
  * 內層函式可能被參考的時間很長，可以使得外層函式變數 context 存活很久。
  * 特別注意的是內層函式讀取外層變數時是**直接讀取**而非複製內容。(注意取得的變數何時是參考 (reference) 何時是複製的值)
  * 可以配合立即執行函式使用。

#### 非同步執行與回呼函式 (callback function)
  * JavaScript 無法執行 multithread，因此要在只有 main thread 的情況下，讓程式產生良好的運作而不阻塞。
  * JavaScript 中很多動作都是非同步執行，因此在第一次呼叫之後要傳入一個回呼函式 (callback function)，讓工作完成時才做接下來的動作而非等待。

#### Cascade
  * 某些函式不回傳值，而是直接從參數 (parameter) 取得的參考 (reference) 去操作外部的值，可以藉由回傳 `this` 形成 function 呼叫的串聯。

#### curry
  * 單變函式回傳另一個函式，讓函式功能可以更彈性的被組合使用。

#### Memoization
  * 把要執行的函式形成一個 closure ，並且在 private context 創造儲存先前執行結果的資料結構，以利重複讀取換取更好的效能。


------------------------------


### 第五章 - 繼承

#### 模仿類別的繼承模式
  * 以建立建構子函式 (constructor function) 的方式創造物件
  * `var Parent = function () {}` 創造物件
  * `var Child = function () {}`
  * `Child.prototype = new Parent()` 繼承 
  * 以 `new` 來創造新的物件時，會呼叫建構子函式 (constructor) 並且回傳 `prototype` 裡的特性，利用這種特性取得父物件的 prototype。
  * 缺點: 沒有 private 變數、super 可以使用與呼叫，並且在直接呼叫建構子函式的誤用時會產生錯誤的全域變數。

#### 原型繼承模式
  * ...

#### 函式繼承模式
  * ...

#### 零件繼承模式
  * 創造一個函式，傳入一個物件並且附上其他函式或值，然後回傳。
  * `function (that) { that.someFunction(); return that; }`


------------------------------


### 第六章 - 陣列
  * JavaScript 中的陣列並非傳統的固定長度陣列，而是用**物件**模擬的陣列，速度較慢。
  * 操作陣列時盡量使用 `Array.prototype` 裡的方法，而非像物件一樣的方式操作。
  * 因為陣列也是物件，因此 `typeof` 取得的都是 `object`。
  * 如同 C 語言一樣，使用前**先初始化**是最好的方式。

#### 建立陣列
  * `[ ]` 實字建立
  * 繼承於 `Array.prototype`

#### length 特性
  * 並**非**陣列中內容的數量, 而是最大整數加 `1`
  * Example: `var test = []; test[1000] = 'a'; test.length`, 1001
  * 直接修改 length 變數，如果賦予的值比原本的 length 更小的話會**刪除**大於的內容。


------------------------------


### 第七章 - 正規運算式
  * 對於正規表達式來說，簡單是最好的策略。

#### 常用的函式
  * `regexp.exec`, `regexp.test`, `string.match`, `string.replace`, `string.search`, `string.split`

#### 建立正規式
  * `/ /`, 實字建立
  * `new RegExp()`, 可以傳入兩個字串參數，正規式與旗標 (flag) 。

#### 特殊符號
  * `\`, `/`, `[`, `]`, `(`, `)`, `{`, `}`, `?`, `+`, `*`, `|`, `.`, `^`, `$`

#### 跳脫字元後常用集合
  * `\d` = `[0-9]`, `\D` = `[^0-9]`
  * `\s` 空白集合
  * `\w` = `[0-9A-Z_a-z]`
  * `\數字` 取得分組

#### 打包
  * `()`, 會儲存的打包, 可以藉由 `\數字` 取出。
  * `(?)`, 不會儲存的分組, 更好的比對效能。
 

------------------------------


### 第八章 - 方法