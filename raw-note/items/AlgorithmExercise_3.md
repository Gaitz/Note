## AlgoExpert 160 Coding Interview Questions

### [AlgoExpert](https://www.algoexpert.io/questions), AlgorithmExercise

---

Coding Interview Tips

Easy and Medium

第一章 - Arrays : Easy and Medium 14

第二章 - Strings : Easy and Medium 10

第三章 - Stacks : Easy and Medium 5

第四章 - Heaps : Easy and Medium 1

第五章 - Linked Lists : Easy and Medium 4

第六章 - Binary Trees : Easy and Medium 6

第七章 - Binary Search Trees : Easy and Medium 7

第八章 - Tries : Easy and Medium 1

第九章 - Graphs : Easy and Medium 8

第十章 - Recursion : Easy and Medium 6

第十一章 - Sorting : Easy and Medium 4

第十二章 - Searching : Easy and Medium 3

第十三章 - Greedy Algorithms : Easy and Medium 5

第十四章 - Dynamic Programming : Easy and Medium 5

第十五章 - Famous Algorithms : Easy and Medium 1

Hard and Very Hard

第十章 - Arrays : Hard and Very Hard 10

第十六章 - Strings : Hard and Very Hard 5

第十七章 - Stacks : Hard and Very Hard 2

第十八章 - Heaps : Hard and Very Hard 4

第十九章 - Linked Lists : Hard and Very Hard 9

第二十章 - Binary Trees : Hard and Very Hard 7

第二十一章 - Binary Search Trees : Hard and Very Hard 3

第二十二章 - Tries : Hard and Very Hard 1

第二十三章 - Graphs : Hard and Very Hard 5

第二十四章 - Recursion : Hard and Very Hard 7

第二十五章 - Sorting : Hard and Very Hard 5

第二十六章 - Searching : Hard and Very Hard 4

第二十七章 - Dynamic Programming : Hard and Very Hard 14

第二十八章 - Famous Algorithms : Hard and Very Hard 4

---

### Coding Interview Tips

How To Best Use AlgoExpert

- 目標在於最佳化面試
- 做大多數或所有的題目並且吸收
- 推薦依據難度練習,
- 依據類型做題, 可以找出自己的弱項, 然後加強學習
- 一開始練習不要限制解題時間, 只有在快要面試時才開始限制時間練習
- 盡可能自己解開問題, 才能最大化吸收
- 對於 Hint 的使用, 要一個一個來
- 永遠要詳細的描述空間與時間複雜度

---

## Tips

- 清楚問題的輸入與輸出的型別與可進行的操作
- 複雜流程應該被抽成有意義的函式, 然後組合成可閱讀的程式碼
- Index pointers
- Hash table, 優化搜尋, T: O(1), S: O(N)
- Sort first, T: O(N \* LogN), 先排序
- Scan and find candidate, 搜尋尋找候選者
- Recursive, 遞迴解, 因為 call stack 的關係會產生額外的 space
- Back tracking, 一邊優化的遞迴解
- 觀察問題特性, 尋找獨特的優化方式
- 遞迴中止條件放在最開頭, 來保障正確性
- 遞迴可以利用物件型別回傳多個資料
- 如果 case 結束記得 `return` 避免錯誤
- 完成前記得 trace code with example 找到可能沒處理到的 case.
- 注意呼叫內部函式或已有函式的複雜度
- Immutable 與 mutable 如果只是 read 減少不必要的空間
- 紙筆優先
- 遞迴型複雜度分析可以畫出完整的樹狀結構來計算
- 必須學著自己找 edge cases examples, 可以從 operator 的各種情況分類

---

## Easy and Medium

---

### 第一章 - Arrays : Easy and Medium 14

Hints:

- Index pointers
- 排序 T: O(N \* LogN), 排序後利用有序這個條件來更有效率地尋找解
- Hash table memory, 計算且儲存 S: O(N)
- 找出回傳的模式並且優先計算格式, 才補值
- 注意剩餘條件或迴圈跑完後的狀況, 除了中途正確的 return 外，特別注意最後的 return 應該回傳的內容
- 把問題 array 的值，依序加入思考每次的結果是否可以重用
- 檢查特殊案例與基本案例
- 嚴格思考問題定義與解的相關邏輯，也許有更簡單的作法
- 依據定義尋找候選答案，然後再計算出最佳解
- 嘗試從左走訪陣列跟從右邊走訪陣列, 嘗試一次只做一部份的解最後才整合
- 思考 bottleneck 原本的功能並且以更 tricky 的方式實現相同功能

#### 1. Two Number Sum

- 三種方式
- Brute force, T: O(N^2)
- Using space, T: O(N), S: O(N)
- Using sorted and two pointers, T: O(N \* LogN)

#### 2. Validate Subsequence

- `while` loop, two index pointers
- `for` loop, one index pointer
- T: O(N), S: O(1)

#### 3. Sorted Squared Array

- 計算排序, T: O(N \* LogN), S: O(N)
- 利用已排序的特性配合 two pointers 直接找到正確的位置後才計算, T: O(N), S: O(N)

#### 4. Tournament Winner

- 分步驟做
- 思考步驟是否可以使用相同的迴圈一次處理完
- T: O(N), S: O(N)

#### 5. Non-Constructible Change

- T: O(N \* LogN), S: O(1)
- 排序, 思考依序增加後重用找解

#### 6. Three Number Sum

- Brute force (triple `for` loop): T: O(N^3),
- 排序後使用 two pointers 分別為最大與最小包夾找解, T: O(N^2), S: O(N) 放置解答的空間

#### 7. Smallest Difference

- Brute force (double `for` loop): T: O(N \* M), N for arrayOne.length, M for arrayTwo.length
- 排序後使用 two pointers 依據大小尋找適合的解，節省多餘的計算, T: O(N _ LogN + M _ LogM) 因為排序, S: O(1)

#### 8. Move Element To End

- Brute force: 分類儲存然後合併, T: O(N), S: O(N)
- 因為最佳的時間複雜度只可能是 T: O(N) 並且已經達到, 因此要改成精簡成 S: O(1), 使用 two index pointers, 分別指向頭與尾

#### 9. Monotonic Array

- T: O(N), S: O(1) 符號變動
- 有小陷阱需要注意 0 變動時
- 方法二, 從定義下手雖然複雜度不變，但是程式更簡短

#### 10. Spiral Traverse

- T: O(N), S: O(N)
- 方法一, 一次走訪一個, 類似走迷宮, 程式較為繁瑣
- 方法二, 一次走訪一圈, 然後內縮, 可分成迭代解與遞迴解

#### 11. Longest Peak

- T: O(N), S: O(1)
- 方法一, `for` loop, 處理 current, next 先前狀態分成三種 NOT_CLIMB, CLIMB_UP, CLIMB_DOWN, 程式較為複雜因為狀態分支很多
- 方法二, `for` loop or `while` loop 尋找最小的 peak 狀態後再向左右延伸計算長度, 程式較為簡單

#### 12. Array Of Products

- 方法一, Brute force, double `for` loop, T: O(N^2), S: O(N)
- 方法二, 先計算總合後, 個別使用除法, T: O(N), S: O(N)
- 方法三, 分別由左走訪跟由右走訪, 並且儲存計算後的值, 最後再組合成解答, T: O(N), S: O(N)

#### 13. First Duplicate Value

- 方法一, `for` loop + hash table, T: O(N), S: O(N)
- 方法二, 依據題目的特殊規則讓原本的 array 可以直接提供 memory 功能, super tricky, T: O(N), S: O(1)

#### 14. Merge Overlapping Intervals

- Immutable 版本, 排序後處理, `for` loop 利用額外的判斷處理比較的起始值, 需要特別注意最後一項的處理, T: O(N \* logN), S: O(N)
- Mutate 版本, 排序後處理, `for` loop 利用修改原生 array 並且控制 index 直接一邊修改一邊處理迴圈, T: O(N \* logN), S: O(1)

---

### 第二章 - Strings : Easy and Medium 10

Hints:

- 字串就是陣列
- 遞迴解，肯定需要額外的空間複雜度
- 字元可以轉換成 ASCII code 或 Unicode 後做運算
- 在 JavaScript 中, 需要注意 code unit 與 code point 的差別在 UTF-16 中遇到擴充字元時。
- Hash table 優化搜尋

#### 1. Palindrome Check

- 方法一, two pointers, T: O(N), S: O(1)
- 方法二, recursive, T: O(N), S: O(N), 每次呼叫都會儲存一次新的 string 因此空間複雜度是 O(N)

#### 2. Caesar Cipher Encryptor

- 方法一, 利用紙筆計算找出計算移動後正確的 char code 公式，然後依序執行。T: O(N), S: O(N), N for string.length, 題目要求回傳新的字串因此佔用空間複雜度 N

#### 3. Run-Length Encoding

- 方法一, pre 放在迴圈外，T: O(N), S: O(N)，程式較複雜
- 方法二, pre 放在迴圈內，每次都讀取 pre 與 current, T: O(N), S: O(N), 程式較簡單

#### 4. Generate Document

- 方法一, Brute Force, 每次在迴圈裡尋找後刪除用過的，T: O(N \* M), S: O(1), N 為 characters.length, M 為 document.length
- 方法二, 使用 hash table 取代搜尋, T: O(N + M), S: O(N), N 為 characters.length, M 為 document.length

#### 5. First Non-Repeating Character

- 方法一, Brute Force, double `for`, T: O(N^2), S: O(1)
- 方法二, hash table, T: O(N), S: O(1), N for string.length, 空間複雜度為 O(1) 因為已經指定字元集合最多為 26 個

#### 6. Longest Palindromic Substring

- 方法一, Brute Force, 窮舉後計算, T: O(N^3), S: O(N), 空間複雜度為輸出結果
- 方法二, Scan and expand, 依序尋找候選者並且擴充找到最佳解, 由定義下手觀察特性，誰是候選者。 T: O(N \* (N + N)) = O(N^2), S: O(N), N for string.length
- 方法三, 等同於方法二, 但是儲存使用 index 取代完整的字串, T: O(N^2), S: O(1)

#### 7. Group Anagrams

- 方法一, 排序配合 hash table, T: O(N \* W \* log(W)), S: O(N), N for words.length, W for longest word length

#### 8. Valid IP Address

- 方法一, Brute force (triple `for`), T: O(1), S: O(1), 因為 string.length 的長度已經被限制，因此最高上限是固定的
- 方法二, Brute force (triple `for`) + index optimization (不需要每一個 `for` 都檢查完整的字串，因為 ip 每個區間上限就是 3 個字元)

#### 9. Reverse Words In String

- 方法一, 收集 word 與 space 然後翻轉後組合起來, T: O(N), S: O(N) N for string.length

#### 10. Minimum Characters For Words

- 方法一, 分別計算然後整合

---

### 第三章 - Stacks : Easy and Medium 5

Hints:

- 遞迴中止條件放在最開頭, 來保障正確性

#### 1. Min Max Stack Construction

- 方法一, 追蹤每次的 min 與 max 連動 stack

#### 2. Balanced Brackets

- 方法一, 追蹤 brackets 是否關閉, 使用 stack 資料結構, 注意 error case, T: O(N), S: O(N), N for string.length

#### 3. Sunset Views

- 方法一, 先直觀的處理容易的 WEST 然後反向處理 EAST, T: O(N), S: O(N), N for buildings.length

#### 4. Sort Stack

- 遞迴解, 遞迴中止條件放在最開頭, 來保障正確性

#### 5. Next Greater Element

---

### 第四章 - Heaps : Easy and Medium 1

- Tip: 用 array 儲存 binary tree,
  - parent = array[floor((currentIndex - 1) / 2)],
  - childLeft = array[currentIndex * 2 + 1] ,
  - childRight = array[currentIndex * 2 + 2]

#### 1. Min Heap Construction

- Min heap 建立, 以 array 來儲存 binary tree, build heap 的方式有多種
- insert 是從底層浮上來
- remove 是把 root 與最後一個元素交換, 然後把最後一個元素向下移動到適合的位置
- **buildHeap** 的時間複雜度是 T: O(n) 而非 T: O(n \* log(n)), 學習實際的複雜度分析

### 第五章 - Linked Lists : Easy and Medium 4

Hints:

#### 1. Remove Duplicates From Linked List

- 方法一, 記憶一個 reference 負責改造連接所有值不一樣的節點，需注意在 `while` loop 結束後要處理結尾, T: O(N), S: O(1), N for linked list length
- 方法二, 在處理每個 current node 的時候，都 `while` loop 找到值不同的 next 節點然後接上, 複雜度同上

#### 2. Linked List Construction

- 細心處理 edge case, 盡可能重用 function

#### 3. Remove Kth Node From End

- 如果 case 結束記得 `return` 避免錯誤

#### 4. Sum of Linked Lists

- 一個 while loop 解決， 完成前記得 trace code with example 找到可能沒處理到的 case.

---

### 第六章 - Binary Trees : Easy and Medium 6

Hints:

- DFS, 遞迴, 非遞迴使用 stack
- 遞迴回傳多資料型態

#### 1. Branch Sums

- DFS + Recursive

#### 2. Node Depths

- DFS, 遞迴或非遞迴
- 遞迴解可以只用一行 expression 就寫完

#### 3. Invert Binary Tree

- mutable, 遞迴解 DFS
- immutable, 遞迴解 DFS

#### 4. Binary Tree Diameter

- dfs, 思考遞迴應該回傳的型別與最基礎的案例, 回傳的內容可以是多資料的

#### 5. Find Successor

- 清楚的理解, input 的型別與能進行的操作
- 兩種做法,

  1. 無視額外的 parent pointer 存在 array 後查詢, T: O(n), S: O(n), n = length
  1. 因為輸入的目標含有指標, 可以直接進行搜尋, T: O(h), S: O(1), h = depth

  #### 6. Height Balanced Binary Tree

  - DFS, 紀錄 balance 狀態與 height
  - 先思考 base case 然後擴張, 記得使用範例思考演算法

---

### 第七章 - Binary Search Trees : Easy and Medium 7

Tips:

#### 1. Find Closest Value in BST

- 遞迴與非遞迴解, 只差在佔用的空間

#### 2. BST Construction

- Remove 有多種 case 需要思考清楚, 是否是 root 與子樹的存在與否

#### 3. Validate BST

- 針對一個點思考什麼狀況是不合理的, 然後使用遞迴方式依序檢查
- 遞迴函式可以藉由回傳值或參數攜帶狀態

#### 4. BST Traversal

- 遞迴 in-order, pre-order, post-order

#### 5. Min Height BST

- 手動建立, 找出基本案例, 發現遞迴解
- 注意呼叫內部函式或已有函式的複雜度
- Immutable 與 mutable 如果只是 read 減少不必要的空間

#### 6. Find Kth Largest Value In BST

- 遞迴走訪

#### 7. Reconstruct BST

---

### 第八章 - Tries : Easy and Medium 1

Tips:

- 紙筆優先

#### 1. Suffix Trie Construction

- 思考時間與空間複雜度

### 第九章 - Graphs : Easy and Medium 8

Tips:

- 試著用 DFS 和 BFS 尋找有用的資訊

#### 1. Depth-first search

- 複雜度分析, 依據邊 (edges) 與節點數 (vertices)

#### 2. Single Cycle Check

- T: O(n), S: O(n) 記錄版
- T: O(n), S: O(1) 不記錄版
- 困難在正確寫出 next index 的處理包含所有的 edge cases

#### 3. Breadth-first Search

- Queue

#### 4. River Sizes

- 演算法不難, 但是很繁瑣

#### 5. Youngest Common Ancestor

- S: O(n), S: O(1) 對應 Level

#### 6. Remove Islands

- 演算法不難, 但是很繁瑣
- 有更複雜的 S: O(1) 版本

#### 7. Cycle In Graph

- 試著用 DFS 和 BFS 尋找有用的資訊
- 紀錄兩種東西, visited 與 inStack

#### 8. Minimum Passes Of Matrix

- 直觀的執行並且減少不必要的重複檢查

---

### 第十章 - Recursion : Easy and Medium 6

Tips:

- 遞迴型複雜度分析可以畫出完整的樹狀結構來計算

#### 1. Nth Fibonacci

- 有趣的題目, 三種解法, 每種都有進步, T: O(2^n), S: O(n) -> T: O(n), S: O(n) -> T: O(n), S: O(1)

#### 2. Product Sum

- 沒任何難度, 照著題目定義解

#### 3. Permutations

- 經典題目, 注意複雜度算法
- SWAP + 遞迴法

#### 4. Powerset

- 經典題目
- 從基礎案例列舉, 找出新增規律
- 注意複雜度分析

#### 5. Phone Number Mnemonics

- 窮舉的題目
- 遞迴處理每一個階段
- 注意複雜度分析

#### 6. Staircase Traversal

- 經典題目, 有多種解法並且有不同的複雜度
- 注意複雜度分析
- 遞迴型複雜度分析可以畫出完整的樹狀結構來計算

1. 遞迴法,
2. 遞迴 + memorize,
3. 疊代法 (DP),
4. Window 移動, 每次只做必要的工作

---

### 第十一章 - Sorting : Easy and Medium 4

#### 1. Bubble Sort

- IDEA: 持續從頭兩兩檢查
- 最基礎的 Sort 方式, mutated, 不需要其他的空間
- Avg T: O(n^2), S: O(1)
- Best T: O(n), S: O(1)
- 依序檢查並且 SWAP 然後重複執行直到 Sorted
- 特別注意到的是每次跌代都會把最大值放到最尾端
- 每次跌代記得追蹤是否已經 sorted 可以提早回傳

#### 2.Insertion Sort

- IDEA: 把左側作為已排序, 一次加入一個新的元素, 插入已排序的左側
- Mutated, 不需要額外空間
- Avg T: O(n^2), S: O(1)
- Best T: O(n), S: O(1)

#### 3. Selection Sort

- IDEA: 把左側作為已排序, 持續地把未排序的最小值往已排序的位置放置
- Mutated, 不需要額外空間
- Avg T: O(n^2), S: O(1)
- Best T: O(n^2), S: O(1)

#### 4. Three Number Sort

- Count and swap, Bucket Sort
- 使用 Index 去指定 first, second, third value 的正確位置

---

### 第十二章 - Searching : Easy and Medium 3

Tips:

#### 1. Binary Search

- 經典搜尋
- T: O(log(n))
- 注意 middleIdx 的修改

#### 2. Find Three Largest Numbers

- 走訪且持續更新最大值

#### 3. Search In Sorted Matrix

- 手動找出走訪規則

---

### 第十三章 - Greedy Algorithms : Easy and Medium 5

Tips:

- Greedy Algorithms: 每次都找出局部最佳解則最終結果為最佳解時適用
- 通常解法都很直觀

#### 1. Minimum Waiting Time

- 沒有難度找出規律, 思考複雜度
- 先排序比重複尋找更有效率

#### 2. Class Photos

- 沒有難度找出規律, 思考複雜度
- 先排序比重複尋找更有效率

#### 3. Tandem Bicycle

- 沒有難度找出規律, 思考複雜度
- 先排序比重複尋找更有效率

#### 4. Task Assignment

- 為了要符合答案的格式, 需要準備適當的資料結構來計算

#### 5. Valid Starting City

- 利用給的條件可以達成 O(n) 有點 tricky

---

### 第十四章 - Dynamic Programming : Easy and Medium 5

Tips:

- Dynamic Programming 是以子問題的解來建立全域的解
- 持續追蹤目前的最佳解並且觀察目前最佳解與過去最佳解的關係, 找出可以推導的公式
- 適合在問題組合非常多種時, 可以先以非常小的問題慢慢建立起解答
- 針對 Dynamic Programming 的空間使用率, 可以藉由觀察每一次真正所需要使用到的範圍, 去做空間使用率的減少

#### 1. Max Subset Sum No Adjacent

- 持續追蹤目前的最佳解並且觀察目前最佳解與過去最佳解的關係, 找出可以推導的公式

#### 2. Number Of Ways To Make Change

- Dynamic Programming 經典題目
- 無限數量的背包問題

#### 3. Min Number Of Coins For Change

- Dynamic Programming 經典題目
- Dynamic Programming 時, 只需一小步變化作考慮

#### 4. Levenshtein Distance

- Dynamic Programming 經典應用
- 針對實際會用到的內容建立需要暫存的空間, 達到最佳化空間複雜度

#### 5. Number Of Ways To Traverse Graph

- Dynamic Programming 經典問題
- 1. 使用基本的 dp 方式可以做出來
- 2. 最佳解其實是答案即移動次數的組合數, 因此可以直接使用數學組合數公式, 直接算出解

---

### 第十五章 - Famous Algorithms : Easy and Medium 1

Tips:

#### 1. Kadane's Algorithm

- 處理連續子陣列最大和
- Dynamic Programming 的基礎應用
- 每次加入新 index 都可以計算一次最大值並且與現有最大值做比較

---

## Hard and Very Hard

---

### 第十章 - Arrays : Hard and Very Hard 10

Tips:

- 最佳化的兩種情況 1. 一次處理雙向, 2. 一次處理單向但是處理兩次, 最好兩種都想想看選擇出最簡單實作的
- 圖形題, 先視覺化畫出實際的圖, 來觀察
- 沒有想法時, 先思考 brute force 然後減少重複的部分
- 試著儲存某些結果, 來觀察是否有用, 最後試著減少所使用的空間
- 此題困難處在於處理 float point as hash table key
- 資料的順序, 可以避免不必要的計算
- Hash Table 儲存邊 (edge) as key

#### 1. Four Number Sum

- 以 Two number sum 的解法為基礎進化而成
- 思考如何避開紀錄重複的內容, 以一定的順序做處理

#### 2. Subarray Sort

- 注意相等時的處理並且測試多個可能

#### 3. Largest Range

- Hash table 優化搜尋
- 順序的 check 除了單向之外, 其實可以一次雙向處理 (+ -)

#### 4. Min Rewards

- 除了 expand valley 一次處理左右邊
- 不如一次處理單向然後執行兩次 (更聰明, code 更簡單)

#### 5. Apartment Hunting

- 一次處理單向然後執行兩次

#### 6. Calender Matching

- 思考方式有兩種, 演算法不同但是時間與空間複雜度一樣

1. 計算出允許的時間後才挑出共同適合的
2. 合併雙方被占用的時間, 然後才找出剩餘的時間

#### 7. Waterfall Streams

- 樹狀結構, 因此使用 stack 儲存所需的資訊, 與處理順序
- 程式稍微繁瑣適合抽離邏輯, 提高表達力
- 官方解法使用, 一次處理兩層依序處理 (認為稍微複雜, 不直觀, 效能也沒有差異)

#### 8. Minimum Area Rectangle

- 資料的順序, 可以避免不必要的計算
- Hash Table 儲存邊 (edge) as key

#### 9. Line Through Points

- 圖形題, 先視覺化畫出實際的圖, 來觀察
- 沒有想法時, 先思考 brute force 然後減少重複的部分
- 試著儲存某些結果, 來觀察是否有用, 最後試著減少所使用的空間
- 此題困難處在於處理 float point as hash table key

---

### 第十六章 - Strings : Hard and Very Hard 5

Tips:

- 試著以儲存 index 來處理字串問題, 而非儲存字串本身
- 如果單一個迴圈或直接處理太困難, 試著不要一個迴圈做完, 而是分成多個步驟處理
- 試著達到與解相關的部分成果, 然後再一步一步變成真正的解
- 記得字串尋找 (find) 比對 string matching 所需要的時間複雜度是 O(n + m), n, m 為分別的字串長度, KMP 演算法
- 複雜度分析可以嘗試分析實際的 input 可以更精準的計算出實際的複雜度
- 先手寫每一步執行步驟, 最後才歸納成演算法, 然後才實作, 並且分成多個 function 來處理細節
- 試著思考所有能儲存的東西, 並且觀察是否有用

#### 1. Longest Substring Without Duplication

- 試著以儲存 index 來處理字串問題, 而非儲存字串本身

#### 2. Underscorify Substring

- 困難, 允許的情況除了連接以外 overlay 也算, 要處理的 case 非常多
- 如果單一個迴圈或直接處理太困難, 試著不要一個迴圈做完, 而是分成多個步驟處理
- 試著達到與解相關的部分成果, 然後再一步一步變成真正的解
- 記得字串尋找 (find) 比對 string matching 所需要的時間複雜度是 O(n + m), n, m 為分別的字串長度, KMP 演算法
- 此題步驟分成
  1. 找出所有 substring indices,
  2. 合併 substring indices 找到真正要加 underscore 的地方
  3. 實際執行加 underscore 並且組合出結果

#### 3. Pattern Matcher

- 困難, 細節很複雜
- 先手寫每一步執行步驟, 最後才歸納成演算法, 然後才實作, 並且分成多個 function 來處理細節
- 簡化 case, 優先處理簡化版本

#### 4. Smallest Substring Containing

- 困難, 有一個搜尋字串時的特殊技巧值得學會 (sliding window), 使用兩個一前一後的 pointer 一次只移動一個
- 使用到兩個 pointers, left 與 right,
  - 尚未找到 substring 時由 right 往前尋找
  - 找到 substring 後移動 left 來縮短, 直到又不符合 substring 時

#### 5. Longest Balanced Substring

- 困難, cases 很多, 最佳解不容易想到
- 試著思考所有能儲存的東西, 並且觀察是否有用
- brute force, T: O(n^3), S: O(n)
- 方法 1. T: O(n), S: O(n)
  - 使用 stack 儲存 index, 並且計算 diff 取得距離
- 方法 2. T: O(n), S: O(1),
  - 最佳解法: 只記錄 opening 與 closing 的數量, 並且要執行由左至右和由右至左兩次, 才能包覆所有的 cases

---

### 第十七章 - Stacks : Hard and Very Hard 2

Tips:

- 必須學著自己找 edge cases examples, 可以從 operator 的各種情況分類

#### 1. Shortest Path

- 困難, 要考慮的 cases 非常多, 很難一次完成, 必須經過多個 edge cases 來修正
- key points:
  1. path 是以 '/' 作為間隔的, 因此可以直接 `split('/')` 再來做處理
  1. 思考所有合法的 path 開頭, 可以分類成 `/`, `../`, others related path
  1. edge case, 以 root 開頭的 absolute path
  1. edge case, 以 `../` 開頭的 related path
  1. 在前項沒有東西時遇到 `..` 則要加入相對父層路徑 `../`
  1. 前項是 root `/` 時遇到 `..` 則保持 root `/`
- 必須學著自己找 edge cases examples, 可以從 operator 的各種情況分類

#### 2. Largest Rectangle Under Skyline

- 困難, 最佳解想不到, 即使知道使用 stack 仍然想不到解法
- Brute force T: O(n^2)
- 最佳解使用 stack 儲存 index of strict order of value
  - 利用這個條件, 嚴格小於, 可以在適當的時機找到指定 height 的極右與極左位置 (即 width 長度)
  - 這樣就可以一次性計算並且與最大值比較
  - 複雜度是 T: O(n), S: O(n), n for length of buildings

---

### 第十八章 - Heaps : Hard and Very Hard 4

Tips:

- Heap 是一種特殊的 binary tree, 可以利用 array 儲存
- 問題涉及變動的極大極小值或想要降低排序時間時, 可以嘗試使用 heap

#### 1. Continuous Median

- 第一個想法是建立 sorted array, 這樣 insert 是 T: O(n), get median 是 T: O(1), S: O(n)
- 想到一個不需要排序, 但是可以取出特定的值, 最大值或最小值就是 heap
- 同時建立 max heap 與 min heap 來處理中間值的左半與右半
- 使用 Heap 讓 insert 複雜度降成 T: O(log(n)), S: O(n)

#### 2. Sort K-Sorted Array

- 以 min-heap 來 sort 可以降低時間複雜度從 `n * log(n)` 到 `n * log(k)`

#### 3. Laptop Rentals

- 經典題目, 區間覆蓋問題, 記得最佳解為 T: O(n \* log(n)), S: O(n)
- 出現時間相關問題時, 可以先嘗試排序來觀察是否有幫助, sort first, T: O(n \* log n)
- 由於排序所需的複雜度是 T: O(n \* log(n))
- 每個欄位做 Heap insert 所需的總共複雜度也是 T: O(n \* log(n))
- 方法 2. 不需要 heap, 很聰明的方式, 只需要知道 start times 與 end times 不需要管 interval
  - 分別排序 start times 與 end times 即可知道在每個 end times 歸還前還有幾個 start times 正在運行 (即此題的佔用數)
  - start 代表開始租, ends 代表歸還
- 好好觀察問題, 嘗試排序永遠適合

#### 4. Merge Sorted Array

- 經典題目, merge sorted array
- 優於直接 sort 整個 array 的優勢在於 array 的數量 k 遠小於總數 n
- 使用 heap 的複雜度會是 T: O(n \* log(k)), S: O(n + k)
- 通常這題會提供限制 1. 不能使用 sort, 2. array 的數量 k 遠小於總數 n
- 記得複雜度分析

---

### 第十九章 - Linked Lists : Hard and Very Hard 9

Tips

- linked list 除了記錄節點之外, 也可以記錄走過的長度
- 嘗試紀錄移動的距離

#### 1. Find Loop

- 經典題目, 尋找 loop 的起點
- 解法非常巧妙聰明
- 利用**移動的距離**尋找出關係, 紀錄移動距離!!
- 先以 fast slow pointer 來找到交會點, 從交會點與起點開始一起走直到相遇則是 loop 起點
  - 可以通過畫圖, 找出這個關係, fast 的移動長度 - slow 的移動長度 = loop 的長度
  - 假設 D 為起點到 loop 起點的距離, P 為起點到交會點的距離
  - slow 移動 D + P, fast 移動 2D + 2P 並且剛好 D + P 為 loop 的長度, 因此在重走 D 即會在 loop 起點相遇

#### 2. Reverse Linked List

- 經典題目
- 直接直線執行即可, 轉換時想到 swap
- 沿路執行依序轉換順序

#### 3. Merge Linked List

- 簡單, 依序執行每次都選出最小的即可
- **複雜度分析**, 基本走過一次因此是 T: O(n + m), S: O(1)

#### 4. Shift Linked List

- 簡單, 仔細處理細節即可
- 畫圖然後舉例思考所需
- 寫程式時注意 edge cases

---

### 第二十章 - Binary Trees : Hard and Very Hard 7

Tips:

- 先舉多個不同的 cases 為例子再想演算法, 否則常有不能處理的情況
- tree 問題可以嘗試建立 parent pointer table 來協助處理, 變成類似 graph 問題, 需要額外的 O(n) space

#### 1. Max Path Sum In Binary Tree

- 問題 spec 需要問清楚, 1. 值是否有負的, 2. 可以不取嗎?
- 關鍵在於不一定要過 root, 任意子樹也可能有最大值
- 還有一個關鍵的 edge cases 當所有值都是負的時, 則預設值不能為 0
- 比想像中困難, 需要考慮多種情況

#### 2. Find Nodes Distance K

- 困難, 但是有趣的題目, 很多不同的 cases, 要處理相對複雜的 recursive program
- 先舉多個不同的 cases 為例子再想演算法, 否則常有不能處理的情況
- tree 問題可以嘗試建立 parent pointer table 來協助處理, 變成類似 graph 問題, 需要額外的 O(n) space

---

### 第二十一章 - Binary Search Trees : Hard and Very Hard 3

Tips:

- 沒想法時試著操作資料, 然後查看是否有用

#### 1. Same BSTs

- 此題限制不能建立 BST 來比較, 否則最佳解則是直接建立 BST 然後比較
- 注意複雜度分析
- 方法 1. 持續分割成左半與右半, 然後遞迴比較, T: O(n^2), S: O(n^2)
- 方法 2. 較複雜, 但是可以降低空間複雜度, T: O(n^2), S: O(d), d for depth of bst
  - 學習這個技巧:
  - 傳入上一層的節點作為 bound value, 這樣就不需要傳入完整的 array 而是重新正確的搜尋出所需的比較值
  - 並且以 index 取代完整的 array

#### 2. Validate Three Nodes

- 簡單直接執行檢查即可, 記得利用 BST 的搜尋
- while 版只需要 S: O(1), recursive 版需要 S: O(log(n))

#### 3. Right Smaller Than

- brute force 很簡單
- 要找出最佳解規則很不容易, 因為需要持續更新, 以反序建立特殊的 binary search tree 來實現

---

### 第二十二章 - Tries : Hard and Very Hard 1

Tips:

#### 1. Multi String Search

- 有趣的題目, 有很多種解決方式不同的複雜度
- 應該詳細的分析複雜度, 更多的變數來精確估計
- 最佳解: 反過來以 small strings array 建立 trie 然後以 big string char 進行比對
- 次解為: 以 big string 建立 suffix trie 然後以 small strings 搜尋

---

### 第二十三章 - Graphs : Hard and Very Hard 5

Tips:

#### 1. Boggle Board

- 不困難但是程式寫起來有點長
- 如同其他字串比較, 使用 trie 來儲存要比較的字串
- 要檢查 8 個方向並且不能採用已經拜訪過的

---

### 第二十四章 - Recursion : Hard and Very Hard 7

Tips:

- **可以儲存: 目前搜尋到的目標數量**, 以數量來判斷是否找齊
- 必須看出 recursive 的行動模式然後以 caching 提升速度
- 對於遞迴一定要想到 cache 來提升速度

#### 1. Lowest Common Manager

- 要討論好, 特例的處理情況才進行實作
- 與尋找最近的共同父層問題等價
- 樹狀問題以各層的子樹來觀察看看是否有用
- **可以儲存: 目前搜尋到的目標數量**, 以數量來判斷是否找齊

#### 2. Interweaving Strings

- 注意複雜度分析, 可以以 worst case 舉例計算
- 必須看出 recursive 的行動模式然後以 caching 提升速度
- 沒有 cache 是 T: O(2^(n + m)) worst case
- 有 cache 是 T: O(n \* m)

---

### 第二十五章 - Sorting : Hard and Very Hard 5

---

### 第二十六章 - Searching : Hard and Very Hard 4

---

### 第二十七章 - Dynamic Programming : Hard and Very Hard 14

---

### 第二十八章 - Famous Algorithms : Hard and Very Hard 4

---
