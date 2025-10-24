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
- 進入交互界面後
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
