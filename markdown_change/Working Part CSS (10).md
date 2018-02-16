Working Part CSS 
==

PURPOSE: 網頁前端 CSS 入門含 CSS frameworks
--

## NEXT: 現有方法不好玩，尋找新的學習方式

[TOC]

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
可以把玩的檢查清單
==




# wikipedia 簡介

[chinese version wikipeida of CSS](https://zh.wikipedia.org/wiki/%E5%B1%82%E5%8F%A0%E6%A0%B7%E5%BC%8F%E8%A1%A8)

[wikipedia of CSS](https://en.wikipedia.org/wiki/Cascading_Style_Sheets)

* 選擇器


[wikipedia of CSS framework](https://en.wikipedia.org/wiki/CSS_framework)

* [Bootstrap](https://en.wikipedia.org/wiki/Bootstrap_(front-end_framework)) 
  
  專注於前端的 framework
  可以選擇使用包含 Javascript 的擴充功能
  開源的專案 GitHub

* [Foundation](https://en.wikipedia.org/wiki/Foundation_(framework))

  回應式, 開源, 包含 Javascript, 前端的 framework

* WC.CSS # 簡單, 只包含CSS

[Sass](https://zh.wikipedia.org/wiki/Sass)

  CSS的前處理器
  
  提供很多語法糖，以程式語言的方式描述設計者的意圖，在轉譯為 CSS 語法。

DOM

  https://ithelp.ithome.com.tw/articles/10108783
  https://openhome.cc/Gossip/JavaScript/W3CDOM.html

  Document Object Model, DOM
  作為程式語言與瀏覽器之間的中間層，一種標準界面。
  前端使用
  由 W3C 訂定。

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 學習主軸 1. [codecademy - learn css]( https://www.codecademy.com/learn/learn-css) undone


* Cascading Style Sheets, CSS 

* 為了從 HTML 中分離樣式 (style) 程式碼，
  **HTML** 文件中只負責**結構與內容**，
  **`.css`** 文件負責**樣式**，讓 HTML 更好維護與修改。

* 以 `key:value;` pair 的形式指定樣式，結尾最好都加上 `;` 。
  Example: `font-family:Arial;`

* **inline style**, 在 HTML 檔案中的 elements 可以直接使用屬性 (style) 來指定 css 樣式。 
例如： 
`<p style="font-family:Arial;"> </p>`

* **internal style**, 在 HTML 撰寫 css 程式碼於 metadata 區塊中以標籤 `<style>`包起來。
  ```
  <head>
      <style>
        css codes here
      </style>
  </head>
  ```

* **external style**, 把所有的樣式 css 程式碼放置在 `.css` 檔案中，從 HTML 中分離出去，推薦使用這種方式，才符合 css 設計的目的。
    * 連結 **`<link />`** HTML 與 CSS 檔案，
     標籤`<link />`是自身標籤
     屬性 (href) 連結 `.css` 檔案的位置
     屬性 (type) 連結的檔案類型，這邊固定為 `text/css`
     屬性 relation (rel) 檔案的關係，這邊固定為 `stylesheet`
     

     ```
     <link href="" type="text/css" rel="stylesheet"/>
     ```

* CSS **選擇器** selector，用來連結需要造型的位置。
    * 利用標籤名稱 `<tag_name>`
    
       範例：
    ```
    p {
        color:red;
    }
    ```

    * 利用類別名稱 屬性 (class)， `.` 是必須的。
    
       ```
       .className {
       }
       ``` 
    
    * 利用唯一名稱 屬性 (id), `#` 是必須的。
       ```
       #id {
       }
       ``` 

    * **選擇器的優先順序**，如果有相同的造型被指定不同的值，會依據優先順序去覆蓋，**id > class > tag** ，越嚴格的越優先。
    
    * 使用選擇器時，**先以優先序較弱的開始規劃**。
    
    * 選擇器**組合**使用，為了更有彈性的指定目標，可以組合標籤 (tag) 與物件 (class) 兩種選擇器，只有當**同時符合條件**的目標才會使用。
    
      ```
      elementName.className {
      }
      ``` 
      
   * **巢狀指定** nested element 利用**空白間隔**指定，巢狀結構內的標籤。
    example: 
    ```
    <ul class="main-list">
      <li></li>
    <ul>
    ```

     ```
     .main-list li {
     }
     ```

    * **最嚴格的指定** `!important`，最好**不要使用**，因為非常沒有彈性。
    example: `p { color: red !important;}`

   * **共用** css 程式碼以 `,` 隔開即可。
     example: `p, h1 {  }` 
     
   * 萬用指定 `*`

<br />

* 字型 (**font-family**), 預設 `Times New Roman`
* 字形大小 (**font-size**),  Example: `font-size: 18px;`
* 字形粗細 (**font-weight**), 選項: `thin`, `normal`, `bold`
* 文字對齊 (**text-align**), 選項: `left`, `center`, `right`
* 顏色 (**color**), 背景顏色(**background-color**)
* 透明度 (**opacity**), 值介於 0 ~ 1 之間, 0 完全透明, 1 不透明
* 背景圖片 (**background-image**), `background-image: url("");` 
* 預留份 (**margin**), 邊框 (**border**), 填充 (**padding**) 
![圖片來源 codecademy](https://s3.amazonaws.com/codecademy-content/courses/freelance-1/unit-4/diagram-boxmodel.svg "圖片來源 codecademy")

* 寬度 (**width**), 高度 (**height**) 可以指定為固定的pixel (px)。 
* 邊框設定 (**border**),   `border: width style color ;`
  可以設定寬度, 形式, 顏色。
  寬度選項可以為指定 `px` 或者 `thin`, (default)`medium`, `thick`
* 邊框四個角圓弧設定 (**border-radius**), 選項為 百分比 (%) 或者pixel (px)

* 邊框與內容物之間的填充區塊 (**padding**), 值為 pixel (px),
  可以分別指定四個方向:
  (**padding-top**), (**padding-right**), (**padding-down**), (**padding-left**)。
  或者寫為同一個指令
  `padding: 1px 2px 3px 4px`, 從上方開始順時鐘, 上, 右, 下, 左。
  `padding: 1px 2px`, 上下, 左右 分成兩組。
  
* 邊框外的預留區 (**margin**) 指令方法同 padding。

<br />
**tutorial undone**


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 學習主軸 2. [w3school - CSS](https://www.w3schools.com/css/default.asp) undone

**do all exercises**

* CSS **註解** 同 C 語言, `//` , `/*   */`
* **Colors**
* **Backgrounds**
  `background-color`, 
  `background-image: url("")`,
  `background-repeat: repeat-x, repeat-y, no-repeat`
  `background-position: right top`
  `background-attachment: fixed`
  簡化
  `background:#fff url("") no-repeat right top`
  
* **Borders**
  `border:size style color`
  `border-radius: % or px`

* **Margins**
  `margin: auto` # 置中
  Margin Collapse # 只有在**上下**才存在的問題，上下兩個的 Margin 取**最大值顯示**。
  `margin: inherit` # 繼承上層的設定值
  
* **Padding** 
  Padding # 會額外增加於 width 之外。
  `box-sizing: border-box` # 或者使用這個指令，則由 width 控制寬度，多的內容會自動換行。
  
* **Height, Width**
  pixel `px` 控制
  百分比 `%` 控制 # 畫面寬度或高度的百分比

  `max-width: ` # 與 `width` 不同，`max-width` 在顯示長度小於設定時，會自動縮小 `width` 。
  
* **Box Model**
   margin, border, padding, content.

* **Outline**
  類似於 border 設至於 border 之外，作為輪廓或高亮使用
 
* **Text**
  `text-align: center, left, right, justify` # justify 每行字都拉到同寬，報紙或雜誌的排版。
  `text-decoration: none, overline, line-through, underline`
  `text-transform: uppercase, lowercase, capitalize`
  `text-indent: px` # 段落首行內縮 
  `letter-spacing: `
  `line-height: `
  `word-spacing: `
  `text-shadow: ` 

* **Font**
  `font-family: ` # 字型
  `font-size: px, em, %` # 大小
  `font-style: normal, italic` # 斜體與否
  `font-weight: normal, bold` # 粗體與否
  `font-variant: small-caps` # 字型變化

* **Icons**
  有很多內建的小圖示可以使用，搜尋 CSS Icons
  
* **link** 裝飾 超連結
  `color`, `background-color`, `padding`, `text-decoration`
  `以連結的狀態區分`
  `a:link` # 一般狀態, **未拜訪過的**
  `a:visited` # **拜訪過的**
  `a:active` # 滑鼠**點擊**超連結時
  `a:hover` # 滑鼠在超連結**上**時

* **list** ul, ol, li
  `list-style-type: circle, square, upper-roman, lower-alpha`
  `list-style-image: url(" ")` # 利用圖片作為標籤
  `list-style-position: inside, outside` # 顯示位置
  `可以調整 padding, margin, list-style-type`
  `list-style: image type position ` # 簡寫
  
* **table** table, th, tr, td
  `border:` # 設定邊框
  `border-collapse: collapse` # 自動結合邊界
  `width, height` # 設定寬高
  `text-align, vertical-align` # 設定對齊
  `padding:` # 設定填充區
  `tr:hover `  # 指定設定於被**滑鼠移動到的列** `:hover`
  `tr:nth-child(even, odd)` # 藉由 `:nth-child()` 指定基數或偶數列的裝飾
  
  當欄位過長於顯示寬度時，**讓表格擁有拖拉列**。

  ```
  <div style="overflow-x: auto;">
     <table>
     </table>
  </div>
  ```

<br / >

* **Display & Visibility**
  `display: none` # Remove 直接移除，導致相鄰的物件移位。
  `display: block` # 顯示, 把不換行的物件變成換行。
  `display: inline`  # 把換行的物件變成不換行。
   `display: inline-block;` # 變成不換行並且顯示空間。
  `visibility: hidden` # 隱藏，但是位置還在。
  
* **position**
  先指定類型後才指定位置
  `position: static;` # default
  `position: relative;` # 從 default 的位置去移動
  `position: fixed;` # 固定於畫面的指定位置，就算捲動畫面也不會移動。
  `position: sticky;` # 一開始類似 `relative` 指定位置，捲動畫面後如同 `fixed` 被黏住畫面上。
  `position: absolute;`# 絕對於上層結構的位置。即把上層結構當作畫面去移動。
  
  移動明確位置
  `top`, `bottom`, `left`, `right` px;

  `z-index: -1;` # 移動到後方不覆蓋。
  
* **Overflow**
  捲軸設定
  `overflow: visible` # default
  `overflow: hidden` # 看不到也沒有捲軸
  `overflow: scroll` # 固定加上捲軸
  `overflow: auto` # 只有在需要的時候，才會增加捲軸。
  `overflow-x:` # 只增加水平捲軸
  `overflow-y:` # 只增加垂直捲軸
  
* **Float & Clear**
  物件在容器中的位置設定
  `float: left`
  `float: right`
  `float: none` # 預設
  `float: inherit` 
  設置空間不允許的 float 位置
  `clear: none` # 預設
  `clear: left`
  `clear: right`
  `clear: both`
  `clear: inherit`

* 藉由 
   `float`, 
   `padding`, 
   `margin`, 
   `position`, 
   `text-align`, 
   `line-height`
  排版物件想要的位置
  
* Selector Combinators
  `空白` # 所有的後代 ex: `div p`
  `>` # 連接的下一層 ex: `div > p`
  `+` # 馬上相連的一個 ex: `div + p`
  `~` # 之後所有的 ex: `div ~ p`

* Pseudo-classes 
  選擇器加上特殊的狀態 `selector:pseudo-classes {}`
  例如 `:hover`
  可以藉由 `:hover` 與 `display:none` 製作出移動顯示的功能。

* Pseudo-elements
  用來指定選擇器中特定的**部份**， `selector::pseudo-elements {}` 
  使用 `::` 作為與 Pseudo-classes 的區分。
  `::first-line` # 第一行
  `::first-letter` # 第一個字母
  `::selection` # 被選取時，可單獨使用
  `::before { content: }` # 物件之後
  `::after { content: }` # 物件之前
  
* opacity
  不透明度設定 `1.0 ~ 0.0`, 1 不透明, 0 完全透明
  
* navigation bar
  藉由 超連結的 list 裝飾而成
  

# 學習主軸 3. 書: CSS 重構   

Book: CSS 重構, Steve Lindstrom

## 第一章 重構與架構

好架構：

* 可預期性
* 重用性
* 擴充性
* 維護性

最佳實務: 新技術帶來的新方法取代舊方法。

重構的時機與重構的內容

進行的流程：

1. 撰寫程式碼
2. 撰寫測試
3. 重構
4. 執行測試

## 第二章 瞭解串接

串接 (cascade)

特定度
選擇器的優先順序

## 第三章 編寫較佳的 CSS

## 第四章 為不同類型的樣式分類

## 第五章 測試

## 第六章 樣式碼置放與重構策略


## NOTE

* selector
* box model

# 真實文本, mud your hand

使用 GitHub Page 練習前端技術並且保留作品。
HTML, CSS, Javascript

* [Bootstrap framework GitHub repository](https://github.com/twbs/bootstrap)

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 其他資源

https://www.codecademy.com/catalog/language/html-css
codecademy

https://www.w3schools.com/
w3schools

http://www.tutorialspoint.com/tutorialslibrary.htm
tutorials

https://noootown.wordpress.com/category/%E5%89%8D%E7%AB%AF%E9%80%A3%E8%BC%89/
前端入門 概念說明

<a href="https://www.edx.org/course/css-basics-w3cx-css-0x-0?utm_source=sailthru&utm_medium=email&utm_campaign=newsletter_student_actives_20171128_givingtuesday" target="_blank" > edX 免費課程 CSS basics </a>

https://www.edx.org/school/w3cx
edX 課程由 w3c 提供 包含前端語言入門 

https://developer.mozilla.org/zh-TW/
網頁入門教學 **待閱讀**

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

# note

What made this design stand out to you?
What do you like best about this design?
What is one thing you don't like about this design?
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTU4NDc5NDQxM119
-->