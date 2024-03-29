## Clean Code and The Clean Coder

### Clean Code 與 The Clean Coder, 中文版, ComputerScience/Mindset

---

Clean Code

第一章 - 無瑕的程式碼

第二章 - 有意義的命名

第三章 - 函式

第四章 - 註解

第五章 - 編排

第六章 - 物件及資料結構

第七章 - 錯誤處理

第八章 - 邊界

第九章 - 單元測試

第十章 - 類別

第十一章 - 系統

第十二章 - 羽化

第十三章 - 平行化

第十四章 - 持續地精煉

第十五章 - JUnit 的內部結構

第十六章 - 重構 SerialDate

第十七章 - 程式碼的氣味和啟發

第十八章 - 平行化之二

The Clean Coder

第一章 - 專業主義

第二章 - 說不

第三章 - 說是

第四章 - 寫程式

第五章 - 測試驅動開發

第六章 - 練習

第七章 - 驗收測試

第八章 - 測試策略

第九章 - 時間管理

第十章 - 預估

第十一章 - 壓力

第十二章 - 協作

第十三章 - 團隊與專案

第十四章 - 輔導、學徒期與工藝典範

第十五章 - 工具

---

Clean Code

---

### 第一章 - 無瑕的程式碼

- 概略的描述 clean code 是什麼
- 我們為什麼需要 clean code
- 不好的程式會形成阻礙, 壞的程式會導致嚴重的後果
  - 劣質的程式碼導致了公司的倒閉
  - 不好的程式碼構成了阻礙，那又為什麼要撰寫這樣的程式碼呢?
  - 雜亂的程式碼會拖慢開發的速度直到根本改不動, 最後變成 rewrite 整個系統, 然後產生新的雜亂程式碼周而復始
- 待會兒等於永不, **LeBlanc's law: Later equals never**
- **造成雜亂程式碼的根本原因在於程式設計師不夠專業**
  - 如果程式設計師遵守不懂劣質程式碼風險主管的意願, 代表程式設計師也一樣不專業
- 讓開發速度加快的**唯一**方式是 clean code
  - 隨時隨地都確保程式碼盡可能的整齊潔淨
  - 爛的程式碼不會讓你因此趕上截止日, 只會讓開發速度更慢
- Clean code 的藝術
  - 具有程式感, 看到雜亂程式碼的同時知道有哪些更好的選擇, 知道如何改變
- **更容易閱讀才會更容易撰寫**
- **童子君規則: 持續地保持 clean code, 每次 commit 都更乾淨一點點**
  - vs. 破窗理論
- **重複的程式碼代表我們的想法沒有被適當的表達在程式碼中**
  - 試圖弄清楚是什麼，然後試圖把想法表達的更清楚
- 我們是作者, 程式碼的作者, 與讀者有良好的溝通是作者的**責任**
  - 記得你就是作者, 讀者會對你的作品下評論
  - 在撰寫新程式碼之前, 我們總是閱讀舊的程式碼
  - 因此讓程式碼更容易閱讀, 也會讓程式碼變得更容易撰寫
  - 你今天寫程式的難易度, 取決於周邊程式碼的可閱讀性高低
- clean code 是
  - 十分注重細節
  - 優雅的、令人愉快的
  - 專注表達單一意圖
  - 簡單明瞭、俐落的抽象概念
  - 只包含必要的資訊，讓讀者感受到我們的果決
  - 包含測試的, unit test, acceptance test
  - 盡可能減少相依性
  - 被細心照料的
  - 沒有重複的程式碼
  - 具有表達力的
  - 提早建立簡單抽象概念
  - 執行結果如同想像的
  - 看起來像是為了解決該問題而存在的

---

### 第二章 - 有意義的命名

- **認真嚴肅地對待命名**
- **一發現有更好的命名就立刻替換掉原本的名稱**
- 如果一個名稱還需要註解輔助就代表他不具備展現意圖的能力
- 命名的用處在於讓程式本身提供上下文資訊 (context)
  - 顯示出存在的意圖

**避免誤導**

- 避免留下喪失程式原意的錯誤線索
- 小心過於相似的名稱, 不容易在第一時間判斷出不同

**產生有意義的區別**

- 無意義詞彙是多餘的, 沒有區分性
  - Ex. _Data_, _Info_
- 要區別名稱，就用讀者能辨識出不同之處的區別方式

**使用能唸出來的名稱**

- 字詞應該是能夠發音的，讓閱讀時能使用到人腦的語言功能

**使用可被搜尋的名字**

- 長命名勝過短命名
  - 短命名造成搜尋的困難
- 命名的長度應該與他的存活 scope 成正比

**避免編碼**

- 不要在命名上額外提供一套規則的資訊, 像是
  - 型別代號
  - Member Prefixes, 用額外命名來區分物件成員或是函數參數
  - Interfaces 和 Implementations, 不要為 interface 增加額外的命名資訊, 加在 implementation 上, 好的程式應該相依於 interface 上, 不必額外透露出是 interface 或是 implementation 給使用者

**避免思維的轉換**

- 專業的程式設計師知道清楚明白才是王道
  - 專業人士運用本身的好能力, 寫出讓別人可以了解的程式
- **命名應該使用讀者所熟知的名稱**

類別的命名

- 應該使用名詞或名詞片語
- 不應該是動詞

方法的命名

- 應該使用動詞或動詞片語
- 當對 constructor 被 overloaded 時, 應該提供包含參數資訊的靜態工廠方法取代直接呼叫 constructor
  - 考慮強制將 constructor 設為 private 都由有意義的 static factory method 取代

不要裝可愛

- 命名上賣弄小聰明、幽默、俚語、俗語

**每個概念使用一種字詞**

- **替單一抽象概念挑選一個字詞, 並堅持持續的使用一致的詞彙**
  - 固定的、一致性的命名規則
- 範例: 無法區分的 _controller_, _manager_, _driver_

**別說雙關語**

- **一個詞彙不能多於一種目的**
- 身為作者，我們的目標是讓程式碼盡可能易於理解，可以快速瀏覽不需要時間奮力苦讀

**使用解決方案領域的命名**

- 取決於讀者是誰,
- 讀者是程式設計師, 因此應該盡可能使用程式設計師彼此本身就知道的知識領域命名, 像是 pattern 的慣用詞, 演算法名稱, ...

**使用問題領域的命名**

- 如果沒有解決方案的命名方式 (程式設計師熟悉的術語) 時,
- 使用問題領域 (domain language) 的命名, 起碼維護程式碼時可以詢問業務相關人員 (領域專家) 命名含意
- **將程式碼區分成解決方案領域和問題領域**, 是專業程式設計師該做的工作, 在適當的時機使用適當的命名

**添加有意義的上下文資訊 (context)**

- 命名意義, 很難從單獨的命名中取得足夠的資訊, 大多數時候需要配合 context 命名
- _grouping_ 把單獨散落的命名聚合成物件或集合, 以程式碼的方式展現出 context
- 改善上下文資訊並且讓演算法變得清晰
- _補_: **當有多個零散的區域變數時, 就是個時候把它聚合成一個概念**, 變成物件, 另外的程式,

**別添加無理由的上下文資訊**

- 當能用更簡潔的方式命名時, 就不需要額外添加 context 資訊的長命名

總結

- 別讓重新命名阻礙你的前進
- 以重構工具協助解決可閱讀性的問題 (renaming tool)

---

### 第三章 - 函式

- 函式是所有程式組成的基礎, 首先把函式寫好

簡短

- **最重要的準則是簡短**
  - 每個函式只有僅僅 2 ~ 4 行, 每個函式都一清二楚, 透露出本身的意圖
  - 每個函式都帶領著你到下一個函式, 這就是函式該有的簡短

區塊 (Blocks) 與縮排 (Indenting)

- 縮排程度不應該大過於 1 或 2
- 每個 If, else, while, 其他敘述都應該只有一行

只做一件事情

- **函式應該只做一件事, 他們應該把這件事情做好。而且他們應該只做這件事**
- 函式只做了在函式名稱下**同一個抽象概念**的步驟
- 觀察函式否超過一件事情的方法是, 是否能從函式中提煉出另一個函式, 但此新函式不是只是重新詮釋實作而已

函式的段落

- **如果函式內部可以被拆解成多個段落, 也很明顯地顯示他做了超過一件事情**

**每個函式只有一層抽象概念**

- 細節跟本質不應該混在一起
- **我們希望閱讀程式碼就像是在敘事一樣**
- **聚焦在函式如何引導到下一個函式，以及每個函式如何保持在同一個抽象層概念**

Switch 敘述

- switch 敘述應該盡可能地隱藏在底層
- 因為它很明顯的破壞了 Single Responsibility Principle, SRP 跟 Open Closed Principle, OCP
- 物件導向應該善用 **Factory pattern** 或者隱藏在繼承關係中

**使用具描述能力的名稱**

- 取一個好名稱, 別害怕去取較長的名稱, 只要他能具備描述性質
- 保持命名的一致性

函式的參數

- 最理想的狀況下是 0 個參數, 再來是 1 個參數, 2 個參數, 最差是 3 個參數
- **多參數導致測試困難**
- **參數最好是輸入型參數, 盡可能不要使用輸出型參數, 不容易理解**

**Flag 參數**

- 非常爛的方式, 很明顯地告訴這個函式他會做超過一件事情
- 最好的辦法是拆成獨立的兩個函式

**物件類型的參數**

- 當函式參數超過 2 ~ 3 個時, 就可能要把它封裝成物件, 讓概念被聚合在一起

動詞和關鍵字

- 選一個好的動詞, 能解釋意圖, 甚至能解釋參數的順序性

**要無副作用**

- **No side effect**
- 任何的 side effect 都會導致奇怪的耦合, 更有可能是時空的耦合 (temporal coupling)
- **如果函式帶有副作用, 必須在函式命名上顯示出來**

輸出型參數

- 在物件導向中, 使用 `this` 取代輸出型參數

**命令和查詢分離**

- 一個函式只能做某件事情或回答某個問題, 不應該同時發生
- **command 與 query 分離**

**使用例外處理取代回傳錯誤碼**

- 回傳錯誤碼會違反命令和查詢分離
- 導致必須處理的巢狀迴圈
- **使用錯誤處理取代**

提取 Try/Catch 區塊

- **錯誤處理本身就是一件事情**
- **應該把錯誤處理完全分離在一個函式中**
- Happy Path 分離

**不要重複自己**

- **Don't repeat yourself, DRY**
- **重複程式碼也許是軟體裡所有邪惡的根源**
- 所有的設計模式、範型，都是為了消除程式碼中的重複

**要如何寫出這樣的函式?**

- 寫軟體就如同其他寫作一樣, 是寫很多版, 逐步雕琢, 修改而成的
- **refactor**
- 函式一開始總是又複雜又長, 也有很多重複程式碼, **但是有一整套的單元測試**，測試涵蓋每一行粗糙的程式碼
- **開始琢磨和改善程式碼** refactor

總結

- **每個系統都是某個特定領域的語言所描述的**
- 程式大師在撰寫程式時, 不認為自己是在寫程式而是**在說故事**
- 建造更豐富更有表達力的語言，讓這些語言來說故事
- **真正的目標是在描述系統的故事**，而你撰寫的函式必須是整潔的結合在一起，形成一種清楚又精確的語言，來幫助你講述故事

---

### 第四章 - 註解

---

### 第五章 - 編排

---

### 第六章 - 物件及資料結構

---

### 第七章 - 錯誤處理

---

### 第八章 - 邊界

---

### 第九章 - 單元測試

---

### 第十章 - 類別

---

### 第十一章 - 系統

---

### 第十二章 - 羽化

---

### 第十三章 - 平行化

---

### 第十四章 - 持續地精煉

---

### 第十五章 - JUnit 的內部結構

---

### 第十六章 - 重構 SerialDate

---

### 第十七章 - 程式碼的氣味和啟發

---

### 第十八章 - 平行化之二

---

The Clean Coder

---

### 第一章 - 專業主義

---

### 第二章 - 說不

---

### 第三章 - 說是

---

### 第四章 - 寫程式

---

### 第五章 - 測試驅動開發

---

### 第六章 - 練習

---

### 第七章 - 驗收測試

---

### 第八章 - 測試策略

---

### 第九章 - 時間管理

---

### 第十章 - 預估

---

### 第十一章 - 壓力

---

### 第十二章 - 協作

---

### 第十三章 - 團隊與專案

---

### 第十四章 - 輔導、學徒期與工藝典範

---

### 第十五章 - 工具

---

33 = 18 + 15
