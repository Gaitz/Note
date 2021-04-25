## ReactiveX, RxJS documentation

### [ReactiveX](http://reactivex.io/), [RxJS](https://rxjs-dev.firebaseapp.com/guide/overview), [Learn RxJS](https://www.learnrxjs.io/), RxJS

---

ReactiveX

第一章 - Observable

第二章 - Operators

第三章 - Single

第四章 - Subject

第五章 - Scheduler

RxJS

第六章 - Observable

第七章 - Observer

第八章 - Operators

第九章 - Subscription

第十章 - Subjects

第十一章 - Scheduler

Learn RxJS

第十二章 - Subjects

第十三章 - Operators, Combination

第十四章 - Operators, Conditional

第十五章 - Operators, Creation

第十六章 - Operators, Error Handling

第十七章 - Operators, Filtering

第十八章 - Operators, Multicasting

第十九章 - Operators, Transformation

第二十章 - Operators, Utility

---

ReactiveX

---

### 第一章 - Observable

- observer 訂閱 (subscribes) observable 並且在未來 observable 會發送 (emit) 資訊
- marble diagrams 彈珠圖，用來表示 observable 的資訊串 (streams)
- 在 ReactiveX 中，指令是平行且未來執行的，取代一般的 callback function (更低階), 使用 observer pattern (高階抽象), 使用的是 subscribe (訂閱) observable 並且準備好接收資訊且處理
- 優點： 促進平行化，在無關的行為中，可以被平行的執行，而不需要循序且阻塞
- 實現非同步程式 (asynchronous)
- Observer 等同於 subscriber, watcher, reactor
- 每個 ReactiveX 的實作命名規則上可能有所不同

建立 observables

- 一般程式是同步的，執行函式並且立刻接收回傳值
- Observer pattern 的 asynchronous programming

  - 定義一個處理函式接收的值是非同步的回傳值 (asynchronous return), 即 observer
  - 定義非同步呼叫, 即 Observable
  - observer 訂閱 (subscribe) observable, 同時會啟動 observable
  - 等到 observable 發送 (emit) 資訊時，會自動執行 observer 的處理函式

- Observable 會呼叫以下三種 onNext, onCompleted, onError 函式

  - 通過約定好的函式名稱, observable 會呼叫 observer 的 callback function

- Unsubscribing, 在某些 ReactiveX 的實作上會有 Subscriber interface 包含 unsubscribe method 用來讓 observer 停止註冊該 observable

  - 在 observable 沒有任何的 subscribe 時，可以考慮停止 emit 行為，來優化性能

Hot and cold Observables

- 冷熱 observables 的差別，取決於 observable 開始發送的時間
- Hot Observable, 通常是一開始就發送訊息，因此後面註冊的 observer 是從中間開始接收資訊
- Cold Observable, 等到 observer 註冊後才開始發送訊息, 即 observer 每次註冊都可以取得完整的資訊

Composition via Observable Operators

- ReactiveX 的精華在於 Observable Operators，用來操作由 observable 發送的訊息序列
- 主要可以分成幾類

  - Creating Observables, 創建類
  - Transforming Observable Items, 資訊轉換類
  - Filtering Observable, 過濾類
  - Combining Observables, 組合類
  - Error Handling Operators, 錯誤處理類
  - Utility Operators, 工具類
  - Conditional and Boolean Operators, 條件判斷類
  - Mathematical and Aggregate Operators, 數學與聚合類
  - Converting Observables, 轉換類
  - Connectable Observable Operators, 連結類, 通常與 hot observable 有關
  - Backpressure Operators, 流程控制類
  - 其他領域類, 依據 ReactiveX implements 的平台，可能會有領域專用的 operators

- Chaining Operators
  - 大多數的 operator 都會回傳新的 Observables, 因此可以使用 chaining 的方式串連

---

### 第二章 - Operators

- Operators 的命名與實作, 都依據 ReactiveX 實現的平台，為了更符合平台慣例，可能會有所不同。
- Operator Chaining, 藉由串連組合 operators
- 本章內容包含, 核心的 operators, 1. 以類別介紹 2. 藉由 decision tree 選用最佳的 operator 3. 以字母排序所有的核心 operators
- 含有連結到更詳細的 operator 說明

Creating Observables, 創建類

- `Create`, 手動創建
- `Defer`, 延遲創建 (等到 subscribe 時)
- `Empty`, `Never`, `Throw`, 嚴格的特殊性質
- `From`, 從其他資料結構中轉換
- `Interval`, 每個時間區間執行一次
- `Just`, 單一或一組物件直接轉換成的
- `Range`, 連續整數
- `Repeat`, 重複出現
- `Start`, 發送函式回傳值
- `Timer`, 延遲一定時間後發送單一個

Transforming Observables, 轉換類

- `Buffer`, 累積數個一次發送
- `FlatMap`, Observables 依據函式轉成壓平的 observables
- `GroupBy`, 依據 key 打包後發送
- `Map`, 每個 item 依據相同的函式轉換
- `Scan`, 具有儲存功能的 map, 類似 reduce 功能
- `Window`, 累積發送並且關閉, 類似 Buffer 但是會關閉

Filtering Observables, 過濾類

---

### 第三章 - Single

---

### 第四章 - Subject

---

### 第五章 - Scheduler

---

RxJS

---

### 第六章 - Observable

---

### 第七章 - Observer

---

### 第八章 - Operators

---

### 第九章 - Subscription

---

### 第十章 - Subjects

---

### 第十一章 - Scheduler

---

Learn RxJS

---

### 第十二章 - Subjects

---

### 第十三章 - Operators, Combination

---

### 第十四章 - Operators, Conditional

---

### 第十五章 - Operators, Creation

---

### 第十六章 - Operators, Error Handling

###

---

### 第二十章 - Operators, Utility

---
