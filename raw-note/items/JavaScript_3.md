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