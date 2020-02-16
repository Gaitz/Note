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

#### 綁定事件的方法
  * 直接加在 HTML 元素上, inline 在 HTML 標籤上。 `<element onevent='callback_function' ></element>`
  * DOM 元素指定事件, 每個事件只能有一個對應函式。 `element.onevent = callback_function`
  * 事件監聽器 (event listener), 每個事件可以增加多個函式。 `element.addEventListener('event', callback_function)`

####  事件氣泡與事件捕捉
  * Event Bubbling, 由內而外, 預設行為
  * Event Capturing, 由外而內, `addEventListener()` 可以選用

#### Event 物件
  * 作為 callback_function 傳入的第一個參數。
  * `target`, `type`, `cancelable`
  * `preventDefault()`, `stopPropagation()`

#### 不同類型的事件
  * W3C DOM 事件
  * HTML5 事件
  * BOM 事件, 瀏覽器物件模型 (BOM), 各家瀏覽器各自的事件。

#### 使用者介面事件 UI 事件
  * `load`
  * `unload`
  * `error`
  * `resize`
  * `scroll`, 觸發次數高, 需注意效能問題。

#### Focus 與 Blur 事件
  * 使用者互動時會先聚焦元件
  * `focus`
  * `blur`
  * `focusin`
  * `focusout`

#### MOUSE 事件
  * `click`
  * `dblclick`
  * `mousdown`
  * `mouseup` 
  * `mouseover`
  * `mouseout`
  * `mousemove`

#### 事件發生位置
  * `event.screenX`, `event.screenY`, window 上的位置
  * `event.pageX`, `event.pageY`, 網頁頁面上的位置
  * `event.clientX`, `event.clientY`, 瀏覽器可視範圍中的位置

#### KEYBOARD 事件
  * `input`, `<input>`, `<textarea>` 被輸入時
  * `keydown`, 持續按著也會連續觸發
  * `keypress`,
  * `keyup`,
  * 觸發順序 keydown -> kyepress -> keyup
  * event 取得 keycode, `event.keycode`, 可以透過 `String.fromCharCode()` 取得對應的字元

#### FORM 事件
  * `submit`
  * `change`
  * `input`

#### MUTATION 事件
  * DOM 結構變動時產生的事件
  * `DOMNodeInserted`
  * `DOMNodeRemoved`
  * `DOMSubtreeModified`
  * `DOMNodeInsertedIntoDocument`
  * `DOMNodeRemovedFromDocument`

#### HTML5 事件
  * `DOMContentLoaded`, DOM 樹被建立時觸發的事件
  * `hashchange`, url 改變時觸發
  * `beforeunload`, unload 之前觸發。


------------------------------


### 第七章 - JQuery
  * jQuery library 提供跨瀏覽器的函式，不用額外處理各種瀏覽器版本的相容性。
  * 通過 jQuery 選擇器 (selector)，找到指定的元素並且包成 jQuery 物件的形式，在通過 jQuery 物件的方法操作。

#### ready
  * `$(document).ready( function() {} );`
  * `$( function() {} );`

#### 取得內容
  * `html()`, 子代 html
  * `text()`, 文字內容
  * `val()`, 表單

#### 變更
  * `html()`
  * `text()`
  * `replaceWith()`
  * `remove()`

#### 新增
  * `before()`
  * `prepend()`
  * `append()`
  * `after()`

#### 屬性, 類別, CSS style
  * `attr()`
  * `removeAttr()`
  * `addClass()`
  * `removeClass()`
  * `css()`

#### 集合操作
  * `each()`, 配合 `this`, `$(this)`

#### 事件
  * `on(events[, selector][, data], function (e))`

#### 特效
  * 使用 CSS 效能更好
  * `show()`
  * `hide()`
  * `toggle()`
  * `fadeIn()`
  * `fadeOut()`
  * `fadeTo`
  * `fadeToggle()`
  * `slideUp()`
  * `slideDown()`
  * `slideToggle`
  * `delay()`
  * `stop()` 
  * `animate()`, 類似 CSS animation

#### 走訪 DOM (traveling)
  * `find()`, 找子代
  * `closest()`, 找最近父代
  * `parent()`
  * `parents()`
  * `children()`
  * `siblings()`
  * `next()`
  * `nextAll()`
  * `prev()`
  * `prevAll()`

#### 操作 jQuery 集合
  * `add()`, 增加 jQuery 元件
  * `filter()`
  * `find()`
  * `not()`
  * `has()`
  * `contains()`
  * `is()`, 回傳 boolean
  * 藉由 index
    * `eq()`
    * `lt()`
    * `gt()`
  * `remove()`
  * `detach()`, 類似剪下
  * `empty()`
  * `unwrap()`
  * `clone()`

#### 元件大小, 位置
  * `height()`
  * `width()`
  * `innerHeight()`
  * `innerWidth()`
  * `outerHeight()`
  * `outerWidth()`
  * `scrollLeft()`
  * `scrollTop()`
  * `offset()`
  * `position()`

#### `<script>` 放置的位置
  * 瀏覽器遇到 script 標籤會先讀取並且執行，會影響其他工作。
  * 放置於 `</body>` 前是最適當的位置。

#### 其他 JavaScript 函式庫
  * DOM 與事件
    * Zepto.js, YUI, Dojo.js, MooTools.js
  * 繪圖與圖表
    * jQuery UI, jQuery Mobile, Twitter Bootstrap, YUI
  * 網頁應用程式
    * Chart.js, D3.js, Processing.js, Raphael.js
  * 使用者介面
    * Mustache.js, Handlebars.js, jQuery Mobile
  * 樣板
    * Angular.js, Backbone.js, Ember.js
  * 相容性
    * Modernizr.js, YepNope.js, Require.js


------------------------------


### 第八章 - AJAX 與 JSON