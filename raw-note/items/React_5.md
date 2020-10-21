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

與 UI 渲染無關的工作, 被視為 side-effect 就是適合由 useEffect 所處理的工作

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
- output: 現在的 context value, 由最近的 `<MyContext.Provider value>` 所提供的參數

#### useReducer

- React 原生的方式實現, state, dispatch, reducer 的類 Flux 架構

Hook 簽名

- `const [state, dispatch] = useReducer(reducer, initialArg, init);`
- input: reducer function `(state, action) => newState`,
- output: 當前 state 與 dispatch function

用途

- 用來處理複雜的 state 管理, 作為另一種 `useState`
- 可以配合 `context` API 傳遞 `dispatch` 到深層的結構, 取代依序傳遞 callback function.
- [參考範例](https://reactjs.org/docs/hooks-reference.html#usereducer)

Specifying the initial state

- 初始化的方式有兩種, 可以任意選擇
- 最簡單的方式是直接傳遞 initial state 作為 `useReducer()` 的第二參數
- 第二種是以下的 lazy initialization

Lazy initialization

- 第二種 initialize state 的方式是傳遞 `init` callback function 給 `useReducer()` 的第三個參數, 同時第二個參數的值會作為變數傳入 `init` callback function.
- 這種方式可以把初始化過程變成函式

Bailing out of a dispatch

- 如果 dispatch 後回傳的 state 與當前的 state 相同時 (`Object.is` comparison), 不會觸發 re-render.
- 然而 React 仍然會觸發 function component 的內部但是不會深入下層, 因此 function component 內部如果有複雜的計算可以使用 `useMemo` 做效能最佳化.

#### useCallback

- 效能最佳化工具, 提供記憶函式, memoized function, 避免在每次 rendering 時重複計算
- 類似於 `useMemo()` 回傳記憶值, 而 `useCallback` 回傳記憶函式.

Hook 簽名

- ```javascript
  const memoizedCallback = useCallback(() => {
    doSomething(a, b)
  }, [a, b])
  ```
- input: 一個函式, 與 dependencies list
- output: 受 memory 最佳化的 function

用途

- 協助實現避免子代 component 不必要的 re-rendering, 類似 `shouldComponentUpdate`
- `useCallback(fn, deps)` 等價於 `useMemo(() => fn, deps)`
- 推薦啟用 `eslint-plugin-react-hooks` 裡的 `exhaustive-deps` 協助偵測 dependencies list 的完整性

#### useMemo

- 效能最佳化工具, 提供記憶值, 避免在 re-rendering 時重複觸發計算

Hook 簽名

- ```javascript
  const memoizedValue = useMemo(() => computeExpensiveValue(a, b), [a, b])
  ```
- input: callback pure function 與 dependencies list
- output: 回傳被記憶的值

用途

- `useMemo` 回傳的值, 只有在 dependencies list 裡面的值有所變動時才會觸發 recompute
- 避免在每次 rendering 時重新執行昂貴的計算
- `useMemo` 的計算會在 rendering 當中執行, 因此不要放置任何的 side effect function, side effect 行為應該交由 `useEffect` 處理.
- `useMemo`, 的計算函式需要是 pure 的, 並且必須提供 dependencies list, 如果沒有 dependencies list 時每次 rendering 都會觸發計算.
- `useMemo` 只是作為效能最佳化, 給予 React 提示, React 並不保證永遠不會重算.

#### useRef

- 回傳 mutable ref object, 用來實現保存跨 lifecycle 的值

Hook 簽名

- ```javascript
  const refContainer = useRef(initialValue)
  ```
- input: 傳入任一初始化值
- output: 取得保存 ref 的 object, 包含用來取值的 `current` property, 這個物件會完整的存在 component 的 lifecycle 中, 不受 re-rendering 影響.

用途

- `useRef` 不只可以用來處理 React `ref` attribute 而是更一般性的可變變數, 可以視為 class static variable
- 簡單來說 `useRef` 產生一個盒子來存放 mutable value 並且需要透過 `current` property 存取
- `useRef` 創造出單純的 JavaScript object, 並且保持每次 re-rendering 都是相同的 reference, 因此每次存取的都是同一個 object.
- 重點是 `useRef` 的 `current` 值就算有變化時, 也不會觸發 React re-rendering.

#### useImperativeHandle

- 必須配合 React [forwardRef API](https://reactjs.org/docs/react-api.html#reactforwardref) 使用
- 用來提供 parent component 一些 function 並且直接與 child 的 DOM ref 互動

Hook 簽名

- ```javascript
  useImperativeHandle(ref, createHandle, [deps])
  ```
- input: 從 forwardRef 來的 ref attribute, 建立物件的 function, 選用的 dependencies list
- output:

用途

- 多數時候不需要使用到
- 必須配合 `forwardRef` 使用, 把操作 child ref 的 function 定義在 child component 中, 讓 parent component 只需要透過 `ref` 去呼叫定義好的函式即可.
- [參考範例](https://reactjs.org/docs/hooks-reference.html#useimperativehandle)

#### useLayoutEffect

- 功能等同於 `useEffect`, 但是觸發 effect 的時機在 DOM 合併但是在 DOM update 之前
- 意思是使用 useLayoutEffect 會暫停 UI 更新, 有機會在渲染 UI 前操作, 但是也會影響到 UX.

Hook 簽名

- ```javascript
  useLayoutEffect(didUpdate)
  ```
- input:
- output:

用途

- 優先使用 `useEffect` 不會影響 UI 更新造成使用者體驗變差, 直到實際需要影響 UI 更新時才使用 `useLayoutEffect`
- 需注意如果使用 server-side rendering, `useEffect` 或 `useLayoutEffect` 都必須等待 JavaScript download 後才會執行.
  - 解決方案: 使用類似 `showChild && <Child />` 條件選染或者 `useEffect(() => { setShowChild(true); }, [])`
  - 讓 client-side 使用 `hydrate()` UI 時不會壞掉.

#### useDebugValue

- 在 Custom Hook 中提供 React DevTools 專用的 debug message
- 不推薦在每個 Custom Hook 都使用

Hook 簽名

- ```javascript
  useDebugValue(value)
  ```
- input: String message

用途:

- 推薦使用在共用函式庫裡的 custom hook
- 格式化 message string, 常常是昂貴的計算, 因此 `useDebugValue()` 第二個選用參數可以提供 formatting function
- 格式化函式只有在 React 實際需要時才會被呼叫, 範例 `useDebugValue(date, date => date.toDateString());`

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

- `constructor`, function component 不需要 constructor, 初始化狀態使用 `useState`
- `getDerivedStateFromProps`, [參考文件](https://reactjs.org/docs/hooks-faq.html#how-do-i-implement-getderivedstatefromprops)
- `shouldComponentUpdate`, 使用 `React.memo`, [參考文件](https://reactjs.org/docs/hooks-faq.html#how-do-i-implement-shouldcomponentupdate)
- `render`, 即 function component 的 body 與回傳值
- `componentDidMount`, `componentDidUpdate`, `componentWillUnmount`, 使用 `useEffect` Hook
- `getSnapshotBeforeUpdate`, `componentDidCatch`, `getDerivedStateFromError`, 目前 Hooks 尚未支援, 未來會支援.

How can I do data fetching with Hooks

- [參考文章: How to fetch data with React Hooks?](https://www.robinwieruch.de/react-hooks-fetch-data)

Is there something like instance variables?

- 使用 `useRef()`, `ref` 物件並不只用於捕捉 DOM reference, `ref` object 是一個通用的容器, 配合 mutable 的 `current` property 保存任何值.
- [參考範例](https://reactjs.org/docs/hooks-faq.html#is-there-something-like-instance-variables)
- `ref` 物件可以被視為 class 的 static variable, 可以在內部被任何函式取值與修改, 通過 `ref` 的 `current` property.
- 在配合 lazy initialization 時會有不可預期的行為需注意.

Should I use one or many state variables?

- 如果使用 object 或是 array 作為 `state` 時, 使用 `useState` 裡的 `setState` 與 class component 有巨大的不同在於使用 `replace` 取代原本的 `merge`.
- React 推薦把 state 依據是否一同修改作為判斷, 分成多個 `useState` 來分離 local state, 這麼做的好處是更容易抽離成 custom hook, 分離且重用邏輯.
- 如果有很複雜的 state 邏輯, 可以改用 `useReducer` 變成 Flux 架構或抽離成 custom hook 處理.

Can I run an effect only on updates?

- 這是一個少用的使用案例,
- 實作上可以使用 mutable ref, `useRef` 去保存一個 boolean 狀態告知是否是第一次渲染, 然後在 `useEffect` 中取得 `ref` 值去做判斷達成只有在 updates 時工作.
- 如果這個邏輯常常需要時, 可以抽離成 custom hook 重複使用.

How to get the previous props or state?

- 配合 mutable ref, `useRef` 去保存舊的值,
- [參考範例](https://reactjs.org/docs/hooks-faq.html#how-to-get-the-previous-props-or-state)
- 未來也許會直接原生提供類似的取值 Hooks, 目前可以使用 `useRef` 製作成 custom hook 使用.

Why am I seeing state props or state inside my function?

- 要在非同步行為中取得最新的 state 值, 可以配合 `useRef` 的 `ref` 使用
- [參考範例](https://reactjs.org/docs/hooks-faq.html#why-am-i-seeing-stale-props-or-state-inside-my-function) 說明新舊 state 與更新時間

How do I implement getDerivedStareFromProps?

- 在使用 getDerivedStateFromProps 之前可以先參考[文章: You Probably Don't Need Derived State](https://reactjs.org/blog/2018/06/07/you-probably-dont-need-derived-state.html)
- 只有非常少數的使用案例需要在 rendering 前 update state 並且如果有更新 state 時會觸發包含前一次在內的兩次 re-render.
- 參考使用 `useState` 保存狀態的[解決方案](https://reactjs.org/docs/hooks-faq.html#how-do-i-implement-getderivedstatefromprops)

Is there something like forceUpdate?

- 在使用 `useState` 或 `useReducer` 只有在前後的狀態改變時才會觸發 rendering, 如果相同則會 skip.
- 要實現 forceUpdate, 可以透過一定會使值不同的更新函式達成, 例如範例使用 `useReducer(x => x + 1, 0)`
- 盡可能避免使用 forceUpdate 破壞 React component 更新邏輯.

Can I make a ref to a function component?

- 當父層需要使用 `ref` 去操作子代 component 時, 可以通過 `useImperativeHandle()` Hook 與 `forwardRef()` 實現
- 可以把相關的函式直接定義在子代 component 然後透過 `useImperativeHandle()` 與 `forwardRef()` 把 ref methods 傳遞給父層使用, 這樣可以把實作細節留在子代.
- [參考範例](https://reactjs.org/docs/hooks-reference.html#useimperativehandle)

How can I measure a DOM node?

- 實現測量 DOM node 與在更新時通知 React component
- 範例中使用 `useCallback` 與 `ref` 實現,
- [參考範例](https://reactjs.org/docs/hooks-faq.html#how-can-i-measure-a-dom-node)
- 可以配合新的 element API, `ResizeObserver`

#### Performance Optimizations, 效能最佳化

Can I skip an effect on updates?

- 使用 `useEffect` 的選用參數 [conditionally](https://reactjs.org/docs/hooks-reference.html#conditionally-firing-an-effect)

Is it safe to omit functions from the list of dependencies?

- 一般來說不安全, [參考本篇說明與解決方案](https://reactjs.org/docs/hooks-faq.html#is-it-safe-to-omit-functions-from-the-list-of-dependencies)
- 對於 `useEffect` 來說應該把所有的 dependency 加上, 包含所呼叫的函式裡用到的部份.
- 因此 React 推薦把相依的函式宣告在 `useEffect` 內部, 利用 `useEffect` 控制與外部的連結, 除了安全也更容易看出來相依性.
- 在 `useEffect`, `useLayoutEffect`, `useMemo`, `useCallback`, `useImperativeHandle` 裡使用 dependencies list 時, 要包含所有相依的變數, 例如 props, state, ...
- 如果真的無法把 function 定義在 `useEffect` 內部時, 可以參考以下選擇
  - 把該 function 定義在 component 之外, 這樣確保該 function 不會相依 props, state
  - 如果是 pure function 可以在 rendering 時運算, 可以放置在 function component body, 讓 useEffect 通過區域變數的方式使用該 pure function 的回傳值
  - 使用 `useCallback` 包裹 function, 並且加上 dependency, 保障不會在 re-render 時新計算, [參考範例](https://reactjs.org/docs/hooks-faq.html#is-it-safe-to-omit-functions-from-the-list-of-dependencies)

What can I do if my effect dependencies change too often?

- 如果 `useEffect` 相依 `useState` 但是 state 變動很快並且 effect 不需要如此平凡被觸發時, 可以考慮使用 setState 改成傳遞 callback function 的方式改值, 並且使得 effect 不直接相依於 state 值.
- [參考範例](https://reactjs.org/docs/hooks-faq.html#what-can-i-do-if-my-effect-dependencies-change-too-often)
- 更複雜的案例中如果 state 與其他 state 互相相依時, 可以考慮改用 `useReducer` 來處理複雜的 state 管理, [參考文章](https://adamrackis.dev/state-and-use-reducer/)
- 如果 effect 相依的是 component 裡 mutable variable 可以使用 `useRef` 保存並且取值, 這是不得已的作法, 把函式相依於 mutable variable 破壞 pure 讓函式變得不可預測.

How do I implement shouldComponentUpdate?

- 使用 `React.memo()` 包裹 pure function component, 讓 element 的值只依據 props 的 shallow comparison, 等價於 `extends React.PureComponent`, 並且更有彈性可以傳入選用的 comparison function.
-

How to memoize calculations?

- 使用 `useMemo` hook 提供跨 rendering 的 memory, 解決提昇複雜計算的效能問題, 避免不必要的重算.
- 範例 `const memoizedValue = useMemo(() => computeExpensiveValue(a,b), [a, b]);`
- 使用 `useMemo` 的時機應該是針對 pure function 的計算, side effect 的處理都應該交由 `useEffect` 負責.
- 對於 React 來說 `useMemo` 只是作為效能最佳化的提示, 而非保證.
- 常用情境, 使用 `useMemo` 來最佳化複雜的 child component re-render.
- [參考範例](https://reactjs.org/docs/hooks-faq.html#how-to-memoize-calculations)

How to create expensive objects lazily?

- `useMemo`, 可以作為提示當相依值相同時不會重新計算, 但是不保證永遠不重新計算.
- 因此, 仍然有其他方式可以保證永遠不重新計算
- 常用情境, 當 initial state 需要複雜的計算時
  - 傳遞 callback function 給 `useState` 取代直接傳遞 initial state 的值,
- 常用場景, 當 `useRef` 的初值, 需要避免每次 render 都重新計算時,
  - 通過令 `useRef(null)` 再配合自行撰寫額外的 initialize function 中使用 `ref.current` 賦值來避免重算
- [參考範例](https://reactjs.org/docs/hooks-faq.html#how-to-create-expensive-objects-lazily)

Are Hooks slow because of creating functions in render?

- [參考文件](https://reactjs.org/docs/hooks-faq.html#are-hooks-slow-because-of-creating-functions-in-render)
- 對於現代的瀏覽器來說不會
- 甚至使用 Hooks 可以避免以下的效能消耗以提昇效能
  - 使用 Hooks 避免了建立 class 所需的效能消耗, 包含 instance, constructor 運作, 綁定 event handlers, ...
  - 使用 Hooks 取代 render props, higher-order component, context, 可以讓 React component tree 不這麼多層, 減少 React 的工作.
- 常見的 React component performance 最佳化, 建立在 `shouldComponentUpdate` 的實作上, React Hooks 有以下三種方式的解決方案
- `useCallback`, 保持 function 的 references 不會在每次 rendering 時重新創造.
- `useMemo`, 更簡單的建立 pure component 與 child update 最佳化.
- `useReducer`, 提供 flux 架構處理複雜的 state 管理

How to avoid passing callbacks down?

- 多數人不喜歡一層一層的傳遞 callback function
- 可以使用 `useReducer` 配合 `context` 傳遞 `dispatch()`, 用來解決深層的 component 觸發上層 state 的更新
- 自行選擇使用 React 明確的單向傳值或者使用 context API

How to read an often-changing value from useCallback?

- 不推薦使用, 可以視為 anti-pattern 並且在未來的 concurrent mode 中會有問題產生.

#### Under the hood, React Hook 的開發

How does React associate Hook calls with components?

- 受到 Rules of Hooks 的限制, React component 可以很好的辨認出 Hooks
- 每個 component 內部有自己的 memory cells 來控制 state

What is the prior art for Hooks?

- React Hooks 是整合了好幾個想法與舊的嘗試而成
- [參考文件](https://reactjs.org/docs/hooks-faq.html#what-is-the-prior-art-for-hooks) 說明細節

34 Q&A
