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

- Mobile / Web, 通過 Firebase Authentication 與 Cloud Firestore Security Rules 去實現權限管理
- Server Client libraries, 通過 Identity and Access Management (IAM) 去管理權限

#### Get started

- 要做到 user-based 權限管理需要配合 Firebase Authentication
- 使用新版的 Security rules, `rules_version = '2';` 來啟用 recursive wildcards `**`, [說明參考](https://firebase.google.com/docs/firestore/security/get-started#security_rules_version_2)

Writing rules

- `match`, 指定 documents
- `allow`, `if <condition>`, 權限設定
- mobile/web client library 在執行讀取或寫入前都會先經過 rules 檢查, 只要違反任一權限都會讓整個請求失敗。

Testing rules

- 通過 Firebase Cloud Firestore console, 可以從 Rules Playground 測試寫好的 rules

Deploying rules

- 部屬 rules 到所有 listeners 完成更新, 需要花 1 ~ 10 分鐘
- 通過 Firebase console, 點選發佈 (Publish) 即可
- 通過 Firebase CLI, `firebase deploy --only firestore:rules`, 如果使用 CLI 部屬會直接覆蓋掉 Firebase Console 上的 Rules
- 如果同時使用 Firebase console 與 Firebase CLI 時需要手動同步設定檔至本地端。

#### Structure Security Rules

Service and database declaration

- 開頭的宣告是固定的
- `service cloud.firestore {`, 表明是 cloud firestore 所使用的 rules
- `match /databases/{database}/documents {`, 指定 rules 影響 project 中所有的 databases, (目前限制一個專案只有一個資料庫)

Basic read/write rules

- `match`, 指定適用的 documents 路徑, 指定明確的單一 document, 或者不定數量的多個 documents
- `allow <operations> :if <condition>;`, 指定動作與限制條件
- 沒有明確設定 rules 的其他 documents 權限預設是 deny
- [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-structure#basic_readwrite_rules)

Granular operations

- 除了設定 `read` 與 `write` 之外，可以設定更細緻的動作權限
- `read` 可以分成 `get`, `list`
- `write` 可以分成 `create`, `update`, `delete`

Hierarchical data

- 針對 document 的權限設定並不會自動套用到 sub-collections 中，子代的 documents 需要額外的明確設定規則才能開通。
- 如果子代的權限跟父層的權限永遠相依,
  1. 可以使用單一路徑整合權限,
  1. 使用 recursive wildcards `{document=**}` 表明所有 documents 包含所有子代
- Recursive wildcards 的行為跟 rules 版本有關, Version 2 才能設定 collection group 的權限
- [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-structure#hierarchical_data)

Overlapping match statements

- 一個 document 如果適用多組 `match`, 只要有任一組允許 (true) 則權限開啟, 與 rules 順序無關

Security rule limits

- 各種數量與容量限制
- [參考文件](https://firebase.google.com/docs/firestore/security/rules-structure#security_rule_limits)

#### Writing conditions for Security Rules

Authentication

- 有登入的使用者, `if request.auth != null;`
- 使用者只能讀取本身的資料,
- 通過變數 `request.auth` 取得更多資訊來做判斷, [request.auth 文件](https://firebase.google.com/docs/reference/rules/rules.firestore.Request#auth)
- [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-conditions#authentication)

Data validation

- 依據 document 欄位的值，動態設置權限 `if resource.data.`, [resource.data 文件](https://firebase.google.com/docs/reference/rules/rules.firestore.Resource)
- 資料驗證可以使用 `request.resource.data.<fieldName>`, 比對資料是否要被接受
- 資料驗證也可以通 `resource.data.<fieldName>`, 取得現有資料來做比對
- [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-conditions#data_validation)

Access other documents

- 使用其他 document 的資料來協助判斷, `get()`, `exists()`, 需要使用 rules `match` 路徑方式表達
- Access call limits, 請求動作是有數量限制的, 超過數量會回報錯誤, 細節參考[文件](https://firebase.google.com/docs/firestore/security/rules-conditions#access_call_limits)
- Pricing, 這些 read 動作也會被記入帳單, 無論資料最後有沒有被接受。
- [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-conditions#access_other_documents)

Custom functions

- 越來越複雜的 rules 設定, 可以利用 domain-specific language 撰寫 function 來重用。
- 類似 JavaScript function 但是有以下限制
  - Function 內部只是一個 `return` 敘述, 並且不能呼叫外部服務 (service) 與使用迴圈 (loop)
  - Function 可以依據定義時的 context 產生可以使用的 build-in function 與全域變數
  - Function 可以呼叫其他函式, 但是無法遞迴呼叫並且 call stack 上限是 10 個
  - 在 rules `v2` 版本, 可以使用至多 10 個 `let` 定義變數

Rules are not filters

- 不要使用 rules 來省略 query 時的 `where()` 條件
- [範例](https://firebase.google.com/docs/firestore/security/rules-conditions#rules_are_not_filters)

#### Fix insecure rules

Understand your Cloud Firestore Security Rules

- 預設 deny 所有權限, 需要時才明確的開啟權限
- 在實際 apply 之前, 可以先通過模擬器做過權限測試

Common scenarios with insecure rules

- Open access, 無任何限制的權限
  - 解法, 依據 Firebase Authentication, 去設定讀寫權限, [範例程式碼](https://firebase.google.com/docs/firestore/security/insecure-rules#open_access)
- Access for any authenticated user, 任何 logged-in 使用者能任意讀寫完整的資料庫
  - 解法, 依據屬性或不同的使用者來限制讀寫權限, [範例程式碼](https://firebase.google.com/docs/firestore/security/insecure-rules#access_for_any_authenticated_user)
- Closed access, 關閉所有客戶端權限
  - Firebase Admin SDKs 和 Cloud functions 仍然可以讀取資料庫, 只有在 Cloud Firestore 提供給 server-only 的情況下採用這種 rules [設定](https://firebase.google.com/docs/firestore/security/insecure-rules#access_for_any_authenticated_user)

Check your Cloud Firestore Security Rules

- 在發佈前先經過 Cloud Firestore emulator 模擬測試
- Firebase web console 中 Cloud Firestore Security Rules, **Rules Playground**

#### Test your Security Rules

- 使用 CLI 在本地端操作 local emulator 是 bata 版的功能

Understand Cloud Firestore Security Rules

- 權限控管實現由 Firebase Authentication 與 Cloud Firestore Security Rules 設定實現
- Firebase Authentication 實現 user-based / role-based 使用者驗證
- Cloud Firestore Security Rules 實現 Web/mobile client libraries 讀寫限制與寫入資料驗證

Install the emulator

- 通過 [Firebase CLI](https://firebase.google.com/docs/cli/) 在本地端啟用 firestore local emulator,
- `firebase setup:emulators:firestore`

Run the emulator

- `firebase emulators:start --only firestore`, 啟動後不會自動關閉
- `firebase emulators:exec --only firestore "./my-test-script.sh"`, 啟動後執行完測試後自動關閉
- 預設執行在 8080 port, 可以通過在 `firebase.json` 中設置項調整 `"emulators: { "firestore": { "port": "8080" } }"`

Before you run the emulator

Run local tests

- [範例參考](https://firebase.google.com/docs/firestore/security/test-rules-emulator#run_local_tests)
- `initializeTestApp({ projectId: string, auth: Object }) => FirebaseApp`, 假定測試權限
- `initializeAdminApp({ projectId: string }) => FirebaseApp`, 假定使用 admin 權限
- `apps() => [FirebaseApp]`, 列出所有執行中的 test 與 admin apps, 可以用來清除已經完成的測試。
- `loadFirestoreRules({ projectId: string, rules: Object }) => Promise`, 載入新規則 (security rules)
- `assertFails(pr: Promise) => Promise`, 驗證 deny
- `assertSucceeds(pr: Promise) => Promise`, 驗證 allow
- `clearFirestoreData({ projectId: string }) => Promise`, 清除現有測試資料
  - emulator 執行任何指令都不會自動清除存在記憶體中的測試資料庫, 如果有資料相依性的問題, 需要手動呼叫清除 `clearFirestoreData`

Generate test reports

- 通過瀏覽器開啟測試報告, 預設連結[參考](https://firebase.google.com/docs/firestore/security/test-rules-emulator#generate_test_reports)

Differences between the emulator and production

- 不需要實際創造新的 Cloud Firestore project. Local emulator 會自動創建測試用資料庫
- 不需要實際通過 Firebase Authentication 登入流程, 通過 `initializeTestApp()` 即可設置測試使用者。

Troubleshoot known issues

- 常見問題與解決方案, [參考文件](https://firebase.google.com/docs/firestore/security/test-rules-emulator#troubleshoot_known_issues)
- Test behavior is inconsistent, 測試時好時壞
- Test only pass the first time you load the emulator, 測試只有在第一次載入時成功
- Test setup is very complicated, 複雜的測試權限設定

#### Securely query data

- Cloud Firestore Security Rules 限制 query 的範例, 包含有 `limit` 和 `orderBy` 的 query 。
- Rules are not filters, 不要使用 Security Rules 作為 get filters,
  - 讀取全部或失敗, 沒有部份讀取
  - 以提昇效能與資源利用

Queries and security rules

- Secure and query documents based on **auth.uid**

  - 依據使用者, `request.auth.uid` 跟 `resource.data.` 裡存的使用者 id 比對
  - query 時也需要在 `where` 上加上正確的 `uid`, 否則 query 不會成功, 因為 query 整個 collection 下的 documents 會包含非使用者的內容。
  - [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-query#secure_and_query_documents_based_on_authuid)

- Secure and query documents based on field

  - 讀寫條件可以使用 `||` or 關係，達成多重條件
  - [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-query#secure_and_query_documents_based_on_a_field)

- `in` and `array-contains-any` queries

  - 會獨立比對所有的值, 只要出現任何 deny 的狀況, 都會導致 query fail

- Evaluating constraints on queries

  - 權限限制由 query 條件欄位決定, [`request.query`](https://firebase.google.com/docs/reference/rules/rules.firestore.Request) 下的變數
  - 可以把 `read` 權限區分成 `get` (取得單一) 與 `list` (取得多個), 設置不同的權限
  - [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-query#evaluating_constraints_on_queries)

Collection group queries and security rules

- Collection group queries 一次取得所有同名的 sub-collections
- Secure and query documents based on collection groups

  1. 確定使用 `rules_version = '2';` 否則無法使用 collection group queries
  1. Collection group query rule template `match /{path=**}/[COLLECTION_ID]/{doc}`

  - [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-query#secure_and_query_documents_based_on_collection_groups)

- Secure collection group queries based on field

  - 依據欄位值決定 collection group 的權限
  - Query 時需要加上正確的 `where()` 來通過 rules
  - [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-query#secure_collection_group_queries_based_on_a_field)

- Secure and query documents based on collection group and document path

  - 因為是 NoSQL 同名的資料集合會存在多個地方，如果無條件的使用 collection group 取得，會有些不適合的情境。
  - [範例程式碼](https://firebase.google.com/docs/firestore/security/rules-query#secure_and_query_documents_based_on_collection_group_and_document_path)

---

### 第七章 - Solutions

- 提供更複雜情境的解決方案與限制

#### Aggregation queries

- 如果需要存取的屬性是需要走訪整個 collection 中所有的 documents 時
- 解決方案: aggregation 的屬性存成單個屬性, 每次存取不需要重新走訪整個 collection
- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/aggregation)

實現方式 1. Client-side transactions

- 把邏輯寫在 client-side transaction 中

實現方式 2. Cloud Functions

- 把邏輯寫在 Cloud functions 中

#### Distributed counters

- 單個 document 的存取速度上限是 1 秒 1 次, 對有些應用程式來說可能太慢
- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/counters)

解決方案 distributed counters

- 把單 counter 屬性分開存放成多個 documents, 讓讀寫速度上限可以依據分開的數量而加速
- 寫入時隨機選擇一個 document 儲存
- 讀取時取得所有的 documents 後在 client-side 整合。
- 類似 map 與 reduce

#### Full-text search

- Cloud firestore 不提供原生的 full-text search, 在客戶端讀取所有的文件也不現實

解決方案: Algolia - 第三方服務

- 配合 Cloud Functions 使用 Algolia 實現 index 與全文搜尋
- Algolia 並不是唯一的第三方服務, 可以使用其他類似的服務
- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/search#solution_algolia)

#### Build presence

- 偵測在線 detecting presence
- 沒有原生支援

解決方案: 使用 Cloud Functions 組合 Realtime database

- Realtime database 擁有連線狀態的資訊, 配合 Cloud Functions 作為橋樑
- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/presence#solution_cloud_functions_with_realtime_database)

#### Secure data access for users and groups

- 使用者群組與個別的權限管理

解決方案: Role-Based Access Control

- 增加 roles 屬性儲存 uid 對應的 role, Security Rule 中轉換 `request.auth.uid` 到 role 再來限制
- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/role-based-access#solution_role-based_access_control)

#### Delete data with a callable Cloud Function

- 由於刪除功能沒有提供原生的遞迴刪除

解決方案: 通過 Cloud Function 實作遞迴刪除

- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/role-based-access#solution_role-based_access_control)

#### Schedule data exports

- 使用 Cloud Functions 與 Cloud Schedular 實現定期輸出資料庫
- 輸出資料庫時每個 document 都會經過 read operation 是需要計費的
- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/schedule-export#before_you_begin)

#### Sharded timestamps

- document 寫入有每秒 500 writes 速度上限, 使用 Sharded timestamps 突破這個限制
- [範例](https://firebase.google.com/docs/firestore/solutions/shard-timestamp)

#### Automating database creation

- 通過 REST APIs, gcloud, Terraform 三種方法自動建置 Cloud Firestore database
- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/automate-database-create)

#### Reduce index costs with map fields

- 作為最佳實務, 移除不必要的 indexes 提昇寫入效能與減輕空間
- 然而消除 single-field index 有數量上限每個資料庫最多 200 個
- 使用 grouping map field 打包所有不必要 index 的欄位，變成消除一次即可。
- [範例程式碼](https://firebase.google.com/docs/firestore/solutions/index-map-field#solution_use_map_fields_to_help_manage_indexes)

---

### 第八章 - Usage, limits, and pricing

#### Usage and limits

Monitor your usage

- Firebase web console, Cloud Firestore `Usage` tab
- Google Cloud Platform (GCP) 界面也可以查看 [App Engine Quotas](https://console.cloud.google.com/appengine/quotadetails)

Free quota

- 免費額度, [參考文件](https://firebase.google.com/docs/firestore/quotas#free-quota)

Standard limits

- [Collections, documents, and fields](https://firebase.google.com/docs/firestore/quotas#collections_documents_and_fields)
- [Writes and transactions](https://firebase.google.com/docs/firestore/quotas#writes_and_transactions)
- [Realtime updates](https://firebase.google.com/docs/firestore/quotas#realtime_updates)
- [Indexes](https://firebase.google.com/docs/firestore/quotas#indexes)
- [Export/Import](https://firebase.google.com/docs/firestore/quotas#exportimport)
- [Security Rules](https://firebase.google.com/docs/firestore/quotas#security_rules)

Manage spending

- 避免超過預期的花費, 可以設定每個月預算與通知
- 可以通過 GCP 界面設定 Cloud Firestore 每日花費上限

#### Monitor usage

Usage dashboard

- GCP 或 Firebase 都有界面可以查看

Security rule usage

- Firebase console 查看 Security rules 的執行情況, Cloud firestore -> Rules -> Monitor rules

Daily quotas

- 從 GCP App Engine Quotas 界面查看每日使用量

Cloud Monitoring

- 通過 GCP 界面設定 Cloud Monitoring workspace, 創建 dashboard, 圖表, 警告通知條件
- [操作流程說明](https://firebase.google.com/docs/firestore/monitor-usage#cloud-monitoring)

#### Understand Cloud Firestore billing

Pricing overview 計費依據, 每日計費

- 執行 讀 ,寫 ,刪除的數量
- 資料庫使用到的容量, 包含 metadata 與 indexes 所佔用的空間
- 網路流量

Pricing by location

- 依據所選擇的 region 讀寫刪跟容量有不同的[計費價格](https://firebase.google.com/docs/firestore/pricing#select-region)

Reads, writes, and deletes

- 每次的 `set`, `update` 都會紀錄一次 write
- 使用 listening 讀取資料, 只要資料有 `add` 或 `update` 都會紀錄一次 read
- 善用 `Cursors`, `Page token`, `Limits`, `Offsets` 讓每次精準取得所需的資源, 避免不必要的消耗
- 使用 `Cursors` 優於 `Offsets`, `Offsets` 被略過的數量也會被計費
- 每次使用 `query` 都有最小計費, 就算回傳的值是空的也會計費
- Cloud Firestore Security Rules, 使用 `exits()`, `get()`, `getAfter()` 也會計費

Storage size

Network bandwidth

Manage spending

- 設定每月預算與通知

#### Example Cloud Firestore costs

#### Storage size calculations

- storage size 計費細節
- [文件](https://firebase.google.com/docs/firestore/storage-size)

#### Best practices for Cloud Firestore

Database location

- 選擇與使用者最接近的地方

Document IDs

- 避免 `.`, `..`, `/`
- 不要使用數字遞增減作為名稱, 例如 `Customer1`, `Customer2`, ..., 會造成大量讀寫時的延遲 (hotspotting)

Field Names

- 避免使用 `.`, `[`, `]`, `*`, **`**, 這些符號需要額外的跳脫

Indexes

- 避免使用太多的 indexes, 會造成寫入延遲與佔用空間
- 小心單調成長的值, 例如 timestamps, 可能會造成 hotspotting
- 消除特定案例的 indexes 來減少空間消耗,
  - 不需要搜尋的大型字串欄位
  - 不需要搜尋的大型陣列或物件欄位
  - 不需要搜尋的高速寫入連續值, 例如高速寫入 timestamp
  - [參考資源](https://firebase.google.com/docs/firestore/best-practices#index_exemptions)

Read and write operations

- 避免寫入單一 document 速度快於 1 秒 1 次
- 使用非同步呼叫
- 不要使用 `offsets` query, 改用 [`cursors`](https://firebase.google.com/docs/firestore/query-data/query-cursors)
- Transactions retires, 使用 SDKs 和 client libraries 會自動 retry, 如果使用其他方式直接呼叫的話, 需要自行實現 retry
- Realtime updates, 最佳化 snapshot listener 效能
  - 讓 document 盡可能小,
  - 控制讀取速度
  - 避免頻繁的註冊刪除相同的 listener, 最佳實務 snapshot listener 的生命週期起碼要有 30 秒以上
  - 限制每個 client 的 listener 數量小於 100
  - 限制每個 collection 的寫入速度低於每秒 1000 個寫入
  - ...
  - 參考文件 [checklist](https://firebase.google.com/docs/firestore/best-practices#realtime_updates)

Designing for scale

Updates to a single document

- 更新速率必須小於每秒一次，否則會造成延遲

High read, write, and delete rates to a narrow document range

- 避免高速度的 hotspotting, 會造成延遲
- [常見案例](https://firebase.google.com/docs/firestore/best-practices#high_read_write_and_delete_rates_to_a_narrow_document_range)

Ramping up traffic

- 慢慢遞增的讀寫速度
- 從每秒 500 個動作, 以每五分鐘增加 50% 的速度提昇最大速率
- [文件參考](https://firebase.google.com/docs/firestore/best-practices#ramping_up_traffic)
- Migrating traffic to a new collection, 大量讀寫的 collection 切換, 會造成延遲, [文件說明](https://firebase.google.com/docs/firestore/best-practices#migrating_traffic_to_a_new_collection)
- 使用 [Parallel reads](https://firebase.google.com/docs/firestore/best-practices#parallel_reads),
  - 利用使用者 ID 去控制一定比例的使用者可以創建新 document, 避免一次同時
  - Batch 搬移舊資料到新的 collection 後才刪除舊的 documents
  - Batch 時避免順序上連續的資料, 小心造成 hotspotting

Prevent unauthorized access

- Security Rules 必須設定得更嚴謹, 避免惡意的使用者有權限大量寫入或讀取資料庫

---

### 第九章 - Cloud Firestore integrations

#### Use the Cloud Firestore REST API

---

### 第十章 - API reference

---

### 第十一章 - Samples

---
