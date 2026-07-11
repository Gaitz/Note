## Tech Interview Handbook: the 3 month study plan

### [The 3 month study plan](https://www.techinterviewhandbook.org/coding-interview-study-plan/), ComputerScience/AlgorithmExercise

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

Array,

7 mins + 1 hour + 24 mins + 44 mins + 22 mins + 60 mins + 60 mins + 55 mins + 40 mins + 30 mins + 22 mins = 7 hours 4 mins

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

71 mins + 80 mins + 74 mins = 3 hours and 45 minutes

常用技巧

- Array 能用的技巧通常也適用於 string
- Counting characters
  - 通常使用 hash map
  - 紀錄字元所使用的 space complexity 取決於 input character set, 通常是 O(1), 因為字元集合是有限的且為常數
- String of unique characters
  - 操作在字元上具有唯一性的字串, 並且字元集合本身是常見的大小寫字母時
  - 可以通過 bit-wise 操作, 使用等同於字母集合數量的 bitmask 來進行儲存
  - 進行字串比較時, 可以通過 bit operator `&` 來進行
- Anagram
  - 同個字元內容但是經過 rearranging 的字串
  - 判別是否為 anagram
  - 方法 1, sorting, 需要花 T:O(n \* log n), S: O(n)
  - 方法 2, 計算字元的出現頻率 (frequency), 需要花 T: O(n), S: O(n) or O(1) 取決於實作
- Palindrome
  - 從兩個方向順序讀取都是相同的字串
  - 判別是否為 palindrome
  - 方法 1, reverse
  - 方法 2, two pointers, 分別從前後依序比對, 或者從中間點往外走依序比對
- 字串的比對, 可以使用 regular expression, 對效能有幫助

常見資料結構

- Trie/Prefix Tree
- Suffix Tree

常見演算法

- Rabin Karp, 用來搜尋 substring
- KMP, 用來搜尋 substring

基礎特性

- 字串就是以字元組成的 array

運算複雜度

- 因為字串就是 array 因此時間複雜度等同於 array 操作
- Access: O(1)
- Search: O(n)
- Insert: O(n)
- Remove: O(n)
- 與其他字串互動的複雜度, 假設原本字串長度為 n, 另一字串長度為 m
- Find substring: O(n \* m), 一般做法, 依據字串的特性, 可以通過其他演算法進行優化到 O(n + m), 例如: KMP 演算法
- 字串連接 (concatenating): O(n + m)
- Slice: O(m)
- Split (by token): O(n + m)

優點

缺點

該詢問的問題

- 字串的 input character set
- 是否包含數字
- case sensitively, 大小寫相關

注意

Corner cases

- 空字串
- 只有 1 ~ 2 個字元的字串
- 連續重複字元的字串, repeated
- 只含有不重複字元的字串, Strings with only distinct characters

Completed Practices

- [Valid Anagram](https://leetcode.com/problems/valid-anagram)
- [Valid Palindrome](https://leetcode.com/problems/valid-palindrome)
- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters)

---

Hash Table

64 mins + 26 mins

常用技巧

常見資料結構

常見演算法

基礎特性

- 基於 array 的一種抽象化實作
- 利用 hash function 轉換 key 成 array index
- 來形成能以 O(1) 進行 get 的 key value pair
- 常用於搜尋的 space-time tradeoff, 以 hash table 取代循序搜尋的其他資料結構, 搜尋從 O(n) 加速到平均 O(1)
- 處理 hash collisions 的常見方法
  - Separate chaining, 以 linked list 來處理
  - Open addressing, 依據某種方式尋找一個空的位置來存放

運算複雜度

- Average case
- Search: O(1)
- Insert: O(1)
- Remove: O(1)

優點

- 在平均的情況下, search, insert, delete 都是 O(1)
- 通常程式語言都內建實作並且支援 key 可以是任何型別

缺點

- worst case 時, search, insert, delete 會變成 O(n)

該詢問的問題

注意

Corner cases

Completed Practices

- [Two Sum](https://leetcode.com/problems/two-sum)
- [Ransom Note](https://leetcode.com/problems/ransom-note)

---

Recursion

常用技巧

- 常用於 permutation 和 tree 相關的問題
- Memorization
  - 因為遞迴結構會解構到 base cases 因此可能會有多項重複的函式執行, 很直覺的可以使用 memorization 來提升其效率

常見資料結構

- tree

常見演算法

基礎特性

- 每個遞迴演算法裡都必然會有的兩個部分
  - 1 base case
  - 2 breaking down
- base cases 所需的數量取決於 breaking down 時的呼叫結構
- 使用遞迴時, 是隱含的使用 stack 結構
- 有些程式語言會支援尾端遞迴最佳化 (tail-call optimization, TCO)

運算複雜度

優點

缺點

該詢問的問題

注意

- 必須要有 base case 千萬別漏掉
- 當問題被解構成太多層時, 可能會有 stack overflow 發生
  - JavaScript 的 stack size 取決於不同的執行環境
- 注意到所需的

Corner cases

- n = 0
- n = 1
- 依據 breaking down 的結構來確認必須有足夠多的 base cases

Completed Practices

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
