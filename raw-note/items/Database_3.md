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
- _補_,
  - `psql -l` list all available databases
  - `\d`, 列出所有的 tables (display)
  - `\d [table_name]`, 列出指定的 table column 定義
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

`JOIN ON`

- 多個 table 一起搜尋, 或者針對同一個 table 一次搜尋多次
- 這項技術被稱為 `join`
- 組合不同 table instances 的 rows, 通過 expression 指定他們如何配對
- 範例: `SELECT * FROM weather JOIN cities ON city = name;`
  - 想要同時顯示都市的氣候和都市位置資訊, 這些內容存在兩個 table 中, weather table 與 cities table
  - 藉由 join 兩個 table, 而連結的方式是藉由 weather table 中的 name 與 cities table 中的 city 欄位
- 這種 join 方式 (**inner join**) 只會取得完全符合的結果, 交集 (intersection) 的部分
  - 換句話說, 如果 weather table 中存在資料, 但是 cities table 沒有資料的城市, 則不會顯示其 weather 資訊
- 因為每個 column name 只有在自己的 table 內是唯一的, 因此在 join 時可能會產生 column name 相同的情況, 會分不清楚所屬
  - 需要藉由 table 作為指名 `table.column`

`FROM WHERE`

- 上面這種類型的 `JOIN`/`ON` 模式可以被改寫成, 範例:
- ```sql
  SELECT *
      FROM weather, cities
      WHERE city = name;
  ```
- 這種語法比 `JOIN`/`ON` 更早出現
- 簡單地將所有的 tables 列在 `FROM`
- 並把 comparison expression 寫在 `WHERE` 中
- 語意上來說 `FROM WHERE` 方式屬於 implicit syntax; `JOIN`/`ON` 屬於 explicit syntax, 明確表明 JOIN 關係
- 使用 `JOIN/ON` 明確表明其意圖是比 `FROM WHERE` 更好的做法

**Outer join**, `LEFT OUTER JOIN`, `RIGHT OUTER JOIN`, `FULL OUTER JOIN`

- ```sql
  SELECT *
      FROM weather LEFT OUTER JOIN cities ON weather.city = cities.name;
  ```
- `LEFT OUTER JOIN`, 我們需要左側 table 所有的資料, 並且在符合條件情況下列出 JOIN table 的資料
  - 如果找不到對應的資料時, 則以 empty values 取代
- `RIGHT OUTER JOIN`, 概念上等同於 LEFT JOIN, 只不過需要列出的是右側 table 所有的資料
- `FULL OUTER JOIN`, 概念上等於 LEFT JOIN + RIGHT JOIN, 兩個 table 都必須列出所有的資料
- **OUTER keyword 是選用的**
  - 可以直接使用 `LEFT JOIN`, `RIGHT JOIN`, `FULL JOIN`

**Self Join**

- Join 相同的 table 來進行搜尋, 即 self join
- 範例: 想要找出一個城市最低溫低於其他城市且最高溫高於其他城市時, 需要 self join weather table 來尋找
- ```sql
  SELECT w1.city, w1.temp_lo AS low, w1.temp_hi AS high,
        w2.city, w2.temp_lo AS low, w2.temp_hi AS high
      FROM weather w1 JOIN weather w2
          ON w1.temp_lo < w2.temp_lo AND w1.temp_hi > w2.temp_hi;
  ```
- self join 因為使用相同的 table, 因此無法直接使用 table 名稱進行區分
  - 因此可以使用別名語法, Example: `weather w1`, `weather w2`
- 別名語法也常廣泛使用在其他 query 上
  - 例如: `SELECT * FROM weather w JOIN cities c ON w.city = c.name;`

Convention

- 保持 SQL 命令的穩定度是重點
- `SELECT` 的 column 用明確指名取代 `*` 是更好的做法
- 在 `SELECT` join 時, 每個指名都使用 qualify 的方式指明, 換句話說都必須包含 `table.column`
  - 這樣的好處是在未來如果 table 的 column name 增加或修改產生碰撞時不會產生問題
  - 範例
  - ```sql
    SELECT weather.city, weather.temp_lo, weather.temp_hi,
          weather.prcp, weather.date, cities.location
        FROM weather JOIN cities ON weather.city = cities.name;
    ```

---

2.7 Aggregate Functions

Aggregate functions

- 由多個 input rows 計算出單一個值
- 常見的 aggregate functions
  - `count()`, `sum()`, `avg()`, `max()`, `min()`
- 範例: `SELECT max(temp_lo) FROM weather;`
- 假設此時想要尋找溫度最高的指定城市時,
  - 無法使用 `SELECT city FROM weather WHERE temp_lo = max(temp_lo);     -- WRONG`
  - 這樣的語法, aggregate functions 需要 `WHERE` 子句來決定作用的 rows 為何
  - 因此需要使用 subquery 做法, 先計算出 aggregate function 的結果

**subquery**

- 範例:
- ```sql
  SELECT city FROM weather
      WHERE temp_lo = (SELECT max(temp_lo) FROM weather);
  ```
- 在 `WHERE` 下使用 `()` 建立並且先運行一個 query

`GROUP BY`

- Aggregate 也常常與 `GROUP BY` 一起使用
- 範例: 我們想要列出 weather 中以 city 為單位, 計算出每個 city 有幾個 rows 和最低溫的上限是多少
- ```sql
  SELECT city, count(*), max(temp_lo)
      FROM weather
      GROUP BY city;
  ```
- 此時的結果會以 city 為單位, 並且 aggregate function 分別以個別 city 為單位進行計算

`HAVING`

- 對於 `GROUP BY` 的結果, 增加額外的篩選
- 範例:
- ```sql
  SELECT city, count(*), max(temp_lo)
      FROM weather
      GROUP BY city
      HAVING max(temp_lo) < 40;
  ```
- 如何區分 `WHERE` 與 `HAVING` 的使用時機
- `WHERE` 用來篩選 input rows
  - 早於 `GROUP BY` 與 aggregate function 的運作
  - 因此 WHERE 子句無法包含 aggregate function 直接作用, 而需要使用 subquery
- `HAVING` 則是通常必須與 aggregate function 一起作用
  - (`HAVING` 獨立於 aggregate function 之外使用的情境, 通常可以直接由 `WHERE` 取代)
  - `HAVING` 作用於 aggregation function 與 GROUP BY 之後, 換句話說, 是針對搜尋結果再次篩選
  - 因此, 優先使用 `WHERE` 取代 `HAVING` 是更好的做法, 節省一些不必要的計算

`LIKE`

- 在 `WHERE` 中使用 pattern matching 篩選
- 範例: 只搜尋 city 中以 S 開頭的
- ```sql
  SELECT city, count(*), max(temp_lo)
      FROM weather
      WHERE city LIKE 'S%'
      GROUP BY city;
  ```

`FILTER`

- 屬於**單一個** aggregation function 的 option
- `FILTER` 與 `WHERE` 十分相似, 重點在於篩選作用於指定 aggregate function 的 rows
  - 先篩選 input rows 早於 aggregation function 計算, 因此可以減少計算
  - 但是只針對單一個指定的 aggregate function
- 範例:
- ```sql
  SELECT city, count(*) FILTER (WHERE temp_lo < 45), max(temp_lo)
      FROM weather
      GROUP BY city;
  ```

---

2.8 Updates

`UPDATE`

- 更新搜尋結果
- 範例:
- ```sql
  UPDATE weather
      SET temp_hi = temp_hi - 2,  temp_lo = temp_lo - 2
      WHERE date > '1994-11-28';
  ```
- `UPDATE`, `SET`

---

2.9 Deletions

`DELETE`

- 從 table 中刪除 rows
  - 範例: `DELETE FROM weather WHERE city = 'Hayward';`
- 刪除 table 中所有的 rows, 要**特別小心的指令**
  - 範例: `DELETE FROM tablename;`
  - 系統不會進行確認, 並且會直接刪除所有的內容

`DROP TABLE`

- 從資料庫中移除整個 table
- 範例: `DROP TABLE weather, cities;`

---

3 Advanced Features

---

3.1 Introduction

- Tutorial 程式碼在 `advanced.sql ` 範例中可以找到

---

3.2 Views

`CREATE VIEW`

- 以建立 `VIEW` 取代複雜的 query, 使用 VIEW 如同一般的 table 一樣
  - _補_, 用來封裝細節, 像是建立使用者介面一樣
- VIEW 幾乎可以像是 table 一樣使用, 在 VIEW 上建立 VIEW 也是尋常做法
- 範例:
- ```sql
  CREATE VIEW myview AS
      SELECT name, temp_lo, temp_hi, prcp, date, location
          FROM weather, cities
          WHERE city = name;

  SELECT * FROM myview;
  ```

Best practices & conventions

- 大量使用 VIEW 去封裝常用到且複雜的 query 是好的做法, good
  SQL database design
- 在隱藏且不改變資料庫細節的情況下, 可以隨著應用程式的發展與使用去調整 VIEW

---

3.3 Foreign Keys

`references`

- 通過定義讓資料庫去限制 (constraints) 必須存在資料的相依性
  - 換句話說, 通過 `references` 去指定該欄位的資料必須是先存在於其他 table 中的值
  - 在正規化的資料庫下, 存在自己 table 中有其他 table 的值,
  - 此時這個值必是 Foreign keys, 用來關聯其他 table 用的關鍵欄位,
  - 因此可以通過定義 constraints, 讓資料庫來保證其值的存在
- 範例: weather table 中的 city, 必須是 cities table 中已經存在的 name 值
- ```sql
  CREATE TABLE cities (
          name     varchar(80) primary key,
          location point
  );

  CREATE TABLE weather (
          city      varchar(80) references cities(name),
          temp_lo   int,
          temp_hi   int,
          prcp      real,
          date      date
  );
  ```

Best practices & conventions

- Constraints foreign keys 的做法, 是可以提高資料庫品質的做法, 被強烈推薦使用

---

3.4 Transactions

-

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

```

```

```

```
