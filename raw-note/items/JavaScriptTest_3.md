## Jest Official Documents

[Website resource](https://jestjs.io/en/), Jest, JavaScript/Testing

---

Introduction

第一章 - Getting Started

第二章 - Using Matchers

第三章 - Testing Asynchronous Code

第四章 - Setup and Teardown

第五章 - Mock Functions

第六章 - Jest Platform

第七章 - Jest Community

第八章 - More Resources

Guides

第九章 - Snapshot Testing

第十章 - An Async Example

第十一章 - Timer Mocks

第十二章 - Manual Mocks

第十三章 - ES6 Class Mocks

第十四章 - Bypassing module mocks

第十五章 - Using with webpack

第十六章 - Using with puppeteer

第十七章 - Using with MongoDB

第十八章 - Using with DynamoDB

第十九章 - DOM Manipulation

第二十章 - Watch Plugins

第二十一章 - Migrating to Jest

第二十二章 - Troubleshooting

第二十三章 - Architecture

Framework Guides

第二十四章 - Testing React Apps

第二十五章 - Testing React Native Apps

第二十六章 - Testing Web Frameworks

---

### 第一章 - Getting Started

install from `yarn` or `npm`

- `npm install --save-dev jest`

Simple example

- default module 使用 CommonJS, 要使用 ES6 modules 需要配合 Babel 與額外設定, [jest config transform with babel-jest](https://jestjs.io/docs/en/configuration#transform-objectstring-pathtotransformer--pathtotransformer-object)
- `test(name, fn, timeout)`
- `expect(value)`
- `.toBe(value)`

Jest CLI

- install `npm install --global jest`

Work with Babel
Work with Webpack
Work with Parcel
Work with TypeScript

---

### 第二章 - Using Matchers

`expect` [API](https://jestjs.io/docs/en/expect)

- 斷言工具
- Expectation object 呼叫 Matchers 呈現斷言

Common Matchers 

- `expect(2 + 2).toBe(4)`, `expect()` 回傳 expectation  object, `toBe()` 斷言
- `toBe()` 使用 `Object.is()` 作判斷
- `toEqual()`, deep equal, 比較物件內容時使用
- `.not`, 實現相反邏輯

Truthiness 真假值

- `toBeNull`, 嚴格等於 `null`
- `toBeUndefined`, 嚴格等於 `undefined`
- `toBeDefined`, 等價 `not.toBeUndefined`
- `toBeTruthy`, `if` 真值
- `toBeFalsy`, `if` 假值

Numbers 數字斷言

- `toBeGreaterThan`, >
- `toBeGreaterThanOrEqual`, >=
- `toBeLessThan`, <
- `toBeLessThanOrEqual`, <=
- `toBe`, `toEqual`, =
- `toBeCloseTo`, 比較浮點數時使用, 可以避開 IEEE-754 的誤差值

Strings 字串斷言

- `toMatch(//)`, 使用 regular expression 比較

Arrays and iterables 陣列與迭代子 存在斷言

- `toContain`, 存在斷言

Exceptions 例外斷言

- `toThrow()`,
- `toThrow(Error)`, 指定錯誤型別
- `toThrow('')`, 指定錯誤字串
- `toThrow(//)`, 通過 Regular expression 指定錯誤字串

More

完整的斷言函式參考 [API 文件](https://jestjs.io/docs/en/expect)

---

### 第三章 - Testing Asynchronous Code

- 測試非同步, [範例程式碼](https://jestjs.io/docs/en/asynchronous)
- Jest 的測試案例, 在執行到函式結尾時即完成, 因此呼叫非同步機制時並不會等待
- 各非同步機制有不同的處理方式, Callbacks, Promises, `Async` / `Await`

Callbacks

- 傳入 `done` 函式, 控制測試案例的結束
- `done()` 如果沒有被呼叫, 則會有 timeout failed
- 可以通過 `try...catch` 補捉錯誤並且呼叫 `done(error)` 傳出錯誤訊息

Promises

- 把 Promise 的測試放在測試函式的 `return` 會 Jest 會自動等待 Promise 的處理
- `reject` 會產生 test fail 
- Promise 補捉錯誤斷言, 需要配合 `expect.assertions()` 和 `catch()`

`.resolves` / `.rejects`

- 在測試函式的 `return` 放置 Promise 的測試呼叫
- 通過 `except( promiseFunction ).resolves` 與 `except( promiseFunction ).rejects` 達成 Promise 回傳值測試

`Async` / `Await`

- 測試 `async`/ `await` 時, 使用 `test(message, async () => {})`
- 可以組合 `resolves` 與 `rejects` 使用

---

### 第四章 - Setup and Teardown

- 設定 setup 與 teardown

Repeating Setup for Many Tests, 每次測試前後

- 使用 `beforeEach(() => {]})`, 與 `afterEach(() => {})`, 實現每次測試前與測試後的工作處理
- 如果處理函式使用非同步處理, 則需要配合非同步處理的方式, 參考 Testing Asynchronous Code

One-Time Setup, 所有測試前, 所有測試後

- `beforeAll(() => {})`, 所有測試前, 只執行一次
- `afterAll(() => {})`, 所有測試後, 只執行一次

Scoping 設置影響範圍

- 預設 before 與 after 影響該檔案中所有的測試
- 使用 `describe` block 包覆時, 並且只在內部宣告 before 與 after 則影響範圍只有 `describe` block 中的測試

Order of execution of describe and test blocks, `describe` 區塊與測試執行順序

- 所有的 `describe` block 函式內部會先執行完, 才會開始照順序實際執行測試

General Advice, 建議

- 當測試失敗時, 可以通過 `test.only()` 只執行單個測試, 
- 可以避免測試全部重跑加快執行和確認沒有 side-effect 影響
- 如果是 side-effect 影響導致測試失敗, 可以通過 `beforeEach` 加上 log 來作 debug

---

### 第五章 - Mock Functions

[範例程式碼](https://jestjs.io/docs/en/mock-functions)

Using a mock function, 創造模擬函式

- 測試 mock function 的呼叫次數, 回傳值, arguments
- `jest.fn(function mockFunctionImplements () {})`

`.mock` property, Jest 模擬函式提供的測試資料

- 由 `jest.fn()` 生成出來的 mock function 都有 `mock` property 可以呼叫提供測試資料
- `mock.calls`, `mock.results`, `mock.instances`

Mock Return Values, 模擬回傳值

- `jest.fn()` 生成 mock function, 使用 `.mockReturnValueOnce()` 或 `.mockReturnValue()` 提供回傳值
- `mockReturnValueOnce` 可以持續串接, 會依序回傳串接的回傳值
- 在測試無關的函式, 避免實作內容而是使用 mock function 達成, 測試效能也較好

Mocking Modules, 模擬模組

- 例如模擬呼叫 API 的函式庫
- 在測試時需 import 被模擬的函式庫
- `jest.mock('mock_module_name')`
- `mock_module_name.mock_method.mockResolvedValue()`, mock module, mock 所屬函式, mock 回傳值

Mock Implementations

- `.mockImplementation()`
- `.mockImplementationOnce()`
- `.mockReturnThis()`

Mock Names

- `.mockName()`, 協助 mock function 串連時的錯誤定位

Custom Matchers

- mock function 斷言時的語法糖
- `expect(mockFunc).toHaveBeenCalled()`, 
- `expect(mockFunc).toHaveBeenCalledWith(arg1, arg2)`,
- `expect(mockFunc).toHaveBeenLastCalledWith(arg1, arg2)`,
- `expect(mockFunc).toMatchSnapshot()`,

---

### 第六章 - Jest Platform

- Jest 相關的 package 可提供使用
- [說明與範例](https://jestjs.io/docs/en/jest-platform)

jest-changed-files

jest-diff

jest-get-type

jest-validation

jest-worker

pretty-format

---

### 第七章 - Jest Community

- jest-community, [GitHub organization](https://github.com/jest-community)
- [awesome-jest](https://github.com/jest-community/awesome-jest) 列出與 jest 相關的 projects

---

### 第八章 - More Resources

- 延伸學習 Snapshot testing, 更多 mock functions
- Configuration jest
- API references
- [測試範例](https://github.com/facebook/jest/tree/master/examples)
- Discord 社群, `Reactiflux` Facebook 相關開源軟體討論區, 由 Facebook 設立

---

### 第九章 - Snapshot Testing

---

### 第十章 - An Async Example

---

### 第十一章 - Timer Mocks

---

### 第十二章 - Manual Mocks

---

### 第十三章 - ES6 Class Mocks

---

### 第十四章 - Bypassing module mocks

---

### 第十五章 - Using with webpack

---

### 第十六章 - Using with puppeteer

---

### 第十七章 - Using with MongoDB

---

### 第十八章 - Using with DynamoDB

---

### 第十九章 - DOM Manipulation

---

### 第二十章 - Watch Plugins

---

### 第二十一章 - Migrating to Jest

---

### 第二十二章 - Troubleshooting

---

### 第二十三章 - Architecture

---

### 第二十四章 - Testing React Apps

---

### 第二十五章 - Testing React Native Apps

---

### 第二十六章 - Testing Web Frameworks

---

Enzyme, React component testing
Mocha <-> Jest, similar platform
