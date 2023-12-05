## Google Tag Manager official documentation

### [Google Tag Manager official documentation](https://developers.google.com/tag-platform), ComputerScience/GTM

---

第一章 - tag platform overview

第二章 - Guides

第三章 - Google Tag

第四章 - Tag Manager

---

### 第一章 - [tag platform overview](https://developers.google.com/tag-platform)

- Google Tags (gtag.js)
  - 用單一個設定去通知所有的 Google 相關服務, (Google Ads, Google Analytics, ...)
- Google Tag Manager
  - 在不需要額外撰寫程式碼的前提下, 設定且管理 Tags, 除了支援 Google 本身產品之外, 也可以用於其他第三方的 tracking 機制

---

### 第二章 - [Guides](https://developers.google.com/tag-platform/devguides)

#### First steps

Overview

- Tag
  - 由來是一段 `<script>` 或 `<img>` 用來追蹤測量使用者行為
- Google Tag (`gtag.j`), 以單一個 tag 適用於多個 Google 服務
- Google Tag Manager, 用來設定以及部屬 tags, 提供包含多種的 tags 包含第三方服務的
- 差異主要在於 Google Tag Manager 多支援其他第三方的 tags

Before you begin

- 先思考一些問題
  - 你測量的目標是什麼?
  - 你應該使用 Google Tag Manager, Google tag (gtag.js), or Firebase?
  - 有沒有已經存在的 tags installed through Tag Manager, Google tag, Firebase, or other platforms?
  - 現在有沒有已經在使用的追蹤機制
- Measurement goals
  - 取決於你的商業策略, 找出正向與反向的目標
  - 依據商業策略來選擇適合的追蹤產品和 tags
  - 商業策略應該時常重新評估反思
  - 當收集更多資料時, 商業策略有可能也會因此而調整, 藉此需要追蹤其他東西
  - _補_: 應該以商業策略為導向
- Google Tag Manager, Google tag (gtag.js), or Firebase?
  - 在網站允許的情況下, 應該使用 Google Tag Manager 作為入門, 他提供更高的彈性與擴充性
  - Google tag: 如果只需要單一的產品 (Ads performance or traffic), 並且不時常變動, Google tag 應該是最簡便快速的選擇
  - Google tag manager: 可靠, 有非常豐富的功能, 對第三方的支援, 客製化, 在不需要工程師額外工作的情況下, 仍然可以擴充
  - Firebase: 如果需要額外測量 Mobile App 時, Firebase 可以提供給 iOS, Android 使用
- Integration with content management and ecommerce systems
  - 優先參考使用的平台上是否已經有整合好的服務
- Third-party tag management systems
  - 使用第三方 tag 時, 儘管使用 Google Tag Manager, 也需要去參考第三方的文件
- Existing tag installations and instrumentation
  - 先檢查已經安裝的設定和版本 (`analytics.js`, `conversions.js`)
  - 舊版先升級, 檢查設定, 可以使用 `Google Tag Assistant` 自動偵測
  - 檢查現有的資料, 與追蹤條件
- For Google Tag Manager installations
  - Manage personnel changes, 進行人員權限管理
  - One Tag Manager account per organization, 每個組織只需要一個帳號
  - Empower IT with additional security controls, 給 IT 部門提供更多安全控管設定
  - Use zones to manage access, 使用 `zones` 去管理權限

Analyze existing tag configurations

- 為了不要有多餘的, 重複的 tag 設定, 先調查現有的 tags
- Google Tag Assistant
  - 自動化檢查工具
- Google Tag Manager
  - 從帳戶中檢查現有的設定
  - Search, Versions, Preview mode
- Manual code inspection
  - 手動搜尋 codebase, keywords: `gtag`, `googletagmanager.com`
  - 如果已經存在現有的服務, 應該採用升級和調整設定值的方式
  - `dataLayer`, 檢查是否建立, 是否使用 `dataLayer.push()` 發送 event
  - `analytics.js`, `ga.js` 舊版的 GA 服務, 需升級
  - `conversion.js`, `conversion_async.js`, Google Ads 所使用的 library
  - `optimize.js`, Google Optimize tags
  - 其他第三方的函式庫, 可能使用到的 Google tags
- `gtag.js`
  - `gtag()`
  - ID 的 prefix, `UA`: Google Analytics, `DC`: Floodlight, `G`: Google Analytics, `AW`: Google AdWords
- Google Tag Manager
  - `GTM-`

#### Basic setup

Add a tag to your website

- Google Tag 與 Google Tag Manager 的簡易[安裝方式](https://developers.google.com/tag-platform/devguides/add-tag?solution=gtm)

#### Core concepts

Events

- Tag 是用來獲得能收集到 event 的資訊, 包含 event type, 與其他相關資訊
- 一個 event 代表的是一個使用者互動, 例如: 點擊, 載入頁面, 下載, 訂閱, ...
- 一個 parameter 代表的是與 event 相關的資訊, 例如: 產品 id, 折扣碼, 幣別, ...
- `event` 指令, 這邊使用 Google tag `gtag('event', '<type>', {<parameter>})`
- Google Tag Manger: event 可以是任何支援的 tag 像是
  - Google Ads Conversion Tracking, (使用者與廣告互動)
  - Google Analytics: GA4 event, (包含自動追蹤的, 客製化的, ...)
  - Google Analytics: Universal analytics, (Google 舊的服務)
  - Floodlight Counter or Floodlight Sales,

The data layer

---

### 第三章 - [Google Tag](https://developers.google.com/tag-platform/gtagjs)

---

### 第四章 - [Tag Manager](https://developers.google.com/tag-platform/tag-manager)

---
