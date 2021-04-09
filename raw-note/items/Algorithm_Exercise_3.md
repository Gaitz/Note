## AlgoExpert 140 Coding Interview Questions

### [AlgoExpert](https://www.algoexpert.io/questions), AlgorithmExercise

---

Easy and Medium

第一章 - Arrays : Easy and Medium 14

第二章 - Strings : Easy and Medium 9

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

第十三章 - Greedy Algorithms : Easy and Medium 5

第十四章 - Dynamic Programming : Easy and Medium 5

第十五章 - Famous Algorithms : Easy and Medium 1

Hard and Very Hard

第十章 - Arrays : Hard and Very Hard 10

第十六章 - Strings : Hard and Very Hard 5

第十七章 - Stacks : Hard and Very Hard 2

第十八章 - Heaps : Hard and Very Hard 4

第十九章 - Linked Lists : Hard and Very Hard 8

第二十章 - Binary Trees : Hard and Very Hard 6

第二十一章 - Binary Search Trees : Hard and Very Hard 3

第二十二章 - Tries : Hard and Very Hard 1

第二十三章 - Graphs : Hard and Very Hard 4

第二十四章 - Recursion : Hard and Very Hard 6

第二十五章 - Sorting : Hard and Very Hard 4

第二十六章 - Searching : Hard and Very Hard 4

第二十七章 - Dynamic Programming : Hard and Very Hard 13

第二十八章 - Famous Algorithms : Hard and Very Hard 4

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

### 第二章 - Strings : Easy and Medium 9

Hints:

- 字串就是陣列
- 遞迴解，肯定需要額外的空間複雜度
- 字元可以轉換成 ASCII code 或 Unicode 後做運算
- 在 JavaScript 中, 需要注意 code unit 與 code point 的差別在 UTF-16 中遇到擴充字元時。
- Hash table 優化搜尋

#### 15. Palindrome Check

- 方法一, two pointers, T: O(N), S: O(1)
- 方法二, recursive, T: O(N), S: O(N), 每次呼叫都會儲存一次新的 string 因此空間複雜度是 O(N)

#### 16. Caesar Cipher Encryptor

- 方法一, 利用紙筆計算找出計算移動後正確的 char code 公式，然後依序執行。T: O(N), S: O(N), N for string.length, 題目要求回傳新的字串因此佔用空間複雜度 N

#### 17. Run-Length Encoding

- 方法一, pre 放在迴圈外，T: O(N), S: O(N)，程式較複雜
- 方法二, pre 放在迴圈內，每次都讀取 pre 與 current, T: O(N), S: O(N), 程式較簡單

#### 18. Generate Document

- 方法一, Force Brute, 每次在迴圈裡尋找後刪除用過的，T: O(N \* M), S: O(1), N 為 characters.length, M 為 document.length
- 方法二, 使用 hash table 取代搜尋, T: O(N + M), S: O(N), N 為 characters.length, M 為 document.length

#### 19. First Non-Repeating Character

- 方法一, Force Brute, double `for`, T: O(N^2), S: O(1)
- 方法二, hash table, T: O(N), S: O(1), N for string.length, 空間複雜度為 O(1) 因為已經指定字元集合最多為 26 個

#### 20. Longest Palindromic Substring

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

### 第十九章 - Linked Lists : Hard and Very Hard 8

---

### 第二十章 - Binary Trees : Hard and Very Hard 6

---

### 第二十一章 - Binary Search Trees : Hard and Very Hard 3

---

### 第二十二章 - Tries : Hard and Very Hard 1

---

### 第二十三章 - Graphs : Hard and Very Hard 4

---

### 第二十四章 - Recursion : Hard and Very Hard 6

---

### 第二十五章 - Sorting : Hard and Very Hard 4

---

### 第二十六章 - Searching : Hard and Very Hard 4

---

### 第二十七章 - Dynamic Programming : Hard and Very Hard 13

---

### 第二十八章 - Famous Algorithms : Hard and Very Hard 4

---
