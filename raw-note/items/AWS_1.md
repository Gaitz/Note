## AWS_1: AWS Cloud Practitioner Essentials

### [AWS Cloud Practitioner Essentials (skill builder)](https://explore.skillbuilder.aws/learn/course/134/play/99519/aws-cloud-practitioner-essentials), ComputerScience/AWS

---

第一章 - How to Use This Course

第二章 - Introduction to AWS Cloud Practitioner Essentials

第三章 - Module 1: Introduction to Amazon web services

第四章 - Module 2: Compute in the cloud

第五章 - Module 3: Global infrastructure and reliability

第六章 - Module 4: Networking

第七章 - Module 5: Storage and databases

第八章 - Module 6: Security

第九章 - Module 7: Monitoring and analytics

第十章 - Module 8: Pricing and support

第十一章 - Module 9: Migration and innovation

第十二章 - Module 10: The cloud journey

第十三章 - Module 11: AWS certified cloud practitioner basics

第十四章 - Final Assessment

---

### 第一章 - How to Use This Course

---

### 第二章 - Introduction to AWS Cloud Practitioner Essentials

---

### 第三章 - Module 1: Introduction to Amazon web services

- Client-server model
- AWS principle: only pay for what you use
- Cloud computing is the on-demand delivery of IT resources over the internet with pay-as-you-go pricing.
- Deployment models for cloud computing
  - cloud-based, 全在公開雲上
  - on-premises, 全在本地, 私有雲
  - hybrid, 混合雲
- 使用 cloud computing 的優勢
  - 不需要前期費用
  - 不需要額外維護資料中心
  - 不需要猜測 capacity
  - 利用集合經濟優勢, 降低成本
  - 加快速度與彈性
  - 快速的建置全球化架構

---

### 第四章 - Module 2: Compute in the cloud

Amazon Elastic Compute Cloud (EC2)

- Launch
  - 從 template 中選擇適合的基本設定 (OS, server, applications)
  - 啟動 instance 然後設定 security 規則
- Connect
  - 有數種方式可以連結 EC2 instance
- Use
  - 開始使用

Amazon EC2 instance types

- General purpose instances
  - 平衡的 compute, memory, networking 能力
  - application servers, gaming servers, backend servers, 中小型資料庫
- Compute optimized instances
  - 計算能力最佳化的
  - 高效能的 web servers, compute-intensive application servers, 高性能遊戲伺服器, batch processing
- Memory optimized instances
  - 記憶體最佳化的
  - 通常處理需要大量資料在 memory 的情境
- Accelerated computing instances
  - 使用硬體加速的
  - 浮點數計算, 圖形計算, data pattern matching
  - 適合用於 graphics applications, game streaming, application streaming
- Storage optimized instances
  - 儲存最佳化的
  - 需要大量且連續的在 local storage 進行讀寫, 擁有 10000 low-latency, random IOPS 的能力
  - 適合用於分散式檔案系統, data warehousing applications, high-frequency online transaction processing (OLTP)
  - 使用 input/output operations per second (IOPS), 每秒 IO 次數, 來作為測量標準

Amazon EC2 pricing

- On-demand
  - 依據運行時間計費, 沒有最低費用也不需要預先支付
  - 適合短期, irregular workload, 且無法暫停的工作
  - 適合用於開發環境, 測試環境, 未知使用量的環境
  - 不適合用於長期運行的工作, 有其他更省錢的計費方式
- Reserved instances
  - 針對 on-demand instance 的折扣方案
  - 分成兩種類型 standard reserved instances, convertible reserved instances
  - 有分成 1 年合約或者 3 年合約
  - 當合約到期後會自動轉成 on-demand 計費, 直到 instance 被關閉或者簽署新的 reserved instance 合約
  - Standard reserved instances, 適合用於已經知道適合的 EC2 instance type 和 size 並且運行狀態穩定的程式, 同時也已經知道適合的 AWS region, 可以保障你的需求一定能獲得, 固定 (instance family and size, platform description, tenancy, region)
  - Convertible reserved instances, 如果需要不同的 availability zones 和不同的 instance types 時, 以折價率換取靈活性
- EC2 instance saving plans
  - 在預先指定的 regions 下簽署 1 年或 3 年合約並以小時計費, 可以享有折扣
  - 類似於 standard reserved instance 方案, 但是不用指定 instance type 和 size, OS, tenancy 等細項
  - 可以使用 AWS Cost Explorer 服務來進行試算
- Spot instances
  - 適合用於可以靈活啟動與關閉, 並且工作內容允許中斷的情況
  - 中斷時會預先有 2 分鐘時間的提醒, 以用來暫存狀態
  - 使用 AWS EC2 零散的運行時間, 因此提供最高 90% off 的折扣
- Dedicated hosts
  - 預定實體伺服器來運行 EC2 instances
  - 擁有不同的計費方式
  - 是以上所有方案裡最昂貴的

Amazon EC2 Auto Scaling

- Scalability, 自動擴張與縮減所需的效能
- Amazon EC2 Auto Scaling
  - Auto Scaling group 設定
    - Minimum capacity, 最低數量
    - Desired capacity, 希望的數量, 如果沒有設置會等同於 minimum capacity
    - Maximum capacity, auto scaling 時的上限數量
- Dynamic scaling, 依據當前需求反應
- Predictive scaling, 依據預測來反映
- 適用不同情境
  - Scale up, 升級單點能力
  - Scale out, 平行擴張
- _補_, 要讓 auto scaling 能良好的運作需要一個良好設計的 decoupling architecture
  - "Everything fails all the time, so plan for failure and nothing fails."
  - **計畫失敗**, 思考每個可能失敗的地方, 避免 single point failure

Elastic Load Balancing, ELB

- AWS 的 Load balancing 服務
- Elastic Load Balancing 與 EC2 Auto Scaling 是不同的服務
- 但是 Elastic Load Balancing 可以連結 auto scaling group
- 屬於 regional construct, region 層級的 load balancing 機制
- 除了適用於終端使用者 (endpoint) 連結 AWS 服務之外, 也適用於內部服務之間, 像是 front-end servers 連結 back-end servers 中間也可以有個 ELB.

Messaging and queueing

- 一個應用程式或者一個系統是由多個 components 所結合而成
  - tightly coupled components, 容易造成 single point failure
  - 因此好的架構 (architecture) 是 loose coupling (去耦合的)
- Monolithic applications
  - 所有的 component 耦合在一起, 互相溝通是 synchronous
- Microservices
  - components 之間沒有耦合, 互相溝通是 asynchronous
- Amazon Simple Notification Service (Amazon SNS)
  - Publish/subscribe service,
  - subscribers 可以是 webhook, AWS services (AWS Lambda), email address, ...
- Amazon Simple Queue Service (Amazon SQS)
  - Message queueing service

Additional Compute Services

- Serverless computing
  - AWS Lambda,
    - 有運行時間上限 (15 mins)
    - 適合時間不長的計算工作, Event-based 情境
- Containerized
  - 使用 Docker container 的相關服務
  - Amazon Elastic Container Service (Amazon ECS)
    - Docker container
  - Amazon Elastic Kubernetes Service (Amazon EKS)
    - Kubernetes service
  - AWS Fargate
    - 配合 Amazon ECS 與 Amazon EKS 一起使用的 serverless 服務
    - 原本的 Amazon ECS 與 Amazon EKS 都運行在 EC2 上

---

### 第五章 - Module 3: Global infrastructure and reliability

Global infrastructure

- High availability, 高可用性
  - 允許容錯 fault tolerance
- 以多個不同地區的 data center 做避險, Regions

AWS Regions

- AWS Regions
  - 每個 Region 是各自獨立的 (isolated)
  - 資料不會進出 Region 除非使用者有明確要求
- Selecting a Region
  - Compliance, 法規限制
  - Proximity, 距離使用者的物理距離
  - Feature available, 想要使用的 AWS 服務是否提供
  - Pricing, 價格, 每個 Region 計價不同
- Availability Zones, AZ
  - 每個 Region 裡會有多個 Availability Zones 是實體上有物理距離分隔的 data centers, 提供 Region 內部的容錯
  - 推薦 AZ 層級的服務, 至少應該有兩個分散在不同的 AZ 中, 例如 EC2
  - 如果是 Region level 的服務, 已經自動有分散在不同 AZ 的容錯能力, 例如 ELB

Edge Locations

- AWS CloudFront, AWS 的 CDN 服務
- AWS edge location, 也運行於 AWS 的 DNS 服務, Amazon Route53
- 運行 AWS 服務於你的 data center 中, 可以使用 Amazon Outposts, (_補_, 可能類似 OpenStack)

Ways to interact with AWS services

- AWS Management Console, web based 操作介面
- AWS command line interface, CLI
- Software development kits, SDKs
- AWS Elastic Beanstalk, configuration based, 協助調整 capacity, load balancing, automatic scaling, Application health monitoring
- AWS CloudFormation, AWS 的 Infrastructure as code solution, (_補_, 類似 Terraform)

---

### 第六章 - Module 4: Networking

- Amazon Virtual Private Cloud, AWS VPC
  - Public subnet
  - Private subnet
- VPC 內的 resource 可以有不同的 security group 設定
- Internet gateway, IGW
  - 入口, 用來連接 VPC 區域與 public internet
- Virtual private gateway
  - 入口, 用來連接 private only resources, 建立 **VPN connection**
  - 跟 Internet gateway 連結一樣的外部網路, 只是受到 authentication 而已, 但是仍然無法阻擋無效的連結, 產生的頻寬使用 (即一樣可以受到 DoS 攻擊)
- AWS Direct Connect, 建立與 VPC 連結的專用通道
  - 更近一步, 加強 VPC 區域的安全性, 避免任何外部 internet 的連結
  - 最小化 latency 最大化 security
  - (專用的實體網路, 需要額外的供應商協作)

Subnets and Network Access Control Lists

- Subnets
  - Public subnets
  - Private subnets
- Internet gateway 有 network access control list (network ACL)
  - 來檢查進入 (inbound) 與離開 (outbound) 的所有 packet
  - 預設上, network ACL 允許任何 inbound 與 outbound 直到有額外的設定
  - Network ACL 是 **stateless** packet filtering, 換句話說, 他是沒有記憶的, 需要每次都檢查
  - Network ACL 只在 VPC boundary 進行檢查, 因此沒有關於內部 resource 更細緻的設定, 因此需要 Security Group
- VPC component 有 security groups
  - 在 VPC 內部的 resources 可以定義第二層的 packet filtering (instance level access control), 稱為 security group
  - 預設上, security group 阻擋所有的 inbound, 開放所有的 outbound
  - Security group 是 **stateful** packet filtering, 他會記憶過去進出的 packet 用於加速 inbound

Global Networking

Domain Name System (DNS)

- Amazon Route 53, DNS service
  - Routing policies
    - latency-based routing
    - geolocation DNS
    - geoproximity
    - weighted round robin
- Amazon CloudFront, CDN service

---

### 第七章 - Module 5: Storage and databases

Instance stores and Amazon Elastic Block Store (Amazon EBS)

- Instance stores
  - 暫存的 block-level storage of EC2 instance
  - 類似暫時的硬碟, lifecycle 跟 EC2 instance 一樣, 換句話說, 如果 EC2 instance 停止運行時 (stopped or terminated) 資料會被刪除
  - 物理上連結著當時的 EC2 instance host 機器的硬碟 (hard drive)
- Amazon Elastic Block Store (Amazon EBS)
  - 提供永久儲存的 block-level storage, (virtual hard drive)
  - 可以使用 Amazon EBS snapshot 進行備份 (incremental backup)
  - 屬於 Availability Zone 層級服務, 只適用於單的 AZ 中
  - 沒有 auto scaling 功能

Amazon Simple Storage Service (Amazon S3)

- Object storage
  - 每個 object 擁有 data, metadata, key (as id)
- Amazon Simple Storage Service (Amazon S3)
  - 提供 object-level storage 並且把資料以 object 的形式儲存在 bucket 裡
  - 每一個 object 本身最大容量限制為 5 TB
  - 可以設定 visibility 和 access 權限
  - 擁有 versioning 機制, 可以查看 object 的變動
  - 可以設置 S3 lifecycle policies 讓資料依據使用頻率自動調整儲存方案
- Amazon S3 Storage Classes
  - S3 擁有多種儲存類型供選擇, 計費價格通常由以易取性 (availability) 遞減
  - S3 Standard,
    - 資料至少被儲存在 3 個 AZ, 因此是 high availability
  - S3 Standard-Infrequent Access (S3 Standard-IA)
    - 較少需要存取的, 但是保持與 S3 Standard 同等的 high availability
    - 有較低的 storage price 較高的 retrieval price
  - S3 One Zone-Infrequent Access (S3 One Zone-IA)
    - 只儲存在單一個 AZ 中, 因此需要有能力能自行從單一個 AZ 事件中恢復
    - storage price 比 S3 Standard-IA 更低
  - S3 Intelligent-Tiering
    - 適合先前未知使用頻率, 由實際的使用頻率交給 Amazon 來決定儲存模式
    - 在 S3 Standard 與 S3 Standard-IA 中切換
  - S3 Glacier Instant Retrieval
    - 長期儲存, 非常少使用的, 但是能立即取得的
    - Retrieve object 的速度會在 milliseconds, 等同於 S3 Standard
  - S3 Glacier Flexible Retrieval
    - 長期儲存, 非常少使用的, 取得時間會在數分鐘到數小時之間
    - Retrieve object 時間在 1 分鐘到 12 小時之間
  - S3 Glacier Deep Archive
    - 長期儲存, 非常少使用的, 取得時間會大於 12 小時
    - Retrieve object 時間在 12 小時到 48 小時之間
  - S3 Outposts
    - 配合 AWS Outposts 環境使用
    - 建置在 on-premises 環境上

Comparing Amazon EBS and Amazon S3

- Amazon EBS
  - 適合會有大量小改變的檔案
- Amazon S3
  - 適合 write once read many 情境
  - Web based, 每個 object 自帶 URL
  - 不用擔心 backup, 本身已經有非常高的 durability

Amazon Elastic File System (Amazon EFS)

- Shared file folders
- 不同於 block storage 和 object storage,
  - file storage 適合用於多個服務同時使用同一個資料
- Amazon Elastic File System (Amazon EFS)
  - AWS 提供的具有 auto scaling 的 linux file system
  - 屬於 Regional level 的服務, 資料可以在同個 region 內, 跨多個 AZ 存取
  - On-premises data center 也可以通過 AWS Direct Connect 存取

Relational databases

- 對於 AWS 管理有不同程度的服務, 分別為
  - 直接建立在 EC2 上
  - 建立在 Amazon RDS 上
  - 使用 Amazon Aurora
- Amazon Relational Database Service, (Amazon RDS)
  - Amazon 的 relational database 服務
  - 支援數種常見的 database engines
  - Amazon Aurora, PostgresSQL, MySQL, MariaDB, Oracle Database, Microsoft SQL Server
  - 內建 automated patching, backups, redundancy, failover, disaster recovery
- Amazon Aurora,
  - AWS 提供的 relational database
  - 相容於 MySQL 與 PostgresSQL
  - 內建自動備份至 S3, 6 份 Replicates 在 3 個不同的 AZ
  - 可以設定至多 15 個 read replicas

Nonrelational databases

- Nonrelational databases, NoSQL
- 其中一種類型是 key-value pairs database
- Amazon DynamoDB
  - Amazon 所提供的 NoSQL database
  - 屬於 key-value database
  - Serverless 服務
  - Automatic scaling
  - 是可以大量 scalable 的同時保有 millisecond response time
  - 只適用於特殊的使用案例
- Amazon RDS vs Amazon DynamoDB
- Amazon RDS
  - 支援複雜的 SQL query
  - 換句話說, 只有會使用到複雜的 relational 分析時, 才應該選用 RDB
- Amazon DynamoDB
  - Query 時無法進行複雜的運算, 主要是集中所需的 collection
  - 比起 RDB, NoSQL 有更好的 throughput, 更高的效能, 也更便宜

Data warehousing

- 當要處理的資料是不會再次變動的內容 (已經確定的, 過去的) 並且有巨大數量級
  - 在 relational database 上會遇到瓶頸
  - 更適合放在 data warehousing 進行處理
  - 換句話說, 要進行資料分析的資料庫, 應該分開使用專門的資料庫類型, 即 data warehouse
- Amazon Redshift
  - Amazon 提供的 data warehousing 解決方案

Database Migration

- AWS Database Migration Service (AWS DMS)
  - 資料庫搬移服務
  - 用於減少 downtime
  - 適用於相同的資料庫型別, homogenous
  - 適用於不相同的資料庫型別, heterogenous
  - 移動方式
    - Source, on-premisses, EC2, RDS
    - Target, EC2, RDS
  - 除了適用於資料庫搬遷外, 還是用於以下情境
  - 建立測試用的資料庫 (直接從 production 進行複製), 多個資料庫整合成一個, 動態持續的資料庫 replication

Additional Database Services

- Amazon DocumentDB
  - NoSQL, document database, content management system (CMS), 支援 MongoDB
- Amazon Neptune
  - NoSQL, graph database
- Amazon Quantum Ledger Database (Amazon QLDB)
  - NoSQL, ledger database, 所有的資料都是 immutable
- Amazon Managed Blockchain
  - Blockchain 服務
- Amazon ElasticCache
  - In-memory cache, 支援 Redis 和 Memcached
- Amazon DynamoDB Accelerator (DAX)
  - DynamoDB 專用的 in-memory cache

---

### 第八章 - Module 6: Security

AWS Shared Responsibility Model

- AWS 管理 cloud 本身的安全性 (security of the cloud), AWS foundation services
- Customer 管理在使用 cloud 裡的安全性 (security in the cloud), customer data

AWS Identify and Access Management (IAM)

- AWS account root user
  - **Best Practice**: turn on MFA for root user
  - **Best Practice**: 不要使用 root user 作為日常, 使用個別的 IAM user 取代
- IAM users
  - 代表一個使用者或一個服務, 會與其他 AWS services 互動
  - 包含 name 和 credentials
  - 預設是沒有任何權限
  - **Best Practice**: 每個人都有一個各自的 IAM user account, 不要共用
- IAM policies
  - 一個 document 預先設定的權限 (permissions)
  - `Effect`: `Allow` 或 `Deny`
  - `Action`: 任何的 AWS API
  - `Resource`: API 作用的對象 (object)
  - **Best Practice**: 依據最小權限原則 (least privilege principle) 來設定權限, 不要給予任何超過工作內容的權限
- IAM groups
  - 與其針對每個 IAM user 做個別設定, 應該使用 group 來群體設定
- IAM roles
  - 主要用於暫時性的 (temporary) 權限給予
  - **Best Practice**: IAM role 只使用在暫時性的權限給予, 不做任何長期使用
- Multi-factor authentication, MFA
  - 啟用 MFA 提升安全性

AWS Organizations

- 集中多個 AWS accounts 集中管理, 限制所屬的 AWS services 和 resources
- Service control policies (SCPs), 設定最大權限限制
  - 作用對象為 OU (organization unit) 和每個獨立的帳號 (individual account)
  - 與 IAM policies 不同的是 SCPs 是設定最大權限限制, 來進行責任隔離
- Consolidated billing, 集合帳單支付並且設置個別限制
- Organizational units,
  - 每個 OU 可以設置獨立的權限
  - 以 hierarchical 的方式建立
  - 類似於 business unit

AWS Compliance

- AWS Artifact
  - 提供 AWS security 和 compliance reports
  - 內容包含兩類
  - AWS Artifact Agreements, 提供與 AWS 簽訂合規合約
  - AWS Artifact Reports, 提供由第三方檢驗的 AWS 合規報告
- Customer Compliance Center
  - 提供學習各種不同 AWS compliance 來合乎各種不同規定的學習資源
  - 也可以通過查看 compliance whitepapers 和 documentation

Distributed Denial-of-service attack, (DDoS attack)

- Denial-of-service attack examples
  - UDP flood, 針對底層網路的攻擊
  - Slowloris attack, 針對 HTTP 層的攻擊
- 好的程式架構 (good architecture) 就足以防禦大多數的 DDoS attack
  - 例如使用 ELB
- 設定嚴謹的 Security Group 可以防禦來自網路底層的攻擊
- AWS Shield
  - AWS 服務來協助防禦 DDoS attack
  - Standard, 免費服務, 防禦常見的 DDoS attack
  - Advanced, 付費服務, 提供更詳盡的分析與防禦更複雜的 DDoS attack
- AWS WAF
  - 可以配合 AWS Web Application Firewall (AWS WAF) 服務來防禦

Additional Security Services

- Encryption 在任何階段都進行加密, in store, in transit, ...
  - secure socket layer, (SSL connection)
- AWS Key Management Service (AWS KMS)
  - AWS 金鑰管理
- AWS Web Application Firewall (AWS WAF)
  - 應用層網路管理, 通過設定 web access control list (ACL) 來阻擋
- Amazon Inspector
  - 自動測試調查報告, 查看是否符合安全性的 best practice
- Amazon GuardDuty
  - 智能偵測危害
  - 開啟後會持續的監控 network 和 account activity

---

### 第九章 - Module 7: Monitoring and analytics

Amazon CloudWatch

- Amazon CloudWatch
  - 提供 monitoring, 管理 metrics, 設定 metrics alarm
- CloudWatch alarms
  - 可以發出 event 連結其他服務
- CloudWatch dashboard
  - monitoring 所有的 AWS services, 在同一個地方可以看到結果
- Mean time to resolution, MTTR
- Total cost of ownership, TCO

AWS CloudTrail

- AWS CloudTrail
  - API auditing tool
  - 記錄所有的 API calls, log of actions, What, Who, When, How
  - 會有完整的歷史紀錄, 來協助除錯, 監控安全漏洞等等
  - API call 發生後會在 15 分鐘內被記錄在 CloudTrail
- CloudTrail Insights
  - 可以選用的啟動 CloudTrail Insights 來自動捕捉不尋常的 API 行為
- Trust but verify, 信任但確認
- 紀錄會被存在 S3 buckets, 配合 Vault Lock 的使用提供無法被篡改的 log 紀錄

---

### 第十章 - Module 8: Pricing and support

---

### 第十一章 - Module 9: Migration and innovation

---

### 第十二章 - Module 10: The cloud journey

---

### 第十三章 - Module 11: AWS certified cloud practitioner basics

---

### 第十四章 - Final Assessment

---
