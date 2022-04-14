## Competitive Programmer’s Handbook

### _Competitive Programmer’s Handbook_, _Antti Laaksonen_, [Online Book](https://cses.fi/book/book.pdf), ComputerScience/CompetitiveProgramming

---

Basic techniques

第一章 - Introduction

第二章 - Time complexity

第三章 - Sorting

第四章 - Data structures

第五章 - Complete search

第六章 - Greedy algorithms

第七章 - Dynamic programming

第八章 - Amortized analysis

第九章 - Range queries

第十章 - Bit manipulation

Graph algorithms

第十一章 - Basics of graphs

第十二章 - Graph traversal

第十三章 - Shortest paths

第十四章 - Tree algorithms

第十五章 - Spanning trees

第十六章 - Directed graphs

第十七章 - Strong connectivity

第十八章 - Tree queries

第十九章 - Paths and circuits

第二十章 - Flows and cuts

Advanced topics

第二十一章 - Number theory

第二十二章 - Combinatorics

第二十三章 - Matrices

第二十四章 - Probability

第二十五章 - Game theory

第二十六章 - String algorithms

第二十七章 - Square root algorithms

第二十八章 - Segment trees revisited

第二十九章 - Geometry

第三十章 - Sweep line algorithms

---

Basic techniques

---

### 第一章 - Introduction

- 分成兩個部分 1. 演算法設計 2. 演算法實作
- 演算法設計, 有效率且正確
  - 通常建立在已有的演算法技巧 + 新的 insight, 因此學習現有的演算法技巧是重要的
- 演算法實作, 正確且快速
- 程式語言選擇, C++ (快速且有好用的函式庫), Python (有大數函式庫優勢)
- I/O 有時候是瓶頸
  - 字串或數字包含空格與斷行
  - 以檔案呈現

Working with Numbers

- Integer, 通常使用 `int` 32-bit 即可, 更長可以使用 `long long` 64-bit
  - 32-bit 運算時轉換到 64-bit, 需要額外使用 `(long long)` 轉換型別, 或者直接把 `int` 改掉, 全用 `long long`
  - **g++** 還有更大的 128-bit 整數型別, `__int128_t` 不過比賽通常不能使用
- Modular 運算, `%`
- Floating point numbers, `double` 64-bit, `long double` 80-bit
  - 注意浮點數運算時的 precision error 誤差值,
  - 因此在比較浮點數時, 要使用 `abs(a-b) < 1e-9` 之類的方式, **1e-9** 為假定的微小值, 可以依據精準度調整

Shortening code

- 為了在 CP 中提升寫程式的速度, 因此會盡可能地減少所需要的輸入
- Type names, 以簡寫縮短型別的名稱,
  - Ex. `typedef long long ll`, 之後可以使用 `ll` 取代 `long long`
  - `typedef` 可以應用在其他更複雜的型別例如, `typedef vector<int> vi`
- Macros, 巨集, 在 compile 以前的字串替換
  - `#define`, 除了字串名稱替換之外
  - 甚至可以實現縮短語法, Ex. `#define REP(i,a,b) for (int i = 1; i <= b; i++)`
  - 然而, 有漏洞的 marco 用法會難以 debug, 需小心使用

Mathematics

- 數學對於 CP 來說是非常重要的, 需要有好的數學技巧
- Sum formula
  - **Faulhaber's formula**
  - arithmetic progression, 等差級數和 formula, 梯形公式 `n * (a + b) / 2`
  - geometric progression, 等比級數和 formula, `(b * k - a) / (k - 1)`, a 首項, b 末項, k 公比
  - harmonic sum,
- Set theory
  - 空集合
  - intersection, `∩`
  - union, `∪`
  - complement,
  - difference, `A \ B = A ∩ B`
  - subset
  - 常見集合, **N**, **Z**, **Q**, **R**
- Logic
  - `true`, `false`
  - negative, `¬`
  - conjunction, `∧`
  - disjunction, `∨`
  - implication, `⇒`
  - equivalence, `⇔`
  - predicate, function of logic, return `true`, `false`
  - `∀` (for all), `∃` (exist)
- Function,
  - floor, ceiling function
  - `min`, `max`
  - Factorial, `n!`, define `0! = 1`, `n! = n * (n - 1)!`
  - Fibonacci numbers, define `f(0) = 0, f(1) = 1, f(n) = f(n-1) + f(n-2)`
    - Binet's formula, `f(n) = ((1 + sqrt(5))^n - (1 - sqrt(5))^n) / (2^n * sqrt(5))`
- Logarithms,
  - `logk(x)`
  - `logk(ab) = logk(a)+logk(b)`, 乘法 = 加法
  - `logk(x^n) = n·logk(x)`, 乘法 = 加法
  - `logu(x) = logk(x) / logk(u)`, 換底公式
  - natural logarithm, `ln(x)`, 以 `e` 為底的對數

Contests and resources

- IOI, International Olympiad in Information, 高中學生的, 以國家為單位
- ICPC, International Collegiate Programming Contest, 大學生的
- Online contests,
  - **Codeforces**, **AtCoder**, **CS Academy**, **HackerRank**, **Topcoder**
  - **Facebook Hacker Cup**, **Google Code Jam**, **Google Kickstart**, **Yandex.Algorithm**
- Books
  - _S. S. Skiena and M. A. Revilla: Programming Challenges: The Programming Contest Training Manual_
  - _S. Halim and F. Halim: Competitive Programming 3: The New Lower Bound of Programming Contests_
  - _K. Diks et al.: Looking for a Challenge? The Ultimate Problem Set from the University of Warsaw Programming Competitions_
  - _T. H. Cormen, C. E. Leiserson, R. L. Rivest and C. Stein: Introduction to Algorithms_
  - _J. Kleinberg and É. Tardos: Algorithm Design_
  - _S. S. Skiena: The Algorithm Design Manual_

---

### 第二章 - Time complexity

- 利用時間複雜度分析, 在實作之前比較演算法的速度
- Loops,
- 多個變數
- 遞迴

Complexity classes

- `O(1)`, constant-time
- `O(log(n))`, logarithmic
- `O(sqrt(n))`, square root algorithm
- `O(n)`, 多數最佳解的時間複雜度, 因為通常都需要走訪所有的輸入
- `O(n * log(n))`, 通常與排序 (sorting) 有關或者配合 `O(log(n))` 處理時間的資料結構
- `O(n^2)`, quadratic algorithm, 例如走訪所有的 pairs
- `O(n^3)`, cubic algorithm, 例如走訪所有的 triplets
- `O(2^n)`, 通常代表需要走訪所有的 subsets
- `O(n!)`, 例如走訪所有的 permutations
- **polynomial** 多項式時間是指時間複雜度最高是 `O(n^k)`, k 是常數, 被視為有效率的 (efficient) 演算法
- **NP-hard** 問題, 是重要的問題集合, 代表沒有多項式時間的演算法

Estimating efficiency

- 現在的電腦, **1 second** 內可以執行 **10^8** 左右的指令,
  - 配合時間複雜度分析, 以此預估預期的時間
- 1 second 不同複雜度的對應 input size
  - **n <= 10, O(n!)**
  - **n <= 20, O(2^n)**
  - **n <= 500, O(n^3)**
  - **n <= 5000, O(n^2)**
  - **n <= 10^6, O(n \* log(n)) or O(n)**
  - **n is large, O(1) or O(log(n))**
- 如果已知 input size 的情況下, 可以預估演算法的複雜度,
  - 並以此為提示思考演算法

範例 Maximum subarray sum

- `O(n^2)` to `O(n)`
- **Kadane's algorithm**, 依序加入動態配置 Dynamic Programming, 利用前項最佳解, 來推導當前最佳解

---

### 第三章 - Sorting

---

### 第四章 - Data structures

---

### 第五章 - Complete search

---

### 第六章 - Greedy algorithms

---

### 第七章 - Dynamic programming

---

### 第八章 - Amortized analysis

---

### 第九章 - Range queries

---

### 第十章 - Bit manipulation

---

Graph algorithms

---

### 第十一章 - Basics of graphs

---

### 第十二章 - Graph traversal

---

### 第十三章 - Shortest paths

---

### 第十四章 - Tree algorithms

---

### 第十五章 - Spanning trees

---

### 第十六章 - Directed graphs

---

### 第十七章 - Strong connectivity

---

### 第十八章 - Tree queries

---

### 第十九章 - Paths and circuits

---

### 第二十章 - Flows and cuts

---

Advanced topics

---

### 第二十一章 - Number theory

---

### 第二十二章 - Combinatorics

---

### 第二十三章 - Matrices

---

### 第二十四章 - Probability

---

### 第二十五章 - Game theory

---

### 第二十六章 - String algorithms

---

### 第二十七章 - Square root algorithms

---

### 第二十八章 - Segment trees revisited

---

### 第二十九章 - Geometry

---

### 第三十章 - Sweep line algorithms

---
