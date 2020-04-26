## 重構 JavaScript
### BOOK resource, JavaScript

------------------

第一章 - 什麼是重構?

第二章 - 你用的是哪一種 JavaScript?

第三章 - 測試

第四章 - 測試實戰

第五章 - 基本的重構目標

第六章 - 重構簡單的結構

第七章 - 重構函式與物件

第八章 - 重構於層次結構之中

第九章 - 重構為各種物件導向模式

第十章 - 重構異步

第十一章 - 使用函數式範式重構

第十二章 - 結語

------------------


### 第一章 - 什麼是重構?
  * 確保行為不變
    * 單元測試 (Unit Test)
    * 版本控制 (Version Control)
  * 重構只在有測試的前提之下有意義，測試包含手動測試與自動測試。
  * **重購的前提是擁有測試**，否則只是在改變程式碼。
  * 只測試我們希望正常的功能，包含特定的極端案例、效能...。
  * 程式碼品質
    * SOLID: Single responsibility, Open/closed, Kiskov substitution, Interface segreation, Dependency inversion
    * DRY: Don't repeat yourself
    * KISS: Keep it simple, stupid
    * GRASP: General responsibility assignment software patterns
    * YAGNI: Ya ain't gonna need it
  * **Programming to interface not implementation**
  * 重構建立在使用相同的 interface 。
  * 任何改變 interface 的修改都不是重構而是新功能。


------------------


### 第二章 - 你用的是哪一種 JavaScript?
  * JavaScript 標準: ECMAScript 規格書
  * 平台與實作: caniuse
  * 預處理: Babel.js, minifier
  * 框架與函式庫: jQuery, React, Angular, Ember, Underscore.js, ...


------------------


### 第三章 - 測試
  * 測試的目的是帶來信心
  * 把測試分成快速測試與緩慢測試。

#### 功能性測試
  * 手動測試 (Manual Testing)
  * 含有文件的手動測試 (Documented Manual Testing)
  * 驗收測試 (Acceptance Testing)
  * 點對點測試 (End-to-End Tests), 避免使用 mocking 與 stubbing。
  * 單元測試 (Unit Tests), 盡量使用 mocking 與 stubbing。

#### 非功能性測試
  * 效能測試
  * 易用性測試
  * 安全性測試
  * 無障礙測試
  * 本土化測試

#### 提升品質的實務
  * 團隊共同使用的風格標準
  * 定期招開的技術債審視會議、工程品質會議，適時地把重構工作加進時程。
  * Pair Programming, 知識共享、更快的反饋、更少的 bug
  * Code Review, 
  * Test-driven Development (TDD)
  * Behavior-driven development (BDD), 從 End-to-end 的角度做 TDD。

#### 相關工具
  * 版本控制 (version control), 
  * 測試框架 (framework), 
  * 斷言語法庫 (assertion syntax libraries), 
  * 特定領域函式庫 (domain-specific libraries), 
  * 工廠方法 (factories and fixtures) fake/faker
  * Mocking/stubbing 函式庫
  * 建置打包工具 (build/task/packaging tools)
  * 載入器與監聽器 (loaders and watchers)
  * 測試平行運行 (test run parallelizers)
  * 持續整合 (continuous integration, CI)
  * 覆蓋率回報器 (coverage reporters)
  * Linters
  * Debugger / loggers
  * staging 環境


------------------


### 第四章 - 測試實戰
  * Node debugger, `node debug`, `debugger`
  * Node aseert library, `require('assert')`
  * 第三方斷言函式庫, **wish**, `npm install wish`, `require('wish')`
  * 第三方測試框架, **mocha**
  * 讓每次 git commit 之間的差別小一點，可以方便 revert/reset。

#### Test-driven development (TDD)
  * Red / Green / Refactoring
  * baby steps

#### Mocha
  * `describe('description_here', function () {})`
  * `it('description_here', function() {})`

#### Testing
  * 利用 Regular expression 測試隨機性的輸出
  * 描述測試，試著讓測試印出未知的東西，然後測試。(單純測試未知的 return)


------------------


### 第五章 - 基本的重構目標

#### 函式
  * 體積
    * 複雜度 (路徑分支的數量)
    * 行數
  * 顯性輸入
    * 盡量使用顯示輸入的是 (Functional Programming 風格)
    * 盡量使用隱性輸入 (this) 的是 (Object-Oriented Programming 風格)
    * 越少輸入就越好控制體積，也越容易測試。
  * 輸出
    * 預設回傳 `undefined`
    * 就算是利用 side-effect 的函式也盡可能傳出一些有意義的訊息或者 `this`。
    * 回傳值最好保持單一型別
  * 副作用 (side-effect)
    * 理想上副作用越少越好，副作用越少越好測試。
    * 就算有副作用也需要控制好範圍。
  * 隱性輸入 (this)
  * 隱私 (privacy)
    * JavaScript 還未有真正的 private，只有刻意控制的作用域 (scope)。
    * 利用 immediately invoked function expressions (IIFE) 產生的 closure
    * 使用 `class` 要實現 private 需要配合 module 的使用。

#### 結論
  * 減少體積 (複雜度與行數)
  * 減少輸入總數
  * 使用顯式輸入與隱性輸入，取決於風格。
  * 回傳真實且有意義的回傳值，比默默地只產生副作用好。
  * 副作用越小越好
  * 控制好作用域


------------------


### 第六章 - 重構簡單的結構
  * 效能與表達能力的選擇，應該以表達能力為優先，效能調教等遇到瓶頸時再做調整。

#### 重新命名
  * 錯字
  * 短名 (縮寫)
  * 非解釋性 / 通用性名字
  * 變數名稱裡的數字
  * 重複名字
  * 命名慣例, 建構子大寫, 函式, 變數小寫

#### 無用程式碼
  * 死碼 (dead code), 無用的
  * 推測性程式碼和註解
      * ticket, todo, issue tracking, user story 不要使用註解而是另外的系統
  * 空白
  * 冗贅程式碼 (do-nothing)
  * 除錯/打印

#### 變數
  提出變成變數
  * 魔術數字
  * 魔術字串
  * 長行
  * 不必要的函式呼叫，改寫為 inline。
  * 變數提升 (Hoisting)
      * JavaScript 專屬，會被提升的變數或函式，應該宣告在 scope 的最上方。

#### 字串
  * 魔術字串, 連接, \` ${}\` 字串模板
  * 長字串
  * 長陣列

#### 迴圈
在正確性相同的情況下選擇表達性最好的。
  * while
  * do...while
  * for with index
  * for...of
  * forEach


------------------


### 第七章 - 重構函式與物件

#### 容器
  * 陣列 (array)
  * 集合 (set), `new Set()`
      * 不重複的
  * 物件 (object)
      * 不保證順序
  * 映射 (map), `new Map()`
      * 容易取得正確大小
      * 避免物件原型鏈
      * 可迭代的 (iterable)
  * 位元欄 (bit fields)
      * 一組的 boolean 可以轉換成一串位元序列, 利用位元運算取代布林運算。
      * 在效能與記憶體上最佳化

#### 提取函式
  * 提取函式與程式碼 inline 為相反的作用
  * 匿名函式的提取與命名
  * 適時的選擇不同的函式宣告
      * arrow function
      * 匿名函式
      * 有名函式

#### 物件導向式
移除全域變數，物件導向式，包成物件。  
  * 建構子替代初始化函式 (inital)
  * 分離資料與商業邏輯
  * 注意匿名函式中的 `this`, 善用 that, `bind`, `apply`, `call`, arrow function 處理。
      * 使用 arrow function 自動綁定外部的 this。
  * 持續調整把函式放到正確的物件中
  * 物件實字與建構子函式的使用時機
      * 當物件會被多次生成時 (`new`) 使用建構子函式。
  * 工廠模式 (closure return)
      * 模板生成 1. IIFE 回傳物件模板, 2. 物件實字模板
      * 模板再配合 `Object.create()` 生成物件本體。
      * 好處是可以藉由 closure 提供 private block 並且可以像建構子般生成多個物件。
  * ES6 `class`
      * `class { constructor() {}; methods(); }`
      * 配合 `new` 生成物件
      * `static`

#### var, let, const
  * `var`, (function scope)
  * `let`, `const` (block scope)
  * 優先使用 `const` 其次 `let`。

#### 避免相同參考
  * 避免相同參考的資料集合
  * 多重參考會產生 side-effect。


------------------


### 第八章 - 重構於層次結構之中
  * 框架是為了控管複雜度
  * 預設參數只用在真正預設的值，而非常用的值。
  * 最重要的是一個專案只使用一種風格
  * 有疑慮 (缺乏信心) 時就需要測試

#### 物件導向式
  * 繼承與重用
  * Override 與 if
  * 動態新增的能力來自於原型鏈 (prototype)，因此如果繼承實現方式與原型鏈無關就無法動態新增。
  * `class` 與 `extends`
  * 建構子函式
      * 綁定子物件與父物件, `Child.prototype = Object.create(Parent.prototype)`
  * 物件實字
  * 工廠模式 (closure return)
  * 繼承是很強大的關係，必須確保真正需要，而非只是減少重複的程式碼。

#### 創建物件
  * 物件實字
  * 類別 (`new`)
  * 建構子函式 (`new`)
  * 工廠模式 (closure return)
  * `Object.assign()`, `Object.create()`
  * 第三方函式庫

#### 容器
  * Set
  * Map
  * Array
  * String
  * Function
  * 其他型別


------------------


### 第九章 - 重構為各種物件導向模式

#### 模板方法模式 (template method)
  * 同名函式上移
  * 函數式範型, 單一函式傳入物件。

#### 策略模式 (strategy)
#### 狀態模式 (state)
#### null 物件
  * 不回傳 `null` 或 `undefined` 而是一個 Null物件，包含相同的函式處理 null 時的情況。
#### 裝飾器 (decorator)
#### 轉換器 (adapter)
#### 外觀模式 (facade)
  * 客製化的中間層 interface


------------------


### 第十章 - 重構異步
  * callback hell
  * 提取命名的回呼函式

#### 測試異步程式

#### Promises
  * chaining
  * `new Promise()`
  * `resolve()`, `.then`
  * `reject()`, `.catch`
  * `Promise.all`
  * `Promise.race`


------------------


### 第十一章 - 使用函數式範式重構
  * 分離執行時間與宣告
  * 建議順序
      1. JavaScript 原生的陣列高階函式, forEach, map, filter, reduce, ...
      1. 嘗試使用第三方函式庫 underscore 或 lodash
      1. 習慣使用第三方函式庫 Ramda 或 Sanctuary
      1. 嘗試使用更多函數式抽象概念, 
      * 嘗試使用 Immutable.js 或 mori 強制不可變性。
      * 嘗試使用編譯式的 JavaScript，例如 TypeScript。
      * 嘗試其他編譯式的函數式程式語言, Haskell, Scheme/Closure, Erlang, Scala

#### 函數式的限制與好處
  * 限制
      * 沒有變數，只有值，即常數。
      * 沒有共享的全域狀態
      * 很難賦值，值只作為函數的參數與回傳。
      * 函數永遠回傳某些東西。
      * `if` 必有 `else`
      * 沒有 `null`
      * 沒有狀態改變, 即沒有時間。
  * 好處
      * 相同的輸入必有相同的輸出
      * 純函式避免 race conditions 可以任意的平行處理。
      * 因為純函式，因此可以用值取代函式運算，安全的快取 （memorize)。

#### 基礎
  * 避免重新賦值，所有值都是 atomic。
  * 避免在迴圈中重新賦值，改用 `map`, `filter`, `reduce`, 回傳新的內容。
  * 取代 for loop 的工具，`every`, `filter`, `find`, `forEach`, `map`, `reduce`, `some`
  * 避免使用不純的函式，包含內建函式。
  * 別回傳 `null`, 可以使用 Null 物件模式取代。
  * 嚴格的分離純函式與不純函式。例如存在不同的 namespace 下。

#### 進階基礎
  * 柯里化 (currying), 部分應用 (partial application)
      * 第三方函式庫 (Ramda), 提供函式 (`R.curry()`) 讓任意函式柯里化。
      * 柯里化 (currying) 產生部分應用 (partial application) 回傳另一個函式。
  * 函式組合 (function composition)
      * 無參數風格程式設計 (Point-Free Programming), 柯里化後的單變數函式容易做到。
      * `R.compose()`
      * `R.map()`
      * `R.memoize()`
      * `R.pipe()`
  * 型別 (type)

#### Others
  * Monoids
  * functor
  * Applicatives
  * Monad


------------------


### 第十二章 - 結語