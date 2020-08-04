## Firebase Cloud official documentation - Firestore

### [Website resource](https://firebase.google.com/docs/firestore), Firebase

---

第一章 - Introduction

第二章 - Get started

第三章 - Understand Cloud Firestore

第四章 - Add and manage data

第五章 - Read data

第六章 - Secure and validate data

第七章 - Solutions

第八章 - Usage, limits, and pricing

第九章 - Cloud Firestore integrations

第十章 - API reference

第十一章 - Samples

---

### 第一章 - Introduction

---

### 第二章 - Get started

#### 創建流程

1. Create project
1. Create Database
1. Select Cloud Firestore Security Rules
1. Select location (GCP)

- Cloud Firestore (Firebase) 與 Cloud DataStore (GCP) 無法共存。

#### 基礎操作

- 環境設定
- 初始化
- 新增資料
- 讀取資料
- 權限設定

#### [Getting Started With Cloud Firestore on the Web - Firecasts](https://www.youtube.com/watch?time_continue=1&v=2Vf1D-rUMwE&feature=emb_logo)

---

### 第三章 - Understand Cloud Firestore

#### 比較與選擇 Cloud Firestore 或 Realtime Database

- Cloud Firestore 新 (推薦使用), Realtime Database 舊
- 皆是 NoSQL
- Data Model 不同, Cloud Firestore Collections of documents, Realtime Database 一個巨大的 JSON
- 離線支援，支援度少許不同。Cloud Firestore 較佳
- Querying, 效能, 擴張性, 安全性都是 Cloud Firestore 較佳
- 兩種資料庫**可以**同時使用

#### Data Model

- Document-oriented database
- 資料儲存在 Document, 集合成 Collections
- Document 是 key-value pair 的集合
- Document 必須存在某個 Collection 裡
- Document 裡允許有子代 Collection

- Documents

  - 可視為有大小限制 (1MB) 並且擁有更多資料型別的 JSON
  - 單一的資料集合實體
  - ID 可自選或自動生成

- Collections

  - Documents 的容器
  - 每個 Document 在相同的 Collection 中時名稱必須是唯一的。(類似資料夾裡的檔案名稱)

- References, 可以任意建立資料庫裡位置的參考, 以方便操作。(不需使用網路)

  - Reference to a document / Reference to a collection

- Hierarchical Data

  - Document 必須是輕量的，因此要善用 sub-collection 生成適當的結構。
  - 結構深度最多為 100 層
  - 單獨刪除 Document 並不會同時移除他的 sub-collections 需要手動操作。

#### Data Types

- Array 陣列
- Boolean
- Bytes, 容量上限 1MB, 只有前 1500 bytes 會被搜尋得到
- Date and time 日期與時間
- Float 浮點數, 64-bit double, IEEE754
- Geographical point 經緯度
- Integer 整數, 64-bit, signed
- Map, Key-value pairs, key ordered
- Null
- Reference, 資料庫中的路徑
- Text string, UTF-8, 容量上限 1MB, 只有前 1500 bytes 會被搜尋得到

#### SDKs 與 API

- mobile, web, server client libraries
- 通過 mobile/web SDKs 可以實現 serverless 架構
- server client libraries 擁有特權可以存取完整的 Database 因此權限由 IAM 控制。(Firebase Admin SDKs/ Google Cloud client libraries)
- 其他第三方整合, [清單](https://firebase.google.com/docs/firestore/library-integrations)

#### Index Types

- index 與資料庫效能
- Cloud Firebase 所有的 query 都使用 index，因此不需要搜尋完整的資料庫。並且 index 自動生成與管理。
- Index types
  - Single-field indexes, 自動 indexing 並且可以設定, 可額外手動設定 index exemptions 以提昇效能。
  - Composite, 需手動設定, Firebase log 會有引導。
- Index modes, Ascending, Descending, Array-contains
- Query scopes, Collection scope, Collection group scope
- Pricing, Indexes 由佔有的空間計費
- Indexing limits, 有容量或數量限制
- Best Practices
  - 使用 exemptions 的時機
  - 大型字串欄位, 不需要 querying 的大型字串內容可以使用 index exemption
  - 高速寫入的欄位, 例如 timestamp, 並且不需要 querying 時
  - 大型陣列或 Map, 容易衝破 index 數量限制, 如果不需要 querying 時

#### Database locations

- Default GCP resource location 設定後不能更改, 設定套用至 Cloud Firestore, Cloud Storage, Google App Engine app

---

### 第四章 - Add and manage data

---

### 第五章 - Read data

---

### 第六章 - Secure and validate data

---

### 第七章 - Solutions

---

### 第八章 - Usage, limits, and pricing

---

### 第九章 - Cloud Firestore integrations

---

### 第十章 - API reference

---

### 第十一章 - Samples

---
