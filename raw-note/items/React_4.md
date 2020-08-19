## Create React App official documents

### [Website resource](https://create-react-app.dev/docs/getting-started), React

---

[第一章 - Setup](#第一章%20-%20Setup)

[第二章 - Getting started](#第二章%20-%20Getting%20started)

[第三章 - Development](#第三章%20-%20Development)

[第四章 - Style and assets](#第四章%20-%20Style%20and%20assets)

[第五章 - Build your App](#第五章%20-%20Build%20your%20App)

[第六章 - Testing](#第六章%20-%20Testing)

[第七章 - Back-End Integration](#第七章%20-%20Back-End%20Integration)

[第八章 - Development](#第八章%20-%20Development)

---

#### 第一章 - Setup

1. `nvm`
1. `nvm install node`
1. `npx create-react-app`

- [nvm](https://github.com/nvm-sh/nvm)
- [create-react-app](https://facebook.github.io/create-react-app/)
- [create-react-app GitHub](https://github.com/facebook/create-react-app#creating-an-app)

---

#### 第二章 - Getting started

- Scripts

  - `npm start`
  - `npm test`
  - `npm run build`
  - `npm run eject`

- Support features
  - includes **no polyfills** by default
  - config [browserslist](https://github.com/browserslist/browserslist) checkout your code in browser support.

#### 第三章 - Development

- Editor settings (vscode)
  - syntax highlighting with [babel](https://babeljs.io/docs/en/editors/)
  - ESLint output in editor
  - React debugger mode
  - Format code with Prettier automatically.
- Develop React component in isolation
  - StoryBook
  - Styleguidist
- Https in development
  - `HTTPS=true npm start`

#### 第四章 - Style and assets

- Webpack based, `import .css`
- CSS Module, `import .module.css`
- work with Sass, are not recommended.
- add normalize.css `@import-normalize;`, any `.css`, duplicate will be removed.
- Post-Processing handled by `Autoprefixer`, minify, vendor prefixes,
  add Grid by `/* autoprefixer grid: autoplace */`
- Adding Images, Fonts, and Files, using Webpack way, `import logo from './logo.png';`
  image less than 10,000 bytes return [Data URI](https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Data_URIs) base64.
- add SVG,
  way 1. Webpack,
  way 2. import as ReactComponent
  `import { ReactComponent as Logo } from './logo.svg';`, `<Logo />`
- work with GraphGL
- Using the Public Folder, without Webpack and its benefit,
  using in `.html` as `href="%PUBLIC_URL%/favicon.ico"`
  using in `.js` as `<img src={process.env.PUBLIC_URL + '/img/logo.png'} />;`
- Code splitting,
  1. [dynamic import()](https://2ality.com/2017/01/import-operator.html#loading-code-on-demand)
  2. React Router

#### 第五章 - Build your App

- add React Router or other dependency `npm install --save react-router-dom`
- Can use both `require(), module.exports` or `import, export`,
  [different between](https://stackoverflow.com/questions/36795819/when-should-i-use-curly-braces-for-es6-import/36796281#36796281) `export default`, named `export`
- compiler option, `jsconfig.json`
- Using Global Variables, 1. `const $ = window.$;` 2. `// eslint-disable-line`
- Adding Bootstrap
- Adding Flow
- Adding TypeScript
- ? Adding Relay
- Adding a Router, client-side routing `npm install --save react-router-dom`
- Adding Custom Environment Variables
- Making a Offline-first Progressive Web App
  optional use, `serviceWorker.register()`
  Offline-First Considerations **intro list**
- Creating a Production Build
  `code splitting chunks` and `Static File Caching`
  https://jakearchibald.com/2016/caching-best-practices/

#### 第六章 - Testing

- Running Tests

  - Using [Jest](https://jestjs.io/) run on node environment
  - Jest is intended to be used for unit tests of your logic and your components
  - Create React App do not include end-to-end test
  - Jest test work with
    - Files with `.js` suffix in `__tests__` folders.
    - Files with `.test.js` suffix.
    - Files with `.spec.js` suffix.
  - `npm test` work in watch mode.
  - Jest will only run the tests related to files changed since the last commit.
  - Press a in the watch mode to force Jest to run all tests.
  - [Testing Components](https://create-react-app.dev/docs/running-tests#testing-components)
  - Option 1: Shallow Rendering with [Enzyme](https://airbnb.io/enzyme/)
  - Option 2: [React Testing Library](https://github.com/testing-library/react-testing-library)
  - Initializing test environment with browser API mock
  - Jest `it()`: test, `xit()`: exclude test, `fit()`: focus test
  - Coverage Reporting, `npm test -- --coverage`
  - Continuous Integration, CI servers
  - [Travis CI](https://docs.travis-ci.com/user/tutorial/), [CircleCI](https://medium.com/@knowbody/circleci-and-zeits-now-sh-c9b7eebcd3c1)
  - Disabling jsdom if do not need [it](https://create-react-app.dev/docs/running-tests#disabling-jsdom)
  - Snapshot Testing with [jest](https://jestjs.io/blog/2016/07/27/jest-14.html)
  - Visual Studio Code [extension](https://github.com/jest-community/vscode-jest)

#### 第七章 - Back-End Integration

#### 第八章 - Development

1. Static Server, `serve` Node.js
1. `Express` Node.js
1. AWS Amplify
1. Azure
1. Firebase
1. GitHub Pages
1. Heroku
1. Netlify
1. ZEIT Now
1. Render
1. AWS S3 and CloudFront
1. Surge
