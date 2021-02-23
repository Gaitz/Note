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
- 

---

### 第三章 - 型態推斷

---

### 第四章 - 型態設計

---

### 第五章 - 使用 any

---

### 第六章 - 型態宣告與 @types

---

### 第七章 - 編寫與執行你的程式

---

### 第八章 - 遷移至 TypeScript
