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

第十七章 - Operators, Multicasting

第十八章 - Operators, Filtering

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

- `Debounce`, 在一定時間內只發送出一個
- `Distinct`, 去除重複, 不發送重複的內容
- `ElementAt`, 只發送指定序號的
- `Filter`, 只發送通過檢查的
- `First`, 只發送第一個, 或者第一個通過檢查的
- `IgnoreElements`, 不發送任何內容, 但是會收到終結通知 (onComplete, onError)
- `Last`, 只發送最後一個
- `Sample`, 定期抽樣
- `Skip`, 忽略從頭開始的指定數量
- `SkipLast`, 忽略指定數量的結尾
- `Take`, 只取從頭開始的指定數量
- `TakeLast`, 只取結尾的指定數量

Combining Observables, 組合類

- `And` / `Then` / `When` , 組合多組 observable 成一個
- `CombineLatest`, 依據指定函數連結最新的內容
- `Join`, 指定區間內組合
- `Merge`, 合併內容
- `StartWith`, 略過開頭指定數量後開始
- `Switch`, 交替發送, 如果同個時間區間則會以目前交替到的對象為優先
- `Zip`, 組合序列對應的內容成一個

Error Handling Operators, 錯誤處理類

- `Catch`, 捕捉 `onError` 並且不終結 observables streaming
- `Retry`, 接收到 `onError` 後重新註冊 (subscribe) observables 重試所有內容

Utility Operators, 工具類

- `Delay`, 延遲指定時間後發送
- `Do`, 執行指定轉換內容
- `Materialize` / `Dematerialize`, 轉換成 onNext, 或 onComplete, onError 形式
- `ObserveOn`, **?**, 指定 schedular 去表達 observables
- `Serialize`, 強制整合 observables 形成一個序列
- `Subscribe`, 訂閱 observable, 啟動
- `SubscribeOn`, 指定 schedular 來執行 `Subscribe`
- `TimeInterval`, 轉換 observables 內容成發生的時間區間
- `Timeout`, 如果當內容超越時間區間後, 則發送終結訊號
- `Timestamp`, 發送內容附加 timestamp 資訊
- `Using`, **?**,依據 resources 創建 observables

Conditional and Boolean Operators, 條件判斷類

- `All`, 類似 every, 判斷所有的內容並且回傳 boolean
- `Amb`, 多條 observables 競爭, 只取最優先觸發的
- `Contains`, 判斷是否擁有符合的內容, 回傳 boolean
- `DefaultIfEmpty`, 如果內容是空的則發送預設值
- `SequenceEqual`, 比較兩條 observables 發送是否順序一致, 回傳 boolean
- `SkipUntil`, 忽略 observables 內容直到第二條 observables 發送後才開始
- `SkipWhile`, 忽略內容直到判斷式為 false 後才開始
- `TakeUntil`, 取值直到第二條 observables 開始後就停止
- `TakeWhile`, 取值直到判斷式為 false 後中止

Mathematical and Aggregate Operators, 數學與聚合類

- `Average`, 計算並且發送平均數
- `Concat`, 接續連接兩條 observables
- `Count`, 計算符合條件的數量
- `Max`, 發送最大值
- `Min`, 發送最小值
- `Reduce`, 依序計算並且記憶, 回傳最終值
- `Sum`, 計算並且發送總和

Connectable Observable Operators, 連結類, 通常與 hot observable 有關

- `Connect`, 連接現有的 observables 並不從頭觸發, 而是等待新的內容
- `Publish`, 把現有的 observable stream 轉換成 connectable
- `RefCount`, 轉換 connectable observable 成原本的靜態模式
- `Replay`, 配合 connectable 使用, 可以保證重複發送先前於 publish 的內容

Operators to Convert Observables, 轉換類

- `To`, 轉換 observable 成單一的資料結構

---

### 第三章 - Single

- RxJava 家族專屬
- 類似 Observable, 但是 callback function 不同, 變成 `onSuccess`, `onError` 兩種狀態
- 概念類似於 JavaScript Promise

Single 也有 Operators

- `compose`,
- `concat`, `concatWith`
- `create`,
- `delay`,
- `doOnError`,
- `doOnSuccess`,
- `error`,
- `flatMap`,
- `flatMapObservable`,
- `from`,
- `just`,
- `map`,
- `merge`,
- `merge`, `mergeWith`,
- `observerOn`,
- `onErrorReturn`,
- `subscribeOn`,
- `timeout`,
- `toSingle`,
- `toObservable`,
- `zip`, `zipWith`,

---

### 第四章 - Subject

- 一個中間層, Proxy, Bridge, 同時具有 observer 與 observable 性質
- Subject 具有四種類型, 不一定每個實作都有, 名稱也有可能不同

AsyncSubject

- Subject 註冊一個 Observable 後, 在該 Observable 完結 (onComplete) 後, 會發送最後一個訊息 (final value)
- 如果註冊的 Observable 以 error 結束時, Subject 則不發送任何內容

BehaviorSubject

- Observer 註冊 BehaviorSubject 會接收到最近的資訊, 並且 BehaviorSubject 所註冊的原始 Observer 資訊也會一同傳遞，並且在原始 Observer onError 結束時也會傳遞, onError 出去

PublishSubject

- 從建立開始就會發送資訊, 不管目前有沒有 observer 註冊, 並且使用 hot observable 提供後續的 observer 資訊

ReplaySubject

- 提供 cold observer 的功能

---

### 第五章 - Scheduler

- Rx 預設是 single thread 的非同步模式 (asynchronous)
- 利用 Rx 的 Scheduler 協助做到 concurrency and multithreading
- 有些 operator 提供可以指定 Schedular 參數
- Schedular 以抽象層表示, 內容包含三個部份
  - execution context, (threads)
  - execution policy, (queue, async, ...)
  - clock, (timer)
- 提供對於 observer 的控制, 也提供實現 virtual timer 介入的機會, 方便測試 time-based scenario
- `SubscribeOn`
- `ObserveOn`

---

RxJS

---

### 第六章 - Observable

Pull, Push

- 資料的生產者與接收者
- Pull System, 資料的生產者, 不在意資料被接收的時機, (資料生產者為被動傳遞)
  - 例如 function, generator (iterator)
- Push System, 資料的生產者, 主動傳遞資訊, (接收者為被動接收)
  - 例如 Promise, (callback function), Observable

function and Observable

- 都是 lazy 執行的, 不被呼叫 (call) 或註冊 (subscribe) 之前不會執行
- 預設的情況下 Observable 是同步執行的

Anatomy of an Observable

- 分成建立 (create), 訂閱 (subscribe), 執行 (execute), 處置 (disposed)
- Creating
  - 使用 `new Observable()`
  - 使用創建類的 operator 例如 `from()`, `of()`, ...
- Subscribing
  - 使用 `.subscribe` 來觸發 observable 的執行
- Executing
  - 觸發 `next`, `error`, `complete`
- Disposing
  - Observer 的 executing 可以是無限的
  - 通過 subscribing 的回傳函式, 來終止 (`unsubscribe`)

---

### 第七章 - Observer

- 接收 Observable 資料的人, 只是一組 callback function 的集合
- 包含 `next`, `error`, `complete` 命名的 callback functions
- Observer 可以是只有部分的 (partial), 並不一定要提供完整的三個 callback function
- 甚至可以傳入單一函式, Observable 會自動封裝成 `next` callback function

---

### 第八章 - Operators

- RxJS 最主要的功能實現
- Operator 只是單純的 pure function
- 可以使用 functional 的 `pipe()` 達成 operator chaining, 取代手動的函式呼叫
- Marble diagrams, 彈珠圖, 用圖示的方式解釋各種 operator 的作用

Categories of Operators, 分類

- Creation Operators 建造類
- Join Creation Operators 組合建造類
- Transformation Operators 轉換類
- Filtering Operators 過濾類
- Join Operators 組合類
- Multicasting Operators 多重發佈類 (hot)
- Error Handling Operators 錯誤處理類
- Utility Operators 工具類
- Conditional and Boolean Operators, 條件判別類
- Mathematical and Aggregate Operators, 數學類

Custom Operators, 建立客製化的 operator

- 使用 `pipe()` 建立 custom operator
- 使用定義建立 custom operator 較為繁瑣, 只有在無法使用 `pipe()` 配合現有的 operators 組合時才有機會使用

---

### 第九章 - Subscription

- 由 creator 回傳的物件, 內容包含了 `unsubscribe()` 的中止函式
- `add()` function, 可以組合多個 subscription object 組合成單個 `unsubscribe()` 中止函式, 即呼叫一次中止所有的
- `remove()` function, 為 `add()` 的反向作用

---

### 第十章 - Subjects

- 同時包含 Observable 與 Observer 的特性, 等同於 event emitter,
- 可以使用 subject `subscribe()` 來註冊 callback function
- 使用 subject `next()` 來發送訊息

Multicasting

- 可以用來轉發單一 observable 成 multicasting
- 其他 Observer `subscribe()` subject
- 藉由 subject `subscribe()` source observable 來觸發, 轉發給之前註冊的 observers
- 使用 `multicast` operator 來實現與簡化 multicasting 流程
  - 回傳 ConnectableObservable 實現 hot 與 multicasting

BehaviorSubject

- 對於 behaviorSubject 新註冊的 observer 都可以立即接收到先前最新的資訊

ReplaySubject

- 類似於 BehaviorSubject 但是可以接收先前指定數量 buffer 裡的所有訊息

AsyncSubject

- 類似於 `last` operator, 只會在 `complete` 時, 發送最後一個資訊

Void subject

- 不在意內容, 只在意有 event 被發送的話, 可以使用 void subject, 使用下面兩種方式建立
- `new Subject<void>()`
- `new Subject()`

---

### 第十一章 - Scheduler

- Scheduler 用來控制 subscription 何時開始與 資訊何時發送
- 包含三個部分
  - Data structure, 用來控制 task 儲存的資料結構
  - Execution context, 用來控制 task 何時, 在哪裡執行
  - Clock, 定義計時時鐘 timer
- observable 定義時以 `observeOn()` 來指定 scheduler

Scheduler types, 可指定的類型

- `null`, default 設定, 以同步且遞迴的方式執行通知
- `queueScheduler`, 同步執行, 所有的 observable 放置在 queue 中
- `asapScheduler`, 非同步執行, 以 `microtask` 實現
- `asyncScheduler`, 非同步執行, 以 `macrotask` 實現
- `animationFrameScheduler`, 非同步執行, 以 `requestAnimationFrame` 實現 (macrotask)

Using Schedulers

- 很多 operator 都提供指定 scheduler 的參數, 並且擁有不同的 default Scheduler
- 大多數的 creation operators 都提供 scheduler 指定的機會
- 使用 `subscribeOn()` 提供在 Observer subscribe 時指定 scheduler 的機會
- 使用 `observeOn()` 提供在建立 Observable 時指定 scheduler 的機會
- 其他時間相關的 operators 也提供指定 scheduler 的機會

References, 額外的參考資料

- [認識 RxJS 的 Scheduler](https://ithelp.ithome.com.tw/articles/10253801)

---

Learn RxJS, v6

---

### 第十二章 - Subjects

- multicasting 單一來源把資訊 (subject) 一次性發給多個使用者
- 可以分成幾類 Subject, AsyncSubject, BehaviorSubject, ReplaySubject
- Subject, 一般的, 一次性發送給所有訂閱者, 沒有初始值, 不重發
- AsyncSubject, 只有在 `complete` 後才發送最後一組資料給訂閱者, (只發一個)
- BehaviorSubject, 帶有初始值的 subject, 新進訂閱者也會取得當前最新的資訊 (replay 1)
- ReplaySubject, 會 cache 指定次數, 並且新進訂閱者會取得 cache 的內容 (replay)

---

### 第十三章 - Operators, Combination

- 組合類, 可以組合多個 observers 的資訊成一個
- combineAll, **?**
  - `combineAll(project: function): Observable`
- combineLatest ⭐, 轉換多個 observables 成為一個, 並且取得所有的最新資訊一次印出
  - `combineLatest(observables: ...Observable, project: function): Observable`
- concat ⭐, 依序執行, 只有在前一個 observable `complete` 後第二個才會開始執行
  - `concat(observables: ...*): Observable`
- concatAl, 類似於 `concat`, 但是不用傳入 observables
  - `concatAll(): Observable`
  - 來源是 promise 時, 會自動轉換成 value
- endWith, 在 observable `complete` 時, 會發送一次指定的值
  - `endWith(an: Values): Observable`
- forkJoin, 類似於 `Promise.all` 的概念, 等所有的 observers 都 `complete` 後, 蒐集所有的最後一筆資料傳出 (只會傳出一個)
  - `forkJoin(...args, selector : function): Observable`
- merge ⭐, 整合多個 observables 成為一個, 所有的 observables 一起執行但是訊息發到 merge
  - `merge(input: Observable): Observable`
- mergeAll, **?**
  - `mergeAll(concurrent: number): Observable`
- pairwise, 發送前一個與當前的資訊組成的 array
  - `pairwise(): Observable<Array>`
- race, 使用最先發送的 observable, (有第一筆資料後採用該 observable)
  - `race(): Observable`
- startWith ⭐, 先發送指定的 values, 提供初始值
  - `startWith(an: Values): Observable`
- withLatestFrom ⭐, 也取得指定的 observable 裡最新的資料
  - `withLatestFrom(other: Observable, project: Function): Observable`
- zip, 收集所有的 observables 都有發送值後形成 array 回傳
  - `zip(observables: *): Observable`
  - 其中一個 observable 如果中止後, 則停止

---

### 第十四章 - Operators, Conditional

- 依據特定的條件達成的 operator
- defaultIfEmpty, 如果在 `complete`前沒有任何資訊發送, 則發出指定的預設值
  - `defaultIfEmpty(defaultValue: any): Observable`
- every, 檢查在 complete 前所以的資訊是否有通過 predicate function, 回傳 boolean
  - `every(predicate: function, thisArg: any): Observable`
- iif, 依據 condition function 來決定 subscribe 的對象
  - `iif(condition: () => boolean, trueResult: SubscribableOrPromise = EMPTY, falseResult: SubscribableOrPromise = EMPTY): Observable`
- sequenceEqual, 比對 array 裡的值, 回傳 boolean
  - `sequenceEqual(compareTo: Observable, comparor?: (a, b) => boolean): Observable`

---

### 第十五章 - Operators, Creation

- 建立 observable
- ajax ⭐, 發送 http request 並且把 response 轉換成 observable
  - `ajax(urlOrRequest: string | AjaxRequest)`
- create, 以 subscription 定義函式 (`next`, `complete`, `error`), 產生 observable
  - `create(subscribe: function)`
- defer, 直到 subscribe 觸發時, 才執行 observableFactory function 產生 observable
  - `defer(observableFactory: function(): SubscribableOrPromise): Observable`
  - 適合時間性的, 例如 `new Date()` 在 subscription 時產生
- empty, 立即 `complete` 的 observable
  - `empty(scheduler: Scheduler): Observable`
- from ⭐, 發送 promise, string, array, iterables 成 stream observable
  - `from(ish: ObservableInput, mapFn: function, thisArg: any, scheduler: Scheduler): Observable`
- fromEvent, 把 event 轉換成 stream observable
  - `fromEvent(target: EventTargetLike, eventName: string, selector: function): Observable`
- generate, 以 state function 的方式生成 observable, 類似 `for` loop
  - `generate(initialStateOrOptions: GenerateOptions, condition?: ConditionFunc, iterate?: IterateFunc, resultSelectorOrObservable?: (ResultFunc) | SchedulerLike, scheduler?: SchedulerLike): Observable`
- interval, 以時間區間發送觸發次序, 1000 = 1second
  - `interval(period: number, scheduler: Scheduler): Observable`
- of ⭐, 發送以逗號相隔的 stream, 可以是異質的
  - `of(...values, scheduler: Scheduler): Observable`
- range, 發送數組
  - `range(start: number, count: number, scheduler: Scheduler): Observable`
- throw, 丟出 error
  - `throw(error: any, scheduler: Scheduler): Observable`
- timer, 提供延遲與時間間隔形成的次序 observable
  - `timer(initialDelay: number | Date, period: number, scheduler: Scheduler): Observable`

---

### 第十六章 - Operators, Error Handling

- 錯誤處理的 operators
- catch / catchError ⭐, 捕捉錯誤並且回傳 observable 接續執行
  - `catchError(project : function): Observable`
  - 記得回傳 observable
- retry, 接收到錯誤時, 執行重試指定次數
  - `retry(number: number): Observable`
  - 適合用於 http request retry
- retryWhen, 接收到錯誤時傳給 function 處理何時 retry
  - `retryWhen(receives: (errors: Observable) => Observable, the: scheduler): Observable`
  - 可以實現費式數列 retry

---

### 第十七章 - Operators, Multicasting

- Observable 預設都是 cold 且 unicast 的, 可以藉由 operators 轉換成 hot 或 multicast
- publish, 在 `connect()` 後開始執行, 以 hot 模式發送資訊
  - `publish() : ConnectableObservable`
- multicast, 配合 `subject` 使用, `connect()` 後開始 multicast subject
  - `multicast(selector: Function): Observable`
- share ⭐, 轉換 observable 成為分享模式, 所有的 subscription 共享一筆資訊
  - `share(): Observable`
  - 好處是昂貴的計算或 request 不用重新觸發
- shareReplay ⭐, 等同於 `share` 只是新的 subscription 會有 replay 指定次數的值
  - `shareReplay(bufferSize?: number, windowTime?: number, scheduler?I IScheduler): Observable`

---

### 第十八章 - Operators, Filtering

- 控制何時發送資訊的過濾類 operators
- audit, 等同於 `auditTime` 只是忽視的時間點由, 傳入的 observable 決定
  - `audit(durationSelector: (value) => Observable | Promise): Observable`
- auditTime, 固定時間區間的忽視發送, 只取最近一筆, 然後時間區間重複執行
  - `auditTime(duration: number, scheduler?: Scheduler): Observable`
- debounce, 等同於 `debounceTime`, 只是延遲的時間點由傳入的 observable 決定
  - `debounce(durationSelector: function): Observable`
- debounceTime ⭐, 延遲指定的時間, 發送最近一筆訊息, 其他會被忽略
  - `debounceTime(dueTime: number, scheduler: Scheduler): Observable`
- distinct, 只發送不同於以往的資訊內容, 可以傳入函式決定 key 與 flushes 時機
  - `distinct(keySelector?, flushes?): Observable`
- distinctUntilChanged ⭐, 發送 _值_ 改變時的最後一筆, 使用 `===` 作為比較算子
  - `distinctUntilChanged(compare: function): Observable`
- distinctUntilKeyChanged, 可以指定 key 與比較算子的 `distinctUntilChanged`
  - `distinctUntilKeyChanged(key, compare: fn): Observable`
- filter ⭐, 只發送通過測試的值
  - `filter(select: Function, thisArg: any): Observable`
- find, 只發送通過測試的第一筆資料
  - `find(predicate: function)`
- first, 發送第一筆通過測試的資料或者不指定函式, 只回傳第一筆資料
  - `first(predicate: function, select: function)`
- ignoreElements, 忽略所有的發送值, 只發送 `complete` 或 `error`
  - `ignoreElements(): Observable`
- last, 發送最後一筆資料或者最後一筆通過測試的資料
  - `last(predicate: function): Observable`
- sample, 依據傳入的 observable 決定, 每個開關內取一個值發送
  - `sample(sampler: Observable): Observable `
- single, 確保發送值只有一個, 並且回傳該發送值, 在多餘一個或者沒有的情況下會回傳 `error`
  - `single(a: Function): Observable`
  - 與 `first` 不同之處在於 single 需要等待 `complete` 並且會在多餘一個時丟出錯誤
- skip, 忽略開頭的指定數量個發送值
  - `skip(the: Number): Observable`
- skipUntil, 忽略開頭的發送值, 直到傳入的 observable 被觸發
  - `skipUntil(the: Observable): Observable`
- skipWhile, 忽略開頭的發送值, 直到 predicate function 變成 `false`
  - `skipWhile(predicate: Function): Observable`
- take ⭐, 取得開頭固定數量的發送值
  - `take(count: number): Observable`
- takeLast, 取得結尾固定數量的發送值
  - `takeLast(count: number): Observable`
- takeUntil ⭐, 取值直到傳入的 observable 發送訊息時停止
  - `takeUntil(notifier: Observable): Observable`
- takeWhile, 取值直到 predicate function 回傳 `false` 時停止
  - `takeWhile(predicate: function(value, index): boolean, inclusive?: boolean): Observable`
- throttle, 只取第一筆, 然後忽略直到傳入的 observable 觸發後重新開啟, 重複執行
  - `throttle(durationSelector: function(value): Observable | Promise): Observable`
- throttleTime, 只取第一筆, 然後忽略發送指定時間, 之後重新開啟, 重複執行
  - `throttleTime(duration: number, scheduler: Scheduler, config: ThrottleConfig): Observable`

---

### 第十九章 - Operators, Transformation

- 轉換類
- buffer, 收集內部 observable 的結果成 array 發送
  - `buffer(closingNotifier: Observable): Observable`
- bufferCount,收集指定數量的 observable 的結果成 array 發送
  - `bufferCount(bufferSize: number, startBufferEvery: number = null): Observable`
- bufferTime ⭐, 收集指定時間內 observable 的結果成 array 發送
  - `bufferTime(bufferTimeSpan: number, bufferCreationInterval: number, scheduler: Scheduler): Observable`
- bufferToggle, 依據開關收集 observable 的結果成 array 發送
  - `bufferToggle(openings: Observable, closingSelector: Function): Observable`
- bufferWhen, 收集 observable 的結果直到關閉訊號觸發, 成 array 發送
  - `bufferWhen(closingSelector: function): Observable`
- concatMap ⭐, 執行 map 但是在內部的 (inner) observables 前一項結束後, 下一項才會觸發
  - `concatMap(project: function, resultSelector: function): Observable`
- concatMapTo, 當 source observable 觸發後, 會先執行 inner observable 直到結束, 才繼續接下去 source observable
  - `concatMapTo(observable: Observable, resultSelector: function): Observable`
  - 小心有 memory leak 的問題發生
- exhaustMap, source observable 被觸發後會執行 inner function 直到完成, 才會在接收 source observable 並且在執行期間的原有的 source 會被忽略, 類似 hot observable.
  - `exhaustMap(project: function, resultSelector: function): Observable`
- expand, 遞迴呼叫 project function 直到達成指定次數
  - `expand(project: function, concurrent: number, scheduler: Scheduler): Observable`
- groupBy, 依據 selector function 對 observable 執行 grouping
  - `groupBy(keySelector: Function, elementSelector: Function): Observable`
- map ⭐, 對於 observable 每個訊息都執行指定的 function 然後回傳
  - `map(project: Function, thisArg: any): Observable`
- mapTo, 簡化的 `map`, 直接指定每次的回傳值
  - `mapTo(value: any): Observable`
- mergeMap / flatMap ⭐, 允許指定平行數量執行的 `map`
  - `mergeMap(project: function: Observable, resultSelector: function: any, concurrent: number): Observable`
  - 在 inner observables 執行不會結束時, 可能會造成 memory leak
- mergeScan, 依據 inner observable 的 `scan`
  - `mergeScan(accumulator: (acc, value, index: number) => ObservableInput, seed, concurrent: number = Number.POSITIVE_INFINITY): OperatorFunction`
- partition, 把 source observable 依據 predicate function 一分為二, 分成兩個 observables, 以 array 的方式回傳
  - `partition(predicate: function: boolean, thisArg: any): [Observable, Observable]`
- pluck, observable 發送 object 時可以藉由 pluck 指定欄位回傳, (類似 `map` 的物件取值版)
  - `pluck(properties: ...args): Observable`
- reduce, 依據 accumulator function 計算結果, 在 source observable 結束後發送結果值
  - `reduce(accumulator: function, seed: any): Observable`
- scan ⭐, 每次都發送結果值的 `reduce`, 可以被視為有記憶功能的 `map`
  - `scan(accumulator: function, seed: any): Observable`
- switchMap ⭐, 會結束的 inner observable `map`, 在新的 observable 被取用時就的會自動關閉, 改用新的 observable
  - `switchMap(project: function: Observable, resultSelector: function(outerValue, innerValue, outerIndex, innerIndex): any): Observable`
- switchMapTo, 直接指定 inner observable 的 `switchMap`
  - `switchMapTo(innerObservable: Observable, resultSelector: function(outerValue, innerValue, outerIndex, innerIndex): any): Observable`
- toArray, 收集所有的發送值在結束 (complete, error) 後, 回傳一個 array
  - `toArray(): OperatorFunction`
- window, 類似 `buffer` 轉換成多個 inner observables (window) 取代 array (buffer 的回傳值)
  - `window(windowBoundaries: Observable): Observable`
- windowCount, 在累積指定數量的 source observable 發送, 轉換成 inner observable (window)
  - `windowCount(windowSize: number, startWindowEvery: number): Observable`
- windowTime, 收集指定時間內的 source observable 發送, 轉換成 inner observable (window)
  - `windowTime(windowTimeSpan: number, windowCreationInterval: number, scheduler: Scheduler): Observable`
- windowToggle, 依據 toggle observable 收集 source observable 發送, 轉換成 inner observable (window)
  - `windowToggle(openings: Observable, closingSelector: function(value): Observable): Observable`
- windowWhen, 在指定的 closing observable 觸發時, 關閉一次 window 的收集, 並生成新的
  - `windowWhen(closingSelector: function(): Observable): Observable`

---

### 第二十章 - Operators, Utility

- Observable toolkit
- tap / do ⭐, 執行 side-effect function
  - `tap(nextOrObserver: function, error: function, complete: function): Observable`
- delay ⭐, 指定時間延遲發送
  - `delay(delay: number | Date, scheduler: Scheduler): Observable`
- delayWhen, 以函式的方式指定延遲的時間
  - `delayWhen(selector: Function, sequence: Observable): Observable`
- dematerialize, 把 Notification object 轉換成 Notification value observable
  - `dematerialize(): Observable`
- finalize / finally, 在 `complete` 或 `error` 後執行
  - `finalize(callback: () => void)`
- repeat, 重複執行指定次數
  - `repeat(count: number): Observable`
- timeInterval, 取得與前一次觸發的時間差
  - `timeInterval(scheduler: *): Observable<TimeInterval<any>> | WebSocketSubject<T> | Observable<T>`
- timeout, 在指定時間內沒有任何資訊發送的話則關閉 (`complete`)
  - `timeout(due: number, scheduler: Scheduler): Observable`
- timeoutWith, `timeout` 後, 執行指定的 observable
  - `timeoutWith(due: number | Date, withObservable: ObservableInput, scheduler: SchedulerLike = async): OperatorFunction`
- toPromise, 轉換成 promise
  - `toPromise() : Promise`

---
