## SQL 學習手冊, 第三版

### BOOK SQL 學習手冊, Alan Beaulieu ,O'reilly, ComputerScience/Database

---

第一章 - 一點背景知識

第二章 - 建立並填製資料庫

第三章 - 基礎查詢

第四章 - 篩選

第五章 - 查詢多個資料表

第六章 - 集合的運用

第七章 - 資料的產生, 操作與轉換

第八章 - 分組與彙整

第九章 - 子查詢

第十章 - 再談結合

第十一章 - 條件邏輯

第十二章 - 交易

第十三章 - 索引與約束條件

第十四章 - Views

第十五章 - 中繼資料

第十六章 - 分析函式

第十七章 - 操作大型資料庫

第十八章 - SQL 與大數據

---

### 第一章 - 一點背景知識

資料庫的發展歷史

- database, 說穿了就是彼此有關聯的資訊集合 (**補**, set)
- 最早被發展出來的應用程式之一, 為了解決手動維護紙本資料的困擾
  - 並且隨著硬體與軟體的發展, 現代的資料庫系統, 可處理的資料量與速度是過往無法想像的數量級

非關聯式的資料庫系統

- 階層式資料庫系統 (hierarchical database system)
- 單源階層 (single-parent hierarchy), 以樹狀結構儲存
- 網路式資料庫系統 (network database system), 以 graph 結構儲存
  - 也常被視為多源階層 (multiparent hierarchy)

關聯式模型

- 1970, IBM 研究實驗室的 Edgar Frank Codd (E.F. Codd) 的論文 _A Relational Model of Data for Large Shared Data Banks_
- 以 tables 取代 entities, 即資料實體與資料實體之間去耦合, 而是通過資料表來實現關聯
- 欄位 ( **columns** ), 資料 ( **rows** )
  - 每個資料庫系統的 columns 數量上限各有不同, (_補_, 例如 PostgreSQL 18, 上限是 1600 columns per table)
  - 資料量的上限屬於物理限制和可維護性來決定
- 用來獨一無二識別資料的欄位, 主鍵 ( **primary key** )
  - 多個欄位組成的主鍵, 複合鍵 ( **compound key** )
  - 自然鍵 ( **natural key** ), 使用資料本身欄位形成的, 而不用資料庫生成的 id
  - 代理鍵 ( **surrogate key**), 生成 id
  - 外來鍵 ( **foreign key** ), 來自其他 table 的 primary key 欄位, 作為關聯使用
- 結合 ( **join** ), 關聯數個資料表一起
  - 結果集合 ( **result set** )
- 實體之間彼此重複的資料 ( redundant data )
- 正規化 ( **normalization** ), 將資料庫設計加以精簡, 確保各自的資料只會存在一處, 除去外來鍵之外, 去除所有的 redundant data

SQL

- Codd 論文中提出的一種 DSL/Alpha 語言,
  - 由 IBM 進行實作命名為 SQUARE
  - 持續演進衍生出 **SEQUEL** 語言
- 1980 年代中由 American National Standards Institute, ANSI, 開始制定 SQL 語言標準
  - _補_, 各家資料庫版本並不一定會完全符合標準, 並且各自擁有不相容的方言
- **SQL schema statements**, 定義資料表
- **SQL data statements**, 操作資料
- **SQL transaction statements**, 設置交易 (transaction)

SQL 並非 procedural programming language

- 無法控制命令的執行方式
- 一切由資料庫引擎中的 optimizer 決定執行方式
- 多數資料庫系統允許使用 optimizer hints 去影響最佳化的執行方式
- 因此, 資料庫系統無法建立出完整的應用程式, 而是需要配合其他程式語言一起使用
- 一些與 SQL 整合好的程式語言, 例如: PL/SQL, MySQL stored procedure, Transact-SQL
- 其他程式語言則需要使用 toolkit 或者 API 來撰寫 SQL statement 並且與資料庫系統溝通
  - 例如: Java: JDBC, Go: database/sql, ...
- 圖形化工具來與資料庫系統互動
  - 例如: Squirrel

SQL 範例

- `SELECT`, `FROM`, `WHERE`
- comment, `/*` ... `*/`
- 查詢句
  - 會用到哪些 table, 列在 `FROM`
  - 篩選目標資料的條件, 列在 `WHERE`
  - 想要讀取哪些欄位 (column), 列在 `SELECT`
- 填入資料
  - `INSERT INTO`
  - `VALUES`
- 修改資料
  - `UPDATE`
  - `SET`
- **撰寫 SQL 相關程式時, 應該要檢查 SQL 執行完的回傳結果, 以確保如預期的執行**

SQL 關聯式資料庫系統

- 商業版
  - Oracle Database
  - 微軟的 SQL Server
  - IBM 的 DB2 Universal Database
- 社群版 (open source)
  - PostgreSQL
  - MySQL server
- 資料庫實作是否符合 ANSI 標準, 是 SQL 語法是否可以移植使用的關鍵之一

額外的參考書

- C.J. Date, _Database in Depth: Relational Theory for Practitioners_
- C.J. Date, _An Introduction to Database Systems_
- C.J. Date, _The Database Relational Model: A Retrospective Review and Analysis_

---

### 第二章 - 建立並填製資料庫

---

### 第三章 - 基礎查詢

---

### 第四章 - 篩選

---

### 第五章 - 查詢多個資料表

---

### 第六章 - 集合的運用

---

### 第七章 - 資料的產生, 操作與轉換

---

### 第八章 - 分組與彙整

---

### 第九章 - 子查詢

---

### 第十章 - 再談結合

---

### 第十一章 - 條件邏輯

---

### 第十二章 - 交易

---

### 第十三章 - 索引與約束條件

---

### 第十四章 - Views

---

### 第十五章 - 中繼資料

---

### 第十六章 - 分析函式

---

### 第十七章 - 操作大型資料庫

---

### 第十八章 - SQL 與大數據

---

342
