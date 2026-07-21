## Algorithms

### Computer Science

collection of algorithms that I learned

- 紀錄該演算法的效果和實現概念, 不需要提供程式碼, 但是要能提供足夠的想法在任何時候能實作

---

Algorithm strategies and patterns

---

Divide and conquer

- 主要想法在於藉由較小範圍的子問題, 來建構出原問題的解, 會自然形成一種遞迴結構
- 類似 mathematical induction
- 分成三個步驟
  - Divide, 把原問題分解成相同問題, 但是更小的範圍的子問題, 理想上是子問題剛好是原問題的一半大小 (最小化遞迴層數)
  - Conquer, 遞迴子問題 (recursive case), 直到子問題足夠簡單可以被解決 (base case)
  - Combine, 利用子問題的解, 來產生原問題的解
- Bottom up
  - 先思考最小案例 (基礎情況), 在一步一步變複雜, 並且從中找到可以維持最佳解的結構
- Top down
  - 把主問題分成兩部分, 並且思考假設在已知所有子問題的解答時, 如何產生主問題的最佳解

Backtracking

- 適用於**條件滿足型的窮舉問題**, 屬於遞迴窮舉解法的優化方案, 通常可以在計算複雜度與空間複雜度上優化, 尤其是空間複雜度上
- 遞迴的每一層來處理當層的 candidate 進行判斷和是否需要再次延伸
- 分成兩個步驟
  - Check (is the candidate failed or accepted)
  - Explore every combination by recursion
- explicit backtrack 在於在當前這層時, 就建立下一層的 candidate, 因此在下層的遞迴函式回傳後, 在當前這層需要進行 backtrack 還原層這層原本的 candidate 來進行後續的處理

---

Sorting

---

Bucket sort

- 前提條件: 輸入值的區間是有限, 且可接受的數量時
- **當值區間是有限且可接受的數量時**
  - 常用於優化排序效能時使用, 時間複雜度最佳可以達到 O(n)
- 建立多個 bucket 並把輸入放入桶內
- 排序非空的 bucket
- 依據大小輸出 bucket 則得排序好的數值
- 最差的時間複雜度則會退回一般排序演算法的時間複雜度, O(n^2) 或者 O(n \* log n)
- 優點:
  - 當 bucket 數量等同於輸入值的範圍區間相等時( k == n ), 最佳時間複雜度可以達到 O(n)
- 缺點:
  - 需要使用額外的空間, 空間複雜度為 O(n \* k), k 是 bucket 數量, n 是

---

Searching

---

Binary Search

- 遇到**已經排序好的資料結構**並且**搜尋的方向跟排序大小有關係**時
  - Binary Search 是很好的搜尋工具, Time: O(log n)
- 前提條件:
  - Sorted

---

Data structures

---

Min/max stack

- 可以隨時以 O(1) time complexity 讀取 min/max 的 stack

---
