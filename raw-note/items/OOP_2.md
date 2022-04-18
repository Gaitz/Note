## 深入淺出設計模式

### Head First Design Patterns 中文版, ComputerScience/OOP

---

第一章 - 介紹設計模式

第二章 - 觀察者模式

第三章 - 裝飾者模式

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
  - 重用性以合成實現比起繼承更有彈性, 並且**繼承不利維護與擴充**, 繼承無法在 runtime 產生變動
- Design Pattern 1: `策略模式 Strategy Pattern`
  - **封裝個別的策略, 並且允許動態的替換, 但是介面保持不動**
  - 以 delegation 實現

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

### 第三章 - 裝飾者模式

- 原則 4. **開放封閉原則 Open-closed principle**
  - 對於擴充開放, 關閉修改
  - 減少變動開發完成的程式
  - **只需要針對系統中最有可能變動的地方採用即可**
- 避免過早最佳化, 最佳化帶來額外的抽象層
- 物件可能有很多不同的變化, 避免使用繼承產生無數種組合
- Design Pattern 3. `Decorator Pattern 裝飾者模式`
  - **動態地將責任與擴充功能加在物件上**, 提供比繼承更有彈性的作法
  - 缺點是會產生出多個裝飾者類別
- 仍然使用**繼承為建立方式**, 因此會出現多個裝飾者類別
  - 但是**使用時是以 delegation** 因此可以在 runtime 進行組合 aggregation
- 重點在於 **decorator** 與 **component** 是繼承關係, 因此擁有相同的 super class 介面
  - **decorator** 會傳入 **component** 並且 delegation + 加上自己的行為
- 實際的範例, **Java I/O** 的 _InputStream_ 與 _OutputStream_ 系列
  - Node.js 的 _middleware_ pattern

---

### 第四章 - 工廠模式

- _new_ 等同於 construct 建立具體的物件
  - 為了針對介面寫程式, 並且封裝變動之物
- 為了要利用超型別, 因此必然會有選擇於生成不同的具體物件
  - 封裝這樣的 _switch_ + _new_
- Design Pattern 4. `Simple Factory` 簡單工廠, 把生成物件外包給單一個
  - 獨立出一個單獨的類別處理這樣的生成行為, 通常命名慣例為 **factory** 配合 **create**
- Design Pattern 4. `Factory Method`,
  - 以繼承 _abstract_ **create** method 的方式讓子類別實作個別的 factory method
- Design Pattern 4. `Abstract Factory`,
  - 建立一個 **factory** 介面 (interface) 然後允許存在多個不同的 factory 物件
  - 使用工廠時可以動態的決定要使用哪個工廠實體 factory object
- 原則 5. **反向依賴原則 Dependency Inversion Principle**
  - **依賴抽象 (abstract), 不要依賴具體 (concrete)**
  - 因此會導致高階物件與低階元件都指向中間的抽象層, 而非高階物件直接指向低階物件
  - 變數不持有 object reference, (以 factory 取代)
  - 不要繼承 inherit 具體類別, 而是 _interface_ 或 _abstract class_,
  - 子類別不要 override 父類別的 method

---

### 第五章 - 獨體模式

- 如同全域變數一樣, 但是只在需要使用到的時候才會建立
- 最經典的建立方式是
  - class **private constructor**, 因此無法被 _new_
  - 配合 class **static getInstance** function, 來提供生成與回傳唯一的 instance
- Design Pattern 5. `Singleton Pattern 獨體模式`
  - 一個 class 只有唯一的一個 instance 並且是全域可得 global
  - 在使用時, 做好思考, 是否真的需要使用 Singleton Pattern, 因為真正適用的時機其實是少數, 否則等同於濫用全域變數一樣
- 最經典的建立方式**並非是 thread-safe**
  - 在不同的 thread 都在尚未建立前執行時, 會產生多餘一個的 instance, 則破壞模式
- `thread-safe Singleton pattern` 建立方式

1. 以 _synchronized_ 讓 **getInstance** function 成為同步的,

   - 優點, 實作簡單
   - 缺點, 原本的問題只有在建立實體時才有 thread-safe 問題之後的呼叫並不需要, 因此會有效能浪費

2. **instance** 生成在 class 載入時, 即 _new_ 並不在 **getInstance** 中呼叫, 而是直接生成且存在 class member 上

   - 缺點, 等同於全域變數, 並無法在所需要時才生成, 因此應用程式從載入時就佔用額外的空間, 造成資源浪費

3. **double-checked locking** 在生成時才進行 _synchronized_ 限制, 需要額外配合 _volatile_ 語法使用在 instance 上
   - 最佳解法
   - 缺點, 稍嫌複雜需要額外注意

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
