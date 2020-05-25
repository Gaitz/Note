## 可測試的 JavaScript
### BOOK resource, JavaScript/Testing

------------------

第一章 - 可測試的 JavaScript 程式 (Testable JavaScript)

第二章 - 複雜度 (Complexity)

第三章 - 事件導向架構 (Event-Based Architectures)

第四章 - 單元測試 (Unit Tests)

第五章 - 程式碼涵蓋率 (Code Coverage)

第六章 - 整合 (Integration)、效能 (Performance) 以及負載 (Load) 測試

第七章 - 除錯 (Debugging)

第八章 - 自動化 (Automation)

------------------


### 第一章 - 可測試的 JavaScript 程式 (Testable JavaScript)
  * Agile Development (fail fast, release often, backlog, standup, continuous, user stories, pair programming)
  * Test-Driven Development (TDD)
  * Behavior-Driven Development (BDD)
  * 目的是寫出清楚、鬆散耦合、擁有良好註解、能夠轉交他人維護的程式碼。
  * 看起來、編譯起來、除錯起來、使用起來皆是專業等級。
  * 寫短小、獨立 (isolatable)、最小相依性 (dependencies)、與最小複雜度 (complexity) 的程式碼

#### 程式碼是為人而寫的
  * 觀看並且了解程式碼的難易程度。可理解的程式碼才能被維護。

#### 測試
  * Unit Tests
  * Integration Tests
  * Performance Tests / load testing


------------------------------


### 第二章 - 複雜度 (Complexity)
  * 可維護的程式碼是清楚、前後一致、標準化導向的
  * 可測試的程式碼是鬆散耦合、短小、獨立的
  * 正確分離出程式碼複雜的區塊，應該複雜的地方 (複雜的核心演算法) ，與可以降低複雜度的程式碼區塊。

#### 程式碼大小 (Code Size)
  * 分離 command 與 query。對應則是 setters (do something); getters (return something)。
  * 避免邊際效應 (side-effect)
  * 使用 IIFE 實現 private data 與 public setters/getters + validator 配合 `Object.preventExtensions(this)` 防止預期外的擴充。

#### JSLint
  * compiler time static error detection
  * 讓團隊撰寫的程式碼盡可能像是同一個人寫出來的。(一致的風格)

#### 循環複雜度 (Cyclomatic Complexity)
  * 分支數量/所需單元測試的最小數量
  * 使用工具 **jsmeter** 幫忙檢測，目標是 **< 10**
  * 循環複雜度太高容易產生誤修 (bad fix) 與越複雜可靠度越低。
  * 盡可能拆成較小的函式，分開測試。
  * 把循環複雜度檢測加到 pre commit hook 或 build process 中。
  * 可使用工具 **jscheckstyle** (npm) 配合 **Jenkins**

#### 重複使用 (Reuse)
  * 使用函式庫與第三方函式庫
  * 一般應用程式只有 15% 是 application-specific，其他則是 65% domain-specific 與 20% domain-independent。
  * 減少重新造輪子，先搜尋現有解決方案，才自行動手。
  * 當出現重複的程式碼時，就是應該抽取出來成為函式的時候。警覺的面對重複的程式碼。

#### 扇出 (Fan-Out)
  * 直接使用到的外部物件數量 (`new`) + 全域變數數量
  * 盡可能 `< 4`, 數字越高越緊密耦合 (tight coupling)
  * facade pattern 與 dependency injection

#### 扇入 (Fan-In)
  * 數字越高重用度越高

#### 耦合 (Coupling)
