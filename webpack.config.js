const path = require('path');

module.exports = {
  entry: './src/example.js',
  output: {
    filename: 'main.js',
    path: path.resolve(__dirname, 'build'),
  },
  module: {
    rules: [
      {
        test: /\.(js|jsx)$/,
        exclude: /node_modules/,
        use: {
          loader: "babel-loader",
          options: {
            "presets": ["@babel/preset-env", "@babel/preset-react"]
          }
        }
      }
    ]
  }
};