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

- `DELETE` `FROM` `WHERE`
- `DELETE` 用來刪除 rows / records
- 使用 `DELETE` 前最好都先在相同的條件下運行一次 `SELECT` 確認要刪除的內容
- `UPDATE` `SET` `WHERE`
- `UPDATE table_name`
- `SET column_name = newvalue`
- `WHERE column_name = somevalue;`
- `UPDATE` 更新單筆或多筆 records/rows
- `SET` 使用 `,` 更新多個 fields/columns
- `SET` 除了直接指定新的 value, 也可以使用舊的資料進行運算
  - 數值運算
  - 文字修改函式, 例如 `UPPER()`, `LOWER()`

---

### 第四章 - 聰明的資料表設計

---

### 第五章 - ALTER

---

### 第六章 - SELECT 進階

---

### 第七章 - 複數資料表的資料庫設計

---

### 第八章 - 聯結與複數資料表的操作

---

### 第九章 - 子查詢

---

### 第十章 - 外部聯結、自我聯結與聯集

---

### 第十一章 - 限制條件、視觀表、交易

---

### 第十二章 - 安全性

---

571
