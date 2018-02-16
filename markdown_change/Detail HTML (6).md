Detail HTML
==

PURPOSE: 網頁前端設計入門
--

## NEXT: HTML5 API 生成圖形與動畫

[TOC]

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
可以把玩的檢查清單
==

* HTML 負責網頁中的 **結構**
* 語法由**標籤** tags 與**屬性** attributes 組成
* **文件標準宣告** `<!DOCTYPE html>`
* `<html>` # 指定 html
* `<head>` # metadata
* `<body>` # 展示
* **註解** `<!-- comments -->`
* **表格** `<table>`
* **清單** `<ol>`, `<ul>`, `<li>`
* **超連結** `<a>`
* **圖片與多媒體** `<img>`, `<video>` ...
* **可以排版的文字區塊** `<pre>`
* css 與 `<style>`
* **文字段落** `<p>`
* **標題**六種大小 `<h1>`, `<h2>`, ... , `<h6>`
* 分**區塊** `<div>`, `<span>`
* 含有語義的區塊 **semantic** block `<nav>`, `<header>`, ...
* **區塊命名與指定** `(id)`, `(class)`
* **內嵌視窗** `<iframe>`
* javascript 與 `<script>`
* **使用者輸入輸出** `form`, `(input)`, `(output)`
* **HTML APIs** `geolocation`, `drag/drop`, `web storage`, `web workers`...
* **圖形與多媒體** `<canvas>`, `<svg>`, `<video>`, `<audio>`...
* **Viewport** 為不同瀏覽裝置設定不同的大小設定。


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 入門簡介 Wikipedia

[Wikipedia of HTML](https://zh.wikipedia.org/wiki/HTML)

* 標記語言 **markup** language
* 標籤 成對出現 **tags**
* 屬性 **attributes**
* 伺服器, HTTP協定, 瀏覽器
* HTML 標準由 World Wide Web Consortium (W3C) 訂定

[Wikipedia of HTML5](https://zh.wikipedia.org/wiki/HTML5)

* 最新的修訂版本
* 希望以 HTML, CSS, Javascript 取代其他外掛程式
* 更多的 **API** 
* **動畫**效果以 CSS 與 Javascript 實作取代 Flash 等外掛程式

[Wikipedia of Canvas 畫布](https://zh.wikipedia.org/wiki/Canvas_(HTML%E5%85%83%E7%B4%A0))

* HTML5 的新功能
* 可以藉由 Javascript 存取實作出圖形、動畫與遊戲

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 學習主軸 1. [Codecademy - Learn HTML](https://www.codecademy.com/catalog/language/html-css)

* 標題標籤 有六種大小 (**h**)
   `<h1> </h1>` 最大
   `<h6> </h6>` 最小

* 文件標準宣告 
   `<!DOCTYPE html>` # 必須在第一行, 已經代表 html5

* HTML標籤 (**html**)
  `<html> </html>` # 把 html 程式碼寫在其中
 
* Metadata 區塊 (**head**)
  `<head> </head>` # 網頁內容之外的描述
  
  * 網頁 (**title**)
    `<title> </title>` # 顯示在網頁 bar 上的文字

* 網頁內容主體 (**body**)
   `<body> </body>` 

* 段落 (paragraph) (**p**)
    `<p> </p>` # 放置純文字為主 (text)

* 分區塊 (divide) (**div**) # 但是並沒有語意說明區塊是什麼。(non-semantic tag)
    `<div> </div>` # 其中包含其他的 html 語法與純文字 

* 斷行 line break (**br**)
    `<br />` # 可放在任何地方例如 `<p> <br /> </p>`

* 強調 
    `<em> </em>` # 斜體
    `<strong> </strong>` # 粗體

* 清單 lists (**li**)
        
       * 無序清單 unordered list (**ul**)
        `<ul> </ul>`         
       * 有序清單 ordered list (**ol**)
        `<ol> </ol>`
        
   `#兩種皆無法直接放置內容，需要配合<li> </li>標籤作為一個單位。`
   例如: 

        
        <ol>
          <li> item 1 </li>
          <li> item 2 </li>
        </ol>
        

* 插入圖片 image (**img**)
    `<img src="" />` #包含一個屬性 source (src)，後面的字串中必須是 uniform resource locator (URL)。
     
     `<img src="" alt="" />` # alt 屬性，作為圖片的描述，可以幫助使用者了解圖片內容。
     
* 插入影片 (**video**)
     `<video src="" width="" height="" controls> error messages </video>`     
     `#`包含四個屬性檔案位置 (src), 寬度 (width), 高度 (height), 提供基本影片控制功能 (controls)
     `#` 包含一個純文字內容 text，文字只會在影片無法執行時顯示，
     因此是個影片錯誤訊息。

* **超連結** hyperlink, anchor 標籤 (**a**)
    `<a href="">  </a>` # 包含一個屬性 hyperlink reference (href) 連結到的位置。網址連結必須包含 `https://` 或 `http://`
     
    * `#` 超連結可以使用純文字或者圖片作為連結。 
    ` <a href=""> <img src=""  /> </a>`
    
        
    * 超連結在新視窗開啟，使用屬性 (**target**) 來描述開啟的位置：
    `<a href="" target="_blank"> </a>`
    
    * 內部網頁超連結，使用相對路徑 (./)
        `<a href="/index.html">  </a>`
    
   * 網頁內 **id** 連結，連結使用 (#)
        多數標籤都可以加上屬性 (id)，之後都能當作一個跳躍點
        `<a href="#id_name"> </a>`
       
    * 跳到其他網頁的指定 id 位置
      `<a href="/index.html#place"> </a>`
 
 
* 語意標籤 (**semantic tags**) # 為了更好的閱讀性，讓程式碼依據功能分區塊，使用具有明確意義的標籤。
    
    * 超連結區塊 navigation (**nav**)
      `<nav> </nav>`

* 表格 (**table**)
  `<table> </table>` 
  
    * 列 table rows (**tr**)
    `<tr> </tr>`

    * 資料 table data (**td**)
    `<td> </td>`
    
    * 表格項目標題 table headings (**th**)
    `<th scope="col"> </th>` # 屬性 (**scope**) 可為 "row" / "col"，說明這項標題是給予行或列。
    
    * 表格邊框的大小 # 請使用 css 而非 html 屬性去達成。
    
    * 合併表格 
        * 向右 行合併 span columns (**colspan**)
          `<td colspan="numberOfColumns"> </td>`
        
        * 向下 列合併 span rows (**rowspan**)
        `<td rowspan="numberOfColumns"> </td>`

    * 把表格分類成 標題項目, 內容與總結 三個部份 table head (thead), table body (tbody), table footer (tfoot) 達到程式碼有較好的閱讀性。
      `<thead> </thead>`
      `<tbody> </tbody>`
      `<tfoot> </tfoot>`
    
    * 使用 css 控制與裝飾表格細節。

* **縮排慣例** 
    `2 個空白`

* **註解**
    `<!-- comments here -->`


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 學習主軸 2. [W3Schools tutorial- HTML](https://www.w3schools.com/)

**Do all exercises**


* html 負責處理網頁的 **結構**  (structure)。
* html 文件編碼使用 **UTF-8**

* 為了嚴謹性，讓所有的標籤都是關閉的 **closed**。包含空的項目，例如：`<br />` # / 代表關閉。

* 指定語言 (**lang**)
  `<html lang="en-US">` # 語言與方言

* 屬性 (**title**) # 讓滑鼠移動到特定區塊顯示提示文字
  `<p title="paragraph title"> </p>`
  `<h1 title="header title"> </h1>`

* 參數的雙引號 `"` 與單引號 `'` ，可以替換使用，使用時以雙引號為優先。
 
* 分段線 Horizontal Rules (**hr**)
  `<hr /> `

* 利用 chrome 瀏覽器，按**右鍵**可以閱讀程式碼 (source code) 或者 html element (inspect)。

* 可以排版的文字段落 preformatted text (**pre**)
`<pre> </pre>` # 類似於 `<p>` 但是內容不會省略空白與斷行。

* 屬性 (**style**)， html 文件中單行內嵌的 css 程式碼來指定樣式 (inline style for single element)。
    例如：文字顏色 (color), 背景顏色 (background-color), 字型 (font-family), 字形大小 (font-size), 文字對齊 (text-align)。

* 文字格式標籤 **text**: 粗體 (b), 斜體 (i), 強調 (em), 重要 (strong), 標示 (mark), 下標 (sub), 上標 (sup), 底線 (ins), 刪除線 (del)。

* 引言標籤 **quote**: 短引言 (q), 段落引言 (blockquote), 縮寫 (abbr) # 配合 (title) 屬性。

* 顏色表示方式 **color**：預設的顏色文字, RGB, HEX, HSL, RGBA, HSLA。

* **Cascading Style Sheets (css)** 樣式設定，使用的方式有三種：
 1. **inline**, 在 element 中使用屬性 (style)。
 2. **Internal**, 在 html 檔案中的 metadata 區塊 (head) 使用 (style) 標籤。 
 3. **External**, 在 html 中的 metadata 區塊指定路徑至 `.css` 檔案，撰寫在外部檔案中。# 主要使用這種方式

* 圖片 (**img**)
    * 建議使用：每張圖片都指定寬度 (width) 與高度 (height)
    * 在段落 (p) 中加入圖片並且指定圖片的位置 左或右，使用 css 中的 (float)。
    * 分割一張圖片中的位置，並且製作成連結，使用 map 標籤。
    * 背景圖片的 css 語法為 (background-image:url('  '))
    * HTML5 新增的 picture 標籤更靈活的操作圖片顯示。

* 表格 (**table**)
    * 表格標題標籤 (**caption**)
      `<caption> </caption>`

* 清單 
    * 無序清單 (ul) 的符號，使用 css 修改 `style="list-style-type: "` 選項有 circle, square, none。
    * 有序清單 (ol) 的符號更改，使用屬性 (type) 選項有 1, a, A, i, I  。
    * 可以利用 css 製作出水平清單，可當作水平目錄連結使用。
      `float:left;`
    
* (**div**) 與 (**span**) 的使用時機
  兩者都作為可以被屬性 (style) 描述的區塊 block 使用。 
    * (div) 作為數個 **elements** 的容器，包出一個區塊來指定裝飾。
    * (span) 作為 inline 使用，包出一塊**文字**區塊來指定描述。 

* (**class**) 與 (**id**)
    * 屬性 id，在同一個 html 裡頭不能有同名的，id 是唯一指定作為操作的名稱。
    例如：
    `<div id=""> </div>`
    
    * 屬性 class，可以被重複使用的指定。
     
     可以使用在 css internal style 描述，例如：
     
     ```
     <style>
     .className {
         some css code;
     }
     </style>
     ```
     element 可以擁有多個 class 指定。例如:
     `<div class="classA classB"> </div>`
    
* 網頁內的視窗 inline frame (**iframe**)
  `<iframe src="url"> </iframe>`

* (**script**) 標籤，配合客服端的 script : javascript 使用。
  `<script> javascript codes </script>`

* 檔案路徑，推薦使用相對路徑 (relative path)，這樣在更改網站 domain 時，不用修改路徑。

* Metadata 區塊 (**head**) 可以包含
  
  標題標籤 (title), 
  css 標籤 (style), 
  額外資訊標籤 (meta), 
  外部資源連結標籤 (link), 
  javascript 標籤 (script), 
  基本預設修改標籤 (base)。

* **Layout** 畫面的分層，由 css 實作。

* 使用者輸入 (**form**), (input)

* HTML5
  * 含有語義的區塊 **Semantic**
    Examples:  `<nav>`, `<article>`, `<header>` ...
  
  * 輸入輸出相關 **form** 與更多 **input types**
     Examples: `<output>`
     
  * 圖形相關 **Graphics** 
    Examples: `<canvas>`, `<svg>`

  * 多媒體相關 **Media** 
     Examples: `<audio>`, `<video>`

* **HTML APIs** 
  * 使用者位置資料 geolocation 
  * 圖片拖拉 drag/drop
  * 客服端資料暫存 web storage  # 與 cookies 不同
  * 背景執行程式 web workers 
  * 與伺服器端互動 Server-Sent Events



# 真實文本, mud your hand

* https://github.com/thedaviddias/Front-End-Checklist
  前端網頁設計的檢查清單

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 其他資源

https://www.freecodecamp.org
freeCodeCamp

https://developer.mozilla.org/en-US/docs/Web/HTML/Element
list of all html tags

http://htmlreference.io/
html reference

https://www.youtube.com/channel/UC_jMDZX_-HTrFVX-UY0He0g/featured
切版影片

http://www.tutorialspoint.com/tutorialslibrary.htm
tutorials

# Questions

* 什麼是文件物件模型( Document Object Model, DOM ) ?

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

Working Part 整合進 list 結構
**List**

List Subject
**List Computer Science**

**Detail HTML (6)**

Next Working Part 
**Working Part CSS**
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTU5Njk3MTMwM119
-->