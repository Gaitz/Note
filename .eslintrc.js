module.exports = {
  "env": {
    "browser": true,
    "es2020": true,
    "node": true
  },
  "extends": [
    "eslint:recommended",
    "plugin:react/recommended"
  ],
  "parserOptions": {
    "ecmaFeatures": {
      "jsx": true
    },
    "ecmaVersion": 11,
    "sourceType": "module"
  },
  "plugins": [
    "react"
  ],
  "rules": {
    "semi": ["error", "never"],
    "indent": ["error", 2],
  },
  "settings": {
    react: {
      "version": "detect"
    }
  }
}
