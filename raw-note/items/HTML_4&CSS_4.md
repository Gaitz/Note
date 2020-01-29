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
  * 影片字幕, `<track src srclang kind label default>`

#### 檔案格式
  * 多媒體檔案格式與 MINE 類型
  * 記得在 server-side 配合多媒體檔案格式設定正確的 MINE 類型
  * 除了 `src` 之外改以多個 `<source>` 來指定來源，可以提供多種檔案格式

#### 透過 JavaScript 操作
  * audio API
  * video API


------------------------------


### 第六章 - CSS3 的吸睛特效與絢麗字體

#### CSS3使用策略
  1. 能用則用
  2. 不同瀏覽器可以看起來不一樣但是行為要一致。
  3. 必須加上備援機制, Modernizr / CSS fallback / 查詢 caniuse 帶上前綴

#### CSS3 新功能
  * 透明度 (Transparency)
    * `rgba()`
    * `opacity()`
  * 弧形邊角 (Rounded Corners)
    * `border-radius`
    * 可以設置成橢圓邊角, Ex. `border-top-left-radius: 150px 30px;`
  * 多重背景 (Background)
    * `background-image`
    * `background-position`
    * `background-repeat`
  * 陰影 (Shadow)
    * `box-shadow`
    * `text-shadow`
  * 漸層 (Gradients)  
    * 線性漸層 `linear-gradient()`
    * 放射漸層 `radial-gradient()`
    * 循環漸層 `repeating-linear-gradient(), repeating-radial-gradient()`
  * 轉場 (transition)
    * `transition`
    * 範例 `opacity`, `box-shadow`, `gradient`, `transform` 
  * 變形 (transform)
    * 2D transform, 3D transform
  * 網頁字體 (Web Font)
    * `@font-face`
    * 下載免費字體 Font Squirrel
    * 使用 Google Fonts
    * 付費字體 https://fonts.com https://typekit.com
  * 欄位文字排版 (Column)
    * `column-count`
    * `column-gap`
    * `column-rule`
    * `column-span`


------------------------------


### 第七章 - CSS 的自適應式網頁設計 (Responsive Web Design)

#### 流體排版
  * 從固定尺寸改成百分比排版 `%`
  * `box-sizing: border-box`
  * `calc()`

#### 流體圖片
  * `max-width: 100%`
  * 無論顯示大小，圖片都會被完整的下載。小心大圖造成的效能問題

#### 流體字型
  * `em`, `rem` 取代 `px`

#### 設置 viewport
  * `<meta name='viewport' content='initial-scale=1.0' />`

#### Media Query
  * `@media () {}`
  * media query 不會增加 CSS 選擇的權重
  * 設計時行動裝置優先 (mobile first)
  * 連結整份樣式表 `<link rel='stylesheet' media='' href />`
  * 查詢裝置大小 www.mobitest.me/devices
  * 影片的 media query, `<source media src type />`


------------------------------


### 第八章 - Canvas 的基本繪圖功能

#### Canvas 基礎入門
  * 必須配合 JavaScript 使用
  * `<canvas id width height ></canvas>`
  * JavaScript
    1. `getElementById()`
    2. `getContext("2d")`
  * 原點(0, 0) 為左上角

#### 直線
  * `moveTo()`, 畫筆移動到起始點
  * `lineTo()`, 畫線到
  * `stroke()`, 實際畫出
  * 在呼叫 `stroke()` 實際畫出內容之前，還可以設置 `lineWidth`, `strokeStyle`, `lineCap`
  * `beginPath()` 重新開啟一段，否則呼叫 `stroke()` 時會重新繪製先前所有的內容。

#### 路徑和形狀
  * `closePath()`, 關閉路徑
  * `fillStyle`, 填滿設定
  * `fill()`, 實際填滿內容
  * 可以使用一樣的路徑配合 `stroke()` 畫出邊框

#### 方形
  * `fillRect()` 左上座標, 寬度, 長度, 配合 `fillStyle` 設定
  * `strokeRect()`, 配合 `lineWidth`, `strokeStyle` 設定

#### 曲線和圓形
  * `arc()`, `arcTo()`, `bezierCurveTo()`, `quadraticCurveTo()`
  * `arc()`, 圓心, 半徑, 起始角度, 中止角度, 0 ~ 2 Math.PI
  * `bezierCurveTo()` Bezier 曲線, 兩個控制點, 和終點

#### 變形
  * `translate()` 平移畫布 (移動原點)
  * `scale`, `rotate`, `matrix`

#### 透明度
  * `rgba()`
  * `globalAlpha` context 參數

#### 複合運算 (Composite Operations)
  * 設定相疊的行為, default: `source-over`
  * `globalCompositionOperation` context 參數
  * `source-over`, `source-in`, `source-out`, `source-atop`, `destination-over`, `destination-in`, `destination-out`, `destination-atop`, `lighter`, `copy`, `xor`

#### 儲存
  * 儲存成資料網址 `toDataURL()`, base64
  * 取得原始資料 `getImageData()`
  * 儲存生成步驟清單


------------------------------


### 第九章 - Canvas 進階: 互動性與動畫
  * 在 Canvas 中所有的動畫與互動功能都需要自行使用 JavaScript 實作，因此可以選用函式庫。
 
#### 繪製圖片
  * 畫出現有的圖片, `drawImage()`, 現有的 `<img>`, `Image` 物件, 甚至是另一個 `<canvas>`, 或者播放中的 `<video>`。
  * 裁切現有圖片, 重設圖片大小 `drawImage()` 代入更多參數。

#### 繪製文字
  * 只能繪製單行，多行文字需要自行斷行，配合參數 `font`, `textBaseline` 設定
  * `fillText()`, 繪製實心文字
  * `strokeText()`, 繪製空心文字, 配合屬性 `lineWidth`, `strokeStyle`
  * 繪製文字效能較差，在需要效能最佳化的情況下，可以把文字存成圖片檔，使用 `drawImage()` 畫出。

#### 陰影
  * 屬性 `shadowColor`, 陰影顏色
  * 屬性 `shadowBlur`, 陰影模糊程度, 最清晰是 0
  * 屬性 `shadowOffsetX`, `shadowOffsetY`, 陰影位置

#### 利用圖片填滿
  * `createPattern()`, 參數 src, `repeat-x`, `repeat-y`, `repeat`
  * pattern 設定給 `fillStyle` 或 `strokeStyle`

#### 利用漸層填滿
  * 支援線性漸層 (linear-gradient) 與放射漸層 (radial-gradient)
  * `createLinearGradient()`, 創造線性漸層給予兩個點
  * `createRadialGradient()`, 創造放射漸層給予兩個圓
  * 設定漸層顏色 `addColorStop()`, 0 起點 ~ 1 終點, 及顏色。

#### 互動功能
  * 紀錄繪製
  * 點擊測試

#### Canvas 動畫
  * 使用 `setTimeout()`, `setInterval()`, 清除與重新繪製
  * 在 mobile 時可能會有效能問題，要多測試並且最佳化。
  * 瀏覽器通過硬體加速 (hardware-acceleration) 把繪圖交給顯示卡處理。


------------------------------


### 第十章 - 儲存你的資料
  * 分成伺服器端 (server-side) 與客戶端 (client-side)
  * 客戶端是瀏覽器軟體

#### 客戶端儲存 Web Storage 入門
  * `localStorage`, 長期儲存
  * `sessionStorage`, 暫存
  * 儲存容量以各瀏覽器實作為準
  * 儲存以 domain 區分
  * key-value pair storage, 資料都以字串儲存
  * `setItem()`, `getItem()`, `removeItem()`, `clear()`, `key()`
  * 字串以外的型別，需要做型別轉換。例如 `Number()`
  * 儲存物件時可以通過 `JSON`, `JSON.stringify()`, `JSON.parse()`
  * `window.onStorage` 事件，`addEventListener("storage")`，監聽事件可以讓同 domain 跨頁上做出互動。

#### File API 檔案操作
  * 取得檔案的方式
    * `<input type="file">` 元素
    * 隱藏的 `<input type="file">` 元素, 使用 JavaScript 觸發
    * 拖拉 API (drag-and-drop), `onDragEnter`, `onDragOver`, `onDrag` 配合 `event.stopPropagation()`, `event.preventDefault()`, `event.dataTransfer.files`
  * `FileReader()` 非同步處理, 需配合 `onload` 事件
    * `readAsText()`, `readAsBinaryString()`, `readAsArrayBuffer()`, `readAsDataUrl()`
    * 配合 `Blob` (binary large object) 物件

#### IndexedDB 瀏覽器中的資料庫
  * 
