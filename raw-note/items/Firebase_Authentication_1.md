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

- [Firebase UI web library](https://github.com/firebase/firebaseui-web)

FirebaseUI UI library, 實作好串接 Firebase Authentication SDK 與登入流程

- 可以客製化 CSS 並且因為是 Open Source 允許 fork 後自行擴充
- 支援 i18n
- 提供轉換 Anonymous 到 sign-in/sign-up 的機制

Before you begin

1. 連結 Firebase Authentication 與應用程式, [參考 setup](https://firebase.google.com/docs/web/setup)
2. 引用 FirebaseUI, [程式碼範例](https://firebase.google.com/docs/auth/web/firebaseui#before_you_begin)

   - CDN
   - npm Module
   - Bower Component

Initialize FirebaseUI

- `var ui = new firebaseui.auth.AuthUI(firebase.auth())`

Set up sign-in methods

- 在 Firebase web console 中啟動 Authentication 與 FirebaseUI 設定
- Email address and password, FirebaseUI [設定範例](https://firebase.google.com/docs/auth/web/firebaseui#email_address_and_password)
- Email link authentication, FirebaseUI [設定範例](https://firebase.google.com/docs/auth/web/firebaseui#email_link_authentication)
- OAuth providers(Google, Facebook, Twitter and GitHub), FirebaseUI [設定範例](https://firebase.google.com/docs/auth/web/firebaseui#oauth_providers_google_facebook_twitter_and_github)
- Phone number, FirebaseUI [設定範例](https://firebase.google.com/docs/auth/web/firebaseui#phone_number)

Sign in

1. 初始化 FirebaseUI
1. 建立 html container
1. 建立 FirebaseUI configuration
1. 啟動 FirebaseUI

- [程式碼範例](https://firebase.google.com/docs/auth/web/firebaseui#sign_in)

Upgrading anonymous users

- 讓未登入的會員能在登入後保留先前的狀態

- Enabling anonymous user upgrade, 在 FirebaseUI config 中設定 `autoUpgradeAnonymousUsers` 為 `true`, 預設是關閉的
- Handling anonymous user upgrade merge conflicts, 處理未登入使用者登入已登入的帳號產生的 conflicts
  - FirebaseUI 處理細節設定, [參考程式碼](https://firebase.google.com/docs/auth/web/firebaseui#handling_anonymous_user_upgrade_merge_conflicts)

#### Get Started

Connect your app to Firebase

- 連結 Firebase, [參考 setup](https://firebase.google.com/docs/web/setup)

Sign up new users

- 使用 email 與 password 註冊帳號
- 建立 Sign-up 表單, 讓使用者輸入 email 與 password 驗證後傳遞給 `firebase.auth().createUserWithEmailAndPassword(email, password)`
- [參考程式碼](https://firebase.google.com/docs/auth/web/start#sign_up_new_users)

Sign in existing users

- 使用 email 與 password 登入帳號
- 建立 sign-in 表單, 輸入 email 與 password 驗證後傳遞給 `firebase.auth().signInWithEmailAndPassword(email, password)`
- [參考程式碼](https://firebase.google.com/docs/auth/web/start#sign_in_existing_users)

Set an authentication state observer and get user data

- 通過註冊 `firebase.auth().onAuthStateChanged()` 事件, 監聽登入狀態與使用者資訊
- [參考程式碼](https://firebase.google.com/docs/auth/web/start#set_an_authentication_state_observer_and_get_user_data)

#### Manage Users

Create a user

- Email 與 password, 通過 `createUserWithEmailAndPassword`, [參考文件](https://firebase.google.com/docs/auth/web/password-auth#create_a_password-based_account)
- 第三方認證, [Google Sign-in](https://firebase.google.com/docs/auth/web/google-signin), [Facebook Login](https://firebase.google.com/docs/auth/web/facebook-login), ...

Get the currently signed-in user

- 推薦使用 `firebase.auth().onAuthStateChanged((user) => {})` 取得 `user` 物件
- 使用這種方式取得的 `user` 物件，可以確保是正確的狀態, 而非初始化中的狀態
- 或者使用 `firebase.auth().currentUser`, 取得 sign-in user
- 以上兩種方式, 如果是未登入的使用者會得到 `null`
- [參考範例](https://firebase.google.com/docs/auth/web/manage-users#get_the_currently_signed-in_user)

Get a user's profile

- 通過 `user` 物件的 properties 取得使用者資料
- `displayName`, `email`, `photoURL`, `emailVerified`, `uid`
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#get_a_users_profile)

Get a user's provider-specific profile information

- 取得第三方授權的使用者資料
- 通過 `user` 物件的 `providerData` 屬性
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#get_a_users_provider-specific_profile_information)

Update a user's profile

- 更新使用者的名稱 (displayName) 與大頭貼 URL (photoURL)
- 通過 `user` 物件的 `updateProfile()` 方法
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#update_a_users_profile)

Set a user's email address

- 設定使用者 email 通過 `user` 物件的 `updateEmail()` 方法
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#set_a_users_email_address)

Send a user a verification email

- 發送 email 驗證信, 通過 `user` 物件的 `sendEmailVerification()` 方法
- 可以在 Firebase Authentication web console 設定驗證性的內容模板
- 傳遞訊息與實現 i18n
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#send_a_user_a_verification_email)

Set a user's password

- 設定使用者 password 通過 `user` 物件的 `updatePassword()` 方法
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#set_a_users_password)

Send a password reset email

- 發送密碼重設信, 通過 `firebase.auth().sendPasswordResetEmail()`
- 等同驗證信, 可以設定 email 模板, i18n, 傳遞資訊
- 也可以直接在 Firebase web console 中直接發送

Delete a user

- 刪除使用者帳號通過 `user` 物件的 `delete()` 方法
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#delete_a_user)

Re-authenticate a user

- 在觸發安全性相關動作時, 如果登入太久的使用者會失敗, 需要重新驗證才能繼續操作。
- 使用者重新驗證, 通過 `user` 物件的 `reauthenticateWithCredential()` 方法
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#re-authenticate_a_user)

Import user accounts

- 通過 Firebase CLI `auth:import` 匯入使用者帳號與資訊
- [程式碼範例](https://firebase.google.com/docs/auth/web/manage-users#import_user_accounts)

#### Password Authentication

#### Email Link Authentication

#### Google Sign-in

#### Facebook Login

#### Sign in with Apple

#### Twitter

#### GitHub

#### Microsoft

#### Yahoo

#### Phone Number

#### Use a Custom Auth System

#### Anonymous Authentication

- 創建暫存的匿名使用者帳戶
- 在轉換成實際使用者帳戶時傳遞先前的資料

#### Link Multiple Auth Providers

- 同個使用者帳號, 連結多個認證系統

#### OAuth Sign-In for Cordova

#### Auth State Persistence

- 通過 browser 暫存使用者狀態, 避免持續重複登入造成使用者體驗不佳
- 需取捨資料安全與使用者體驗之間的平衡
- 分別可以選擇儲存在 `local`, `session`, `none` 達成不同條件的資料保存
- 細節參考[文件](https://firebase.google.com/docs/auth/web/auth-state-persistence)

#### Passing State in Email Actions

- 通過驗證信或重設信, 帶著狀態轉倒回應用程式
- 細節參考[文件](https://firebase.google.com/docs/auth/web/passing-state-in-email-actions)

#### Service Worker Sessions

- Beta 版功能
- 管理 service workers 與使用者 token

### 第五章 - Customize the Email Action Handler

- 如果使用 Firebase Hosting, 會有預設的 Email Action Handler 處理。
- 在使用 email 重設密碼, 驗證, 修改 email 時, 會有相對應的 Action Handler
- 可以客製化相對應的 handler 與 Email template
- [程式碼範例](https://firebase.google.com/docs/auth/custom-email-handler)

### 第六章 - Extend with Cloud Functions

- Firebase Authentication 事件可以觸發 Cloud Functions
- 例如在使用者註冊新帳號後發送歡迎信
- [程式碼範例](https://firebase.google.com/docs/auth/extend-with-functions)

### 第七章 - Case Studies

使用 Firebase Authentication 的 mobile APP 範例

### 第八章 - Usage Limits

- 創造帳號與刪除帳號, 受到速度限制, [參考文件](https://firebase.google.com/docs/auth/limits#account_creation_and_deletion_limits)

Accounts per project

- 匿名使用者有數量限制
- 註冊使用者則無數量限制
- [參考文件](https://firebase.google.com/docs/auth/limits#accounts_per_project)

Email limits

- 每日數量限制, [參考文件](https://firebase.google.com/docs/auth/limits#email_limits)

Email link generation limits

- 每日數量限制, [參考文件](https://firebase.google.com/docs/auth/limits#email_link_generation_limits)

Phone number sign-in limits

- 電話驗證與簡訊, 有速度限制
- [參考文件](https://firebase.google.com/docs/auth/limits#phone_number_sign-in_limits)

API limits

- 有速度限制與每日請求數量限制, [參考文件](https://firebase.google.com/docs/auth/limits#api_limits)
