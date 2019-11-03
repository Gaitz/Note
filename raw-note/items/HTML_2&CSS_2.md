## Mobile HTML5 學習手冊
### BOOK resource, HTML / CSS 

------

第一章 - 開發工具、測試工具

第二章 - 升級 HTML5

第三章 - HTML5 的新元素

第四章 - HTML5 Web 表單

第五章 - SVG、Canvas、音訊與視訊

第六章 - 其他的 HTML5 API

第七章 - 升級 CSS3

第八章 - 擴充的 CSS3 特性

第九章 - CSS3 模組、模型與圖像

第十章 - CSS3 變形、漸變、動畫

第十一章 - 響應式 Web 的 CSS 功能

第十二章 - 行動應用程式設計

第十三章 - 以行動與觸控設備為目標

第十四章 - 行動效能

------

### 第一章 - 開發工具、測試工具

******

### 第二章 - 升級 HTML5

#### Best practice
* HTML 管理內容、CSS 管理外觀、JavaScript 管理行為
* 使用小寫
* 屬性都使用 `" "`
* 關閉所有標籤
* 正確的順序配對元素
* 非布林屬性必須有值
* 使用最符合語義的元素

#### Global Attributes
* id
* class
* title (無用)
* style
* lang (language)
* dir (direction) 文字方向
* tabindex 無障礙 (**0 / -1**)
* accesskey 無障礙 (無用)
* hidden (沒有意義、不再有意義的內容)
* contenteditable
* draggable
* dropzone
* spellcheck
* aria-*
* data-* (自訂資料屬性)
* itemid, itemprop, itemref, itemscope

#### Document Type Declaration (DTD) 文件類型宣告
  * `<!DOCTYPE html>`

#### 元素 `<html>`
  * 加上 lang 屬性是好習慣

#### 元素 `<head>` 
#### 元素 `<title>`
  * 必要的元素
  * 對於 SEO 非常重要

#### 元素 `<body>`
#### 元素 `<head>` 裡的元素
  * `<meta>` 專用屬性 charset, http-equiv, content, name
    * `<meta charset="utf-8" />`
    * `<meta name="description" content="" />` SEO 相關, 重要。
    * `<meta name="keyword" content="" />` SEO 相關，較不重要。
    * `<meta http-equiv="" />` 設置 http response header, 最好由伺服器端設置而非 html。
    * `<meta name="viewport" conent="width=, height=, user-scalable=, initial-scale=, maximum-scale=, minimum-scale= " />`
    * 行動製造商專用值, `<meta name="apple-mobile-web-app-capable" content="yes" />`, `<meta name="apple-mobile-web-app-status-bar-style" content="" />`, `<meta name="format-detection" content="telephone=no" />` 關閉電話撥號連結

#### 元素 `<base>`
#### 元素 `<link>`
  * HTML文件與其他資源的關係
  * 屬性 href, rel, type, sizes, hreflang, media, title
  * `<link href="" rel="" />`
  * 使用 media 屬性配合 media query 指定下載
    * 設備類型 all, screen, print, tty, tv, projection, braille, aural
    * (min-/max)-width
    * (min-/max)-height
    * (min-/max)-device-width
    * (min-/max)-device-height
    * orientation
    * (min-/max)-aspect-ratio
    * (min-/max)-device-aspect-ratio
  * 屬性 rel 
    * stylesheet
    * next
    * prev
    * index
    * help
    * contents
    * alternate
    * copyright
    * glossary
    * icon
    * apple-touch-icon
    * apple-touch-startup-icon

#### 元素 `<style>`
#### 元素 `<script>` 
  * 放置的位置，影響下載、解析
  * 屬性 async 非同步執行, defer 解析完文件後執行
  * `<noscript>` 顯示無 JavaScript 時的內容
    
*****

### 第三章 - HTML5 的新元素

#### 分段語義元素
  * `<section>`, 通常包含一個標題、有語義的子區塊
  * `<article>`, 獨立的文章、內容
  * `<nav>`, 導覽連結, `<nav role="navigation">` 無障礙
  * `<aside>`, 與主內容無關的, 側邊欄位, 廣告...
  * `<header>`
  * `<footer>`
  * `<main>`, 網頁的主要內容, 只能有一個.
  * `<content>`
  * `<body>`
  * `<h1-h6>`
  * `<address>`, 聯絡資訊
  * `<figure>, <figcaption>` 補充內容以及其文字描述、補充圖片、資料...
  * `<hr />`, 段落主題斷行、強制換行
  * `<li>`, `<ol>`, 屬性 value

#### 文字語義元素
  * `<mark>`, 標記文字, 例如搜尋結果
  * `<time>`, 特定的時間、日期, 利用屬性 datetime 提供電腦能讀的時間
  * `<ruby>`, `<rt>`, `<rp>`, 與 Ruby 程式語言無關, 文字的註釋或發音註解。例如日文讀音
  * `<bdi>`
  * `<wbr>`, 告知瀏覽器可換行點, word break
  * `<data>`
  * `<a>`, 可以容納行內和區塊元素, 新屬性 download, media, ping. 特別的 href, `mailto:`, `tel:`, `sms:`...
  * `<small>`
  * `<s>`
  * `<cite>`
  * `<i>`, 
  * `<b>`
  * `<u>`
  * `<q>`
  * `<samp>`
  * `<kbd>`
  * `<sub>`
  * `<sup>`
  * `<bdo>`
  * `<span>`
  * `<br>`
  * `<em>`
  * `<strong>`
  * `<dfn>`
  * `<abbr>`
  * `<code>`
  * `<var>`