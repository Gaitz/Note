## React Official Documents - React Hooks

### [Website resource](https://reactjs.org/docs/hooks-intro.html), React

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

#### 第一章 - Introducing Hooks

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

#### 第二章 - Hooks at a Glance

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

#### 第三章 - Using the State Hook

#### 第四章 - Using the Effect Hook

#### 第五章 - Rules of Hooks

#### 第六章 - Building Your Own Hooks

#### 第七章 - Hooks API Reference

#### 第八章 - Hooks FAQ
