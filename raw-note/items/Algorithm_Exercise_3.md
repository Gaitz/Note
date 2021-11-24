## AlgoExpert 140 Coding Interview Questions

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

- ***

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

- ***

### 第八章 - Tries : Easy and Medium 1

---

### 第九章 - Graphs : Easy and Medium 8

---

### 第十章 - Recursion : Easy and Medium 6

---

### 第十一章 - Sorting : Easy and Medium 4

---

### 第十二章 - Searching : Easy and Medium 3

---

### 第十三章 - Greedy Algorithms : Easy and Medium 5

---

### 第十四章 - Dynamic Programming : Easy and Medium 5

---

### 第十五章 - Famous Algorithms : Easy and Medium 1

---

## Hard and Very Hard

---

### 第十章 - Arrays : Hard and Very Hard 10

---

### 第十六章 - Strings : Hard and Very Hard 5

---

### 第十七章 - Stacks : Hard and Very Hard 2

---

### 第十八章 - Heaps : Hard and Very Hard 4

---

### 第十九章 - Linked Lists : Hard and Very Hard 9

---

### 第二十章 - Binary Trees : Hard and Very Hard 7

---

### 第二十一章 - Binary Search Trees : Hard and Very Hard 3

---

### 第二十二章 - Tries : Hard and Very Hard 1

---

### 第二十三章 - Graphs : Hard and Very Hard 5

---

### 第二十四章 - Recursion : Hard and Very Hard 7

---

### 第二十五章 - Sorting : Hard and Very Hard 5

---

### 第二十六章 - Searching : Hard and Very Hard 4

---

### 第二十七章 - Dynamic Programming : Hard and Very Hard 14

---

### 第二十八章 - Famous Algorithms : Hard and Very Hard 4

---
