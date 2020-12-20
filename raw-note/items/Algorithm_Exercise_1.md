## Cracking the Coding Interview, 6th Edition

### BOOK resource, AlgorithmExercise

---

第一章 - 面試流程

第二章 - 幕後故事

第三章 - 特殊狀況

第四章 - 面試前

第五章 - 行為題目

第六章 - Big O

第七章 - 技術題目

第八章 - 薪資與福利

第九章 - 資料結構, Array and String

第十章 - 資料結構, Linked List

第十一章 - 資料結構, Stack and Queue

第十二章 - 資料結構, Tree and Graph

第十三章 - 概念與演算法, 位元運算

第十四章 - 概念與演算法, 數學與邏輯謎題

第十五章 - 概念與演算法, 物件導向設計

第十六章 - 概念與演算法, 遞迴與動態規劃

第十七章 - 概念與演算法, 系統設計

第十八章 - 概念與演算法, 排序與搜尋

第十九章 - 概念與演算法, 測試

第二十章 - 知識基礎, C/C++

第二十一章 - 知識基礎, Java

第二十二章 - 知識基礎, 資料庫

第二十三章 - 知識基礎, 執行緒與鎖

第二十四章 - 中級題目

第二十五章 - 困難題目

第二十六章 - 進階題目

第二十七章 - 函式庫

---

### 第一章 - 面試流程

---

### 第二章 - 幕後故事

---

### 第三章 - 特殊狀況

---

### 第四章 - 面試前

---

### 第五章 - 行為題目

- 準備行為題目的問題, 
  - 挑戰
  - 錯誤/故障
  - 收穫
  - 領導
  - 衝突
  - 不同的做法

- 提問的問題
- 自我介紹的結構
  - 目前工作 (粗略)
  - 學校
  - 畢業後
  - 目前工作 (詳細)
  - 工作之外
  - 結論

---

### 第六章 - Big O

- 實際計算執行次數
- 正確區分變數
- 等加級數
- 等比級數
- while loop
- 遞迴

---

### 第七章 - 技術題目

練習時

1. 嘗試自行回答
1. 紙上寫程式
1. 紙上寫測試
1. 電腦上實現

解題思考流程

1. 仔細聽懂題目
1. 畫出範例
1. 說出暴力解, 解釋空間與時間複雜度
1. 最佳化
1. 逐步檢視, 仔細檢查思考出來的演算法
1. 實作程式碼
1. 測試

最佳化的技巧

- BUD, 瓶頸, 不必要的工作, 重複的工作
- DIY, 實際手動操作範例
- 簡化與歸納
- 底條件與疊加, 會自動生成遞迴解法
- 資料結構腦力激盪, 嘗試思考常見的資料結構
- 最理想執行時間

---

### 第八章 - 薪資與福利

---

### 第九章 - 資料結構, Array and String

- 9 題練習
- Array
- String
- Hash table

Hints

- 利用 Hash Table: insert, search O(1), 利用 hash table 的搜尋與插入 O(1), 缺點是需要 O(n) 空間複雜度 
- 利用 Sorted O(n log n), 思考排序過後是不是更容易處理, 缺點是排序需要 O(n log n) 的時間複雜度
- 利用 字串連接, 觀察連接後是否更好處理
- 字串問題相關, 
  - 字元編碼 (ASCII / Unicode)
  - 空白, 大小寫, 重複字元, 字串長度, 
  - 排序
  - 字串連接, 自己與自己相連或與其他相連

---

### 第十章 - 資料結構, Linked List

- 8 題練習
- Singly Linked List
- Doubly Linked List
- Runner 技巧
- 可能可以使用遞迴技巧

Hints

- 雙指標, 快指標剛好快一倍
- 圖解計算

---

### 第十一章 - 資料結構, Stack and Queue

- 6 題練習
- Stack
  - 可以用於把遞迴演算法改成迭代演算法時使用
- Queue
  - 常用於廣度優先搜尋 BFS, 實現 Cache

Hints



---

### 第十二章 - 資料結構, Tree and Graph

- 12 題練習

Tree

- 二元樹 Binary Tree
- 二元搜尋樹 Binary Search Tree
- 平衡樹 Balanced tree, AVL tree, Red-black tree
- 完全樹 Complete tree
- 滿樹 Full tree
- 完美樹 Perfect tree
- 走訪 Traversal
  - in-order
  - pre-order
  - post-order

Heap

- 小堆疊 Min-heap
- 大堆疊 Max-heap
- 操作 
  - insert O(log n) 
  - extract O(1)
  - delete O(log n)

Trie

- prefix tree
- 常用於實現前綴詞搜尋
- 搜尋時間複雜度 O(K), K 為字串長度

Graph

- 有向圖 Directed Graph
- 連通圖 Connected Graph
- 無環圖 Acyclic Graph
- 儲存方式
  - 相鄰清單 Adjacency List
  - 相鄰矩陣 Adjacency Matrix

Graph Search

- 深度優先搜尋 Depth-first Search, DFS
- 廣度優先搜尋 Breadth-first Search, BFS
  - 最短路徑通常使用 BFS
  - 使用 Queue 實作
- 雙向搜尋 Bidirectional Search
  - 從目標的兩個節點同時使用 BFS

Hints

- 善用 BFS 與 DFS
- 利用遞迴解決, 使用 bottom up 思考
- 利用遞迴解決, 使用 top down 思考

---

### 第十三章 - 概念與演算法, 位元運算

- 8 題練習

---

### 第十四章 - 概念與演算法, 數學與邏輯謎題

- 10 題練習

---

### 第十五章 - 概念與演算法, 物件導向設計

- 12 題練習

---

### 第十六章 - 概念與演算法, 遞迴與動態規劃

- 14 題練習

---

### 第十七章 - 概念與演算法, 系統設計

- 8 題練習

---

### 第十八章 - 概念與演算法, 排序與搜尋

- 11 題練習

---

### 第十九章 - 概念與演算法, 測試

- 6 題練習

---

### 第二十章 - 知識基礎, C/C++

- 11 題練習

---

### 第二十一章 - 知識基礎, Java

- 8 題練習

---

### 第二十二章 - 知識基礎, 資料庫

- 7 題練習

---

### 第二十三章 - 知識基礎, 執行緒與鎖

- 7 題練習

---

### 第二十四章 - 中級題目

- 26 題練習

---

### 第二十五章 - 困難題目

- 26 題練習

---

### 第二十六章 - 進階題目

---

### 第二十七章 - 函式庫

---

189 = 9 + 8 + 6 + 12 + 8 + 10 + 12 + 14 + 8 + 11 + 6 + 11 + 8 + 7 + 7 + 26 + 26
216 = 27 + 189 