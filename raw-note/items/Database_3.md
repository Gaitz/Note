## PostgreSQL 18.0 Documentation

### [PostgreSQL 18.0 Documentation](https://www.postgresql.org/docs/current/index.html), ComputerScience/Database

---

第一章 - Preface

第二章 - I. Tutorial

第三章 - II. The SQL Language

第四章 - III. Server Administration

第五章 - IV. Client Interfaces

第六章 - V. Server Programming

第七章 - VI. Reference

第八章 - VII. Internals

第九章 - VIII. Appendixes

第十章 - Bibliography

---

第一章 - Preface

1 What Is PostgreSQL?

- open-source project

2 A Brief History of PostgreSQL

3 Conventions

4 Further Information

- [Postgres wiki](https://wiki.postgresql.org/wiki/Main_Page)
- [Postgres web site](https://www.postgresql.org/)
- Mailing lists
- Yourself, 開源的

5 Bug Reporting Guidelines

- Identifying bugs
- What to report
- Where to report bugs

---

第二章 - I. Tutorial

- 官方提供的 tutorial
- 介紹 PostgreSQL, relational database concepts, SQL language
- 提供可操作的練習

---

1 Getting Started

---

1.1 Installation

- From source code

---

1.2 Architectural Fundamentals

- Postgresql 使用 client/server model
- Server process, `postgres` program
  - 負責管理資料庫本身
  - 管理 connections
- Client (frontend)
  - 客戶端非常多元, 可以是任何型態
  - 客戶端請求資料庫去進行操作
- 就像傳統的 client/server model 一樣
  - client 與 server 可以屬於不同的 host
  - 底層通過 TCP/IP 進行溝通
- PostgreSQL server
  - 可以同時處理多個 connection ( multiple concurrent connections )
  - **forks**

---

1.3 Creating a Database

- _補_,
  - 需要先啟動 postgreSQL server (service)
  - 取決於安裝方式
  - 可以通過 postgresql bin 底下提供的 `pg_ctl` 來啟動
  - 或者使用 `brew services start` 啟動
- `createdb` 指令, postgreSQL 安裝目錄下的 bin 中
  - 建立新的資料庫
  - 此指令是 SQL 命令 `CREATE DATABASE` 的 wrapper
  - _補_, 可以使用把 bin 目錄加到 PATH 環境變數中, 讓 shell 可以在任意位置執行
- `createdb` 正常執行不會有回傳值,
- 可能會遇到的問題
  - 1 server 沒有啟動
  - 2 下命令的使用者並非 PostgreSQL user 需要由系統管理員增加 PostgreSQL user account
    - postgreSQL user 與 OS user 不同
    - 預設是相同的, 但是允許使用不同名稱, 用指定方式登入
  - 3 PostgreSQL user 的使用者權限不足, 無法執行 `createdb`
- Database naming convention
  - 通常會與 user name 一致, 直接執行 `createdb` 不加參數會預設 database 名稱為使用者名稱
- `dropdb` 指令
  - 移除存在的資料庫
  - 這個指令沒有預設的名稱設定, 需要指定
  - **這個指令無法被 undo 需小心使用**
  - 此指令是 SQL 命令 `DROP DATABASE` 的 wrapper
- _補_, 相關的環境變數
  - `PGHOST`, server host
  - `PGPORT`, service port number
  - `PGUSER`, postgreSQL user name
  - `PGDATABASE`, database name
  - `PGDATA`, 指定檔案資料夾位置
- _補_,
  - `initdb`, 屬於安裝流程的一部分, 用來初始化儲存位置的檔案結構
  - `createdb`, 用於建立新的資料庫

---

1.4 Accessing a Database

- 與 database server 互動的常見方式
  - 1 command line 交互式的 `psql` 介面
  - 2 使用圖形化介面, `pgAdmin` 或者其他的 GUI
  - 3 使用客製化的程式與 server 互動
- 這個 tutorial 中都使用 `psql` 進行互動
- `psql [database_name]` 進入交互式界面
  - 不指定 database 名稱時, 預設是 OS user name
- 進入 `psql` 交互界面後
  - 提示字元如果是 `=#` 代表是 superuser, 一般使用者是 `=>`
  - superuser 意味著不會受到權限控制
  - 1 使用 SQL command 互動
  - 2 使用 `psql` 內建命令互動, 以 `\` 開頭的命令, 例如 `\help`, `\?`, `\h`, ...
- SQL 命令
  - 大小寫有別, `;` 是必須的
  - `SELECT version();`, 取得 PostgreSQL 版本資訊
  - `SELECT current_date;`, 取得當日日期

---

2 The SQL Language

---

2.1 Introduction

- tutorial 的範例程式碼, 可以在 PostgreSQL source code repo 底下的 /src/tutorial 找到
  - 執行 `make` 去生成 scripts 與生成 user-defined functions and types
- `psql -s` 以 single step mode 執行
  - 此時每個命令執行之前會先暫停
  - 常用於 debug SQL script 的執行
- psql 介面下的指令 `\i` 執行外部檔案
  - `\i [...].sql` 例如執行外部檔案的 sql 腳本

---

2.2 Concepts

- PostgreSQL 是一個 relational database management system (RDBMS)
- RDBMS
  - 一個系統 (system) 用來管理存在 **relations** 中的資料
  - **Relation** 是對於表示 `table` 的數學名詞
- 除了 RDBMS 以 relations 概念之外, 管理資料的方式有很多種
  - 例如: Unix-like OS 的檔案系統 (hierarchical database)
  - 例如: 更現代的 object-oriented database
  - ...
- 每個 `table` 是 rows 的組合
- 在相同的 `table` 下的每個 `row` 具有相同集合的 columns
- 每個 `column` 是一個特定的資料型別 (data type)
- 與此同時 `column` 在 `row` 中的順序是固定的 (fixed order)
  - 需要記住的是 !! **SQL 不保證 rows 在 table 中的順序** !!
- `Tables` 集群成為 `databases`
  - 而 databases 由 a single PostgreSQL server instance 所管理
  - 被稱為 a database `cluster`

---

2.3 Creating a New Table

`CREATE TABLE`

- 建立一個新的 table 指定 table name 與所有的 column names 與相對應的資料型別 (types)
- `psql` 可以輸入指令並且使用斷行, 直到出現 `;` 才代表一句命令結束
- SQL 中 white spaces (spaces, tabs, and newlines) 的使用沒有限制
  - 結構並非命令的規則, 可以任意排版
- `--` 代表 comments
- SQL 中對於 keywords and identifiers 的認定是 case-insensitive (不分大小寫)
  - 對於 identifiers 使用 `"` 包裹會保證 case

Example 1

- ```sql
  CREATE TABLE weather (
      city            varchar(80),
      temp_lo         int,           -- low temperature
      temp_hi         int,           -- high temperature
      prcp            real,          -- precipitation
      date            date
  );
  ```

Types

- `varchar(80)`, 指定這個 data type 是可以儲存上限最多 80 個字元的字串
- `int` 代表 integer
- `real` 代表單精度的浮點數 single precision floating-point numbers
- `date` 代表 date

standard SQL types

- `int`, `smallint`
- `real`, `double precision`
- `char(N)`, `varchar(N)`
- `date`, `time`, `timestamp`
- `interval`
- ...

PostgreSQL types

- 除了支援 standard SQL types 之外
- 可以自定義型別 user-defined data types

Example 2

- ```sql
  CREATE TABLE cities (
      name            varchar(80),
      location        point
  );
  ```
- `point` 屬於 PostgreSQL-specific data type
- 儲存 geographical location

`DROP`

- 移除一個現有的 table
- `DROP TABLE tablename;`

Tutorial

- 以上程式碼可以在 `basic.sql` 範例中找到並且執行

---

2.4 Populating a Table With Rows

`INSERT`

- 用於在 table 中加入新的 rows
- `INSERT INTO weather VALUES ('San Francisco', 46, 50, 0.25, '1994-11-27');`
- 對應的 data types 的輸入值格式通常是顯而易見的,
- 如果不是常見的格式, 則使用 `'` 包裹來表明
- 對於 `date` 的輸入格式則十分有彈性, _補_, 在使用前可以查詢一下規則
- `INSERT INTO cities VALUES ('San Francisco', '(-194.0, 53.0)');`
  - 對於 PostgreSQL-specific 的 `point` data type 需要以 a coordinate pair 作為輸入格式
- 以上兩種的 `INSERT` 命令需要你記住並且符合 column order

另一種語法格式

- ```sql
  INSERT INTO weather (city, temp_lo, temp_hi, prcp, date)
      VALUES ('San Francisco', 43, 57, 0.0, '1994-11-29');
  ```
- 指定要輸入的 column name 時, 就不需要符合原本的 column order
- 甚至不需要所有的 column 都必須包含
- ```sql
  INSERT INTO weather (date, city, temp_hi, temp_lo)
    VALUES ('1994-11-29', 'Hayward', 54, 37);
  ```
- 以上例子遺漏 `prcp` 欄位

Convention

- 多數開發者認為使用 explicitly listing 是比較好的方式

`COPY`

- 以純文字檔案 (flat-text files) 輸入大量的資料
- 通常速度較快, 因為 `COPY` 語法經過最佳化, 但是比起 `INSERT` 更沒有彈性
- `COPY weather FROM '/home/user/weather.txt';`
- 然而, 這個要求純文字檔案是存在 server 上的
- 因為 database server process 會直接去讀取
- 範例 weather.txt 的檔案內容如下, 以 `tab` 進行區隔
- ```
  San Francisco    46    50    0.25    1994-11-27
  San Francisco    43    57    0.0    1994-11-29
  Hayward    37    54    \N    1994-11-29
  ```

Tutorial

- 以上程式碼可以在 `basic.sql` 範例中找到並且執行

---

2.5 Querying a Table

`SELECT`

- 從 table 中讀取檔案 (queried)
- 通常使用 `SELECT` 語法
- `SELECT` 語法中主要分成三個部分
  - 1 表明需要哪些 columns, (a select list)
  - 2 表明哪些 table, (a table list)
  - 3 選擇的條件, 限制條件, (an optional qualification)
- `SELECT * FROM weather;`
  - `*` 代表 for all columns
  - 在這個範例中等價於 `SELECT city, temp_lo, temp_hi, prcp, date FROM weather;`

`SELECT` + expressions

- 以 expression 取代單純的 column reference
- `SELECT city, (temp_hi+temp_lo)/2 AS temp_avg, date FROM weather;`
- `AS` 是選用的, 用來重新命名輸出的 column name

`SELECT` + `WHERE`

- 使用 `WHERE` 來搜尋指定的 rows
- `WHERE` 包含一個 boolean expression
  - 只回傳 boolean expression 為 true 的 rows
- 可以使用 boolean operators `AND`, `OR`, `NOT` 來協助撰寫邏輯
- ```sql
  SELECT * FROM weather
      WHERE city = 'San Francisco' AND prcp > 0.0;
  ```

`ORDER BY`

- 控制回傳結果的順序
- ```sql
  SELECT * FROM weather
      ORDER BY city;
  ```
- ```sql
  SELECT * FROM weather
      ORDER BY city, temp_lo;
  ```

`DISTINCT`

- `SELECT DISTINCT`
- 去除重複的結果
- ```sql
  SELECT DISTINCT city
      FROM weather;
  ```
- 與 `ORDER BY` 一起使用, 保證輸出結果順序
- ```sql
  SELECT DISTINCT city
      FROM weather
      ORDER BY city;
  ```

Conventions

- `SELECT *` 通常作為一般方便的搜尋使用
  - 在 production code 中被廣泛的視為是一種 bad style
  - 因為之後增加的 column 會改變 query 的結果, 讓搜尋結果產生一種不確定性

Warning

- 在一些資料庫實作中, 包含舊版的 PostgreSQL,
  - 使用 `DISTINCT` 的輸出結果會自動 ordered
  - 換句話說, `ORDER BY` 是不必要的
  - !! 但是這並非是 SQL 標準的行為, 並且新版的 PostgreSQL 並不保證 `DISTINCT` 結果的有序性 !!

Tutorial

- 以上程式碼可以在 `basic.sql` 範例中找到並且執行

---

2.6 Joins Between Tables

---

3 Advanced Features

---

第三章 - II. The SQL Language

---

第四章 - III. Server Administration

---

第五章 - IV. Client Interfaces

---

第六章 - V. Server Programming

---

第七章 - VI. Reference

---

第八章 - VII. Internals

---

第九章 - VIII. Appendixes

---

第十章 - Bibliography
