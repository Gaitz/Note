## React Official Documents - Main Concepts

### [Website resource](https://reactjs.org/docs/hello-world.html), React

---

第一章 - Installation

第二章 - Hello World

第三章 - Introducing JSX

第四章 - Rendering Elements

第五章 - Components and Props

第六章 - State and Lifecycle

第七章 - Handling Events

第八章 - Conditional Rendering

第九章 - Lists and Keys

第十章 - Forms

第十一章 - Lifting State Up

第十二章 - Composition vs Inheritance

第十三章 - Thinking in React

---

#### 第一章 - Installation

- React is a JavaScript library

CDN:

```html
<script
  src="https://unpkg.com/react@16/umd/react.development.js"
  crossorigin
></script>
<script
  src="https://unpkg.com/react-dom@16/umd/react-dom.development.js"
  crossorigin
></script>
```

[Beginner tutorial](https://www.taniarascia.com/getting-started-with-react/)

React

ReactDOM

Babel and JSX

`npx create-react-app`

components:

- class component
- pure function component

props

states

#### 第二章 - Hello World

[Main concepts](https://reactjs.org/docs/hello-world.html)

Hello World

- JavaScript ES6

---

#### 第三章 - Introducing JSX

- HTML in JavaScript
- markup + UI logic
- as HTML element
- use JavaScript inside `{ }`
- `( )` wrap multiple lines JSX
- JSX attribute use camelCase, `className`
- always close `</>`
- prevent injections (XSS), everything is a string
- convert by babel to `React.createElement()` and then into object `{ }`, as React element.

---

#### 第四章 - Rendering Elements

- React elements are plain objects
- React usually have a single root DOM node
- `ReactDOM.render()`
- React elements are immutable
- React Only Updates What’s Necessary

---

#### 第五章 - Components and Props

- components are like JavaScript functions, They accept arbitrary inputs (called “props”) and return React elements.
- Function component, literally a pure JavaScript function.
- Class component, ES6 `class`, `extends React.Component`, `render() {}`
- component name start with capital letter, lowercase represents HTML tag.
- Composing Components
- Extracting Components into smaller components.
- Props are Read-Only
- All React components must act like pure functions with respect to their props.
- pure function

---

#### 第六章 - State and Lifecycle

1. render with state

- The render method will be called each time an update happens.
- State is **private** and fully controlled by the component.
- Adding Local State to a Class
- Class components should always call the base constructor with props.

```JavaScript
constructor(props) {
    super(props);
}
```

2. add life cycle

- "mounting" is rendered to the DOM for the first time. (setup)
- "unmounting" is removed from the DOM. (clear)
- `this.setState({ })`, `this.setState(function () {})`

  - Do Not Modify State Directly, this will not re-render a component.
    - The only place where you can assign this.state is the constructor.
  - State Updates May Be Asynchronous, multiple setState() calls into a single update for performance.
  - State Updates are Merged

- state is top-down, unidirectional data flow.

---

#### 第七章 - Handling Events

- very similar to handling events on DOM elements.
- CamelCase
- pass handle function
- class component, function need to `bind(this)`
- the other two ways: arrow function when call, class field syntax (experimental syntax)
- recommend binding in the constructor or using the class fields syntax
- Passing Arguments to Event Handlers, `(e) => this.deleteRow(id, e)` or `this.deleteRow.bind(this, id)`

---

#### 第八章 - Conditional Rendering

- JavaScript: `if else`, `{ && }`, `? :`
- return `null`

---

#### 第九章 - Lists and Keys

- JavaScript `map()`
- special property `key=`
- unique to sibling
- key used in `map()`

---

#### 第十章 - Forms

- Controlled Components (handle by React)
- Uncontrolled Component (cannot or do not want to handle by React)
- [Formik](https://jaredpalmer.com/formik)

---

#### 第十一章 - Lifting State Up

- components common states handle from their closest common ancestor.
- pass props and handle functions
- top-down data flow

---

#### 第十二章 - Composition vs Inheritance

- pass children components as special prop, `props.children` or custom props.
- component is just an object. pass as variables.
- always composition, pass everything, functions, React elements, data, as props.

---

#### 第十三章 - Thinking in React

1. see the mock, and make a component hierarchy
1. build a static version ( never use state at this stage)
1. find out state, ( computing better than memory )
1. right place of state
1. one way binding
