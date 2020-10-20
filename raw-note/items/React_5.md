## React Official Documents - React Hooks

[Website resource](https://reactjs.org/docs/hooks-intro.html), React

---

第一章 - Introducing Hooks

第二章 - Hooks at a Glance

第三章 - Using the State Hook

第四章 - Using the Effect Hook

第五章 - Rules of Hooks

第六章 - Building Your Own Hooks

第七章 - Hooks API Reference

第八章 - Hooks FAQ

---

### 第一章 - Introducing Hooks

- React 16.8+
- `import { useState } from 'react'`, 引入新函式 `useState()`
- Completely opt-in, 選用的功能
- 100% backwards-compatible, 不影響舊功能
- React 不會移除 class component, 也不會修改現有的 concepts.
- React 核心 concepts, (**props**, **state**, **context**, **refs**, **lifecycle**)

Hooks 想解決的問題

- **Q**, Reuse stateful logic between components,
- **A**, Hooks 把 stateful logic 抽出來變成可以獨立測試與重用

* **Q**, Complex components become hard to understand,
  - 越來越複雜後互相無關的方法都會在 life cycle functions 中呼叫, 導致巨大的 component 而無法切小, 變得難以測試與維護.
  - 多數時候引用第三方 state 管理方法解決, 例如 Redux, 而沒有原生的方式
* **A**, Hooks 允許切割 component 變成小函式

- **Q**, Classes confuse both people and machines
  - JavaScript `class` 語法與 `this` 是個學習障礙
  - Class 不容易最佳化
- **A**, Hooks 允許使用 React 功能而不需要 `class`, 更靠近 function, 不需要額外學習 functional programming 或 reactive programming 來克服困難

Gradual Adoption Strategy

- React 不會移除 `class` component 的使用
- Hooks 可以與現有的程式碼一起使用, 慢慢的移植
- 新 component 開始使用 Hooks

### 第二章 - Hooks at a Glance

- React 16.8+
- 不需要 `class` component 即可使用 state

State Hook

- `useState()`, 創造出 local state

  - input: 傳入 initial state
  - output: 回傳, **currentState** 與 **updateFunction** (類似 `this.setState` 但是有所不同)
  - example, `const [count, setCount] = useState(0)`

- Declaring multiple state variables

  - `useState()` 初始值可以為任何型別

- But what is a Hook?

  - Hooks 就是利用 API 函式操作 component state 跟 lifecycle
  - 因此 class component 無法使用 Hooks
  - React 提供數種現成的 Hooks, 例如 `useState()`, 也可以實現客製化 Hooks

Effect Hook

- 操作 side-effect, 例如發送 Http Request
- `useEffect()`, 實現 class component 中的 `componentDidMount`, `componentDidUpdate`, `componentWillUnmount`
- 每一次 render 都會觸發 `useEffect()`, 包含第一次, 實現了 `componentDidMount` 與 `componentDidUpdate`
- 因為 `useEffect()` 被定義在 component function 裡, 因此可以取得 `props` 與 `state`
- 通過 `return` 函式，實現 `componentWillUnmount`,
  - Example:
    ```javascript
    useEffect(() => {
      callWhenRender()
      return function callWhenUnmount() {}
    })
    ```
- `useEffect()` 如同 `useState()` 一樣，可以擁有多個
- `useEffect()` Hooks 把 side-effect 集中在同個函式宣告中, 而非各個 lifecycle function, 因此個別的 side-effect 可以聚合在同個 function 中。

Rules of Hooks

- Hooks are JavaScript functions
- 額外限制, Hooks function 只能在 component 第一層呼叫, 不能在其他位置 (loops, conditions, nested function)
- 額外限制, 內建的 Hooks function 只能由 React function component 所呼叫
- 在 eslint 中加上上面兩個限制, [eslint-plugin-react-hooks](https://www.npmjs.com/package/eslint-plugin-react-hooks)

Building Your Own Hooks

- 整合內建 Hooks 與 side-effect 邏輯成一個客製化的 hook function
- 在其他的 component 中可以重用。
- custom hook function 命名以 `use` 開頭
- [官方範例](https://reactjs.org/docs/hooks-overview.html#building-your-own-hooks)

Other Hooks

- 其他內建的 Hooks,

  - `useContext()`, 通過 Hook 使用 React Context
  - `useReducer()`
  - [More reference](https://reactjs.org/docs/hooks-reference.html)

### 第三章 - Using the State Hook

- Equivalent Class Example, 比較 class state 與 `useState()` hook
- Hooks and function components, Hooks 使用的位置,
  - 從 stateless component 變成 function component
- What's a Hook?

Declaring a State Variable

- 宣告與初始化 state, `[state, setState()] useState(initial_state)`
- 初始值, 不需要一定是 Object, 允許任意型別
- `useState()` 回傳值是 state 變數與更新函式, 所組成的 array

Reading State

- 直接呼叫 state 變數

Updating State

- 直接呼叫 update function
- 與 `this.setState()` 的**差別**, 如果更新的是 Object 型別不再是 merge state 而是 **replace** 覆蓋掉舊的 state

Tip: What Do Square Brackets Mean?,

- 回傳值是 array 存放 state 與 update function, 因此可以使用陣列解構 (array destructuring) 取得內容。

Tip: Using Multiple State Variables,

- `useState()` 可以擁有多個, 所以承載多個 state 的方式可以自由選擇。
- 選擇用 Object 或 Array 打包, 或者註冊多個 state

### 第四章 - Using the Effect Hook

- `useEffect()` 可以視為是 `componentDidMount()`, `componentDidUpdate()`, `componentWillUnmount()` 的組合

Effects Without Cleanup

- 不用回收的 side-effect 功能, 例如 fetch data, ...
- 通常被實作在 `componentDidMount` 與 `componentDidUpdate` 兩個階段的內容
- `useEffect( effect_function )`, input 一個函式, **預設**是在每次 render 後會被觸發 (`componentDidMount` + `componentDidUpdate`),
- 由 `useEffect()` 所註冊觸發的 effect_function 其實在每次 render 時都是全新的, 應該被視為是每一次 render 後所觸發的結果
- `useEffect()` 並不會讓瀏覽器阻擋畫面的更新, 會影響到畫面的 side-effect 需要使用另外的 Hook `useLayoutEffect`

Effects With Cleanup

- 需要在 `componentWillUnmount` 時觸發的功能
- `useEffect(effect_function () { return clean_up_function })`, clean up function 被定義在 effect_function 的回傳值
- 這種方式讓同一個 effect 的註冊與清除都在同一個函式定義中, 而不用散落在各個 lifecycle 上
- 實際上這個 clean up function 預設的觸發時機是每次 render 觸發 effect function 過後，而只在的 component unmount 時, 因此需要額外設定。

Tips:

Tip: Use Multiple Effects to Separate Concerns

- 藉由使用多個不同的 `useEffect()`, 分割 side-effect function 為各個不同的 function, 而非註冊在同一個 life cycle function 裡
- Explanation: Why Effects Run on Each Update,
  - 因為 effect function 可能會相依著 `props`, 因此在每次 re-render 都觸發 effect function 與 clean up function 可以確保狀態的一致性, 而不用在 effect function 中持續判斷 `props` 的狀態。[官方範例](https://reactjs.org/docs/hooks-effect.html#explanation-why-effects-run-on-each-update)
  - clean up function 會在下一次觸發新的 effect function 時先觸發,
  - 因此流程是 render -> effect_function -> re-render -> clean_up_function -> effect_function

Tip: Optimizing Performance by Skipping Effects

- 處理每一次 render 都呼叫 effect function 與 clean up function 的 performance issue
- `useEffect(effect_function, [skip_non_changed_variables])`, 傳入第二個選用的參數, 一個 array 存放多個變數, 如果變數並沒有改變則 effect_function 不會被觸發 (skip)。
- 觸發 effect_function 前會先比對, 選用參數陣列中的值, 是否與前一次有所不同, 不同才觸發。
- clean_up_function 的觸發也受到這個選用陣列的影響, 因此在值沒有改變時, clean_up_function 也不會被觸發。
- 判斷陣列如果傳入的是 `[]` 空陣列時, 則每次比對都會是相同的, 因此只有在 `componentDidMount` 與 `componentWillUnmount` 時才會分別觸發, effect function 與 clean up function。

My Tip: 混用 `useState` 與 `useEffect` 時, state 作為 function component 中的**區域變數**傳入, 不用作為參數傳入 effect function。

### 第五章 - Rules of Hooks

- Hooks are JavaScript functions
- 加上兩個額外的限制

限制 1. Only Call Hooks at the Top Level

- 只能在 component 的第一層呼叫, 不能在 loop, nested functions, conditions 裡, 為了要確保 state 的狀態.

限制 2. Only Call Hooks from React Functions

- Hooks 只能在 React function components 與 custom Hooks 裡呼叫
- 確保 component state function 可以正確的被 component 所識別

ESLint plugin

- 使用 [eslint-plugin-react-hooks](https://www.npmjs.com/package/eslint-plugin-react-hooks) 可以協助偵測這兩個限制

Explanation

- `useState()` 與 `useEffect()` 所產生的值是與順序相依的。
- 因為每次觸發 Hooks 時都會比對 `props` 與 `states` 如果不能保證存在的話會導致錯誤, 並且不容易 debug, 因為錯誤相依不確定的 side-effect。

### 第六章 - Building Your Own Hooks

- 自訂 Hook function 整合 effect 邏輯並且重用
- 過去使用 [render props](https://reactjs.org/docs/render-props.html) 與 [higher-order components](https://reactjs.org/docs/higher-order-components.html) 來達成邏輯重用
- 使用 custom hook 可以避免增加抽象的 component, 重用的只是函式

Extracting a Custom Hook

- custom Hook 是一個 JavaScript function, 命名以 `use` 開頭, 並且會呼叫其他內建的 Hooks
- 獨立的 state 可以內聚在 custom Hook 中, 其他相依的值 (`props`, `state`) 使用參數傳入。
- 只要符合 Hooks 額外的兩個限制, custom Hook 就是一般的 JavaScript function, 因此可以任意使用.

Using a Custom Hook

- 如同一般的 function 一樣呼叫, 只是把 Hooks 的邏輯打包成函式而已。

Tip: Pass Information Between Hooks

- Custom Hook 相依於其他 `state`, 可以作為參數傳入.
- 傳入的 `state` lifecycle 仍然會依循宣告順序, 並且有正確的狀態。即外部 state 的 update 也會影響到 custom hook 傳入的參數上, 確保 custom hook 在呼叫時會有最新的 state

useYourImagination()

- custom hook 提供了很大的彈性, 如同一般的 JavaScript function, 可以作到很多事情。
- 內建的 `useReducer` Hook, 也提供了整合第三方 state library 的功能, 可以把狀態改變邏輯解構到 Flux 架構中, 方便獨立測試。

### 第七章 - Hooks API Reference

Basic Hooks

- `useState`, [Doc](https://reactjs.org/docs/hooks-reference.html#usestate)
- `useEffect`, [Doc](https://reactjs.org/docs/hooks-reference.html#useeffect)
- `useContext`, [Doc](https://reactjs.org/docs/hooks-reference.html#usecontext)

Additional Hooks, 應付特殊需求所存在的 Hook

- `useReducer`, [Doc](https://reactjs.org/docs/hooks-reference.html#usereducer)
- `useCallback`, [Doc](https://reactjs.org/docs/hooks-reference.html#usecallback)
- `useMemo`, [Doc](https://reactjs.org/docs/hooks-reference.html#usememo)
- `useRef`, [Doc](https://reactjs.org/docs/hooks-reference.html#useref)
- `useImperativeHandle`, [Doc](https://reactjs.org/docs/hooks-reference.html#useimperativehandle)
- `useLayoutEffect`, [Doc](https://reactjs.org/docs/hooks-reference.html#uselayouteffect)
- `useDebugValue`, [Doc](https://reactjs.org/docs/hooks-reference.html#usedebugvalue)

#### useState

- 使用 state

Hook 簽名

- `const [state, setState] = useState(initialState);`
- input: 任意型別的值或函式
- output: Array 存放 state 與 setState function

使用 `setState()`

- `setState()` 可以傳入新的值, 或者一個函式能接收到先前的狀態, `(preState) => { return }`, 如果回傳值等同於先前狀態時, 後續的 re-render 會被 skip 以提昇效能。
- `setState()` 傳入的物件, 並不會如同 `this.setState()` 一樣採用 merge, 而是 replace

Lazy initial state

- 如果初始值需要額外的計算, 可以傳入一個會回傳初值的 function 取代, `useState(() => { return })`

Bailing out of a state update

- React 使用 `Object.is` 作 state 的比較, 並且在相等的時候會 skip rendering
- 如果在 rendering 需要費時的計算, 可以使用 `useMemo` 來最佳化

#### useEffect

- 執行與 UI 渲染無關的 side-effect 工作

Hook 簽名

- `useEffect(didUpdate)`
- input: 傳入一個函式

與 UI 渲染無關的工作, 被視為 effect 就是適合由 useEffect 所處理的工作

- 在 useEffect 執行完 effect 後, 會觸發重新渲染 UI (re-render)
- 把 useEffect 視為一個 pure render function 與外部世界的接口

Cleaning up an effect

- 提供 clean up function 在下次觸發 effect 前和 componentUnmount 時會先執行清除動作。
- clean up function 實現在 didUpdate function 的 return function,
  ```javascript
  useEffect(function didUpdate() {
    return function cleanUpFunction() {}
  })
  ```

Timing of effects

- 與 `useLayoutEffect` Hook 的差別只有在呼叫時機
- `useEffect` 觸發時機在每次的 screen painting **之後**, 在下一次 screen painting 之前, 避免影響使用者視覺效果
- `useEffect` 預設每次觸發新 effect 之前會先清除舊的, 即每次都會先執行 cleanUpFunction 後才執行 didUpdateFunction.

Conditionally firing an effect

- 提供條件觸發 effect function 的機會, 最佳化執行效能
- `useEffect()` 傳入第二個選用的參數, 一個陣列包含需要判斷的值, 只有在上次的 effect 值與這次的不同時, 才會觸發 didUpdateFunction
- 傳入 `[]` 空陣列, 會導致 effect 永遠不會在 re-rendering 時執行, 只會在第一次 render 與 component unmount 時
- 因此這個選用的陣列需要包含**所有**被 effect 所使用到的並且會依循時間所改變的 props 與 state 才能確保運行如期, 保證資料的一致性。

#### useContext

- 使用 React Context, 提供一個跨層的資料傳遞

Hook 簽名

- `const value = useContext(MyContext)`
- input: 由 `React.createContext` 所回傳的物件
- output: 現在的 context value, 由最近的 `<MyContext.Provider>` 所提供的參數

#### useReducer

- React 原生的方式實現, state, dispatch, reducer 的類 Flux 架構

Hook 簽名

- `const [state, dispatch] = useReducer(reducer, initialArg, init);`
- input:
- output:

#### useCallback

- 提供避免 re-render 的機制, 效能最佳化工具
- 類似於 `useMemo()`, 一個記憶值, 一個記憶函式

Hook 簽名

- ```javascript
  const memoizedCallback = useCallback(() => {
    doSomething(a, b)
  }, [a, b])
  ```
- input:
- output:

#### useMemo

- 提供避免 re-render 的機制, 效能最佳化工具

Hook 簽名

- ```javascript
  const memoizedValue = useMemo(() => computeExpensiveValue(a, b), [a, b])
  ```
- input:
- output:

#### useRef

- 使用 React ref, 提供取得實際的 DOM element

Hook 簽名

- ```javascript
  const refContainer = useRef(initialValue)
  ```
- input:
- output:

#### useImperativeHandle

- 需配合 React [forwardRef API](https://reactjs.org/docs/react-api.html#reactforwardref) 使用

Hook 簽名

- ```javascript
  useImperativeHandle(ref, createHandle, [deps])
  ```
- input:
- output:

#### useLayoutEffect

- 功能等同於 `useEffect`, 但是觸發 effect 的時機在 DOM 合併但是 re-render 之前

Hook 簽名

- ```javascript
  useLayoutEffect(didUpdate)
  ```
- input:
- output:

- 優先使用 `useEffect` 直到實際遇到問題時才使用 `useLayoutEffect`

#### useDebugValue

- 在 Custom Hook 中提供 React DevTools 專用的 debug message
- 不推薦在每個 Custom Hook 都使用

Hook 簽名

- ```javascript
  useDebugValue(value)
  ```
- input:
- output:

### 第八章 - Hooks FAQ

- [link to FAQ](https://reactjs.org/docs/hooks-faq.html)

主題包含

- 改用策略
- Class component 與 Hooks 的差異跟移植
- 效能最佳化
- React Hook 的開發

#### Adoption Strategy, 改用策略

Which versions of React include Hooks?

- 從 React 16.8.0 開始穩定支援 React Hooks.
- 為了使用 React Hooks 所有 React packages 都需要在 16.8.0 以上版本

Do I need to rewrite all my class component?

- 不必修改所有的已經存在的 class component
- React 也沒有移除 class component 的打算
- 推薦使用 React Hooks 在新的程式碼中

What can I do with Hooks that I couldn't with classes?

- Hooks 提供強大且易懂的方式去重用邏輯與功能
- 參考[文章](https://medium.com/@dan_abramov/making-sense-of-react-hooks-fdbde8803889)

How much of my React knowledge stays relevant?

- React 沒有從根本的修改, 因此舊有的概念 state, lifecycle, context, refs 仍然與 React Hooks 息息相關.

Should I use Hooks, classes, or a mix of both?

- 不推薦沒意義的把舊的 class component 重寫成 React Hooks 方式.
- 推薦使用 React Hooks 在新建立的 component 上.
- 從長遠看來, 官方推薦使用 React Hooks 作為 React component 主要的實現方式.

Do Hooks cover all use cases for classes?

- 長遠來說會完全支援
- 目前還不支援 `getSnapshotBeforeUpdate`, `getDerivedStateFromError`, `componentDidCatch` 以上 lifecycle

Do Hooks replace render props and higher-order components

- 在多數情形, React Hooks 可以完全取代 render props 與 higher-order components, 以減少 React DOM 上的 component 層數.

What do Hooks mean for popular APIs like Redux connect() and React Router?

- 常見的 library 會提供 React Hooks 版本的 APIs 來連接功能
- 例如 React Redux 在 7.1.0 以上支援 Hooks, React Router 在 5.1 以上支援 Hooks

Do Hooks work with static typing?

- React Hooks 更容易配合 static typing, 因為 React Hooks 就是單純的 function.
- 最新版的 Flow 與 TypeScript, 已經可以支援 React Hooks

How to test components that use Hooks?

- 從 React 的觀點, React Hooks component 與一般的 component 相同, 測試的方式應該也不會有所不同.
- 如果要測試 custom Hook, 可以建立單純的測試 component 後直接測試 component.
- 推薦使用 [React Testing Library](https://testing-library.com/docs/react-testing-library/intro) 來協助測試

What exactly do the lint rules enforce?

- [eslint-plugin-react-hooks](https://www.npmjs.com/package/eslint-plugin-react-hooks) ESLint plugin 協助偵測是否違反 rules of Hooks 來避免 bug 產生.
- 這個 ESLint plugin 假設一個函式開頭是 `use` 並且連接著大寫開頭的字母時就代表是 React Hooks.
- 因此是有可能誤報的, 不過在未來會進一步調整.

#### From Classes to Hooks, Class component 與 Hooks 的差異跟移植

How do lifecycle methods correspond to Hooks?

-

34 Q&A
