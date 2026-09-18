## Algorithms

### Computer Science

collection of algorithms that I learned

- 紀錄該演算法的效果和實現概念, 不需要提供程式碼, 但是要能提供足夠的想法在任何時候能實作

---

## Algorithm strategies and patterns

---

Divide and conquer

- 主要想法在於藉由較小範圍的子問題, 來建構出原問題的解, 會自然形成一種遞迴結構
  - 關鍵在於子問題的範圍會小於原問題, 並以子問題的解答來組合出原問題的解
- 把原問題分解層兩個範圍較小的子問題
- 類似 mathematical induction
- 分成三個步驟
  - **Divide**, 把原問題分解成相同問題, 但是更小的範圍的子問題, 理想上是子問題剛好是原問題的一半大小 (最小化遞迴層數)
  - **Conquer**, 遞迴子問題 (recursive case), 直到子問題足夠簡單可以被解決 (base case)
  - **Combine** (resolution), 利用子問題的解, 來產生原問題的解
- Bottom up
  - 先思考最小案例 (基礎情況), 在一步一步變複雜, 並且從中找到可以維持最佳解的結構
- Top down
  - 把主問題分成兩部分, 並且思考假設在已知所有子問題的解答時, 如何產生主問題的最佳解

Backtracking

- 適用於**條件滿足型的窮舉問題**, 屬於遞迴窮舉解法的優化方案, 通常可以在計算複雜度與空間複雜度上優化, 尤其是空間複雜度上
- 遞迴的每一層來處理當層的 candidate 進行判斷和是否需要再次延伸
- 分成兩個步驟
  - **Check** (is the candidate failed or accepted)
  - **Explore** every combination by recursion
- explicit backtrack
  - 在於在當前這層時, 就建立下一層的 candidate,
  - 因此在下層的遞迴函式回傳後, 在當前這層需要進行 backtrack 還原層這層原本的 candidate 來進行後續的處理
- 在遞迴探索時, 需要 **pruning** 來減少路線才是優化方案的關鍵

Greedy

- 逐步遞增, 在每個步驟都找出局部最佳解, 並以此往前推進最終得到全域最佳解
- 時間複雜度, 通常為 O(n) \* 尋找每個局部最佳解所需的時間複雜度

Dynamic Programming

- 屬於 Divide and conquer 的變種
- 通過儲存子問題的結果 (memorize), 依據特定的順序來推進, 得到更大的問題的解

---

## Algorithm Analysis and complexity

Complexity Ranking, fastest to slowest

- `O(1)`, constant time
- `O(α(n))`, inverse Ackermann function
- `O(log*(n))` iterated logarithm
- `O(log(n))` logarithm
- `O(sqrt(n))`
- `O(n)`, linear time
- `O(A(n))`, Ackermann function

Amortization / amortized

- 當一個昂貴的運算可以節省之後的運算時, 依據特定的順序來平均計算後得到的複雜度
- 注意: average case 與 amortized 是不一樣的
  - Average case 使用的是 random 或符合特定機率的分布 ( probability distribution )
  - Amortized 計算的是依據一個特定的執行順序, 最後產生的平均值結果
- 例如: Union-find 的 find operation; dynamic array 的動態配置

---

## Sorting

---

Bucket Sort

- 前提條件: 輸入值的區間是有限, 且可接受的數量時
- **當值區間是有限且可接受的數量時**
  - 常用於優化排序效能時使用, 時間複雜度最佳可以達到 O(n)
- 複雜度:
- 演算法實作:
  - 建立多個 bucket 並把輸入放入桶內
  - 排序非空的 bucket
  - 依據大小輸出 bucket 則得排序好的數值
- 優點:
  - 當 bucket 數量等同於輸入值的範圍區間相等時( k == n ), 最佳時間複雜度可以達到 O(n)
- 缺點:
  - 需要使用額外的空間, 空間複雜度為 O(n \* k), k 是 bucket 數量, n 是元素的數量
  - 最差的時間複雜度則會退回一般排序演算法的時間複雜度, T: O(n^2) 或者 T: O(n \* log n)

Quick Sort

- In-place 排序法, 採用 divide-and-conquer 建立
  - 性能的關鍵在於每次所選擇的 pivot 是否能產生大小相當的 partitions
- 複雜度:
  - Best, Average, T: O(n \* log n), S: O(log n)
  - Worst, T: O(n^2), S: O(n)
  - 額外的空間是遞迴所使用的
- 演算法實作概念:
  - Divide-and-conquer,
  - 通過選擇 pivot 並且每次決定該 pivot 位於排序後**最終位置**
  - 通過 partition 產生出, 小於 pivot 與大於等於 pivot 的兩個 partitions (divide)
  - 依序遞迴處理更小的 partitions 直到完成排序 (conquer)
  - 因為每次都是以 in-space swap 的方式完成, 所以不需要 combine 階段
- 演算法實作:
  - `Partition`
  - 選擇 pivot
  - 移動 pivot 至最右側, 方便之後實作
  - 初始化, 追蹤 pivot value 最終位置的 pointer
  - 從頭走訪, 比較大小, 以追蹤的 pointer 為中間點,
  - 並且移動元素 (swap), 逐漸區分出兩個 partitions, 最終形成 [ < pivot, pivot, >= pivot ] 的結構
- 優點:
  - 在實務上有優秀的性能, T: O(n \* log n) average and best, S: O(log n)
- 缺點:
  - 不是 stable 的排序演算法, 無法維持相等時的原位置順序
  - 需要額外的空間, 用於遞迴呼叫, average S: O(log n), worst S: O(n)
  - 在 pivot 每次都選擇到最糟的結果時, 複雜度會退化至 T:O (n^2), S: O(n)

---

## Searching

---

Binary Search

- 遇到**已經排序好的資料結構**並且**搜尋的方向跟排序大小有關係**時
  - Binary Search 是很好的搜尋工具, Time: O(log n)
- 前提條件:
  - Sorted

---

## Data structures

---

Min / max stack

- 可以隨時以 O(1) time complexity 讀取 min / max 的 stack

---

Disjoint Set / Union-find Forest / Union-find data structure / Merge-find Set

- 功能
  - 隨時知道 graph 中不相交的子集合個數, number of disjoint subsets
- 資料結構,
  - 把一個 graph 分成互相不相交的 (disjoint) subsets
  - 做法在於以每個 tree 的 root 來決定兩個元素是否所屬同一個 tree
- 底層資料結構
  - 一個追蹤所有 elements 對應 parent 的 array
  - 目的是用每個 tree 擁有不同的 root 來代表分別不同的 disjoint set
- 性能優化關鍵在於避免隨時走訪整個完整的 tree 來尋找對應的 set, 讓 T: O(n) 的走訪降低成 T: O(α(n)) amortized
  - 優化技巧在於 **shallow** 壓平原本的 tree
  - 1 Union by size or by rank, 讓兩個子樹依據大小, 把小樹接在大樹上, 會形成較為 balanced tree 而不會退化成 linked list
    - T: O(log n)
  - 2 Path compression, 把所有子節點都接到 root, 變成只有兩層的扁樹,
    - T: O(α(n)) amortized, `inverse Ackermann function`, 第一次需要完整走訪然後調整資料結構後, 其他次只需要向上走一層
- 提供的 members
  - `parent` array or other data structure
  - `size`, how many disjoint subsets
- 提供的 operators
- `find(x)`, FIND-SET(x), 尋找 x 元素所屬的集合
  - 通過尋找 x 所屬 tree 的 root
  - 通常配合 path compression 使用, 在第一次尋找後, 調整資料結構來優化未來執行
- `union(x, y)`, 結合 x 元素所屬的集合與 y 元素所屬的集合
  - union 合併兩個集合的策略可以分成依據集合大小 (by size) 或者有特定的排序系統 (by rank)
  - 通過結合兩個 tree 的 root 變成單一個 tree
- `make-set(x)`, constructor, 建立只有 x 一個元素的新的 disjoint set
- Union find algorithm
  - T: O(α(n)) amortized, `inverse Ackermann function`
- Path compression
  - 壓縮 tree 變成所有的節點都接著 root 的兩層樹
- 使用方式
  - 1 建立一個空的 Disjoint Set
  - 2 初始化, 以 `make-set(x)` function 為每個節點建立成一個 subset
  - 3 為每個 edge x-y 呼叫 `union(x, y)` function 來連結且合併所有關聯的 subset 以產生最終的結果
- 常用於
  - 解決 connectivity 問題
  - 作為 Kruskal's algorithm 解決 minium spanning tree 的底層關鍵

複雜度分析

空間複雜度

- Space: O(n) where n is the size of the graph, 用於建立 `parent` array

時間複雜度

- `find`, 以 merge by rank + path compression 時
  - T: O(α(n)) amortized, `inverse Ackermann function`
- `union`
  - T: O(α(n)) amortized, `inverse Ackermann function`
  - 主要因為會呼叫 `find`
- `union` 在 merge 的部分是 T: O(1), 只需要設定 parent node
  - 較為昂貴的操作在於 `find`, 在第一次尋找 parent 的時候, worst case 是 O(n), 發生在退化成 linked list 時

---

Min / Max Heap

- 資料結構,
  - Complete Binary Tree + Min Tree or Max Tree
- 功能,
  - 以 O(1) 可以取得 Min 或者 Max
- 時間複雜度
  - Insert, T: O(log n)
  - Remove min or max, T: O(log n)
- 實作
- Insert,
  - 1 把新的 element 放到 complete binary tree 的順序位置
  - 2 持續 bubbling up 直到符合 min tree 或 max tree 定義
- Remove min or max,
  - 1 移除 root, root 即是 min or max
  - 2 把現有的 last element, 即當前 complete binary tree 的最後一個位置的值, 移動到 root
  - 3 持續 trickle down 直到符合 min tree 或 max tree 的定義

---

## Specific Algorithms

---

QuickSelect

- 用來處理 k-th max / k-th min 問題
  - 原始演算法的回傳值是 k-th value
  - 但是可以延伸成為, 快速的取得前 K 大或者前 K 小的集合, 但不排序其結果
- 使用 quick sort 的 partition 但是不需要遞迴處理兩側, 因此可以變成 iterative algorithm
- 複雜度:
  - Best and Average, T: O(n), S: O(1)
  - Worst, T: O(n^2)
- 複雜度分析:
  - 理想上 ( best case ) 處理的次數是 n + n / 2 + n / 4 + ...
  - 套用等比級數和公式, S = a1 / ( 1 - r), 取得 S = n / (1 - (1/2)) = 2n
  - 因此, 最佳的複雜度是 T: O(2n) = O(n)
- 演算法實作概念:
  - 採用 quick sort 的 partition
  - 因為, 每次 partition 都能找到該次選擇的 pivot 值的最終排序位置, 並且分好兩邊的大小
  - 因此, 尋找 k min 或 k max, 就變成尋找目標的 pivot position
  - 因為, 尋找的是大小, 因此在 divide 階段就不需要搜尋兩邊, 只需要挑選 k 所在的分區即可
  - 因此時間複雜度會從 T: O(n \* log n) 的 quick sort 降到 T: O(n)
- 演算法實作:
- 優點:
  - 不需要完整排序就可以取得 k-th smallest / largest
  - Average T: (O(n))，比完整 sorting 的 (O(n\log n)) 更好
- 缺點:
  - in-space 處理, 會改變原本的順序
  - 取得的結果, 是沒有排序的

---

## Questions

---

Template

- title and brief introduction
- 複雜度:
- 演算法實作概念:
- 演算法實作:
- 優點:
- 缺點:
