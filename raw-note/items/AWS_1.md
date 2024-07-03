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

---

### 第七章 - Module 5: Storage and databases

---

### 第八章 - Module 6: Security

---

### 第九章 - Module 7: Monitoring and analytics

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
