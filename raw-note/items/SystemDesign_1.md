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

- Key-Value store 是最常見的 NoSQL, 常用於 cache 與設定配置
- _Etcd_, _Redis_, _ZooKeeper_

---

### 第十四章 - Specialized Storage Paradigms

- Blob store
  - Blob, Binary large object, 是容量大且 unstructured 的資料型態, 不適合存放在 relational database (SQL database) 裡
  - 大多數情況不會自行建立 (實作複雜) 而是使用 Blob store 雲端服務 _s3_, _GCS_
- Time Series Database
  - 以時間為 index 的資料, 例如 log, event,
  - 如果要操作很多時間相關的行為, 很適合存在 time series database, 例如 monitoring
  - _InfluxDb_, _Prometheus_, _Graphite_
- Graph Database
  - 適合處理資料型態會自然形成 graph 的資料
  - 以 relational database 儲存時在 query 時會相對較慢且複雜
  - _Neo4j_
- Spatial Database
  - 例如 location related data, latitude and longitude
  - Quadtree, 分支只有 4 或 0 的樹狀結構, 常用於建立空間資料, 例如地圖上的內容
  - query 時複雜度為 O(log4(n))
  - 現代 relational databases 例如 _Postgres_, 都有很好的最佳化

---

### 第十五章 - Replication And Sharding

- 由於資料庫在整個系統中至關重要, 並且時常是效能瓶頸或者 single point failure
- 多數情況會建立多個資料庫來避免 single point failure
- Replica, 複製體可以隨時取代原本的 main database 運作, 以避免 single point failure, 因此必須要與 main database 完全同步 (sync write)
  - Replication 可以分地理區域建立, 提供更好的 latency
  - sync update 也可以以 async 的方式進行, 取決於使用需求
- Main database 在增加 throughput 時, 以 vertical scaling 單體增加不能滿足後必須採用 horizontal scaling 形成 database cluster
- Sharding and shards, data partitioning 資料區塊分割並且放在不同的機器上
  - Sharding 時要做的決策是如何切割資料
  1. 以 client 區域做分割
  1. 依據資料類型分割, 例如 payment, clients, ...
  1. 結構化資料以特定欄位的 hash 值做區分 (consistent hashing), 使用良好設計的 hash function 是至關重要的來避免 hot spot
  - 不良的分割會產生 hot spot 讓單一的機器負擔過重甚至無法承擔
- Sharding 與 replication 在實際上是非常複雜的內容, 在系統設計中只需要最高抽象層的討論

---

### 第十六章 - Leader Election

- 範例: Database 包含會員付費資訊與第三方支付服務 (Stripe, Paypal, ...) 之間的互動
- 系統設計永遠思考避免 single point failure, 因此服務多數都會以 cluster 的方式建立, 但是有一些操作必須只做一次時, 必須確保只有一台機器會執行
- 範例: 在 cluster 中避免重複扣款問題, 因此要選出 main or leader server 來執行
- Leader Election 為選擇 main server 的機制並且要考慮問題發生時 (Network issue, leader server down, exception, interrupt)
- Consensus Algorithm, 複雜的共識演算法
  - Paxos & Raft,
- 實務上以 _Etcd_, _ZooKeeper_ key-value store 建立 leader election, 都是 strong consistent (資料維護), highly available 儲存當前的 leader

---

### 第十七章 Peer-To-Peer Networks

- 傳送資料的 source 如果可以持續增加即可避免依序的傳輸 (避免等待)

1. 資料被切割成 chunk
2. 主資料來源把各個 chunk 傳送給不同的 peer
3. 與此同時各個 peer 可以跟其他 peer 取得缺少的 chunk

- 另外的問題是需要 peer selection algorithm 去選擇下一個 peer
  1. 另外一個 management server 來處理 peer selection 問題 (tracker)
  2. peers 之間互相溝通並且分享資訊 (例如用 hash table 存資訊), 去試著理解群體與選出自己下一個 peer (gossip protocol), DHT, distributed hash table
- _Kraken_, uber open source

---

### 第十八章 - Polling And Streaming

- client-server communication
  1. request and response
  1. polling, client 持續且定期的發出 request, 例子: 溫度更新
  1. streaming, client 與 server 建立一個長期的 connection (socket) 然後由 server 主動發送 (push) 資料給 client 來更新, 例子: chat
- 在系統設計時需要依據需求來決定溝通方式

---

### 第十九章 - Configuration

- JSON or YAML
- static, 寫死的相依於 application 中, 修改通常需要重啟或重新建置
  - 修改時通常需要經過 code review
- dynamic, 與 application 分離的, application 以 query/request 取得當下的設定
  - 修改時更容易, 要小心安全性
- configuration 修改與更新, 可以非常複雜與詳細的流程, 來保證安全性

---

### 第二十章 - Rate Limiting

- Rate Limiting, 一個動作在一定時間內的執行次數上限
- 為了安全性的 rate limiting
  - DoS attack, 單一來源利用大量的 request 導致伺服器的功能無法服務其他人甚至直接掛掉
  - DDoS attack, 多個來源產生的 DoS attack, 為了嘗試繞過 rate limiting 設定的限制
- 為了效能的 rate limiting
- Rate limiting 可以依據 user, IP-address, region, time
- Rate limiting 可以建立在各個不同的 layer, 例如 Network, Service, ...
- 對於 service cluster 把 rate limiting 建立在單台機器上是不足夠的, 因此要把 rate limiting 建立在其他 server 上, 例如 _Redis_
- _Redis_
- 系統設計上要思考各個情境要如何設計對應的 rate limiting 機制

---

### 第二十一章 - Logging And Monitoring

- 在系統越來越大時 logging, monitoring, alerting 會越來越重要
  - 用來除錯, 偵測攻擊, 尤其是跨系統的問題
  - 用來取得有用的資訊來協助決策
- Logging, 有格式的印出各種 event 與重要的資訊, 協助除錯與偵測攻擊, 尤其是跨系統的問題
- Monitoring, 設定指定的數據來觀察或查詢, 可以協助 BD, marketing, ...
- Alerting, 設定指定的觀測並且主動通知
- 有額外的系統協助收集 logs, 提供 monitoring, 設定 alerting 等等
- 例如 time series database, ...

---

### 第二十二章 - Publish/Subscribe Pattern

- async, 分離 (decouple) publisher 與 subscriber
- publisher, 發送 message 到 topic
- subscriber, 訂閱 topic 來取得 message
- topic (channel),
- message, 資料與動作
- Idempotent operation, 這個動作無論執行多少次都不會影響他的輸出或影響
- Publish/Subscribe Pattern, 特色是保證至少一次的 delivery, persistent storage, 保證 message 順序 (ordering), replayability 可重現
- _Apache Kafka_, _Google Cloud Pub/Sub_

---

### 第二十三章 - MapReduce

- 大數據處理
- distributed
- Google opened white paper: MapReduce
- 由 functional programming 的概念啟發
- Map, 分散的檔案經過 map function 形成 key-value pairs
- Reduce, 整合各節點裡的 key-value pairs 成最終的結果
- Map 與 Reduce function 都必須是 idempotent
- Distributed File System, 由分散式系統組成的檔案系統
- word count, 大數據處理的 hello world example
- _Hadoop_, HDFS (Hadoop Distributed File System)

---

### 第二十四章 - Security And HTTPS

- HTTP
  - Man-in-the-middle attack
- Encryption
  - Symmetric, _AES_ Advanced Encryption Standard, AES-128, AES-192, AES-256, 只有一個 key 因此安全的分享 key 是一個問題
  - Asymmetric, _RSA_,
- HTTPS
- TLS, Transport Layer Security, 一個 security protocol
- SSL Certificate, Secure Socket Layer, a public key from server, 認證 server 是正確的 server 來提供 public key 否則一樣可以被 man-in-the-middle 攻擊, 由 certificate authority (CA) 提供的 digital certificate
- TLS Handshake, 讓 client 與 server 建立 session key 來安全的溝通
  1. client hello (random) -> server
  2. server hello + SSL Certificate (server public key, signed by CA) -> client
  3. client verify SSL Certificate by CA public key
  4. client premaster secret (encrypted by server public key) -> server
  5. generate symmetric-encryption session key (client hello, server hello, premaster secret)

---

### 第二十五章 - API Design

- API for inner or as a product
- 因為 API 被大量的使用不管是內部還是對外, 因此如何設計 API 是非常重要的事情
- Pagination
- CRUD Operations
- 做決定時的溝通是設計面試的重點

1. 詢問詳細的需求細節, 2. 系統設計: 畫出架構圖, 2. API 設計: 描述 API endpoint 等等細節 (API outline)

- 寫下 API Definition, 像是所有的 entity 與 properties
- 寫下 API Endpoint Definition, 各個需要支援的 function definition, 名稱, 輸入與輸出, 與實際的 restful endpoint (path, method, request body, response body)
- 或者寫下 API in swagger format
- 面試時詢問可以接受的格式與寫法
- **練習方式**:
  1. 實際看大公司的 API 文件, 學習如何設計 (Stripe API, ...)
  2. 嘗試回答如何常見公司的 API (Stripe API, Twitter API, ...) 然後對照實際的 API 詢問設計是否更好或決策想法

---

Questions

---

### 第一章 - Design A Code-Deployment System

問題

- Q1: what is
- Q2: 用戶是誰, 為什麼需要這個系統
- Q3: 地區性, 全球或特定地區
- Q4: 使用我們自己的機器或雲端服務, 機器是在特定區域還是全世界各地
- Q5: 內部系統或外部系統, 時間需求 (反應非常快速與否), 遇到錯誤時的處理
- Q6: 以自己的話描述來確認需求
- Q7: 需求的時間頻率, 容量大小
- Q8: 輸入的資料從何而來, 如何取得

Video Solution

- 需求探索, 列出要實作中的每個階段並且討論每個階段的需求與設定
  - 實際的需求數據, 例如每天多少次, 執行時間, 容量大小 等等
  - 輸入資料的來源與如何取得
- 分成兩個步驟 building 與 deploying
- 使用 message queue 來接需求與準備處理
  - 討論 queue 如何實作, 建立在 memory 上或有實際的硬碟儲存, 例如建立在 relational database 上
  - relational database 的 table 實際上會怎麼建立
  - 利用 SQL database 的 ACID transaction 來保證 concurrency safety
- 一直思考或詢問自己如何處理 worst case 或任何的 failed 與 edge cases
  - 處理方式例如 health check
- 依據假設的需求數據計算出預估的機器數量或工作數量
- region issue 可以分散成各區域獨立一個小系統處理, 但要記得如果有資料需要部屬在各個 region 時的處理
- 大資料傳輸可以建立在 peer-to-peer network

Solution Walkthrough

- 解題步驟與思考順序

1. 探詢且確認系統需求, 系統目的與動作, 使用者, 預估運行的量與時間, 期望的 availability 程度
2. 第一個高抽象層的計畫, 系統應該切成那些獨立的功能, 階段, component, 子系統, ...
3. 從 high level 去描述這些階段與獨立功能要執行的工作與成員

- 思考實作討論與假設並且思考每個 edge cases, worst cases, failed cases 發生時
- 討論輸入資料的來源與取得方式
- Job Queue, 以 memory 實作時發生錯誤時資料會消失, 可以以 SQL databases 實作
- 討論 SQL databases 實際的 table 與 query
- 思考 concurrency, 以 SQL databases 為例可以使用 ACID transaction 來保護
  - 實際計算需求的量以 SQL 為系統是否能乘載
- 部分機器死掉時, 可能遇到的狀況與解決方案, 可以實作 health check
- 實際計算預估的機器數量
- 討論輸出資料的存放位置與實現方式
- 考慮 region 與 vertical scaling
- 在大資料大數量傳輸時, 可以考慮使用 peer-to-peer network 加速
- 非同步工作追蹤可以使用 dynamic configuration 建立 global 與 regional 之類的互相讀取得到最新狀態
- 畫出最終系統圖包含 scaling 與 load balancer

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
