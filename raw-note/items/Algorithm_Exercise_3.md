## AlgoExpert 140 Coding Interview Questions

### [AlgoExpert](https://www.algoexpert.io/questions), AlgorithmExercise

---

Easy and Medium

第一章 - Arrays : Easy and Medium 13

第二章 - Strings : Easy and Medium 8

第三章 - Stacks : Easy and Medium 3

第四章 - Heaps : Easy and Medium 1

第五章 - Linked Lists : Easy and Medium 4

第六章 - Binary Trees : Easy and Medium 6

第七章 - Binary Search Trees : Easy and Medium 7

第八章 - Tries : Easy and Medium 1

第九章 - Graphs : Easy and Medium 7

第十章 - Recursion : Easy and Medium 6

第十一章 - Sorting : Easy and Medium 4

第十二章 - Searching : Easy and Medium 3

第十三章 - Greedy Algorithms : Easy and Medium 4

第十四章 - Dynamic Programming : Easy and Medium 5

第十五章 - Famous Algorithms : Easy and Medium 1

Hard and Very Hard

第十章 - Arrays : Hard and Very Hard 10

第十六章 - Strings : Hard and Very Hard 5

第十七章 - Stacks : Hard and Very Hard 1

第十八章 - Heaps : Hard and Very Hard 3

第十九章 - Linked Lists : Hard and Very Hard 8

第二十章 - Binary Trees : Hard and Very Hard 6

第二十一章 - Binary Search Trees : Hard and Very Hard 2

第二十二章 - Tries : Hard and Very Hard 1

第二十三章 - Graphs : Hard and Very Hard 3

第二十四章 - Recursion : Hard and Very Hard 5

第二十五章 - Sorting : Hard and Very Hard 3

第二十六章 - Searching : Hard and Very Hard 4

第二十七章 - Dynamic Programming : Hard and Very Hard 12

第二十八章 - Famous Algorithms : Hard and Very Hard 4

---

## Easy and Medium

---

### 第一章 - Arrays : Easy and Medium 13

Hints:

- Index pointers
- 排序 T: O(N \* LogN), 排序後利用有序這個條件來更有效率地尋找解
- Hash table memory, 計算且儲存 S: O(N)
- 找出回傳的模式並且優先計算格式, 才補值
- 注意剩餘條件或迴圈跑完後的狀況, 除了中途正確的 return 外，特別注意最後的 return 應該回傳的內容
- 把問題 array 的值，依序加入思考每次的結果是否可以重用
- 檢查特殊案例與基本案例
- 嚴格思考問題定義與解的相關邏輯，也許有更簡單的作法

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

---

### 第二章 - Strings : Easy and Medium 8

---

### 第三章 - Stacks : Easy and Medium 3

---

### 第四章 - Heaps : Easy and Medium 1

---

### 第五章 - Linked Lists : Easy and Medium 4

---

### 第六章 - Binary Trees : Easy and Medium 6

---

### 第七章 - Binary Search Trees : Easy and Medium 7

---

### 第八章 - Tries : Easy and Medium 1

---

### 第九章 - Graphs : Easy and Medium 7

---

### 第十章 - Recursion : Easy and Medium 6

---

### 第十一章 - Sorting : Easy and Medium 4

---

### 第十二章 - Searching : Easy and Medium 3

---

### 第十三章 - Greedy Algorithms : Easy and Medium 4

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

### 第十七章 - Stacks : Hard and Very Hard 1

---

### 第十八章 - Heaps : Hard and Very Hard 3

---

### 第十九章 - Linked Lists : Hard and Very Hard 8

---

### 第二十章 - Binary Trees : Hard and Very Hard 6

---

### 第二十一章 - Binary Search Trees : Hard and Very Hard 2

---

### 第二十二章 - Tries : Hard and Very Hard 1

---

### 第二十三章 - Graphs : Hard and Very Hard 3

---

### 第二十四章 - Recursion : Hard and Very Hard 5

---

### 第二十五章 - Sorting : Hard and Very Hard 3

---

### 第二十六章 - Searching : Hard and Very Hard 4

---

### 第二十七章 - Dynamic Programming : Hard and Very Hard 12

---

### 第二十八章 - Famous Algorithms : Hard and Very Hard 4

---
