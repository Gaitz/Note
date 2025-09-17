## Algorithms

### Computer Science

---

Sorting

---

Bucket sort

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

---
