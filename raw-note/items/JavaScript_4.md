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
  * 使用具名函式有助於提升 Error 物件的可閱讀性
  * 避免使用 `eval`

#### 了解 variable hoisting
  * var 變數是 lexical scoping 並沒有 block scoping `{}` 範圍是函式空間 (function-scoped)。
  * 把變數的宣告與賦值變成兩個步驟 (JavaScript 程式碼解析與執行)，宣告會被 hoists 至所屬的函式空間開頭。

#### 利用 IIFE 建立 scope
  * closure 所儲存的是外部變數的參考 (reference) 而非值。
  * 利用 IIFE 創造出區域變數，儲存上層的值。


------------------------------


### 第三章 - 函式的使用
  * 在 JavaScript 中 `function` 代表著函式、物件方法、建構式。
  * 熟悉 Higher-order functions (接收函式為參數或者回傳函式) 並且用於減少重複的程式碼。
  * 善用 `Funciton.call()` 指定 `this`
  * 以 `Function.apply()` 配合 `arguments` 創造參數不定數量函式。
  * 傳遞函式時可藉由 `Function.bind()` 先指定好 `this` 的對象。
  * 以 `bind()` 實作 currify function。
  * 避免使用功能不一或非標準化的 `toString()`, `arguments.caller`, `arguments.callee`

#### arguments
  * arguments 是類 array 物件，在 strict mode 與非 strict mode 時行為不同。
  * 避免直接修改 arguments。
  * 如果要操作改用 `[].slice.call()` 複製一份。
  * 每個 function 都有自己的 `arguments`，因此如果要在 nested functions 操作時要小心對象。


------------------------------


### 第四章 - 物件和原型
  * 把能共用的方法存在 `prototype` 上。
  * 如果需要私有 (private) 資料則使用 closure 實作。
  * prototype 只應該放置能被共用的資料。
  * 注意每個方法被呼叫時的 `this`，如果需要外層的 `this` 可以創建區域變數 (self, that) 儲存或者使用 `bind()`。

#### 了解 prototype, getPrototypeOf, __proto__
  * `ConsturcterFunction.prototype`
  * `Object.getPrototypeOf( objectInstance )`, ES5語法取得所屬的 `ConsturcterFunction.prototype`
  * `objectInstance.__proto__`, 非標準的取得所屬的 `ConsturcterFunction.prototype`
  * 優先使用標準化的 `getPrototypeOf()` 取代 `__proto__`，並且永不修改 `__proto__` 以 `Object.create()` 取代。

#### 子類別
  1. contructor function 中呼叫 `Parent.call(this, )` 
  1. `Child.prototype = Object.create(Parent.prototype)`
  * 避免子類別使用與父類別相同的特性名稱，否則會取得相同的 reference。
  * 不要利用內建的標準類別 (Array, Function, Number, String, Boolean, Date, RegExp) 建立子類別，容易產生不可預期的錯誤。
    * 只取出特定的方法來使用就好


------------------------------


### 第五章 - 陣列與字典

#### 字典
  * 直接使用原生物件當成字典時要小心窮舉時遇到 prototype 上的元素。
  * 使用 `Object.create(null)` 創造出真正沒有原型的空物件。
  * 使用 `hasOwnProperty()` 避免原型元素汙染。
  * ES6 之後有原生支援。

#### for-in
  * 物件順序是不一定的，不要依賴 for-in 產生的順序。
  * 永遠不要汙染 `Object.prototype`
  * 不要列舉時同時修改該物件，會造成不可預期的取值錯誤。
  * 迭代陣列時使用傳統 for-loop 或 `forEach()` 不要使用 for-in。
  * for-loop 終止條件，可以使用區域變數儲存避免每次重新計算。

#### 陣列
  * 善用陣列專用的方法 `forEach()`, `map()`, `filter()`, `some()`, `every()` 來操作陣列。
  * 使用實字陣列 (literal) 創建陣列，永遠不要使用 `new Array()`。


------------------------------


### 第六章 - 程式庫與 API 設計
  * 函式如果有過多引數時，改用傳遞物件。閱讀性更佳並且不需記住順序。
  * API 分成 `stateful` 與 `stateless` (無 side-effect, pure)，優先使用 stateless API。
  * 定義介面 (interface) 分離實作，配合 structural typing (duck typing) 定義具有彈性的實作。
  * 注意 JavaScript 陣列與類陣列之間的差別，分離並且一致性處理。
  * 避免使用強制型別轉換產生多載功能，使用防禦性的寫法丟出例外 (TypeError)
  * 提供方法串聯功能 (method chaining)，stateful 方法則回傳 `this`，stateless 方法則回傳全新的內容。

#### 維持一致的慣例 (conventions) 
  * 引數的順序 (argument order) 固定順序代表的慣例。
  * 命名慣例 (naming conventions), 變數命名與函式簽名 (function signatures)

#### undefined
  * `undefined` 只代表沒有值，不要產生其他意義。
  * 要為了 `undefined` 時提供預設值時，只使用 falsy 作為判斷是不準確的，需要明確的比較 `undefined`。


------------------------------


### 第七章 - 共時性
  * JavaScript 只有主執行序，因此處理事件的方式使用 event-queue (event-loop) concurrency 非同步機制 (asynchronous)
  * 執行 callback function 時仍然是單一執行序，因此並非事件一發生就會執行。
  * 永遠不要在 event queue 中加入 blocking 的處理，會擋住之後的事件處理。
  * 在事件處理時有相依性的處理會產生 nested callback function (callback hell)，可以使用具名函式降低巢狀結構。
  * 非同步方法在遞迴呼叫時使用並不會產生 stack overflow ，因為非同步方法呼叫後立即回傳。
  * 處理相依的非同步工作時，要小心 race condition，避免正確性是依據執行完成的順序 (不確定性的)。

#### Worker API
  * 在 JavaScript 中任何會消耗大量時間的運算，不管是不是非同步機制，仍然會在某個時間佔住主執行序，導致用戶體驗不佳。
  * Worker 不同於 thread 沒有共用的資料區塊。
  * Worker 會提供另外一個獨立的環境，只能通過 message 來溝通。
  * 當一個工作過於巨大時，可以把步驟拆解成 asynchronous 函式一次只執行一小段，丟給 (`setTimeout`) event queue 中排程，避免擋到其他事件的處理。