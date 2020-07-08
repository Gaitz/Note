## FireBase Experience 1

### Create project
  * 使用 google 帳戶登入
  * 新增 project 
  * 新增 App
  * 新增 Database, 選擇 Clould Firestore

### Cloud Firestore
  * [Cloud Firestore Tutorial playlist](https://www.youtube.com/playlist?list=PLl-K7zZEsYLluG5MCVEzXAQ7ACZBCuZgZ)
  * NoSQL, 樹狀結構儲存資料
  * Document, 類似 JavaScript object, 一種 key-value pair, 一個最多 1 MB。
  * Collection, 收集 ducuments。
  * 需要用到的資訊，以複製的方式存在。(相同的資訊可以同時存在多個 Document 裡，只要使用這個 document 的情境需要)
  * query default 是 shallow 的。


---------------------------

### References

#### Firebase services
  * Firebase hosting, 機器部屬, (支援 SSL, CDN, 靜態或動態網站, CLI 部屬, 部屬的版本控管，容易回復)
  * Authentication, 權限管理
  * Clould Firestore (NoSQL, 較新, Collection Document model), Realtime Database (NoSQL, JSON storage, 資料即時同步到客戶端), 儲存資料
  * Clould Storage, 儲存檔案
  * Performance Monitoring, 效能監測與分析
  * Clould Functions, 後端執行 (交由後端執行 JavaScript/TypeScript, Serverless)
  * Clould Messaging, 發送訊息到客戶端 (Firebase Cloud Messaging, FCM)

#### 功能分類
  * Develop,
    * Authentication
    * Database
    * Storage
    * Hosting
    * Functions
    * Machine Learning
  * Quality
    * Crashlytics
    * Performance
    * Test Lab
    * App Distribution
  * Analytics
    * Dashboard
    * Events
    * Conversions
    * Audiences
    * Funnels
    * User Properties
    * Latest Release
    * Retention
    * StreamView
    * DebugView
  * Grow
    * Predicitions
    * A/B Testing
    * Cloud Messaging
    * In-App Messaging
    * Remote Config
    * Dynamic Links
    * AdMob