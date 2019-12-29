## HTML5 The missing manual
### BOOK resource, HTML / CSS 

------------------------------

* 第一部份 : 時尚標記

第一章 - HTML5 介紹

第二章 - 結構化頁面 (Structuring Pages) 和語義元素 (Semantic Elements)

第三章 - 撰寫更多有意義的標記

第四章 - 建置優質網頁表單 (form)

* 第二部份 : 視訊、圖像、與炫目特效

第五章 - 音訊與視訊

第六章 - CSS3 的吸睛特效與絢麗字體

第七章 - CSS 的自適應式網頁設計 (Responsive Web Design)

第八章 - Canvas 的基本繪圖功能

第九章 - Canvas 進階: 互動性與動畫

* 第三部份 : 建置網頁應用程式

第十章 - 儲存你的資料

第十一章 - 離線執行

第十二章 - 連結網路伺服器 (Web Server)

第十三章 - Geolocation、Web Workers、與瀏覽紀錄管理


------------------------------


### 第一章 - HTML5 介紹
#### 演進
  1. HTML
  1. XHTML 1.0
  1. XHTML 2.0
  1. HTML5
  1. HTML

* 持續更新的 HTML5 標準 https://html.spec.whatwg.org/multipage/

#### HTML5 原則
  * 不破壞舊的網頁, 向下相容
  * 延續舊習, 建構在舊的使用上, Example: drag-and-drop
  * 實用主義, 標準化最實用的網路需求, Example: video

#### 基礎
  * `<!DOCTYPE html>`
  * `<html lang="">` 加上語言
  * `<head>`
  * `<meta charset="utf-8" />` 加上編碼
  * `<title></title>` 加上網頁標題
  * `<link href="" ref="stylesheet" />` 連結外部樣式檔
  * `<script src=""></script>` 連結外部 JavaScript

#### 好習慣
  * 使用 `<html>`, `<head>`, `<body>`
  * 使用小寫
  * 屬性值加上引號 `"`
  * 使用 https://caniuse.com/ 檢查支援情況


------------------------------


### 第二章 - 結構化頁面 (Structuring Pages) 和語義元素 (Semantic Elements)

#### 語義元素
  * `<header>`
  * `<footer>`
  * `<article>`, 需要標題
  * `<figure>`, `<ficaption>`
  * `<aside>`
  * `<nav>`
  * `<section>`, 需要標題
  * `<details>`, `<summary>`
  * `<main>`, 整個頁面只能有一個
  * HTML5 outline system, 利用 `<h1>...<h5>`, `<article>`, `<aside>`, `<nav>`, `<section>` 產生


------------------------------


### 第三章 - 撰寫更多有意義的標記

#### 行內語義元素
  * `<time>` 時間與日期, 配合屬性 `datetime` 提供專用格式 `YYYY-MM-DD HH:MM-TimeZone`, 屬性 `pudate` 標注出版日期
  * `<output>` JavaScript 輸出的內容, 可以通過屬性 `form` 指定表單ID, 屬性 `for` 說明
  * `<mark>` 強調重要內容或者關鍵字, 
  * `<del>` 被刪除的、不合現狀的
  * `<ins>` 新增的

#### 其他語義標準
  * ARIA (Accessible Rich Internet Application) 無障礙網頁, 
    * 屬性 `role`, `aria-`
  * RDFa (Resource Description Framework) 資源描述框架
  * Microformats, 通過固定的 class 名稱，產生具語義的 metadata 。
  * Microdata, [https://schema.org](https://schema.org), 
    * 配合屬性 `itemscope`, `itemtype`, `itemprop` 標示標準化的 metadata
  * 好處: 
    1. 提供瀏覽器更多資訊
    1. SEO, 可以配合 google webmaster 


------------------------------


### 第四章 - 建置優質網頁表單 (form)
  
#### 基本表單
  * `<form>` 
    * `<fieldset>`, 欄位集
    * `<legend>`, 
    * `<label for="">`
    * `<input>`
  
  * 屬性 `placeholder`
  * 屬性 `title` 在滑鼠移動過去時，會顯示說明
  * 屬性 `autofucus` 由瀏覽器提供功能

#### 表單驗證
  * HTML5 通過特定的屬性，由瀏覽器幫忙提供驗證功能, 驗證時機是表單被觸發 submit 時。
  * `<form novalidate>` 屬性 `novalidate` 可以使表單不執行驗證功能。
  * 屬性 `required`, 必填欄位
  * 屬性 `pattern`, 使用 reqular expression 驗證
  * 客製化驗證使用 API `input.setCustomValidity("")` 配合 JavaScript 驗證與傳送錯誤訊息。

#### 新式 `<input>`
  * 屬性 `type` 的預設值是 `text`
  * 新的 type, `email`, `url`, `search`, `tel`, `number`, `range`, `date`, `color`, ...
  * 新元素 `<datalist>`, 共用的資料集 `<datalist id="">` 類似選單功能，可以提供相同的資料集給不同的 `<input list="">`
  
#### 其他新元素與功能
  * 新元素 `<progess>`, 進度條配合屬性 `value` 0 ~ 1 表達完成率或者配合屬性 `max` 自動計算完成率
  * 新元素 `<meter>`,  配合屬性 `value`, `min`, `max`, `low`, `high`
  * 新元素 `<command>`,
  * 新元素 `<menu>`,
  * 屬性 `contenteditable`, 使 html 區塊變成可編輯模式, 可以透過 JavaScript 達成更多互動功能。
  * 屬性 `designMode`, 


------------------------------


### 第五章 - 音訊與視訊

#### 音訊
  * `<audio></audio>`
  * 屬性 `src`, 
  * 屬性 `controls`,
  * 屬性 `preload`, 
  * 屬性 `autoplay`,
  * 屬性 `loop`,

#### 視訊
  * `<video></video>`
  * 屬性 `src`, 
  * 屬性 `controls`,
  * 屬性 `preload`, 
  * 屬性 `autoplay`,
  * 屬性 `loop`,
  * 屬性 `height`, `width`
  * 屬性 `poster`,
  * 配合屬性 `mediagroup` 讓多個 video 或者 audio 同時播放。
  * 影片字幕 

#### 檔案格式
  * 多媒體檔案格式與 MINE 類型
  * 記得在 server-side 配合多媒體檔案格式設定正確的 MINE 類型
  * 除了 `src` 之外改以多個 `<source>` 來指定來源，可以提供多種檔案格式

#### 透過 JavaScript 操作
  * audio API
  * video API