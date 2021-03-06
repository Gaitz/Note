
學習 Python 
==

PURPOSE: 需要一個熟練且深度了解的程式語言，做為日常使用能快速開發
--

## NEXT: 真實文本, 標準函式庫略讀

[TOC]
   
* * *

# 可以把玩的檢查清單

* 註解 #, """
* 輸出 print()
* 輸入 raw_input()
* 檔案輸入輸出
* 各式迴圈與 in 算子
* 物件導向 
* 自訂函數 def
* 資料結構
 List
 Tuple, Sequence
 Set
 Dictionary
* 多重賦值
* Module 與 script
* 例外處理
* 標準函式庫
* 函式庫引入 pip, pypi 
 


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

學習主軸 1. [Learn Python the Hard Way (免費版已關閉) Python2.7][mainSource1] 
==
[mainSource1]: https://learnpythonthehardway.org/book/ "Learn Python the Hard Way"


進度紀錄
==
Table of Contents                          | Read | Study Drills Undone
:------------------------------------------|:----:|:------------:
Preface                                    | Done | null
Introduction: The Hard Way Is Easier       | Done | null
Exercise 0: The Setup                      | Done | null
Exercise 1: A Good First Program           | Done | Done
Exercise 2: Comments And Pound Characters  | Done | Done
Exercise 3: Numbers And Math               | Done | Done
Exercise 4: Variables And Names            | Done | Done
Exercise 5: More Variables And Printing    | Done | Done
Exercise 6: Strings And Text               | Done | Done
Exercise 7: More Printing                  | Done | Done
Exercise 8: Printing, Printing             | Done | Done
Exercise 9: Printing, Printing, Printing   | Done | Done
Exercise 10: What Was That?                | Done | Done
Exercise 11: Asking Questions              | Done | Done
Exercise 12: Prompting People                 | Done | Done
Exercise 13: Parameters, Unpacking, Variables | Done | Done
Exercise 14: Prompting And Passing         | Done | Done
Exercise 15: Reading Files                 | Done | Done
Exercise 16: Reading And Writing Files     | Done | Done
Exercise 17: More Files                    | Done | Done
Exercise 18: Names, Variables, Code, Functions | Done | Done
Exercise 19: Functions And Variables       | Done | Done
Exercise 20: Functions And Files           | Done | Done
Exercise 21: Functions Can Return Something    | Done | Done
Exercise 22: What Do You Know So Far?      | Done | Done
Exercise 23: Read Some Code                | Done | 1
Exercise 24: More Practice                 | Done | Done
Exercise 25: Even More Practice            | Done | Done
Exercise 26: Congratulations, Take A Test! | Done | Done
Exercise 27: Memorizing Logic              | Done | Done
Exercise 28: Boolean Practice              | Done | Done
Exercise 29: What If                       | Done | Done
Exercise 30: Else And If                   | Done | Done
Exercise 31: Making Decisions              | Done | Done
Exercise 32: Loops And Lists               | Done | Done
Exercise 33: While Loops                   | Done | Done
Exercise 34: Accessing Elements Of Lists   | Done | Done
Exercise 35: Branches and Functions        | Done | Done
Exercise 36: Designing and Debugging       | Done | Done
Exercise 37: Symbol Review                 | Done | n
Exercise 38: Doing Things To Lists         | Done | Done
Exercise 39: Dictionaries, Oh Lovely Dictionaries | Done | Done
Exercise 40: Modules, Classes, And Objects | Done | Done
Exercise 41: Learning To Speak Object Oriented    | Done | n
Exercise 42: Is-A, Has-A, Objects, and Classes    | Done | Done
Exercise 43: Gothons From Planet Percal #25       | Done | n
Exercise 44: Inheritance Vs. Composition   | Done | 1, n
Exercise 45: You Make A Game               | Done | 1, n
Exercise 46: A Project Skeleton            |  |
Exercise 47: Automated Testing             |  |
Exercise 48: Advanced User Input           |  |
Exercise 49: Making Sentences              |  |
Exercise 50: Your First Website            |  |
Exercise 51: Getting Input From A Browser  |  |
Exercise 52: The Start Of Your Web Game    |  |
Advice From An Old Programmer              |  |
Next Steps                                 |  |
Appendix A: Command Line Crash Course      |  |



學習技巧
--
* **每天**練習
* 如果遇到困難或是卡關，仍就**繼續嘗試**最後就會變簡單。
* **專於於享受學習的過程**
* 把**問題拆解**成**較小的問題**和課程，並且**每天**都**嘗試練習**，利用這樣的步驟幾乎可以做到任何事情。
* **專注於緩慢的進步**和**享受學習的過程**就能從中得到好處。
* 最重要的是**保持進程**，**太困難的問題，可以先略過標注之後再回來**。
* Never give up.

[Reference: A Note on Practice and Persistence](https://learnpythonthehardway.org/book/intro.html "A Note on Practice and Persistence" )


記憶技巧
--
* Your brain will retain whatever you studied in the first 15 or 30 minutes anyway.
* flash cards
* write out from memory each night if stuck then glance quickly to refresh it.


程式碼閱讀技巧
--
* comment every line of code
* read it backward
* read it loud


物件導向開發流程
--
### Top Down

### Bottom Up


Python 練習環境
--
使用 Atom 為文字編輯器，Terminal 執行，使用 Python 2.X 而非 3


註解與文件
--
###註解
單行註解： **＃**

###說明文件 pydoc

* 在 **terminal 下使用 pydoc** + 要查詢的指令

* 自訂函式中的文件註解 ( documentation comments )
  在函式中使用 """ 多行字串語法 """ 會自動生成文件

File: fileName.py

		def functionName():
			""" here is the documentation comments of this function """
			functionBody...
	
在 python 互動式界面中可以使用 ` help(fileName) `	查詢整個檔案的說明文件或者
`help(fileName.functionName)` 查詢檔案中的單個函式。


Print
--
###一般

	print "Strings"

###使用 format

	print "%d %r %s" % ( variable1, variable2, variable3 )
 
	%d -> 顯示十進位數字
	%r -> 顯示變數原始內容 ( raw ), 多用於 debug 時
	%s -> 顯示字串 ( string )

###使用算子

	#使用乘號 *
	print " hi " * 10

	#使用加號連接變數
	print var1 + var2 + var3
	 
	#使用逗號連結兩個 print 指令避免換行並且兩個字串中自動加上一個空白 
	print "Hello",
	print "World!"	
	結果如下：
	Hello World!

###包含 format 的字串變數

	把包含 format 的字串放入變數中，在 print 時才指定。
	formatter = "%r %r %r"
	print formatter % ( 1, 2, 3 )

###print 多行字串

	print """
	line1 %r
	line2 %r
	line3
	""" % ( v1, v2 )

	多行字串也可以配合 format 使用

###使用 `,` 輸出變數 

	print "Hello ", variable, " World!"   # 使用 , 


跳脫字元
--
	\n #換行
	\b #向後
	\f #向前
	\\ #\
	\' #'
	\t #1個tab
	...


輸入
--
###不含參數

	raw_input() #從鍵盤輸入,內容當成字串
	input() #自動轉換成 python 資料型態，可能有安全性問題，盡量使用 raw_input()。

###含參數 ( prompt )
 
	raw_input("the prompt string")   #參數為顯示在輸入前的字串 ( prompt )


Sys 函式庫 
--
###argv

外部傳入參數 argument variable

	from sys import argv # import argv
	
	script, first, second, third = argv  
	# 指定順序與名稱，第一個必為檔名即 script

###exit

跳出程式 

	from sys import exit

	exit(0)


讀寫檔案
--
###開檔案
	
	開啟檔案並且回傳一個 file 物件
	txtFile = open(filename, mode)	 # both filename and mode are string, 
	
	txtFile = open(filename) # 不加入 mode 則預設是 read only
	txtFile = open(filename, 'w') # 從頭寫入模式 (write)
	txtFile = open(filename, 'a') # 附加寫入模式 (append)
	txtFile = open(filename, 'r+') # 同時包含 read and write
	
	**write mode**：
	如果有相同名稱的檔案會被覆蓋
	=> 先**清除檔案內容**在從頭開始寫入。

###讀檔案

	txtFile.read() # 讀取 file 物件中所有的內容
	txtFile.readline() # 一次讀取一行

###寫入, 清空與關閉檔案

	寫入內容
	txtFile.write(content) 

	清空檔案內容
	txtFile.truncate() 

	關閉檔案且儲存 
	textFile.close() 
	
###其他檔案操作

	想知道相同名稱的檔案是否存在則使用：
	from os.path import exists
	exists( filename ) # return boolean

	移動到檔案起始處：
	txtFile.seek(0)


自定義函式
--
	def functionName(arg1, arg2):
		function_body
		return      # not necessary 
	
	Python 的縮排也是語法的一部分，function body 必有一個 tab 的空間。
	
另外一種的 arguments 的寫法，類似於外部讀取：
	
	def functionName(*args):
		arg1, arg2 = args

函式回傳值，可有可無，並且**可以回傳一個以上**。例如：

	def example():	
		variable1 = doSomethings(1)
		varibale2 = doSomethings(2)
		return variable1, variable2

	get1, get2 = example()

###函數呼叫 
python 操作函數的方式

**Object.functionName( argument )**
=> **functionName( Object, argument )**


函式庫、模組
--

	import fileName
	
	or
	
	from fileName import *
	
 像 C 一般使用函式庫，每個 .py 都能成為函式庫，
 檔案中的函式 ( def ) 與變數 ( variable ) 皆可被呼叫。
 
* import fileName
	使用函數時需包含檔名，類似名稱空間的方式使用。
	 
		fileName.function()
		fileName.variable

* from fileName import function
	直接引入函數，因此不需要使用時不需包含檔名。
	`function()`


算子
--
###邏輯算子：
	算子     | 意義
	--------|----
	`==`    | 等於 
	`!= `   | 不等於 
	`not `  | 非
	`<= `   | 小於等於
	`>= `   | 大於等於
	`<`     | 小於
	`>`     | 大於
	`and`   | 和 
	`or`    | 或
	`True`  | 真
	`False` | 假
	`1`     | == True
	`0`     | == False
	`None`  | == False
	
**數字除了 0, 1 之外並無真假值**

**使用 and, or 算子於非 True, False 時回傳並不一定為 True, False**	
例如： 
"test" `and` "test" **回傳**  "test", 
0 `and` True **回傳** 0
應**避免使用**或者需先測試過避免非預期的結果。


### in 算子：
	1. 作為判斷元素是否在變數中，回傳 True/False
		element `in` variable
		element `not in` variable
	
	2. 作為 `for` 迴圈中的迭代
	
			for element in variable:
				print element 

判斷
--
###if
```
if condition:
	execution

elif condition:
	execution

else:
	execution
```
**Rules**

1. 一定要有 **else**
2. 利用 else 接住一些異常，印出警告。
3. 巢狀 if 最多**2**層
4. 簡化判斷式，為了可閱讀性
5. 每個 elif 都像是文章的段落，所以可以在前後空行，有較好的閱讀性。


迴圈
--
###for-loop

	for i in range(0,3):
		repeat 3 times.

**記得 " ： " python 中的 code block 之前會有 : **


###while-loop
	while condition:
		execution when condition is true



資料結構
--
###list

可作為 array, stack, queue 使用

* 初始化
		
		list = []
		
		listExmaple1 = [1, 2, 3]
		listExample2 = ['a', 'b', 'c']
		listExample3 = [1, 'abc', 3] 
	 
	 python list 可包含**不同資料型態**的資料。

* 加入資料

		list.append()
		
		接合 (concatenation):
		list + [30, 'a', 'abc'] 
		
		
* 讀取資料

		list[index]
		list[index : index]
		
* Functions
	1. len()   # 長度
	
	2. pop([index])  # 移除並且回傳
		default 是最後一個元素, [ ] 在 python 文件中表示 optional 。

###dictionary (dict)

一種 key, value pair

* 初始化

		dictionary= {}

		states = {
		    'Oregon': 'OR',
		    'Florida': 'FL',
		    'California': 'CA,
		    'New York': 'NY',
		    'Michigan': 'MI'
		}
	用 **:** 分開 key 與 value 
	用 **,** 分開數個 pair


* 加入或改寫資料

		dictionary[key] = value
		
	如果 key not in dictionary 則加入, 反之改寫資料。

* 讀取資料 

		dictionary[key]
		
		dictionary.get(key) # safer
		
* 移除資料

		del dictionary[key]
		
* functions
	1. keys() # 回傳所有的 key 				
	
	2. items() # 回傳所有的 key, value pairs
		可使用於 **for** loop 例如：

			for key, value in dictionary.items():
			    print "key-value pair ( %r, %r )" % ( key, value )
	
	3. get( key ) # 比較安全的讀取資料方式
		如果 key 不存在，則回傳 None ，等同於 False
		use case:
			
			state = states.get('Texas') # return None if 'Texas' is not a key.
			
			if not state: # (not None) == True
			    print "Sorry, no Texas."

 
物件導向
--
### Class

new-style class 可以使用更多能力，例如 super()

	class ClassName(object):
		
		def __init__(self, arguments):
			self.variableName = arguments
						
		def functions(self, arguments):
		
  `object` 物件的 class ，等同於 Java 中所有的 class 都繼承 Object，
  但是 python 的 object 類別是小寫，是 python 的歷史錯誤。
  
  `def __init__(self):` 即建構子 ( constructor ) 
  
  `self` 即 this pointer

* 繼承 

		class ClassName( ParentClass ):
			
			def __init__(self):
				# 使用 ParentClass 中的  __init__ 方法
				super( ClassName, Self ).__init__( arguments )
	
### Object

* 生成物件
	
		objectName = ClassName()


* * *

學習主軸 2. [Python3.5 官方教學文件][mainSource2]
==
[mainSource2]: https://docs.python.org.tw/3/tutorial/index.html 

進度紀錄
==
Table of Contents | Read
:-----------------|:----
count             | 124
1 淺嘗滋味 | done
2 使用 Python 直譯器 | done
2.1. 啟動直譯器 | done
2.1.1. 傳遞引數 | done
2.1.2. 互動模式 | done 
2.2. 直譯器與它的環境 | done 
2.2.1. 原始碼的字元編碼 (encoding) | done 7
3 一個非正式的 Python 簡介 | done
3.1. 把 Python 當作計算機使用 | done
3.1.1. 數字 (Number) | done
3.1.2. 字串 (String) | done 
3.1.3. List（串列） | done 12
3.2. 初探程式設計的前幾步 | done
4 深入了解流程控制 | done
4.1. if 陳述式 | done
4.2. for 陳述式 | done
4.3. range() 函式 | done
4.4. break 和 continue 陳述、迴圈內 else 段落 | done
4.5. pass 陳述式 | done 19
4.6. 定義函式 (function) | done
4.7. More on Defining Functions | done
4.7.1. Default Argument Values | done
4.7.2. Keyword Arguments | done
4.7.3. Arbitrary Argument Lists | done
4.7.4. Unpacking Argument Lists | done
4.7.5. Lambda Expressions | done
4.7.6. 說明文件字串 | done
4.7.7. Function Annotations | done 28
4.8. Intermezzo: Coding Style | done
5 資料結構 | done
5.1. 進一步了解 List（串列） | done
5.1.1. 將 List 作為 Stack（堆疊）使用 | done 
5.1.2. 將 List 作為 Queue（佇列）使用 | done
5.1.3. List Comprehensions（串列綜合運算） | done
5.1.4. 巢狀的 List Comprehensions | done
5.2. del 陳述式 | done 
5.3. Tuples 和序列 (Sequences) | done
5.4. 集合 (Sets) | done
5.5. 字典（Dictionary） | done
5.6. 迴圈技巧 | done
5.7. 更多條件式主題 | done 
5.8. 序列和其他資料結構之比較 | done 42
6 模組 | done
6.1. More on Modules | done
6.1.1. Executing modules as scripts | done
6.1.2. The Module Search Path | done
6.1.3. “Compiled” Python files | done
6.2. Standard Modules | done
6.3. The dir() Function | done
6.4. Packages | done
6.4.1. Importing * From a Package | done
6.4.2. Intra-package References | done
6.4.3. Packages in Multiple Directories | done 53
7 輸入和輸出 | done
7.1. Fancier Output Formatting | done
7.1.1. Old string formatting | done
7.2. Reading and Writing Files | done
7.2.1. Methods of File Objects | done
7.2.2. Saving structured data with json | done 59
8 錯誤和例外 | done
8.1. 語法錯誤 | done
8.2. 例外 | done
8.3. 處理例外 | done
8.4. Raising Exceptions | done
8.5. User-defined Exceptions | done
8.6. Defining Clean-up Actions | done
8.7. Predefined Clean-up Actions | done 67
9 Classes | done
9.1. A Word About Names and Objects | done
9.2. Python Scopes and Namespaces | done
9.2.1. Scopes and Namespaces Example | done
9.3. A First Look at Classes | done
9.3.1. Class Definition Syntax | done
9.3.2. Class Objects | done
9.3.3. Instance Objects | done
9.3.4. Method Objects | done
9.3.5. Class and Instance Variables | done
9.4. Random Remarks | done
9.5. Inheritance | done
9.5.1. Multiple Inheritance | done
9.6. Private Variables | done
9.7. Odds and Ends | done
9.8. Exceptions Are Classes Too | done
9.9. Iterators | done
9.10. Generators | done
9.11. Generator Expressions | done 86
10 Python 標準函式庫概覽 | done
10.1. 作業系統介面 | done
10.2. 檔案之萬用字元 | done
10.3. 命令列引數 | done
10.4. 錯誤輸出重新導向與程式終止 | done
10.5. 字串樣式比對 | done
10.6. 數學相關 | done
10.7. 網路存取 | done
10.8. 日期與時間 | done
10.9. 資料壓縮 | done
10.10. 效能量測 | done
10.11. 品質控管 | done
10.12. 標準模組庫 | done 99
11 Python標準函式庫概覽 – Part II | done
11.1. Output Formatting | done
11.2. Templating | done
11.3. Working with Binary Data Record Layouts | done
11.4. Multi-threading | done
11.5. Logging | done
11.6. Weak References | done
11.7. Tools for Working with Lists | done
11.8. Decimal Floating Point Arithmetic | done 108
12 Virtual Environments and Packages | done
12.1. 簡介 | done
12.2. Creating Virtual Environments | done
12.3. Managing Packages with pip | done 112
13 What Now? | done
14 Interactive Input Editing and History Substitution | done
14.1. Tab Completion and History Editing | done
14.2. Alternatives to the Interactive Interpreter | done 116
15 Floating Point Arithmetic: Issues and Limitations | done
15.1. Representation Error | done 118
16 附錄 | done
16.1. 互動模式 | done
16.1.1. Error Handling | done
16.1.2. Executable Python Scripts | done
16.1.3. The Interactive Startup File | done
16.1.4. The Customization Modules | done 124

<br>

互動式相關指令
--
在 terminal 下執行指令或腳本

	python -c command [arg] # 指令可為多行 
	python -m module [arg]
	python -i # 執行完腳本後留在互動式界面中	
		
在 python 互動式界面中，當計算機運算時
	
	_ : 儲存最後一次計算的結果，可以方便之後的計算。
	
	>>> 2 + 3  
	5
	>>> _ ** 2
	25

原始碼的編碼
--

	default: UTF-8
	
	指定特殊編碼指令，寫在第一行或第二行：
	# -*- coding: encoding -*-

運算子 
-- 

1.  /  除法
	
	python3: 
	division always returns a floating point number

2. // 整數除法

	回傳整數，無條件捨去小數點。
	
3. ** power 次方

字串 
--

python 中字串是 immutable，因此一個已經宣告的字串無法被更改。
如要更改，只能創造一個新的。

字串變數類似於 array ，可使用 [index], [ index : index] 取值

### raw string

	不把 \ 當作跳脫字元則在字串前加入 r 
	
	>>>print(r'C:\some\name')
	C:\some\name	
	
### 多行字串, 換行控制

	在多行字串中每行的結尾可以使用 \ 避免換行。
	
	>>>print("""\
	...Hello\
	... World\
	...""")
	Hello World
	
### 配合運算子

	+ : 連接
	* : 重複
	len() : 取得字串長度
	
### 相鄰的字串自動連接

	>>>'py' 'thon'
	'python'
	
	可以用在很長的字串時
	text = ('Put several strings within parentheses '
	...    'to have them joined together.') 


多重賦值
--

	單行可以多重賦值，可以精簡指令行數。
	使用與否需考量可閱讀性的好壞。
	
	a, b = 0, 1
	a, b = b, a + b

print()
--

python3 之後，使用格式與 python2 不同。
使用 print( ) 。

* 參數 end	
	
	利用 end 參數取代換行，更靈巧控制輸出格式。
	print(content, end = ',')
	

迴圈
--

如果需要在迴圈中更改參考到的資料，
建議以複製過後的資料作為迭代，再來更改原變數中的資料。

例如使用 python 中的 slice 複製一份新的內容。

	 for w in words[:]:  
		 # Loop over a slice copy of the entire list.

### for-loop

python for-loop 可以配合 in 算子迭代任何資料型態中的內容。

	box = ['hi', 'there']
	for x in box:
		print(x, len(x))	

### other keywords
* continue
* break
* pass

函式 (function)
--

必有回傳值，沒有指定時回傳 **None** 。

python call by **value** (where the **value** is always an **object reference**)

* 函式重新命名
	可藉由 assignment 把函式指派給新的名子，同時可以呼叫到舊的函式內容。
	
		>>> fib
		<function fib at 10042ed0>
		>>> f = fib
		>>> f(100)
		0 1 1 2 3 5 8 13 21 34 55 89

### 函式參數 ( arguments )

* 設定參數**預設值** ( default arguments )

函式參數可以有預設值設定，在參數後面使用 `=` 即可指定預設值。

		def f(a, b = 1, c = 2):
			print(a,b,c)

**重要:** 如果預設值是 mutable 物件，例如空序列 `[]`，則預設值的物件只會被生成一次，意思是重複呼叫函式會使用到同一個物件，可能會有舊的值存在。

	>>>def f(a, L=[]):
	>>>    L.append(a)
	>>>    return L

	>>>print(f(1))
	[1]
	>>>print(f(2))
	[1, 2]
		
可以使用以下方式避開在預設值生成物件：

	def f(a, L=None):
	    if L is None:
	        L = []
	    L.append(a)
	    return L


<br>

* **指定**參數 ( keyword arguments )

在呼叫函式時可以**指定**參數傳值，藉由定義函式參數時所使用的**變數名稱**指定，可不依定義時順序指定傳值。  

	def f(v1, v2 = 'default', v3 = 'value'): 

	f(v2 = 'new', v1 = 'value')

**限制**是指定參數後面不能再有不指定的參數，因為直譯器無法確定是哪個參數的值。

<br>

* **隨意**數量參數 ( arbitrary arguments )

參數為 tuple 或 dictionary 資料型態，可以傳入不限定數量的參數。
tuple 使用 * ，dictionary 使用 ** ，並且如果同時使用時 tuple 類型必須在 dictionary 類型之前。

	def f(v1, *tuple_V, **dictionary_V):
	
	f('v1', 1, 2, 3, k1 = 'a', k2 = 'b')

如果在隨意參數**之後**還有其他類型參數的話，必須是**指定**參數。

	def f(*tuple_V, v1 = 'default'):

	f(1,2,3, v1 = 'value')

<br>

* **打開資料結構**後傳入參數 ( unpacking )

只要資料型態中的資料類型與數量**對應**函式的參數，不管是 tuple 或者 dictionary 皆可以透過 unpacking 直接傳給函式作為參數。
tuple 使用 * ， dictionary 使用 ** 解開資料型態。


	tuple:
	
	>>>args = [3, 6]
	>>>list(range(*arfgs)) 
	[3, 4, 5]

	dictionary 配合指定參數:

	>>>def f(v1, v2 = 'default', v3 = 'value'):
	...    print(v1, v2, v3)
	...
	>>>args = {'v1' : 'this', 'v2' : 'is', 'v3' :  'fashion'}
	>>>f(**args)
	this is fashion
	

python 程式碼慣例
--
參考官方文件 [PEP8](https://www.python.org/dev/peps/pep-0008/)

* 縮排使用 4 個空白，而非 tab。
* 每一行程式碼不超過 79 個字元。
* 如果可以註解寫在同一行程式碼後面
* 使用 docstrings 產生文件
* 命名 Classes 使用 CamelCase，functions or methods 使用 小寫與 _ 。 
	

資料結構
--

### List （串列）

mutable 資料，通常儲存同質資料。

* 當作 array 和 stack 使用，雖然也能作為 queue 使用但是效能較差。
* 如要使用 queue 推薦使用 collections.deque 實作。

### Tuple 與 sequence （序列） 

**Immutable** 通常儲存異質資料，可以以 index 讀取。 

* 初始化

		直接使用 , 隔開，使用 ( ) 可有可無。
		t = 123, 'abc'
		t = ( 123, 'abc' )
	
* 多重賦值

		只要數量相對，資料會自動 unpacking 達到多重賦值
		t = 123, 'abc'
		a, b = t
		
### Set （集合）

無序，沒有重複的資料，有提供集合運算。

* 初始化

		使用 { } 或 set()
		>>>s = set('aaaaaabbbdddcc')
		>>>s
		{'b', 'c', 'a', 'd'}

### Dictionary (字典)
	
無序的 key, value pairs 。

* 當 key 為字串時的簡化語法，key 不需使用 ' or " 表示字串

		>>> dict(sape=4139, guido=4127, jack=4098)
		{'sape': 4139, 'jack': 4098, 'guido': 4127}

### Comprehensions （綜合運算）

藉由 for、 in 和 if 算子的運算，作為資料內容的生成表達。
不需要使用迴圈結構，產生資料內容。
以更簡化與直觀的方式產生資料，類似 lambda 的功能。
非常類似數學集合的表示方式。

	>>> [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]
	
	[(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]

甚至可以以巢狀運算表示，只是可讀性可能較差。

	以巢狀運算達到矩陣轉置
	
	>>> matrix = [
	...     [1, 2, 3, 4],
	...     [5, 6, 7, 8],
	...     [9, 10, 11, 12],
	... ]

	>>> [[row[i] for row in matrix] for i in range(4)]
	[[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]


模組與模組庫 ( Module & Package )
--

### import

* from package import (module or item)
* 程式只載入 import 後面的內容，使用時亦從 import 的資料階層開始呼叫。
* 盡量不要使用 import * ，避免不預期的邊際效應。



### Module ( 模組 )

當同一個 python 檔案同時作為 script 與 module 使用時，可以利用以下程式碼分開使用時機：

	if __name__ == '__main__' :
        # script code here

`__name__` 當作 module 被呼叫時，會是 python 檔案名稱；
作為 script 執行時則是 `"__main__"`。

這種方式可以將 module 所需要的測試寫在同一個檔案裡。

### dir([object]) 查詢 namespace

內建函數 ( built-in function ) ， dir([object]) 可以用來取得 module 裡的 item names ，不加參數時 dir() ，可以取得當前環境的 names 。 

### Package (模組庫)

把多個 modules 放置於相同的資料夾做成 package ，可以在包含資料夾做成階層模組庫。

每個資料夾中都會有 `__init__.py` 內容可為空，這樣使 python 直譯器能識別該資料夾為一個 package 結構。
`__init__.py` 中亦可定義其他內容。


輸入和輸出
--

### String Format

* 字串排版函數 rjust(), ljust(), center(), zfill()

新的 String Format : str.format() 以下為各種不同的例子。

	'We are the {} who say "{}!"'.format('knights', 'Ni')
	
	'The story of {0}, {1}, and {other}.'.format('Bill', 'Manfred', other = 'Georg'

	'{0:.3f}'.format(math.pi)



	table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 8637678}
	
	'Jack: {0[Jack]:d}; Sjoerd: {0[Sjoerd]:d}; ''Dcab: {0[Dcab]:d}'.format(table)
	
	'Jack: {Jack:d}; Sjoerd: {Sjoerd:d}; Dcab: {Dcab:d}'.format(**table)

### File I/O

#### Efficient Way of Read

	f = open('filename','mode')
	for line in f:
		# operating about line

#### open file with key word `with`

這是一種良好的操作檔案的方式，因為他會自動 f.close() 關閉檔案，
就算發生 exception 依舊會自動關閉檔案。不需要繁複的 try-finally 語法。

	with open('filename', 'r') as f:
	    read_data = f.read()

### JSON	


例外處理 (Exception)
--

Python 中的 Exception ，除了 Base Exception class 使用 Exception 之外。其他繼承的例外處理皆使用 Error 作為其名稱。
除了 SyntaxError 為 parsing error 外，其他為 run-time error

語法使用：

   	try:
		# do something 
		raise SomeError('WithAttributes')
	except SomeKindError:
	except ( HandleError, MultipleError, ATimeError ):
	except OSError as err:
        print("OS error: {0}".format(err))
    except:
        print("Unexpected error:", sys.exc_info()[0])
        raise # raise the exception again then show the description.
    else:
        # when try scope has no exception
    finally:
        # doing this not matter what. clean-up

<br>

### 預先定義好的 clean-up 物件

python 中有些物件有定義出 clean-up 機制例如 File，這種設計會被寫在說明文件中。此時可以使用 with 語法，並且保證了 clean-up 機制。

範例：

	with open("myfile.txt") as f:
        for line in f:
            print(line, end="")

<br>
Classes 
--

類似於 C++ 中 static 的 data ，一個 class 只有一份被其所有的 objects 使用。

### static data in python

	class ClassName:
	
	    shared_data = 0
	    # class variable shared by all instances (static variable)
		
		def __init__(self, name):
	        self.name = name
	    # instance variable unique to each instance 

### 多重繼承 (Multiple Inheritance)

為了避免參考問題，python 中的呼叫順序為 depth-first, left-to-right, 並且每個 class 只被查詢一次。因此會產生不重複的線性查詢序。

* 一些關於繼承的 built-in functions:

1. isinstance( instance, class ) return True / False 
2. issubclass( subclass, parentclass ) return True / False 

### private 

python 中並沒有 private 的使用，因此所以的成員皆可以被外部呼叫。但是 python 中有命名慣例，來代表希望只被內部使用的成員。

命名慣例在希望使用 private 的成員名稱前面加上 `__` or `_` ，
例如 `__spam`

### 自訂 iterator

實做 iterator 之後就能在使用 for-loop 時配合 `in` 算子執行迭代。
以下為官方文件中的例子：

	class Reverse:
	    """Iterator for looping over a sequence backwards."""
		def __init__(self, data):
	        self.data = data
	        self.index = len(data)

	    def __iter__(self):
	        return self

	    def __next__(self):
	        if self.index == 0:
	            raise StopIteration
	        self.index = self.index - 1
	        return self.data[self.index]

重點在於 

1. `__iter__` 回傳 `self`
2. 實作 `__next__`
3. 包含 raise StopIteration 作為中止條件


常用的標準函式庫
--

### 作業系統介面 os, 檔案操作 shutil


* os.system(' system call commands ') # 直接把指令以字串型態傳出執行。

* os.getcwd() # 取得當前位置
  等等其他常見的殼層操作

### 檔案路徑搜尋 glob

可以通過 * wildcard 查詢檔案

### 正規表示式字串操作 re

### 數學相關 math, random, statistics, decimal

### 網路相關 urllib.request 

### 日期與時間 datetime

### 資料壓縮 zlib, gzip, bz2, lzma, zipfile, tarfile 

### 效能量測 timeit

### 程式測試 doctest, unittest

### 多執行序 threading 


<br>
虛擬環境與函式庫引入 pip
--

python 提供 script : **pyvenv** ，可以創造出虛擬的工作環境，
為了讓不同的 python 程式可以運行在指定的 python 版本中。
可以通過使用 **pip** 模組中的指令，管理不同函式庫的版本，
並且可以做成清單重複使用。

### pyvenv
### pip

### pypi
Python Package Index, 這是一個第三方使用者創造的函式庫的官方管理儲存庫。
[pypi 網站連結](https://pypi.python.org/pypi)

<br>
Python 其他官方建議的資源
--

### [標準函式庫](https://docs.python.org/3.5/library/index.html#the-python-standard-library)

### [安裝第三方函式庫文件](https://docs.python.org.tw/3/installing/index.html#installing-index)

### [細部討論 python 語法](https://docs.python.org.tw/3/reference/index.html#reference-index)

### [python 官方網站](https://www.python.org/)

### [Pypi](https://pypi.python.org/pypi)

### [Python Cookbook](https://code.activestate.com/recipes/langs/python/)
大量的 python 實作程式碼，包含實用的 script 與其他函式庫。

### [python conference video](http://pyvideo.org/)

### [scipy : Scientific Python project](https://scipy.org/)

<br>
Python shell 
--
python 中的互動式殼層 (shell)，
可以使用 **tab** 自動語法補全。

在自定義的函式庫中也可以支援語法自動補全，
需在類別中實作 `__getattr()__`。

### IPython 與 bpython
IPython 與 bpython 是非官方開發的互動式殼層，
有更好的編輯能力，包含語法高亮、更強大的自動補完等等。

<br>
浮點數運算與限制 
--

在電腦中儲存小數的方式，是轉為二進位小數。
因此以十進制的小數，無法被**準確**的表達，大多數皆是近似值，
因此在做運算時，常常會得到非預期的判斷，尤其是作等號 ` == ` 判別時。

### decimal, fractions, SciPy
如果需要考慮精確值時可使用函式庫 **decimal** 和 **fractions** ，或者直接使用專門做數值運算的第三方函式庫 [**SciPy**](https://scipy.org/)


* * *

學習主軸 3. [codecademy : Python (lesson broken at 8)][mainSource3]
==
[mainSource3]: https://www.codecademy.com/learn/learn-python

進度紀錄
==
Table of Contents | Read
:-----------------|:----
count             | 12
1 Python Syntax | done 
2 Strings and Console Output | done 2
3 Conditionals and Control Flow | done
4 Functions | done 4
5 Lists & Dictionaries | done
6 Student Becomes the Teacher | done 6
7 Lists and Functions | done 7
8 Loops |
9 Exam Statistics |
10 Advanced Topics in Python |
11 Introduction to Classes |
12 File Input and Output |


## 多行註解

	"""
	comments
	here
	"""

## datetime module 

## list methods

* pop(index)
* remove(itme)
* del() 

## String methods

* " string ".join()

## 指令分段

* 使用 \ 
 
 
 * * *  * * *  * * *  * * *  * * *  * * * 

專題學習 1. [Django Girls 教學手冊][subjectStudy1]
==
[subjectStudy1]: http://djangogirlstaipei.herokuapp.com/tutorials/

進度紀錄
==
Table of Contents | Read
:-----------------|:----:
count             | 8
課前準備| -
1 安裝開發環境 | done 
2 PythonAnywhere 註冊與設定 | done 
前導課程 | -
3 命令列 | done 
4 Python 入門 | done 
5 HTML | done 5
Django 教學 | -
6 Django 學習指南 | done 
進階教材 | - 
7 用 Git 進行版本控制 | done 
8 部屬到 Heroku | done 8


* * * * * * * * * * * * * * * * * * * * * * * * 

專題學習2. 探索標準函式庫與 build-in function  
==

### [標準函式庫](https://docs.python.org/3.5/library/index.html#the-python-standard-library)

### [安裝第三方函式庫文件](https://docs.python.org.tw/3/installing/index.html#installing-index)

### [細部討論 python 語法](https://docs.python.org.tw/3/reference/index.html#reference-index)



# 真實文本 mud your hand



* * * * * * * * * * * * * * * * * * * * * * * * 

其他資源
==

完整學習地圖資源

* [良葛葛 python](https://openhome.cc/Gossip/Python/index.html)
* [Dive into Python 3](http://www.diveintopython3.net/)
 
其他

* [PEP8](https://www.python.org/dev/peps/pep-0008/)
* [Built-in Functions](https://docs.python.org/3.5/library/functions.html)
* Flake8
* [Python 慣用語](http://seanlin.logdown.com/posts/239883-python-idioms)
* [Python 台灣使用者群組](http://wiki.python.org.tw/Pot)
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTgzNDQ4MjE3Nl19
-->