## TestCafe official documents

### [TestCafe official documents](https://devexpress.github.io/testcafe/), JavaScript/Testing

---

Getting Started

第一章 - Getting Started

Basic Guides

第二章 - Install TestCafe

第三章 - Organize Tests

第四章 - Select Page Elements

第五章 - Interact with the Page

第六章 - Assert

第七章 - Obtain Client-Side Info

第八章 - Run Tests

第九章 - Debug

第十章 - Best Practices

Advanced Guides

第十一章 - Authentication

第十二章 - Screenshots and Videos

第十三章 - Intercept HTTP Requests

第十四章 - Inject Client Scripts

第十五章 - Test HTTPS Features and HTTP/2 Websites

第十六章 - Detect the Client Browser and Platform

第十七章 - Use TestCafe Docker Image

第十八章 - Multiple Browser Windows

Concepts

第十九章 - Browsers

第二十章 - Reporters

第二十一章 - Page Model

第二十二章 - TypeScript and CoffeeScript

第二十三章 - Built-in Wait Mechanisms

Continuous Integration

第二十四章 - AppVeyor

第二十五章 - Azure DevOps

第二十六章 - Bitbucket Pipelines

第二十七章 - CircleCI

第二十八章 - CircleCI + LambdaTest

第二十九章 - GitHub Actions

第三十章 - GitHub Actions + BrowserStack

第三十一章 - GitLab

第三十二章 - Jenkins

第三十三章 - TeamCity

第三十四章 - Travis

第三十五章 - Travis + Sauce Labs

Extend TestCafe

第三十六章 - Install Plugins

第三十七章 - Reporter Plugin

第三十八章 - Browser Provider Plugin

---

Getting Started

-------

### 第一章 - Getting Started

Installing TestCafe

- Node.js, npm, 
- install from npm or yarn

Creating a Test

- 可以使用 TypeScript 或 JavaScript 撰寫
- 測試檔內需包含特定的語法 `fixture`
1. `import { Selector } from 'testcafe'`
1. 指定測試名稱與開啟頁面 URL
    ```javascript
   fixture `Test Name`
    .page(`Page URL`)
    ```
1. `test('description', async t => { // Test Code })`

Running the Test

- 指定測試瀏覽器與測試檔案, `testcafe chrome test.js`

Writing Test Code 簡單範例

- 執行動作, TestCafe 數種動作例如 `click`, `hover`, `typeText`, `setFilesToUpload`, ...
  - ```javascript
    test('test with action', async (t) => {
        await t
            .typeText('selector here', 'string text')
            .click('selector here')
    });
    ```
- 利用 `Selector` 存取 DOM, 參考[範例](https://devexpress.github.io/testcafe/documentation/getting-started/#observing-page-state)
- 斷言庫 例如 `expect().eql()`, 參考[斷言文件](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/assert.htmls)

-------

Basic Guides

-------

### 第二章 - Install TestCafe

- Global Installation
  - command line 執行 `testcafe chrome tests/`, 範例指定 chrome 瀏覽器與測試檔案資料夾 `tests/`
- Local Installation
  - 執行方式 `npx`, `yarn run`, `npm scripts`
- Mac 執行時會跳出權限許可視窗

-------

### 第三章 - Organize Tests

- 使用 eslint 時需要安裝對應的 TestCafe plugin 協助處理 `fixture` undefined 警告.

Fixtures

- 必須使用 `fixture` 函式，類似 `describe()` 的功能, 設置測試名稱, 提供 setup 與 teardown 等等預處理.
- ```javascript
  fixture `Testing name`;
  ```

Tests

- 單個測試撰寫 `test('test description', async t => { test here })`
- 傳入一個 test controller `t`, 藉此呼叫 TestCafe test API
- 使用 `test actions` 操作測試頁面, 
- 使用 `selectors`, `client functions` 取得狀態
- 使用斷言庫 `assertions` 實行斷言

Specify the Start Webpage

- 使用 `fixture` 函式，指定測試頁 URL
  - ```javascript
    fixture `Fixture Name` 
        .page `Specify URL`
    ```
- 使用 `test` 函式，單一測試指定測試頁 URL
  - ```javascript
    test.page `Specify URL`
        (`test description`, async t => {
            // test here
        }) 
    ```

Specify Test Metadata

- 以 key-value pair 帶入 metadata 作為測試報告資料或過濾測試用
- 使用 `fixture` 函式或 `test` 函式帶入 
  - `.meta('key', 'value')`, 直接帶入 key-value pair
  - `.meta({ key1: 'value1' , key2: 'value2' })`, 傳入物件
- 配合 `testcafe` CLI 參數 `--test-meta`, `--fixture-meta` 塞選測試或其他方式 (runner.filter, configuration file)
- 作為客製化測試報告的資訊 custom reporters

Initialization and Clean-Up

- 使用 `fixture` 函式, 指定 `.beforeEach( async t => { } )`, `.afterEach( async t => { } )` 作為每個測試前與測試後的 hook function
- 使用 `test` 函式的 `.before( async t => { } )`, `.after( async t => { } )` 會覆寫 `fixture` 指定的 `.beforeEach` 與 `.afterEach` hook function.
- 使用 `t.ctx` context 物件作為全域變數, 各個 hook function 與測試函式皆可存取
- 使用 `fixture` 函式的 `.before( async ctx => { })`, `.after( async ctx => { })`, 賦予全部測試前與測試後可以預先設置 `ctx` (context) 作為測試資料
  - test 中可以呼叫 `t.fixtureCtx` 來取得 `fixture` 設置的 `ctx` 物件

Skip Tests

- 通過 `fixture.skip` 或 `test.skip()` 停止該測試
- 通過 `fixture.only` 或 `test.only()` 只執行特定測試

-------

### 第四章 - Select Page Elements

- 選取頁面元素的方式
  - 在 `Selector` 函式中使用 CSS selectors
  - 配合 `Selector` 的 method 可以鏈結 (chain) 搜尋 (類似 jQuery)

Create Selectors

- 呼叫 `Selector('CSS selectors string')`, 傳入 CSS selector 字串
- 傳入函式 `Selector(() => { return document.getElementById() })`
- 自由組合 Selector methods 與 actions 指定 element

Member Tables

- Selector 的 filter methods
- `nth`, `withText`, `withExactText`, `withAttribute`, `filterVisible`, `filterHidden`, `filter`
- `find`, `parent`, `child`, `sibling`, `nextSibling`, `prevSibling`

Use Selectors

- 檢查選中的元素數量與是否存在, 
  - `Selector().count` 回傳 number, 
  - `Selector().exists` 回傳 boolean
- 取得 DOM 元素上的資訊, `DOMNodeStates` API, 非同步的 API 需配合 `await` 使用
  - 參考 [`DOMNodeStates` 文件](https://devexpress.github.io/testcafe/documentation/reference/test-api/domnodestate.html)
- 指定動作到選定的元素上
  - Example `t.click(elementFromSelector)`
- 配合斷言 `t.expect()`
  - TestCafe 有聰明的 query 與 assert 機制, 會自動等待重試或者 timeout, 不需要額外指定等待

Selector Timeout

- 指定單一個 `Selector()` timeout 值, 傳入第二個 options 物件, `Selector('', { timeout: })`
- 指定全部 `Selector()` timeout 值, 則使用 `runner.run` API 或 CLI 參數 `--selector-timeout`
- `Selector.exists`, `Selector.count` 的值都是立即取得無視 Selector timeout, 需要配合斷言機制的參數設置 timeout.
  - [參考範例](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/select-page-elements.html#selector-timeout)

Debug Selectors

- TestCafe 會指出在 chain 中錯誤的位置

Extend Selectors with Custom Properties and Methods

- 通過加入客製化的 element properties 或 methods 協助測試而不用修改程式, `addCustomMethods()`, `addCustomDOMProperties()`
- [參考範例](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/select-page-elements.html#extend-selectors-with-custom-properties-and-methods)

Overwrite Options

- 通過 Selector 的 `with()` 函式一次性覆寫 Selector options
- [參考範例](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/select-page-elements.html#overwrite-options)

Framework-Specific Selectors

- 通過社群提供的函式庫, 提供各個 front-end framework 專用的 selectors
- 例如 `React`, `AngularJS`, `Vue`, `Aurelia`

Call Selectors from Node.js Callbacks

- 測試中包含 Node.js 的非同步動作與 Callbacks 的驗證, 例如測試中發送 http request 並且驗證 response 的頁面
- [參考範例](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/select-page-elements.html#call-selectors-from-nodejs-callbacks)

-------

### 第五章 - Interact with the Page

Actions

- Click, 
- Press Key, 
- Navigate, 
- Type Text, 
- Select Text, 
- Hover, 
- Drag Elements, 
- Upload Files, 
- Take Screenshot, 
- Work with iframes, 
- Handle Native Dialogs, 
- Resize Window, 
- Wait

Click

- 滑鼠點擊
- `t.click()`, `t.doubleClick()`, `t.rightClick()`

Press Key

- 鍵盤輸入
- `t.pressKey()`

Navigate

- 頁面移動到指定的 URL
- `t.navigateTo()`

Type Text

- 輸入字串到指定的 input element
- `t.typeText()`

Select Text

- 選取 input, `<textarea>`, `contentEditable` 元素中的文字
- `t.selectText()`, `t.selectTextAreaContent()`, `t.selectEditableContent()`

Hover

- 滑鼠 hover
- `t.hover()`

Drag Elements

- 拖拉
- `t.drag()`, `t.dragToElement()`

Upload Files

- input 上傳檔案
- `t.setFilesToUpload()`, `t.clearUpload()`

Take Screenshot

- 螢幕攝影
- `t.takeScreenshot()`, `t.takeElementScreenshot()`

Work with Iframes

- 測試 iframe
- `t.switchToIframe()`, `t.switchToMainWindow()`

Handle Native Dialogs

- 測試瀏覽器的原生彈窗
- `t.setNativeDialogHandler()`, `t.getNativeDialogHistory()`

Resize Window

- 模擬視窗大小調整
- `t.resizeWindow()`, `t.resizeWindowToFitDevice()`, `t.maximizeWindow()`

Wait

- 測試暫停
- `t.wait()`

Remarks for Touch Devices

- 在觸碰裝置上，使用觸碰事件取代滑鼠事件
- mousemove -> touchmove, mousedown -> touchstart, mouseup -> touchend

Interaction Requirements

- 互動只能作用於看得到的元素
- 參考[定義](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/interact-with-the-page.html#interaction-requirements)

-------

### 第六章 - Assert

- 斷言 assert
- 建立在 Behavior-Driven Development (BDD) style 

Assertion Structure

- test controller, `t.expect()`

Assert Actions

- Deep Equal, `.eql()`
- Not Deep Equal, `.notEql()`
- Ok, `.ok()`, assert `true`
- Not Ok, `notOk()`, assert `false`
- Contains, `contains()`
- Not Contains, `notContains()`
- Type of, `typeOf()`, 型別
- Not Type of, `notTypeOf()`
- Greater than, `gt()`, 數值大於
- Greater than or Equal to, `gte()`, 數值大於等於
- Less than, `lt()`, 數值小於
- Less than or Equal to, `lte()`, 數值小於等於
- Within, `within()`, 數值區間
- Not Within, `notWithin()`, 數值區間
- Match, `match()`, regular expression
- Not Match, `notMatch()`, regular expression

Smart Assertion Query Mechanism

- TestCafe, 在做斷言時會**自動** retry 和 wait，來模擬網頁行為需要等待.

Options

- `{ timeout }`, milliseconds, 
- `{ allowUnawaitedPromise }`, boolean, 預設是 `false`

-------

### 第七章 - Obtain Client-Side Info

- 自訂 client functions 回傳可序列化的資料, 用來協助測試.
- Client functions 無法回傳 DOM node, 需要使用 selectors API

Client Function Constructor

- `import { ClientFunction } from 'testcafe'`
- `ClientFunction( () = > {} )`

Run Asynchronous Client Code

- Promise 作為回傳值 `ClientFunction( () => { return new Promise() })`

Execute Client Functions

- 配合 `await` 執行 client function

Pass Parameters to Client Functions

- Client function 也可以傳值

Overwrite Client Function Options

- 透過 `with()` 可以覆寫 option 值

One-Time Client Code Execution

- 一次性的立即執行 client function
- `t.eval( () => {} )`

Import Functions to be Used as Client Function Dependencies

- 引用外部 function 給 Client Function 使用
- 配合 `require()` 和 `{ dependencies: {} }`
- 參考[範例](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/obtain-client-side-info.html#import-functions-to-be-used-as-client-function-dependencies)

Call Client Functions from Node.js Callbacks

- 使用 Node.js 的函式回傳值, 例如 `fs`. 需要配合 option `{ boundTestRun: t }`
- 參考[範例](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/obtain-client-side-info.html#call-client-functions-from-nodejs-callbacks)

Client Function Limitations

- 有語法限制
- 參考[文件](https://devexpress.github.io/testcafe/documentation/guides/basic-guides/obtain-client-side-info.html#client-function-limitations)

Access Console Messages

- 取得 console 中的訊息
- `t.getBrowserConsoleMessages()`

Examples

- 通過 `window.location` 取得頁面的 URL
- 通過 `navigator.userAgent` 取得瀏覽器資訊
- 通過 `document.querySelector()`, `document.querySelectorAll()` 預處理與收集複雜的測試資料

-------

### 第八章 - Run Tests

-------

### 第九章 - Debug

-------

### 第十章 - Best Practices

-------

Advanced Guides

-------

### 第十一章 - Authentication

-------

### 第十二章 - Screenshots and Videos

-------

### 第十三章 - Intercept HTTP Requests

-------

### 第十四章 - Inject Client Scripts

-------

### 第十五章 - Test HTTPS Features and HTTP/2 Websites

-------

### 第十六章 - Detect the Client Browser and Platform

-------

### 第十七章 - Use TestCafe Docker Image

-------

### 第十八章 - Multiple Browser Windows

-------

Concepts

-------

### 第十九章 - Browsers

-------

### 第二十章 - Reporters

-------

### 第二十一章 - Page Model

-------

### 第二十二章 - TypeScript and CoffeeScript

-------

### 第二十三章 - Built-in Wait Mechanisms

-------

Continuous Integration

-------

### 第二十四章 - AppVeyor

-------

### 第二十五章 - Azure DevOps

-------

### 第二十六章 - Bitbucket Pipelines

-------

### 第二十七章 - CircleCI

-------

### 第二十八章 - CircleCI + LambdaTest

-------

### 第二十九章 - GitHub Actions

-------

### 第三十章 - GitHub Actions + BrowserStack

-------

### 第三十一章 - GitLab

-------

### 第三十二章 - Jenkins

-------

### 第三十三章 - TeamCity

-------

### 第三十四章 - Travis

-------

### 第三十五章 - Travis + Sauce Labs

-------

Extend TestCafe

-------

### 第三十六章 - Install Plugins

-------

### 第三十七章 - Reporter Plugin

-------

### 第三十八章 - Browser Provider Plugin

-------

