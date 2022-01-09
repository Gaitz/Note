## AlgoExpert System Design

### [AlgoExpert System Design](https://www.algoexpert.io/systems/fundamentals), SystemDesign

---

Concepts

第一章 - Introduction

第二章 - What Are Design Fundamentals

第三章 - Client-Server Model

第四章 - Network Protocols

第五章 - Storage

第六章 - Latency And Throughput

第七章 - Availability

第八章 - Caching

第九章 - Proxies

第十章 - Load Balancers

第十一章 - Hashing

第十二章 - Relational Databases

第十三章 - Key-Value Stores

第十四章 - Specialized Storage Paradigms

第十五章 - Replication And Sharding

第十六章 - Leader Election

第十七章 - Peer-To-Peer Networks

第十八章 - Polling And Streaming

第十九章 - Configuration

第二十章 - Rate Limiting

第二十一章 - Logging And Monitoring

第二十二章 - Publish/Subscribe Pattern

第二十三章 - MapReduce

第二十四章 - Security And HTTPS

第二十五章 - API Design

Questions

第一章 - Design A Code-Deployment System

第二章 - Design AlgoExpert

第三章 - Design A Stockbroker

第四章 - Design Amazon

第五章 - Design The Reddit API

第六章 - Design Facebook News Feed

第七章 - Design Google Drive

第八章 - Design Netflix

第九章 - Design The Uber API

第十章 - Design Tinder

第十一章 - Design Slack

第十二章 - Design Airbnb

第十三章 - Design the Twitch API

---

Concepts

---

### 第一章 - Introduction

- 對於 System Design 題目背後的 Design Fundamentals 知識
- System Design 問題需要大量的背景知識才能回答問題

---

### 第二章 - What Are Design Fundamentals

- 首先理解 System Design 面試的進行方式
  1. 大量的問答與溝通用來釐清與假設系統需求
- 對於 System Design 問題來說很常沒有絕對正確的答案, 系統設計都是假設與取捨
- Design Fundamentals
- 簡單分成四個類型
  1. 必需的基礎知識 (Network protocol, basic model, ...),
  2. 觀測系統相關 (logger, monitoring, latency, ...),
  3. 進階提升的部分 (Load balancers, proxy, ...)
  4. 實際存在的工具 (AWS services, redis, ...)

---

### 第三章 - Client-Server Model

- Client-Server Model
- Client, 提出請求 request
- Server, 接收請求與回覆 resolve and response
- IP address, 機器位置 `localhost` `127.0.0.1`
- DNS, Domain Name System 解析名稱與機器位置
- port, 單一機器上的接口後方對應不同的服務, 0-1023 為系統保留, 範圍在 0~65535 (2^16)
- Example, 輸入網址在瀏覽器上與伺服器回應

---

### 第四章 - Network Protocols

- Network Protocols
- IP, Internet Protocol, 主要包含來源與目的地的資訊, 目前分成 IPv4 與 IPv6 兩個版本
- TCP, Transmission Control Protocol, 建立連線, 主要目的在於提供溝通上的一些功能, 例如保持資料的順序, 丟包時資料重送. 以 handshake 的方式建立連線 (connection)
- HTTP, HyperTextTransfer Protocol, 應用層協定, 實現 request respond model
- IP Packet, 一次傳遞的最小單位, 由 header 與 payload 兩個部分組成

---

### 第五章 - Storage

- Persistence, 資料不遺失, 對於各種不同的資料庫來說資料不遺失可能會有不同的前提假設
- Databases, 資料庫, 基本上就是一個提供存取資料的服務
- Disk, 硬碟, 速度慢, 可以防止多種情況下的資料遺失
- Memory, RAM, Random Access Memory, 記憶體

---

### 第六章 - Latency And Throughput

- 常用來定義效能 (performance) 的兩種測量
- Latency, 延遲, 定義資料從來源到終點所需要花費的時間, 不同的設計會產生不同的延遲時間, 因此會對應不同的需求產生不同的設計
  - 粗估 1 MB 的傳輸
  - RAM, 0.25 ms
  - SSD, 1 ms
  - Network (1Gbps), 10 ms, 假設沒有實體距離
  - HDD, 20 ms
  - intercontinental round tripe, 150 ms
  - 用來取捨精準度, 延遲, 可取得性
- Throughput, 在單位時間內的產出量, 可承受的上限
  - 常用單位是 requests per second, RPS
  - queries per second, QPS
  - 可以用來檢視 bottleneck

---

### 第七章 - Availability

- 系統的穩定性
- 可以用不可以取得的持續時間來做為測量
- **取決於系統提供的功能是否很需要高度的穩定性**, 一個系統中有各種服務, 每種服務需求的可取得性是不一樣的
- 以一年的可取得時間作為測量單位, Nines
  - 99%, downtime: 3.65 天
  - 99.9%, downtime: 8.77 小時
  - 99.99%, downtime: 52.6 分鐘
  - 99.999%, downtime: 5.26 分鐘
- High Availability, HA, 通常代表有 5 nines 以上的可取得性
- SLA, service-level agreement, 保證, 整體合約
- SLO, service-level objective, 保證的項目, 細項
- **實現 High Availability 的方式是讓系統避免 single point failure 以 redundancy 實現**, 可以分成以下兩種方式
  - 多台機器以平均分配工作的方式實現 redundancy
  - 以單一個機器工作, 但是有多個備援可以隨時取代工作
  - 並且要思考是否需要人工介入重啟或備援機制

---

### 第八章 - Caching

- 提升速度與減少延遲
- 可以在不同的階段或位置使用 caching 技術, 例如在 client-side, server-side, database level
- 針對 read 的
  - 思考 cache 新舊版更新問題, 針對內容的性質
- 針對 write 的,
  - write through, cache 與 database, 同時寫入後才 response
  - write back, cache 與 database 非同步寫入, cache 寫入後即 response
- caching 的內容最好是 immutable 的
- caching 空間的內容移除策略或取代策略
  - least-recently used, LRU, 最近最沒用到的內容 (時間上最久以前使用到的內容)
  - first in first out, FIFO, 最早加入的內容
  - least-frequently used, LFU, 頻率上用到最少次數的內容
- Content Delivery Network, CDN
  - 第三方服務提供實體地區性的 cache 機制
- _Redis_

---

### 第九章 - Proxies

- 一種伺服器提供中間層的服務
- Proxy, Forward Proxy, 服務使用服務的 Client (隱藏 client)
- Reverse Proxy, 服務提供服務的 Server (隱藏 server)
- Reverse Proxy 可以提供 load balancer, logger, cache, filter 等等不同的功能
- _Nginx_ (used for reverse proxy or load balancer)

---

### 第十章 - Load Balancers

- 中間層伺服器, 一種 reverse proxy, 用來分配資源
- 以多個服務伺服器來提升 throughput 時, 需要 load balancer 來分配工作
- 使用水平擴張 (horizontal scaling) 提高 throughput 時需要使用 load balancer
- Load balancer 有分成硬體版與軟體版
- Load balancer 使用的分配演算法 (Server-Selection Strategy),
  - random, 隨機分配
  - round-robin (RR), 依序分配
  - weighted round-robin,
  - performance/load, 定期調查機器使用量, 並且分配給最輕的
  - ip based, **通過 ip hash 值到指定的機器上, 這種做法可以提高 cache hit rate**
  - path based, 功能性分配, 每個機器提供不同的服務並且以 load balancer 做區分, 可以安全的個別更新並且不會產生 single point failure
- 系統設計上最需要回答的是依據需求選擇適當的分配演算法
- Load balancer 可以擁有多層並且在系統各層都可以使用
- 可以使用 _Nginx_ 實現

---

### 第十一章 - Hashing

- load balancer 考慮到提高 cache 使用率時, 希望相同的 request 可以對應到相同的伺服器, 因此可以提供 cache
- 以 hashing 產生固定的 bucket, 要考慮到新增伺服器或有伺服器停止功能時, 需要產生新的 bucket
- **Consistent Hashing**, 以 loop 的方式放置 server 然後 client hashing 後尋找值的下一個 server, 這樣讓 bucket 與 hashing 值有範圍空間, 而不是單純的 1 對 1, 這樣在新增或移除伺服器時, 大多數 request 仍然可以到舊的 bucket
  - 另外可以讓相同的 server 有多個 bucket 產生, 這樣可以讓 request 更 balanced 的分配
- **Rendezvous Hashing**, coined highest random weight hashing,
  - 每個 client 與所有的 server 值做計算 score 並且選擇 score 最高的 server 處理,
  - 與 consistent hashing 一樣在減少或增加伺服器時能保持一定的一致性, 但是缺點是每次選擇都要計算 O(n), n 為伺服器數量
- 在預期有大量的流量產生並且需要即時加機器時, 應該使用以上兩種 hashing 方式來提高 cache 的使用率
- SHA, Secure Hash Algorithms,
- 一般情況下我們會選用現成的 hashing function 與 score function 避免自己建立

---

### 第十二章 - Relational Databases

- Relational Databases, 有結構的 (structured)
  - table
  - schema
  - 大多數的 relational databases 都支援 SQL
- Non-Relational Databases, 不強制定義 structure 的資料庫
- **SQL**, Structured **Query** Language, 一種 domain-specific language 用來查詢結構資料庫, 提供強大且複雜的查詢功能
- SQL Database, 支援使用 SQL 查詢的資料庫
- NoSQL Database, 不支援使用 SQL 查詢的資料庫
- ACID **Transaction** 可以視為一般人對於資料庫安全性的基本要求或看法
  - Atomicity, 複雜的交易會形成一個單元, 只有全部成功或全部失敗, 沒有中間型態, 失敗就會自動回復已執行的動作
  - Consistency, 當交易完成或者回復時, 其他相關的 transition 或未來的 transition 都能得到最新狀態的值
  - Isolation, 多個交易可以同步執行結果等價於他們依序執行, 並不會互相影響
  - Durability, 所有完成的交易會把紀錄寫進 disk 中, 而不會僅存在 memory 上
- Database **Index**, 用來加速指定的查詢, 以建立額外的資料結構來協助查詢, 增加容量和寫入速度變慢但是提高查詢速度, 有多種方式實作
  - 通常用在常用的查詢上
- Strong Consistency, 等價於 ACID transaction 的 Consistency
- Eventual Consistency, 相較於 Strong Consistency 有時候會取得過時的資料, 只保證在一定時間內會更新到最新
- **選擇適當的資料庫系統在系統設計是重要的決定**
- 移植資料庫是複雜且痛苦的過程
- _Postgres_

---

### 第十三章 - Key-Value Stores

---

### 第十四章 - Specialized Storage Paradigms

---

### 第十五章 - Replication And Sharding

---

### 第十六章 - Leader Election

---

### 第十七章 - Peer-To-Peer Networks

---

### 第十八章 - Polling And Streaming

---

### 第十九章 - Configuration

---

### 第二十章 - Rate Limiting

---

### 第二十一章 - Logging And Monitoring

---

### 第二十二章 - Publish/Subscribe Pattern

---

### 第二十三章 - MapReduce

---

### 第二十四章 - Security And HTTPS

---

### 第二十五章 - API Design

---

---

Questions

---

### 第一章 - Design A Code-Deployment System

---

### 第二章 - Design AlgoExpert

---

### 第三章 - Design A Stockbroker

---

### 第四章 - Design Amazon

---

### 第五章 - Design The Reddit API

---

### 第六章 - Design Facebook News Feed

---

### 第七章 - Design Google Drive

---

### 第八章 - Design Netflix

---

### 第九章 - Design The Uber API

---

### 第十章 - Design Tinder

---

### 第十一章 - Design Slack

---

### 第十二章 - Design Airbnb

---

### 第十三章 - Design the Twitch API

---

38
