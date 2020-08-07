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

- config setup
- document Reference
- `set()`
- `get()`
- document reference `onSnapshot()` listener
- `doc()`

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

##### [What is a NoSQL Database? How is Cloud Firestore structured? | Get to know Cloud Firestore #1](https://www.youtube.com/watch?time_continue=9&v=v_hR4K4auoQ&feature=emb_logo)

- Cloud Firestore
- NoSQL, schemaless
- 配合使用場景產生 document，因此資料庫中可能存在重複的資料。
  - 讀取很快，寫入會相對麻煩。
  - 容易擴充, 可以跨機器架設。

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

#### Structure data

資料存放結構選擇

- 單一 document,
  - 好處: 簡單
  - 壞處: 持續增加的資料不適合，大的 Map 或 Array 會影響效能
  - 使用時機: 固定項目的資料
- sub-collection 與 document 組合,
  - 好處: 保持讀取速度不被影響
  - 壞處: 刪除時較複雜，需手動一層一層刪除
  - 使用時機: 會持續增加的資料使用 sub-collection 結構存放
- root 層多個 collections,
  - 好處: 適合多對多結構
  - 壞處: 擴張時結構變得複雜, 適應使用場景不易
  - 使用時機: 與使用場景無關時的資料集合

#### Add data

新增資料的方式

- 明確的指定 document 與 `set()` properties
- 直接增加新的 document (含資料) 到 collection 中, Cloud Firestore 會自動生成 document id
- 新增空的 document 到 collection 中, 未來在填上資料

##### 指名新增修改 `set()`

- 新增/修改 document, `set()`
- 合併 `set( , { merge: true })`

Data types

- 數字都被當成 double 所儲存

Custom objects

- 直接儲存物件
- 需額外實作 Firestore data converter function, [參考程式碼](https://github.com/firebase/snippets-web/blob/3eabc6557db7cbc30b12e25dc08ed1a384f04ae1/firestore/test.firestore.js#L202-L226)

##### Add a document, `add()`, `doc().set()`

- 不需要指定 document id, 由 Cloud Firestore 自動生成
- 自動生成的 id 並不保證 ordering, 如果需要排列需要自行儲存 timestamp

語法

- collection `.add()`
- collection `.doc()`, 創造並且回傳 document reference, 再使用 reference `.set()` 存放資料

##### Update a document, `update()`

修改 document 中的部份欄位

- document reference `.update({ })`
- 伺服器端的 timestamp, `update({ timestamp: firebase.firestore.FieldValue.serverTimestamp() })`
- 更新 document 中的子物件內容, 通過 dot notation 指名
  - 如果忘記使用 dot notation 指名, 會**覆蓋整個子物件內容**
- 修改 array 欄位, `arrayUnion()`, 新增 (會檢查是否重複), `arrayRemove()`, 移除
  - `update({ arrayFieldName: firebase.firestore.FieldValue.arrayUnion("") })`
  - `update({ arrayFieldName: firebase.firestore.FieldValue.arrayRemove("") })`
- 操作數值, 增加或減少數值欄位, 如果欄位非數值會被覆蓋, `increment()`
  - `update({ numericFieldName: firebase.firestore.FieldValue.increment() })`
  - 每個 document 更新速度最快是 1 秒一次, 如果更新需要比這個速度更快則需要使用其他方法

#### Transactions and batched writes

atomic 的 read 與 write

- Transactions, 一個 transaction 是一組 read 與 write 的集合
- Batched Writes, 一個 batched write 是一組 write 的集合
- 每個動作寫入上限是一次 500 個 documents

##### Transactions

可以應付同步 (concurrent) 的狀況, 如果遇到碰撞則會重新執行 transaction 保證正確性, transaction 沒有部份成功。

Transactions 使用指南

- 讀取必須在寫入之前
- 執行的 transaction 可能會多次執行, 如果遇到碰撞時 (不保證執行次數)
- Transaction function 不應該直接修改 application state (因為不保證一次完成, 錯誤時可能導致 state 不一致)
- 如果客戶端離線 (offline), 會導致 Transaction 失敗

語法請參考[文件](https://firebase.google.com/docs/firestore/manage-data/transactions#transactions)

- 應用程式的狀態修改應該接在, Transaction 執行成功後的 promise 裡

Transaction failure

- 讀寫順序錯誤, 讀取必須在寫入之前
- 遇到碰撞, 會重試有限次
- request 大小超過 10 MB
- 失敗不需要 rollback, 因為 atomic 動作, 沒有部份成功

##### Batched writes

組合任意 `set()`, `update()`, `delete()`, 形成的 atomic operation

語法

- db `.batch()`
- batch reference `.set()`, `.update()`, `.delete()`
- batch reference `.commit()`

特性

- 組合數量上限是 500 個動作
- 客戶端離線也可以成功
- 因為沒有 read 因此碰撞機會較少
- **server client library** 提供平行寫入 API, 能提供比 Batched writes 更快速的寫入。

##### 資料驗證

- 使用 Cloud Firestore Security Rules 驗證資料與執行伺服器端工作 `getAfter()`

#### Delete data

Delete documents

- document reference `.delete()`
- 刪除 document 並**不會一同刪除** sub-collections, 需手動執行, 並且未被刪除的 sub-collections 然仍能用路徑去讀取。

Delete fields

- `update({ fieldName: firebase.firestore.FieldValue.delete() })`, 指定欄位刪除

Delete collections

- 由於刪除並沒有辦法遞迴刪除子代, 因此避免 out-of-memory errors, 需要使用 batch 執行
- 不推薦在 client-side (web/mobile) 執行類似的刪除, 僅推薦在可相信的 server-side 去執行類似指令。

其他刪除方式

- Firebase CLI
- Cloud Firestore console

#### Manage Cloud Firestore with the Firebase Console

從 Firebase web console 操作資料庫

- 讀,寫 ,修改, 刪除
- 調整 Cloud Firestore Security Rules
- 管理 indexes
- 監測使用量, (console 操作也算在使用量內)

特點

- console 執行刪除 document, 可以一同刪除 sub-collections

#### Export and import data

資料匯入與匯出, 可用於備份

前置動作

- 必須啟用計費才能使用功能, GCP project with billing enabled
- 創建一個 Cloud Storage bucket
- 權限設定

#### Move data between projects

通過資料匯入與匯出功能, 需付費

---

### 第五章 - Read data

#### Get data once

讀取資料

- 呼叫函式 `get()`
- 設置 listener

Get a document

- `get()` 回傳 promise
- 設置 Source Options 用來支援離線功能, 讀取 cache, `get(config)`, 傳入 config 物件, 設置 `source` property
- 讀取 Custom objects 中的資料, 需要透過實作 Firestore data converter, 呼叫 document reference `.withConverter(customConverterObject).get()`, [範例程式碼](https://firebase.google.com/docs/firestore/query-data/get-data#custom_objects)

Get from collection

- 讀取一個 collection 中的多個 documents 通過 `where()` 做 querying, collection reference `.where().get()`, [範例程式碼](https://firebase.google.com/docs/firestore/query-data/get-data#get_multiple_documents_from_a_collection)
- 讀取 collection 中所有的 documents, 不需要通過 `where()`, 直接呼叫 `get()`, collection reference `.get()`, [範例程式碼](https://firebase.google.com/docs/firestore/query-data/get-data#get_all_documents_in_a_collection)
- 讀取同名 sub-collection 中的資料, 通過 compound queries
- 讀取一個 document 中所有的 sub-collections, web/mobile client-side 不支援, 可信任的 server-side 有提供 API

#### Listen for realtime updates

註冊 `onSnapshot()` listener

- document reference `.onSnapshot((doc) => { doc.data() })`

Event for local changes

- 在客戶端觸發 write 時, 會立即觸發 `onSnapshot` event, 就算在 server-side 還沒改變時
- 可以通過 `metadata.hasPendingWrites` 屬性來做區分, `onSnapshot( (doc) => { doc.metadata.hasPendingWrites ? 'Local' : 'Server' })`

Event for metadata changes

- 預設不會監聽 metadata 改變
- 可以通過傳入 config 開啟, `onSnapshot({ includeMetadataChanges : true }, (doc) => {} )`
- 例如 local change 時 metadata `pending writes` 會改變成 `true`, 成功寫入後端後會回傳並且改變狀態 `pending writes` 成 `false`
- 如果只是單純需要監聽寫入成功與否, 可以通過 write 動作的 Promise 做判斷即可 (`.then()`)。

Listen to multiple documents in a collection

- Listen to query, 監聽 query 並且在每次搜尋結果變更時收到通知, 使用 `onSnapshot()`, 取代 `get()`
- `.where().onSnapshot( (querySnapshot) => { querySnapshot.forEach( (doc) => { doc.data() }) })`, [範例程式碼參考](https://firebase.google.com/docs/firestore/query-data/listen#listen_to_multiple_documents_in_a_collection)

View changes between snapshots

- 只讀取改變的資料, 並且可以通過 type 去做區分, `.docChanges()`, `.type`, [範例程式碼](https://firebase.google.com/docs/firestore/query-data/listen#view_changes_between_snapshots)
- 第一次讀取時就算資料沒有改變也會觸發 `add` type change, 方便初始化畫面時使用。

Detach a listener

- 取消監聽, 通過執行註冊 onSnapshot 時的回傳函式, [範例程式碼](https://firebase.google.com/docs/firestore/query-data/listen#detach_a_listener)

Handle listen errors

- `onSnapshot()` 可以傳入處理 error 的函式, 但是 listen fail 並不需要手動取消 listener

#### Perform simple and compound queries

Simple queries

- Create a query, reference `.where()`
- Execute a query, query `.get()`, `.then( (querySnapshot) => { querySnapshot.forEach( doc => doc.data() ) })`
- Execute a query with snapshot listener, query `.onSnapshot()`
- Query operators, `where( field, comparison_operation, value)`,
  - comparison operations, `<`, `<=`, `==`, `>`, `>=`, `array-contains`, `in`, `array-contains-any`

Array membership

- `array-contains`,
- `in`, OR 關係, 完全相等才會納入
- `array-contains-any`, OR 關係, 包含則納入, 回傳是 de-duped 的 array
- Limitations,
  - `in` 跟 `array-contains-any` 最多 10 個比較值
  - `in` 跟 `array-contains-any` 不能同時使用
  - `array-contains` 可與 `in` 同時使用, `array-contains-any` 則不能
  - 使用 `=` 和 `in` 時回傳結果不能排序

Compound queries

- Chained `where()`, AND 關係
- Range filters (`<`, `<=`, `>`, `>=`) 只能作用在一個欄位上，即不能有多個不同欄位使用到 range filters

Collection group query

- 搜尋跨 documents 的同名 sub-collections
- `collectionGroup( collectionId ).where()`, [範例程式碼](https://firebase.google.com/docs/firestore/query-data/queries#collection-group-query)
- 使用 collection group query 之前需要先手動建立 index

Query limitations

- 多個不同欄位的 range filters 同時使用是不支援的
- 沒有 `!=` 關係, 需要針對同欄位組合 range filters 達成
- 沒有廣泛的支援 OR 關係, 希望建立多個 query 並且在客戶端組合
- `in` 跟 `array-contains-any` 無法同時使用
- `array-contains` 跟 `array-contains-any` 無法同時使用
- 無法排序 `=` 或 `in` 的結果

#### Order and limit data

Order amd limit data

- query ordering 的預設是 document ID 的 ascending order
- 使用 `orderBy()` 改變排序使用的欄位和順序 `desc` for descending order
- 使用 `limit()` 改變取得的數量
- 串連 `orderBy()` 排序多個欄位

Limitations

- 使用 `orderBy()` 時, 不包含指定欄位的 document 會被省略。
- 組合使用 range comparison `where()` 時, 第一個連接的 `orderBy()` 必須是相同欄位
- `=` 和 `in` query 無法使用 ordering

#### Paginate data with query cursors

Add a simple cursor to a query

- 使用 `startAt()` 或 `startAfter()` 去指定 query 結果的開頭
- 使用 `endAt()` 或 `endBefore()` 去指定 query 結果的結尾

Use a document snapshot to define the query cursor

- 把已經讀取到的 document snapshot 用於 query
- [範例程式碼](https://firebase.google.com/docs/firestore/query-data/query-cursors#use_a_document_snapshot_to_define_the_query_cursor)

Paginate a query

- 配合 `startAfter()` 與 `limit()` 分頁讀取 query 結果
- [範例程式碼](https://firebase.google.com/docs/firestore/query-data/query-cursors#paginate_a_query)

Set cursor based on multiple fields

- `startAt()` 或 `beforeAt()` 使用準確的值
- 當單個欄位搜尋不精確時, 可以組合多個欄位使用 `orderBy()` 和 `startAt()` 值來取得所需的內容。
- [範例程式碼](https://firebase.google.com/docs/firestore/query-data/query-cursors#set_cursor_based_on_multiple_fields)

#### Access data offline

藉由 cache Cloud Firestore data 在 client-side 達成 offline 功能 (寫入, 讀取, 註冊監聽, 搜尋結果)

- 在恢復連線後會自動同步
- 客戶端只支援 Android, iOS, web apps
- 只要開啟離線功能, 線上離線資料管理與同步會由 library 自動完成

Configure offline persistence

- Android, iOS 預設開啟, Web 預設關閉
- Web 啟動 `firebase.firestore().enablePersistence()`, 由於資料不會自動清除, 如果有敏感資料時, 最好經過用戶授權確認是可信任的機器。
- Cache size 預設是 40MB 超過會自動刪減, 可以通過 settings 設定 cache size, [範例程式碼](https://firebase.google.com/docs/firestore/manage-data/enable-offline#configure_cache_size)

Listen to offline data

- 使用 `onSnapshot()` 監聽時, 如果是離線的狀態下會從 cache 中取得, 可以通過 `SnapshotMetadata` 中的 `fromCache` 去判斷這次的事件資料來自於伺服器或者 cache
- [範例程式碼](https://firebase.google.com/docs/firestore/manage-data/enable-offline#listen_to_offline_data)

Get offline data / Query offline data

- 離線且沒有 cache 的狀態下,
  - query a collection, 會回傳空值
  - query a document, 會回傳 error
- 離線的狀態下, 也可以創建新的 query, 結果會建立在 cache 上

Disable and enable network access

- 可以通過 API 去控制客戶端的連線狀態
- Write operations 會在儲存在 queue 中等待連線恢復
- `firebase.firestore().disableNetwork()`, `firebase.firestore().enableNetwork()`, 皆回傳 Promise
- [範例程式碼](https://firebase.google.com/docs/firestore/manage-data/enable-offline#disable_and_enable_network_access)

#### Manage indexes

- Cloud Firestore 為了效能因此所有的 query 都是使用 index 來進行的。
- 基本的 query 所使用的 index 會自動生成。
- 如果執行沒有設置 index 的 query 時會丟出 error。

Create a missing index through an error message

- 錯誤訊息中會含有 Firebase console 的連結, 可以從 Firebase Web console 中新增或刪除 indexes
- [操作範例](https://firebase.google.com/docs/firestore/query-data/indexing#use_the_firebase_console)

Use the Firebase CLI

- 通過 [Firebase CLI](https://firebase.google.com/docs/cli), 也可以設置 indexes
- [範例參考](https://firebase.google.com/docs/firestore/query-data/indexing#use_the_firebase_cli)

1. Setup, `firebase init firestore`
1. 編輯 JSON 設置 indexes
1. Deploy `firebase deploy`

Index build time

- 監控 index build time
- [操作流程參考](https://firebase.google.com/docs/firestore/query-data/indexing#index_build_time)

Index building errors

- 最常見的錯誤是達到 index 數量上限
- Console 中會有錯誤訊息

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
