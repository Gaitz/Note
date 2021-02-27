## Effective TypeScript 中文版 

### BOOK resource, TypeScript

---

第一章 - 認識 TypeScript

第二章 - TypeScript 的型態系統

第三章 - 型態推斷

第四章 - 型態設計

第五章 - 使用 any

第六章 - 型態宣告與 @types

第七章 - 編寫與執行你的程式

第八章 - 遷移至 TypeScript

---

### 第一章 - 認識 TypeScript

#### 1. 瞭解 TypeScript 與 JavaScript 的關係
- TypeScript 是 JavaScript 的語法超集合加上型別檢查器 (type checker)
- 所有語法正確的 JavaScript 都是 TypeScript 程式
- 副檔名為 `.ts`, `.tsx`
- 即使是一般的 JavaScript 直接轉換成 TypeScript 程式仍然能試圖捕捉到一些錯誤
- 提供型別給 TypeScript 是讓 type checker 更清楚程式設計師的意圖
- TypeScript 使用 type checker 試圖在 build time 模擬 runtime 結果並且嘗試找出錯誤, 這種錯誤是由 TypeScript 主觀定義的

#### 2. 知道你正在使用哪些 TypeScript 選項
- `noImplicitAny`, 一開始就設定為 `true` 讓 TypeScript 不允許隱性的 any, 提早思考且撰寫 type
- `strictNullChecks`, 需要精準的描述 `null` 與 `undefined`, 盡早開啟使用, 否則未來採用時會需要修改很多地方
- 盡早開啟 strict mode
- 確定專案所有人使用相同的 tsconfig.json 

#### 3. 程式碼生成與型態檢查無關
- TypeScript 編譯期會執行兩件事情 1. TypeScript 轉換 JavaScript 與 2. TypeScript type checker, 兩個機制之間沒有關係
- TypeScript type checker error 並不會中止 TypeScript compile to JavaScript
- TypeScript 型別相關功能, `type`, `interface`, `declare` 都只在 build time 有功能, 因此 runtime 實作不能相依在型別上
- 要注意 TypeScript 的 type 與 value, type 不存在 runtime, value 存在 runtime
- 因此 type operators 並不影響 runtime 功能, type 的保證也只存在 build time, runtime (JavaScript) 仍然有可能有不預期的型別

#### 4. 熟悉結構性定型 (duck typing, structural typing)
- type 的辨認不依據名稱, 而是結構, 因此在傳遞時可能會存在與名稱不相同的 bug.
- duck typing 也可以很有彈性不需要特別標示型別之間的關係, 只需要結構相同就能直接使用

#### 5. 限制 any 型態的使用頻率
- 盡可能不要使用 `any`, 使用 `any` 代表無法從 TypeScript 獲得任何好處, 因此有可能藏匿 bug

---

### 第二章 - TypeScript 的型態系統

#### 6. 使用編輯器來查詢與探索型態系統
- 安裝 TypeScript 包含兩個工具 `tsc`, `tsserver`
- `tsserver` 被編輯器使用並且提供服務, 確保使用的編輯器有開啟這些服務
- 利用編輯器提供的服務查看 TypeScript 推論的型別, 並且適時的調整, 更嚴格或更鬆散

#### 7. 將型態視為值的集合
- 把 type 視為允許值的集合 (set)
- 型別的 empty set 為 `never` type, full set 為 `unknown`
- unit type 為 literal type, 直接限制值的型別
- 以集合的角度思考 typing, 配合集合運算思考 `&` `|` `extends` `keyof`
- TypeScript 使用 `{0, 1, ..., length}` 模擬 tuple, 固定長度的 array, 在使用 structural typing 時需要考慮 `length` key
- TypeScript 的 type 不包含所有對應的集合, 因此配合 type operators 時, 只能運算出 TypeScript 允許的型別. 

#### 8. 知道某個代號究竟屬於型態空間還是值空間
- TypeScript 中所有的東西都分別屬於 type space 或 value space
- 最準確判斷的方式是 runtime 後是否還存在, 嘗試編譯後看結果.
- 像是 `instanceof`, `typeof` 在 type space 和 value space 都存在, 但是代表完全不同的運算
- `type`, `:` 後的東西通常屬於 type space, `=` 後的東西通常屬於 value space
- type space 中分層取值使用 `[]`,
- 相同的 keyword 在 type space 與 value space 可能都存在, 要正確的區分其意義

#### 9. 優先使用型態宣告，而非型態斷言
- 指定型別的方式有 `: TypeName` 型別宣告, `as TypeName` 型別斷言
- 優先使用型別宣告, 而非型別斷言, 型別斷言會破壞 TypeScript 的行為
- 在箭頭函式回傳值中宣告型別, 確保結果的型別
- 只有在掌握比 TypeScript 更多資訊時才使用型別斷言, 例如 DOM
- 結尾的 `!` 作為 Nonnull 的型別斷言語法糖

#### 10. 不要使用物件包裝型態 (String, Number, Boolean, Symbol, BigInt)
- 不要使用物件型態的 `String`, `Number`, `Boolean`, `Symbol`, `BigInt` 作為型態, 因為與 primitive type 不同
- 使用小寫的 `string`, `number`, `boolean`, `symbol`, `bigint` 作為型別

#### 11. 認識多餘屬性檢查的侷限性
- 在賦值 object literal 或傳遞給函式時, 會觸發多餘屬性檢查
- 多餘屬性檢查在意義上與 structural typing 有所牴觸, 要正確的區分兩種思想.
- 可以使用中間物件協助避開這個檢查 (也是利用 structural typing 機制)

#### 12. 盡量對整個函式表達式套用型態
- 提供函式型態分離型別與實作 `type FunctionName = (keys: types) => returnType`
- 針對整個函式表達式設置型別, 取代針對個別參數與回傳值設定型別

#### 13. 知道 type 與 interface 的差別
- 幾乎相同
- 差異之處在於 
  - interface 無法 extends 含有聯集的型別 (union) 
  - tuple 宣告使用 type 較為方便
  - interface 有宣告合併功能 (declaration merging)
- 複雜的型別只能使用 type
- 作為給外部使用的型別時 interface 的宣告合併有助於版本更新
- 重點是專案保持一致性

#### 14. 使用型態操作與泛型來避免重複
- 使用 type operators 和宣告型別並且共用減少重複的程式碼
- 使用技巧包含 `extends`, `keyof`, `typeof`, `[]` index, `[k in ]` (mapped type)
- 使用泛型 (generics) 作為型別的函式協助減少重複的程式碼抽出型別運算的重用邏輯
- 熟悉內建的泛型工具
- 在建立型別時專注於要限制檢查的東西, 該拒絕的內容與該允許的內容

#### 15. 讓動態資料使用索引簽章
- index signature, 多數時候因為限制過於鬆散, 不適合使用
- 只使用在不知道 key 與數量的動態資料上

#### 16. 優先使用陣列、tuple 與 ArrayLike 為索引簽章編號
- 由於 JavaScript 的陣列也是物件, 因此其實陣列取值時的 key 也是從數字轉換成字串
- 如果要使用數字做為 index 時, 採用原生陣列, tuple, ArrayLike 作為型別

#### 17. 使用 readonly 來避免意外變動造成的錯誤
- 宣告時使用 `readonly` (type modifier) 提供保護
- 使用 `readonly` 時會變成更嚴格的子型別
- `readonly` 是 shallow 的, 
- 處理物件時可以使用 `Readonly<>` generics, 也是 shallow 的
- 如果資料不會被寫入盡可能的使用 `readonly` 保護, 更容易抓出 bug 也讓函式使用者保證不會修改

#### 18. 使用對映型態來讓值保持同步
- 利用 mapped type 來同步物件之間的 key ，在不同步時 TypeScript 會抓出錯誤
- `{[k in keyof ObjectName]: }`

---

### 第三章 - 型態推斷

- 越來越多強型別語言支援型態推斷
- 在 TypeScript 中盡可能使用型態推斷, 減少不必要的型別宣告.

#### 19. 不要讓可推斷的型態混淆你的程式
- 在 TypeScript 能推斷的型別上加上宣告是多餘的, 並且會降低效能
- 配合編輯器檢查 TypeScript 的推斷是否如預期
- 對於函式應該先定義函式簽名(輸入與輸出的型別)後再實作

#### 20. 用不同的變數來代表不同的形態
- 讓變數只代表一種型別
- 型別改變時創造另一個變數使用，好處有
  - 分離概念, 更準確的名稱, 自動推斷型別, 更簡單的型別, 可以使用 const 取代 let

#### 21. 瞭解型態加寬
- 常數初值時, TypeScript 推斷會 widening, 加寬一點點
- TypeScript 推斷時不一定能準確捕捉到意圖, 因為相同的初始值判別型別會有多種可能的選項
- 可以使用 `const`, `as const`, 明確的註記型別, 提供 context 等方法更準確的定義型別

#### 22. 瞭解型態窄化
- 了解 TypeScript 自動窄化時機並且協助窄化型別
- 在使用型態判別分支後, 變數型別會被 TypeScript 做窄化達到更精準的型別
- 可以設置使用者自訂的窄化函式 (user-defined type guard)，回傳值設定 `is`,

#### 23. 一次建立物件
- 因為 TypeScript 通常是在建立時決定型別, 因此建立物件時應該盡可能的一次建立起完整的物件
- 善用 `...` spread operator, 建立擴張的物件

#### 24. 使用一致的別名
- 建立別名後 (alias) 型別窄化就會分別作用, 為了確保一致性, 使用上要一致使用
- 任意變換使用會導致使用者與 TypeScript 混淆

#### 25. 用 async 函式來編寫非同步程式，不要使用回呼
- 使用 `async`, `await` 取代 callback 與原始的 Promise,
- `async`, `await` 更容易讓 TypeScript 保證型別並且確定是同步或非同步

#### 26. 瞭解型態推斷如何使用背景
- 當型態出現錯誤時使用，變數明確的型態宣告或使用 `const`, `as const`

#### 27. 使用泛函結構與程式庫來協助型態流經程式
- 為了減少使用型態宣告
- 盡可能使用 functional structure, 或第三方 functional 函式庫, 可以更準確的協助 TypeScript 捕捉型別

---

### 第四章 - 型態設計

- 藉由擁有型別讓程式更易懂

#### 28. 盡量使用永遠代表有效狀態的型態
- 正確的型態設計，會讓程式容易撰寫，減少奇異，不相關的東西不要放在一起
- 盡量讓型態只存在有效的狀態，有機會成為無效的狀態在使用上都需要被檢查, 否則會造成錯誤 (容易產生 bug)

#### 29. 寬容低對待你收到的東西，嚴格地看待你產生的東西
- Robustness principle / Postel law
- 輸入型別寬鬆, 輸出型別嚴格

#### 30. 不要在註釋中重複編寫型態資訊
- 不要把型別資訊加在註解與變數名稱上, 重複的資訊多餘的註解, 並且難以維護一致性.

#### 31. 將 null 值推至型態邊緣
- 函式或物件的 `null` 狀態不要分配給個別的值, 應該整理成完全的 `null` 與有效狀態, 更容易使用, 分支更少, 錯誤更少.
- 開啟 `strictNullChecks` 更容易捕捉 null 相關錯誤

#### 32. 盡量使用介面的聯集，而不是聯集的介面
- 讓每個有效狀態形成一個介面, 在使用介面的聯集整合起來, 保持有效狀態
- 在使用時配合 `switch` 個別分支會達到型別窄化
- 型別之間的關係, 不應該放置在註解上, 而是寫在程式中, 讓程式強制維護且描述關係

#### 33. 盡量使用更精確的替代物來取代字串型態
- 不要使用字串作為狀態型別, 字串過於鬆散, 容易產生錯誤
- 定義更精確的型別跟型別聯集來使用

#### 34. 寧可使用不完整的型態，也不要使用不精確的型態
- 如果無法精確的定義型別, 就認份的使用 `unknown` 與 `any`, 錯誤的定義更糟
- 完成精確的定義後, 檢查一下錯誤訊息與自動完成功能是否正常運作, 保持開發者體驗

#### 35. 用 API 與規格生成型態，不是資料
- 用 API Schema 跟正確的規格書 (specification) 來協助建立型別
- 不要使用單純的標準資料建立型別, 容易漏掉 edge case

#### 36. 用你的問題領域的語言來為型態命名
- 使用 domain 資訊來建立精確地命名
- 好的命名提高抽象層, 命名 what, 而非 how / why
- 同樣的概念只有相同的命名
- 避開含糊且多餘的字眼

#### 37. 考慮使用 brand 來進行名義定型
- 在 duck typing 的行為下無法正確區分型別時, 可以考慮使用 brand 來達成 nominal typing
- 使用 brand 參數配合一個 type guard function 乘載判別邏輯

---

### 第五章 - 使用 any

- TypeScript 讓靜態型別模式變成選用的 (optional), 這讓 JavaScript 移植到 TypeScript 可以漸進式的執行

#### 38. 盡量讓 any 型態使用最窄的範圍
- 讓 `any` 的影響範圍最小, 例如只針對個別函式參數, 物件中的個別屬性
- 永遠不要從函式中回傳 `any` 這樣的 any 型別會擴散到其他地方

#### 39. 盡量使用 any 的精準替代物，不要使用一般的 any
- 1. 優先考慮其他型別 2. 使用具型態的 any 家族, 例如 `any[]`, `{[key: string]: any}`, `() => any`, `(arg: any) => any`, `()`

#### 40. 將不安全的型態斷言藏在型態良好的函式內
- 當需要使用不安全的型態斷言時, 可以把它藏在定義清楚的函式中
- 也是為了封裝 any 限制執行範圍, 並且讓使用者操作函式時不需要處理 any

#### 41. 瞭解 any 的演變
- 隱性的 `any` 與 `any[]` 會被 TypeScript 自動推斷成其他型別
- 顯性的 `any` 不會被推斷而會保持 `any`
- 推斷的型別不一定是預期正確的, 最佳的方式還是明確的定義型別

#### 42. 當值的型態不明時，用 unknown 取代 any
- 知道有值但是不確定型別時使用 `unknown` 取代 `any`
- 使用 `unknown` 不會擴散並且會提供錯誤訊息給使用者, 強制使用者決定型別, 例如窄化或斷言

#### 43. 不要 Monkey Patching，而是採取型態安全的做法
- Monkey Patching 不是良好的實務就算要使用也不要使用 any 的 Monkey Patching
- 使用 interface extends 或 interface augmentation 機制提供 monkey patching 讓他受到型別保護

#### 44. 追蹤型態覆蓋率，以防止再次失去型態安全性
- 使用 `npx type-coverage` 與 `npx type-coverage --detail` 追蹤 `any` 型別的數量與狀態
- 適時的思考且修正不必要的 `any` 型別，讓專案更受型別安全保護

---

### 第六章 - 型態宣告與 @types

#### 45. 將 TypeScript 與 @types 放入 devDependencies
- 把 TypeScript 與 @types 安裝在 devDependencies 中

#### 46. 瞭解涉及型態宣告的三種版本
- `@types` 與對應函式庫的版本, TypeScript 版本, `@types` 版本有關. 更新或處理時需要一起思考
- 更新函式庫時一併更新 `@types`

#### 47. 匯出公用 API 的所有型態
- 只要匯出的函式簽名上含有的型態，可以被視為是公開的。
- 因此直接匯出所有型態，方便函式庫使用者使用

#### 48. 使用 TSDoc 來註釋 API
- 使用 TSDoc 與 JSDoc 來提供說明
- `/** */`, `@param`, `@returns`
- 型別定義時也可以加上 TSDoc 註解 
- TSDoc 註解中可以使用 Markdown 語法

#### 49. 在回呼為 this 指定型態
- 如果要使用 `this` 記得幫指定型別

#### 50. 優先使用條件型態，而不是多載的宣告
- 型別可以使用 `?:` 三元運算, 再配合 extends 與 generics 使用時可以提供聯集與個別運算並且產生正確的回傳型別
- 條件型態可以提供更正確的型別
- 優先思考使用條件型態，然後才是多載的宣告

#### 51. 將型態映射至伺服器依賴關係
- 使用 structural typing 自訂非必要的相依型別 (通常來自第三方函式庫)

#### 52. 注意測試型態的陷阱 

---

### 第七章 - 編寫與執行你的程式

#### 53. 優先使用 ECMAScript 的功能，而非 TypeScript 的功能
- 釐清 JavaScript 與 TypeScript 的關係，類似的功能優先使用 ECMAScript 標準的
- 使用 type union 取代 enum
- TypeScript `class` constructor 擁有專屬的 public 參數屬性, 避免混用或不要使用
- TypeScript namespace 與三斜線匯入，過去用來控制 TypeScript module 的專屬工具
- TypeScript decorator，只在配合 Angular 時使用

#### 54. 知道如何迭代物件
- 維護迭代物件時的型別
- 使用 `Object.entries()` 確保型別

#### 55. 瞭解 DOM 階層
- EventTarget 有各自的型別階層，每個型別階層含有各自的屬性。
- Event 事件類別也有各自的型別階層
- 因此在使用時要斷言或確認使用的型別。

#### 56. 不要用 private 來隱藏資訊
- TypeScript 提供的 private 只存在於 build time。
- 在 JavaScript 尚未有標準的 private 工具時，隱藏物件資訊只能使用 `closure` 達成

#### 57. 使用 source map 來對 TypeScript 進行 debug
- 在 development mode 開啟 source map 協助 debugger
- 不要在 production mode 使用並且不要公開 source map 檔案，內容物可能含有原始碼副本。

---

### 第八章 - 遷移至 TypeScript

- JavaScript 遷移至 TypeScript 是漸進式的，大多數情況下無法一次完成。
- TypeScript 比起撰寫 JavaScript 更能避免 bug 的產生。

#### 58. 撰寫現代的 JavaScript
- TypeScript 作為 JavaScript 的 superset，並且會協助轉譯語法。
- 因此採用最新的 JavaScript 語法可以協助撰寫更好的 TypeScript 程式碼，例如以下功能
- ECMAScript module 標準的模組工具 `import` `export`
- 原生的 `class` 物件模組取代建構子函式，TypeScript 更擅長處理 `class` 物件語法
- 使用 `let` `const` 來取代 `var`
- 使用 `for-of` 或其他 functional 方式取代 `for-in`
- 優先使用 arrow function 協助綁定 `this`
- 更簡潔優雅的賦值寫法，解構賦值
- 使用預設函式參數，提供預設值並且 TypeScript 可以掌握型別
- 使用 `async/await` 來處理非同步功能
- 不需要在 TypeScript 裡使用 `'use strict'`，可以開啟 `alwaysStrict` 讓 TypeScript 轉譯 JavaScript 含有嚴格模式

#### 59. 使用 @ts-check 與 JSDoc 來以 TypeScript 進行實驗
- 在 JavaScript 檔案中使用 `@ts-check` 註解協助測試 TypeScript 的執行結果
- 在含有 JSDoc 的程式裡，可以直接註解型別來協助 TypeScript 執行結果
- 最終目的在於搬遷 `.js` 到 `.ts` 而不是含有型別的 `.js`

#### 60. 使用 allowJs 來混合 TypeScript 與 JavaScript
- 在搬遷的過程中可以開啟 `allowJs` 混用 TypeScript 與 JavaScript 一步一步的搬移
- 搬移前確保 bundler 與 test 機制能執行 TypeScript 

#### 61. 在依賴關係圖中，由下往上逐一轉換模組
- 由下往上開始增加型別，尤其是第三方工具與外部 API 優先
- 不要在搬移中同時重構程式碼，在搬移中會暴露出很多設計缺陷，但是避免同時重構。
- 利用編輯器提供的 TypeScript 功能協助轉換

#### 62. 在啟用 noImplicitAny 之前，不要認為遷移已經完成了
- 啟用 `noImplicitAny` 之後才能享有 TypeScript 最重要的好處
- 目標邁向開啟 TypeScript 嚴格模式
- 確定團隊成員熟悉 TypeScript 後前往更嚴格的標準