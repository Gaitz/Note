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
- Redis

---

### 第九章 - Proxies

- 一種伺服器提供中間層的服務
- Proxy, Forward Proxy, 服務使用服務的 Client (隱藏 client)
- Reverse Proxy, 服務提供服務的 Server (隱藏 server)
- Nginx (used for reverse proxy or load balancer)
- Reverse Proxy 可以提供 load balancer, logger, cache, filter 等等不同的功能

---

### 第十章 - Load Balancers

---

### 第十一章 - Hashing

---

### 第十二章 - Relational Databases

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
