## Firebase Cloud official documentation - Authentication

### [Website resource](https://firebase.google.com/docs/auth), Firebase

---

第一章 - Introduction

第二章 - Where do I start ?

第三章 - Users in Firebase Projects

第四章 - Web

第五章 - Customize the Email Action Handler

第六章 - Extend with Cloud Functions

第七章 - Case Studies

第八章 - Usage Limits

---

### 第一章 - Introduction

2 種使用方式,

- FirebaseUI Auth, 開源實作好的 Auth component, 只要引用即可完成
- Firebase SDK Authentication, 各種類型的驗證 SDKs

  - Email 與 password 驗證
  - 第三方帳號整合, Example: Google, Facebook, Twitter, GitHub
  - 電話號碼驗證, 通過 SMS
  - 整合現有的認證系統
  - 匿名者認證, 暫存狀態直到使用者登入系統

How does it work?

- 通過取得 credentials 或 OAuth token 後交由 Firebase Authentication 後端驗證與權限控管
- 預設行為, 授權使用者可以讀寫 Firebase Realtime database 與 Cloud Storage, 可以額外設定權限

Implementation paths

- 使用 FirebaseUI Auth

  1. Set up sign-in methods, 選擇並且開啟驗證種類
  1. Customize the sign-in UI, 設置前端登入界面
  1. Use FirebaseUI to perform the sign-in flow, 利用 FirebaseUI library 初始化並且管理登入流程

- 使用 Firebase Authentication SDK

  1. Set up sign-in methods, 選擇並且開啟驗證種類
  1. Implement UI flows for your sign-in methods, 實作前端界面和登入流程
  1. Pass the user's credentials to the Firebase Authentication SDK, 通過 SDK 傳送驗證資訊給 Firebase 後端

What's next

- 提供各平台的整合範例, iOS, Android, Web, C++, Unity, Admin

### 第二章 - Where do I start ?

#### I already have an authentication system

已經有認證系統, 想要使用原有的認證系統來認證使用 Firebase 服務

- 使用 Custom Authentication

#### I want to build my authentication system with Firebase

通過 Firebase 建立認證系統

- 使用原生的 drop-in UI library (FirebaseUI Auth), 直接注入使用
- 完整控制登入流程與使用者界面, 可以通過 Firebase Authentication SDK 協助實作, [參考文件](https://firebase.google.com/docs/auth/where-to-start#firebasesdk)

#### I want to build rich pre-sign-in experiences

使用 `Anonymous Auth` 暫存使用者狀態, 等到實際登入後自動轉換先前的操作。

#### I want to access Firebase services from my backend

伺服器對伺服器的方式, 不需要通過 Firebase Authentication, 而是使用 `Admin SDK`

### 第三章 - Users in Firebase Projects

- Firebase `user` 物件，代表一個登入的使用者帳號

User properties

- 內建固定的使用者欄位, Unique ID, Email address, Name, Photo URL
- 無法直接在 user 物件中增加欄位, 需要額外使用資料庫儲存 (例如 Cloud Firestore)
- 使用不同種類的認證方式, 使用者欄位初始化的內容也不同

Sign-in providers

- 同一名使用者帳戶, 可以同時使用不同種類的認證方式登入

The current user

- 在使用者註冊後或者登入後, 會被視為使用中的使用者, 會追蹤使用者狀態和儲存到伺服器端。
- 使用者登出後則不追蹤, 但是如果刻意保存 reference 時，可以持續使用。

The user lifecycle

- 使用 Auth listener 監控使用者狀態
- 會監聽到不同的使用者事件, [參考文件](https://firebase.google.com/docs/auth/users#the_user_lifecycle)

Auth tokens, 3 種類型的 tokens

- Firebase ID tokens, (signed JWTs)
- Identity provider tokens, 由第三方認證提供, 例如 Google, Facebook, GitHub, ...
- Firebase custom tokens,(JWTs)
- [說明文件](https://firebase.google.com/docs/auth/users#auth_tokens)

### 第四章 - Web

#### Sign in with a pre-built UI

### 第五章 - Customize the Email Action Handler

### 第六章 - Extend with Cloud Functions

### 第七章 - Case Studies

### 第八章 - Usage Limits
