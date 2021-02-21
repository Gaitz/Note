## TypeScript 程式設計, O'Reilly

### BOOK resource, TypeScript

---

第一章 - 簡介

第二章 - TypeScript: 10_000 英尺高的觀點

第三章 - 全部關於型別

第四章 - 函式 (Functions)

第五章 - 類別與介面

第六章 - 進階型別

第七章 - 處理錯誤

第八章 - 非同步程式設計、共時與平行處理

第九章 - 前端與後端框架

第十章 - Namespaces.modules

第十一章 - 與 JavaScript 的交互作業

第十二章 - 建置與執行 TypeScript

第十三章 - 結論

第十四章 - 附錄

---

### 第一章 - 簡介

- TypeScript 會在 build time 做型別檢查, 可以配合編輯器 plugin 讓在編輯時就一同檢查
- 設計時會變成先思考型別, 順帶考慮到更多的 edge cases

---

### 第二章 - TypeScript: 10_000 英尺高的觀點

TypeScript Compiler
- 編譯器把 TypeScript 編譯成 JavaScript 之前, 會先經過 Typechecker 的型別檢查
- TypeScript 的 type 與編譯後的 JavaScript 完全沒有關係

Type Systems
- 不需明確標示型別, 在 Runtime 時推論型別
- 明確指示型別並且在 Compiler time 受到檢查
- TypeScript 同時支援兩者
- TypeScript 指定型別 `value: type`, 型別註解於 `:` 後
- Practice: 讓 TypeScript 盡可能推論型別, 明確指定型別越少越好

TypeScript Type system
- 作為 gradually typed, TypeScript 並不需要知道全部的型別才能運作, 因此可以漸進式的移植舊有的 JavaScript codebase

安裝 TypeScript
- NPM `typescript`, `tslint`
- 建立設定檔 `tsconfig.json`, 手動建立或者使用 TSC cli `--init`
- `tsconfig.json`, 常見設定說明:
  - `include`, 輸入檔案來源
  - `lib`, 包含哪些 JavaScript 語法或環境
  - `module`, 使用的模組系統
  - `outDir`, 輸出檔案位置
  - `strict`, 嚴格檢查與否
  - `target`, 目標 JavaScript 版本
- `tslint.json`, 選用的 linter
- `index.ts`

---

### 第三章 - 全部關於型別

- Type 包含允許的值與允許的動作
- Type literal, 在配合 `const` 時, primitive type 會被指定為 type literal, 提供更強大的保護
- 型別別名 type alias, `type` 定義型別, block-scoped
- 型別運算子 type operators, Union `|`, Intersection `&`

any
- 任意型別, 即停止 TypeScript 的功能

unknown
- 使用 unknown 取代 any, 
- 在配合 `typeof` 或 `instanceof`  後, unknown 可以變成指定的型別

boolean
- `true`, `false`
- logic operators

number
- 數字
- 數值算子
- TypeScript 中數字可以使用 `_` 作為分隔, 包含值與型別

bigint
- JavaScript 與 TypeScript 新的型別, 確保整數運算不會遇到 rounding error
- 大型整數
- 數值算子

string
- 字串
- 字串算子

symbol
- JavaScript ES2015 新的型別
- 配合 `const` 或明確定義 `unique symbol` 產生 type literal

object
- 使用 `{}` 定義物件時能讓 TypeScript 正確的推論物件型別
- JavaScript 與 TypeScript 採用 structurally typed (duck typing), 所以在結構一樣時, 就算名稱不同仍能被視為相同的物件類型
- 定義物件型別時, 可以有 `optional` 定義, `?`, `[key: ]`
- 修飾型別 `readonly` 視為唯讀

array
- 型別定義 `T[]` or `Array<T>`
- 可以配合 `readonly`, `Readonly<>`, `ReadonlyArray<>` 達到 TypeScript 保證的 immutable, 希望大量使用 immutable 時最好採用其他 library 來保證效能

tuple
- array 的 subtype
- 固定長度的 array, 需要明確定義, 可以配合 `?` 與 `...` 使用
- 可以配合 `readonly` 達到 TypeScript 保證的 immutable
- 可以配合 `readonly`, `Readonly<>`, `ReadonlyArray<>` 達到 TypeScript 保證的 immutable, 希望大量使用 immutable 時最好採用其他 library 來保證效能

null, undefined, void, never
- void, 沒有回傳值
- never, 用在無窮迴圈的函式與丟出錯誤的函式

Enums
- `enum`, unordered, key-value pair, 
- enum 名稱大寫, 單數, key 大寫
- `enum` 有很多安全性問題要注意, 因此盡可能不要使用, 或者加上 TSLint

---

### 第四章 - 函式 (Functions)

宣告
- 參數, 可以有 optional `?` 或 default `=`, rest `...`

`this`
- TypeScript function 如果要用到 this 時, 可以宣告成第一個參數 this 並且指定型別

支援 Generator function 與 iterators

Function Type
- 簡寫版 `type` 函式定義 `type Fn = (...) => ...`
- 複雜版 `type Fn = { (...): ... }`

Function Overloaded
- 重載函式
- 可以用複雜版 Function Type 多重定義

Generic Type
- 泛型
- `<T>`
- 可以有預設值 `=`

Type-driven development
- 先設計且定義出 type 後才實作內容

---

### 第五章 - 類別與介面

類別
- `class`
- `extends`
- `constructor(){}`
- `public`, default
- `private`
- `protected`
- `new`
- `abstract`, abstract class 與 abstract method
- `static`
- `super`

介面
- `interface`
- 類似於 `type`, 但是 `type` 更有彈性
- `implements`

類別與介面都可以使用 `<>` generic type

Mixins
- 自行實作

裝飾器 decorator
- TypeScript 提供 decorator 語法 `@`

模擬 final class
- 通過 private constructor 自行實作

Design Patterns
- Factory Pattern
- Builder Pattern

---

### 第六章 - 進階型別

Subtype and Supertype

Advanced type operators
- keying-in, `[ ]`, 藉由其他 type 的 key-in 取得
- `keyof` 取得指定 type 第一層的所有的 key 作為 type
- `Record<>`, type set 的 mapping 形成的 key-value pairs type set
- Mapped types, `{ [Key in UnionType]: ValueType }`
- 內建的 Mapped types, `Record<Keys, Values>`, `Partial<Object>`, `Required<Object>`, `Readonly<Object>`. `Pick<Object, Keys>`
- Companion object patter, 利用 merging 機制, 讓同名的 type 與實作同時存在相同的 namespace 下
- User-defined type guard, `is`, 定義的 function 回傳值是 boolean 時可以使用 `is` 來決定, 輸入值的型別, 避免繁瑣的 `typeof` 與 `instanceof`
- Conditional types, `extends ? : `,
- `infer`
- 內建的 Conditional types, `Exclude<T, U>`, `Extract<T, U>`, `NonNullable<T>`, `ReturnType<F>`, `InstanceType<T>`

Escape hatches 逃脫口, 盡可能不要使用
- 型別斷言, 使用 `as` 指定
- Nonnull 斷言, `!.`
- Definite assignment checks, 指定一定存在 `!:`

模擬名義型別 type branding
- 因為 TypeScript 使用 structural typing, 因此型別命名只是別稱, 沒辦法作為型別判斷用途
- 採用 type brand, `& { readonly brand: unique symbol }` 綁定為獨立的型別即以名稱判別的 nominal types

---

### 第七章 - 處理錯誤

---

### 第八章 - 非同步程式設計、共時與平行處理

---

### 第九章 - 前端與後端框架

---

### 第十章 - Namespaces.modules

---

### 第十一章 - 與 JavaScript 的交互作業

---

### 第十二章 - 建置與執行 TypeScript

---

### 第十三章 - 結論

---

### 第十四章 - 附錄

---

