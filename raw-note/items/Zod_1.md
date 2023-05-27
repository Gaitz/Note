## Zod official documentation

### [Zod.dev](https://zod.dev/), Front-end/Zod

---

第一章 - Introduction

第二章 - Installation

第三章 - Basic Usage

第四章 - Primitives

第五章 - Coercion for primitives

第六章 - Literals

第七章 - Strings

第八章 - Numbers

第九章 - BigInts

第十章 - NaNs

第十一章 - Booleans

第十二章 - Dates

第十三章 - Zod enums

第十四章 - Native enums

第十五章 - Optionals

第十六章 - Nullables

第十七章 - Objects

第十八章 - Arrays

第十九章 - Tuples

第二十章 - Unions

第二一章 - Discriminated unions

第二二章 - Records

第二三章 - Maps

第二四章 - Sets

第二五章 - Intersections

第二六章 - Recursive types

第二七章 - Promises

第二八章 - Instanceof

第二九章 - Functions

第三十章 - Preprocess

第三一章 - Custom schemas

第三二章 - Schema methods

第三三章 - Guides and concepts

第三四章 - Comparison

---

### 第一章 - Introduction

---

### 第二章 - Installation

- Typescript 4.5+
- 必須開啟 TypeScript `strict`

---

### 第三章 - Basic Usage

- `import { z } from "zod";`
- `z.string()`
- `parse()`, 錯誤時丟出 Error, 成功時回傳 `true`
- `safeParse()`, 錯誤時回傳 Object `{ success: false, error }`, 成功時回傳, `{ success: true, data }`
- `z.infer` 取得 TypeScript type

---

### 第四章 - Primitives

primitive values

- `string()`
- `number()`
- `bigint()`
- `boolean()`
- `date()`
- `symbol()`

empty types

- `undefined()`
- `null()`
- `void()`

catch-all type, allows any value

- `any()`
- `unknown()`

never type, allows no values

- `never()`

---

### 第五章 - Coercion for primitives

- 內建強制轉換型別的定義
- `coerce`
- `coerce.string()`, String(input)
- `coerce.number()`, Number(input)
- `coerce.boolean()`, Boolean(input)
- `coerce.bigint()`, BigInt(input)
- `coerce.date()`, new Date(input)
- Boolean coercion, 會依據 truthy 與 falsy 轉換成 `true` 與 `false`

---

### 第六章 - Literals

- `literal()`

---

### 第七章 - Strings

- `string()`

validations

transformations

- 可以客製化錯誤訊息
- 通過傳入 object

ISO datetimes

- 判別 UTC
- 可以依據 optional 判別是否加上時區 `offset`
- 與精準度 `precision`

IP address

- 可以判別 IPv4 與 IPv6 兩種格式
- 可以通過 `version` option 指定

---

### 第八章 - Numbers

validations

- `number()`

---

### 第九章 - BigInts

- 有針對 bigint 執行 validations
- `bigint()`

---

### 第十章 - NaNs

- `nan()`

---

### 第十一章 - Booleans

- `boolean()`

---

### 第十二章 - Dates

- `date()` 驗證 `Date`

Coercion to Date

- `coerce.date()`, 內部使用 `new Date(input)`

---

### 第十三章 - Zod enums

- `enum()`, 只支援 string enum
- input 是 `string[]`

Autocompletion

- `.enum.`
- `.options` 可以取得原始的 string[]

---

### 第十四章 - Native enums

- `nativeEnum()`
- TypeScript enum 因此允許 number enum, string num, 混合, 與使用 `as const`

---

### 第十五章 - Optionals

- `optional()`
- input 是 Zod schema
- 產生允許 `undefined` 的 schema
- 可以通過 `unwrap()` 轉換 optional schema 成原本的版本

---

### 第十六章 - Nullables

- `nullable()`
- 產生允許 `null` 的 schema
- 同樣可以通過 `unwrap()` 轉換成原本的版本

---

### 第十七章 - Objects

- `object()`
- `shape()` 取得指定 key 的 schema
- `keyof()` 取得 ZodEnum 版本的 key string array
- `extend()`
- `merge()`
- `pick()`, `omit()`, 對應 TypeScript 的 `Pick` 與 `Omit`
- `partial()`, 對應 TypeScript 的 `Partial`
- `deepPartial()`
- `required()` 等同於 `partial()` 的反向
- `passthrough()`, 允許帶入未定義的 key
- `strict()`, 遇到未定義的 key 時會丟出 `ZodError`
- `strip()`, 重置 object schema 回原本的行為
- `catchall()`, 指定未定義 key 的型別

---

### 第十八章 - Arrays

- `array()`
- `element()` 取得 array element schema
- `nonempty()`, 指定非空
- validation `min()`, `max()`, `length()`

---

### 第十九章 - Tuples

- `tuple()`
- 固定長度的 array
- `rest` 捕捉不固定長度的部分

---

### 第二十章 - Unions

- `union()`, or

---

### 第二一章 - Discriminated unions

- `discriminationUnion()`, |

---

### 第二二章 - Records

- `record()`, 等同於 `{ [k: string]: }`
- 不同於 `object()` 同時驗證 key 與 value
- `record()` 只驗證 value

Record key type

- 如果要同時驗證 key 與 value 時, 可以傳入雙變數

---

### 第二三章 - Maps

- `map()` 對應 `Map<>` 型別

---

### 第二四章 - Sets

- `set()` 對應 `Set<>` 型別
- validation, `nonempty()`, `min()`, `max()`, `size()`

---

### 第二五章 - Intersections

- `intersection()`, `and()` 同時符合的部分
- 推薦優先使用 `merge()` 連接兩個物件

---

### 第二六章 - Recursive types

- 使用 `lazy()`, `extend()` 產生定義 recursive types

ZodType with ZodEffects

- ZodType
- ZodEffects

JSON type

Cyclical objects

---

### 第二七章 - Promises

- `promise()`
- 會同時驗證 Promise 和回傳值的型別

---

### 第二八章 - Instanceof

- `instanceof()`
- 用來取得 `class` 的 instance schema

---

### 第二九章 - Functions

- `function(args, returnType)` 同時定義
- `function()`, `.args()`, `.returns()` 分開定義
- `implement()` 同時撰寫函式內容, 並且讓 Zod 自動判別 return type
- `void()` 可以指定沒有回傳值
- `.parameters()` 取得 input 的型別
- `.returnType()` 取得 return value 的型別

---

### 第三十章 - Preprocess

- `.preprocess()`
- 允許自行定義的前置轉換函式

---

### 第三一章 - Custom schemas

- `custom()` 自訂型別與驗證函式

---

### 第三二章 - Schema methods

`parse()`

- 傳入驗證值

`parseAsync()`

- 如果使用 `refine()` 定義時則需要使用 `parseAsync()` 版本

`safeParse()`

- 取代丟出 Error 改以回傳含有狀態值的 object 取代

`safeParseAsync()`

- 非同步版本的 `safeParse`

`refine()`

- 定義自己的驗證函式與錯誤訊息
- 甚至允許 async function 作為驗證函式

`superRefine()`

- 客製化用的 syntax sugar

`transform()`

- 轉換 input value
- 提供一個函式用於 parsing 之後

`default()`

- 傳入預設值

`describe()`

- 提供與 schema 綁定的文字敘述

`catch()`

- 當遇到錯誤時的回傳值
- 可作為補救時的預設值

`optional()`

- 允許 `undefined`

`nullable()`

- 允許 `null`

`nullish()`

- 允許 `undefined` 和 `null`

`array()`

- 轉換成 array

`promise()`

- 轉換成 promise

`or()`

- 等同於 `union()`

`and()`

- 等同於 `intersection()`

`brand()`

- 因為 TypeScript 是 duck typing
- 因此如果要比對型別名稱時, 需要使用 `brand<>()` 綁定名稱
- 底層則是以 Symbol 來實作

`pipe()`

- 配合 `transform()` 可以進行二次驗證

---

### 第三三章 - Guides and concepts

Type inference

- `z.infer<typeof mySchema>` 取得 schema 對應的 TypeScript Type
- 與 `transform()` 一起使用時, 則可以通過 `z.input()`, `z.output()` 取得對應的型別

Writing generic functions

Error Handling

- 會丟出 `ZodError`
- `error.issues` 回傳錯誤訊息的 array
- `format()`, 轉換成 error object 成 nested object

---

### 第三四章 - Comparison

---
