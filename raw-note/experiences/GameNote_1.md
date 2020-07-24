## GameNote Experience 1

### Setup
  * Node.js
    1. nvm install Node.js, npm
    1. `npm init` 
  * Git repository
    1. git clone
  * Webpack + Babel
    1. `npm install --save-dev webpack webpack-cli`
    1. add file **webpack.config.js**
    1. `npm install --save-dev babel-loader @babel/core`
    1. `npm install --save-dev @babel/preset-react`, **.babelrc** add `"@babel/preset-react"`
    1. `npm install --save-dev @babel/preset-env`, **.babelrc** add `"@babel/preset-env"`
    1. **webpack.config.js**, setup babel-loader
    1. Combine **.babelrc** into **webpack.config.js**, by babel-loader [options](https://webpack.js.org/loaders/babel-loader/)
  * Webpack-dev-server
    1. `npm install --save-dev webpack-dev-server`
  * React
    1. `npm install react react-dom`
  * Webpack config details
    1. `npm install --save-dev webpack-merge`
    * details follow [the document](https://webpack.js.org/guides/production/#setup)
    