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

- `expect(2 + 2).toBe(4)`, `expect()` 回傳 expectation object, `toBe()` 斷言
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

- 通過 Snapshot 自動化建立測試比對
- 適合 UI 測試, API 測試

Snapshot Testing with Jest

- [範例程式碼](https://jestjs.io/docs/en/snapshot-testing), 使用 Snapshot 測試 React component
- 通過 `react-test-renderer` package 建立 Snapshot, `create().toJSON()`, `expect().toMatchSnapshot()`
- 可以通過不同的 props 建立不同的 snapshot 讓 React component 有更完整的測試

Updating Snapshots

- 當實作改變時, 過去的 snapshot 已經不符合使用時, 可以通過 `jest --updateSnapshot` 更新成新的 snapshot
- 在更新 snapshot 前, 得先確定失敗的 snapshot testing 是因為實作更新, 而非 bug 否則會 snapshot 出有 bug 的版本
- 或者可以配合 `--testNamePattern` 指定更新的測試

Interactive Snapshot Mode

- 通過 watch mode 可以互動式更新失敗的 snapshot
- 互動式一筆一筆查看結果後, 選擇跳過或更新

Inline Snapshots

- Powered by `Prettier`. 並且要指定 prettier 路徑給 Jest
- Snapshot 會生成在測試檔案裡 (`.test.js`), 而非另開新檔 (`.snap`)
- `toMatchInlineSnapshot()`

Property Matchers

- 比較動態的值, 例如 Date 與 id
- 可以通過優先測試 property 後才比較 Snapshots
- `toMatchSnapshot({ propertyName: expect.any(Type) })`
- [程式碼範例](https://jestjs.io/docs/en/snapshot-testing#property-matchers)

Best Practices 最佳實務

1. Treat snapshot as code,
   - 把快照視為程式碼的一部分, 同樣需要 code review
   - 確保 snapshot readable, 可以通過其他工具輔助
   - 把 snapshot 視為程式碼的好處, 在於遇到錯誤時應該試著找 bug, 而非直接重新生成
1. Tests should be deterministic,
   - 測試應該要是確定的, 不能依據 platform 或容易變動的值導致測試失敗
   - 善用 mock function, 取代容易變動的值或 API
1. Use descriptive snapshot names,
   - 測試名稱需要有足夠的描述性, 並且測試的內容要與描述一致, 如同程式碼註解一般

Frequently Asked Questions 常見問題

- [Q&A](https://jestjs.io/docs/en/snapshot-testing#frequently-asked-questions)

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

with Create React App

- 加上 `react-test-renderer` 協助 snapshot testing 即可

without Create React App

- 使用 `babel-jest`, `@babel/preset-env`, `@babel/preset-react`, `react-test-renderer`, 作為 dev-dependency
- babel config, `presets: ['@babel/preset-env', '@babel/preset-react']`

Snapshot Testing

- 使用 snapshot testing 測試 React component,
- `import renderer from 'react-test-renderer'` 使用 `renderer.create()` 傳入要測試的 component,
- 配合 component `.toJSON()` 與 matcher `toMatchSnapshot()` 實現比對
- 手動觸發 event handler, re-rendering 後再次觸發 `toJSON()` 與 `toMatchSnapshot()` 進行比對
- 執行 snapshot testing 並且在錯誤的時候檢查 snapshot code 和進行 snapshot update
- 同時使用 Jest snapshot testing, Enzyme, React 16+ 時可能會遇到的問題與解決方案

DOM Testing

- 不使用 snapshot testing 時手動建立測試案例, 則一使用 `react-testing-library`, `Enzyme`, `react-dom/test-utils`
- 文件包含 `react-testing-library` 範例與 `Enzyme` 範例
- React [官方推薦](https://reactjs.org/docs/test-utils.html#overview)使用 `react-testing-library` 取代 `react-dom/test-utils`

Custom transformers

- 建立客製化的 transformer 取代 `babel-jest`

---

### 第二十五章 - Testing React Native Apps

---

### 第二十六章 - Testing Web Frameworks

---

Enzyme, React component testing
Mocha <-> Jest, similar platform
