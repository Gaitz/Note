## Competitive Programming

### Computer Science

---

### 練習方式

- 嘗試自行回答
- 紙上寫程式
- 紙上寫測試
- 電腦上實現
- 依據難度, 類型做練習
- 依據類型做題, 可以找出自己的弱項, 然後加強學習
- 永遠要詳細的描述空間與時間複雜度
- 紙筆優先

---

### 題目種類

- Array and String
- Linked List
- Stack and Queue
- Tree and Graph
- bit 計算
- Recursion
- Greedy Algorithms
- Dynamic Programming
- Sorting
- Searching
- Depth First Search (DFS)
- Breadth First Search (BFS)
- Hash Table
- Heap
- Binary Tree
- Binary Search Tree
- Tries
- Famous Algorithms
- Math
- Backtracking
- Divide and Conquer

---

### 通用 Tips

- 清楚問題的輸入與輸出的型別與可進行的操作
- 複雜流程應該被抽成有意義的函式, 然後組合成可閱讀的程式碼
- 觀察問題特性, 尋找獨特的優化方式
- Index pointers
- Hash table, 優化搜尋, T: O(1), S: O(N)
- Sort first, T: O(N \* LogN), 先排序
- Scan and find candidate, 搜尋尋找候選者
- Recursive, 遞迴解, 因為 call stack 的關係會產生額外的 space
- Backtracking, 一邊優化的遞迴解
- 遞迴中止條件放在最開頭, 來保障正確性
- 遞迴可以利用物件型別回傳多個資料
- 如果 case 結束記得 return 避免錯誤
- 完成前記得 trace code with example 找到可能沒處理到的 case.
- Immutable 與 mutable 如果只是 read 減少不必要的空間
- 紙筆優先
- 複雜的問題: 先手寫每一步執行步驟, 最後才歸納成演算法, 然後才實作, 並且分成多個 function 來處理細節
- 如果單一個迴圈或直接處理太困難, 試著不要一個迴圈做完, 而是分成多個步驟處理
- 試著達到與解相關的部分成果, 然後再一步一步變成真正的解
- 試著思考所有能儲存的東西, 並且觀察是否有用, 不管是得到最佳解或者是優化空間複雜度
- 沒想法時試著操作資料, 然後查看是否有用
- 必須學著自己找 edge cases examples, 可以從 operator 的各種情況分類
- 先舉多個不同的 cases 為例子再想演算法, 否則常有不能處理的情況

#### 解題思考流程

1. 仔細聽懂題目
1. 畫出範例
1. 說出暴力解, 解釋空間與時間複雜度
1. 最佳化
1. 逐步檢視, 仔細檢查思考出來的演算法
1. 實作程式碼
1. 測試

#### 最佳化的技巧

- BUD, 瓶頸, 不必要的工作, 重複的工作
- DIY, 實際手動操作範例
- 簡化與歸納
- 底條件與疊加, 會自動生成遞迴解法
- 資料結構腦力激盪, 嘗試思考常見的資料結構
- 最理想執行時間

#### 計算時間與空間複雜度

- 永遠要詳細的描述空間與時間複雜度
- 實際計算執行次數
- 正確區分變數
- 等加級數
- 等比級數
- while loop
- 遞迴
- 遞迴型複雜度分析可以畫出完整的樹狀結構來計算
- Recursive, 遞迴解, 因為 call stack 的關係會產生額外的 space
- 注意呼叫內部函式或已有函式的複雜度
- 記得字串尋找 (find) 比對 string matching 所需要的時間複雜度是 O(n + m), n, m 為分別的字串長度, KMP 演算法
- 複雜度分析可以嘗試分析實際的 input 可以得到更精準的複雜度
- 利用 worst case 實際計算複雜度

---

### 各類型 Tips

#### Array and String

- 利用 Hash Table: insert, search O(1), 利用 hash table 的搜尋與插入 O(1), 缺點是需要 O(n) 空間複雜度
- 利用 Sorted O(n log n), **思考排序過後是不是更容易處理**, 缺點是排序需要 O(n log n) 的時間複雜度
- 利用 字串連接, 觀察連接後是否更好處理
- 字串問題相關,
  - 字元編碼 (ASCII / Unicode)
  - 空白, 大小寫, 重複字元, 字串長度,
  - 排序
  - 字串連接, 自己與自己相連或與其他相連
- Index pointers, 處理陣列時, 使用 one pointer 或 two pointers 等等方式嘗試
- 嘗試排序 T: O(N \* LogN), 排序後利用有序這個條件來更有效率地尋找解
- Hash table memory, 計算且儲存 S: O(N)
- 找出回傳的模式並且優先計算格式, 才補值
- 注意剩餘條件或迴圈跑完後的狀況, 除了中途正確的 return 外，特別注意最後的 return 應該回傳的內容
- 把問題 array 的值，依序加入思考每次的結果是否可以重用
- 檢查特殊案例與基本案例
- 嚴格思考問題定義與解的相關邏輯，也許有更簡單的作法
- 依據定義尋找候選答案，然後再計算出最佳解
- 思考 bottleneck 原本的功能並且以更 tricky 的方式實現相同功能
- 字串就是陣列
- 遞迴解，肯定需要額外的空間複雜度
- 字元可以轉換成 ASCII code 或 Unicode 後做運算
- 在 JavaScript 中, 需要注意 code unit 與 code point 的差別在 UTF-16 中遇到擴充字元時。
- Hash table 優化搜尋
- **嘗試從左走訪陣列跟從右邊走訪陣列, 嘗試一次只做一部份的解最後才整合**
- **最佳化的兩種情況 1. 一次處理雙向, 2. 一次處理單向但是處理兩次, 最好兩種都想想看選擇出最簡單實作的**
- 圖形題, 先視覺化畫出實際的圖, 來觀察
- 沒有想法時, 先思考 brute force 然後減少重複的部分
- 試著儲存某些結果, 來觀察是否有用, 最後試著減少所使用的空間
- 資料的順序, 可以避免不必要的計算
- 試著以儲存 index 來處理字串問題, 而非儲存字串本身
- 計算 square 時, 試著使用 **two pointers** 逼近

#### Linked List

- 雙指標, 快指標剛好快一倍
- 圖解計算
- 思考遞迴解與迭代解
- 進位只有兩種可能 0, 1
- 注意長度不相等的時候
- 模組化, 抽離函式
- 補齊長度
- 嘗試記錄移動的距離

#### Stack and Queue

- Stack, 可以用於把遞迴演算法改成迭代演算法時使用
- Queue, 常用於廣度優先搜尋 BFS, 實現 Cache
- 遞迴中止條件放在最開頭, 來保障正確性
- Stack 與 Queue 可以用來儲存待處理的事項並且在適當的時機取出來處理

#### Heap

- Heap 是一種特殊的 binary tree, 可以利用 array 儲存
- 一個不需要排序 O(n \* log(n)) 但是可以取出特定的值的資料結構
- get O(1), 其他 operator 都是 O(log(n))
- **buildHeap** 的時間複雜度是 T: O(n) 而非 T: O(n \* log(n)), 學習實際的複雜度分析
- 問題涉及變動的極大極小值或想要降低排序時間時, 可以嘗試使用 heap
- 嘗試排序永遠適合

#### Tree and Graph

- 試著用 DFS 和 BFS 尋找有用的資訊
- 利用遞迴解決, 使用 bottom up 思考
- 利用遞迴解決, 使用 top down 思考
- 拓樸排序 topological sort, 建立順序有兩種, 從起點或從終點反推
- 詢問樹狀資料結構中是否有父節點的資訊
- tree 問題可以嘗試建立 parent pointer table 來協助處理, 變成類似 graph 問題, 需要額外的 O(n) space
- 注意 null 把它是為基礎案例
- 把樹或圖 pre-order 轉換成字串或陣列來處理
- 利用數量平衡機率產生隨機
- 二元搜尋走訪時間 O(log n) 比走訪完整的樹更快 O(n), 為思考優化時的參考
- 遞迴回傳多資料型態
- **可以儲存: 目前搜尋到的目標數量**, 以數量來判斷是否找齊

#### Hash map and trie

- Trie, suffix trie, 以 characters 做成的 hash map 可以用於實現以字首序搜尋
  - key point 有 end symbol 作為結尾

#### Recursion

- 遞迴型複雜度分析可以畫出完整的樹狀結構來計算
- 複雜度分析需要練習, 並不這麼直觀
- 對於遞迴一定要想到 cache 來提升速度
- 必須看出 recursive 的行動模式然後以 caching 提升速度
  - 例如 fibonacci number, interweavingStrings 計算

#### Sorting and Searching

- 記住所有常見的排序演算法實作邏輯與複雜度分析

#### Greedy Algorithms

- Greedy Algorithms: 每次都找出局部最佳解則最終結果為最佳解時適用
- 通常解法都很直觀並且適用時多為最佳解

#### Dynamic Programming

- Dynamic Programming 是以子問題的解來建立全域的解
- 持續追蹤目前的最佳解並且觀察目前最佳解與過去最佳解的關係, 找出可以推導的公式
- 適合在問題組合非常多種時, 可以先以非常小的問題慢慢建立起解答
- 針對 Dynamic Programming 的空間使用率, 可以藉由觀察每一次真正所需要使用到的範圍, 去做空間使用率的減少

---

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

---

### clever algorithms

- Maximum subarray sum,
  - **Kadane's algorithm**, `O(n)`, 依序加入動態配置 Dynamic Programming, 利用前項最佳解, 來推導當前最佳解
- Longest palindromic substring
  - **Manacher's algorithm**, `O(n)`,
