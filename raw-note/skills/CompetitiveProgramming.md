## Competitive Programming

### Computer Science

---

## My Game Plan

- 先看一輪所有的題目
- 解題應該由負擔最輕的開始, 做到最困難的
- 先思考所有可能的演算法, 選擇最笨的那種
  - 使用 My checklist 去思考可能的演算法
  - 演算法思考順序: Filtering (brute force) -> Generating
- 實際用數字計算, 時間複雜度, 空間複雜度, 特殊案例,
- 開始使用特殊案例建立演算法
- 開始撰寫, 同一時間只嘗試解決一題
  - 決定要使用的演算法
  - 建立 test case 案例
    - 一次只需要一個測試案例, 並且必須包含手動計算輸出值
  - 撰寫要使用的資料結構
  - 撰寫 input 的邏輯並且測試
  - 撰寫 output 的邏輯並且測試
  - Stepwise refinement, 先用註解, 撰寫出演算法邏輯的框架
  - 一次撰寫填入一個演算法區塊並且測試過
  - 使用 trivial test case 驗證整體的正確性
  - 嘗試破壞程式碼, 使用特殊案例來驗證正確性
  - 嘗試最佳化, 只有在需要的時候最佳化, 並且只最佳化到需要的程度, 並且必須保留之前所有可以運行的各種版本, 使用最極端的測試案例檢測實際的 runtime
- 草圖: 演算法, 複雜度, 相關的數字, 資料結構, tricky details

### 解題思考流程

1. 仔細聽懂題目
1. 畫出範例
1. 說出暴力解, 解釋空間與時間複雜度
1. 最佳化
1. 逐步檢視, 仔細檢查思考出來的演算法
1. 實作程式碼
1. 測試

---

## Checklists

### My checklist

- 1 Traveling the input
- 2 Sorted the input
- 3 Hashmap trick, (anything can be an input)
- 4 Use the constraint of input, output, value range, ...

### Strategies Checklist

- Brute force
- Greedy
- Two pointer / Three pointers
- Filtering vs. Generating
- Divide and conquer
  - 通常會自動形成 recursive 演算法
- Recursive
  - 思考三步驟 TRUST the function, find green box, find base case

### Data Structure and Operations

- String
- Array
- Stack

### Methods check list

- Greedy Algorithm,
  - 每個步驟都尋求局部最佳解 (local optimal solution) 最後即得到全域最佳解 (global optimal solution)
  - 也許不是最佳解但是可以快速找到近似解
- Divide and conquer,
  - Divide 原問題太難, 先切割成子問題
  - Conquer, 嘗試解決子問題
  - Combine, 組合子問題解答變成原問題解答
- Dynamic Programming,
  - 試著以子問題的最佳解來推導母問題最佳解, (子問題最佳解可以組合出母問題最佳解)
  - 因此通常需要儲存子問題的解 (需要佔用空間, 通常用到方格)
  - 可以視為 Divide and conquer + memorization
- NP complete
  - 辨識出無法以多項式時間解決的問題

#### 最佳化的技巧

- BUD, 瓶頸, 不必要的工作, 重複的工作
- DIY, 實際手動操作範例
- 簡化與歸納
- 底條件與疊加, 會自動生成遞迴解法
- 資料結構腦力激盪, 嘗試思考常見的資料結構
- 最理想執行時間

#### 個人常見錯誤

- !! 使用 while loop 時, 記得處理 index

---

## Details

### 題目種類

Basic

- Array and String
- Linked List
- Stack and Queue

Graph and Tree

- Tree and Graph
- Depth First Search (DFS)
- Breadth First Search (BFS)
- Heap
- Binary Tree
- Binary Search Tree
- Tries

Others

- bit 計算
- Hash Table
- Math

Particular Algorithms

- Sorting
- Searching
- Famous Algorithms

Algorithm Methodology

- Divide and Conquer
- Greedy Algorithms
- Dynamic Programming
- Recursion
- Backtracking

### 通用 Tips

Notices

- Input, Output
  - 清楚問題的輸入與輸出的型別與可進行的操作
- Readability and KISS
  - 複雜流程應該被抽成有意義的函式, 然後組合成可閱讀的程式碼
- Edge cases
  - 完成前記得 trace code with example 找到可能沒處理到的 case.
  - 必須學著自己找 edge cases examples, 可以從 operator 的各種情況分類
  - 檢查特殊案例與基本案例
- Recursive
  - 遞迴可以利用物件型別回傳多個資料
- Common errors
  - 遞迴中止條件放在最開頭, 來保障正確性
  - 如果 case 結束記得 return 避免錯誤
- Memory usage
  - Immutable 與 mutable 如果只是 read 減少不必要的空間

Tricks

- 1 Manually
  - 紙筆優先
  - 圖形題, 先視覺化畫出實際的圖, 來觀察
  - 複雜的問題: 先手寫每一步執行步驟, 最後才歸納成演算法, 然後才實作, 並且分成多個 function 來處理細節
- 2 Loop
  - 如果單一個迴圈或直接處理太困難, 試著不要一個迴圈做完, 而是分成多個步驟處理
- 3 Tricky points
  - 觀察問題特性, 尋找獨特的優化方式
  - 嚴格思考問題定義與解的相關邏輯，也許有更簡單的作法
- 4 Partial solutions
  - 試著達到與解相關的部分成果, 然後再一步一步變成真正的解
  - 4.1 return data structure first
    - 找出回傳的模式並且優先計算格式, 才補值
- 5 Store and computation
  - 試著思考所有能儲存的東西, 並且觀察是否有用, 不管是得到最佳解或者是優化空間複雜度
  - 沒想法時試著操作資料, 然後查看是否有用
  - 試著儲存某些結果, 來觀察是否有用, 最後試著減少所使用的空間
- 6 More cases
  - 先舉多個不同的 cases 為例子再想演算法, 否則常有不能處理的情況
- 7 Candidates, filtering algorithm
  - Scan and find candidate, 搜尋尋找候選者
  - 依據定義尋找候選答案，然後再計算出最佳解
- 8 Divide and conquer, dynamic programming, greedy algorithms
  - 把問題的值，依序加入思考每次的結果是否可以重用
- 9 Optimization
  - 思考 bottleneck 原本的功能並且以更 tricky 的方式實現相同功能
- 10 Brute force, naive solution
  - 沒有想法時, 先思考 brute force 然後減少重複的部分

### 計算時間與空間複雜度

- 永遠要詳細的描述空間與時間複雜度
- 正確區分變數
- while loop
- Recursive, 遞迴解, 因為 call stack 的關係會產生額外的 space
  - 遞迴解，肯定需要額外的空間複雜度

Tricks

- Manually
  - 複雜度分析可以嘗試分析實際的 input 可以得到更精準的複雜度
  - 實際計算執行次數
  - 遞迴型複雜度分析可以畫出完整的樹狀結構來計算
- Worst cases
  - 利用 worst case 實際計算複雜度
- Calculation
  - 等加級數
  - 等比級數
- Common cases
  - 記得字串尋找 (find) 比對 string matching 所需要的時間複雜度是 O(n + m), n, m 為分別的字串長度, KMP 演算法
- Common errors
  - 注意呼叫內部函式或已有函式的複雜度

### 各類型 Tips

#### Array and String

Basics

- 字串就是陣列
- 字串問題相關,
  - 字元編碼 (ASCII / Unicode)
  - 空白, 大小寫, 重複字元, 字串長度,
  - 排序
  - 字串連接, 自己與自己相連或與其他相連
- 利用 Hash Table: insert, search O(1), 缺點是需要 O(n) 空間複雜度

String

- Common data structures
  - Trie/Prefix tree
  - Suffix tree
- Famous algorithms
  - `Rabin Karp algorithm`, search for substring with a rolling hash
  - `KMP algorithm`, search for substring, Time: , Space:

Notices

- Hash
  - Hash table memory, 計算且儲存 S: O(N)
- Common errors
  - 注意剩餘條件或迴圈跑完後的狀況, 除了中途正確的 return 外，特別注意最後的 return 應該回傳的內容
  - 在 JavaScript 中, 需要注意 code unit 與 code point 的差別在 UTF-16 中遇到擴充字元時。
- String input
  - 詢問 case sensitivity
  - 詢問 string character encoding
  - 詢問 string input character set

Tricks

- 1 sort
  - 嘗試排序 T: O(N \* LogN), 排序後利用有序這個條件來更有效率地尋找解
  - 利用 Sorted O(n log n), **思考排序過後是不是更容易處理**, 缺點是排序需要 O(n log n) 的時間複雜度
  - 資料的順序, 可以避免不必要的計算
- 2 concat
  - 利用 字串連接, 觀察連接後是否更好處理
  - concat take O(n) time complexity
- 3 go from two side
  - **嘗試從左走訪陣列跟從右邊走訪陣列, 嘗試一次只做一部份的解最後才整合**
  - **最佳化的兩種情況 1. 一次處理雙向, 2. 一次處理單向但是處理兩次, 最好兩種都想想看選擇出最簡單實作的**
  - 3.1 prefix and postfix
- 4 Hash
  - Hash table 優化搜尋
- 5 index and pointers
  - Index pointers, 處理陣列時, 使用 one pointer 或 two pointers 等等方式嘗試
  - 試著以儲存 index 來處理字串問題, 而非儲存字串本身
  - 計算 square 時, 試著使用 **two pointers** 逼近
- 6 to Unicode code points
  - 字元可以轉換成 ASCII code 或 Unicode 後做運算
- 7 Two pointers and sliding window technique

Edge cases and corner cases

- String
  - empty string
  - string with one or two char
  - with repeated char
  - with only distinct char
- Array
  - empty array
  - array with one or two elements
  - repeated elements
  - duplicated elements in the sequence

#### Linked List

- 模組化, 抽離函式

Notices

- 進位只有兩種可能 0, 1
- 注意長度不相等的時候

Tricks

- 圖解計算
- 雙指標 (two pointer), 快指標剛好快一倍
- 思考遞迴解與迭代解
- 補齊長度
- 嘗試記錄移動的距離

#### Stack and Queue

Notices

- 遞迴中止條件放在最開頭, 來保障正確性

Tricks

- Stack, 可以用於把遞迴演算法改成迭代演算法時使用
- Queue, 常用於廣度優先搜尋 BFS, 實現 Cache
- Stack 與 Queue 可以用來儲存待處理的事項並且在適當的時機取出來處理

#### Heap

Notices

- Heap 是一種特殊的 binary tree, 可以利用 array 儲存
- 一個不需要排序 O(n \* log(n)) 但是可以取出特定的值的資料結構
- get O(1), 其他 operator 都是 O(log(n))
- **buildHeap** 的時間複雜度是 T: O(n) 而非 T: O(n \* log(n)), 學習實際的複雜度分析

Tricks

- 問題涉及變動的極大極小值或想要降低排序時間時, 可以嘗試使用 heap
  - 降低 sorting 時間時, 尋求極大值, 極小值時
- 嘗試排序永遠適合

#### Tree and Graph

Notices

- 詢問樹狀資料結構中是否有父節點的資訊
- 注意 null 把它視為基礎案例

Tricks

- 試著用 DFS 和 BFS 尋找有用的資訊
- 利用遞迴解決, 使用 bottom up 思考
- 利用遞迴解決, 使用 top down 思考
- 拓樸排序 topological sort, 建立順序有兩種, 從起點或從終點反推
- tree 問題可以嘗試建立 parent pointer table 來協助處理, 變成類似 graph 問題, 需要額外的 O(n) space
- 把樹或圖 pre-order 轉換成字串或陣列來處理
- 二元搜尋走訪時間 O(log n) 比走訪完整的樹更快 O(n), 為思考優化時的參考
- 遞迴回傳多資料型態
- 利用數量平衡機率產生隨機
- **可以儲存: 目前搜尋到的目標數量**, 以數量來判斷是否找齊

#### Hash map and trie

Notices

- Trie, suffix trie, 以 characters 做成的 hash map 可以用於實現以字首序搜尋
  - key point 有 end symbol 作為結尾

Tricks

#### Recursion

Notices

- Recursive, 遞迴解, 因為 call stack 的關係會產生額外的 space
- Backtracking, 一邊優化的遞迴解
- 遞迴型複雜度分析可以畫出完整的樹狀結構來計算
- 複雜度分析需要練習, 並不這麼直觀

Tricks

- 對於遞迴一定要想到 cache 來提升速度
- 必須看出 recursive 的行動模式然後以 caching 提升速度
  - 例如 fibonacci number, interweavingStrings 計算

#### Sorting and Searching

Notices

Tricks

- 記住所有常見的排序演算法實作邏輯與複雜度分析

#### Greedy Algorithms

Notices

- Greedy Algorithms: 每次都找出局部最佳解則最終結果為最佳解時適用
- 通常解法都很直觀並且適用時, 通常都是最佳解

Tricks

#### Dynamic Programming

Notices

- Dynamic Programming 是以子問題的解來建立全域的解
- 持續追蹤目前的最佳解並且觀察目前最佳解與過去最佳解的關係, 找出可以推導的公式

Tricks

- 適合在問題組合非常多種時, 可以先以非常小的問題慢慢建立起解答
- 針對 Dynamic Programming 的空間使用率, 可以藉由觀察每一次真正所需要使用到的範圍, 去做空間使用率的減少

### Specific Algorithms

#### clever algorithms

- Maximum subarray sum,
  - **Kadane's algorithm**, `O(n)`, 依序加入動態配置 Dynamic Programming, 利用前項最佳解, 來推導當前最佳解
- Longest palindromic substring
  - **Manacher's algorithm**, `O(n)`,

---

## References

### Practice Resources:

- USACO TRAINING
- codeforces problem set

### 練習方式

- 嘗試自行回答
- 紙上寫程式
- 紙上寫測試
- 電腦上實現
- 依據難度, 類型做練習
- 依據類型做題, 可以找出自己的弱項, 然後加強學習
- 永遠要詳細的描述空間與時間複雜度
- 紙筆優先

### Programming Languages

#### C++

- STL
  - `vector`
  - `set`
  - `tuple`
  - `sort()`

---
