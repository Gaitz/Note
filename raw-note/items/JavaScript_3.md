## JavaScript 設計模式
### BOOK resource, JavaScript

------------------

第一章 - 介紹

第二章 - 精要

第三章 - 實字與建構式

第四章 - 函式

第五章 - 物件建立模式

第六章 - 程式碼重用模式

第七章 - 設計模式

第八章 - DOM 和瀏覽器的模式

------------------


### 第一章 - 介紹

#### 物件導向
  * 只有 number, string, boolean, null, undefined 不是物件，其他所有東西都是物件，包含函式。
  * 所有宣告的變數都是物件的屬性 (property)。
  * 物件只是具名屬性的集合，key-value pairs。
  * 物件創造後隨時能夠修改，新增、刪除、更新。
  * 兩類物件
    * Native, ECMAScript 標準中定義的物件。
    * Host, 宿主環境上的物件。
  * 來自四人幫的通則，組合勝於繼承 (Prefer object composition to class inheritance)
  * 原型 (prototype) 也是一個物件即 `__proto__`，每個物件都有 `__proto__` 物件。

#### ECMAScript
  * JavaScript 語言核心是由 ECMAScript 標準定義
  * 嚴格模式 `"use strict"`
  * 建議使用 JSLint 做靜態程式碼檢查，並且養成好的程式碼習慣。

#### console 物件
  * Host 物件，方便輸出檢視。


------------------------------


### 第二章 - 精要

#### 撰寫可維護的程式碼
  * 發現 bug 盡早修復
  * 容易維護的程式碼必須
    * 可讀性
    * 一致性
    * 可預料的
    * 看起來要像是同一人寫的
    * 文件化

#### JavaScript 好的實務
  * 減少全域變數，關注變數作用域。
    * 最小化全域變數數量，最理想的情況使只有一個，作為 namespace 使用。
    * 全域變數容易造成 namespace 衝突。
    * 永遠宣告變數後才使用。
    * 用 `var` 創造的全域物件，不可以被 `delete` 刪除，但是隱性的可以。
  * 存取全域物件的方法，採用**立即執行函式**，把全域變數作為參數傳入。
  * 單一 `var` 模式
    * 在每個函式一開頭把所有用到的變數一次宣告好。
    * 宣告同時初始化是好實務。
  * Hoisting
    * 在範圍中的變數宣告會被拉到最上方，避免錯誤預期最好的方法就是明確的把所有的變數都在開頭宣告。
  * `for` 迴圈疊代陣列
    * 如果在終止條件中使用 `.length` 每次迴圈檢查都會呼叫一次，如果是在操作 DOM 會造成效能問題。
  * `for-in` 疊代物件
    * 不保證順序，操作物件最好配合 `hasOwnProperty()` 避免繼承鏈上的元素
  * 不要擴充內建物件的原型
  * switch 模式
    * 將 `case` 與 `switch` 並排
    * `case` 內部縮排，並且以 `break` 結束
    * 避免 case fall through，刻意使用需要加上文件或註解。
    * 補上 `default` 就算沒有 case 落入。
  * 避免隱含的型別轉換
    * 永遠使用嚴格比較算子 `===`, `!==`
  * 避免使用 `eval()` 和 `new Function()`
  * 數值轉換使用 `parseInt()` 並且每次都指定基數
    * 其他數值轉換方法 `+`, `Number()`, 注意傳入非數字時的行為
  * 編碼規範 coding standard 最重要的是大家都遵守規則，而非哪種規則。
    * 縮排
    * 大括號, 不要省略單行執行的大括號。
    * 左括號位置, 因為在 JavaScript 有分號自動插入機制 (semicolon insertion mechanism), 因此必須把左括號放置於第一行尾。
    * 空格
    * 命名慣例
      * 函式建構式 (function constructor) 以大寫開頭，仿造 class 命名。
    * 註解
      * 最重要的是更新註解
    * API 文件
      * 使用 API 文件生產工具
      * 配合註解自動生成文件
    * 寫得讓人看得懂
      * 總是回頭查看第一次的解決方案，refactoring。
    * peer review, code review
    * 推到產品之前最小化程式碼 (minification)
      * 撰寫讓人看得懂的程式碼，最小化的工作交給工具。
    * 隨時執行 JSLint


------------------------------


### 第三章 - 實字與建構式
  * 結論是能使用實字創建時不要用 `new`， `new` 更容易有錯誤發生並且沒有特別的益處。

#### 物件實字 `{ }`
  * 物件只是 key-value pair
  * 物件創建最好的方式是實字創建 `{ }`
  * 不要使用 `new Object()`。
  * 自訂 constructor 函式
    * `new ConstructorFunction()`
    * 建構子，只是一個函式。
    * `new` 算子會指定 `this` 為空物件，並且繼承指定的原型，最後未指定回傳時，會隱含的回傳 `this`。
    * 共用的方法最好使用原型鍊附加 `ObjectName.prototype.functionName` ，避免多份相同的函式被建立。
    * 永遠不要不使用 `new` 直接呼叫建構子函式，會導致 `this` 綁到全域，並且汙染全域變數。
    * 可以通過 `if (!(this instanceof ObjectName))` 來檢查是否使用 `new` 創建
    * 因此建構子函式命名規則類似於類別 (class)，以大寫開頭。

#### 陣列實字 `[ ]`
  * 陣列創建最好的方法是實字創建 `[ ]`
  * 避免使用 `new Array()`, 因為建構子的預設第一個參數為陣列長度而非內容。
  * 檢查變數是否為陣列使用
    * `Array.isArray()`
    * `Object.prototype.toString.call() === '[object Array]'`

#### JSON
  * 屬性名稱必須使用 `" "` 包起來。
  * 使用 JSON 為了安全性問題，不要使用 `eval()`
    - 解析 JSON 字串時只使用 `JSON.parse()`
    - 反向轉換成 JSON 字串使用 `JSON.stringify()`

#### 正規表示式實字 `/ /`
  * regular expression 建立方式有
    - `/ /`, 實字
    - `new RegExp(regex string, flags string)`, 建構式
  * flags
    - `g`, 全域檢查 (global)
    - `m`, 檢查多行 (multiple line)
    - `i`, 不分大小寫 (ignore case)

#### 原始型別物件 primitive wrapper objects
  * `Number()`
  * `String()`
  * `Boolean()`
  * 沒有任何理由特別使用物件建構式來建立 primitive 類型物件。
  * 原始型別仍然可以呼叫所屬物件的方法，會隱含的創立物件使用後再釋放。

#### Error 物件
  * 可以字鍵錯誤物件，傳入 `name` 與 `message`。
  * 用於 `throw`, `try`, `catch`, `finally` 處理中。
  * 但是錯誤處理 `throw`, `try`, `catch` 可以使用的物件不需要一定是 Error 物件，可以是任何自訂的物件。


------------------------------


### 第四章 - 函式
  * 函式也是物件 (first-class object)，只是能被呼叫 `()` execution。
  * 函式提供作用域 (context)
  * 函式可以被存為變數，作為參數，回傳值。

#### 函式建立
  * `var a = function a () {}`, named function expression, hositing 的只有變數的宣告。
  * `var a = function () {}`, anonymous function, hositing 的只有變數的宣告。
  * `function a () {}`, function declaration, hositing 的包含函式宣告與定義。
  * 函式作為變數存在，因此也受到 Hositing 影響。

#### 回呼模式 (callback function)
  * 把函式作為參數傳給其他函式，在需要的時候才呼叫執行 `()`。
  * 利用回呼函式，分離一些執行邏輯，提高重用性與去耦合。
  * 如果需要回呼的是物件的方法 (method of object)，要小心 `this` 指向的對象，因此需要連同物件一起傳入。
  * 瀏覽器作為事件驅動 (event trigger)，特別需要使用回呼模式。範例:
    - `addEventListener(event, callback_function)`
    - `setTimeout(callback_function, time)`
    - `setTnterval(callback_function, time)`

#### 回傳函式
  * 函式回傳另一個函式

#### 自我定義函式
  * 函式中複寫同名函式的內容 (override self)

#### 立即執行函式 (immediate function pattern)
  * 函式定義後立即執行 
  * `( function () {}() );`
  * 好處在於提供作用域 (contenxt) 避免汙染全域變數。
  * 可以把全域變數作為參數傳入，提供與外部互動的功能。
  * 立即執行函式也可以回傳值。 `var result = (function () { return something; } ());`
  * 當立即執行函式回傳值是個函式時，可以形成 `closure` 並且第一層函式內部的變數變成私有 (private) 且有更長的存活期。

#### 立即執行物件模式
  * 物件宣告後立即執行定義的函式。
  * `({  }).methodName();`
  * 取決於呼叫函式的回傳值，可以回傳 `this` 讓物件之後可以再被使用。

#### memoization pattern
  * 函式也是一個物件，因此可以擁有自己的屬性。
  * 利用 `functionName.cache = {}` 建立 cache 屬性並且作為計算值的儲存位置。

#### 函式參數物件模式
  * 當函式需要多個參數時，只傳入一個物件簡化函式簽名。
  * 此模式的缺點是需要記住參數的名稱並且正確。

#### Currying
  * 函式 `apply()`
    - `functionName.apply(null, [])`, apply 函式指定作用的物件與參數陣列。
    -  一般的函式呼叫等同於作用物件為 `null`
    - `call()` 等同於 `apply()` 只是參數傳入方式不同。
  * 部分應用 (partial function application)
    - 當傳入的參數數量不完全時，回傳的是一個函式。
  * currying
    - 在其他函數式程式語言中是內建的功能
    - 在 JavaScript 中要額外實作提供任意函式 currying 的函式功能。
  * 使用 currying 的時機
    * 當某個函式時常傳入相同的參數時，就是使用 currying 的時機。
    * 利用 currying 保存相同的參數。


------------------------------


### 第五章 - 物件建立模式

#### 命名空間模式
  * JavaScript 沒有原生支援的 namespace 功能。
  * 應該為自己的應用程式或者函式庫提供唯一一個全域變數作為命名空間。
  * 命名規則為全大寫, 類似 Java 的網域名稱等等。
  * 命名空間的建立最好先做檢查，存在與否在建立。

#### 宣告相依性
  * 使用全域變數時，在自己的函式開頭重新命名為區域變數。
  * 好處
    - 明確的在開頭知道相依性
    - 使用區域變數速度更快
    - 可以被工具 minify 名稱

#### Private 屬性與方法
  * Private 屬性與方法
    - 使用 closure 實作，外層函式內部的變數都是 private 的。但是如果把變數參考傳出去仍然能被修改。

#### 模組模式 (module pattern)
  1. 建立命名空間
  1. 使用區域變數把全域變數的相依性加在初始處
  1. 使用立即執行函式定義模組，也提供了 private context
  1. 回傳對外的物件
  
#### 靜態成員 (static)
  * public static method，只要把方法直接掛在建構子函式上，就可以利用建構子函式名稱去呼叫，而不需要先建構物件。
    - 需要注意函式內部的 `this` 指向的是建構子。
  * private static method, 建構子函式的建立也透過立即執行函式回傳，在立即函式裡的變數則變為私有的。

#### 鍊接模式 (chaining pattern)
  * 當函式不需要特別的回傳值時，可以回傳 `this` 達到實作串接的功能。
  * 優點
    - 簡短的程式碼
    - 特別去思考函式的單一責任。
  * 缺點, debug 較於困難。


------------------------------


### 第六章 - 程式碼重用模式