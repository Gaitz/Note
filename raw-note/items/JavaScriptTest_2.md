## 可測試的 JavaScript
### BOOK resource, JavaScript/Testing

太多實際範例，內容容易過時。

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
  * 目標是最小化複雜度

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
  * 內容耦合 (Content Coupling), 5, 修改外部變數
  * 共用耦合 (Common Coupling), 4, 兩個物件共用同一個外部變數
  * 控制耦合 (Control Coupling), 3, 傳遞 flag 或 parameter 影響外部物件運作
  * 戳記耦合 (Stamp Coupling), 2, 傳遞不會被使用到的資訊給外部物件
  * 資料耦合 (Data Coupling), 1, 物件之間的資料傳遞
  * 無耦合 (No Coupling), 0,
  * 生成新物件 (Instantiation), `new`, 非常緊密的耦合關係
  * 耦合越多會造成單元測試必需建構更多的 mock 和 stub 去分離測試。

#### 相依性注入 (Dependency Injection)
  * 取代在建構子中實體化其他物件 (instantiation)，更改為注入的方式 (injection)
  * 利用注入的方式把實體化物件的工作都留在應用程式的最初期，方便控制物件實體的範圍與共用 (scope)。

#### 註解 (Comments)
  * 撰寫註解最重要的是要隨時更新註解
  * 結構化註解 (structured comments) 可以配合其他工具輕易的生成註解文件。
  * 文件生成工具 YUIDoc, JSDoc, Docco/Rocco, ...

#### 人為測試 (The Human Test)
  * 人為實際 review 程式碼與註解


------------------------------


### 第三章 - 事件導向架構 (Event-Based Architectures)
  * 避免實體化與維護外部變數，消除 tight coupling
  * event and listener
  * call and return
  * 資料與模組是分離的
  * **socket.io** 函式庫 (Real time, Event-based architectures, Node.js)

#### 事件集線器 (The Event Hub)
  * 事件管理中心, listen and fire
  * 單純的傳遞事件，簡單的 controller。domain-independent

#### 回應丟出的事件
  1. 不需要回傳值，fire 事件即可。
  2. 需要處理回傳值, fire 事件並且傳入 callback 處理結果

#### event-based architectures 與 MVC
#### event-based architectures 與 OOP

#### Web 應用程式
  * http server 當初只是單純的單向處理協定與靜態資料
  * 雙向通訊改用 Web Sockets

#### 事件導向架構注意事項
  * 擴展性 (Scalability), event hub 作為中心 controller 需要多組來做 load balance 增加服務可靠度。
  * 廣播 (Broadcasting), 注意事件的傳送，避免廣播造成的流量浪費。
  * 執行期確認 (Runtime Checking), 事件名稱的傳遞，應該使用 enumerations 或 hashes 而非單純的字串 (String)
  * 安全性 (Security), 需要實作權限管理與傳遞加密, 避免有疑慮的註冊與執行。
  * 狀態 (State), session cookie 傳遞

#### 更聰明的事件處理中心, 事件交換器 (The Event Switch)
  * Deployment, 控制事件註冊與廣播，在不需要關閉 Http service 的情況下升級模組。
  * 單播事件 (Unicast events), 事件只有唯一一個 listener
  * 廣播事件 (Broadcast events), 通知所有的 listeners 然後關閉事件。


------------------------------


### 第四章 - 單元測試 (Unit Tests)
  * 選用測試框架

#### 寫出好的測試程式
  * 獨立 (isolation), 測試的獨立性, 使用 mocks, stubs 去模擬外部相依。
  * 範圍 (scope), 盡可能的小範圍, 單一個 method。

#### 定義函式
  1. 撰寫函式開頭註解, 確定函式規格 (specification)
  1. 撰寫測試程式
    * 正面測試 (Positive Testing),
    * 邊界測試 (Bounds Testing), corner
    * 負面測試 (Negative Testing), 

#### 相依性 (Dependencies)
  * Mock, 模擬命令執行 (command)
  * Stub, 模擬回傳 (query)

#### 非同步測試 (Asynchronous Testing)

#### 測試 client-side 程式 
  * PhantomJS (headless)
  * Selenium (web driver)
  * 測試 mobile 裝置

#### 測試 server-side 程式
  * Jasmine


------------------------------


### 第五章 - 程式碼涵蓋率 (Code Coverage)
  * 過高的測試覆蓋率並不代表可靠性，測試覆蓋率是有誤導可能的。
  * 測試覆蓋率只是良好的測試帶來的成果，而非追求的目標。


------------------------------


### 第六章 - 整合 (Integration)、效能 (Performance) 以及負載 (Load) 測試

#### 整合測試 (Integration Testing)
  * Selenium + web driver
  * CasperJS (headless)

#### 效能測試 (Performance Testing)
  * HAR, HTTP Archive
  * Browser 內建的開發者工具
  * 深入了解瀏覽器運作

#### 負載測試 (Load Testing)
  * 目標是找到可接受的最長回應時間
  * Apache Bench
  * nodeload (Node.JS)

#### 追蹤資源使用率
  * 監測 CPU 與 memory
  * 需要被監測的情況為
    1. 長時間開啟的 client-side 應用程式 (SPA)
    1. 伺服器端程式 (daemon)
  * Memory leak
  * CPU usage
  * Client-side, 使用瀏覽器提供的工具檢測
  * Server-side (Node.js), webkit-devtools-agent, heapdump, 


------------------------------


### 第七章 - 除錯 (Debugging)

#### 瀏覽器內的除錯 (In-Browser Debugging)
  * 各家瀏覽器的開發者工具

#### Node.js 除錯

#### 行動裝置除錯
  * Android, 配合 Android Software Developer Kit (SDK), 連到桌機版除錯
  * iOS, 使用 safari 開發者工具連結桌機版 safari


------------------------------


### 第八章 - 自動化 (Automation)
  * 自動化所有的事情
  * 持續整合 (Continuous Integration, CI)

#### 自動化開發環境 (Code)
  * Editor, 選用適合的編輯器，更多自動化功能的。
  * Unit Test, 能夠快速自動執行單元測試的工具
  * Pre-commit hook, 自動執行 unit test, Lint, ...
  * Post-commit hook, 

#### 自動化建置環境 (Build) 
  * Jenkins
  * minify, uglify, unit testing, integration testing,

#### 自動化怖署 (Deploy)