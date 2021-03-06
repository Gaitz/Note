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
  * `<a>`, 可以容納行內和區塊元素, 新屬性 download, media, ping. 特別的 href(`mailto:`, `tel:`, `sms:`...)
  * `<small>`, 文件小字體的部份, 例如法律條文..
  * `<s>`, 已經不正確或不相關的
  * `<i>`, 突顯重點
  * `<b>`, 字體上的不同
  * `<u>`, 突顯文字, 例如拼錯的字
  * `<cite>`, 標記標題, 例如書籍, 歌曲...
  * `<em>`, 強調文字
  * `<strong>`, 重點文字, 重要的
  * `<q>`, 引用文字
  * `<dfn>`, 定義
  * `<abbr>`, 縮寫, 配合 title 屬性標明完整文字
  * `<code>`, 程式碼
  * `<var>`, 數學或程式變數
  * `<samp>`, 程式的輸出範例
  * `<kbd>`, 使用者鍵盤輸入
  * `<sub>`, 下標
  * `<sup>`, 上標
  * `<bdo>`, 改變文字方向
  * `<span>`
  * `<br>`, 分行
  
#### 內嵌元素
  * `<embed>`, 整合第三方資源, 屬性 src, type
  * `<video>`
  * `<audio>`
  * `<source>`
  * `<track>`
  * `<canvas>`
  * `<img>`, 屬性 srcset 
  * `<iframe>`, 屬性 srcdoc(建立iframe裡的html), sandbox(控制iframe的限制), seamless(無外框,可以繼承父文件的樣式)
  * `<object>`, 必要屬性 data, type
  * `<param>`, 屬性 name, value
  * `<map>`
  * `<area>`, 屬性 rel, ping, media, hreflang

#### 互動式元素
  * `<details>`, `<summary>`, 屬性 open
  * `<menu>`, `<menuitem>`, 尚未支援, 透過表單控制項, 產生互動功能


******


### 第四章 - HTML5 Web 表單

#### `<input>` 屬性
  * `type`, 預設是 text
  * `required`, 必填, 空值或錯誤格式會停止 submit
  * `min`, `max`, 限制數值最小、最大
  * `step`, 遞增遞減值
  * `placeholder`, 佔位文字, 需配合 `<label>` 達到無障礙功能
  * `pattern`, 指定 regular expression 來驗證輸入, 配合屬性 title 來說明限制。
  * `readonly`, 不可編輯, 會被送出。
  * `disabled`, 不可編輯, 不會被送出。
  * `maxlength`, 長度限制, 不建議使用, 使用者體驗不佳。
  * `size`, 
  * `form`, input 不需要被包在 `<form>` 中也可以一起被傳送，指定 form 屬性到表單 id。
  * `autocomplete`, 提供瀏覽器建議是否要自動填入。
  * `autofocus`, 整頁中只能有一個 autofocus 自動聚焦。
  * `name`,
  * `value`,
  * `id`, 

#### `<input type="">` 類型
  * `type="text"`, default
  * `type="password"`, 傳送密碼務必使用 POST
  * `type="checkbox"`, 確認方塊, 務必填上 name, value
  * `type="radio"`, 單選按鈕, 同組使用相同的 name, 不同的 value, 可配合 `type=reset` 取消選定。
  * `type="submit"`, 可以透過 form 屬性指定要傳送的 form 表單, 取消發送表單行為方法 
    1. disabled, 
    2. JavaScript `return false;` 
    3. JavaScript `preventDefault()`
  * `type="reset"`, 重設按鈕, 不推薦使用, 使用者體驗不佳。
  * `type="file"`, 屬性 `accept` 指定檔案類型, `capture` 指定行動裝置使用設備。
  * `type="hidden"`, 傳送使用者看不到的值
  * `type="image"`, 包含所有 `<img>` 的屬性, 可給予 name, value 傳送值。
  * `type="button"`,  需要配合 JavaScript 提供功能, `<button>` 更適合 CSS。
  * `type="search"`, 搜尋欄位 
  * `type="tel"`, 電話號碼, 可以配合 placeholder 和 pattern 使用
  * `type="url"`, url, 不會檢查, 可以配合 pattern 使用
  * `type="email"`, email 支援 multiple
  * `type="datetime"`, 日期 + 時間, 可以配合 min, max, step 或者 pattern 來做驗證
  * `type="datetime-local"`, 同 datetime 但不是 UTC 
  * `type="date"`, 年、月、日的日期
  * `type="month"`, 年、月, 可設置 min, max, step
  * `type="week"`, 年、當年週數 01 ~ 52 
  * `type="time"`, 24時制, 可設置 min, max, step 以秒遞增。 
  * `type="number"`, 數字, 可配合 min, max, step 做驗證優先程度強於 pattern 驗證。可以使用 pattern 驗證當作候補。
  * `type="range"`, 配合 min, max, step 產生可拖拉的範圍區間。
  * `type="color"`, 預設 #000000

#### 表單驗證
  * HTML5 用戶端驗證
  * JavaScript Validity API, 與 HTML5 驗證方法互動、客製化。
  * CSS 改變驗證 UI, ::-webkit-validation-bubble
  * input:required, :invalid, :valid, :read-only, :checked

#### 其他表單元素
  * `<datalist>` 配合 `<option>` 使用提供**建議**資料選項, input 的 list 屬性指定哪個 datalist 提供選項。
  * `<output>`, 類似 `<span>` 提供語義與表單屬性 name, form 等等, 表單中的顯示區塊。
  * `<meter>`, 計量顯示, 配合 min, max, high, low, optimum
  * `<progress>`, 顯示進度
  * `<keygen>`, 金鑰, 授權..
  * `<form>` 屬性 novalidate 取消驗證功能。
  * `<button>`, 三種類型 submit (default), reset, button 
  * `<label>`, 配合 for 指定說明


******


### 第五章 - SVG、Canvas、音訊與視訊

#### SVG
  * 向量基底的圖片或動畫
  * 以 XML 為基礎, 需要 SVG DTD，`<svg></svg>`, 結構存在於 DOM 中。
  * `<title></title>`, `<desc></desc>` 作為說明用途
  * style 使用方式跟一般 CSS 類似, inline, `<style></style>`, 外部檔案
  * `<img src=".svg" alt />`
  * `<embed type="image/svg+xml" src=".svg" width height/>`
  * `<object data=".svg" type="image/svg+xml" width height ></object>`
  * `<svg>` 屬性 `viewbox`: min-x, min-y, width, height, `preserveAspectRatio`
  * [W3C 規格書](https://www.w3.org/TR/SVG/), 免費工具 [Amaya](https://www.w3.org/Amaya), [Inkscape](https://inkscape.org/)

#### Canvas
  * 繪畫用的 JavaScript API, 像素基底的圖片或者動畫
  * `<canvas></canvas>` 畫板元素
  * 直譯式的變數宣告與繪製

#### WebGL
  * SVG, Canvas, WebGL 在行動裝置上都有可能會有效能問題，需要評估使用。

#### 音訊 `<audio>`, 視訊 `<video>`
  * 注意各瀏覽器支援的檔案格式，確認目標瀏覽器支援編碼。
  * `<video>`, `<audio>` 屬性
    * src 單個來源, `<source>` 子節點承載多個來源。
    * autoplay,
    * loop,
    * controls,
    * preload,
  * `<video>` 屬性
    * poster, 預覽圖
    * width,
    * height,
  * `<track>` 元素, 連結字幕檔案
    * 屬性 kind, 類型, subtitles, captions, descriptions, chapters, metadata
    * 屬性 src 來源, srclang 內容語言, label 描述, default 設定預設的 `<track>`
  * 內容可以使用 JavaScript API, CSS 控制, 與 Canvas 互動


******


### 第六章 - 其他的 HTML5 API

#### 離線功能
  * `navigator.onLine` 判斷是否在線上

#### 應用程式快取 Application Cache API
  * mobile 容量限制 5MB
  * `<html manifest='url To .appcache file'>`
  * 更新快取，必需先更新 manifest 裡的內容。
  * 只有在瀏覽器更新完所有新的內容後，並且在下一次的載入才會有全新的內容，之外都採用舊的快取顯示。
  * 快取清單檔 `.appcache`
    * 第一行必為 `CACHE MANIFEST` 
    * 註解行以 `#` 開頭
    * 四種類型區隔 `CACHE:`, `NETWORK:`, `FALLBACK:`, `SETTINGS:`
    * `CACHE:`, 會被快取的檔案 **不可以**將 .appcache 放在 `CACHE:` 裡, 不然頁面永遠不會被更新。
    * `NETWORK:`, **不會**被快取的檔案
    * `FALLBACK:`, 檔案備援配對
    * `SETTINGS:`, 
  * 更新快取, 
    1. 通過更新快取清單檔 `.appcache`, 只更新快取檔案內容不會自動更新。
      * 例如修改快取清單檔裡面的註解 `# timestamp` 造成快取清單檔內容改變。
      * 如果快取清單檔得到 404 回應也會讓瀏覽器清除快取。
    2. 使用 applicationCache JavaScript
      * `window.applicationCache.status`, UNCACHED, IDLE, CHECKING, DOWLOADING, UPDATEREADY, OBSOLETE
      * `window.applicationCache.swapCache()`

#### 瀏覽器端暫存 storage
  * localStorage, sessionStorage, IndexedDB, Web SQL Database (deprecated)
  * 與 cookie 的差別
    * cookie 會帶在 http 上增加頻寬, KB 級的容量限制
  * localStorage domain 共享, 關閉瀏覽器不會被刪除。
  * sessionStorage domain 共享，關閉瀏覽器會被刪除。
  * localStorage, sessionStorage, 都是 key-value pair storage, API 操作是同步執行的。
    * `setItem(key, value)`,
    * `getitem(key)`,
    * `removeItem(key)`,
    * `clear()`,
    * `key(position)`,
    * `length`,
  * IndexedDB, 關聯式資料表的儲存，API 操作是非同步執行的。

#### 地理定位 geolocation
  * 得到使用者的地理位置資訊，非同步的 API
  * `getCurrentPosition()`, latitude 緯度, longitude 經度, altitude 海拔, accuracy
  * `watchCurrentPosition()`, heading 方向, speed 速度

#### Web Workers
  * 額外的執行序, 背景執行與 DOM 無關的 JavaScript, 與 UI 執行序平行處理。
  * `new Worker('.js')`,
  * 訊息溝通使用 `postMessage()` 配合 `onmessage` 事件
  * web worker 中可以配合 timeout 和 interval 來做週期執行。
  * `importScripts()`, 載入其他 js 庫

#### Microdata
  * SEO 相關, HTML5 標準
  * 使用新的屬性 `itemscope`, `itemprop`, `itemref`, `itemtype`

#### 跨文件溝通
  * 可以跨 domain 的溝通
  * 通過 `postMessage(message, domain)` 傳遞訊息到別的 domain
  * 通過 message event listener 讀取資訊，`event.origin` 辨別來源，為了安全性一定要辨別來源。

#### ARIA 無障礙網頁 (Accesible Rich Internet Applications)
  * 網頁增強功能
  * 最重要且最容易加入的屬性 `role`，最佳策略還是選用原生語義的元素。


******


### 第七章 - 升級 CSS3

#### media query
  * device: all, braille, embossed, handheld, print, projection, screen, speech, tty, tv
  * width, 視區寬度, min-width ,max-width
  * height, 視區高度, min-height, max-height
  * device-width, 螢幕寬度, min-device-width, max-device-width
  * device-height, 螢幕高度, min-device-height, max-device-height
  * orientation, 直向或橫向
  * aspect-ratio, 視區寬度 / 視區高度, min-aspect-ratio, max-aspect-ratio
  * device-aspectratio, 螢幕寬度 / 螢幕高度, min-device-aspectratio, max-device-aspectratio

#### CSS Best Practice
  * 減少 http request, 使用 bundle.css 單一檔案。
  * 使用外部樣式表 `<link rel="stylesheet">`
  * 使用 reset.css 或者 normalize.css
  * 使用較不明確的選擇器，每個選擇器使用小於三種規則，維持**效能**、**明確性**、**可閱讀性**之間的取捨。
  * `inline style` 與 `!important` 只用於 debug。

#### CSS selectors
  * 元素選擇器, element,
  * 多重選擇, 以 `,` 分隔選擇器
  * class 選擇器, `.`, 大小寫有別
  * id 選擇器, `#`, 大小寫有別
  * 萬用選擇器, `*`
  * 後代選擇器, `E F`, 以一個或多個空白間隔
  * 直接子代選擇器, `E > F`
  * 相鄰選擇器, `E + F`, E 相鄰的 F
  * 鄰居選擇器, `E ~ F`, E 之後所有的 F
  * 屬性選擇器, `E[attr]`, 具有屬性
    * `E[attr=val]`, 具有屬性，值為 val
    * `E[attr|=val]`, 具有屬性，值為 val 或 val-
    * `E[attr~=val]`, 具有屬性，值為 val
    * `E[attr^=val]`, 具有屬性，值開頭為 val
    * `E[attr$=val]`, 具有屬性，值結尾為 val
    * `E[attr*=val]`, 具有屬性，值含有 val 子字串
  * 擬類別 Pseudo-classes
    * `:link`, 未造訪連結
    * `:visited`, 已造訪連結
    * `:hover`, 游標覆蓋
    * `:active`, 
    * `:focus`, 被聚焦的
    * `:enabled`,
    * `:disabled`,
    * `:checked`, input 被選取的
    * `:indeterminate`, 未被選取的
    * `:default`,
    * `:valid`,
    * `:invalid`,
    * `:in-range`,
    * `:out-of-range`,
    * `:required`,
    * `:optional`,
    * `:read-only`,
    * `:read-write`,
    * `:root`, 根元素 `<html>`
    * `:nth-child(n)`, even, odd, (x*n+y), n start from 0
    * `:nth-last-child(n)`, even, odd, (x*n+y)
    * `:nth-of-type(n)`, even, odd, (x*n+y) 
    * `:nth-last-of-type(n)`, even, odd, (x*n+y)
    * `:first-child`,
    * `:last-child`,
    * `:first-of-type()`,
    * `:last-of-type()`,
    * `:only-child`,
    * `:only-of-type`,
    * `:empty`, 沒有子元素
    * `E:target`, 錨點
    * `E:lang(L)`, 配合屬性 lang 語言選擇器
    * `E:not(s)`, 反向選擇
  * 擬元素 pseudo-element, 從 DOM 上取得不到的元素
    * `:before`, 可以配合 `{ content: '' }` 給值
    * `:after`, 可以配合 `{ content: '' }` 給值
    * `:first-line`,
    * `:first-letter`,
  * 各個瀏覽器自有的選擇器


******


### 第八章 - 擴充的 CSS3 特性

#### CSS 顏色值
  * `#RRGGBB`, `#RGB`, 16進位顏色值, 不區分大小寫
  * `rgb(255,255,255)`, `rgb(100%, 100%, 100%)` 數字或者百分比
  * `rgba()`, 增加 alpha 透明度, 1 不透明 ~ 0 完全透明
  * `hsl()`, 色調(hue) 0 ~ 359, 彩度(saturation) 0 ~ 100%, 亮度(lightness) 0 ~ 100%
  * `hsla()`, 增加 alpha 透明度, 1 不透明 ~ 0 完全透明
  * `currentColor` 對應到當前的 `color:` 值, example: `text-shadow: 0 0 1px currentColor;`
  * 瀏覽器顏色值, 統一的或各瀏覽器不同的, 例如 `activateBorder`, `background`, `-webkit-link`, `-moz-buttonDefault`...

#### CSS 計量單位
  * 長度值
    * px, 像素, 相對於螢幕解析度
    * %, 相對於**父**元素
    * em, 相對於**父**元素字形大小
    * rem, 相對於**根**字形大小
    * vw, 視區寬度百分比 100vw
    * vh, 視區高度百分比 100vh
    * vmin, vh, vw 的較小值
    * vmax, vh, vw 的較大值
    * ex, 相對於`小寫x`的高度
    * ch, 相對於字元`0`的大小
    * in, 英吋
    * cm, 公分
    * mm, 公釐
    * pt, 
    * pc,
  * 解析度單位
    * dpi, dpc, dppx
  * 角度、時間、頻率單位 **(使用時必需加上單位，包含 0)**
    * deg, 0deg ~ 360deg, + 順時針, - 逆時針
    * grad, 0grad ~ 400gard, + 順時針, - 逆時針
    * rad, 0 ~ 2pi, 1rad = 180/pi
    * turn, 1turn = 360deg
    * ms, 
    * s, 
    * Hz, 
    * kHz, 


******


### 第九章 - CSS3 模組、模型與圖像
 
  * CSS3 將 CSS 規則分成模組，每個模組有自己的 level 和認證階段。

#### CSS 方塊模型 box-model
  * margin, margin-top, margin-right, margin-bottom, margin-left
  * border, border-style, border-color, border-width, ...
  * padding, padding-top, padding-right, padding-bottom, padding-left
  * border-style: hidden (default), dashed, dotted, double, groove, inset, none, outset, ridge, solid.
  * border-color: currentColor (default)
  * border 配合 transparent 可以做出三角形
  * box-sizing: content-box (default), border-box (width, height 包含 border-size, padding)
  * **相鄰的 margin 會整合在一起** 值都為 + 時取最長, 有正負時則取總和。
  * border-radius, 原生圓角, border-top-left-radius, border-top-right-radius, border-bottom-right-radius, border-bottom-left-radius.

#### CSS 漸層
  * 視為一種圖像的值，可以放在任何使用 image 的 CSS 欄位中。Example: border-image, background-image, list-style-image
  * 線性漸層 linear-gradient 
    * `linear-gradient([<angle> | to <keyword>], <colorstop>, [<colorstop>,] <colorstop>)`
    * **通過中心點**的方向
    * 方向預設值是 `to bottom`
    * 可以設置多組顏色配合起始點百分比
  * 放射漸層 radial-gradient (需考慮效能問題,佔用記憶體)
  * `background-size`, contain: 保持比例縮小, cover: 覆蓋整個元素、切割
    * 只有在 width, height 同時被宣告時，會有破圖的情況，可以其一選用 auto 來保持圖片比例。
  * `background-image` 多重背景

#### 陰影
  * 文字陰影 `text-shadow` 水平偏移量, 垂直偏移量, 陰影寬度, 陰影顏色
  * 處理超過容器的文字, `text-overflow`, `width`, `white-space`, `overflow` 相互配合
  * 方框陰影 `box-shadow`, 內陰影、外陰影


******


### 第十章 - CSS3 變形、漸變、動畫

#### 漸變 Transition
  * 狀態之間的轉變
  * `transition-property`, 要影響的特性, 以 `,` 區隔或者使用關鍵字 `all`。
  * `transition-duration`, 持續時間, `s` or `ms`
  * `transition-timing-function`, 過程函數
  * `transition-delay`, 延遲時間, `0s` (default)
  * `transition`: property, duration, timing-function, delay (縮寫順序)

#### 變形 transform
  * 對元素變形, 不影響流向, box-model
  * `tramsform`, 變形種類 2D 變形, 3D 變形
    * `translate(x, y)`, 位移
    * `translateX(x)`, 水平移動
    * `translateY(y)`, 垂直移動
    * `scale(w, h)`, 縮放 w, h 寬高或單變數等比例縮放
    * `scaleX(w)`, 水平縮放
    * `scaleY(h)`, 垂直縮放
    * `rotate(angle)`, 旋轉
    * `rotateX(angle)`, 以 x 為軸旋轉
    * `rotateY(angle)`, 以 y 為軸旋轉
    * `skew(x, y)`, 傾斜
    * `skewX(x)`, 設定水平向傾斜
    * `skewY(y)`, 設定垂直向傾斜
    * `matrix()`, 混合函數
    * 可以多重種類變形, 以 ` ` 間隔
    * `translate3d(x, y, z)`, 3d位移
    * `translateZ(z)`, trick `translateZ(0)` 可以把渲染運算刻意給 GPU。
    * `scale3d(w, h ,z)`, 3d縮放
    * `scaleZ(z)`
    * `rotate3d(x, y, z, angle)` 3d旋轉
    * `perspective()` 透視效果
  * `transform-origin`, 元素變形的原點, `50% 50% 0` (default), x, y, z 值, 0 0 是左上。
  * `transform-style`, 受變形影響的子元素行為, `flat` (default), `preserves-3d`
  * `backface-visibility`, 背面是否可視, `visible` (default), `hidden`

#### 動畫 animation
  * `animation-name`, keyframe 對應的動畫名稱, `none` (default)
  * `animation-duration`, 一個循環的持續時間, `0s` (default)
  * `animation-timing-function`, 過程函數, `ease` (default)
  * `animation-iteration-count`, 播放次數, `1` (default), 整數, `infinite`
  * `animation-direction`, 循環時的方向, `normal`, `alternate` 正反循環
  * `animation-play-state`, `running` (default), `paused`
  * `animation-delay`, 開始的時間
  * `animation-fill-mode`, 開始前或結束後要保留的值, `none` (default), `backwards`, `forwards`, `both`
  * `animation`, 縮寫使用以上順序, 以 ` ` 間隔。
  * `@keyframes animation-name {  }`, `from {}`, `to {}`, 百分比 `n% {}`


******


### 第十一章 - 響應式 Web 的 CSS 功能

#### Media Query and break point
  * 在變動中發現開始變不好看的時候，增加中斷點。

#### 多重欄位
  * `column-count`, 最大欄位數
  * `column-width`, 最小欄位寬度
  * `columns`: 縮寫 width, count
  * `column-gap`, 欄位間距
  * `column-rule-width`, 分隔線寬度
  * `column-rule-style`, 分隔線樣式
  * `column-rule-color`, 分隔線顏色
  * `column-rule`, 分隔線縮寫, width, style, color
  * `column-span`, `none` (default), `all` 元素橫跨所有欄位
  * `column-fill`, 指定分 column 時的行為

#### 邊框圖片
  * `border-image-source`, 圖片URL, 漸層函數
  * `border-image-slice`, 圖片切割, 選擇要使用的部份
  * `border-image-width`, 邊框寬度
  * `border-image-outset`, 邊框與內容之間的距離, `0` (default)
  * `border-image-repeat`, 除了四個角之外的邊框，如何展示, `stretch`, `repeat`, `round`, `space`
  * `border-image`, 縮寫

#### flexbox
  * `display: flex` or `display: inline-flex` 啟用
  * `flex-direction`, 延伸方向, `row` (default), `column`, `row-reverse`, `column-reverse`
  * `flex-wrap`, 是否折行, `nowrap` (default), `wrap`, `wrap-reverse`
  * `flex-grow`, 與同層元素放大的比率
  * `flex-shrink`, 與同層元素縮小的比率
  * `flex-basis`, 等同於 width
  * `flex`, 縮寫 grow, shrink, basis, 均分 `1 1 0` 
  * `order`, 元素排列順序
  * `justify-content`, 整體元素主軸線上的排列方式
  * `align-content`, 整體元素在正交線上的排列方式
  * `align-items`, 各個元素在正交線上的行為
  * `align-self`, 控制單獨元素在正交線上的行為

#### 偵測功能
  * `@supports` 依據功能支援與否來建立 css, 如同 media query 一般

#### image-set()
  * srcset, 讓瀏覽器選擇要請求的圖片大小, 為不同類型的螢幕給予不同的檔案來源。

#### filter
  * CSS層級的圖片濾鏡


******


### 第十二章 - 行動應用程式設計

#### 設計的注意事項
  * 決定使用者是誰, 什麼族群, 瀏覽的目的, 使用的情境
  * 網站需要 
    * "簡單", 
    * "可理解", 
    * "具相關性"
  * 應用程式什麼類型, 生產立工具, 公用程式, 娛樂程式, 
  * 風格是正式 (簡單, 顏色種類少, 設計單調), 還是有趣。
  * 行動裝置網頁, 仍然要提供完整的內容, 但是呈現是有順序的。
  * 行動裝置網站要思考的特性
    * 小螢幕, => 一次能呈現的內容更少, 循序的瀏覽
    * 較少的記憶體空間, => 縮小原始檔案, 不要載入不需要的資源
    * 多利用開發者工具檢查記憶體的使用
    * 通過 meta data 設置，與行動裝置互動
    * 減少鍵盤輸入
    * 無法使用 hover, 不要使用下拉、彈出式互動。
    * 使用點擊式的互動, 動態載入更多的內容。


### 第十三章 - 以行動與觸控設備為目標
  * 設置 `<meta name="viewport" content="width=device-width"/>`
  * 觸碰而非滑鼠的行為模式, 手指相對於螢幕很巨大。
  * 需要更大的點擊範圍與間隔, height > 22px, 間隔 > 10px
  * 注意所有原生 OS 提供的功能，避免非預期的行為。
  
#### 操作行動硬體
  * event listener `'devicemotion'`, 加速度計
  * event listener `'compassneedscalibration'`, 磁強計
  * event listener `'deviceorientation'`, 陀螺儀
  * Network API, `navigator.connection.type` 檢測連線狀況與品質
  * Battery Status API, `navigator.battery` 檢查目前電池狀況
  * 更多行動裝置上專屬的 API 


### 第十四章 - 行動效能
  * 效能優先
  * 減少 JavaScript 大小與運算量
  * 以 CSS 動畫取代 JavaScript 動畫
  * 使用暗色系設計, 減少發光量 => 減少電源消耗
  * 使用 **JPEG** 比 PNG 擁有更好的壓縮率
  * 減少網路請求, 移除不必要的 polling request
  * 避免重新繪製 (repaint)、重新排版 (reflow)
    * 避免重繪 alpha 等等比較複雜的特性
    * 更少的操作 DOM 節點, 改變 box-model, 刪除複雜的 CSS 選擇器
  * 行動裝置下載延遲，盡可能的減少 HTTP request 和 DNS request
  * 使用瀏覽器快取, 加上適當的 Cache-control response header
  * 單一的 CSS 樣式檔
  * 盡可能的圖片壓縮 gzip, base64, inline SVG, ...
  * 使用開發者工具 network 檢查, 查看各個 request 所需要的時間並且減少他們。
  * 壓縮所有的檔案, JavaScript, CSS, image, ...
  * 使用者開發工具檢查檔案大小
  * 避免非必要的 JavaScript library 或者延遲載入
  * 最小化 DOM 的結點數量與深度
  