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

- database, 說穿了就是彼此有關聯的資訊集合 (_補_, set)
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

建立一個 MySQL 資料庫

- 安裝並且啟動一套 MySQL server, 從本地端或者使用雲端服務 (Amazon Web Services, Google Cloud)
- 啟動 cli 工具 `mysql`, 並且進入資料庫系統
- 使用 MySQL 官方提供的範例資料庫 sakila, https://dev.mysql.com/doc/index-other.html
  - 下載並且執行相關的 `.sql` 腳本 (`sakila-schema.sql`, `sakila-data.sql`)
- _補_, 在 PostgreSQL 中使用 sakila 範例
  - PostgreSQL 無法直接執行 MySQL 官方提供的腳本, 因為有使用到特定資料庫的語法, 因此無法直接相容
  - 使用第三方建立的 `.sql`, GitHub repo: https://github.com/jOOQ/sakila/tree/main
  - 執行 schema -> 執行 insert data

---

使用命令列工具 mysql

- MySQL 的 cli 工具, `mysql`
- 登入資料庫 server (建立連線), `mysql -u root -p`
- 查看所有現存的 databases, `show databases;`
- 選擇要操作的 database, 範例: `use sakila;`
- 查詢當下日期與時間, `SELECT now();`
- 離開 mysql cli, `quit;`, `exit;`
- `dual` table,
  - Oracle Database 要求所有的 SELECT 必須包含 `FROM`, 因此內建一個 dummy table `dual` 來符合這個要求
  - MySQL database 為了語法相容性, 也有內建一個相同名稱的 dummy table
  - _補_, PostgreSQL 中並不內建這個 dummy table
- _補_, in PostgreSQL
  - cli, `psql`
  - login, `psql -d database_name`
  - list database, psql 中 `\l`, 外部 `psql -l`
  - change using database, `\c` (connect 的意思)
  - 查看當前連線的資訊, `\conninfo`
  - 查詢當下日期與時間, `SELECT now();`
  - 顯示執行所花的時間, `\timing` 預設是 off
  - 離開 cli, `\q`

---

MySQL 的資料型別

- 資料庫系統之間的差異, 通常會出現在特殊資料型別, 例如: XML, JSON, ...
- 其他基本的資料型別, 通常都會實作

字元資料, (有長度上限的)

- 固定長度, `char()`, 上限: 255 bytes
- 非固定長度, `varchar()`, 上限: 65,535 bytes
- **每個資料庫系統實作資料型別的容量上限, 是不同的**
  - Oracle Database, 對於 `char` 上限 2000 bytes, `varchar2` 4000 bytes, `clob` ...
  - SQL Server, `char`, `varchar` 8000 bytes, `varchar(max)` 單個上限可達 2GB
- _補_, PostgreSQL
  - 固定長度, `character(n)`, `char(n)`, `bpchar(n)`, 有長度上限
  - 非固定長度, `character varying(n)`, `varchar(n)`, 有長度上限

convention

- 如果資料的字串長度都一致, 應該使用 `char` 型別, 例如: 省份的所寫

字元集 (character sets)

- 資料庫所支援的編碼集合
- 多位元組字元集 (multibyte character sets)
- mysql> `SHOW CHARACTER SET;`
- 可以為字元型別欄位, 選定不同的 character set (encoding)
  - 範例: `varchar(20) character set latin1`
- MySQL, 對資料庫進行預設值設定, `create database [database_name] character set [character_set_name];`
- _補_, PostgreSQL 不支援 mixed encoding
  - encoding 的設置是屬於 database 階層的, 不允許個別的資料型別有個別的 encoding 設置
  - `psql -l` 可以看到所有的資料庫與其編碼格式
  - `SHOW server_encoding;`, `SHOW client_encoding;`

文字資料

- 儲存文字資料大於 `varchar()` 的上限時
- MySQL 文字型別
  - `tinytext`, 255 bytes, 2^8
  - `text`, 65,535 bytes, 2^16
  - `mediumtext`, 16,777,215 bytes, 2^24
  - `longtext`, 4,294,967,295 bytes, 2^32
- **如果文字儲存超過該型別的上限時, 多餘的部分會被截斷**
- 輸入文字的尾端多餘的空白不會被自動移除
- 對 `text` 型別進行 排序, 分組時, 只有前 1024 bytes 文字會有作用
- MySQL 中文字型別是各異的; 但是其他資料庫實作不一樣
  - SQL Server, 只有一個文字型別用於儲存大量字元資料
  - DB2, Oracle 採用 `clob` (Character Large Object) 來儲存
- MySQL 中隨著版本更新 `varchar()` 支援的上限 >= `tinytext` 與 `text`, 因此後兩者逐漸失去使用情境
- _補_, PostgreSQL
  - `bpchar`, 無上限, 會自動刪除尾端的空白字元
  - `text`, 無上限

數字資料 (numeric)

- 整數型別 (integers)
- 可以加註 unsigned 表明所有的值都是 >= 0
- MySQL integers
  - `tinyint` (1 byte), signed: -128 ~ 127; unsigned: 0 ~ 255
  - `smallint` (2 bytes), signed: -32768 ~ 32767; unsigned: 0 ~ 65535
  - `mediumint` (3 bytes), signed: -8388608 ~ 8388607; unsigned: 0 ~ 16777215
  - `int` (4 bytes), signed: -2147483648 ~ 2147483647; unsigned: 0 ~ 4294967295
  - `bigint` (8 bytes), signed: -2^63 ~ 2^63 -1; unsigned: 0 ~ 2^64 -1
- MySQL 浮點數
  - `float(p, s)`
  - `double(p, s)`
  - (options) 可以指定 precision 小數點左右邊加起來的位數, 與 scale, 小數點後的位數
  - 超過位數會四捨五入或者出現錯誤
  - 一樣可以分成 signed, unsigned (作為限制的一種, 不影響有效位數)
- _補_, PostgreSQL
  - PostgreSQL 裡沒有 unsigned
  - 整數型別分成 `smallint` (2 bytes), `integer` (4 bytes), `bigint` (8 bytes)
  - 自定義: `decimal` == `numeric`,
  - 浮點數: `real`, `double precision`

時序資料 (temporal)

- 處理時間與日期
- MySQL
  - `date`, YYYY-MM-DD
  - `datetime`, YYYY-MM-DD HH-MI-SS
  - `timestamp`, YYYY-MM-DD HH-MI-SS
  - `year`, YYYY
  - `time`, HHH:MI:SS
- 對 `datetime`, `timestamp`, `time` 可以多定義秒數的精確值, 最多可以到小數點後 6 位
- **每個資料庫系統對於時間日期允許的範圍不同**
  - 主要差別在於對過去年份的支援度
- 針對不同的使用情境選用適當的型別

---

建立資料表, create table

步驟 1 設計

- 1 思考需要哪些資料
- 2 決定欄位名稱與資料型別

步驟 2 細分 (normalization)

- 資料正規化
- 確保資料庫中不出現 1 重複的資料, 2 複合式欄位 (compound columns)
  - compound columns 拆分成多個獨立欄位
  - 例如: 拆分 name 成 first_name, last_name 兩個欄位
  - 例如: 拆分地址成特定細化的欄位 postal_code, country, state, city, street, ...
- 拆分欄位到個別的資料表中 (another table)
  - 例如: favorite_food table
- 決定 primary key 欄位
- 決定 foreign key 欄位
- 正規化的程度, 與細緻化的程度, 取決於使用情境

步驟 3 建立 SQL 語句

`CREATE TABLE`

- MySQL 範例:
- ```sql
  CREATE TABLE person (
    person_id SMALLINT UNSIGNED,
    fname VARCHAR(20),
    lname VARCHAR(20),
    eye_color ENUM('BR', 'BL', 'GR'),
    birth_date DATE,
    street VARCHAR(30),
    city VARCHAR(20),
    state VARCHAR(20),
    country VARCHAR(20),
    postal_code VARCHAR(20),
    CONSTRAINT pk_person PRIMARY KEY (person_id)
  );
  ```
- _補_, 等價的 PostgreSQL 語法
- ```sql
  CREATE TYPE eye_color AS ENUM ('BR', 'BL', 'GR');
  CREATE TABLE person (
    person_id SERIAL,
    fname VARCHAR(20),
    lname VARCHAR(20),
    eye_color eye_color,
    birth_date DATE,
    street VARCHAR(30),
    city VARCHAR(20),
    state VARCHAR(20),
    country VARCHAR(20),
    postal_code VARCHAR(20),
    CONSTRAINT pk_person PRIMARY KEY (person_id)
  );
  ```

`CONSTRAINT`, `PRIMARY KEY`, `FOREIGN KEY`

- **primary key constraint**
- 主動加上 `CONSTRAINT`, `PRIMARY KEY` 來指定 primary key 欄位
- 主動加上 `CONSTRAINT`, `FOREIGN KEY` 來指定 foreign key 欄位
- MySQL 範例:
- ```sql
    CREATE TABLE person (
      person_id SMALLINT UNSIGNED,
      CONSTRAINT pk_person PRIMARY KEY (person_id)
    )
  ```
- MySQL 範例 2:
- ```sql
    CREATE TABLE favorite_food (
      person_id SMALLINT UNSIGNED,
      food VARCHAR(20),
      CONSTRAINT pk_favorite_food PRIMARY KEY (person_id, food),
      CONSTRAINT fk_fav_food_person_id FOREIGN KEY (person_id)
      REFERENCES person (person_id)
    );
  ```
- _補_, PostgreSQL 也有相同語法
  - 有兩種方式加上 PRIMARY KEY CONSTRAINT
    - 差異在於 CONSTRAINT 的 name 是否可以自訂
  - 1 在欄位型別的後面加上 `PRIMARY KEY`
    - 範例: `person_id SERIAL PRIMARY KEY`
    - 此時 PostgreSQL 會自動生成 constraint name
  - 2 使用 `CONSTRAINT` 標明
    - 範例: `CONSTRAINT pk_person PRIMARY KEY (person_id)`
    - 可以自訂 constraint name

`CHECK`

- **check constraint**
- 限制指定欄位的輸入值
- 範例:
- ```sql
    eye_color CHAR(2) CHECK (eye_color IN ('BR', 'BL', 'GR')),
  ```
- _補_, PostgreSQL 也有相同語法

`ENUM`

- MySQL enum 型別
- 範例: `eye_color ENUM('BR', 'BL', 'GR'),
- _補_, PostgreSQL 也有 ENUM
  - 不過語法不同, 不是直接用在 CREATE TABLE 中
  - 而是需要使用 `CREATE TYPE ... AS ENUM ();` 來定義 ENUM
  - 範例:
  - ```sql
      CREATE TYPE eye_color AS ENUM ('BR', 'BL', 'GR');
    ```
- _補_, PostgreSQL 查詢 custom types
  - `psql` 中, `\dT` or `\dT+` for verbose

MySQL `describe`

- 查看 table 定義
- `describe [table_name]`, `desc [table_name]`
- _補_, PostgreSQL
  - 在 `psql` 中, 可以使用 `\d` 來查看 table 定義

Null

- 無法提供預設值
- 對 column 可以加上 `NOT NULL` constraint 來表明不得為空

`REFERENCES`, `FOREIGN KEY`

- `REFERENCES` 用來表明一個 column 的值, 必須是已經存在於其他指定的 table column
- PostgreSQL 範例:
  - ```sql
      CREATE TABLE favorite_food (
        person_id SERIAL REFERENCES person (person_id),
        food VARCHAR(20),
        CONSTRAINT pk_favorite_food PRIMARY KEY (person_id, food)
      );
    ```
  - 即 product_no 這個欄位必須是存在 products table 中的 product_no column 裡的值
- 如同 `PRIMARY KEY` 與 `CONSTRAINT ... PRIMARY KEY` 的差異
  - `REFERENCES` 實現的也是 foreign key constraint 的功能, 但是無法指定 constraint 名稱 (implicitly)
- (explicit) 明確的表明 foreign key constraint 則是使用 `CONSTRAINT` `FOREIGN KEY` + `REFERENCES`
  - PostgreSQL 範例:
  - ```sql
      CREATE TABLE favorite_food (
        person_id SERIAL,
        food VARCHAR(20),
        CONSTRAINT pk_favorite_food PRIMARY KEY (person_id, food),
        CONSTRAINT fk_fav_food_person_id FOREIGN KEY (person_id) REFERENCES person (person_id)
      );
    ```

---

為資料表填入資料或更改資料表

- 練習 SQL 中的四種基本操作
  - `insert`, `update`, `delete`, `select`

不好的敘述寫法

Sakila 資料庫

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
