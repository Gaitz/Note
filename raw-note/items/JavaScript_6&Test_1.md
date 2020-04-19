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


------------------


### 第五章 - 基本的重構目標

#### 函式
  * 體積
    * 複雜度 (路徑分支的數量)
    * 行數
  * 顯性輸入
    * 
  * 輸出
  * 副作用 (side-effect)
  * 隱性輸入 (this)
  * 隱私 (privacy)