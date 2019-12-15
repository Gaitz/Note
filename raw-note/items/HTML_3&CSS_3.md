## HTML5 與 CSS3 響應式網頁設計
### BOOK resource, HTML / CSS 

------------------------------

第一章 - 響應式網頁設計的要點

第二章 - 媒體查詢_支援不同視區

第三章 - 流動版型與響應式圖片

第四章 - 用 HTML5 作響應式網頁設計

第五章 - CSS3_選擇器、排字學、色彩模式和新功能

第六章 - 用 CSS3 做出讓人驚呆的美感

第七章 - 採用 SVG，不用管解析度

第八章 - 漸變、變形與動畫

第九章 - 用 HTML5 和 CSS3 征服表單

第十章 - 朝響應式網頁設計邁進

------------------------------


### 第一章 - 響應式網頁設計的要點
  * Mobile first
  1. `<meta name='viewport' content='width=device-width' />`
  1. `max-width: 100%`
  1. `@media`


******************************


### 第二章 - 媒體查詢_支援不同視區

#### 效能優化
  1. 所有圖片都壓縮過了
  1. 單一 JavaScript 並且 minify 過。
  1. gzip 所有的東西。
  1. 靜態內容配合 CDN 使用。
  1. 移除多餘的 CSS。


******************************


### 第三章 - 流動版型與響應式圖片

#### Flexbox
#### 響應式圖片
  * `<img>` 屬性 `srcset`
  * `<picture>` 配合 `<source media="" />`


******************************


### 第四章 - 用 HTML5 作響應式網頁設計

#### 語義元素
  * `<a>` 允許包含除了互動式元素以外的多個元素。
  * `<main>`, 主要內容。
  * `<section>`, 願意給予標題的區塊, 不然使用 `<div>` 即可。
  * `<nav>`, 導覽連結區塊
  * `<article>`, 一個完整並且可以單獨存在的內容。
  * `<aside>`, 與主內容沒有直接關係的區塊。
  * `<figure>`, `<figcaption>`, 圖片、圖表、程式碼與他的描述。
  * `<details>`, `<summary>`, 原生的互動式開合內容。
  * `<header>`, `<footer>`, 標頭, 頁尾
  * `<address>`, 聯絡訊息
  * `<h1>` - `<h6>`, 每一個新區塊的標題, 避免使用 `<h1>`, `<h2>` 作為子標題, 而是使用 `<h1>`, `<p>`
  * `<b>`, 關鍵字、吸引注意的內容
  * `<em>`, 
  * `<i>`, 文字, 聲音、情緒有差別或者偏離本文。


******************************


### 第五章 - CSS3_選擇器、排字學、色彩模式和新功能

  * 文字折行, `word-wrap: break-word;`
  * 超過邊界的文字, `text-overflow: ellipsis; overflow: hidden; white-space: no-wrap;`
  * 功能查詢, `@suprrot`
  * 空的選擇器, `:empty`
  * CSS 變數, `var()`
  * CSS 計算, `calc()`


******************************


### 第六章 - 用 CSS3 做出讓人驚呆的美感
  
  * 文字陰影, `text-shadow`
  * 箱型陰影, `box-shadow`
  * 漸層, `linear-gradient`, `radial-gradient`
  * 背景, `background`, 背景尺寸, `background-size`, 背景位置, `background-position`,
  * CSS濾鏡, `filter`


******************************


### 第七章 - 採用 SVG，不用管解析度

  * XML 的一種
  * root, `<svg width="" height="" viewBox="" ></svg>`
  * 描述標籤, `<title></title>`, `<desc></desc>`
  * 定義可重複出現的內容, `<defs></defs>`
  * SVG `<symbol>` 與 `<use>` 分開的 svg 可以通過 id 指定重用
  * 通過 CSS 可以調整 SVG 的樣式
  * SVG 引用外部的 SVG `<use xlink:href=""></use>`
  * SVG 內的 style 區塊 `<defs><style type="text/css"> <![CDATA[  ]]> </style></defs>`
  * SVG 製作動畫可以使用 CSS 動畫或者 JavaScript 動畫
  * 使用 SVG 達成濾鏡校果 (filter)


******************************


### 第八章 - 漸變、變形與動畫


******************************


### 第九章 - 用 HTML5 和 CSS3 征服表單


******************************


### 第十章 - 朝響應式網頁設計邁進

  * 漸進增強
  * 支援的瀏覽器, 功能均等而非美感均等
  * JavaScript 使用與 CSS 相同的中斷點, 可以透過 CSS before, after 配合 media query 綁定特定字串，JavaScript 讀取決定中斷情況。
  * 使用 3wc validator 或者其他 linter
  
#### 效能
  * 減少需要外連的資源數量
  * 減少 size
  * 延遲非必要的內容
  * 讓網頁盡早能用
  * 有辦法測試才能優化, 使用效能檢測工具。
  
