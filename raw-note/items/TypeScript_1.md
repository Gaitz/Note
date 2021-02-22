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

- TypeScript 盡可能的把錯誤移動到編譯期察覺, 但是仍然會有 runtime error 需要被處理
- 處理方式分為 return null, throw exceptions, return exception, `Option` type

Return Null
- 無法提供錯誤資訊, 需要時常檢查 Nonnull

Throw Exceptions
- 丟出例外, 可以提供錯誤資訊
- 使用 try-catch, 可以避開時常檢查的 Nonnull
- 缺點是不能保證所有人都會使用 try-catch 捕捉可能的錯誤

Return Exception
- TypeScript 需要註明回傳值的型別, 因此會有例外型別的檢查, 被迫必須處理

`Option` type
- 回傳的是容器, 而非值. 
- 無法提供錯誤資訊, 
- `Option<T>` interface, `Some<T>`, `None`
- `flatMap`, 在 chaining 時需要攤平每次的 return containers
- `getOrElse()`, 

---

### 第八章 - 非同步程式設計、共時與平行處理

處理 Callbacks
- Node.js API 慣例回傳第一個參數為錯誤處理
- 普通的 callback 只適合處理最簡單的非同步行為

使用 Promise
- 把 Callback pyramids 攤平成 Chain 的形式

使用 `async` 和 `await`

Async Streams
- 處理非同步的事件串流
- 處理模式常見的有 event emitter, reactive programming
- Event emitter 是 JavaScript 中常見的模式

多執行序處理 multithreading
- 瀏覽器中使用 Web Workers, 取代 shared memory 使用 message passing 機制
- Node.js 中使用 Child Processes

---

### 第九章 - 前端與後端框架

前端框架
- DOM API,
- React, TSX = JSX + TypeScript
- Angular
- API 層, Swagger, GraphQL, gRPC

後端框架
- 使用 TypeScript ORM

---

### 第十章 - Namespaces.modules

import, export

Code splitting
- code splitting
- lazy-load

TypeScript Module Mode vs. Script Mode
- 檔案內有 `import` `export` 則使用 Module Mode

`namespace` in TypeScript
- 選擇使用 Module 優於 Namespace
- `namespace { export }`
- namespace 可以是 nested 
- 使用時使用 `.` 連結, 在 import 時可以 alias
- namespace 會編譯成 IIFE module 模式

宣告合併 merging
- 在同個 scope 下時, 有些元素可以對應同名合併達到功能擴充

---

### 第十一章 - 與 JavaScript 的交互作業

與 legacy JavaScript codebase 合作與 immigrating 策略

型別宣告 type declaration
- `.d.ts`
- `declare`
- `declare let`, `declare module`
- 在沒有 TypeScript 原始碼的情況下提供 types

Migrating JavaScript to TypeScript
1. 加入 TSC, tsconfig.json 中 `"compilerOptions": { "allowJs": true }`
   - Optional 為現有的 JavaScript 開啟型別檢查, 由 TypeScript 自行推論, `"compilerOptions": { "checkJs": true }`
   - Optional 使用 JSDoc Annotations, 協助 TypeScript 更精準的推論型別
1. 一次更新一個檔案為 `.ts`, 切換 strict mode 一步一步的修正錯誤
1. 最後關閉 JavaScript 檢查並且開啟嚴格模式

第三方的 JavaScript
- 分成幾種情況
1. 已經內建有型別宣告
1. 不包含型別宣告, 但是能在社群維護的 DefinitelyTyped 找到 `@types`
1. 不包含型別宣告並且社群沒有支援, 處理方式有 `//@ts-ignore`, `.d.ts` + `declare module` without implement, `declare module` with implements

---

### 第十二章 - 建置與執行 TypeScript

專案布局 project layout
- `src/` to `dist/`
- 生成的檔案們, `.js`, `.js.map` (source map), `.d.ts` (type declaration), `.d.ts.map` (type declaration maps)

決定編譯目標 targets
- `target` JavaScript 版本
- `module` 設定模組模式
- `lib` 設定額外的環境功能, 與添加 polyfills

Source Map
- 在 development mode 時開啟, production mode 時關閉

tsconfig.json `extends`
- 使用 `extends` 來切割管理 tsconfig

錯誤監控
- Sentry
- Bugsnag

---

### 第十三章 - 結論

---

### 第十四章 - 附錄

- Type operators
- Type utilities
- Declaration and merging
- 撰寫第三方 `.d.ts` 的策略
- Triple-slash directives `///`
- TSC strict flags
- TSX, 使用 TSX 但是不使用 React 時的工作
