## TypeScript Official documentation

### [TypeScript official documentation](https://www.typescriptlang.org/docs/handbook/intro.html), TypeScript

---

Getting Stated

第一章 - TS for the New Programmer

第二章 - TypeScript for JS Programmers

第三章 - TS for Java/C# Programmers

第四章 - TS for Functional Programmers

第五章 - TypeScript Tooling in 5 minutes

Handbook

第六章 - The TypeScript Handbook

第七章 - Basic Types

第八章 - Interfaces

第九章 - Functions

第十章 - Literal Types

第十一章 - Unions and Intersection Types

第十二章 - Classes

第十三章 - Enums

第十四章 - Generics

Handbook Reference

第十五章 - Advanced Types

第十六章 - Utility Types

第十七章 - Decorators

第十八章 - Declaration Merging

第十九章 - Iterators and Generators

第二十章 - JSX

第二十一章 - Mixins

第二十二章 - Modules

第二十三章 - Module Resolution

第二十四章 - Namespaces

第二十五章 - Namespaces and Modules

第二十六章 - Symbols

第二十七章 - Triple-Slash Directives

第二十八章 - Type Compatibility

第二十九章 - Type Inference

第三十章 - Variable Declaration

Tutorials

第三十一章 - ASP.NET Core

第三十二章 - Gulp

第三十三章 - DOM Manipulation

第三十四章 - Migrating from JavaScript

第三十五章 - Using Babel with TypeScript

第三十六章 - What's New

Declaration Files

第三十七章 - Introduction

第三十八章 - Declaration Reference

第三十九章 - Library Structures

第四十章 - .d.ts Templates

第四十一章 - Do's and Don'ts

第四十二章 - Deep Dive

第四十三章 - Publishing

第四十四章 - Consumption

JavaScript

第四十五章 - JS Projects Utilizing TypeScript

第四十六章 - Type Checking JavaScript Files

第四十七章 - JSDoc Reference

第四十八章 - Creating .d.ts Files from .js files

Project Configuration

第四十九章 - What is a tsconfig.json

第五十章 - Compiler Options in MSBuild

第五十一章 - TSConfig Reference

第五十二章 - tsc CLI Options

第五十三章 - Project References

第五十四章 - Integrating with Build Tools

第五十五章 - Configuring Watch

第五十六章 - Nightly Builds

---

Getting Stated

---

### 第一章 - TS for the New Programmer

- 介紹 JavaScript 簡史

TypeScript
- TypeScript 提供靜態型別檢查，提早在 compile-time 盡可能的找出錯誤
- 語法上是 JavaScript 的 superset
- Types, TypeScript 利用型別去做錯誤偵測
- TypeScript 不會影響 JavaScript 的 runtime 行為，主要目的只是做靜態檢查盡可能抓出錯誤
- 所有的型別只與 build time 靜態檢查有關，當編譯成 JavaScript 後型別功能會完全移除。

Learning JavaScript and TypeScript
- TypeScript 作為 JavaScript 的 superset 不可能只學 TypeScript 而無視 JavaScript
- 作為單純的 compile-time 靜態型別檢查，所有的 JavaScript solution 也都可以是 TypeScript solution

---

### 第二章 - TypeScript for JS Programmers

Types by Inference
- 型別推理, TypeScript 會自動推理型別，只有在型別與預期不同時才手動增加。

Defining Types
- 定義型別
- `interface`, `:`, `type`
- 文件推薦優先使用 `interface` 直到需要特定功能時才使用 `type`
- 基礎型別，都是全小寫
  - `boolean`
  - `bigint`
  - `null`
  - `number`
  - `string`
  - `symbol`
  - `object`
  - `undefined`
  - `any`
  - `unknown`
  - `never`
  - `void`

Composing Types
- 型別組合與運算
- Unions, 聯集, `|`
- 型別檢查方式
  - `string`: `typeof s === "string"`
  - `number`: `typeof n === "number"`
  - `boolean`: `typeof b === "boolean"`
  - `undefined`: `typeof undefined === "undefined"`
  - `function`: `typeof f === "function"`
  - `array`: `Array.isArray(a)`
- Generics, 泛型, `<>`

Structural Type System
- TypeScript 型別比較使用 Structural Typing (Duck Typing)，依據結構而非名稱。

---

### 第三章 - TS for Java/C# Programmers

Co-learning JavaScript
- 推薦優先學好 JavaScript 然後再學習 TypeScript 的型別系統與 Java/C# 的不同之處

Rethinking the Class
- C# 與 Java 程式最基本的單位就是 class 
- JavaScript 允許自由的 function 與 data 不需要預先包成類別或其他型態
- Singleton pattern 與 static class 不需要被使用，因為 TypeScript (JavaScript) 是 prototype based 

OOP in TypeScript
- TypeScript 包含 JavaScript 標準的 `class` 語法並且有所擴充

Rethinking Types
- Nominal typing vs. Structural typing
- Java/C# 使用 Nominal typing 使用定義名稱形成物件階層
- TypeScript 使用 Structural typing 比較結構而非名稱來判斷型別
- Types as Sets, 把型別想成是集合，而非單純的階層，因此 TypeScript 提供很多集合方式的型別操作功能，例如 union `|`
- TypeScript 的型別只會使用在 compile-time，並且在 runtime 移除

---

### 第四章 - TS for Functional Programmers

- TypeScript 原先想要嘗試將傳統的 OOP (typed, class-based) 帶給 JavaScript 使用
- TypeScript 的型別採用後輟方式呈現 (`variable: type`)
- Built-in Types
- Gradual typing, 漸進式的型別系統, 擁有 `any` 等不嚴謹的型別類型
- Structural typing
- Type Unions (`|`) and Intersections (`&`), 把型別視為集合
- Unit Types, 實字型別, 可以使用聯集實字型別達到類似 `enum` 的效果
- `readonly`, `const`

---

### 第五章 - TypeScript Tooling in 5 minutes

Install TypeScript
- npm

TypeScript File
- `.ts` 

Compile 
- `tsc`
- 儘管有型別錯誤但是並不會停止轉譯成為 JavaScript

Interfaces
- 使用 `interface` 並且因為 structural typing 的關係, 可以不需要 `implements` 即可使用

Classes
- 實現 class-based OOP

---

Handbook

---

### 第六章 - The TypeScript Handbook

- Handbook, 提供基本教學, 理解大部分的概念
- Handbook reference, 提供每個概念更深入的理解

---

### 第七章 - Basic Types

Boolean
- `boolean`

Number
- `number`
- `bigint`

String
- `string`

Array
- `[]`
- `Array<>`

Tuple
- 固定長度的 Array 為 Array 的子集合
- JavaScript 沒有

Enum
- `enum`
- JavaScript 沒有

Unknown
- `unknown`, 預計有值但是不確定型別, 會拒絕取用 property
- JavaScript 沒有
- 可以通過型別判斷達到窄化 (narrow) 型別後使用

Any
- `any`, 任意型別, 不檢查型別, 並且可以任意取用 property
- 使用 `any` 代表拿不到任何 TypeScript 提供的好處

Void
- `void` 只作為函式回傳型別代表沒有回傳值

Null and Undefined
- `undefined`, `null`

Never
- `never`
- 所有型別的子型別
- 代表不會發生的狀況, 例如函式有無窮迴圈的回傳值

Object
- `object`

Type assertions
- 型別斷言, 指定型別給 TypeScript 
- 方式有二 `as`, `<>`
- 通常使用 `as` 因為 `<>` 法會與 JSX 語法衝突

About Number, String, Boolean, Symbol and Object
- 避開物件型別, 因為 JavaScript 會對原始型別做 boxing

---

### 第八章 - Interfaces

- `interface`
- Duck typing, structural typing
- Optional properties `?`
- Readonly properties `readonly`, `ReadonlyArray<>`
- Variable use `const`, Properties use `readonly`
- Function Types, `interface { (): }`
- Indexable Types, index signature, `[ : ]: `
- Class Types, `interface` + `class implements`, constructor interface
- Extending interfaces, `extends`, 可以 extends 多個
- Hybrid Types, 同時為物件和函式, `interface { (): ; }`, 函式型定義 `():`, 物件型定義 `methodName():`
- Interfaces Extends Classes, interface 可以使用 `extends` 一個 class 包含 `private`, `protected` members

---

### 第九章 - Functions

Function Types
- `( ): returnType {}`
- 只定義函式型別, 語法類似箭頭函式, `() => returnType`
- 利用預先定義函式型別, 可以讓 TypeScript 直接推理 function type (contextual typing), 可以視為分離型別定義與實作

Optional and Default Parameters
- TypeScript 會阻擋太多或太少的參數傳遞 (JavaScript 不會)
- 使用 optional parameters `?`
- 使用 default parameters `=`, 如果設定 default parameters 並非在順序的尾端時, 必須明確傳入 `undefined` 才會觸發

Rest Parameters
- `...` 可以被視為無數量上限的 optional parameters

`this`
- 善用 arrow function 協助綁定
- this parameters, 函式定義時可以宣告顯性的 `this` 參數 `(this: )`, 作為第一個參數, 協助 TypeScript 抓出 this pointer 錯誤

Overloads
- 同名函式多載
- 先定義多個多載型別，實作時使用型別判斷達到 narrow 後做個別的處理

---

### 第十章 - Literal Types

- 實字型別, 更嚴格的子型別
- 實字型別包含 strings, numbers, booleans
- 通過 `const` 定義, 窄化 (narrow) 推斷型別成實字型別

String Literal Types
- 配合聯集使用 `|` 可建立類似 enum 的功能

---

### 第十一章 - Unions and Intersection Types

Union Types
- 聯集 `|`

Unions with Common Fields + Discriminating Unions
- Union 形成的型別，可以視為一個獨立的型別
- 在沒有使用型別分支確定之前，可以使用的屬性只有聯集共有的

Intersection Types
- 交集 `&`
- 組合各型別屬性形成一個

---

### 第十二章 - Classes

- TypeScript 提供 class-based OOP 方式
- `class { constructor() {} }`, `new`
- Inheritance `extends`, `super`

Public, private and protected modifiers
- TypeScript default 是 public
- ECMAScript private field, JavaScript 原生的 private 語法, `#`, TypeScript 3.8 以上支援
- TypeScript 自有的 `private` modifier, 對應到 structural typing 時, 必須使用 `extends` 來繼承 private members
- TypeScript 自有的 `protected` modifier, 只能由本身或是子類別 (subclass) 中呼叫, `constructor` 也可以使用
- `readonly` modifier, 記得在 `constructor` 中初始化 `readonly` members

Parameter properties
- 直接在 `constructor()` 中配合 `readonly`, `private`, `public`, `protected` 自動建立 members
- 一種語法糖, 避免與傳統方式混用, 則一使用提供一致性的開發體驗

Accessors
- getter function `get`, setter function `set`

Static Properties
- `static`

Abstract Classes
- `abstract`
- 提供 abstract class 與 abstract members

Constructor functions
- JavaScript 較為原生的 constructor function 建立 object

Using a class as an interface
- 在 TypeScript 裡 `interface` 可以 `extends` class

---

### 第十三章 - Enums

- `enum` 是少數會影響 runtime 的 TypeScript 語法
- Numeric enums, 類似於其他語言的 `enum`
- String enums, 在 runtime 會轉譯成為一般字串
- Heterogeneous enums, 異質性的 enum 除非有 JavaScript runtime 使用需求，否則不需要使用
- Computed enums, `enum` 的值可以是 computed 的

Union Enums and enum member types
- Enum 可以被視為 literal value 使用

Enums at runtime
- `enum` 會轉譯為物件

Enums at compile time
- 在 compile time 時使用 TypeScript 的 `keyof typeof` 會取得 `enum` 的 key string union

Reverse mappings
- 把 enum value 傳給 enum 來取得 key
- 不要使用

const enums
- `const enum` 這種類型的 enum 只存在 compile time，runtime 會被移除

Ambient enums
- ?

---

### 第十四章 - Generics

- `<>` 提供泛型
- Generics Types, 可以利用泛型建立出型別用的函式
- 配合 `interface`, `extends`, 讓泛型型別能使用特定的屬性 

---

### Handbook Reference

---

### 第十五章 - Advanced Types

---

### 第十六章 - Utility Types

---

### 第十七章 - Decorators

---

### 第十八章 - Declaration Merging

---

### 第十九章 - Iterators and Generators

---

### 第二十章 - JSX

---

### 第二十一章 - Mixins

---

### 第二十二章 - Modules

---

### 第二十三章 - Module Resolution

---

### 第二十四章 - Namespaces

---

### 第二十五章 - Namespaces and Modules

---

### 第二十六章 - Symbols

---

### 第二十七章 - Triple-Slash Directives

---

### 第二十八章 - Type Compatibility

---

### 第二十九章 - Type Inference

---

### 第三十章 - Variable Declaration

---

Tutorials

---

### 第三十一章 - ASP.NET Core

---

### 第三十二章 - Gulp

---

### 第三十三章 - DOM Manipulation

---

### 第三十四章 - Migrating from JavaScript

---

### 第三十五章 - Using Babel with TypeScript

---

### 第三十六章 - What's New

---

Declaration Files

---

### 第三十七章 - Introduction

---

### 第三十八章 - Declaration Reference

---

### 第三十九章 - Library Structures

---

### 第四十章 - .d.ts Templates

---

### 第四十一章 - Do's and Don'ts

---

### 第四十二章 - Deep Dive

---

### 第四十三章 - Publishing

---

### 第四十四章 - Consumption

---

JavaScript

---

### 第四十五章 - JS Projects Utilizing TypeScript

---

### 第四十六章 - Type Checking JavaScript Files

---

### 第四十七章 - JSDoc Reference

---

### 第四十八章 - Creating .d.ts Files from .js files

---

Project Configuration

---

### 第四十九章 - What is a tsconfig.json

---

### 第五十章 - Compiler Options in MSBuild

---

### 第五十一章 - TSConfig Reference

---

### 第五十二章 - tsc CLI Options

---

### 第五十三章 - Project References

---

### 第五十四章 - Integrating with Build Tools

---

### 第五十五章 - Configuring Watch

---

### 第五十六章 - Nightly Builds

---
