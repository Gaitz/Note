## 深入淺出 SQL

### BOOK 深入淺出 SQL Beighley O'reilly, ComputerScience/Database

---

第一章 - 資料與表

第二章 - SELECT 陳述句

第三章 - DELETE 與 UPDATE

第四章 - 聰明的資料表設計

第五章 - ALTER

第六章 - SELECT 進階

第七章 - 複數資料表的資料庫設計

第八章 - 聯結與複數資料表的操作

第九章 - 子查詢

第十章 - 外部聯結、自我聯結與聯集

第十一章 - 限制條件、視觀表、交易

第十二章 - 安全性

---

### 第一章 - 資料與表

DATABASE

- database
- table
- column, field
- row, record
- `CREATE DATABASE`
- `USE`
- `;` 是必要的

資料型別

- `CHAR`
- `VARCHAR`
- `BLOB`
- `INT`
- `DEC`
- `DATE`
- `DATETIME`

TABLE

- `CREATE TABLE ();`
- `DEFAULT`, 設定 column 的預設值
- `NOT NULL`, 設定 column 不能為 `NULL`, 因此可能是必填或者有提供預設值設定
- `DESC`
- `DROP TABLE`

Row, record

- `INSERT INTO VALUES ();`
- 字串使用 `'` 包裹
- 跳脫字元 `\`

Select

- `SELECT * FROM `
- `*`

---

### 第二章 - SELECT 陳述句

- `SELECT * FROM WHERE;`
- `SELECT` 指定 field 名稱
  - 搜尋指定的內容, 可以加速搜尋
- `WHERE` 指定搜尋的判斷句
- `=`, `>`, `>=`, `<`, `<=`
- `AND` 邏輯算子
- `OR` 邏輯算子
- `IS NULL`
- `LIKE`,
  - `%`, 任意數量未知字元
  - `_`, 一個未知字元
- `BETWEEN`
  - `>=` `AND` `<=` 的語法糖
- `IN ()`,
  - `NOT IN ()`
- `NOT` 邏輯算子
- 在搜尋的時候要意識到 `NULL` 無法使用 `=` 來尋找
  - 而是必須使用關鍵字 `IS NULL` 來找

---

### 第三章 - DELETE 與 UPDATE

- `DELETE` 用來刪除 rows / records
  - `DELETE` `FROM` `WHERE`
  - 使用 `DELETE` 前最好都先在相同的條件下運行一次 `SELECT` 確認要刪除的內容
- `UPDATE` 更新單筆或多筆 records/rows
  - `UPDATE` `SET` `WHERE`
  - `UPDATE table_name`
  - `SET column_name = newvalue`
  - `WHERE column_name = somevalue;`
- `SET` 使用 `,` 更新多個 fields/columns
- `SET` 除了直接指定新的 value, 也可以使用舊的資料進行運算
  - 數值運算
  - 文字修改函式, 例如 `UPPER()`, `LOWER()`

---

### 第四章 - 聰明的資料表設計

- 正規化, normalization
- 簡短的 query 是更好的 query
  - 速度更快
- **資料的儲存方式, 應該取決於使用方式**

Relational Database Management System, RDBMS

- 關聯性 Relational
  - 資料之間互相的關係
- Atomic Data 資料的單元性
  - 取決於資料的使用, 需要到多細緻的資料
- 具備單元性的 table
  - 單個欄位 (column) 中不會有多個相同類型的資料 (過多的資料)
  - 每個 row 中不會有重複資料類型的欄位, 每個類型的資料只有單獨的欄位
- 單元性的資料更容易撰寫 query

正規化 normalization

- 讓資料具有單元性 atomic
- 正規劃資料沒有重複的資料, 可以減少資料庫的大小, 避免不必要的耦合
- 第一正規化 (First Normal Form, 1NF)
  - Atomic 資料
  - 規則 1. 資料欄只包含具單元性的值
  - 規則 2. 沒有重複的資料群組
- 具有 Primary Key 欄位
- Primary Key 欄位, 代表每個 row 有獨一無二的值
  - 不可為 Null
  - 新增 Record 時, 必須同時指定 Primary Key 的值
  - 必須簡潔
  - 不可修改
- Primary Key 的選擇
  - Natural, 現有的資料中, 有符合條件的欄位
  - Synthetic, 虛構的, 由 SQL 自動生成的 ID 欄位
- 指定 Primary Key 欄位
  - `PRIMARY KEY ()`

更新 Table columns

- `SHOW CREATE TABLE` 查詢當時生成的指令
- 使用 `ALTER` 為現有 table 新增 Primary Key 欄位
  - `ALTER TABLE ... ADD COLUMN ... INT NOT NULL AUTO_INCREMENT FIRST, ADD PRIMARY KEY (...);`

`SHOW` 指令

- `SHOW COLUMNS FROM`
- `SHOW CREATE DATABASE`
- `SHOW INDEX FROM`
- `SHOW WARNINGS`

自動生成的欄位

- `AUTO_INCREMENT`
- 每個 table 裡只能有一個 AUTO_INCREMENT column

---

### 第五章 - ALTER

指定新增欄位的順序

- `LAST`, default
- `FIRST`, `SECOND`, `THIRD`, ...
- `AFTER`, `BEFORE`,

`ALTER` 的風險

- **修改現有的資料型態, 可能會引起資料遺失**

`ALTER` 的指令

- `RENAME`, 修改名稱
  - `ALTER TABLE ... RENAME TO ...`
- `CHANGE`,
  - `ALTER TABLE ... CHANGE COLUMN ...`, 修改現存欄位, 名稱, 型別, ...
- `MODIFY`, 修改欄位型別
  - `ALTER TABLE ... MODIFY COLUMN ...`
- `ADD`, 新增欄位
  - `ALTER TABLE ... ADD COLUMN ...`
- `DROP`, 移除欄位, **包含資料**
  - `ALTER TABLE ... DROP COLUMN ...`
  - `ALTER TABLE ... DROP PRIMARY KEY`, 移除 PRIMARY KEY 設定

好設計

- 讓 table 只保留必要的欄位, 不需要預留當前用不到的欄位
  - 直接 DROP 不需要的欄位
  - 有需要再 ALTER 回來即可

調整現有欄位的設計與內容的移動

- 使用 `ALTER ADD COLUMN` 新增所需要的欄位
- 以 `UPDATE ... SET` 以其他欄位的值, 更新到新的欄位中
  - 配合字串相關函數使用

`SELECT` 字串相關工具, String Functions

- `RIGHT()`, `LEFT()`, 取得指定數量的字元
- `SUBSTRING_INDEX()`, 分割且取得指定的內容
- `SUBSTRING()`, 取的指定位置的 substring
- `UPPER()`, `LOWER()`, 轉換成全大寫或全小寫
- `REVERSE()`, 反轉字串
- `LTRIM()`, `RTRIM()`, 清除左側或右側空白後輸出
- `LENGTH()`, 回傳字串長度

---

### 第六章 - SELECT 進階

- `CASE`, RDBMS, 中的條件句
  - `WHEN`, `THEN`, `ELSE`
  - `END`
- `CASE` 語法可以使用在
  - `SELECT`, `INSERT`, `DELETE`, `UPDATE`
- `ORDER BY`, 排序
  - 配合 `ASC` 或 `DESC` 指定升幕或降幕序
- 負責計算的函數,
  - `SUM()`, 加總
  - `AVG()`, 平均值
  - `MAX()`, `MIN()`, 極大值, 極小值
  - `COUNT()`, 計數
- `GROUP BY`, 分群
- `DISTINCT`, 只計算不同的值 (相同的值則忽略)
- `LIMIT`, 限制回傳數量
  - 單參數版, 從第一項開始的數量
  - 雙參數版, 開始序與數量

---

### 第七章 - 複數資料表的資料庫設計

- 把不合 atomic data 的資料, 存入另一個獨立的資料表 (table) 中
- Schema, 資料的描述
- 資料表之間用資料的 ID 進行連結
- Foreign Key
  - 用於連結其他的資料表, Parent Table
  - 可以為 Null 代表在 Parent Table 沒有對應的資料
- Foreign Key 限制條件 (constraint)
  - Referential Integrity (參照完整性), Foreign Key 必需已經存在 Parent Table 裡
  - 語法 `CONSTRAINT ... FOREIGN KEY (...) REFERENCES ... (...);`
  - 通過語法讓 RDBMS 知道是 Foreign Key 並且檢查限制保證連結性
- 好的習慣
  - 把 Primary Key 欄位作為第一項和 Foreign Key 類的欄位都至於前幾項

資料表之間的關係

- 一對一
  - 使用時機 1. 加速搜尋, 如果需要時常搜尋某種類型的資料, 可以分割成一對一的資料表
  - 使用時機 2. 資料的隔離, 把特殊的資料隔離在另外的資料表中, 因此可以設置存取限制
  - 使用時機 3. 巨大的資料, 隔離在另外的一對一資料表中, 可以加快其他資料的搜尋
- 一對多
- 多對多
  - 把多對多的關係表, 通過 junction table 形成兩組一對多的關係, 避免重複的資料, 更簡單化
  - junction table 單純記錄兩個 table 之間的 id 關係
- 好習慣,
  - 遇到多對多關係時, 一定要使用 junction table 避免重複的資料, 維持 Normalization

組合鍵 Composite Key

- 由複數資料欄位形成的 Primary Key, 藉由組合複數個欄位後形成 Unique

功能相依性 Functional Dependency

- 欄位之間具有關聯, 在修改時有需要一起修改的情形

部分功能相依性 Partial Functional Dependency

- 非 Key 的資料欄相依於 Composite Key 的部分欄位
- **使用獨立的 Primary Key 取代 Composite Key 來避免此問題**

遞延功能相依性 (Transitive Dependency)

- 任何非 Key 資料欄位和其他的非 Key 資料欄位有相依性

第二正規化 (Second Normal Form, 2NF)

- 符合 1NF 條件
- 並且沒有部分功能相依性 (Partial Functional Dependency)
  - 可以藉由建立獨立的 Primary Key 欄位來達成
  - 或者以所有欄位組合成 Composite Key (因此沒有任何非 Key 欄位)

第三正規化 (Third Normal Form, 3NF)

- 符合 2NF 條件
- 並且沒有遞延功能相依性 (Transitive Dependency)

---

### 第八章 - 聯結與複數資料表的操作

- `AS` 搜尋結果新增到另一個資料表中
- `CREATE TABLE ... () AS SELECT ...`
- 別名 `AS`
  - 查詢結果以 `AS` 命名別名, 方便之後使用

Inner Join 內部聯結

- 第一種 Join, **no join**, `CROSS JOIN`, Cartesian Join, Comma Join
  - 單純兩個 table 的內容相乘組合成的 table
  - 容易造成非常巨大的 table (產生效能問題)
- `INNER JOIN`
  - `table1 INNER JOIN table 2 ON some_condition`
- 依據條件分成
  - equijoin 相等性的內部聯結
  - non-equiljoin 不等於的內部聯結
- `NATURAL JOIN` 自然聯結
  - 當 key 的名稱在兩個 table 中都相同時
  - 可以直接使用 `NATURAL JOIN` 取代 `INNER JOIN ON` 的 equijoin 敘述

---

### 第九章 - 子查詢

- 子查詢 subquery
  - 分成 outer query 與 inner query
  - 藉由其他搜尋結果組成的搜尋命令
  - 使用 `()` 包裹子查詢
- 非關聯性子查詢 (noncorrelated subqueries)
  - 子查詢是完全獨立的不會參照到 outer query 的任何結果時
- 多數時候 subquery 可以使用 join 來取代並且
  - **subquery 跟 join 比起來, join 效能更佳**
- `EXISTS`
- `NOT EXISTS`

---

### 第十章 - 外部聯結、自我聯結與聯集

Outer Join 外部聯結

- 與聯結的 table 順序有關
- Outer Join 一定會提供所有的主體資料列, 無論是否有在另外一個 Table 找到對應的資料, 因此會允許出現 `Null` 資料的情況

Left Outer Join 左外部聯結

- `LEFT OUTER JOIN`
- 以左側資料表作為主體去比對右側資料表
  - 不管如何都會呈現完整的左側資料表項目, 當右側資料表沒有對應值時, 會填上 `Null`

外部聯結與複數相符結果

- 有多個結果相符合時, 會全部呈現

Right Outer Join 右外部聯結

- `RIGHT OUTER JOIN`
- 等同於 Left Outer Join 只是搜尋的主體改成右側資料表

Self Join 自我聯結

- 使用同一個資料表來做 Join
  - 即 Join 敘述的左側資料表與右側資料表相同
- 自我參照外鍵 Self-referencing Foreign Key
  - 這個 Foreign Key 欄位的值是同一個 table 裡的 Primary Key
  - 通常用來表達同一個 table 裡各個 row 之間有關聯

Union 聯集

- `UNION` 把多個 `SELECT` 的結果組合後一起輸出
  - 前提是, 這些 `SELECT` 分別的回傳結果需要相同數量,
  - 預設會自動清除相同的結果 (Set)
- `UNION ALL`, 不會自動清除相同的結果
- 把 UNION query 的結果存成一個新的資料表, 方便後續使用
  - `CREATE TABLE ... AS ...`

Intersect 交集

- `INTERSECT`
- 不是每個 SQL 都支援

Except 差集

- `EXCEPT`
- 不是每個 SQL 都支援

子查詢與聯集的比較, Subquery vs. Join

- **聯集執行速度比子查詢快**
- 子查詢, 可以使用 Function, (`AVG`, `MAX`, ...) 因此提供更實用的結果
- 使用與否, 主要取決於可閱讀性和是否需要子查詢才能提供的功能

---

### 第十一章 - 限制條件、視觀表、交易

限制條件 constraint

- `CHECK`,
  - 在建立 table 時, 加上限制, 讓未來進行操作時能自動檢查, 避免預期以外的資料
  - 與 `Where` 使用相同的條件式語法, 但是無法使用子查詢
- 後續修改加上限制條件
  - `ALTER TABLE ... ADD CONSTRAINT CHECK ...`

視觀表 view

- 把常使用的 query 建立成 View
- `CREATE VIEW ... AS ...`
- view 只是一個虛擬資料表 (virtual table)
  - 不會實際保存在資料庫裡, 只有語法被保存
- 好處
  - 把複雜的查詢簡化成一個指令
  - 作為對資料庫外部的介面 (interface) 使用
  - 隱藏機密內容, 只暴露所需要的內容
- 對 View 進行 `INSERT`, `UPDATE`, `DELETE` 是允許的, (updatable views)
  - 在建立 View 時的指令上必須加上 `WITH CHECK OPTION` 才會檢查建立該 view 時的條件 (`WHERE`)
  - 否則, 不會建立限制
  - **沒有特殊的原因需要對 view 進行 `INSERT`, `UPDATE`, `DELETE`**
- `DROP VIEW` 清除

當資料庫的使用者不只一個人時, 以下技術有助於維護控制權

- 使用 `CHECK` constraint
- `VIEW`

交易 Transaction

- 資料庫是個 multiple thread 軟體
- 把多個動作打包成一個 transaction
  - 只有完全成功或者失敗, 兩種選項
  - 失敗的話會自動 Rollback
- ACID
  - A, Atomicity, 單元性
    - 每個步驟都必須完成, 否則即失敗, 沒有部分完成的階段
  - C, Consistency, 一致性
    - 整個資料庫維持一致的限制, 不會破壞限制
  - I, Isolation, 獨立性
    - 多個 transaction 不會互相影響 (同時修改)
  - D, Durability, 耐久性
    - 寫入永久儲存記憶體中
- `START TRANSACTION;`, 開始一個 transaction
- `COMMIT;`, 確認可以實現了
- `ROLLBACK;`, 放棄並且進行 rollback
- 儲存引擎 storage engine
  - 資料庫的底層實作類型
- 資料庫會為 transaction 建立 transaction log
  - 因此, transaction 應該只在必須使用的情況下才使用

---

### 第十二章 - 安全性

- 依據使用者控制權限
- 使用者帳號 (user account)
- 預設的第一位使用者 **root**
  - **一定要為 root user 建立密碼**
- 新增使用者
  - `CREATE USER ... IDENTIFIED BY ...`
  - 不同 SQL 語法不同
- 新增權限設定 (permission)
  - `GRANT ... TO ...`
  - `WITH GRANT OPTION`, 與許給予其他使用者權限的權限
- 撤銷權限
  - `REVOKE ... FROM ...`
  - `REVOKE GRANT OPTION ... FROM ...`
    - 取消使用者給予權限的能力, 會一並取消之前賦予其他使用者的權限
  - 預設為 `CASCADE` 權限連鎖取消
  - `RESTRICT` 只影響目標權限, 沒有連鎖效應
- 建立角色 (Role)
  - `CREATE ROLE`
  - `GRANT role_name TO user_name;`
    - 賦予個別使用者為某些角色, 來賦予權限, 而非單獨指定
  - `DROP ROLE ...` 移除不需要的角色設定
- 賦予其他使用者角色的權利
  - `WITH ADMIN OPTION`

---

571
