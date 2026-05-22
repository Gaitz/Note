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

---

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
  - 即 person_id 這個欄位必須是存在 person table 中的 person_id column 裡的值
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

`AUTO_INCREMENT`

- 數值型態的 primary key
- 取決於每個資料庫系統的實作, 因為這是 concurrent problem
- MySQL 中可以使用 `AUTO_INCREMENT` keyword 來指定欄位自動產生
  - 屬於 MySQL specific
- _補_, PostgreSQL
  - 自動增加的數值欄位
  - 舊版使用 `SMALLSERIAL`, `SERIAL`, `BIGSERIAL` 型別
    - 屬於 PostgreSQL specific
  - 在 PostgreSQL 10+ 以上的版本**推薦使用 Identity Column 的方式**
    - 屬於 SQL 標準
  - 尤其是數值是被用於 primary key 的情況下, 可以增加 constraint 來避免錯誤的手動寫入
  - PostgreSQL 範例:
    - ```sql
      id bigint GENERATED ALWAYS AS IDENTITY,
      id bigint GENERATED BY DEFAULT AS IDENTITY,
      ```
  - 兩者的差異在於 `BY DEFAULT` 基本上等同於 `SERIAL` 可以被手動給值
  - 而 `ALWAYS` 會在手動給值的情況下丟出錯誤, 除非加上特定的關鍵字才能執行 `OVERRIDING SYSTEM VALUE`

`ALTER TABLE`

- 使用語法修改 table 的定義
- MySQL 範例: `ALTER TABLE person MODIFY person_id SMALLINT UNSIGNED AUTO_INCREMENT;`
- _補_, PostgreSQL 也有相同的語法

`INSERT INTO` 添加資料

- MySQL 範例:
- ```sql
  INSERT INTO person (person_id, fname, lname, eye_color, birth_date)
  VALUES (null, 'William', 'Turner', 'BR', '1972-05-27');
  ```

`SELECT` 查詢資料

- `SELECT` 選擇要搜尋的 columns
- `FROM` table
- `WHERE` 增加搜尋條件
- MySQL 範例:
- ```sql
  SELECT person_id, fname, lname, birth_date
  FROM person
  WHERE lname = 'Turner';
  ```
- `ORDER BY` 針對搜尋結果進行排序
- MySQL 範例:
- ```sql
  SELECT food
  FROM favorite_food
  WHERE person_id = 1
  ORDER BY food;
  ```

輸出成 XML 格式, 輸出成 JSON 格式

- 個別的資料庫系統有不同的語法, 可以直接把 query 的結果以其他指定的格式呈現
- _補_,
  - PostgreSQL 中以特殊 function 的形式使用

`UPDATE` 更新資料

- 範例: `UPDATE products SET price = 10 WHERE price = 5;`
- 基本上與 SELECT 語法類似, 只是中間需要使用 `SET` 來更新

`DELETE` 刪除資料

- 範例: `DELETE FROM products WHERE price = 10;`
- 基本上與 SELECT 語法類似

---

常見錯誤

- 違反規則的 INSERT 會丟出錯誤訊息
- 違反 **primary key 欄位需要 unique**
- 違反 **foreign key 需要先存在另外的 table 中** (_補_, `REFERENCES`)
- 違反 ENUM 的輸入值
- 違反日期輸入格式

---

Sakila 資料庫

- MySQL 所提供的範例資料庫, 模擬 DVD 出租連鎖店的資料庫
- _補_, PostgreSQL 可以找到開源的移植版本, 以供練習

---

### 第三章 - 基礎查詢

---

查詢的機制

- 登入且資料庫連線
- 資料庫系統會指定一個識別碼給每一個連線
- MySQL, 會有 `MySQL connection id`
- _補_, PostgreSQL
  - `SELECT pg_backend_pid();` 取得連線使用的 pid
- 一個指令的執行資料庫系統需要確認
  - 1 是否有權限執行該指令
  - 2 是否有權限操作目標資料
  - 3 語法是否正確
- 合法的指令會被轉交給 query optimizer 來決定如何執行, 產生 execution plan
  - 資料庫使用者可以通過一些方式來影響 query optimizer 的選擇, 來為自己的使用情境做最佳化
  - 例如: 產生和檢索 execution plan, index 的使用, query hints, 調整資料庫的啟動參數, ...
- 資料庫查詢完成後會產生 result set 回傳給呼叫指令的連線介面
  - 由介面來決定如何顯示結果

查詢的子句

- 查詢敘述通常由多個 clauses 所組成, 但是並非每個都需要被使用
- `SELECT` 唯一必要的 clause
- `FROM`, 標明參與的資料表以及如何結合
- `WHERE`, 過濾不想要的資料
- `GROUP BY`, 按照共同欄位 (column) 來進行資料分組
- `HAVING`, 過濾掉不想要的群組 (group)
- `ORDER BY`, 依照一個或多個欄位 (columns) 來對 result set 進行排序

`SELECT` 子句

- SELECT 子句的任務是
  - 決定哪些候選欄位可以進入 result set
- 除了標明欄位以外, `SELECT` 還能接受
  - 1 literal value, 例如: 數值, 字串
  - 2 expression (運算),
  - 3 呼叫內建函式,
  - 4 呼叫使用者自訂函式
- `*`,
  - `SELECT * FROM language;` 顯示 language 資料表中所有的欄位
- 指定特定欄位
  - `SELECT language_id, name, last_update FROM language;`
- ```sql
  SELECT language_id,
    'COMMON' language_usgage,
    language_id * 3.1415927 lang_pi_value,
    UPPER(name) language_name
  FROM language;
  ```
- SELECT 內建函式
  - MySQL, `SELECT version(), user(), database();`
  - _補_, 內建函式屬於資料庫系統專屬, 因此不一定是通用函式, 每家資料庫系統擁有自己不同的內建函式庫

欄位的別名

- 為輸出結果欄位, 進行重新命名 (別名)
- 可以直接加在欄位敘述後面後面指定,
- 或者使用 `AS` 關鍵字 (選用)
- `SELECT language_id id FROM language;`
- `SELECT language_id AS id FROM language;`
- 以上兩個敘述功能是一樣的, 屬於程式碼風格的選用

消除重複的內容

- `DISTINCT`
  - `SELECT DISTINCT actor_id FROM film_actor;`
- 如果單純要確認資料是否重複時, 使用 `DISTINCT` 是**很花時間的運算**
  - 要產生一組 unique 的結果集合來確認重複性, 需要先排序 order by 和 distinct 因此在資料量很大的時候是**很花時間的運算**
- **應該要花時間了解要處理的資料集合, 本身是否存在重複的可能性**

`FROM` 子句

- `FROM` 子句定義了, 查詢會用到的資料表, 以及如何將資料表連結在一起的方式

資料表

- 一組彼此相關的資料表
- 可以分成四種形態
  - 永久性資料表 (以 `CREATE TABLE` 建立的)
  - 導出的資料表 (通過子查詢回傳並儲存在記憶體中的資料)
  - 臨時資料表 (儲存在記憶體中的資料 (volatile))
  - 虛擬資料表 (以 `CREATE VIEW` 建立的)
- 以上四種資料表都可以用在 `FROM` 子句中

導出的 (從子查詢產生) 的資料表

- 在 `FROM` 子句下, 以小括號 `()` 建立起的子查詢
  - 子查詢會產生一個導出的資料表, 給予其他子句進行使用
- 這樣的**子查詢產生的資料表只存在於查詢期間, 之後就會被棄置**
- ```sql
  SELECT concat(cust.last_name, ', ', cust.first_name) full_name
  FROM (
    SELECT first_name, last_name, email
    FROM customer
    WHERE first_name = 'JESSIE'
  ) cust;
  ```
- 外圍的查詢 (containing query)
- 以別名來參照子查詢的結果

臨時資料表 (`TEMPORARY`)

- `TEMPORARY`
- 每個資料庫系統實作的方式不同, 但是都允許定義臨時性的資料表,
  - 使用上幾乎等同於永久性資料表,
  - 唯一的差異在於資料會在某個時刻消失, 被釋放
  - 例如: transaction 結束時, 資料庫 connection 結束時
  - Oracle Database 的處理則較為特殊, 會保留臨時資料表的定義, 供未來使用
- ```sql
  CREATE TEMPORARY TABLE actors_j (
    actor_id SMALLINT,
    first_name varchar(45),
    last_name varchar(45)
  );
  ```
- ```sql
  INSERT INTO actors_j
    SELECT actor_id, first_name, last_name
    FROM actor
    WHERE last_name LIKE 'J%';
  ```

檢視表 (`VIEW`)

- 外觀與行為都與資料表 (`TABLE`) 類似, 但是沒有實際的資料
- 而是一種 `SELECT` 的封裝
- 當操作 VIEW 時, 資料庫系統會自動整合語法與 VIEW 定義, 來形成最終的指令
- 主要的用途在於
  - 1 對資料庫使用者隱藏部分的欄位 (_補_, 權限管理)
  - 2 簡化複雜的資料表設計, (_補_, 依據使用情境建立, 而不需要修改實際的 table)
- ```sql
  CREATE VIEW cust_vw AS
  SELECT customer_id, first_name, last_name, active
  FROM customer;
  ```

資料表的連結 `JOIN`, `ON`

- 在 `FROM` 子句中描述, 數個資料表之間的連結方式
- 以下示範 `INNER JOIN`, 條件則是在 `ON` 子句下描述
- ```sql
  SELECT customer.first_name, customer.last_name,
    rental.rental_date rental_time
  FROM customer
    INNER JOIN rental
    ON customer.customer_id = rental.customer_id
  WHERE date(rental.rental_date) = '2005-06-14';
  ```

定義資料表的別名

- 當要在不同子句中參照不同的資料表欄位時, 必須要有個方式描述這個欄位來自於哪個資料表
- 使用全名, 資料表名稱 (table) `.` 欄位名稱 (column), 範例: `employee.emp_id`
- 使用別名, 為資料表命名一個別名 (alias), 然後參照欄位
- 使用別名的目的是**要更簡潔並且不容易造成混淆**
- ```sql
  SELECT c.first_name, c.last_name, r.rental_date rental_time
  FROM customer c
    INNER JOIN rental r
    ON c.customer_id = r.customer_id
  WHERE date(r.rental_date) = '2005-06-14';
  ```

`WHERE` 子句

- `WHERE` 子句, 一種將沒有興趣的 row 從 result set 中剔除的手段
  - _補_, 用來篩選有興趣的資料
- ```sql
  SELECT title
  FROM film
  WHERE (rating = 'G' AND rental_duration >= 7)
    OR (rating = 'PG-13' AND rental_duration < 4);
  ```
- 使用 `AND`, `OR`, `NOT` 邏輯算子 (Logical Operators) 來組合條件
- 使用 `()` 來指定運算順序

`GROUP BY` 和 `HAVING` 子句

- 讓資料庫系統針對 result set 進行某些操作後再顯示
- `GROUP BY` 根據欄位的值 (column) 進行分組 (grouping)
- `HAVING` 子句,
  - 當使用 `GROUP BY` 之後, 可以通過 `HAVING` 對分組進行篩選
  - 類似於作用於 GROUP 的 WHERE 子句
- ```sql
  SELECT c.first_name, c.last_name, count(*)
  FROM customer c
    INNER JOIN rental r
    ON c.customer_id = r.customer_id
  GROUP BY c.first_name, c.last_name
  HAVING count(*) >= 40;
  ```

`ORDER BY` 子句

- 一般的 result set 結果並不保證任何順序
- 要讓結果是以有序的方式排列, 需要使用 `ORDER BY` 子句
- `ORDER BY`
  - 讓結果集合進行排序, 可以通過欄位 (column), 或者欄位相關的表示式 (expressions)
- PostgreSQL example:
- ```sql
  SELECT c.first_name, c.last_name,
    r.rental_date::time rental_time
  FROM customer c
    INNER JOIN rental r
    ON c.customer_id = r.customer_id
  WHERE date(r.rental_date) = '2005-06-14'
  ORDER BY c.last_name, c.first_name;
  ```

降幂與升幂的排序, `ASC`, `DESC`, `LIMIT`

- `ASC`, 排序的預設是升幂的 (ascending)
- `DESC`, 使用關鍵字指定為降幂 (descending)
- `LIMIT`, 指定只顯示前幾筆數量
- PostgreSQL example:
- ```sql
  SELECT c.first_name, c.last_name, r.rental_date::time rental_time
  FROM customer c
    INNER JOIN rental r
    ON c.customer_id = r.customer_id
  WHERE date(r.rental_date) = '2005-06-14'
  ORDER BY r.rental_date::time DESC
  LIMIT 10;
  ```

以欄位的數字定位來指定排序

- 以欄位的排序數字, 來指定排序欄位
- ```sql
  SELECT c.first_name, c.last_name, r.rental_date::time rental_time
  FROM customer c
    INNER JOIN rental r
    ON c.customer_id = r.customer_id
  WHERE date(r.rental_date) = '2005-06-14'
  ORDER BY 3 DESC;
  ```
- _補_, 不推薦使用, 因為容易出錯

---

### 第四章 - 篩選

---

- `WHERE` 子句, 針對 rows 進行篩選
- `FILTER` conditions
- `HAVING` 子句, 針對 groupoing 進行篩選

條件評估

- conditions
- 以 `AND`, `OR` 區隔

小括號的運用

- 在複雜的條件中, 最好使用 `()` 來明確的表示優先順序
- 有助於可閱讀性, 和資料庫系統的解析

`NOT` 算子的使用

- `NOT` 算子
- ```sql
  WHERE NOT (first_name = 'STEVEN' OR last_name = 'YOUNG')
    AND create_date > '2006-01-01'
  ```
- 等價的 `<>` 算子與 `!=` 算子
- ```sql
    WHERE first_name <> 'STEVEN' AND last_name <> 'YOUNG'
      AND create_date > '2006-01-01'
  ```

建構條件

- conditions 由 expressions, 加上 operators 組成
- Expression 可以是
  - 一個數值 (value)
  - 一個欄位 (column)
  - 一個字串 (string)
  - 一個內建函式, Example: `concat()`
  - 一個子查詢 sub-query
  - 一連串的表示式, Example: `('Boston', 'New York', 'Chicago')`
- Operators
  - 比較算子 (Comparison Functions and Operators)
  - 算數算子 (Mathematical Functions and Operators)
  - _補_ ,邏輯算子 (Logical Operators)
  - _補_, ...

條件的類型

等式條件 (equality conditions)

- 大部分會寫成 `column = experssion` 的形式
- 範例:
- ```sql
  SELECT c.email
  FROM customer c
    INNER JOIN rental r
    ON c.customer_id = r.customer_id
  WHERE date(r.rental_date) = '2005-06-14';
  ```

不等式條件 (inequality condition)

- `<>` 算子與 `!=` 算子, 兩者是等價的
- 範例:
- ```sql
  SELECT c.email
  FROM customer c
    INNER JOIN rental r
    ON c.customer_id = r.customer_id
  WHERE date(r.rental_date) <> '2005-06-14';
  ```

利用等式條件來修改資料

- 等式與不等式條件常用於 `UPDATE` 與 `DELETE` 中

以範圍構成的條件

- 以範圍來操作數值, 時序資料, ...
- 比較算子 (Comparison Functions and Operators)
  - `<`, `>`, `<=` `>=`, `=`, `<>`, `!=`
- 範例:
- ```sql
  SELECT customer_id, rental_date
  FROM rental
  WHERE rental_date < '2005-05-25';
  ```

`BETWEEN AND` 算子

- 使用 `BETWEEN` 算子來同時設定上下界
  - 這個算子, 只是 `<=`, `>=` 的語法糖
  - `a BETWEEN x AND y` 等價於 `a >= x AND a <= y`
- 輸入值的順序, 必須是下界限, 然後上界限
- 並且上下界都會**被包含在範圍之內**, _補_, 意味著 `=`
- 範例:
- ```sql
  SELECT customer_id, rental_date
  FROM rental
  WHERE rental_date BETWEEN '2005-06-14' AND '2005-06-16';
  ```

字串的範圍

- `BETWEEN AND` 與比較算子都適用於字串
  - 依據其字元順序
- 範例:
- ```sql
  SELECT last_name, first_name
  FROM customer
  WHERE last_name BETWEEN 'FA' AND 'FR';
  ```

依成員構成的條件, `IN`, `()`

- 使用 `IN` 算子, 作用於候選集合上
- 範例:
- ```sql
  SELECT title, rating
  FROM film
  WHERE rating IN ('G', 'PG');
  ```
- _補_, PostgreSQL, Row and Array Comparisons

子查詢的使用

- 使用 `IN` 算子加上 `()` subquery
  - 讓 `IN` 算子作用於透過子查詢產生的結果集合上
- 範例:
- ```sql
  SELECT title, rating
  FROM film
  WHERE rating IN (
    SELECT rating FROM film
    WHERE title LIKE '%PET%'
  );
  ```
- _補_, PostgreSQL, Subquery Expressions

`NOT IN` 的使用

- `NOT IN`
- 不存在集合中

比對符合條件

- 處理字串條件的方法
- 1 使用內建字串函式配合比較算子
- 範例:
- ```sql
  SELECT last_name, first_name
  FROM customer
  WHERE left(last_name, 1) = 'Q';
  ```
- _補_, PostgreSQL, String Functions and Operators

利用萬用字元 `LIKE`

- 使用萬用字元建立比對 pattern
- `-`, 取代單一字元
- `%`, 取代任意數量的字元
- 配合 `LIKE` 算子進行比對
- 範例:
- ```sql
  SELECT last_name, first_name
  FROM customer
  WHERE last_name LIKE '_A_T%S';
  ```

利用正規表示式, regular expressions

- 對於更複雜的字串比對, 可以使用內建的 regular expression
- 幾乎每個資料庫系統都支援 regular expressions
  - 但是**每個資料庫系統的使用語法不同**, 需要個別確認
- MySQL 範例:
- ```sql
  SELECT last_name, first_name
  FROM customer
  WHERE last_name REGEXP '^[QY]';
  ```
- PostgreSQL 範例:
- ```sql
  SELECT last_name, first_name
  FROM customer
  WHERE last_name ~ '^[QY]';
  ```
- _補_, PostgreSQL, Pattern Matching

`NULL` 那四個字的咒語

- `NULL` 值的多重含義
  - 1 不適用此欄位
  - 2 資料值還未知
  - 3 資料值還未定義
- 在資料庫系統中的 `NULL` 值的特殊性質
  - 1 expression 可以為 `NULL`, 但是不等於 NULL
  - 2 **兩個 NULL 值是不相等的**
- 要判斷 NULL 值**必須使用**
  - `IS NULL` 算子
  - `IS NOT NULL` 算子
  - 而**不能使用比較算子**, `=`, `!=`
- 範例:
- ```sql
  SELECT rental_id, customer_id
  FROM rental
  WHERE return_date IS NULL;
  ```
- 常見錯誤
  - 使用比較算子來判斷 NULL 值
    - 必須使用 `IS NULL`, 與 `IS NOT NULL` 算子進行
- 常見錯誤
  - **使用 `NOT BETWEEN` 算子時的結果並不會包含 `NULL`**
    - 如果需要 `NULL` 值, 必須手動加上條件 `IS NULL`

---

### 第五章 - 查詢多個資料表

---

什麼是結合 (JOIN)

- 組合資料表
- 當查詢涉及多個資料表時
  - 通過欄位中的 foreign key 來連結其他的資料表
- foreign key 是選擇性使用 constraint
  - 使用 join 時並不需要一定要有 foreign key constraint

笛卡爾乘積 (Cartesian product)

- Cartesian product, 所有資料表的欄位進行排列組合形成的乘積
  - 也是 CROSS JOIN 的結果
- _補_, Cross join 不需要有 `ON` 進行連接, 只是資料表單純地進行 Cartesian product 的結果
- MySQL 範例:
- ```sql
  SELECT c.first_name, c.last_name, a.address
  FROM customer c JOIN address a;
  ```
- _補_, PostgreSQL 範例:
- ```sql
  SELECT c.first_name, c.last_name, a.address
  FROM customer c CROSS JOIN address a;
  ```
- PostgreSQL 需要明確表明 `CROSS JOIN`

Inner Joins

- 使用 `ON` keyword 描述, `JOIN` 時所對應的欄位名稱
  - INNER JOIN, 最常見的 JOIN 方式, 也是 `JOIN` 的預設模式
  - 使用 `INNER JOIN` keyword 可以明確表明使用的 JOIN 類型
- INNER JOIN 在兩個對應欄位如果遇到 NULL 或找不到時, 其結果不會出現在結果集合中
  - 與之相對的是如果在其一欄位找不到時, 仍輸出結果, 就需要使用 OUTER JOIN
- MySQL 範例:
- ```sql
  SELECT c.first_name, c.last_name, a.address
  FROM customer c JOIN address a
  ON c.address_id = a.address_id;
  ```
- _補_, PostgreSQL 語法相同

- 當 `ON` 所連結的 key 在兩個欄位中擁有相同名稱時, 可以使用 `USING` keyword 取代
  - 範例如下:
  - ```sql
      SELECT c.first_name, c.last_name, a.address
      FROM customer c JOIN address a
      USING (address_id);
    ```
- `USING` 屬於特定情況下的語法糖, 取決於程式風格使用

ANSI 的 Join 語法

- 採用 ANSI SQL 標準, SQL 92 版本
- 所有的主流資料庫系統都支援 SQL92 標準版的語法
- 但是在此之前仍有舊版的語法使用
  - 範例:
  - ```sql
      SELECT c.first_name, c.last_name, a.address
      FROM customer c, address a
      WHERE c.address_id = a.address_id;
    ```
- 使用 SQL92 標準版的好處
  - 可閱讀性更高
  - 不容易出錯
  - 各家資料庫通用

結合三個以上的資料表

- 一次結合兩個資料表
- 結合三個資料表的範例:
- ```sql
  SELECT c.first_name, c.last_name, ct.city
  FROM customer c
    INNER JOIN address a
    ON c.address_id = a.address_id
    INNER JOIN city ct
    ON a.city_id = ct.city_id
  ORDER BY ct.city;
  ```

結合的順序重要嗎?

- 因為資料庫系統 SQL 語法是非程序式語言 (Non-procedural Language)
- 換句話說, JOIN 的語法順序不會影響執行順序, 執行順序是由資料庫系統本身決定的
- 如果要刻意影響資料庫的 JOIN 順序時, 就需要依據不同的資料庫系統使用不同的語法來影響最佳化的選擇
  - MySQL: `STRAIGHT_JOIN`
  - SQL Server: `force order`
  - Oracle: `ordered`, `leading`

將子查詢當成資料表來使用

- 把子查詢的結果作為一個 table 來參與 JOIN
- 使用時機取決於效能最佳化或者程式可閲讀性, 而使用子查詢
- 範例:
- ```sql
  SELECT c.first_name, c.last_name, addr.address, addr.city
  FROM customer c
    INNER JOIN (
      SELECT a.address_id, a.address, ct.city
      FROM address a
        INNER JOIN city ct
        ON a.city_id = ct.city_id
      WHERE a.district = 'California'
    ) addr
    ON c.address_id = addr.address_id;
  ```

重復使用同一個資料表

- 在進行資料表結合時, 有時候會需要建立重複的組合,
  - 因此會重復使用到相同的一個資料表, 但是以不同的別名進行操作
- 範例: 尋找兩位演員所共演的所有電影的電影名稱
- ```sql
  SELECT f.title
  FROM film f
    INNER JOIN film_actor fa1
    ON f.film_id = fa1.film_id
    INNER JOIN actor a1
    ON fa1.actor_id = a1.actor_id
    INNER JOIN film_actor fa2
    ON f.film_id = fa2.film_id
    INNER JOIN actor a2
    ON fa2.actor_id = a2.actor_id
  WHERE (a1.first_name = 'CATE' AND a1.last_name = 'MCQUEEN')
    AND (a2.first_name = 'CUBA' AND a2.last_name = 'BIRCH');
  ```

自我結合 (self-join)

- 有些資料表中會有包含自我參照的外來鍵 (self-referencing foreign key)
  - 有一個欄位指向自己的 primary key
- 範例: 在 film table 中擁有一個欄位叫做 prequel_film_id 作為指向續集
  - 此時可以使用 self join 尋找擁有續集的所有電影
- ```sql
  SELECT f.title, f_prnt.title prequel
  FROM film f
    INNER JOIN film f_prnt
    ON f_prnt.film_id = f.prequel_film_id
  WHERE f.prequel_film_id IS NOT NULL;
  ```

---

### 第六章 - 集合的運用

---

- 以集合的角度看待資料

集合的理論基礎

- union (聯集)
- intersection (交集)
- except (差集)
- (A union B) except (A intersect B)
  - (A except B) union (B except A)
  - _補_, symmetric difference

現實中的集合理論

- 在資料庫中的運用
  - 兩組資料集合必須有相同的欄位數量
  - 對應的資料欄位型別需要一致, 或者有辦法型別轉換
- 運用集合算子在兩個 SELECT 敘述中
- 範例:
- ```sql
  SELECT 1 num, 'abc' str
  UNION
  SELECT 9 num, 'xyz' str;
  ```
- 組合式查詢 (compound query)
  - 以集合算子組合多組單獨執行查詢的查詢結果, 形成最終的查詢結果集合
  - _補_, PostgreSQL, Combining Queries (UNION, INTERSECT, EXCEPT)

集合運算子

- 額外選用的 `ALL` keyword
  - **不排除重複的值**
- **預設是會排除重複的值**, _補_, 概念上等同於在最終的結果集合上加上 `DISTINCT` 運算

`UNION`, `UNION ALL` 運算子

- 範例: 尋找所有在 customer 與 actor 清單中姓名指定開頭的集合
- `UNION ALL` 範例:
- ```sql
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE c.first_name LIKE 'J%' AND c.last_name LIKE 'D%'
  UNION ALL
  SELECT a.first_name, a.last_name
  FROM actor a
  WHERE a.first_name LIKE 'J%' AND a.last_name LIKE 'D%';
  ```
- `UNION` 範例:
- ```sql
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE c.first_name LIKE 'J%' AND c.last_name LIKE 'D%'
  UNION
  SELECT a.first_name, a.last_name
  FROM actor a
  WHERE a.first_name LIKE 'J%' AND a.last_name LIKE 'D%';
  ```
- 差異在於是否消除重複的資料

`INTERSECT`, `INTERSECT ALL` 運算子

- `INTERSECT` 範例
  - 尋找中 customer 與 actor 符合條件且同名同姓的人
- ```sql
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE c.first_name LIKE 'J%' AND c.last_name LIKE 'D%'
  INTERSECT
  SELECT a.first_name, a.last_name
  FROM actor a
  WHERE a.first_name LIKE 'J%' AND a.last_name LIKE 'D%';
  ```

`EXCEPT`, `EXCEPT ALL` 運算子

- `EXCEPT` 範例
  - 尋找 actor 中符合條件的姓名, 但是剔除 customer 中相同條件的姓名
- ```sql
  SELECT a.first_name, a.last_name
  FROM actor a
  WHERE a.first_name LIKE 'J%' AND a.last_name LIKE 'D%'
  EXCEPT
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE c.first_name LIKE 'J%' AND c.last_name LIKE 'D%';
  ```
- A `EXCEPT ALL` B
  - 只會把出現在 B 集合的重複資料從 A 集合中移除一次
  - 意味著 A 集合可能會存在多餘重複數量的相同資料

集合運算子的規則

將組合式查詢的結果排序

- 在對組合式查詢結果使用 `ORDER BY` 時的欄位名稱需要使用第一組查詢的欄位名稱
- 因此推薦在使用組合式查詢時, 兩個查詢都使用相同的輸出欄位名稱 (使用別名產生一致)
- 可以正確執行的範例: 使用第一組結果的欄位名稱進行排序
- ```sql
  SELECT a.first_name fname, a.last_name lname
  FROM actor a
  WHERE a.first_name LIKE 'J%' AND a.last_name LIKE 'D%'
  UNION ALL
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE c.first_name LIKE 'J%' AND c.last_name LIKE 'D%'
  ORDER BY lname, fname;
  ```
- 會出現錯誤的範例: 使用第二組結果的欄位名稱進行排序
- ```sql
  SELECT a.first_name fname, a.last_name lname
  FROM actor a
  WHERE a.first_name LIKE 'J%' AND a.last_name LIKE 'D%'
  UNION ALL
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE c.first_name LIKE 'J%' AND c.last_name LIKE 'D%'
  ORDER BY last_name, first_name;
  ```

集合運算子的優先性

- 作用於多組集合運算子的優先順序
  - 一般而言是由上而下的順序
  - `INTERSECT` 運算子的順序優於其他算子
  - 可以使用 `()` 改變執行的優先順序
- 範例:
- ```sql
  SELECT a.first_name, a.last_name
  FROM actor a
  WHERE a.first_name LIKE 'J%' AND a.last_name LIKE 'D%'
  UNION (
    SELECT a.first_name fname, a.last_name lname
    FROM actor a
    WHERE a.first_name LIKE 'M%' AND a.last_name LIKE 'T%'
    UNION ALL
    SELECT c.first_name, c.last_name
    FROM customer c
    WHERE c.first_name LIKE 'J%' AND c.last_name LIKE 'D%'
  );
  ```

---

### 第七章 - 資料的產生, 操作與轉換

---

- 關於資料的操作, 各家資料庫系統有屬於自己不同的內建函數
- 資料型別與其容量上限與細節, 在各家資料庫系統也有所不同
- 實際情況應該參照所使用的資料庫系統的文件說明

處理字串資料

- 資料型別與其容量限制
  - 資料型別分成 SQL 標準 + 各家資料庫擴充的
- 主要分為固定長度, 不固定長度但有上限, 不固定長度並且無上限

產生字串

- 面對超過字串容量上限的操作, 各家資料庫系統有不同的應對行為
  - 主要分成兩種應對方式, 1 丟出錯誤, 2 截斷

包含單引號

- 字串以 `'` 單引號包裹
- 遇到字串中需要包含單引號時, 需要使用跳脫字元 (escape)
- 預設的跳脫 `'` 單引好的方式是, 重複兩次 `''`
  - 範例: `'it''s'`
- _補_, PostgreSQL 中,
  - 1 除了使用 `''` 來跳脫單引號, `'it''s'`
  - 2 可以使用 escape string, 以 `\` 來跳脫單引號, 範例: `E'it\'s'`
  - 3 可以使用 dollar-quoted string, 以 `$$` 作為 string quoting, 範例: `$$it's$$`
- _補_, 處理字串
  - Input: 需要思考輸入的字串, 是否需要跳脫, 以及如何處理
  - Input: 如何應對 SQL injection
  - Output: 輸出的格式是否包含跳脫字元

包含特殊字元

- 串聯字串 `||` 或者其他各自資料庫專屬的語法
- 當遇到特殊字元與超過 ASCII 的字元集時, 需要考量所選定的資料庫字串編碼方式, 例如: `UTF-8`
- 與各家資料庫所提供的字串相關函式

字串的操作

- 字串操作的函式, 在每個資料庫系統中都不太一樣, 需要參照自己所使用的資料庫系統文件

會回傳數字的字串函式

- 取得字元數量的函式
  - MySQL: `length()`
  - SQL server: `len()`
  - _補_, PostgreSQL: `char_length ( text ) → integer`
- 取得子字串的位置
  - MySQL: `position()`
  - _補_, PostgreSQL: `position ( substring text IN string text ) → integer`
  - **!! 字串位置是以 1 為起始, 而非 0 !!**, 回傳 0 代表沒有找到
- 書中還提到其他幾個 MySQL 的字串函式
  - `locate()`
  - `strcmp()`
- 使用 `LIKE`, regexp 來運算判斷
  - MySQL 中回傳值為 `1` 代表 true, `0` 代表 false
  - _補_, PostgreSQL: 範例：
  - PostgreSQL 回傳值使用 `t` 與 `f`
  - ```sql
    SELECT title, title LIKE '%R'
    FROM film
    LIMIT 5;
    ```
  - ```sql
    SELECT title, REGEXP_LIKE (title, 'R$')
    FROM film
    LIMIT 5;
    ```

會回傳字串的字串函式

- 連結字串
  - MySQL: `concat()`
  - _補_, PostgreSQL
    - `text || text → text`
    - `concat ( val1 "any" [, val2 "any" [, ...] ] ) → text`
    - `concat_ws ( sep text, val1 "any" [, val2 "any" [, ...] ] ) → text`
- 插入字串
  - MySQL: `insert()`
  - Oracle Database: `replace()`
  - SQL server: `replace()`, `stuff()`
  - _補_, PostgreSQL
    - `regexp_replace()`, `format()`, ...
- 取出子字串
  - MySQL: `SUBSTRING()`
  - _補_, PostgreSQL
    - `substr()`, `regexp_substr()`, `substring()`

處理數值資料

- 算術算子, Mathematical Operators
  - `+`, `-`, `*`, `/`, ...

執行算術函式, Mathematical Functions

- _補_, 參考各家資料庫文件

控制數值的精度

- 控制進位與捨去小數點
- MySQL:
  - `ceil()` 下一個較大的整數,
  - `floor()` 下一個較小的整數,
  - `round()` 四捨五入,
  - `truncate()` 無條件捨去
- _補_, PostgreSQL
  - `floor()`
  - `ceil()`, `ceiling()`
  - `round ( numeric ) → numeric`, `round ( v numeric, s integer ) → numeric`
  - `trunc ( numeric ) → numeric`, `trunc ( v numeric, s integer ) → numeric`

處理有號資料

- 處理正負號
- MySQL:
  - `sign()`, 回傳正負號
  - `abs()`, 回傳絕對值
- _補_, PostgreSQL
  - `sign ( numeric ) → numeric`
  - `abs ( numeric_type ) → numeric_type`

處理時序資料

- 處理時序資料最麻煩的地方在於有很多不同的描述方式

處理時區

- 時區 (time zones), 和日光節約時間 (daylight saving time) 的採用與否
- 早期採用的標準是格林威治標準時間 (Greenwich Mean Time), GMT
  - 其他時區採用與 GMT 所相差的小時數來表示, 例如: GMT -5:00, 美東時間比格林威治早 5 小時
- 現在採用的是世界協調時間 (Coordinated Universal Time), UTC
  - 以世界各地的原子鐘, 產生的世界時間 (Universal Time), 並且盡可能對齊 GMT 規則
  - 多數時候可以與 GMT 互換
- MySQL: `utc_timestamp()`, 取得當下的 UTC timestamp
  - SQL server: `getutcdate()`
  - _補_, PostgreSQL: `current_timestamp`
- 一般資料庫系統的預設時區是伺服器所在的時區
- 可以手動變更時區設定, MySQL: `SET time_zone`
  - Oracle Database: `ALTER SESSION TIMEZONE`
- _補_, PostgreSQL
  - `SHOW TIMEZONE;`
  - 修改 time zone 設定可以分成不同的層級 (系統, 個別資料庫, 個別使用者, 個別 session), 並區分暫時性或永久性
  - 修改當下 session, `SET TIME ZONE 'value'` is an alias for `SET timezone TO 'value'`

產生時序資料

- 產生時序資料
  - 從現有的時序欄位複製
  - 執行內建函數產生時序資料
  - 使用字串型別讓資料庫進行轉換成時序資料

時序資料的字串呈現方式

- 處理字串時序資料的格式
  - 型別與預設格式
  - date: YYYY-MM-DD
  - datetime: YYYY-MM-DD HH:MI:SS
  - timestamp: YYYY-MM-DD HH:MI:SS
  - time: HHH:MI:SS
  - _補_, 查詢使用的資料庫系統文件, 來確認格式
- 範例: 當傳入字串型別運作於時序型別欄位時, 資料庫會嘗試進行解析並且轉換型別
- ```sql
  UPDATE rental
  SET return_date = '2019-09-17 15:30:00'
  WHERE rental_id = 99999;
  ```

從字串轉換到日期

- 當資料庫沒有預期要進行自行轉換時, 可以使用關鍵字進行型別轉換
- MySQL: `CAST()`
  - 範例: `SELECT CAST('2019-09-17 15:30:00' AS DATETIME);`
- _補_, PostgreSQL,
  - PostgreSQL 中也有 `CAST (source_type AS target_type)`
  - 但是 PostgreSQL 中剛好沒有 DATETIME 這個型別
  - 因此如果要實現等同於上面範例的做法是 `SELECT CAST('2019-09-17 15:30:00' AS TIMESTAMP);`

產生日期的函式

- 使用不符合預期格式的字串型別的轉換型別
- 可以指定格式協助資料庫解析
- MySQL: `STR_TO_DATE()`, 使用類似 C 語言的方式, 以 `%M`, `%m`, `%d`, ... 的方式指定格式
  - Oracle Database: `to_date()`
  - SQL Server: `convert()`
  - _補_ PostgreSQL: Data Type Formatting Functions
    - `to_date ( text, text ) → date`,
    - `to_timestamp ( text, text ) → timestamp with time zone`
- 以函式生成當下的時間型別
  - MySQL: `CURRENT_DATE()`, `CURRENT_TIME()`, `CURRENT_TIMESTAMP()`
  - Oracle Database: `current_date()`, `current_timestamp()`
  - SQL Server: `current_timestamp()`
  - _補_ PostgreSQL:
    - `current_date`, `current_time`, `current_timestamp`, `now()`, ...

操作時序資料

- 操作時序資料的內建函式
- 參考各家資料庫系統文件, 語法都各有差異
  - 就算名稱相同, 細節與參數可能不同

會回傳日期的時序函式

- 日期的運算函式
  - MySQL: `date_add()`
  - MySQL: `INTERVAL` 指定參數的型別
  - SQL Server: `DATEADD()`
  - Oracle Database: `ADD_MONTHS()`
- _補_, PostgreSQL
  - `+`, `-`, `*`, `/` 算子可以運用在時間上
  - 也有 `date_add()`, ...
- 找到區間內的最後一天, 特別常用於月份, 尤其是處理 2 月時
  - MySQL: `last_day()`
  - Oracle Database: `last_day()`
  - SQL Server 沒有提供
- _補_, PostgreSQL
  - PostgreSQL 中沒有提供 last_day 函式
  - 但是可以使用 `date_trunc()` 與 `INTERVAL` 實現類似功能
  - `SELECT (DATE_TRUNC('MONTH', input_date) + INTERVAL '1 MONTH - 1 DAY')::DATE;`

會回傳字串的時序函式

- 解析時序資料產生時間或日期的部分資訊
- MySQL: `dayname()` 回傳星期幾的字串
- `extract()` 屬於 SQL 標準,
  - 建議使用這個更為通用的語法, 幾乎所有資料庫系統都有實作
  - SQL Server, 使用 `datepart()`
- _補_, PostgreSQL, 9.9.1. EXTRACT, date_part
  - `date_part` 取得數值
  - `date_subtract` 取得 timestamp
  - `extract` 取得數值

會回傳數字的時序函式

- MySQL: `DATEDIFF()` 計算出兩個時間之間的區間值
- SQL Server: `DATEDIFF()`
- Oracle Database: 支援 `-` 時間減法
- _補_, PostgreSQL
  - 支援時間運算子, `+`, `-`, `*`, `/`

轉換用的函式

- 每個資料庫系統都有各自用來轉換型別的函式
  - 但是推薦使用 SQL 標準的 `CAST()` 函式
  - 幾乎所有的資料庫系統都有實作
- `CAST (source_type AS target_type)`, 使用 `CAST` 與 `AS` keywords
- MySQL 應對字串轉譯成數字時,
  - `CAST('999ABC111' AS INTEGER);` 會跳出 warning 但是繼續執行而非丟出 error
  - _補_, PostgreSQL 同等的指令會丟出 ERROR
- CAST 字串轉譯成時序資料時, 字串需符合時序資料的預設模式, 無法使用客製化的格式
  - 需要轉譯客製化的格式時, 還是需要參照各家資料庫系統所提供的專屬函式

---

### 第八章 - 分組與彙整

---

- 不只是使用資料庫原始資料, 而是通過資料庫整理的資料

分組的概念

- `GROUP BY`, 指定用於整合的欄位
- `COUNT()`, aggregate function
  - `*` 意味著使用所有集合中的資料
- `HAVING`, 作用於 GROUP 的 WHERE 語法,
  - 因為 WHERE 語法作用於 GROUP BY 之前, 因此無法以 WHERE 語法進行篩選 GROUP 後的資料
- 範例:
- ```sql
  SELECT customer_id, COUNT(*)
  FROM rental
  GROUP BY customer_id
  HAVING COUNT(*) >= 40
  ORDER BY COUNT DESC;
  ```

彙整函式

- Aggregate function 針對一個分組中的資料進行特定操作
- 每個資料庫系統有不同專屬的 aggregation function
- 主流資料庫系統都有實作的通用函式為
  - `MAX()`, 回傳集合中的最大值
  - `MIN()`, 回傳集合中的最小值
  - `AVG()`, 回傳集合中的平均值
  - `SUM()`, 回傳集合中的資料總和
  - `COUNT()`, 回傳集合中的資料數
- 範例: 沒有 GROUP BY 但是可以直接使用 aggregation function
  - 這時候作用的群組是 implicit group, 意味著 payment 裡所有的 rows 都屬於一個集合中
  - 因此此時的 aggregation function 作用於所有的 rows
- ```sql
  SELECT MAX(amount), MIN(amount), AVG(amount), SUM(amount), COUNT(*) FROM payment;
  ```

隱性與顯性的分組

- implicit group, 即資料表中所有的 rows 都屬於同一個 group
- explicit group, 即使用 `GROUP BY` 指定分組的方式

計算個別不同的值

- 使用 `COUNT()` 時, 可以配合 `DISTINCT` 針對不同的值進行計算數量,
  - 原本使用 `COUNT(*)` 則是集合中所有值的總數
- 範例: 使用隱性 group 進行, 針對 customer_id 欄位計算數量時, 使用 `DISTINCT` 所產生的效果
- ```sql
  SELECT COUNT(customer_id) num_rows, COUNT(DISTINCT customer_id) num_customers FROM payment;
  ```

利用表示式

- 在 aggregation function 中使用表示式
- MySQL 範例: 計算出起租日到歸還日間隔最長的紀錄
- ```sql
  SELECT MAX(datediff(return_date, rental_date))
  FROM rental;
  ```
- _補_: PostgreSQL 範例
  - `SELECT MAX(return_date - rental_date) FROM rental;`

Nulls 的處理方式

- 進行任何數值計算時, 都應該考慮到 Null 值的處理
- 每個 aggregation function 是否會自動忽略 Null 需要參考文件
- 範例: 此 table 中含有 Null 值
- ```sql
  SELECT COUNT(*) num_rows,
    COUNT(val) num_vals,
    SUM(val) total,
    MAX(val) max_val,
    AVG(val) avg_val
  FROM number_tbl;
  ```
- 此時的輸出, `SUM(val)`, `MAX(val)`, `AVG(val)`, 與 `COUNT(val)` 都會自動略過 Null
  - 而 `COUNT(*)` 會計算 Null 值

產生分組

- 很多時候從事資料分析的人都會將原始資料重新整理, 以符合自己的需求
- 讓資料進行分組 `GROUP BY`

單一欄位分組

- 最簡單也最常用
- 範例: 找出單一演員曾演出的作品數量
- ```sql
  SELECT actor_id, count(*)
  FROM film_actor
  GROUP BY actor_id;
  ```

多重欄位分組

- 產生跨越多個欄位進行的分組
- 範例: 找出每個演員演出過的各個分級影片的數量
- ```sql
  SELECT fa.actor_id, f.rating, count(*)
  FROM film_actor fa
    INNER JOIN film f
    ON fa.film_id = f.film_id
  GROUP BY fa.actor_id, f.rating
  ORDER BY 1, 2;
  ```

按照表示式分組

- 利用表示式產生的值來進行分組
- 範例: 依據年份將租賃記錄進行分組
- ```sql
  SELECT EXTRACT(YEAR FROM rental_date) AS year,
    COUNT(*) how_many
  FROM rental
  GROUP BY year;
  ```

產生小結 (rollups)

- MySQL `WITH ROLLUP`, 在進行 GROUP BY 計算時, 額外產生小結計算
- MySQL 範例:
- ```sql
  SELECT fa.actor_id, f.rating, count(*)
  FROM film_actor fa
    INNER JOIN film f
    ON fa.film_id = f.film_id
  GROUP BY fa.actor_id, f.rating WITH ROLLUP
  ORDER BY 1,2;
  ```
- Oracle Database 語法與 PostgreSQL 相同
  - 使用 `GROUP BY ROLLUP(fa.actor_id, f.rating)`
  - 此種語法的優點在於, 可以指定 ROLLUP 的對象, 只在需要的時候進行
  - 例如: `GROUP BY a, ROLLUP(b, c)
- _補_, PostgreSQL `ROLLUP` 語法不同, 範例如下
  - ```sql
    SELECT fa.actor_id, f.rating, count(*)
    FROM film_actor fa
      INNER JOIN film f
      ON fa.film_id = f.film_id
    GROUP BY ROLLUP(fa.actor_id, f.rating)
    ORDER BY 1,2;
    ```
- `CUBE`, MySQL 不支援此語法
  - SQL Server, Oracle Database, PostgreSQL 都支援
- _補_, PostgreSQL, 7.2.4. GROUPING SETS, CUBE, and ROLLUP
  - 在一個指令中完成, 更進階的 `GROUP BY` 使用 `GROUPING SETS` 任意組合, 提供最常見的兩種集合方式 `ROLLUP` 與 `CUBE`
  - 使用 `GROUPING SETS` 任意組合 GROUPING 的模式
    - `()` 空集合等同於隱性集合, 即所有的 rows
  - 使用 `ROLLUP` 照 GROUPING 的順序, 每次都進行小結計算
  - 使用 `CUBE` 所有的子集合都變成一種 GROUPING 模式, 即 power set
  - 在 `GROUP BY` 子句中, 可以任意組合以上三種語法
    - 並且可以在其中配合 `DISTINCT` 移除重複的 GROUPING SET

分組的篩選條件

- `HAVING` 為分組之後的資料加上篩選條件
- 篩選條件的語法 `WHERE` 作用在 `GROUP BY` 之前
  - `HAVING` 作用在 `GROUP BY` 之後
- 範例: 篩選出分級在 'G' 與 'PG' 的影片, 並且以 actor_id 和 rating 進行分組, 篩選出分組影片大於 9 的集合
- ```sql
  SELECT fa.actor_id, f.rating, count(*)
  FROM film_actor fa
    INNER JOIN film f
    ON fa.film_id = f.film_id
  WHERE f.rating IN ('G', 'PG')
  GROUP BY fa.actor_id, f.rating
  HAVING count(*) > 9;
  ```
- 進行篩選時, 思考操作的是原始資料, 還是已分組的資料,
  - 然後把篩選條件分別寫在 `WHERE` 子句或 `HAVING` 子句中

---

### 第九章 - 子查詢

---

- 子查詢是強大的工具

子查詢是什麼?

- subquery 子查詢
  - 一段包含在另一個 SQL 敘述的查詢
  - 子查詢必須由 `()` 包裹
  - 通常會在 containing statement 完成前先運算
  - 子查詢的結果如同一般查詢一樣會回傳一個結果集合
  - 當外圍敘述執行完成後, 子查詢所回傳的資料集合會被棄置
  - 子查詢就像是在 statement scope 內建立臨時資料表一樣
- 範例:
- ```sql
  SELECT customer_id, first_name, last_name
  FROM customer
  WHERE customer_id = (SELECT MAX(customer_id) FROM customer);
  ```

子查詢的類型

- 子查詢的第一種分類是由功能來區分
- 非關聯式子查詢 (noncorrelated subqueries), 子查詢完全自成一體
  - 大多數使用時機
- 關聯式子查詢 (correlated subqueries), 子查詢需要參照外圍敘述的欄位
  - 使用時機通常與 `UPDATE` 或 `DELETE` 有關
- 子查詢的第二種分類是依據回傳結果集合的類型
- 單一欄位一筆資料, 又稱為 scalar subquery 純量子查詢
  - 可以放在條件式的任一側, 通常搭配比較運算子使用
- 單一欄位多筆資料
- 多重欄位多筆資料

非關聯式子查詢

- 大多時候子查詢都屬於這種類型
- 範例: 搜尋任何不在 India 的城市
- ```sql
  SELECT city_id, city
  FROM city
  WHERE country_id != (
    SELECT country_id FROM country WHERE country = 'India'
  );
  ```
- **當把子查詢的結果用在等式查詢 (`=`, `!=`) 時, 如果子查詢的結果多於一筆時 (非純量結果) 會報出錯誤**

回傳多筆單一欄位資料的子查詢

- 回傳多於一筆資料的子查詢無法用在等式判斷 (`=`, `!=`, `<>`) 上
- 但是單一欄位多筆資料的子查詢, 可以配合其他運算子
  - `IN`, `NOT IN`, `ALL`, `ANY`

`IN` 和 `NOT IN` 運算子

- 雖然無法使用等式判斷來對應多筆資料, 但是可以使用 `IN`, `NOT IN` 來判斷使否屬於該集合中
- 範例: 使用 `IN` 運算子判斷集合
- ```sql
  SELECT country_id FROM country WHERE country IN ('Canada', 'Mexico');
  ```
- 常見的情況是 `IN` 與 `NOT IN` 使用子查詢生成的結果集合來進行判斷
- 範例: 查詢國家不屬於 Canada, Mexico 的所有城市
- ```sql
  SELECT city_id, city
  FROM city
  WHERE country_id NOT IN
  ( SELECT country_id
    FROM country
    WHERE country IN ('Canada', 'Mexico')
  );
  ```

`ALL` 運算子

- 比較整個子查詢的結果集合, 並且要整個結果集合都成立才條件成立
- `<> ALL` 等價於 `NOT IN`
  - 隨各自喜歡的語法和可閱讀性
- 範例: 查詢超過所有北美地區租片次數的客戶
- ```sql
  SELECT customer_id, COUNT(*)
  FROM rental
  GROUP BY customer_id
  HAVING count(*) > ALL
    (
      SELECT count(*)
      FROM rental r
        INNER JOIN customer c
        ON r.customer_id = c.customer_id
        INNER JOIN address a
        ON c.address_id = a.address_id
        INNER JOIN city ct
        ON a.city_id = ct.city_id
        INNER JOIN country co
        ON ct.country_id = co.country_id
      WHERE co.country IN ('United States', 'Mexico', 'Canada')
      GROUP BY r.customer_id
    );
  ```

`ANY` 運算子

- 類似 ALL 比較整個子查詢的結果集合
  - 但是 `ANY` 只要任一成立則條件成立
- `IN` 等價於 `= ANY`
  - 隨各自喜歡的語法和可閲讀性
- 範例: 查詢任何支付總金額比任一三個國家支付總金額還高的客人
- ```sql
  SELECT customer_id, SUM(amount)
  FROM payment
  GROUP BY customer_id
  HAVING SUM(amount) > ANY
    (
      SELECT SUM(p.amount)
      FROM payment p
        INNER JOIN customer c
        ON p.customer_id = c.customer_id
        INNER JOIN address a
        ON c.address_id = a.address_id
        INNER JOIN city ct
        ON a.city_id = ct.city_id
        INNER JOIN country co
        ON ct.country_id = co.country_id
      WHERE co.country IN ('Bolivia', 'Paraguay', 'Chile')
      GROUP BY co.country
    );
  ```

多重欄位子查詢

- 回傳多重欄位的子查詢比對
- 比對多重欄位需要欄位有固定的順序
- 範例: 尋找演員姓氏為 MONROE 並且有出演過 PG 級別電影的演員 ID 和該影片 ID
- ```sql
  SELECT actor_id, film_id
  FROM film_actor
  WHERE (actor_id, film_id) IN
    (
      SELECT a.actor_id, f.film_id
      FROM actor a
        CROSS JOIN film f
      WHERE a.last_name = 'MONROE'
        AND f.rating = 'PG'
    );
  ```
- 使用單一欄位子查詢的相同結果的搜尋
- ```sql
  SELECT fa.actor_id, fa.film_id
  FROM film_actor fa
  WHERE fa.actor_id IN
    (SELECT actor_id FROM actor WHERE last_name = 'MONROE')
    AND fa.film_id IN
    (SELECT film_id FROM film WHERE rating = 'PG');
  ```

關聯式子查詢

- 子查詢與外層查詢有關聯 (dependent) 時, 稱為關聯式子查詢
  - 子查詢會參照到外層查詢的欄位
  - **執行的順序與非關聯式子查詢不同**
  - 針對外查詢的**每個結果都會執行一次**子查詢
  - _補_, 先執行外層查詢, 並且針對每個查詢結果進行一次子查詢
    - 因此如果外層查詢的結果很多時, 容易引起效能問題
- 範例 1: 尋找租賃次數剛好 20 次的客人姓名
  - 這個範例形成關聯式子查詢的關鍵在於子查詢中的 `c.customer_id` 參照到外部的欄位
  - 因為關聯式子查詢會根據外部的次數, 都進行一次子查詢, 因此這個查詢中的子查詢執行次數等同於 customer table 中的資料數量
- ```sql
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE 20 = (
    SELECT count(*) FROM rental r
    WHERE r.customer_id = c.customer_id
  );
  ```
- 範例 2: 尋找租片總金額在 180 到 240 之間的客人姓名
  - 這個關聯式子查詢執行次數一樣等同於 customer table 的資料數量
- ```sql
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE (
    SELECT sum(p.amount) FROM payment p
    WHERE p.customer_id = c.customer_id
  ) BETWEEN 180 AND 240;
  ```

`EXISTS` 運算子

- 常用於配合子查詢的判別算子 `EXISTS` 與 `NOT EXISTS`
- 只是需要用來判斷子查詢是否有回傳結果, 但是不需要理會回傳的資料內容
- 範例: 尋找在 2005-05-25 以前有租過片的客人
- ```sql
  SELECT c.first_name, c.last_name
  FROM customer c
  WHERE EXISTS (
    SELECT 1 FROM rental r
    WHERE r.customer_id = c.customer_id
    AND date(r.rental_date) < '2005-05-25'
  );
  ```
- 使用 `EXISTS` 時, 不需要理會回傳值, 因此**慣例**通常會使用 `SELECT 1` 或 `SELECT *`
  - 使用任何 SELECT 都不會影響結果
- 範例: 尋找從未演出過 R 級片的演員姓名
- ```sql
  SELECT a.first_name, a.last_name
  FROM actor a
  WHERE NOT EXISTS (
    SELECT 1
    FROM film_actor fa
      INNER JOIN film f ON f.film_id = fa.film_id
    WHERE fa.actor_id = a.actor_id
      AND f.rating = 'R'
  );
  ```

以關聯式子查詢來操作資料

- 關聯式子查詢也大量被使用在 `UPDATE`, `DELETE`, `INSERT` 敘述中
- 範例 1: 以每位 customer 最新的 rental_date 來更新 last_update 欄位
- ```sql
  UPDATE customer c
  SET last_update = (
    SELECT max(r.rental_date) FROM rental r
    WHERE r.customer_id = c.customer_id
  );
  ```
- 範例 1 改進版: 為了避免子查詢沒有結果而產生 last_update 被賦值為 null 的情況
  - 增加 WHERE 子句進行判斷有租過片
- ```sql
  UPDATE customer c
  SET last_update = (
    SELECT max(r.rental_date) FROM rental r
    WHERE r.customer_id = c.customer_id )
  WHERE EXISTS (
    SELECT 1 FROM rental r
    WHERE r.customer_id = c.customer_id
  );
  ```
- _補_, PostgreSQL 中可以使用 `EXPLAIN` 來分析 SQL 語句的執行
- 使用於 `DELETE` 子句的情境
- PostgreSQL 範例: 刪除到今日為止在過去一年沒有租過片的客人資料
- ```sql
  DELETE FROM customer c
  WHERE 365 < ALL (
    SELECT EXTRACT (DAY FROM (now() - r.rental_date)) days_since_last_rental
    FROM rental r
    WHERE r.customer_id = c.customer_id
  );
  ```
- **MySQL 中** DELETE 敘述不能使用資料表別名, 以上範例必須改成 `DELETE FROM customer` 不加別名的版本

使用子查詢的時機

將子查詢當作資料來源

- 以子查詢產生的結果集當成一個 table 作為資料來源
  - 子查詢極具彈性, 幾乎可以建構出任何所需要的資料表
- 範例: 查詢使用者姓名和他的租賃次數和總金額
- ```sql
  SELECT c.first_name, c.last_name,
    pymnt.num_rentals, pymnt.tot_payments
  FROM customer c
    INNER JOIN (
      SELECT customer_id,
        count(*) num_rentals,
        sum(amount) tot_payments
      FROM payment
      GROUP BY customer_id
    ) pymnt
  ON c.customer_id = pymnt.customer_id;
  ```
- 進階功能 `CROSS APPLY`, `OUTER APPLY` 可以協助在此情境中使用關聯式子查詢

打造資料

- 利用子查詢的彈性, 來產生原本沒有事先定義過的資料格式
  - _補_, **十分強大的使用情境**
- 範例: 想要按照客戶付款的金額進行分組
- 1 產生分組的描述
  - 使用集合算子產生分組定義
- ```sql
  SELECT 'Small Fry' name, 0 low_limit, 74.99 high_limit
  UNION ALL
  SELECT 'Average Joes' name, 75 low_limit, 149.99 high_limit
  UNION ALL
  SELECT 'Heavy Hitters' name, 150 low_limit, 99999999.99 high_limit;
  ```
- 2 配合子查詢把分組定義與資料組合再一起
- ```sql
  SELECT pymnt_grps.name, count(*) num_custoemrs
  FROM (
    SELECT customer_id,
      count(*) num_rentals,
      sum(amount) tot_payments
    FROM payment
    GROUP BY customer_id
  ) pymnt
  INNER JOIN (
    SELECT 'Small Fry' name, 0 low_limit, 74.99 high_limit
    UNION ALL
    SELECT 'Average Joes' name, 75 low_limit, 149.99 high_limit
    UNION ALL
    SELECT 'Heavy Hitters' name, 150 low_limit, 99999999.99 high_limit
  ) pymnt_grps
  ON pymnt.tot_payments BETWEEN pymnt_grps.low_limit AND pymnt_grps.high_limit
  GROUP BY pymnt_grps.name;
  ```
- 分組定義的子查詢, 也可以變成永久性或暫時性的資料表 (table),
  - 但是這樣細小且無資料的定義資料表更適合以臨時子查詢的方式定義
  - _補_, 取決於管理資料庫系統的方式與表達模式

任務導向的子查詢

- 把要進行分組作業的 table 以子查詢的方式先單獨做完, 再結合其他資訊的表單
  - 比起把全部的 table 整合之後才進行運算, **效能可能會更好**, 可閱讀性可能也更好
- 範例: 查詢包含租賃次數, 總金額, 客戶名稱和所在城市
- ```sql
  SELECT c.first_name, c.last_name, ct.city, pymnt.tot_payments, pymnt.tot_rentals
  FROM (
    SELECT customer_id, count(*) tot_rentals, sum(amount) tot_payments
    FROM payment
    GROUP BY customer_id
  ) pymnt
  INNER JOIN customer c
    ON pymnt.customer_id = c.customer_id
  INNER JOIN address a
    ON c.address_id = a.address_id
  INNER JOIN city ct
    ON a.city_id = ct.city_id;
  ```
- 範例: 同樣的事情但是組合所有的 table 後才進行運算
- ```sql
  SELECT c.first_name, c.last_name, ct.city, sum(p.amount) tot_payments, count(*) tot_rentals
  FROM payment p
  INNER JOIN customer c
    ON p.customer_id = c.customer_id
  INNER JOIN address a
    ON c.address_id = a.address_id
  INNER JOIN city ct
    ON a.city_id = ct.city_id
  GROUP BY c.first_name, c.last_name, ct.city;
  ```

通常資料表運算式

- Common table expressions, CTE
- 在單一大型查詢中的輔助工具, 把複雜的命令拆成個別小部分
- 使用 `WITH` keyword 來實現, 並且可以串聯, 後面直接接續主要命令
- 範例:
- ```sql
  WITH actors_s AS (
    SELECT actor_id, first_name, last_name
    FROM actor
    WHERE last_name LIKE 'S%'
  ),
  actors_s_pg AS (
    SELECT s.actor_id, s.first_name, s.last_name,
      f.film_id, f.title
    FROM actors_s s
      INNER JOIN film_actor fa
      ON  s.actor_id = fa.actor_id
      INNER JOIN film f
      ON f.film_id = fa.film_id
    WHERE f.rating = 'PG'
  ),
  actors_s_pg_revenue AS (
    SELECT spg.first_name, spg.last_name, p.amount
    FROM actors_s_pg spg
      INNER JOIN inventory i
      ON i.film_id = spg.film_id
      INNER JOIN rental r
      ON i.inventory_id = r.inventory_id
      INNER JOIN payment p
      ON r.rental_id = p.rental_id
  )
  SELECT spg_rev.first_name, spg_rev.last_name, sum(spg_rev.amount) tot_revenue
  FROM actors_s_pg_revenue spg_rev
  GROUP BY spg_rev.first_name, spg_rev.last_name
  ORDER BY 3 desc;
  ```

把子查詢當成產生表示式的工具

- 子查詢可以用於任何 expression 出現的場合, 包括 SELECT, ORDER BY, INSERT 敘述中
- 範例: 把子查詢用於 SELECT expression
  - 這個例子中 customer table 會被搜尋三次, 分別在三個子查詢中
  - 但是這個例子中不需要將 payment table 與 customer table 進行組合
- ```sql
  SELECT (
    SELECT c.first_name FROM customer c
    WHERE c.customer_id = p.customer_id
  ) first_name, (
    SELECT c.last_name FROM customer c
    WHERE c.customer_id = p.customer_id
  ) last_name, (
    SELECT ct.city FROM customer c
    INNER JOIN address a
      ON c.address_id = a.address_id
    INNER JOIN city ct
      ON a.city_id = ct.city_id
    WHERE c.customer_id = p.customer_id
  ) city,
    sum(p.amount) tot_payments,
    count(*) tot_rentals
  FROM payment p
  GROUP BY p.customer_id;
  ```
- 範例: 把子查詢用於 ORDER BY expression 中
  - 以純量子查詢的結果作為 ORDER BY 的依據
- ```sql
  SELECT a.actor_id, a.first_name, a.last_name
  FROM actor a
  ORDER BY (
    SELECT count(*) FROM film_actor fa
    WHERE fa.actor_id = a.actor_id
  ) DESC;
  ```
- 範例: 利用子查詢來提供 INSERT 的輸入值
  - 尤其是輸入值是來自於資料庫系統中, 形成關聯的 table
- ```sql
  INSERT INTO film_actor (actor_id, film_id, last_update)
  VALUES (
    (SELECT actor_id FROM actor WHERE first_name = 'JENNIFER' AND last_name = 'DAVIS'),
    (SELECT film_id FROM film WHERE title = 'ACE GOLDFINGER'),
    now()
  );
  ```

子查詢概要

- 多使用不斷實驗各種子查詢的用法, 慢慢的在撰寫複雜的 SQL statement 時, 就會更以子查詢的方式撰寫

---

### 第十章 - 再談結合

- 本章著重說明 INNER JOIN 以外的結合方式, 包含 OUTER JOIN 和 CROSS JOIN

Outer Joins

- `INNER JOIN` 不會考慮到結合條件失敗時的情況, 結果集合只存在結合條件成功的內容
- 範例: 以影片列表為影片單位, 來計算庫存中每個影片的庫存量
  - 此時問題是影片列表中有 1000 筆影片, 但是有 42 部影片不在庫存中
  - 因此, 使用 INNER JOIN 時, 這 42 部影片不會出現在結果集合中
- ```sql
  SELECT f.film_id, f.title, count(*) num_copies
  FROM film f
    INNER JOIN inventory i
    USING (film_id)
  GROUP BY f.film_id, f.title;
  ```
- 範例: 如果想要無論是否存在於庫存中, 都必須輸出該影片的結果, 找不到時顯示 0 庫存
  - 那麼此時需要以 film table 為主體, 使用 OUTER JOIN 並且注意到此時計算的數量是 inventory_id,
  - 換句話說, count 在該影片 inventory_id 是 `null` 時則是 0, 因此 0 庫存符合預期
- ```sql
  SELECT f.film_id, f.title, count(i.inventory_id) num_copies
  FROM film f
    LEFT OUTER JOIN inventory i
    ON f.film_id = i.film_id
  GROUP BY f.film_id, f.title;
  ```
- OUTER JOIN 一定會把指定的那一方的所有資料都輸出到結果集合中, 而無法 INNER JOIN 的部分則會補上 `null`

Left 與 Right Outer Joins 的比較

- `LEFT OUTER JOIN` 與 `RIGHT OUTER JOIN` 的差異在於指定左邊還是右邊的 table 作為一定要輸出的主體

三方 Outer Join

- 也許會想要進行兩個以上的資料表都進行 OUTER JOIN
- 範例: 必須輸出 film 和 inventory table 並且結合 rental table 的資料
  - 此時在 LEFT OUTER JOIN 左側的兩個 table 為 film 和 inventory 是必須出現的資料
  - 結合語法是有順序的, 並且要對應結合的條件
- ```sql
  SELECT f.film_id, f.title, i.inventory_id, r.rental_date
  FROM film f
    LEFT OUTER JOIN inventory i
    ON f.film_id = i.film_id
    LEFT OUTER JOIN rental r
    ON i.inventory_id = r.inventory_id
  WHERE f.film_id BETWEEN 13 AND 15;
  ```

Cross Joins

- 笛卡兒乘積 `CROSS JOIN`
- 兩個 table 所有的資料表進行結合, 並且不指定結合的條件, _補_, 結果是對應的窮舉, 即笛卡爾乘積
- 範例: 列舉出所有 category 與 language 的組合結果
- ```sql
  SELECT c.name category_name, l.name language_name
  FROM category c
    CROSS JOIN language l;
  ```
- CROSS JOIN 的應用
- 假設我們要生成一整年的日期為其建立一個資料表
  - 我們可以使用 CROSS JOIN 生成一年所需的數量, 並且配合日期運算生成我們要的結果
- 範例: 組合出 400 筆資料 10 \* 10 \* 4
- ```sql
  SELECT ones.num, tens.num, hundreds.num, ones.num + tens.num + hundreds.num AS sum
  FROM (
    SELECT 0 num UNION ALL
    SELECT 1 num UNION ALL
    SELECT 2 num UNION ALL
    SELECT 3 num UNION ALL
    SELECT 4 num UNION ALL
    SELECT 5 num UNION ALL
    SELECT 6 num UNION ALL
    SELECT 7 num UNION ALL
    SELECT 8 num UNION ALL
    SELECT 9 num
  ) ones
  CROSS JOIN (
    SELECT 0 num UNION ALL
    SELECT 10 num UNION ALL
    SELECT 20 num UNION ALL
    SELECT 30 num UNION ALL
    SELECT 40 num UNION ALL
    SELECT 50 num UNION ALL
    SELECT 60 num UNION ALL
    SELECT 70 num UNION ALL
    SELECT 80 num UNION ALL
    SELECT 90 num
  ) tens
  CROSS JOIN (
    SELECT 0 num UNION ALL
    SELECT 100 num UNION ALL
    SELECT 200 num UNION ALL
    SELECT 300 num
  ) hundreds;
  ```
- PostgreSQL 範例: 配合日期運算
- ```sql
  SELECT (DATE '2020-01-01' + MAKE_INTERVAL (DAYS => (ones.num + tens.num + hundreds.num))) dt
  FROM (
      SELECT 0 num UNION ALL
      SELECT 1 num UNION ALL
      SELECT 2 num UNION ALL
      SELECT 3 num UNION ALL
      SELECT 4 num UNION ALL
      SELECT 5 num UNION ALL
      SELECT 6 num UNION ALL
      SELECT 7 num UNION ALL
      SELECT 8 num UNION ALL
      SELECT 9 num
    ) ones
    CROSS JOIN (
      SELECT 0 num UNION ALL
      SELECT 10 num UNION ALL
      SELECT 20 num UNION ALL
      SELECT 30 num UNION ALL
      SELECT 40 num UNION ALL
      SELECT 50 num UNION ALL
      SELECT 60 num UNION ALL
      SELECT 70 num UNION ALL
      SELECT 80 num UNION ALL
      SELECT 90 num
    ) tens
    CROSS JOIN (
      SELECT 0 num UNION ALL
      SELECT 100 num UNION ALL
      SELECT 200 num UNION ALL
      SELECT 300 num
    ) hundreds
  WHERE (DATE '2020-01-01' + MAKE_INTERVAL (DAYS => (ones.num + tens.num + hundreds.num))) < '2021-01-01'
  ORDER BY dt;
  ```
- _補_, PostgreSQL 中有一個更實用的語法可以達成以上需求 `generate_series()`
  - ```sql
    SELECT day::date
    FROM generate_series(
        '2020-01-01'::date,
        '2020-12-31'::date,
        '1 day'::interval
    ) AS day;
    ```
- PostgreSQL 範例: 生成一個包含 2005 所有日期並且計算出每日租賃數量的報表
  - 這是一個複雜的 SQL 語句, 包含了 aggregate function, GROUP, 子查詢, OUTER JOIN, CROSS JOIN, UNION ALL, 日期的運算
  - _補_, 關於日期生成的部分可以用更簡單的語法進行撰寫
- ```sql
  SELECT days.date date, count(r.rental_id) num_rentals
  FROM rental r
    RIGHT OUTER JOIN (
      SELECT (DATE '2005-01-01' + MAKE_INTERVAL (DAYS => (ones.num + tens.num + hundreds.num)))::DATE date
      FROM (
          SELECT 0 num UNION ALL
          SELECT 1 num UNION ALL
          SELECT 2 num UNION ALL
          SELECT 3 num UNION ALL
          SELECT 4 num UNION ALL
          SELECT 5 num UNION ALL
          SELECT 6 num UNION ALL
          SELECT 7 num UNION ALL
          SELECT 8 num UNION ALL
          SELECT 9 num
        ) ones
        CROSS JOIN (
          SELECT 0 num UNION ALL
          SELECT 10 num UNION ALL
          SELECT 20 num UNION ALL
          SELECT 30 num UNION ALL
          SELECT 40 num UNION ALL
          SELECT 50 num UNION ALL
          SELECT 60 num UNION ALL
          SELECT 70 num UNION ALL
          SELECT 80 num UNION ALL
          SELECT 90 num
        ) tens
        CROSS JOIN (
          SELECT 0 num UNION ALL
          SELECT 100 num UNION ALL
          SELECT 200 num UNION ALL
          SELECT 300 num
        ) hundreds
      WHERE (DATE '2005-01-01' + MAKE_INTERVAL (DAYS => (ones.num + tens.num + hundreds.num))) < '2006-01-01'
      ORDER BY date
    ) AS days
    ON r.rental_date::DATE = days.date
  GROUP BY days.date
  ORDER BY 1;
  ```

Natural Joins

- 不指定結合的條件, 交由資料庫自行決定的語法 `NATURAL JOIN`
- 範例: 對 customer table 與 rental table 進行 NATURAL JOIN
  - 問題在於這兩個 table 中除了 customer_id 以外, 還有 last_update 這個欄位都為同名欄位
  - 因此資料庫選擇的是 last_update 作為結合欄位, 而非我們期望的 customer_id
- ```sql
  SELECT c.first_name, c.last_name, r.rental_date::date
  FROM customer c
    NATURAL JOIN rental r;
  ```
- 因此, 我們最好還是乖乖使用 INNER JOIN 並且加上明確的結合條件
  - 避免意外也提供更好的可閱讀性

---

### 第十一章 - 條件邏輯

- 在 SQL 敘述中產生分支處理, 可以任意運用在 SELECT, INSERT, UPDATE, DELETE 等敘述中

何謂條件邏輯?

- 賦予多個程式路徑的能力
- 範例: customer table 中的 active 欄位以數字儲存 0 代表 inactive, 1 代表 active
  - 我們希望在生成的時候產生對應的字串以用於報表中
- ```sql
  SELECT first_name, last_name,
    CASE
      WHEN active = 1 THEN 'ACTIVE'
      ELSE 'INACTIVE'
    END activity_type
  FROM customer;
  ```
- `CASE`, `WHEN`, `THEN`, `ELSE`, `END`
- _補_, PostgreSQL, Conditional Expressions

case 表示式

- 各家主流資料庫系統都有內建個別不同的函式, 用來達成 IF-THEN-ELSE 的功能
- `CASE` 表示式屬於 SQL92 標準, 因此各家資料庫都有支援
- `CASE` 語法直接屬於 SQL 語法, 因此可以直接應用在 SELECT, INSERT, UPDATE, DELETE 敘述中

搜尋式 case 表示式 (searched case expression), _補_, 一般的 IF ELSE

- 語法
  - ELSE 語句是選用的
  - 如同常見的 IF ELSE 語句, 具有 lazy evaluation
  - 每個分支的回傳結果必須要是同一個型別的
- ```sql
  CASE
    WHEN C1 THEN E1
    WHEN C2 THEN E2
    ...
    WHEN CN THEN EN
    [ELSE ED]
  END
  ```
- 範例: CASE 條件中使用關聯式子查詢產生結果
  - 依據資料實際的特性, 這種敘述可能比 table JOIN 和 GROUP 更有效率
- ```sql
  SELECT c.first_name, c.last_name,
    CASE
      WHEN active = 0 THEN 0
      ELSE (
        SELECT count(*)
        FROM rental r
        WHERE r.customer_id = c.customer_id
      )
    END num_rentals
  FROM customer c;
  ```

簡易式 case 表示式 (simple case expression), _補_, 類似 switch 語法

- 語法
  - 較無彈性, 只能做單純的比對
  - 推薦優先使用上一種語法, 除非條件非常簡單
- ```sql
  CASE V0
    WHEN V1 THEN E1
    WHEN V2 THEN E2
    ...
    WHEN VN THEN EN
    [ELSE ED]
  END
  ```
- 範例:
- ```sql
  CASE category.name
    WHEN 'Children' THEN 'All Ages'
    WHEN 'Horror' THEN 'Adult'
    WHEN 'Music' THEN 'Teens'
    ELSE 'Other'
  END
  ```

case 表示式的範例

結果集合再轉換

- 把 CASE 篩選用在 SELECT 敘述中, 來呈現不同型態的結果集合
- PostgreSQL 範例: 資料行列轉換
  - 對於簡易的情境, 可以這樣使用
  - 更複雜的行列轉換, 需要參照更進階的語法, pivot table, 在各家資料庫系統有不同的實作
  - _補_, PostgreSQL 的實現是有一個 extension 叫做 crosstab 提供這個功能
- ```sql
  SELECT extract(MONTH FROM rental_date) rental_month,
    count(*) num_rentals
  FROM rental
  WHERE rental_date BETWEEN '2005-05-01' AND '2005-08-01'
  GROUP BY extract(MONTH FROM rental_date);
  ```
- ```sql
  SELECT
    sum(CASE WHEN extract(MONTH FROM rental_date) = 5 THEN 1 ELSE 0 END) May_rentals,
    sum(CASE WHEN extract(MONTH FROM rental_date) = 6 THEN 1 ELSE 0 END) June_rentals,
    sum(CASE WHEN extract(MONTH FROM rental_date) = 7 THEN 1 ELSE 0 END) July_rentals
  FROM rental
  WHERE rental_date BETWEEN '2005-05-01' AND '2005-08-01';
  ```

檢查存在與否

- 把 CASE 篩選用在 SELECT 敘述中, 配合關聯式子查詢實現檢查存在與否
  - `WHEN EXISTS`
- 範例:
- ```sql
  SELECT a.first_name, a.last_name,
    CASE
      WHEN EXISTS (
        SELECT 1 FROM film_actor fa
          INNER JOIN film f USING(film_id)
        WHERE fa.actor_id = a.actor_id
          AND f.rating = 'G'
      ) THEN 'Y'
      ELSE 'N'
    END g_actor,
    CASE
      WHEN EXISTS (
        SELECT 1 FROM film_actor fa
          INNER JOIN film f USING(film_id)
        WHERE fa.actor_id = a.actor_id
          AND f.rating = 'PG'
      ) THEN 'Y'
      ELSE 'N'
    END pg_actor,
    CASE
      WHEN EXISTS (
        SELECT 1 FROM film_actor fa
          INNER JOIN film f USING(film_id)
        WHERE fa.actor_id = a.actor_id
          AND f.rating = 'NC-17'
      ) THEN 'Y'
      ELSE 'N'
    END nc17_actor
  FROM actor a
  WHERE a.last_name LIKE 'S%' OR a.first_name LIKE 'S%';
  ```
- 範例 2: 使用 simple case expression 來調整輸出值
- ```sql
  SELECT f.title,
    CASE (
      SELECT count(*) FROM inventory i
      WHERE i.film_id = f.film_id
    )
      WHEN 0 THEN 'Out of Stock'
      WHEN 1 THEN 'Scarce'
      WHEN 2 THEN 'Scarce'
      WHEN 3 THEN 'Available'
      WHEN 4 THEN 'Available'
      ELSE 'Common'
    END film_availability
  FROM film f;
  ```

除以零的錯誤

- 在 MySQL 中除零, 不會丟出錯誤而是自動設定結果為 NULL
- 其他資料庫系統, 通常會丟出錯誤, 包含 Oracle Database, PostgreSQL, ...
- 範例: 計算客戶的平均支付金額
  - 使用 CASE 判別來避免除零錯誤
- ```sql
  SELECT c.first_name, c.last_name,
    sum(p.amount) tot_payment_amt,
    count(p.amount) num_payments,
    (sum(p.amount) /
      CASE WHEN count(p.amount) = 0 THEN 1
        ELSE count(p.amount)
      END
    ) avg_payment
  FROM customer c
    LEFT OUTER JOIN payment p
    ON c.customer_id = p.customer_id
  GROUP BY c.first_name, c.last_name;
  ```

依條件進行更新

- 把 CASE 條件判別用在 UPDATE 敘述中
- 範例: 配合關聯式子查詢, 條件設定 customer 的 active 值
- ```sql
  UPDATE customer c
  SET active =
    CASE
      WHEN 90 <= (
        SELECT extract(DAY FROM now() - max(rental_date))
        FROM rental r
        WHERE r.customer_id = c.customer_id
      ) THEN 0
      ELSE 1
    END
  ;
  ```

Null 值的處理

- Null 值的處理
  - 輸出 Null 時候的處理
  - 和運算中可能遇到 Null 的處理
- 範例:
- ```sql
  SELECT c.first_name, c.last_name,
    CASE
      WHEN a.address IS NULL THEN 'Unknown'
      ELSE a.address
    END address,
    CASE
      WHEN ct.city IS NULL THEN 'Unknown'
      ELSE ct.city
    END city,
    CASE
      WHEN cn.country IS NULL THEN 'Unknown'
      ELSE cn.country
    END country
  FROM customer c
    LEFT OUTER JOIN address a
    ON c.address_id = a.address_id
    LEFT OUTER JOIN city ct
    ON a.city_id = ct.city_id
    LEFT OUTER JOIN country cn
    ON ct.country_id = cn.country_id;
  ```

---

### 第十二章 - 交易

- 交易, Transactions
- 將 SQL 敘述集合成群, 並且只有全部執行成功, 才會視為成功
- 一種全有或全無的機制

多使用者的資料庫

- 當一個系統所有使用者只進行讀取時, 沒什麼特別需要處理的
- 但是當有使用者**同時**在進行新增或修改資料時, 就有情況需要處理了
- _補_, 讀寫分離架構, Read/Write Splitting

Locking

- 鎖定 locking, 當一個操作被鎖定時, 其他想要進行修改甚至閱讀鎖定資料的使用者就必須等待
- 資料庫針對鎖定 locking 的機制分類
- 第一種, 寫入需取得 write lock, 讀取也需取得 read lock
- 第二種, 寫入需取得 write lock, 但是讀取不需要, 由資料庫系統來控制讀取的 versioning
- 兩種策略各有利弊
- 微軟的 SQL Server 採用第一種, 同時具備 write lock 與 read lock
- Oracle Database 則採用第二種, 使用 write lock + versioning
- MySQL 則可以依據所選擇的 storage engine 儲存引擎來選擇
- _補_, PostgreSQL 使用第二種 write lock + versioning

鎖定的細緻度 (granularities)

- 關於鎖定機制的細緻度, 不同層級
- Table locks, 資料表鎖定
  - 不讓多位使用者同時修改同一資料表中的資料
- Page locks, 記憶體頁面鎖定
  - 不讓多位使用者同時修改同一個記憶體頁面的資料 (一個 page 通常容量在 2KB 到 16KB 之間)
- Row locks, 資料列鎖定
  - 不讓多位使用者同時修改資料表中的同一筆 (row) 資料
- 之間的差異在於等待時間與進行鎖定的難易度和消耗的資源
  - 鎖定整個 table 最簡單, 但是使用者等待時間最長
  - 鎖定一個 row 對於使用者來說最不需要等待, 而資料庫處理卻較複雜
- 微軟的 SQL Server 三者皆採用, 並且中間會動態的調整鎖定的細緻度 (Lock Escalation)
- Oracle Database 只採用 row lock 資料列鎖定
- MySQL Server 則依據所選擇的儲存引擎而定
- _補_, PostgreSQL 三者皆採用並且不會動態調整細緻度

何謂交易?

- 要處理的問題是當資料庫系統突然離線, 使用者突然中斷程式執行, ... 例外處理
- 並且要處理多位使用者同時操作相同的資料的情境
- 交易機制 (transaction) 是打包多道 SQL 敘述,
  - 並且只允許完全成功或者失敗兩種結果 (**atomicity**)
- 成功時會進行 commit; 而失敗時會進行 rollback
- 錯誤處理情境:
  - 1 伺服器在進行到 commit 或 rollback 之前就斷線了, 則伺服器在重啟後必須先還原完成 (rollback) 才能繼續運行
  - 2 已經進行 commit 但是資料還未寫入永久記憶體中, 則伺服器在重啟後必須先完成寫入永久記憶體 (**durability**)

展開一筆交易

- 展開交易, 資料庫系統分成兩類
- 第一類, (Implicitly) 針對每個 session 資料庫系統會自動維護一個對應的 transaction
  - 此時所有的命令都屬於一個 transaction 的內容, 需要手動的進行 commit 或 rollback
- 第二類, (Explicitly) 必須明確的用語法展開一筆 transaction, 一般情況下個別 SQL 敘述會被自動的單獨 commit
  - **autocommit mode**
- Oracle Database 採用第一類, 優點是每個 SQL 命令都有機會可以 rollback
- MySQL 與 SQL Server 採用第二類, 此時一但按下 Enter 就會自動 commit 沒有機會可以 rollback
  - 而使用交易需要使用明確的命令
  - 但是這個 autocommit mode 是可以關閉的
- **推薦進入資料庫系統時, 都關閉 autocommit mode**
  - 養成習慣以 transaction 的方式提交所有的命令, 這樣在出錯的時候能更好的救援
- _補_,
  - PostgreSQL, autocommit mode 預設是開啟的
  - 可以通過語法關閉 `\set AUTOCOMMIT off`
  - `psql -v AUTOCOMMIT=off`

結束交易

- 無論是 Implicitly 或者 Explicitly 展開 transaction
  - 只有在明確命令 commit 並且交易完成後, 變更的內容才會真正寫入並且釋出被鎖住的資源
  - 要還原異動, 則是明確使用 rollback 命令
- 除了明確的 commit 與 rollback 命令之外, 有些情境會自動結束當前的 transaction
- 1 伺服器關閉, 此時這筆交易會在重啟後自動 rollback
- 2 下達關於 schema 相關的命令時, 會立刻提交當前的 transaction
  - 因為與 schema 相關的命令無法 rollback, 例如: 新增 table, 修改 table, 新增 index, ...
- 3 明確展開另一個新的 transaction, 這會自動提交先前的 transaction
- 4 資料庫系統偵測到 deadlock 並且與你的 transaction 有關, 此時會自動 rollback 當前的 transaction 並且收到錯誤訊息
- **當時常出現 deadlock 導致 transaction 被 rollback 時**,
  - **應該檢查應用層的邏輯**, 保持正確的資料存取順序

交易儲存點

- 某些情況下交易中發生問題, 但是不想要整個交易進行 rollback
  - 而是只 rollback 到指定的 savepoint
- 所有的 savepoint 必須要有一個名稱, 並且在一個交易內允許多個 savepoints
- 範例: `SAVEPOINT my_savepoint;`
- 範例: `ROLLBACK TO SAVEPOINT my_savepoint;`
- 範例: 淘汰產品 XYZ
  - 各家關於 transaction 的語法可能有所不同, 需要參照各自的文件
  - 例如: SQL Server 就得改用 `save transaction` 來建立 savepoint
- ```sql
  START TRANSACTION;

  UPDATE product
  SET date_retired = CURRENT_TIMESTAMP()
  WHERE product_cd = 'XYZ';
  SAVEPOINT before_close_accounts;

  UPDATE account
  SET status = 'CLOSED', close_date = CURRENT_TIMESTAMP(),
    last_activity_date = CURRENT_TIMESTAMP()
  WHERE product_cd = 'XYZ';

  ROLLBACK TO SAVEPOINT before_close_accounts;
  COMMIT;
  ```

- _補_, PostgreSQL 範例
- ```sql
  BEGIN;
  UPDATE accounts SET balance = balance - 100.00
      WHERE name = 'Alice';
  SAVEPOINT my_savepoint;
  UPDATE accounts SET balance = balance + 100.00
      WHERE name = 'Bob';
  -- oops ... forget that and use Wally's account
  ROLLBACK TO my_savepoint;
  UPDATE accounts SET balance = balance + 100.00
      WHERE name = 'Wally';
  COMMIT;
  ```

選擇一種儲存引擎

- Oracle Database 與微軟的 SQL Server 都各自使用一套程式碼來控制底層運作
- 而 MySQL 允許你選擇儲存引擎 (storage engine), 甚至針對不同的 table 選用不同的 storage engine
- `MyISAM`, 非交易式, 採用資料表鎖定 (table lock)
- `MEMORY`, 非交易式, 專供記憶體內的資料表使用
- `CSV`, 交易式, 資料儲存在 CSV 格式中
- `InnoDB`, 交易式, 採用資料列層級鎖定 (row lock)
- `Merge`, 讓多個相等的 MyISAM 看起來像單一個資料表, table partitioning
- `Archive`, 儲存大量無 index 資料, 主要用於 archival purpose
- MySQL 中以 `show table status` 可以查詢的到個別資料表的 storage engine 類型
  - 以 `ALTER TABLE ... ENGINE` 可以修改所使用的 storage engine

---

### 第十三章 - 索引與約束條件

- 資料庫中會間接影響撰寫程式的功能 index 與 constraint

索引 (index)

- 在插入 (INSERT) 一筆資料的時候, 資料庫不會特別將資料放在特定的位置
  - 伺服器會對每個 table 保存一個可用的空間清單, 把新增的資料放置到任何可用的空間中
- 在查詢時, 伺服器會需要走訪 table 中的**所有資料**, 稱為 table scan
- 範例: 搜尋特定姓名的使用者
  - 此時需要走訪整個 customer table 一個一個比對
- ```sql
  SELECT first_name, last_name
  FROM customer
  WHERE last_name LIKE 'Y%';
  ```
- 當資料數量持續增加時, 進行 table scan 的速度會越來越慢
  - 到一個**臨界點**時, 查詢的響應時間就會超越合理的時間
- 資料庫系統中提供 index 功能來**加速查詢**
  - 讓你只需檢查資料表中的部分資料, 而不需要完整檢視每筆資料
- **Index 本身也是一種特殊的 table, 但是他不會包含所有的資料, 只需要包含用來搜尋的資料, 以及對應到原始資料的位置資訊**
- 當有了 Index 後, 就會由查詢最佳化工具, 來決定該 index 是否有助於查詢, 如果有用就會採用
  - 當有多個 index 存在時, 會由最佳化工具來選擇
- _補_, 選擇對哪一個建立 index 取決於常用的命令會依據哪個欄位而建立

建立索引, `CREATE INDEX`

- MySQL 範例: 對 customer table 的 email 欄位建立 index 並且命名為 idx_email
  - MySQL 將 index 視為 table 的附屬元件, 因此使用 `ALTER TABLE` 來附加 index
- ```sql
  ALTER TABLE customer
  ADD INDEX idx_email (email);
  ```
- SQL Server 與 Oracle 範例:
  - 其他資料庫系統把 Index 視為獨立的
  - _補_, PostgreSQL 也使用此語法
- ```sql
  CREATE INDEX idx_email
  ON customer (email);
  ```
- MySQL 範例: 查詢既有 index
- ```sql
  SHOW INDEX FROM customer \G;
  ```
- _補_, PostgreSQL
  - 在 `psql` 中使用 `\d [table_name or index_name]` 查詢 table 詳細資料, 其中包含 index 資訊
- 在 MySQL 中, 伺服器會為 CREATE TABLE 時設定的 primary key 欄位建立一個名為 PRIMARY 的 index
  - 是為了用於後續的 primary key contraint
- MySQL 範例: 移除 index
- ```sql
  ALTER TABLE customer
  DROP INDEX idx_email;
  ```
- SQL Server 範例: `DROP INDEX idx_email ON customer;`
- Oracle Database 範例: `DROP INDEX idx_email;`
- _補_, PostgreSQL 移除現有的 index
  - `DROP INDEX index_name;`

獨特性索引 (unique index), `CREATE UNIQUE INDEX`

- 在設計資料庫 schema 時, 務必要考量哪些欄位可以允許重複的資料, 哪些則是必須唯一存在
- Unique index, 同時具有 index 加速查詢的功能, 並且加上唯一性檢查
- MySQL 範例: 建立 unique index
- ```sql
  ALTER TABLE customer
  ADD UNIQUE idx_email (email);
  ```
- SQL Server 與 Oracle Database 範例: 建立 unique index
  - _補_, PostgreSQL 也使用相同語法
- ```sql
  CREATE UNIQUE INDEX idx_email
  ON customer (email);
  ```
- 當 INSERT 時遇到 unique index 欄位, 則會進行唯一性檢查, 如果有重複的資料時會丟出錯誤
  - _補_, PostgreSQL 的錯誤訊息如下
  - ```
    ERROR:  duplicate key value violates unique constraint "idx_email"
    DETAIL:  Key (email)=(MARY.SMITH@sakilacustomer.org) already exists.
    ```
- 對於 PRIMARY KEY 欄位, 不需要額外加上 UNIQUE INDEX, 因為預設已經具備唯一性檢查

多重欄位索引

- 如果時常會**同時**搜尋多個欄位, 就可以針對多欄位進行 INDEX 設定
- MySQL 範例: 為 last_name 與 first_name 欄位同時設定 INDEX
  - **設定多重欄位 index 的欄位順序, 是有意義的**
  - 以這個例子為例, last_name 然後才是 first_name
  - 因此這個 index 可以在同時搜尋 last_name + first_name 時提供幫助
  - 在對於單獨 last_name 搜尋時也能提供幫助, 但是單獨使用 first_name 搜尋時沒有作用
- ```sql
  ALTER TABLE customer
  ADD INDEX idx_full_name (last_name, first_name);
  ```
- 建立多重欄位 index 時, 需要謹慎考量欄位順序, 來提高這個 index 的效用

索引的種類

B-tree 索引, balanced-tree indexes

- 平衡樹索引 (balanced-tree indexes, B-tree index)
  - **適合適用於 high-cardinality 資料, 即欄位中不重複的資料很多時**, 高基數資料
- MySQL, Oracle Database, SQL Server 預設的 index 都是 B-tree index
  - 除非額外指定
- B-tree index 是以樹狀結構配置,
  - 具備至少一層的 branch nodes (分枝節點),
  - 分枝的末梢只有一層 leaf nodes (葉節點)
- leaf nodes 才存資料; branch nodes 只作為引導
- 當原始的 table 要進行 INSERT, UPDATE, DELETE 的修改時,
  - 伺服器會嘗試保持 index tree balanced (維持平衡樹的狀態)
- 只有當樹狀結構保持平衡的狀態 (balanced), 才能在搜尋上快速地走到葉節點並找到所需的資料值

二元圖索引, bitmap indexes

- 當想要加速搜尋的欄位中含有很多重複的資料時, **low-cardinality**, 低基數資料
  - 此時 B-tree indexes 會非常難維持 balanced
  - 因此需要不同的 index 策略
- 二元圖索引 (bitmap indexes) 就是**適用於 low-cardinality 資料情境**
  - 該 index 會對不重複的資料分開個別維護一個 bitmap
  - 此時, 當搜尋特定值時, 只需要挑出該 bitmap 來進行處理即可
- **適合用於資料值的類型有限的欄位**, 例如: 銷售季度, 地理區域, 產品, 業務人員等等
- Oracle Database 範例: 針對只有兩個狀態的欄位進行 index 設定
- ```sql
  CREATE BITMAP INDEX idx_active ON customer (active);
  ```
- _補_, PostgreSQL 並**沒有**像是 Oracle Database 一樣的語法來直接建立 BITMAP INDEX
- _補_, PostgreSQL 也有數種不同的 Index Types, 參照 Index Types 和 Performance Tips 文件

文字索引, fulltext

- 處理大量文件資料時, 可能需要搜尋文件中的字詞或者片語
  - 傳統的 index 並不適用這樣的情境
  - 文件搜尋屬於專門技術
- 個別的資料庫系統都有針對文件特製的 index 和搜尋機制
- MySQL 和微軟的 SQL Server 採用名為 fulltext 的 index 機制
- Oracle Database 則採用名為 Oracle Text 的工具
- _補_, PostgreSQL 文件中有專門一章討論, Chapter 12. Full Text Search

如何運用索引？

- 使用 `EXPLAIN` 語法讓資料庫提供執行計劃 (execution plan)
  - 各家資料庫系統都有各自查詢執行計劃的語法
  - SQL Server 使用 `set show plan_text on`
  - Oracle Database 使用 `explain plan` 語法將執行計劃寫入一個名為 plan_table 的特殊資料表中
  - _補_, PostgreSQL 一樣使用 `EXPLAIN` 語法, 添加在任何 SQL statment 之前即可生成 execution plan
- PostgreSQL 範例: 查詢 execution plan
- ```sql
  EXPLAIN SELECT customer_id, first_name, last_name
  FROM customer
  WHERE first_name LIKE 'S%' AND last_name LIKE 'p%';
  ```
- 從中查詢伺服器決定使用的搜尋方式 (type) 和使用的 index
  - 範圍掃描 (range scan)
- **查詢調校**, 是專門的學問
  - 需要查詢所使用的資料庫系統文件, 尋找有哪些手段可以使用
  - 調校包含檢視 SQL 敘述, 判斷伺服器有哪些資源可以用來執行
  - 可以是修改 SQL 敘述本身, 或者調整資料庫的資源
- _補_,
  - PostgreSQL 查詢文件 Performance Tips

索引的缺陷

- Index 不是萬能的工具, 不是越多越好
- Index 會建立一個特殊的資料表
- 有關的 index 越多, 當資料要進行異動時 (增, 刪, 改), 參與的資料表越多, **則整體的速度越慢**
- 此外 index 資料表也要**佔用硬碟空間**
- 使用 Index 的策略
  - 1 只有當**明確需要時**才使用
  - 2 如果 Index 只有在特殊的目的使用時, 最好是使用時才建立, 並且使用後就把 index 拿掉,下次要用時再加上去
  - 3 使用情境分成需要使用 index 時, 和不需要 index 並且可能造成負擔時; 分成兩個時段分別移除和重新加上 index
- 把 index 控制在剛好的數量
- **常見策略**
- 1 確定所有 primary key 都有 index, 如果是多重欄位 primary key 則可以考慮針對部分欄位進行 index 或者以不同順序添加 index
- 2 欄位作為其他的 foreign key 索引用時, 也針對這個欄位製作成 index
  - 理由是伺服器在進行刪除資料時, 都會對 foreign key 欄位進行檢查, 因此勢必會進行特定值的搜尋
- 3 有些欄位常作為檢索資料使用時, 例如大部分的日期欄位和短字串的欄位 (2 ~ 50個字元)
- **觀察**資料表在**現實收到的**查詢命令, 並且檢視伺服器的執行計劃, 再修改 index 策略, 以符合**實際常見的查詢路徑**

約束條件, constraints

- 針對一個資料表的單一或者多個欄位添加的限制
- 主鍵約束條件, Primary Keys
  - 用來保障資料表中一個或多欄位資料的獨特性
  - 屬於一種特殊的獨特性約束條件
- 外來鍵約束條件, Foreign Keys
  - 限制資料表中的一個或多欄位資料, 必須等同於另外一個資料表中的 PRIMARY KEY
- 獨特性約束條件, Unique Constraints
  - 保障資料表中一個或多欄位資料的獨特性
- 檢查約束條件, Check Constraints, Not-Null Constraints, ...
  - 限制欄位中所允許的資料值
- 沒有約束條件的話, 資料庫的資料一致性 (data integrity) 就容易產生問題, 而產生 orphaned rows
  - 有約束條件的話, 在試圖變更, 修改, 移動資料時, 就能適時地發出錯誤訊息
- MySQL 上需要使用外來鍵約束條件時, 必須確定所選擇的 storage engine 是 InnoDB
- _補_, PostgreSQL 可以參考文件 5.5. Constraints

建立約束條件 `CONSTRAINT`

- 通常會在 `CREATE TABLE` 敘述時一同定義
  - 也可以在事後以 `ALTER TABLE` 進行添加
- PostgreSQL 範例: 建立 customer table + Index + constraints
  - _補_,
  - PostgreSQL 中**不支援** MySQL `last_update TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP`
  - 的 ON UPDATE 觸發 CURRENT_TIMESTAMP
  - 需要使用其他技術達成相同效果, Triggers
- ```sql
  CREATE TABLE customer (
    customer_id INTEGER GENERATED BY DEFAULT AS IDENTITY,
    first_name VARCHAR(45) NOT NULL,
    last_name VARCHAR(45) NOT NULL,
    email VARCHAR(50) DEFAULT NULL,
    active BOOLEAN NOT NULL,
    create_date TIMESTAMP NOT NULL,
    last_update TIMESTAMP DEFAULT NOW(),
    store_id INTEGER NOT NULL,
    address_id INTEGER NOT NULL,
    CONSTRAINT pk_customer PRIMARY KEY (customer_id),
    CONSTRAINT fk_customer_address
      FOREIGN KEY (address_id)
      REFERENCES address (address_id)
      ON DELETE RESTRICT
      ON UPDATE CASCADE,
    CONSTRAINT fk_customer_store
      FOREIGN KEY (store_id)
      REFERENCES store (store_id)
      ON DELETE RESTRICT
      ON UPDATE CASCADE
  );
  CREATE INDEX idx_last_name ON customer (last_name);
  CREATE UNIQUE INDEX idx_fk_store_id ON customer
  (store_id);
  CREATE UNIQUE INDEX idk_fk_address_id ON customer (address_id);
  ```
- `ON DELETE RESTRICT`
  - 加在子層 FOREIGN KEY CONSTRAINT 上
  - 在刪除時, 會限制仍被 referenced 的資料, 無法刪除, 會報錯
  - 來防禦在任意刪除上層資料時, 使得子層資料有無主的資料
- `ON UPDATE CASCADE`
  - 加在子層 FOREIGN KEY CONSTRAINT 上
  - 在更新時, 會一同改變被 referenced 的資料, 使之保持一致性
  - 也是用來防禦當上層資料被修改時, 子層可能產生的無主資料
- 範例: 嘗試在資料仍被 referenced 的情況下刪除上層資料
  - 此時會丟出錯誤並告知有資料在哪個子層 table 中被引用
- ```sql
  SELECT c.first_name, c.last_name, c.address_id, a.address
  FROM customer c
    INNER JOIN address a
    USING (address_id)
  WHERE a.address_id = 123;

  DELETE FROM address WHERE address_id = 123;
  ```

- 範例: 嘗試修改含有 `ON UPDATE CASCADE` 控制的欄位
  - 此時修改上層資料時, 會一並修改子層資料 (referenced 的資料會一同被修改)
- ```sql
  UPDATE address
  SET address_id = 9999
  WHERE address_id = 123;

  SELECT c.first_name, c.last_name, c.address_id, a.address
  FROM customer c
    INNER JOIN address a
    USING (address_id)
  WHERE a.address_id = 9999;
  ```

- 除了 `RESRTICT`, `CASCADE` 之外
  - 還可以選擇 `SET NULL`, 當上層資料被改變時, 對應的子層資料會被設定成 `NULL`
- 因此對於 CONSTRAINT FOREIGN KEY 可以添加的限制可以組合成六種
  - `ON DELETE RESTRICT`
  - `ON DELETE CASCADE`
  - `ON DELETE SET NULL`
  - `ON UPDATE RESTRICT`
  - `ON UPDATE CASCADE`
  - `ON UPDATE SET NULL`
- 修改 CONSTRAINT
  - 通常使用 `ALTER TABLE DROP` 刪除 CONSTRAINT, 和 `ALTER TABLE ADD` 新增 CONSTRAINT

exercise 13-1

```sql
ALTER TABLE rental DROP CONSTRAINT rental_customer_id_fkey;
ALTER TABLE rental ADD CONSTRAINT rental_customer_id_fkey
  FOREIGN KEY (customer_id)
  REFERENCES customer (customer_id)
  ON DELETE RESTRICT
  ON UPDATE CASCADE;
```

exercise 13-2

```sql
CREATE INDEX idx_payment_date_amount ON payment (payment_date, amount);
```

---

### 第十四章 - Views

- 良好設計的應用程式, 通常只會公開一部分的介面, 把其他實作的細節隱藏起來
  - 在日後修改設計, 也不會影響到使用者
- 資料庫中以 VIEW 來實現, 允許使用者只通過 VIEW 介面存取資料, 把實際的資料表隱藏起來

何謂檢視表 VIEW

- VIEW 只是某一種查詢資料的機制而已
  - 不涉及資料的儲存, 意味著不會添加硬碟空間
- 要建立一個 VIEW, 只要建立一個 SELECT 敘述並加上一個名稱,
  - 此時其他使用者是通過這個 SELECT 敘述建立的 VIEW 存取資料, 就如同使用其他 table 一樣
- 範例: 假設對 customer 這個 TABLE 產生一個隱藏 email 欄位的 VIEW, 讓不同權限的使用者, 使用這個 VIEW
  - 上半部 `CREATE VIEW` 用來描述 VIEW 所該擁有的欄位
  - 下半部 `AS SELECT` 則具體描述對應的欄位來源
  - 資料庫會儲存 VIEW 的定義, 在此時不會做任何的執行
- ```sql
  CREATE VIEW customer_vw (
    customer_id,
    first_name,
    last_name,
    email
  ) AS SELECT
    customer_id,
    first_name,
    last_name,
    concat(substr(email,1,2), '*****', substr(email, -4)) email
  FROM customer;
  ```
- 範例: 查詢 VIEW table
  - 一但建立 VIEW 之後, 就可以如同操作一般的 table 一樣操作 VIEW table
- ```sql
  SELECT first_name, last_name, email
  FROM customer_vw;
  ```
- MySQL, Oracle 範例: 查看 VIEW table 的定義
  - _補_, PostgreSQL 中使用 `\d+ customer_vw` 查詢
- ```sql
  describe customer_vw;
  ```
- 範例: 對 VIEW table 使用 SELECT 敘述中的子句操作
  - 例如 aggregate function, GROUP BY, HAVING, ORDER BY, ...
- ```sql
  SELECT first_name, count(*), min(last_name), max(last_name)
  FROM customer_vw
  WHERE first_name LIKE 'J%'
  GROUP BY first_name
  HAVING count(*) > 1
  ORDER BY 1;
  ```
- 範例: 結合 customer_vw table 與 payment table 找出一次性支付金額大於 11 的客人
  - 把 VIEW table 與其他 table 進行結合,
- ```sql
  SELECT cv.first_name, cv.last_name, p.amount
  FROM customer_vw cv
    INNER JOIN payment p
    ON cv.customer_id = p.customer_id
  WHERE p.amount >= 11;
  ```

為何要使用檢視表？

資料安全

- 隱藏資料表, 譬如不要將 SELECT 權限開給所有的使用者
- 而是建立數個 VIEW table, 讓不同的使用者操作不同的 VIEW table
- 範例: 為行銷團隊, 建立一個只包含活躍的用戶 customer VIEW table
  - 使用 WHERE 建立一個篩選過後的 table
- ```sql
  CREATE VIEW active_customer_vw (
    customer_id, first_name, last_name, email
  )
  AS SELECT
    customer_id, first_name, last_name,
    concat(substr(email, 1, 2), '******', substr(email, -4)) email
  FROM customer
  WHERE active = 1;
  ```
- Oracle Database 的另一種功能, Virtual Private Database, VPD
  - 以建立 policies 的方式讓資料庫伺服器自動修改命令敘述
- _補_, PostgreSQL 中有名為 Row Level Security, RLS 的功能
  - 也是以建立 policies 的方式, 控制使用者權限

資料彙整

- 應用程式經常會需要彙整資料, 可以直接讓資料庫彙整好資料後一次呈現
- 以建立 VIEW 的方式撰寫彙整資料的邏輯, 讓外部應用程式只需要操作這個 VIEW 即可
- 範例:
- ```sql
  CREATE VIEW sales_by_film_category
  AS SELECT
    c.name AS category,
    SUM(p.amount) AS total_sales
  FROM payment p
    INNER JOIN rental r USING (rental_id)
    INNER JOIN inventory i USING (inventory_id)
    INNER JOIN film f USING (film_id)
    INNER JOIN film_category fc USING (film_id)
    INNER JOIN category c USING (category_id)
  GROUP BY c.name
  ORDER BY total_sales DESC;
  ```
- 當使用 VIEW 的方式, 效能出現問題時
  - 只需要把彙整資料建立成一個實際的 table 並且修改這個 VIEW 的定義指向實際的 table 就可以提高查詢效能
  - 並且不需要外部應用程式修改介面

隱藏複雜性

- 使用 VIEW 的常見理由之一, 避免使用者直接面對複雜的資料
  - 尤其是當我們需要複雜的資料表結合或複雜的子查詢時
- 範例: 產生與 film 相關的統計資料報表
  - 需要 film_id, title, description, rating, category_name
  - 和計算 num_actors, inventory_cnt, num_rentals
- 製作成 VIEW table 的優點在於
  - 提供一個實作好的介面
  - 並且操作這個 VIEW 的時候, 只有使用到的欄位才會觸發實際的查詢
  - 換句話說, 以下複雜的子查詢只有在對應的欄位使用到的時候才會進行運算
- ```sql
  CREATE VIEW film_stats
  AS SELECT
    f.film_id, f.title, f.description, f.rating,
    (
      SELECT c.name
      FROM category c
        INNER JOIN film_category fc
        ON c.category_id = fc.category_id
    ) category_name,
    (
      SELECT count(*)
      FROM film_actor fa
      WHERE fa.film_id = f.film_id
    ) num_actors,
    (
      SELECT count(*)
      FROM inventory i
      WHERE i.film_id = f.film_id
    ) inventory_cnt,
    (
      SELECT count(*)
      FROM inventory i
        INNER JOIN rental r
        ON i.inventory_id = r.inventory_id
      WHERE i.film_id = f.film_id
    ) num_rentals
  FROM film f;
  ```

結合已區隔的資料

- 在資料庫設計中經常會將大型資料表打散成較小的資料表, 以改善效能
  - 因此在情境需要的時候, 反而可以使用 VIEW 來達成組合這些小的資料表來使用
  - 好處是隱藏效能優化的設計細節, 對外使用統一的介面
- 這種實作的好處是直接把 payment table 換成 payment VIEW 並不會改變介面
  - 但是可以進行效能優化的實作 (分割資料表)
- 範例: 實作為了優化查詢速度, 把 payment 資料分散在 payment_historic 與 payment_current 兩個 table 中
  - 當需要完整資料的時候, 使用 VIEW 來操作
- ```sql
  CREATE VIEW payment_all (
    payment_id, customer_id, staff_id, rental_id, amount, payment_date, last_update
  )
  AS SELECT
    payment_id, customer_id, staff_id, rental_id, amount, payment_date, last_update
  FROM payment_historic
  UNION ALL
  SELECT
    payment_id, customer_id, staff_id, rental_id, amount, payment_date, last_update
  FROM payment_current;
  ```

可供更新的檢視表

- 只要符合限制, 是允許直接通過 VIEW table 進行更新的
  - 各家資料庫系統的限制可能不同, 需要參照文件
- MySQL 可更新 VIEW 的限制
  - 不包含 aggregate functions
  - 不包含 GROUP BY, HAVING
  - 在 SELECT 或 FROM 子句中不包含子查詢, WHERE 裡的子查詢不能參照 FROM 裡的資料表 (_補_, 不允許關聯式子查詢)
  - 不包含 UNION, UNION ALL, DISTINCT
  - FROM 子句中必須包含一個 table 或其他可供更新的 VIEW
  - 涉及多個資料表時, 則 WHERE 必須是以 INNER JOIN 所結合的

更新一個簡單的檢視表

- 範例: 以可供更新的 VIEW 來更新指定 customer 的 last_name
- ```sql
  CREATE VIEW customer_vw (
    customer_id, first_name, last_name, email
  )
  AS SELECT
    customer_id, first_name, last_name,
    concat (substr(email, 1, 2), '*****', substr(email, -4)) email
  FROM customer;

  UPDATE customer_vw
  SET last_name = 'SMITH-ALLEN'
  WHERE customer_id = 1;
  ```

- 在此範例中, 無法以 VIEW 更新 email 欄位, 因為 email 欄位是由推導而得的
  - 從邏輯上來說這樣也是合理的, 因為這個 VIEW 的建立目的就是為了隱藏 email 欄位
- ```sql
  --- will throw an ERROR
  UPDATE customer_vw
  SET email = 'MARY.SMITH-ALLEN@sakilacustomer.org'
  WHERE customer_id = 1;
  ```
- 這個 VIEW 無法進行 INSERT 原因是
  - 1 其中含有被推導的欄位
  - 2 不包含所有關於新增 customer 所需的欄位
- ```sql
  INSERT INTO customer_vw (
    customer_id, first_name, last_name
  )
  VALUES (
    99999, 'ROBERT', 'SIMPSON'
  );
  ```

更新複雜的檢視表

- _補_, 更新複雜的 VIEW 需要參照各家的資料庫限制, 有許多不同之處
- MySQL 範例: 更新一個來自多個資料表結合的 VIEW
  - _補_, PostgreSQL 無法直接執行這種多個資料表結合的 VIEW, 需要額外的功能輔助 (INSERT OF UPDATE trigger)
  - _補_, 換句話說, 要針對複雜的 VIEW 進行除了讀取之外的功能, 可能都需要額外的加工; 但是此時可能已經超越 VIEW 被建立的原因 (用於隱藏細節)
- ```sql
  CREATE VIEW customer_details
  AS SELECT
    c.customer_id, c.store_id, c.first_name, c.last_name, c.address_id, c.active, c.create_date,
    a.address, a.postal_code,
    ct.city,
    cn.country
  FROM customer c
    INNER JOIN address a
    ON c.address_id = a.address_id
    INNER JOIN city ct
    ON a.city_id = ct.city_id
    INNER JOIN country cn
    ON ct.country_id = cn.country_id;

  UPDATE customer_details
  SET last_name = 'SMITH-ALLEN', active = 0
  WHERE customer_id = 1;

  UPDATE customer_details
  SET address = '999 Mockingbird Lane'
  WHERE customer_id = 1;
  ```

- MySQL 範例: 嘗試對於一個 VIEW 同時更新兩個 table 中的欄位
  - 此時會丟出錯誤, 無法同時更新多個 table
- ```sql
  UPDATE customer_details
  SET last_name = 'SMITH-ALLEN', active = 0
    address = '999 Mockingbird Lane'
  WHERE customer_id = 1;
  ```

---

### 第十五章 - 中繼資料

- 中繼資料, metadata

描述資料用的資料

- 關於資料本身的資料, 例如:
  - 資料表名稱, 資料表儲存資訊, 儲存引擎
  - 欄位名稱, 欄位資料型別, 欄位的預設值
  - NOT NULL 的欄位約束條件
  - PRIMARY KEY 的所在欄位, PRIMARY KEY 的名稱, PRIMARY KEY 的 INDEX 名稱
  - INDEX 名稱, INDEX 類型, INDEX 所在的欄位, INDEX 欄位的排序方式, INDEX 的儲存資訊
  - FOREIGN KEY 名稱, FOREIGN KEY 所在的欄位, 與 FOREIGN KEY 關聯的資料表和欄位
- 這些資料被稱為 data dictionary 或 system catalog
  - 資料庫伺服器必須保存且維護這些資料, 才能驗證和執行 SQL 敘述
  - 只能通過正確的機制進行修改, 例如: ALTER TABLE
- 各家資料庫系統, 有各自自己一套的 meta data 機制
  - 其中 information schema 屬於 SQL 標準, 因此通常具備可移植性
- Oracle Database
  - user_tables, all_constraints
  - system-stored procedure: dbms_metadata
- SQL Server
  - system-stored procedure: sp_tables
  - information_schema
- MySQL
  - information_metadata
- _補_, PostgreSQL
  - 專屬: system catalogs 和 PostgreSQL-specific views
  - SQL 標準的 information schema

information_schema

- information_schema 的資料是以 VIEW 的方式存在
- 範例: 查詢 `information_schema.tables`
- ```sql
  SELECT table_name, table_type
  FROM information_schema.tables;
  ```
- 範例: 以 `information_schema.views` 查詢所有可以更新的 VIEW
- ```sql
  SELECT table_name, table_schema, table_catalog, is_updatable
  FROM information_schema.views
  WHERE is_updatable='YES';
  ```
- 範例: 以 `information_schema.columns` 來查詢 film table 的欄位資訊
  - 查詢欄位名稱, 資料型別, 字元長度上限, 數值精度並且以定義時的順序排序
- ```sql
  SELECT column_name,
    data_type,
    character_maximum_length char_max_len,
    numeric_precision num_prcsn, numeric_scale num_scale
  FROM information_schema.columns
  WHERE table_name = 'film'
  ORDER BY ordinal_position;
  ```
- MySQL 範例: 以 `information_schema.statistics` 查詢 index 相關資訊
  - 這個 table 屬於 MySQL 專有
  - _補_, PostgreSQL 可以從專屬的 `pg_indexes` VIEW 中查詢資料
- ```sql
  SELECT index_name, non_unique, seq_in_index, column_name
  FROM information_schema.statistics
  WHERE table_name = 'rental'
  ORDER BY 1, 3;
  ```
- 範例: 以 `information_schema.table_constraints` 查詢 table 的限制條件
- ```sql
  SELECT constraint_name, table_name, constraint_type
  FROM information_schema.table_constraints
  WHERE table_name = 'rental'
  ORDER BY 3, 1;
  ```
- information_schema 所有的資訊, 屬於各家資料庫系統有所不同
  - _補_, PostgreSQL 可以參考文件 https://www.postgresql.org/docs/current/information-schema.html

操作中繼資料

- _補_, 與中繼資料相關的程式碼, 都依據資料庫系統不同有很大的差別, 需要參照各家資料庫的文件來實作

產生架構用的命令碼

- 範例: 使用 SQL 敘述以 information_schema 中的資料, 建立出可執行的 SQL 語法
  - 使用外部其他程式語言更容易實現
  - 很多外部工具提供類似功能
  - 範例中單純以 SQL 敘述實現
- _補_, 非常困難, 因為資料庫系統的不同語法非常不同, 可以移植性很低
  - 並且所需要參考的細節很多, 跨多個 information_schema 甚至無法單純搜集齊全
- _補_, PostgreSQL 中
  - 可以使用 CLI 工具, `pg_dump -U username -t table_name --schema-only database_name` 去查詢所使用的 SQL script
  - 使用 GUI 工具 `pgAdmin` 也有功能可以直接取得

部署驗證

- 使用 SQL 語法, 生成當前資料庫系統的部署資料, 用來驗證執行前與執行後的結果
- PostgreSQL 範例:
- ```sql
  SELECT tbl.table_name, (
      SELECT count(*) FROM information_schema.columns clm
      WHERE clm.table_schema = tbl.table_schema
        AND clm.table_name = tbl.table_name
    ) num_columns, (
      SELECT count(*) FROM pg_indexes
      WHERE tablename = tbl.table_name
    ) num_indexes, (
      SELECT count(*) FROM information_schema.table_constraints tc
      WHERE tc.table_schema = tbl.table_schema
        AND tc.table_name = tbl.table_name
        AND tc.constraint_type = 'PRIMARY KEY'
    ) num_primary_keys
  FROM information_schema.tables tbl
  WHERE tbl.table_type = 'BASE TABLE' AND tbl.table_schema = 'public'
  ORDER BY 1;
  ```

動態產生的 SQL

- 涵蓋 SQL 語言的 superset
  - Oracle 的 PL/SQL 語言
  - 微軟的 Transact-SQL 語言
  - _補_, PostgreSQL 中也有 PL/pgSQL 語言
- 而其他外部的程式語言本身的語法並沒有包含 SQL 敘述的部分, 因此其中的 SQL 敘述是以字串的方式進行處理
- 大部分的資料庫系統都允許以**字串**為形式傳入 SQL 敘述給伺服器
  - 而是以 **dynamic SQL execution** 的方式
  - _補_, PostgreSQL 主要用於 PL/pgSQL 中
  - _補_, 這種方式也是各家資料庫系統有個別的語法, 需參照各自的文件
    - Oracle: EXECUTE IMMEDIATE 指令
    - SQL Server: sp_executesql 指令
    - MySQL: PREPARE, EXECUTE, DEALLOCATE
- 主要是因為指令是在 run time 組合而成的, 或者需要配合外部資源所形成的
  - 因此, 無法將 SQL 敘述寫死在程式碼中
- _補_, 用於優化 SQL 伺服器效能的手法
  - `PREPARE`, `EXECUTE` 用於讓資料庫伺服器避免重複的 parse 階段
    - 搭配的 `DEALLOCATE` 用於釋放 `PREPARE` 所佔用的資源
  - 最大的用處在於在單一個 session 中, 有重複大量相似的 SQL 敘述時的效能優化
  - 用法類似於 function 定義與執行, 和釋放佔用資源
- 主流做法, 還是以 General-purpose programming language 或者 PL/SQL 來實現

---

### 第十六章 - 分析函式, (window functions)

- 一般來說, 進行資料分析都是在資料庫伺服器以外的地方
  - 使用 Excel, R, Python 等外部的程式語言或工具進行
- 但是, SQL 本身也內建一些分析函式, 可以進行資料分析
  - 排序
  - 找出極端值
  - 找出常見的統計值

分析函式的概念

資料窗口 (windows), _補_, window function + aggregate function

- PostgreSQL 範例: 計算出一年中以月為單位最高累積銷售額和以季為單位最高的每月累積銷售額
  - 以 aggregate function 加上 window frame (`OVER`) 變成 window function 來進行分類運算
  - 以 `OVER ()` 關鍵字使用 window function, 其中使用 `PARTITION BY` 分割結果集合
  - _補_, 讓 aggregate function 只運作在指定的 window 上 (分割)
- ```sql
  SELECT EXTRACT(QUARTER FROM payment_date) AS quarter,
    TO_CHAR(payment_date, 'Month') month_nm,
    sum(amount) monthly_sales,
    max(sum(amount)) over () max_overall_sales,
    max(sum(amount)) over (partition by EXTRACT(QUARTER FROM payment_date)) max_qrtrr_sales
  FROM payment
  WHERE EXTRACT(YEAR FROM payment_date) = 2005
  GROUP BY TO_CHAR(payment_date, 'Month'), EXTRACT(QUARTER FROM payment_date);
  ```
- _補_, PostgreSQL 參考文件:
  - Chapter 3. Advanced Features, 3.5. Window Functions
  - Chapter 9. Functions and Operators, 9.22. Window Functions
- _補_, PostgreSQL
  - window function 用來計算跨越 rows 形成的集合, 必須使用 `OVER` 關鍵字來呼叫
  - aggregate function 也可以配合 `OVER` 關鍵字一同使用變成 window function
  - 比起 aggregate function 已經使用 GROUP BY 進行分類; window function 則允許客製化分類的方式
  - 並且 window function 可以運作允許跨越當前的 row

局部排序, `RANK()`, `ROW_NUMBER()`, `DENSE_RANK()`

- PostgreSQL 範例: 依據月份對每月累積銷售額進行排序並且添加順序值
  - 通過 window function 達成添加局部排序的順序值
  - window function `rank()` 中的 `ORDER BY` 是用來指定排序的方式
  - 在 `OVER` 中使用 `ORDER BY` 會形成的 window frame 是從最開始的 row 到當前的 row 包含與當前 row 相等值的 rows
- ```sql
  SELECT EXTRACT(QUARTER FROM payment_date) AS quarter,
    to_char(payment_date, 'Month') month_nm,
    sum(amount) monthly_sales,
    rank() OVER (ORDER BY sum(amount) DESC) sales_rank
  FROM payment
  WHERE EXTRACT(YEAR FROM payment_date) = 2005
  GROUP BY to_char(payment_date, 'Month'), EXTRACT(QUARTER FROM payment_date)
  ORDER BY monthly_sales;
  ```
- _補_, PostgreSQL 參考文件: Chapter 9. Functions and Operators, 9.22. Window Functions
  - 包含所有可用的 window function 列表
- _補_,
  - 比較 `row_number()`, `rank()`, `dense_rank()` 的差別
  - 主要差異在於應對數值相同時的行為
- PostgreSQL 範例: 產生季度排序值
- ```sql
  SELECT EXTRACT(QUARTER FROM payment_date) AS quarter,
    to_char(payment_date, 'Month') month_nm,
    sum(amount) monthly_sales,
    rank() OVER (
      PARTITION BY EXTRACT(QUARTER FROM payment_date)
      ORDER BY sum(amount) DESC
    ) qrtr_sales_rank
  FROM payment
  WHERE EXTRACT(YEAR FROM payment_date) = 2005
  GROUP BY to_char(payment_date, 'Month'), EXTRACT(QUARTER FROM payment_date)
  ORDER BY quarter, qrtr_sales_rank;
  ```

排名

排名函式

- SQL 標準中的排名用函式, 以下三種函式的**差異在於處理平手的做法**
- `row_number`, 每筆資料都有獨一無二的排序數字, 但是平手時則是隨機決定
- `rank`, 平手時排序數字相同, 但是會佔用後續排序數字, 意味著下一個非平手的數字看起來有斷層
- `dense_rank`, 平手時排序數字相同, 但是不會佔用後續的排序數字, 意味著不會產生斷層
- 範例: 對每個客人所租賃的次數, 使用三種排序函式產生排序數字
- ```sql
  SELECT customer_id, count(*) num_rentals,
    row_number() over (order by count(*) desc) row_numbers_rank,
    rank() over (order by count(*) desc) rank_rnk,
    dense_rank() over (order by count(*) desc) dense_rank_rnk
  FROM rental
  GROUP BY customer_id
  ORDER BY num_rentals desc;
  ```

產生多種排名

- PostgreSQL 範例: 對每個月的租賃次數進行排序取出每個月前 5 名的客人
  - 此時要對排序的 window function 進行 partition 成每個月
  - 如果要對經過 window function 運算後的結果集合進行篩選, 必須使用子查詢或者 CTE 的方式參照結果集合
- ```sql
  WITH month_rental_rank AS (
    SELECT customer_id,
      EXTRACT (MONTH FROM rental_date) rental_month,
      count(*) num_rentals,
      rank() over (
        partition by EXTRACT (MONTH FROM rental_date)
        order by count(*) desc
      ) month_rnk
    FROM rental
    GROUP BY customer_id, rental_month
    ORDER BY rental_month, num_rentals DESC
  )
  SELECT customer_id, to_char(to_timestamp(rental_month::text, 'MM'), 'Month') AS month, num_rentals, month_rnk AS ranking
  FROM month_rental_rank
  WHERE month_rnk <= 5
  ORDER BY rental_month, num_rentals desc, ranking;
  ```

報表函式

- 使用 aggregate function + window function + `partition by` 取代 aggregate function + `group by` 來計算
- PostgreSQL 範例: 使用 OVER 取代 GROUP BY 來計算每月累積和總和
- ```sql
  SELECT TO_CHAR(payment_date, 'Month') payment_month,
    amount,
    SUM(amount) OVER (PARTITION BY EXTRACT (MONTH FROM payment_date)) monthly_total,
    SUM(amount) OVER () grand_total
  FROM payment
  WHERE amount >= 10
  ORDER BY payment_month;
  ```
- PostgreSQL 範例: 同時使用 GROUP BY 與 window funciton 來計算每月累積值對總額的百分比
  - 使用 Month 作為 GROUP BY 的切分
  - 因此 SUM(amount) 代表的是每月總和, SUM(SUM(amount)) OVER () 代表的是每月總和的總和即全部加總
- ```sql
  SELECT TO_CHAR(payment_date, 'Month') payment_month,
    SUM(amount) month_total,
    ROUND((SUM(amount) / SUM(SUM(amount)) OVER ()) * 100, 2) pct_of_total
  FROM payment
  GROUP BY TO_CHAR(payment_date, 'Month');
  ```
- PostgreSQL 範例: 以 window function 計算比較, 找出 MAX 與 MIN 並且標注
- ```sql
  SELECT TO_CHAR(payment_date, 'Month') payment_month,
    SUM(amount) month_total,
    CASE SUM(amount)
      WHEN MAX(SUM(amount)) over () THEN 'Highest'
      WHEN MIN(SUM(amount)) over () THEN 'Lowest'
      ELSE 'Middle'
    END descriptor
  FROM payment
  GROUP BY TO_CHAR(payment_date, 'Month');
  ```

Window Frames

- 產生 window frame 的方式
  - `PARTITION BY` 照共同值來進行分組
- 如果此時不是以共同值來進行分組, 而是更複雜的分組方式
  - 例如: 產生累進小計的分組
- PostgreSQL 範例: 產生累進小計的 frame 分組
  - `ROWS UNBOUNDED PRECEDING` 此時的 window frame 代表的是從結果集合的起頭開始, 直到當前的這一筆資料為止
  - _補_, `ROWS` 代表作用於 ROW
  - _補_, 並且 frame_start 為 `UNBOUNDED PRECEDING` 代表從起頭開始
  - _補_, frame_end 沒有明確表明時, 預設是 `CURRENT ROW`
- ```sql
  SELECT TO_CHAR(payment_date, 'IYYYIW') payment_yearweek,
    SUM(amount) week_total,
    SUM(SUM(amount))
      OVER (
        ORDER BY TO_CHAR(payment_date, 'IYYYIW')
        ROWS UNBOUNDED PRECEDING
      ) rolling_sum
  FROM payment
  GROUP BY TO_CHAR(payment_date, 'IYYYIW')
  ORDER BY 1;
  ```
- _補_, PostgreSQL
  - 對 window frame 進行更細緻的處理, 在 `OVER` 中使用 `RANGE`, `ROWS`, `GROUPS`
  - 參考語法文件: Chapter 4. SQL Syntax, 4.2.8. Window Function Calls
- PostgreSQL 範例: 使用 window frame 來計算當前週 + 前後兩週的平均值
  - `ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING`
  - 代表作用在 `ROWS` 並且 frame_start 是 `1 PRECEDING` 和 frame_end 是 `1 FOLLOWING`
  - 要注意的是這個案例中, 第一項與最後一項會是只有兩週的平均值, 因為他們分別沒有前一項跟後一項
- ```sql
  SELECT TO_CHAR(payment_date, 'IYYY-IW') payment_yearweek,
    SUM(amount) week_total,
    ROUND(AVG(SUM(amount)) OVER (
      ORDER BY TO_CHAR(payment_date, 'IYYY-IW')
      ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING
    ), 2) rolling_3wk_avg
  FROM payment
  GROUP BY TO_CHAR(payment_date, 'IYYY-IW')
  ORDER BY 1;
  ```
- PostgreSQL 範例: window frame 的間隔, 使用間隔時間來決定, 計算七天平均值
- ```sql
  SELECT payment_date::DATE,
    SUM(amount),
    AVG(SUM(amount)) OVER (
      ORDER BY payment_date::DATE
      RANGE BETWEEN INTERVAL '3 days' PRECEDING
        AND INTERVAL '3 days' FOLLOWING
    ) seven_days_avg
  FROM payment
  WHERE payment_date BETWEEN '2005-07-01' AND '2005-09-01'
  GROUP BY payment_date::DATE
  ORDER BY 1;
  ```

Lag 和 Lead

- 在同一個結果集合中, 比較其他 ROW 的值
- PostgreSQL 範例: 從結果集合中取出前一項和後一項的值
  - 使用 `LAG` window function 取得當前 ROW 之前的值
  - 使用 `LEAD` window function 取得當前 ROW 之後的值
- ```sql
  SELECT TO_CHAR(payment_date, 'IYYYIW') payment_week,
    SUM(amount) week_total,
    LAG(SUM(amount), 1) OVER w AS prev_wk_tot,
    LEAD(SUM(amount), 1) OVER w AS next_wk_tot
  FROM payment
  GROUP BY payment_week
  WINDOW w AS (ORDER BY TO_CHAR(payment_date, 'IYYYIW'))
  ORDER BY 1;
  ```
- PostgreSQL 範例: 計算與前一週的差異值百分比
- ```sql
  SELECT TO_CHAR(payment_date, 'IYYYIW') payment_week,
    SUM(amount) week_total,
    ROUND(
      (SUM(amount) - LAG(SUM(amount), 1) OVER w)
      / (LAG(SUM(amount), 1) OVER w) * 100,
      1
    ) pct_diff
  FROM payment
  GROUP BY payment_week
  WINDOW w AS (ORDER BY TO_CHAR(payment_date, 'IYYYIW'))
  ORDER BY payment_week;
  ```

串接欄位值

- 整理與調整資料
  - 可以用於去正規化 (denormalize) 和藉此生成其他的文件規格, 例如: JSON, XML
- PostgreSQL 範例: 為每部只有三個演員的電影整理出一個欄位包含所有演員的姓氏, 並且以姓氏排序
  - MySQL 使用的語法是 `group_concat()`
  - SQL Server 使用的語法是 `string_agg`
  - Oracle 使用的語法是 `listagg`
  - _補_, PostgreSQL 也是 `string_agg`
- ```sql
  SELECT f.title,
    string_agg(a.last_name, ', ' ORDER BY a.last_name) actors
  FROM actor a
    INNER JOIN film_actor fa
    ON a.actor_id = fa.actor_id
    INNER JOIN film f
    ON fa.film_id = f.film_id
  GROUP BY f.title
  HAVING count(*) = 3;
  ```
- _補_, PostgreSQL 參考文件, Chapter 9. Functions and Operators, 9.21. Aggregate Functions

---

### 第十七章 - 操作大型資料庫

- 在過去硬碟容量是 MB 級, 而現在是 TB 與 PD 級別
- 關聯式資料庫在資料量持續飆升時遇到各種挑戰
- 通過 partitioning, clustering, sharding 三種技術讓關聯式資料庫的資料分散
- 或者直接轉換到其他專門處理 big data 的資料庫系統上

分割 (partitioning)

- 當資料持續增加時, 會在這些處理中感覺到越來越困難和耗時
  - 查詢執行時需要掃描整個資料表
  - 建立和重建 Index
  - 資料歸檔和刪除
  - 產生資料表和 Index 的統計數字
  - 資料表移位
  - 備份資料庫
- 最好趁資料表剛建立的時候, 就將大型資料表進行拆分, 即 partition (分割區)
- 因此可以進行分個別處理, 甚至同步處理
- _補_, PostgreSQL 文件: Chapter 5. Data Definition, 5.12. Table Partitioning
  - 經驗法則, 當資料的量開始大於伺服器所擁有的 memory size 時, 就應該進行 partitioning
  - 猜測因為當資料的量大於記憶體容量時, 開始會需要 I/O operation 而這個是十分緩慢的操作
- _補_, Partitioning 是允許 sub-partitioning 的
  - 換句話說, 一個 table 被 partitioining 後成為的 partition table 可以再次進行 partitioning

分割的概念

- Partitioning 的概念始於 1990 的 Oracle, 而後被移植到所有主流的資料庫系統上
- 一但資料表進行分割, 代表會出現兩個以上的資料表分區**擁有相同的定義**, 不過其中的**資料集合必須互相不重複**
  - 例如: 以銷售資料為例, 可以以月份進行分割, 或者以地理區域進行分割, ...
- 一但資料表被分割過後, 這個資料表本身就變成虛擬概念, 有點類似於 VIEW
  - 資料表實體與 Index 是建立在個別 paritition 上
- 此時可以對分割區進行個別的管理
  - 個別分割區必定儲存在不同的 tablespace 上
  - 不同的分割區可以使用不同的壓縮
  - 不同的分割區可以使用不同的 Index 策略
  - 不同的分割區可能有些統計資料是不變的, 而其他需要定時更新
  - 有些個別的分割區可以持續存在記憶體中 (pinned), 或者存在快取中 (flash storage tier)
- 資料表分割後, 可以增加資料儲存與管理的彈性, 對使用者來說則是維持統一的介面

資料表的分割

- 水平分割 (horizontal partitioning)
  - 即整個 row 會在同一個資料表裡, 只是把不同的 row 分散到不同的 table 中
- 垂直分割 (vertically partitioning)
  - 即一部分的 column 會被分散到其他的 partition 裡
- 水平分割時, 需要決定一個分割鍵 (partition key), 即依據哪一個欄位進行分割
  - 分割函式 (partitioning function) 會套用在這個 partition key 上, 來決定每筆 row 應該被屬哪一個分割區中

索引的分割

- 如果進行分割的資料表中擁有 Index
- 全域索引, global index
  - 跨分割區讓索引保持不變
  - 全域索引對於與 partition key 無關的欄位的查詢時, 十分有用
  - 因為此時的查詢, 必須進行遍歷所有的分割區, 如果此時有 global index 存在就可以被使用
- 局部索引, local index
  - 每個分割區有獨立的索引

分割的手法

- 各家資料庫系統有自家獨特的分割功能, 但是以下提供最常見的分割手法
- _補_,
  - PostgreSQL 內建的 partitioning 方式
  - Range partitioining
  - List partitioning
  - Hash partitioning

範圍分割法 (range partitioning)

- 第一種實作出來並且最廣泛使用的分割方式
- range partitioning 適用於多種不同的資料型別, 但是最常見的是日期範圍
- _補_, MySQL 語法與 PostgreSQL 不同, 需要參照各自的文件
- PostgreSQL 範例: 以 sale_date 為 sales table 以月進行 range partitioning
  - 建立 TABLE 時就表明是 `PARTITION BY` 的父層架構
  - 建立 partition TABLE 表明是 `PARTITION OF` 屬於哪一個父層 TABLE 的 partition table
  - 建立以 partition key 欄位為依據的 INDEX, 雖然非必須, 但是多數情境下是十分有效的
- _補_, 參考文件:
  - 1 SQL Commands, CREATE TABLE
  - 2 Chapter 5. Data Definition, 5.12. Table Partitioning
- ```sql
  CREATE TABLE sales (
    sale_id SERIAL NOT NULL,
    cust_id INTEGER NOT NULL,
    store_id INTEGER NOT NULL,
    sale_date DATE NOT NULL,
    amount NUMERIC (9, 2)
  ) PARTITION BY RANGE (sale_date);

  CREATE INDEX ON sales (sale_date);

  CREATE TABLE sales_s1 PARTITION OF sales FOR VALUES FROM (MINVALUE) TO ('2020-02-01');
  CREATE TABLE sales_s2 PARTITION OF sales FOR VALUES FROM ('2020-02-01') TO ('2020-03-01');
  CREATE TABLE sales_s3 PARTITION OF sales FOR VALUES FROM ('2020-03-01') TO ('2020-04-01');
  CREATE TABLE sales_s4 PARTITION OF sales FOR VALUES FROM ('2020-04-01') TO ('2020-05-01');
  CREATE TABLE sales_s5 PARTITION OF sales FOR VALUES FROM ('2020-05-01') TO ('2020-06-01');
  CREATE TABLE sales_s999 PARTITION OF sales FOR VALUES FROM ('2020-06-01') TO (MAXVALUE);
  ```

- MySQL 範例: 查詢 table 的 partition 狀態 (metadata)
  - _補_, `information_schema.partitions` 屬於 MySQL 專有的 table
- ```sql
  SELECT partition_name, partition_method, partition_expression
  FROM information_schema.partitions
  WHERE table_name = 'sales'
  ORDER BY partition_ordinal_position;
  ```
- PostgreSQL 範例: 查詢 table 的 partitions 狀態 (metadata)
  - 使用 `pg_partitioned_table`, `pg_inherits` table 查詢相關的 metadata
  - 或者在互動介面使用 `\d+` 查詢 TABLE
- MySQL 範例: 修改分割區進行擴充
  - MySQL 中以 `ALTER TABLE` 與 `REORGANIZE PARTITION` 來修改現有的 PARTITION 並進行擴充
  - _補_, PostgreSQL 中並沒有 `REORGANIZE PARTITION` 語法可以直接進行修改
- ```sql
  ALTER TABLE sales REORGANIZE PARTITION s999 INTO (
    PARTITION s6 VALUES LESS THAN (202007),
    PARTITION s7 VALUES LESS THAN (202008),
    PARTITION s999 VALUES LESS THAN (MAXVALUE)
  );
  ```
- PostgreSQL 範例: 修改分割區進行擴充
  - 需要手動的對 parent table 與 partition table 進行操作
  - 包含 DETACH PARTITION, 建立新的 PARTITION, 把舊的資料傳進新的 PARTITION, 移除不再使用的 TABLE
- ```sql
  /* DETACH the partition table */
  ALTER TABLE sales DETACH PARTITION sales_s999;

  /* rename old partition TABLE */
  ALTER TABLE sales_s999 RENAME TO sales_s999_old;

  /* CREATE new partition tables */
  CREATE TABLE sales_s6 PARTITION OF sales FOR VALUES FROM ('2020-06-01') TO ('2020-07-01');
  CREATE TABLE sales_s7 PARTITION OF sales FOR VALUES FROM ('2020-07-01') TO ('2020-08-01');
  CREATE TABLE sales_s999 PARTITION OF sales FOR VALUES FROM ('2020-08-01') TO (MAXVALUE);

  /* INSERT old values INTO */
  INSERT INTO sales SELECT * FROM sales_s999_old;

  /* DROP unused TABLE */
  DROP TABLE sales_s999_old;
  ```

- MySQL 範例: 列出個別 partition 所擁有的資料數量
  - `FROM ... PARTITION()` 語法, 屬於 MySQL 專有
- ```sql
  SELECT concat('# of rows in S1 = ', count(*)) partition_rowcount
  FROM sales PARTITION (s1) UNION ALL
  SELECT concat('# of rows in S2 = ', count(*)) partition_rowcount
  FROM sales PARTITION (s2);
  ```

- PostgreSQL 範例: 列出個別 partition 所擁有的資料數量
  - 屬於較為資料庫管理需求的指令, 而非一般使用者會進行的操作
  - PostgreSQL 中 PARTITION TABLE 就等於一般的 TABLE 一樣可以直接操作
  - PostgreSQL 中也有專屬的系統管理函式可以協助列出所有的 partition table, `pg_partition_tree()`
  - 與 `pg_class` table 進行 JOIN 取得 table metadata
- ```sql
  /* ANALYZE update the metadata of sales TABLE */
  ANALYZE sales;

  SELECT p.relid partition_name,
    c.reltuples partition_rowcount
  FROM pg_partition_tree('sales') p
    INNER JOIN pg_class c
    ON p.relid = c.oid::regclass
  WHERE p.isleaf IS TRUE;
  ```

清單分割法 (list partitioning)

- 如果資料是具有可枚舉性 (enumerated) 的時候, 就可以考慮使用 list partitioning
  - 例如: 美國州代號 (CA, TX, VA, ...), 或類似貨幣簡寫 (USD, EUR, JPY, ...)
- PostgreSQL 範例: 把 sales TABLE 中的資料依照地理區域分組
  - 假設 sales TABLE 中具有 geo_region_cd 欄位可以用來進行 list partitioning
  - 假設 geo_region_cd 欄位的資料為, US_NE, US_SE, CAN, MEX, EUR_E, ...
- ```sql
  CREATE TABLE sales (
    sale_id SERIAL NOT NULL,
    cust_id INTEGER NOT NULL,
    store_id INTEGER NOT NULL,
    sale_date DATE NOT NULL,
    geo_region_cd VARCHAR(6) NOT NULL,
    amount NUMERIC (9, 2)
  ) PARTITION BY LIST (geo_region_cd);

  CREATE INDEX ON sales (geo_region_cd);

  CREATE TABLE sales_northamerica PARTITION OF sales FOR VALUES IN ('US_NE', 'US_SE', 'US_MW', 'NS_NW', 'US_SW', 'CAN', 'MEX');
  CREATE TABLE sales_europe PARTITION OF sales FOR VALUES IN ('EUR_E', 'EUR_W');
  CREATE TABLE sales_asia PARTITION OF sales FOR VALUES IN ('CHN', 'JPN', 'IND');
  ```

- PostgreSQL 範例: 增加的資料不符合 PARTITION 時, 會丟出錯誤訊息
  - `ERROR:  no partition of relation "sales" found for row`
  - `DETAIL:  Partition key of the failing row contains (geo_region_cd) = (KOR).`
- ```sql
  INSERT INTO sales (cust_id, store_id, sale_date, geo_region_cd, amount)
  VALUES (6, 27, '2020-03-11', 'KOR', 4267.12);
  ```
- MySQL 範例: 修改 PARTITION LIST 中的值
  - `REORGANIZE PARTITION` 屬於 MySQL 專屬語法
- ```sql
  ALTER TABLE sales REORGANIZE PARTITION ASIA INTO
  (PARTITION ASIA VALUES IN ('CHN', 'JPN', 'IND', 'KOR'));
  ```
- PostgreSQL 範例: 修改 PARTITION LIST 中的值
  - 並沒有像是 MySQL 中的 `REORGANIZE PARTITION` 語法直接擴充定義
  - 而是需要手動的重建 PARTITION
- ```sql
  /* DETACH PARITION */
  ALTER TABLE sales DETACH PARTITION sales_asia;

  /* RENAME old partition table */
  ALTER TABLE sales_asia RENAME TO sales_asia_old;

  /* CREATE the same name new partition with extends values */
  CREATE TABLE sales_asia PARTITION OF sales FOR VALUES IN ('CHN', 'JPN', 'IND', 'KOR');

  /* INSERT old values INTO table */
  INSERT INTO sales SELECT * FROM sales_asia_old;

  /* DROP old partition table */
  DROP TABLE sales_asia_old;
  ```

- MySQL 範例: 通過 `information_schema.partitions` 查看 partition 定義的 metadata
  - `information_schema.partitions` 這個 metadata table 屬於 MySQL 專有
- ```sql
  SELECT partition_name, partition_expression, partition_description
  FROM information_schema.partitions
  WHERE table_name = 'sales'
  ORDER BY partition_ordinal_position;
  ```
- PostgreSQL 範例: 取得 TABLE 的 PARTITION 定義
  - 最簡單的方式是在 `psql` 中使用 `\d+` 來查詢
  - 不然就是需要通過 `pg_inherits`, `pg_class` 偏向系統管理的專用 table 來查詢
  - 參考文件: Chapter 52. System Catalogs, 52.11. pg_class
  - 參考文件: 9.27. System Information Functions and Operators
- ```sql
  /* ANALYZE update the metadata of sales TABLE */
  ANALYZE sales;

  SELECT p.relid partition_name,
    c.reltuples partition_rowcount,
    pg_get_expr(c.relpartbound, c.oid) partition_description
  FROM pg_partition_tree('sales') p
    INNER JOIN pg_class c
    ON p.relid = c.oid::regclass
  WHERE p.isleaf IS TRUE;
  ```

- _補_, 可以為 LIST PARTITION 添加一個 DEFAULT PARTITION

雜湊分割法 (hash partitioning)

- 如果選做 partition key 的欄位, 不適用 range partitioning 或 list partitioning
- 還有一個內建的第三種方法, 可以通過 hashing function 來把資料值分割成不同的 partitition
  - 即雜湊分割法 (hash partitioning)
- 與 list partitioning 主要的差異在於 list partition 的可能值, 是可枚舉且有限的
  - 而雜受分割法適合用於大量不同的值
- PostgreSQL 範例: 以 cust_id 欄位作為 partition key 用於 hash partitioning
  - _補_, 從結果來觀察 hash partitioning 的 hash function 並不是單純的以 `%` 來進行的
- ```sql
  CREATE TABLE sales (
    sale_id SERIAL NOT NULL,
    cust_id INTEGER NOT NULL,
    store_id INTEGER NOT NULL,
    sale_date DATE NOT NULL,
    amount NUMERIC(9, 2)
  ) PARTITION BY HASH (cust_id);

  CREATE TABLE sales_0 PARTITION OF sales FOR VALUES WITH (MODULUS 4, REMAINDER 0);
  CREATE TABLE sales_1 PARTITION OF sales FOR VALUES WITH (MODULUS 4, REMAINDER 1);
  CREATE TABLE sales_2 PARTITION OF sales FOR VALUES WITH (MODULUS 4, REMAINDER 2);
  CREATE TABLE sales_3 PARTITION OF sales FOR VALUES WITH (MODULUS 4, REMAINDER 3);
  ```

複合式分割法 (composite partitioning)

- 複合式分割法, 代表使用子分割區 (subpartition) 與此同時子分割區可以使用與上層分割區不同的分割方式
- PostgreSQL 範例: 對 sales table 同時使用範圍分割與雜湊分割
  - _補_, PostgreSQL 建立 PARTITION 的語法都與 MySQL 不同, 建立 PARTITION 時最好參照各家資料庫系統文件
- ```sql
  CREATE TABLE sales (
    sale_id SERIAL NOT NULL,
    cust_id INTEGER NOT NULL,
    store_id INTEGER NOT NULL,
    sale_date DATE NOT NULL,
    amount NUMERIC(9, 2)
  ) PARTITION BY RANGE ((EXTRACT(ISOYEAR FROM sale_date) * 100 + EXTRACT(WEEK FROM sale_date)));

  CREATE TABLE sales_before_202002 PARTITION OF sales
  FOR VALUES FROM (MINVALUE) TO (202002)
  PARTITION BY HASH (cust_id);

  CREATE TABLE sales_before_202002_h0 PARTITION OF sales_before_202002 FOR VALUES WITH (MODULUS 4, REMAINDER 0);
  CREATE TABLE sales_before_202002_h1 PARTITION OF sales_before_202002 FOR VALUES WITH (MODULUS 4, REMAINDER 1);
  CREATE TABLE sales_before_202002_h2 PARTITION OF sales_before_202002 FOR VALUES WITH (MODULUS 4, REMAINDER 2);
  CREATE TABLE sales_before_202002_h3 PARTITION OF sales_before_202002 FOR VALUES WITH (MODULUS 4, REMAINDER 3);

  CREATE TABLE sales_202002 PARTITION OF sales
  FOR VALUES FROM (202002) TO (202003)
  PARTITION BY HASH (cust_id);

  CREATE TABLE sales_202002_h0 PARTITION OF sales_202002 FOR VALUES WITH (MODULUS 4, REMAINDER 0);
  CREATE TABLE sales_202002_h1 PARTITION OF sales_202002 FOR VALUES WITH (MODULUS 4, REMAINDER 1);
  CREATE TABLE sales_202002_h2 PARTITION OF sales_202002 FOR VALUES WITH (MODULUS 4, REMAINDER 2);
  CREATE TABLE sales_202002_h3 PARTITION OF sales_202002 FOR VALUES WITH (MODULUS 4, REMAINDER 3);

  CREATE TABLE sales_202003 PARTITION OF sales
  FOR VALUES FROM (202003) TO (202004)
  PARTITION BY HASH (cust_id);

  CREATE TABLE sales_202003_h0 PARTITION OF sales_202003 FOR VALUES WITH (MODULUS 4, REMAINDER 0);
  CREATE TABLE sales_202003_h1 PARTITION OF sales_202003 FOR VALUES WITH (MODULUS 4, REMAINDER 1);
  CREATE TABLE sales_202003_h2 PARTITION OF sales_202003 FOR VALUES WITH (MODULUS 4, REMAINDER 2);
  CREATE TABLE sales_202003_h3 PARTITION OF sales_202003 FOR VALUES WITH (MODULUS 4, REMAINDER 3);

  CREATE TABLE sales_after_202003 PARTITION OF sales
  FOR VALUES FROM (202004) TO (MAXVALUE)
  PARTITION BY HASH (cust_id);

  CREATE TABLE sales_after_202003_h0 PARTITION OF sales_after_202003 FOR VALUES WITH (MODULUS 4, REMAINDER 0);
  CREATE TABLE sales_after_202003_h1 PARTITION OF sales_after_202003 FOR VALUES WITH (MODULUS 4, REMAINDER 1);
  CREATE TABLE sales_after_202003_h2 PARTITION OF sales_after_202003 FOR VALUES WITH (MODULUS 4, REMAINDER 2);
  CREATE TABLE sales_after_202003_h3 PARTITION OF sales_after_202003 FOR VALUES WITH (MODULUS 4, REMAINDER 3);

  INSERT INTO sales (cust_id, store_id, sale_date, amount) VALUES
  (1, 1, '2020-01-18', 1.1),
  (17, 5, '2020-01-19', 1.3),
  (56, 1, '2020-01-20', 1.6),
  (122, 4, '2020-01-21', 1.8),
  (179, 5, '2020-01-22', 2.0),
  (263, 1, '2020-01-23', 2.2),
  (346, 2, '2020-01-24', 2.4),
  (472, 1, '2020-01-25', 2.6),
  (3, 4, '2020-02-07', 1.2),
  (23, 2, '2020-02-08', 1.4),
  (77, 5, '2020-02-09', 1.7),
  (153, 1, '2020-02-10', 1.9),
  (244, 2, '2020-02-11', 2.1),
  (312, 4, '2020-02-12', 2.3),
  (389, 3, '2020-02-13', 2.5),
  (502, 1, '2020-02-14', 2.7);
  ```

分割的好處

- 最主要的好處是在設計得當的時候, 可以只與少數分割區互動, 而不需要涉及整個資料表
  - 減少所互動的資料量, 以提升效能
- 當所運行的 SQL 敘述中有涉及到與分割區相同的過濾條件時,
  - 資料庫系統就會進行分區修剪 (partition pruning), 這是使用分割最大的好處
- 當運行的資料在 JOIN 時, 涉及到分割區的過濾條件時
  - 資料庫系統會進行分割式結合 (partitionwise joins)
- 從管理資料庫的角度來看, 分割區的另一個好處是可以迅速地刪除不需要的資料
  - 直接以分割區為單位, 進行備份和刪除
- 凡事分割過的資料表需要更新時, 可以同時對多個分割區進行, 以大幅減少運行時間
  - _補_, 需要參考文件來判斷, 運行的 SQL 語法是什麼, 以及是否需要 lock 以及何種 lock
  - _補_, PostgreSQL 中有分成 `ACCESS EXCLUSIVE` lock 會鎖定 parent table 和 `SHARE UPDATE EXCLUSIVE` lock 對 parent talbe 限制較少, 不同層級的 lock
  - _補_, 在適當的時機應該使用 lock 層級較小的操作, 例如 `DETACH CONCURRENTLY` 取代直接 `DROP` TABLE 或單純的 `DETACH` (因為 lock 而昂貴的操作), 等到適當的時機才進行昂貴的操作
- _補_, PostgreSQL
  - 通過 `SHOW enable_partition_pruning;` 查看 partition pruning 功能是否開啟, 預設是開啟的
  - 使用 `EXPLAIN` 可以查看 SQL 敘述的執行計劃, 並且看到預計參與的 table, 由此判斷是否有進行 partition pruning
  - Partition pruning 不只作用於 planning 時期, 也運作於 execution 時期
- _補_, PostgreSQL 官方文件裡的 Best Practices for Declarative Partitioning
  - 使用 Partitioning 的時候必須審慎思考, 否則可能對效能造成負面效果
  - 思考 1 要對哪個或哪些 columns 作為 partition key, 判斷方式為平時**最常用於 WHERE 敘述中的欄位**
    - 另一個考量點是資料管理層面, 哪些資料可能會需要大規模的刪除以及如何切分, Partition 可以很有效率的進行 DETACH 與 DROP
  - 思考 2 要切分成幾份 partition,
    - 如果數量太少, 則單一個 partition 資料仍然太多造成 Index 效能變差和 cache hit ratios 變差
    - 如果數量太多, 則造成 planning 的時間過長和在 planning 與 execution 時額外的記憶體使用過多
    - 要思考的是資料在未來會如何成長, 來決定分割的 partition key, partition 方式
    - sub-partitioning 也是在未來切割變大的 partition 時可以使用的方法之一, 但是必須克制, 否則 partition 的數量會大規模上升
  - 思考 3 考量到 Partitioning 對 planning 與 executiong 時的額外消耗
    - 大量的 partition 會造成效能變差, 以及大量的記憶體消耗, 尤其是當有多個 sessions 同時觸碰到多個 partitions 時
    - 因為每個 partition 都有單獨一個自己的 metadata 要進行管理, 在運行時需要被載入記憶體中
    - 並且因為 partition 產生大量的 lock 會造成嚴重的效能影響, (對於 index 的 lock, 對於 row 的 lock, ...)
  - 思考 4 資料庫的使用情境, 如果是對於資料倉儲的使用情境而言, 可以稍微放寬對 partition 數量的要求
    - 重要的是需要提早思考且做出正確的決定, 因為對大量的資料進行 re-partitioning 會是一個極度耗時的操作
  - 思考 5 重要的是不能預設更多的 partition 就是更好的效能, 反之亦然
- _補_, PostgreSQL
  - `pg_locks` table
  - lock `fastpath` 能快速運行的 lock 操作
  - 小心 long transaction 操作, 應該盡可能的快速進行 commit 以減少 lock 的佔用導致影響到整個資料庫的反應時間

叢集 (clustering)

- 讓數台伺服器如同單一資料庫一般的運作
- 叢集架構有許多種變化, 擁有不同的能力與應對的方式
- 商用資料庫廠商: Oracle 是其中的佼佼者
- 超大型的企業需求 (Google, Facebook, Amazon, ...), 則需要另尋出路

切片 (sharding)

- 當需求不斷變大的時候, 單一資料庫伺服器難以承受時
- 不僅僅是個別的資料表需要分割, 連整個資料庫都需要進行分割 (sharding)
  - 類似於資料表的分割, 但是規模更大也更複雜
- 將資料分割 (sharding) 之後配置給數個資料庫 (切片, shards)
- Sharding 是一個相當複雜的題目, 本書沒有過多深入, 只列出一些重要的問題
  - _補_, 屬於使用關聯式資料庫最終會走向的解決方案
- 1 必須選出一個 sharding key, 決定要連結哪一個資料庫的值
- 2 當大型資料庫被分成多個片段時, 個別的資料列會被分給單一的切片
  - 而較小的參考用資料表可能會被**複製**到所有的切片中
  - 因此需要制定如何修改參考用資料表以及如何把更動的內容傳到所有切片中
- 3 當出現某些切片也變得過大時, 就必須再次進行分割, 添加新的切片, 並且把資料重新分配
- 4 當需要更動架構時, 必須有一套異動部署到各個分片的機制, 才能維持資料庫架構在各個分片上保持一致
- 5 當應用程式邏輯需要進行跨分片的查詢, 甚至是進行交易 (transaction) 時, 需要如何進行的策略

大數據 (big data)

- 有別於關聯式資料庫的解決方案
- 主要由大型公司 (Amazon, Google, Facebook, Twitter, ...) 提出的解決方案
- 三個 V
  - Volume 數量, 達到十億甚至數萬億級別
  - Velocity 速度, 資料累積的速度
  - Variety 變化, 資料並非常見的結構化資料, 而可能是非結構化的, 例如: 電子郵件, 影片, 相片, 聲音檔案, ...
- 以下列出這幾年來發展出來的大數據處理技術

Hadoop

- 一套完整的 ecosystem, 主要成員有
- Hadoop 分散式檔案系統 (Hadoop Distributed File System, HDFS)
  - 進行跨大量伺服器的檔案系統管理
- MapReduce
  - 將運算工作打散至不同的伺服器同時運算的解決方案
- YARN
  - 對 HDFS 進行資源管理與作業排程的工具
- 與此相關的 SQL 介面, Hive, Impala, Drill, ...

NoSQL 與文件型資料庫

- 在關聯式資料庫中, 資料必須符合事先定義的架構
- 為了因應無法事前得知資料結構, 或者是資料架構會經常更動
- 把架構定義與資料本身變成一種檔案, 即 XML 或 JSON 這類的檔案格式
- 讓資料庫直接儲存檔案文件
  - 優點是可以輕易容納和變更各種不同的資料架構
  - 缺點是查詢與分析工具的困難, 變得必須先剖析文件
- NoSQL, 常以 key-value pair 的形式儲存資料
- 例如: MongoDB, 可以以 customer ID 為 key 對應一份 JSON 資料為 value

雲端運算

- 在過去大多數企業都需要自行建置資料中心
- 在雲端運算之後, 基本上可以把整個資料中心交給雲端平台託管, 像是 Amazon Web Servies (AWS), Mircosoft Azure, Google Cloud, ...
- 雲端平台的優點在於易於擴充, 可以迅速地上調或下調運算能力
- 初創業者可以專注於程式碼的開發上, 而不必先花大錢建置伺服器等等硬體與軟體設備
- 在 AWS 中關於資料庫相關的服務就有許多個
- 關聯式資料庫 ( MySQL, Aurora, PostgreSQL, MariaDB, Oracle 和 SQL Server )
- 記憶體型資料庫 ( ElasticCache )
- 資料倉儲型資料庫 ( Redshift )
- NoSQL 資料庫 ( DynamoDB )
- 文件型資料庫 ( DocumentDB )
- 圖形資料庫 ( Neptune )
- 時序型資料庫 ( TimeStream )
- Hadoop ( EMR )
- 資料湖泊 ( Data lakes ) ( Lake Formation )
- 現在更多的企業混合使用各種平台, 關聯式資料庫的受歡迎程度則有所增減

結論

- 資料庫越變越大, 與此同時, 儲存, 叢集, 分割等技術也越來越成熟
- 無論是何種平台, 大量資料的操作都相當具有挑戰性

---

### 第十八章 - SQL 與大數據

- 雖然說關聯式資料庫的逐漸被其他解決方案取代
- 但是 SQL 仍然是許多人使用並且深入進程式碼中
- 因此出現了一些解決方案來使用 SQL 去存取其他類型的資料庫
  - 例如: Presto, Apache Drill, 和 Toad Data Point, ...
- 本章節使用 Apache Drill 為例作為示範

Apache Drill 簡介

- 已經開發出大量的工具與介面, 例如以 SQL 存取 Hadoop, NoSQL, Spark, 等等雲端分散式檔案系統
  - 例如 Hive 用來讓使用者存取 Hadoop
  - Spark SQL 則是一套函式庫用來存取 Spark 中的資料
- 開放原始碼的 Apache Drill 則是在 2015 年問世, 具有一些特色
  - 可跨多種資料格式進行查詢, 包括 CSV, JSON, Parquet 和 log 檔案
  - 可連結關聯式資料庫, Hadoop, NoSQL, HBase 和 Kafka, 以及特殊資料格式 (例如: PCAP, 區塊鏈, ...)
  - 可以自訂外掛程式, 來連接任何其他資料來源
  - 無需事先定義架構
  - 支援 SQL:2003 標準
  - 可搭配常見的 (Business Intelligence, BI) 工具, 例如: Tableau 和 Apache Superset
- 可以透過 Drill 連接任意資料來源, 並且展開查詢, 無需設置 metadata repostiroy

以 Drill 查詢檔案

以 Drill 查詢 MySQL

以 Drill 查詢 MongoDB

具有多重資料來源的 Drill

- 使用 Drill 以 SQL 語法去同時操作多個不同的資料來源

SQL 未來的展望

- 大數據技術逐漸成熟, 各種不同的資料庫再慢慢瓜分掉關聯式資料庫的市占率
- SQL 語言本身卻可以以抽象層的方式, 被用於跨資料庫平台的操作
  - SQL 語言本身還是主要的資料分析與報表工具

---

342
