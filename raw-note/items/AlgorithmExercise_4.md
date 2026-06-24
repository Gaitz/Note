## Tech Interview Handbook: the 3 month study plan

### [The 3 month study plan](https://www.techinterviewhandbook.org/coding-interview-study-plan/), AlgorithmExercise

---

Week 1 - 4: Topical study + practice

Week 1

Array

String

Hash Table

Recursion

Week 2

Week 3

Week 4

Week 5 - 12: In-depth practice

Week 5

Week 6

Week 7

Week 8

Week 9

Week 10

Week 11

Week 12

---

Week 1 - 4: Topical study + practice

---

Week 1, Array, String, Hash Table, Recursion

---

Array, 7 mins + 1 hour + 24 mins + 44 mins + 22 mins + 60 mins + 60 mins + 55 mins + 40 mins + 30 mins + 22 mins = 7 hours 4 mins

常用技巧

- Sliding window
  - 不會跨越對方的 two pointers 技巧
- Two pointers
- Traversing from the right
  - 嘗試從右側走訪
- Sorting the array
  - 排序是否有幫助
  - 但要記得排序是有成本的
- Precomputation
  - Prefix array and suffix array
- Index as a hash key
- Traversing the array more than once
  - 多次走訪
  - 不需要在單一次走訪中完成所有的事情
- 嘗試一項一項加入

基礎特性

- 連續相同型別的記憶體空間
- 主要關注於
  - 1 值的 index, position
  - 2 值本身
- 每個程式語言底層實作不同, 最主要的區別在於陣列大小能否自動動態增加

運算複雜度

- 需要額外注意的是實作細節, 此陣列是 static array 還是 dynamic array 會影響到部分運算的時間複雜度
- Set O(1)
- Get O(1)
- 初始化 O(n)
- Copy O(n)
- Insert O(n), 在 insert 是最結尾並且屬於 dynamic array 時, 通常可以優化為 O(1)
- Remove O(n), 在 remove 是最結尾的元素時, 是 O(1)
- dynamic array 的 insert from the end, 通過 amortized analysis 把最差的運算結果 O(n) 平攤至一般結果後, 得到 O(1) 的複雜度

優點

- 使用一個變數名稱就可以儲存多個同型別的資料
- 隨機存取快速 (Accessing), O(1)

缺點

- 在陣列**中間**進行插入和刪除是耗時的操作, 因為需要移動其他的元素
- 有些程式語言陣列大小不是動態變動的, 此時當需要操作大於原先初始化的數量, 則需要進行重建和複製, 這是費時的操作, O(n)

該詢問的問題

- 是否存在 duplicated elements, 以及如何影響解法
- 是否是已排序的資料

注意

- 操作 array indices 時, 要注意邊界問題
- slicing 與 concatenating 通常需要 O(n) 時間複雜度

Corner cases

- 空陣列
- 只有 1 個或 2 個元素的陣列
- 陣列中存在重複連續出現的元素 (repeated elements)
- 陣列中存在重複的元素 (duplicated elements)

Completed Practices

- [Two Sum](https://leetcode.com/problems/two-sum/)
- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
- [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

---

String

---

Hash Table

---

Recursion

---

Week 2

---

Week 3

---

Week 4

---

Week 5 - 12: In-depth practice

---

Week 5

---

Week 6

---

Week 7

---

Week 8

---

Week 9

---

Week 10

---

Week 11

---

Week 12

---
