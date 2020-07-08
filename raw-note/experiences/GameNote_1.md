## GameNote Experience 1

### Setup
  1. nvm install Node.js, npm
  1. git clone
  1. `npm init` 
  1. `npm install react react-dom`
  1. `npm install --save-dev babel-loader @babel/core`
  1. `npm install --save-dev webpack webpack-cli`
  1. add file **webpack.config.js**
  1. add file **.babelrc**
  1. `npm install --save-dev @babel/preset-react`, **.babelrc** add `"@babel/preset-react"`
  1. `npm install --save-dev @babel/preset-env`, **.babelrc** add `"@babel/preset-env"`
  1. **webpack.config.js**, setup babel-loader
  1. Combine **.babelrc** into **webpack.config.js**, by babel-loader [options](https://webpack.js.org/loaders/babel-loader/)
  1. `npm install --save-dev webpack-dev-server`