## JavaScript & JQuery 網站互動程式 進化之道
### BOOK resource, JavaScript

------------------

第一章 - 程式設計 ABC

第二章 - JAVASCRIPT 基本語法

第三章 - 函式、方法與物件

第四章 - 決策與迴圈

第五章 - 文件物件模型

第六章 - 事件

第七章 - JQuery

第八章 - AJAX 與 JSON

第九章 - APIS 應用程式介面

第十章 - 錯誤處理與除錯

第十一章 - 內容控制面板

第十二章 - 過濾篩選、搜尋與排序

第十三章 - 表單強化與驗證

------------------


### 第一章 - 程式設計 ABC
  * 瀏覽器物件 Window, Document


------------------------------


### 第二章 - JAVASCRIPT 基本語法


------------------------------


### 第三章 - 函式、方法與物件

#### 函式宣告
  * `function functionName () {}`, 命名宣告
  * `var functionName = function () {}`, 匿名函式
  * `( function () { }() );`, 立即執行函式 IIFE

#### 瀏覽器 WINDOW 物件
  * window.document, 目前頁面
  * window.history, 瀏覽紀錄中的頁面
  * window.location, 當前頁面 URL
  * window.navigator, 瀏覽器資訊
  * window.screen, 裝置資訊

#### 瀏覽器 Document 物件
  * DOM 的頂層物件


------------------------------


### 第四章 - 決策與迴圈


------------------------------


### 第五章 - 文件物件模型 DOM
  * 與 HTML, JavaScript 標準無關的瀏覽器標準

#### 取得元件
  * 有執行速度上的差別
  * `getElementById()`
  * `querySelector()`
  * `getElementsByClassName()`
  * `getElementsByTagName()`
  * `querySelectorAll()`

#### 走訪
  * 因瀏覽器實作可能會有差別
  * `parentNode`
  * `previousSibling`, `nextSibling`
  * `firstChild`, `lastChild`

#### 操作
  * `nodeValue`, 文字節點
  * `innerHTML`, 有安全性問題
  * `textContent`
  * `createElement()`
  * `createTextNode()`
  * `appendChild()`
  * `removeChild()`
  * `insertBefore()`
  * `hasAttribute()`
  * `getAttribute()`
  * `setAttribute()`
  * `removeAttribute()`

#### XSS 跨網站指令碼攻擊
  * 小心任何不可信任的資料，包含 API 與任何使用者輸入的內容。


------------------------------


### 第六章 - 事件