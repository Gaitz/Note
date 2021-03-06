Detail Markdown Language 
==

Purpose: 可以撰寫良好的 blog 文件
--

Markdown Language 在 GitHub 時常使用！


[TOC]

* * *

Questions:
--

* 文章中的空白與縮排 如何達成?  
	ANS: markdown language 不能隨意的使用空白與縮排，因為 markdown language 提供的是標記，	只能善用存在的語法。

* 文字是否能有顏色?  
	ANS: 不行，也許鑲嵌的 html 可以達成 ?

* * *

學習主軸 1. 使用的資源為 [Markdown 語法說明中文版][source_1]
==
[source_1]: http://markdown.tw/?utm_source=tonghaohui

行內HTML
--
Markdown 文件中可以包含 html 語法，細節請查詢[文件][source_1]。

文內超連結語法
--

Markdown Language 中可以加入 html 語法，因此可以使用以下語法達成文內超連結。 
文內跳段超連結語法，以本文目錄為例語法如下：

	**目錄**
	學習主幹 1. [Markdown 語法說明中文版](#source1)
	
	如同超連結語法一般: [words](#Title Name) 
	連結到文中的標題 (Title)

	跳躍到的位置可使用 html 標題語法:
	<h1 id="source1"></h1>
	
	或者 Markdown Language 語法類型標題，例如：
	source1
	--

從主幹 2 中學到[ Markdown Language 原生用法](#文內超連結2)

引言
--

	> 引言測試
	> 1. hi
	> 2. list
	>> double 
	>>> triple  

清單與序列
--
無序清單

+ 使用 +
- 使用 -
* 使用 * 以上皆可代表無序清單

有序清單

1. first
2. second
3. third

程式碼
--
This is a code block 使用一個**空白斷行**與程式碼前 **1 個 tab** 可做出程式碼區塊

	for(int i = 0; i < 10; i++)
    System.out.println("hello markdown language");

function inline use **\`** space for code **\` **
Use the ` printf() `function.

分隔線
--

分隔線測試 
分隔線以同一行存在三個 - 或 _ 或 * 

- - -
_ _ _
* * *

超連結
---

inline hyperlink with title :
	
	This is [an example](http://example.com/ "Title") 

hyperlink 把分離連結

	文章中的網址 [website1][1] [website2][]  使用分離連結讓 markdown language 有更佳的閱讀性。

	[1]: http://website1.com/ "website1.com"
	[website2]: http://website2.com/
	"website2.com"

插入圖片
--
插入圖片的語法與 hyperlink 格式相同，只需在開頭加上 ! 作為區別。

	![圖片1][]:
	[圖片1]: link


跳脫字元
--
跳脫字元 \

強制空行
--
強制空行使用 html 語法 `<br>`

標題
--

標題可使用

	== 主標題
	-- 次標題
	#
	##
	### 井字類型標題類似於 html <h3> 可依據#數量影響大小
	
[使用 html 語法達成標題與文內連結效果:](#文內超連結語法)
	
	<h3 id=""> title </h> // h1 h2 h3 ... 可改變標題大小

強調
--

強調語法:

	*words*
	_words_
	**words** 
	__words__

效果:
*words*
_words_
**words** 
__words__

* * *

學習主軸 2. 使用的資源為 StackEdit Hello! 文件
==

文內超連結2
--
文內超連結的 Markdown Language 語法:

	連結位置語法 (from)
	[hyperlink name](#title name) 
	
	Markdown Language 的標題會自動對應成文內超連結 (to)
	title name 
	--
	### title name // 井字類型標題也適用，可以更好的控制標題大小，可完全取代 html 標題語法。

##擴充的 Markdown Language

<br>
### 表格
```
| Item     | Value | Qty   | /* 表格格式 */
| :------- | ----: | :---: | /* 可利用:調整間距，可有可無。 */
| Computer | $1600 |  5    | /* 資料 */
```

<br>
### 註腳
 
 自動生成註腳語法:
 在需要使用註腳的地方使用類似於超連結語法的`[^words]`，
 註腳內容則是分離語法`[^words]: Footnotes content`。

 語法如下: 

	You can create footnotes like this[^footnote].

	  [^footnote]: Here is the *text* of the **footnote**.

<br>
### 自動生成目錄

 對應所有文內的標題語法生成文內目錄。
 語法為 `[TOC]` 。

<br>
### 數學記號

網站需要有支援 MathJax[^支援1] 。  
可以使用 **Latex** 語法，產生數學式。
語法如下: 

		$$
	\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.
	$$

[^支援1]: 網站支援 MathJax 所需語法請查詢 StackEdit Hello! 文件。

<br>
### Definition Lists

	Term 1
	:   Definition A

Term 1
:   Definition A

<br>
### 語法高亮

此功能需要有支援 Highlight.js ，例如 **github**
Code block 以 \` \` \` 包覆。

	```
	// Foo
	var bar = 0;
	```
除了 Highlight.js 之外還可以使用 **Prettify**[^支援2]

[^支援2]: Code highlighting 相關說明請查詢 StackEdit Hello! 文件。

<br>
### UML 圖 和流程圖

 語法細節請點超連結文件:

 [UML 語法][7]
 [流程圖語法][8]
 [7]: http://bramp.github.io/js-sequence-diagrams/
 [8]: http://adrai.github.io/flowchart.js/

<br>
UML圖範例:

* Code:

	\` \` \`sequence
	Alice->Bob: Hello Bob, how are you?
	Note right of Bob: Bob thinks
	Bob-->Alice: I am good thanks!
	\` \` \`


* Result:

```sequence
Alice->Bob: Hello Bob, how are you?
Note right of Bob: Bob thinks
Bob-->Alice: I am good thanks!
```

流程圖範例:

* Code:

	\` \` \`flow
	st=>start: Start
	e=>end
	op=>operation: My Operation
	cond=>condition: Yes or No?
	
	st->op->cond
	cond(yes)->e
	cond(no)->op
	\` \` \`

* Result:

```flow
st=>start: Start
e=>end
op=>operation: My Operation
cond=>condition: Yes or No?

st->op->cond
cond(yes)->e
cond(no)->op
```

* * *
學習主軸 3. [Github Guides: *Mastering Markdown*][source_3]
==
[source_3]: https://guides.github.com/features/mastering-markdown/ "Mastering Markdown"

## Extras

### @mentions 
通知特定人士或團體 @user_name

###	`- [x]` , `- [ ]` # checkbox, task lists

```
To-do lists
- [x] this one is done
- [ ] this is not
```

### emoji # 表情符號
[emoji cheat sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet/)

###  `~~line~ ~` # 刪除線 

###  issues reference 
`username/repository#issue_number` # 	issues reference

### github 內超連結！# 同個 repository 不同的資料夾亦可利用路徑連結。

``` 
Examples:
	連結圖片：![image](../images/picture1.png)
	連結文件：[README](../README.md)
```

### 內縮標籤 <details> <summary>

HTML5 的新標籤在 GitHub like Markdown 可以使用。

```
Examples:
   <details>
    <summary> title </summary>
    details here
   </details>
```

* * *
#Case Study :  




<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEwOTY1NzcwNzddfQ==
-->