## 寫程式前就該懂的演算法

### Grokking algorithms, Aditya Y. Bhargava 中文版, Computer Science / Algorithm

---

第一章 - 演算法概述

第二章 - 選擇排序演算法

第三章 - 遞迴演算法

第四章 - 快速排序演算法

第五章 - 雜湊表

第六章 - 廣度優先演算法

第七章 - 代克思托演算法

第八章 - 貪婪演算法

第九章 - 動態規劃演算法

第十章 - K 最近鄰演算法

第十一章 - 繼續鑽研

---

### 第一章 - 演算法概述

- binary search
- big O

---

### 第二章 - 選擇排序演算法

- Array 陣列,
  - insert O(n),
  - get O(1),
  - delete O(n)
- Linked List,
  - insert O(1),
  - get O(n)
  - delete O(1)
- 選擇排序 selection sort
  - 一直取出最大值, 直到排序完成
  - O(n^2)

---

### 第三章 - 遞迴演算法

- 遞迴 recursive, 通常閱讀性更佳
- 迴圈 loop, 通常性能更佳
- Basic case 與 recursive case
- call stack
- stack, push 與 pop
- 遞迴與 call stack
  - 遞迴的實現方式
  - 會占用記憶體與可能產生 stack overflow
  - 優化方式是改成迴圈或在有支援尾端遞迴最佳化 (tail recursion) 時使用尾端遞迴實作

---

### 第四章 - 快速排序演算法

- Divide and conquer
  1. 找出基礎案例
  2. 找出如何縮減原有案例到基礎案例
- 會自然而然形成遞迴解
- 如果是陣列問題時, 可以先思考空陣列或只有一個元素的陣列的基礎情況
- 可以藉由學習函數式程式語言 functional programming language 來更深入的理解遞迴, 推薦學習 Haskell
- Quick Sort 快速排序
  - 以 Divide and conquer 去做思考
  - 基礎案例是空陣列, 一個元素, 兩個元素時
  - 縮減辦法是挑出一個 pivot 作為比較值, 分成 (partitioning) 大於比較值與小於比較值的兩個陣列
- 可以藉由 proof by induction 歸納法證明
- Quick Sort 平均執行時間是 O(n \* log(n)), worst case 是 O(n^2)
  - 討論最差的案例發生在什麼時候, 發生在 pivot 選取時每次都沒有產生適當的分割, 而是以類似 selection sort 一樣只分類出最小的
  - 越快進入基礎案例 (base case) 則 call stack 越小速度也越快, 理想情況下是 O(log(n)) 高度的 call stack
- Merge Sort 平均執行時間是 O(n \* log(n))
- 在時間複雜度都是相同的 big O 時, 就需要去考量常數細項 (constant) 帶來的影響
  - 例如 Quick Sort 與 Merge Sort 的比較

---

### 第五章 - 雜湊表

- hash function, 輸入為任意型態, 輸出為數字
  - 相同的 input 必須有相同的 output
  - 不同的 input 應該盡可能地擁有不同的 output
- hash table, 以 hash function 與 array 建立的資料結構
  - 等價名詞 Hash map, Map, Dictionary, Associative array
  - key-value pair
- 特點在 get 只要 O(1)
- 適合用於實現 cache
- collision, 即不同的 input 經過 hash function 後產生相同的 output 稱之為碰撞 (collision)
  - 解決方案之一為把碰撞的資料以 linked list 連接
  - worst case 會讓 hash table get 退化成 O(n)
- 使用 hash table 的重點在於選用好的 hash function 避免大量的 collision 產生導致效能退化
  - 例如使用 SHA function
- Load Factor, 內容數量 / hash table 容量, 避免過高 (> 0.7) 來防止 collision 產生

---

### 第六章 - 廣度優先演算法

- Breathe-First Search, BFS
  - 一層一層的向外探索
  - 一層一層的順序是存放在 queue 裡
  - 執行時間為 O( V + E ), V 為 vertex 點數, E 為 edge 邊數
- Graph algorithm, 圖演算法
- 最短路徑問題 Shortest-path problem
- Graph, 是由點 (Node) 與邊 (Edge) 形成的結構
  - 實現的資料結構有多種不同
- 有向圖 Directed graph, 無向圖 Undirected graph 取決於邊是否有方向性
- Queue, enqueue and dequeue
- Topological sort 拓樸排序
  - 依據有向圖建立的節點順序

---

### 第七章 - 代克思托演算法 Dijkstra's Algorithm

- Weighted Graph, 加權圖, 邊有數值
- Dijkstra's Algorithm 僅能解決無負值有向無環加權圖 (Directed acyclic weighted graph) 上的最短路徑問題
- Dijkstra's algorithm 持續更新到達每一節點的最小路徑值, 所有節點都經過後則完成
  - 要找出最短路徑需要在各節點在額外紀錄最短路徑時的 parent node 為何
- 有負值時要使用 Bellman-Ford Algorithm

---

### 第八章 - 貪婪演算法

- Greedy Algorithm
  - 每個步驟都尋求局部最佳解 (local optimal solution) 最後即得到全域最佳解 (global optimal solution)
  - 在可以使用貪婪演算法時通常就是最好的解法並且最容易撰寫
- 背包問題 Knapsack problem
  - 貪婪法無法取得最佳解
- 貪婪演算法 (Greedy Algorithm) 可以做為近似演算法 (Approximation Algorithm) 使用
- NP complete, 需要辨識出 NP 完全問題, 然後以近似演算法解決, 精確演算法耗時過長也無法找到快速解 (多項式時間)
  - 通常涉及窮舉且無法切割成子問題

---

### 第九章 - 動態規劃演算法

- Dynamic Programming
- 試著以子問題的最佳解來推導母問題最佳解, (子問題最佳解可以組合出母問題最佳解)
  - 因此通常需要儲存子問題的解 (需要佔用空間, 通常用到方格)
- 常見問題
  - 背包問題
  - 最大共用子字串
  - diff
  - 最短編輯距離

---

### 第十章 - K 最近鄰演算法

- K-nearest neighbors algorithm, KNN
  - 分類 grouping 與回歸 regression
  - 以新進值最靠近的 group 來決定他屬於哪類
  - K 為最近的近似點, 因此可以利用最近的 K 個點的結果作平均來當作推測值 (regression)
  - 用於水果分類?, 推薦系統
- Feature extraction, 特徵萃取,把特徵作為變量, 特徵數即為維度, 可以利用距離公式決定近似度
  - 因此選擇適當的特徵是非常重要的, 特徵即變量
- Regression, 回歸分析, 預測
- Training
- Naive Bayes Classifier, 以機率作為分類器

---

### 第十一章 - 繼續鑽研

- Tree
  - balanced tree
  - Red-Black tree
  - B-tree
  - Heap tree
  - Splay tree
- Inverted Index, 把搜尋值作為 hash table 的 key
- Fourier Transform 傅立葉轉換
- Parallel Algorithm 以平行運算執行的演算法
- Distributed Algorithm 分散式演算法
  - 例如 MapReduce
- Bloom Filter 布隆過濾器
  - Probabilistic Data Structure
  - 以機率為基礎的近似演算法
  - 通常可以優化執行速度或佔用空間
- SHA, Secure Hash Algorithm
  - 常用的 hash function
  - 可以以 SHA 值作為檔案是否相同的辨識參考
  - Locality-Sensitive Hash 局部敏感, 輸入值微小的差別也會讓 hash 值有巨大的變化, 避免以 pattern 嘗試反推的可能
- Diffie-Hellman Algorithm
  - 與 RSA 一樣的另一個非對稱式加密法 (asymmetric)
- Linear Programming 線性規劃
  - 最佳化演算法的類別
  - 單形演算法 Simplex Algorithm
