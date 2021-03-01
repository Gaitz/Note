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

Handbook Reference

---

### 第十五章 - Advanced Types

Type Guards and Differentiating Types
- 對於聯集型別 `|` 做型別判斷後取得窄化型別使用
- User-Defined Types Guards, 使用者自訂的型別判別函式
- Using the `in` operator, 使用 `in` 判斷特定屬性來區分型別
- `typeof` type guards, 原始型別可以使用 `typeof` 協助判斷
- `instanceof` type guards, 藉由 `instanceof` 以建構子函式來判斷型別

Nullable Types
- `--strictNullChecks`, 針對 `null` 與 `undefined` 型別作更嚴格的檢查, 必須使用聯集 `|` 明確指示可能的 `null` 與 `undefined`
- Optional parameters and properties, `?` 選用參數視為 `undefined` 而非 `null`
- Type guards and type assertions, 解決方案有二，1. 藉由判斷型別窄化確定非 nullable, 2. 指定型別斷言為非 nullable (`!`)

Type Aliases
- `type` 類似 `interface` 作為打包型別的工具，支援比 interface 更複雜的型別，例如包含 `|`
- 可以配合 generics 使用 `<>`
- 可以遞迴定義
- 配合 intersection `&` 與遞迴定義 

`interface` vs. `type`
- 所有 `interface` 能達成的功能 `type` 皆可完成
- 關鍵點在於 `interface` 開放擴張 (merging), `type` 無法初始化後擴張
- `interface` 更類似於 JavaScript object
- 官方推薦優先使用 `interface` 直到需要複雜的型別才用 `type`

Enum Member Types

Polymorphic `this` types
- 物件中的函式回傳 `this` 實現 [fluent interface pattern](https://en.wikipedia.org/wiki/Fluent_interface)
- `this` 型別會是依據 constructor, 因此配合 `extends` 實作時也能正確運行

Index types
- 把 union type 可以視為陣列操作
- index type query, `keyof`
- indexed access operator, `[]`
- index types and index signatures, 定義時使用 index signatures `{ []: }` 

Mapped types
- 以 generics 實現型別的函式用來做到型別轉換
- 某些常見的轉換很好用，因此 TypeScript 有打包成標準函式庫，例如 `Pick`, ...

Conditional types
- 型別宣告也有三元運算可以協助使用，` ? : `
- 大多配合 `extends` 回傳 boolean 使用
- Distributive conditional types, 
- Type inference in conditional types, `infer` 

---

### 第十六章 - Utility Types

- 內建的 type transformations
- `Partial<Type>`, 回傳所有屬性變為 optional 的 Type
- `Required<Type>`, 回傳所有屬性變為 required 的 Type
- `Readonly<Type>`, 回傳所有屬性變為 `readonly` 的 Type
- `Record<Keys, Type>`, 用來組合 keys 加上給予的 Type, 形成另外一個 Type
- `Pick<Type, Keys>`, 只選取特定 keys 形成的 Type
- `Omit<Type, Keys>`, 移除特定的 keys 形成的 Type
- `Exclude<Type, ExcludedUnion>`, 執行 union type 的 exclude 形成新的 Type
- `Extract<Type, Union>`, 指定的 Union 中所有允許的 Type 形成的新 Type
- `NonNullable<Type>`, 移除所有的 `null` 與 `undefined` 形成的 Type
- `Parameters<Type>`, 把函式的參數轉換成 tuple Type
- `ConstructorParameters<Type>`, 把 constructor function 轉換成 tuple 或 Array 的 Type
- `ReturnType<Type>`, 取得函式回傳值的型別
- `InstanceType<Type>`, 取得建構子函式型別
- `ThisParameterType<Type>`, 取得函式中指定的 `this` 參數型別
- `OmitThisParameter<Type>`, 移除函式指定的 `this` 參數並且回傳乾淨的型別
- `ThisType<Type>`, 必須配合 `--noImplicitThis` flag 使用

---

### 第十七章 - Decorators

- TypeScript 中實驗性功能, JavaScript 尚未通過標準

---

### 第十八章 - Declaration Merging

- 同名型別宣告合併

Merging Interfaces
- 最常見的 declaration merging
- `interface`

Merging Namespaces
- `namespace`
- `namespace` + `class`
- `namespace` + `function`
- `namespace` + `enum`

Disallowed Merges
- 不允許 `class` 合併

Module Augmentation
- 模組輸出的 `class` 擴充成員
- 需要配合 `declare module` 讓 TypeScript 能認識擴充的成員

Global Augmentation
- 全域變數的擴充
- 需要配合 `declare global` 讓 TypeScript 能認識新成員

---

### 第十九章 - Iterators and Generators

- Iterables, `Symbol.iterator`
- `for..of`
- `for..in` 取 keys, `for..of` 取 values
- Code generation, 轉譯到 ES6 以下版本使用，傳統的 C-like `for`

---

### 第二十章 - JSX

- TypeScript 支援轉譯 `.tsx`
- 需要開啟適合的 JSX options, Modes: `preserve`, `react`, `react-native`, `react-jsx`, `react-jsxdev`
  
The `as` operator
- 型別斷言變成只能使用 `as`, 因為前墜的 `<>` 有語法衝突

Type Checking
- Intrinsic elements, 內建的 element 需要有被 JSX namespace 定義過才能使用
- Value-based elements, `JSX.Element` Function component 與 class component
- Function component, 因為是單純的 function 因此支援 declaration merging 

Attribute Type Checking 

Children Type Checking 

React integration
- 引用 React typing `@types/react`

Configuration JSX
- 有一些 flags 可以控制 JSX compile, `jsxFactory`, `jsxFragmentFactory`, `jsxImportSource`

---

### 第二十一章 - Mixins

- Mixin pattern, 重用 OOP 的模式之一
- 使用 `function` return class 配合 generics extends 的方式定義

Alternative Pattern
- 提供同時在 compile time 與 runtime 都適用的 Mixin pattern

Constraints
- 無法與 decorator 同時使用

---

### 第二十二章 - Modules

- 在 TypeScript 中，檔案含有 `import` 與 `export` 被視為 module，都沒有的時候被視為 script

Export
- Export a declaration, `export` 任意宣告型別
- Export statements, `export {}`, `export { as }`, 重新命名與打包
- Re-exports, 擴充後重新命名輸出, `export { as }`, `export * from `, `export * as from `

Import
- Import a single export from a module, `import {} from `, 重新命名 `import { as } from `
- Import the entire module into a single variable, and use it to access the module exports, `import * as from `
- Import a module for side-effect only, `import ''`
- Import Types, `import type {} from` 只會在 compile time 作用，Runtime 會被移除

Default exports and imports
- `export default`, `import from `

`export =`, `import =`
- TypeScript, AMD, CommonJS

Code Generation for Modules 
- 指定 module system 並且轉譯

Optional Module Loading and Other Advanced Loading Scenarios
- ...

---

### 第二十三章 - Module Resolution

- Module 機制的細節、策略與控制 flags

---

### 第二十四章 - Namespaces

- `namespace` 為 internal modules

Namespacing 
- 作為檔案內的 namespace 避免與第三方函式庫有名稱衝突

Multi-file namespaces
- 跨檔案的 namespace 可以被 declaration merging

Alias
- `import = `, import 時可以取部分重新命名
- import 不使用 `require`, 避免與 module 混淆

Working with Other JavaScript Libraries
- Ambient Namespace, 如果第三方函式庫不是以 module 的方式載入，而是使用全域的方式，則很適合使用 namespace 來避免名稱衝突

---

### 第二十五章 - Namespaces and Modules

- namespace 在過去的 TypeScript 中叫做 `internal module` 被作為 module system 使用

Using Modules
- 推薦優先使用 module 勝過 namespace，因為現在 module system 有原生支援的版本

Using Namespaces
- TypeScript 的管理方式
- 如果應用程式是使用 `<script>` 一次性嵌入所有的相依性時可以使用 (作為 global 上命名碰撞的解法)
- 不適合使用在大型專案中
- namespace 轉換成 module 的方式，參考[文件](https://www.typescriptlang.org/docs/handbook/namespaces-and-modules.html#needless-namespacing)

---

### 第二十六章 - Symbols

- ECMAScript 2015 後 `symbol` 被作為基礎型別被加入

Symbols
- 使用 constructor 建立, `Symbol(?optionString)`
- Symbol 是唯一且獨特的
- 可以作為 object key 使用

Symbols properties
- 參考 mdn [文件](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol)

---

### 第二十七章 - Triple-Slash Directives

- `///` XML 類型的語法，提供給 TypeScript compiler 使用，單一檔案的 compiler option

---

### 第二十八章 - Type Compatibility

- TypeScript 使用 structural typing (duck typing) 與 Java/C# 等其他語言的 nominal typing 不同
- 為了配合 JavaScript 的使用情境才採用 structural typing 設計

Comparing two functions
- 依據函式參數簽名作為 structural typing 依據

Enums
- 無法互相賦值

Class
- 有 structural typing 可互相賦值
- private 與 protected members 也會被考量在 structural typing 裡

Generics
- 一樣依據內部型別的結構可以做到 structural typing
- 考慮實體化後的內部結構

Subtype vs. Assignment
- 比較性通常考量的是 assignment
- 在使用 `strictNullChecks` flag 時 assignment 的允許機制會有所不同
- 參考 [assignment table](https://www.typescriptlang.org/docs/handbook/type-compatibility.html#any-unknown-object-void-undefined-null-and-never-assignability)

---

### 第二十九章 - Type Inference

- 在沒有明確定義型別時，TypeScript 也會自動推論型別
- 通常發生在初始化的階段

Best common type
- 採用最多共用的型別
- 如果沒有時使用聯集組合 `|` 

Contextual Typing
- 會依據背景去推論參數型別
- 當無法推論出參數型別時，會給予 `any`

---

### 第三十章 - Variable Declaration

- 說明 `var`, `let`, `const`

Destructing 
- Array destructing
- Tuple destructing
- Object destructing, Renaming `:`, Default value `=`

Spread
- 展開元素
- `...`

---

Tutorials

---

### 第三十一章 - ASP.NET Core

- ASP.NET + TypeScript
- Setup and basic use

---

### 第三十二章 - Gulp

- build TypeScript with gulp
- Setup and basic use with gulp + babel + uglify

---

### 第三十三章 - DOM Manipulation

- TypeScript 操作 DOM
- 要注意 DOM element 與 event 分別的型別階層

---

### 第三十四章 - Migrating from JavaScript

- React 專案，優先參考 [TypeScript React Conversion Guide](https://github.com/Microsoft/TypeScript-React-Conversion-Guide#typescript-react-conversion-guide)
- setup directories and `tsconfig.json`
- setup configuration file `tsconfig.json`

Integrating with Build Tools
- Gulp
- Webpack, `ts-loader`, `source-map-loader`

Moving to TypeScript Files
- `.js` to `.ts`, `.jsx` to `.tsx`
- using compile options

Weeding out Errors
- Importing from modules, 依據使用的 module system 引入 module 與 types
- Getting Declaration Files, 安裝第三方工具的型別宣告, `@types/`
- Exporting from Modules
- Too many/too few arguments, 配合 function overload 多載不同型別簽名
- Sequentially Added Properties, 1. 直接放到初始化物件中 2. 使用 `interface` 預先定義並且使用型別斷言 `as`
- `any`, `Object`, `{}`, 優先使用 `{}` 然後是 `any`, 記得 `any` 會損失幾乎所有的服務

Getting Stricter Checks
- 開啟越來越嚴格的審核標準
- `noImplicitAny`, 關閉隱性推斷的 `any` 並且給出警告訊息
- `strictNullChecks`, 嚴格審視 `null` 與 `undefined` 可能的存在
- `noImplicitThis`, 隱性的使用 `this` 時會給出警告, 解法是在外部呼叫的函式中帶入參數 `this` 並且指定型別

---

### 第三十五章 - Using Babel with TypeScript

- Babel vs. TypeScript `tsc`, 簡單的情況使用 `tsc` 複雜情況使用 Babel
- Babel 負責轉譯，TypeScript 負責靜態型別檢查
- Babel, preset-typescript
- Babel 無法協助生成 `.d.ts`, 解法是在 `tsconfig.json` 中設置 options 協助 `tsc` 生成

---

### 第三十六章 - What's New

- 提供所有版本的更新指南

---

Declaration Files

---

### 第三十七章 - Introduction

- 手動建立 declaration files 通常用在沒有使用型別的第三方工具庫

文件分類
- Declaration Reference, 提供多個常用的 API 模式並且如何撰寫型別宣告檔案範例
- Library Structures, 修改舊的檔案不需要, 作為撰寫新的 declaration files 提供範例與 templates
- Do's and Don'ts, 常見錯誤，避免與修正
- Deep Dive, 深入 declaration files 底層機制
- Publish to NPM, 如何發布且管理 package
- Find and Install Declaration Files, 安裝與使用其他人建立的 declaration files

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
