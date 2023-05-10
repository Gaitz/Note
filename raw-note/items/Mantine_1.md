## Mantine official documents

### [Mantine](https://mantine.dev/), Frontend/UI

---

第一章 - Learn the basics

第二章 - About Mantine

第三章 - Theming

第四章 - Styles

第五章 - Guides

第六章 - Mantine hooks

第七章 - Mantine form

第八章 - Mantine core

第九章 - Mantine dates

第十章 - Other packages

---

- React component library
- Works in modern environments
  - Next.js, Vite, CRA, Remix, Gatsby

### 第一章 - Learn the basics

- Go through Learn the basic, Theming, and Styles documents before starting development.

Theming

- 使用 React Context, 提供 `<MantineProvider>` 其中有 `theme` prop 可以傳入 Theme object 來客製化
- Dark color scheme, 一樣通過 theme object 實現, `{ colorSchema: 'dark' }`

Writing styles

- 樣式原生使用 css-in-js library 建立在 **emotion** library 之上
- 推薦使用 `createStyles()` 來客製化樣式, 來避免樣式碰撞
  - _補_: css-in-js 使用方式定義樣式, 以 `const { classes } = useStyles()` hook 來建立對應的樣式 className
- Styles API, 提供客製化內建元件的樣式, 以 `styles` prop 的方式傳遞

Components props

- Color prop
  - 可以使用原生的顏色或者預先定義在 theme object `colors`
  - `color` prop
- Sizes
  - 原生定義的大小或者給予數值
  - `size` prop
- Spacing and padding
  - 配合 theme object 預先定義好 `spacing` 傳遞 `{ xs, sm, md, lg, xl }` 大小數值
  - `spacing` prop
- Shadows
  - 原本會有預設的 box-shadow 也可以通過 theme object 的 `shadows: { xs, sm, md, lg, xl}` 重新定義一次
  - 可以指定使用或傳遞數值
  - `shadow` prop
- element `ref`
  - Mantine component 大多數都可以通過 `ref` prop 取得對應的 ref 綁定

Server side rendering

- 參考額外的文件支援 Next.js, Gatsby.js, Remix, 或者通用的方式設定 SSR

TypeScript

- `@mantine/core` package expose 一些 types 來協助 TypeScript 環境使用
  - `MantineTheme`, `ColorScheme`, `MantineColor`, `MantineGradient`, `MantineShadow`, `MantineSize`, `MantineNumberSize`
- 以慣例方式取得對應的 Component prop type
  - Example, `import type { ButtonProps } from '@mantine/core';`

---

### 第二章 - About Mantine

- React component library
- started in 2021/1

Browser support

- 實機測試於 Chrome, Safari, Firefox, Edge, Safari for iOS, Chrome for Android. 瀏覽器
- 不支援 IE
- 如果要支援舊版的瀏覽器需要額外瀏覽文件, 安裝 polyfills, 實際測試

Release cycle

- 依據 semantic version 的定義 https://semver.org/
- (0.0.X) 每個 Sunday, (1.X.0) 每個月, (X.0.0) 多數每 6 個月 (具有 breaking changes 時)

Previous versions

- v1 (1.3.1), v2 (2.5.1), v3 (3.6.14), v4 (4.2.12), v5 (5.10.5)

Project maintenance

Support project

- 目前不開放 donation 但是可以貢獻程式碼 (open source)

Mantine logo

- 可以通過 svg 取得或者使用 `@mantine/ds` package 中取得 `MantineLogo` component

---

### 第三章 - Theming

Theme object

MantineProvider

Colors

Typography

Default props

Theme functions

Emotion cache

---

### 第四章 - Styles

rem, em, and px units

sx prop

createStyles

Global styles

Responsive styles

Style props

Styles API

Styled components

---

### 第五章 - Guides

Custom components

Dark theme

Polymorphic components

RTL Support

Server side rendering

Using with CRA

Using with Gatsby.js

Using with Next.js

Using with Remix

Using with Storybook

Using with TypeScript

Using with Vite

---

### 第六章 - Mantine hooks

State management

UI and Dom

Utilities

Lifecycle

---

### 第七章 - Mantine form

use-form

Form values

Form errors

Form validation

Form validators

Nested fields

Touched & dirty

Form context

Recipes

---

### 第八章 - Mantine core

Layout

Buttons

Inputs

Navigation

Data display

Overlays

Typography

Feedback

Miscellaneous

---

### 第九章 - Mantine dates

DatesProvider

Calendar

DateInput

DatePicker

DatePickerInput

DateTimePicker

MonthPicker

MonthPickerInput

TimeInput

YearPicker

YearPickerInput

---

### 第十章 - Other packages

Carousel

Dropzone

Modals manager

Navigation progress

Notifications system

Prism code highlight

Rich text editor

Spotlight

---
