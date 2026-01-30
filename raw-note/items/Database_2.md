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

- `WHERE` 子句, 針對 rows 進行篩選
- `filter conditions
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
  - 不排除重複的值
- 預設是會排除重複的值, _補_, 概念上等同於在最終的結果集合上加上 DISTINCT 運算

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
