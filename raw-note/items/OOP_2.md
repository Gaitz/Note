## 深入淺出設計模式

### Head First Design Patterns 中文版, ComputerScience/OOP

---

第一章 - 介紹設計模式

第二章 - 觀察者模式

第三章 - 裝飾模式

第四章 - 工廠模式

第五章 - 獨體模式

第六章 - 命令模式

第七章 - 轉接器與外觀模式

第八章 - 樣板方法模式

第九章 - 反覆器與合成模式

第十章 - 狀態模式

第十一章 - 代理人模式

第十二章 - 複合模式

第十三章 - 與設計模式相處

第十四章 - 剩下的模式

---

### 第一章 - 介紹設計模式

- 程式設計時時刻刻存在變動, 因此擁有一個可維護, 有修改彈性的程式是十分重要的 (程式的維護期總是比開發期更長遠)
- 物件導向 Object Oriented Programming
  - OO base -> OO Principle -> OO Design Pattern
- **OO 原則是我們的目標, Design Pattern 是我們的做法**
- 設計模式 Design Pattern 是架構層次的共同語言, 協助程式設計師之間有固定的名稱討論
  - 以利在討論架構時, 不會掉入細節中
  - 設計模式是抽象的架構, 並不是一種特定的實作
- 原則 1: **封裝所有變動之物**, 目標在於讓系統中的部分改變不會影響其他部分
  - 對於一個類別中會隨之不同的變動應該抽離成另外的類別, 然後以 **delegation** 委派的方式使用
  - 提供 **setter** 來允許變動
- 原則 2: **程式針對介面, 而非實作**, 相依於介面而非實作, 實作是動態傳入的
  - 意思是在宣告變數時的型別, 應該是 **supertype** (**super class** or **interface**), 即使用多型, 增加程式的彈性 (Runtime 才決定實體)
- 原則 3: **多用合成 (composition), 少用繼承 (inheritance)**
  - 重用性以合成實現比起繼承更有彈性, 並且**繼承不利維護與擴充**
- Design Pattern 1: `策略模式 Strategy Pattern`
  - **封裝個別的策略, 並且允許動態的替換, 但是介面保持不動**

---

### 第二章 - 觀察者模式

- Design Pattern 2: `觀察者模式 Observer Pattern`
  - **定義了一對多的關係, 並且在狀態改變時會自動通知所有相依者**
- 用於狀態更新自動通知, Observer Pattern 有多個不同的實現方式
- **Subject** 主題 (介面), 維護一組觀察者, 提供 _Register_ 與 _Deregister_ 方法, 更新時呼叫每個觀察者的約定方法
- **Observer** 觀察者 (介面)
- 依賴性反轉, 讓資料持有人去通知使用者, 而不是所有的使用者都來訪問資料來源
- 原則 4: **設計時, 需要互動的物件關係應該鬆綁 (loose coupling)**
- Java 內建的 Observer Pattern, **java.util** 裡的 **Observer Interface** 與 **Observable Class** (等同 Subject)
  - 注意到 _java.util.Observable_ 是一個類別而非介面, 導致利用上缺乏彈性
  - 以及被保護的 _protected_ _setChanged()_ 導致除了繼承之外無法使用合成
  - 如果內建實作不合用時, 應該自行建立
- JDK 中除了 _java.util_ 使用到 `Observer Pattern` 之外, 在 JavaBeans 與 Swing 中接有用到
  - **event** 與 **event listener** 也是一種 `Observer Pattern` 的實現

---

### 第三章 - 裝飾模式

---

### 第四章 - 工廠模式

---

### 第五章 - 獨體模式

---

### 第六章 - 命令模式

---

### 第七章 - 轉接器與外觀模式

---

### 第八章 - 樣板方法模式

---

### 第九章 - 反覆器與合成模式

---

### 第十章 - 狀態模式

---

### 第十一章 - 代理人模式

---

### 第十二章 - 複合模式

---

### 第十三章 - 與設計模式相處

---

### 第十四章 - 剩下的模式

---
