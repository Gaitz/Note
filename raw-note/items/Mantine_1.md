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

- `colorSchema`
- `focusRing`
- `focusRingStyles`
- `respectReducedMotion`
- `cursorType`
- `defaultRadius`
- `white`, `black`
- `colors`
- `primaryColor`
- `primaryShade`
- `defaultGradient`
- `fontFamily`
- `lineHeight`
- `transitionTimingFunction`
- `fontFamilyMonospace`
- `fontSizes`, `radius`, `spacing`
- `shadows`
- `breakpoints`
- `activeStyles`
- `headings`
- `fn`
- `dir`
- `loader`
- `components`
- `globalStyles`
- `other`
- 通過 `MantineProvider` 傳遞 theme object
- 獨立建立 theme object 可以使用 `import { MantineThemeOverride } from '@mantine/core'` type 來撰寫 TypeScript
- 通過 `useMantineTheme()` hook 來取得 theme object

MantineProvider

- 不是必須使用的,
- CSS rest and global styles
  - `withNormalizeCSS`, 使用類似 normalize.css 的功能
  - `withGlobalStyles`, 啟動一些預設的樣式
- CSS variables
  - 如果要使用純 CSS 或者其他方式進行 styling 不與 CSS-in-JS theme object 直接互動的方式
  - 需要開啟 `withCSSVariables`, 即可通過 CSS variable 的方式取得 theme object 定義的樣式
- Nested MantineProviders
  - 多層的 `MantineProvider` 改寫特定區域的 theme object
  - React Context 的用法 (functional way)
  - 通過給予 `inherit` prop 來繼承上一層的 theme object
- Styles on MantineProvider
  - Styles API 提供更強大的樣式客製化, [參考範例](https://mantine.dev/theming/mantine-provider/#styles-on-mantineprovider)
  - 會傳入 theme object, component params, 來協助定義
- Root selector
  - 如果想要改寫的 component 沒有提供 Style API 框架的話
  - 可以使用 Style API `root` 來進行設定
- Classes on MantineProvider
  - 通過 `classNames` 以類似 Style API 的方式賦予 component 帶上客製化的 class name
- Variants on MantineProvider
  - 客製化定義 `variant`
  - 傳遞一個物件
  - [參考文件範例](https://mantine.dev/theming/mantine-provider/#variants-on-mantineprovider)
- Sizes on MantineProvider
  - 客製化定義 `size`
  - 傳遞一個物件
  - [參考文件範例](https://mantine.dev/theming/mantine-provider/#sizes-on-mantineprovider)

Colors

- 預設使用 open-color, https://yeun.github.io/open-color/
  - 每個顏色會有十種變化
  - 以 array 儲存可以使用 index 取得
  - 越往後的顏色越深
- Adding extra colors
  - 客製化定義新的顏色
  - 通過 theme object `colors` 定義, 每個顏色必須有 10 個漸層設定
- Primary color
  - 預設是 `blue`
  - 用於沒有指定顏色的 component 和 focus styles
  - 通過 theme object `primaryColor` 定義, 必須使用已經定義在 `colors` 裡的顏色名稱, 不允許使用數值定義
- Primary shade
  - 設定主要的深淺階層
  - 在 dark mode 有些設定不會被採用
  - 可以針對 light mode, dark mode 設定不同的數值
  - 在 theme object 中 `primaryShade`, 定義數值或 `{light, dark}` object 分別指定
- Colors index reference
  - 在使用顏色時, 系統會參考 `primaryShade` 和 `colors` 設定來取得對應的顏色使用
  - `color` prop 可以通過 index 來指定 color shade, 例如 `blue.3`, `pink.4`
- Add custom colors types
  - 定義客製化顏色時的 TypeScript 設定
  - [參考範例](https://mantine.dev/theming/colors/#add-custom-colors-types)

Typography

- 通過 theme object 中的
  - `fontFamily` 來控制大多數的 component 字型
  - `fontFamilyMonospace` 來控制使用 monospace font 的元件像是 Code, Kbd, Prism
  - `headings.fontFamily` 針對 h1-h6 控制個別的字型
- 設定 Font sizes
  - 通過 theme object 中的 `fontSizes` object 來定義
- System fonts
  - Mantine 預設使用各個系統的 fonts
  - 如果沒有特殊需求推薦使用預設的方式提供更好的效能和一致的使用者體驗
- Headings
  - 設定 `headings` object, 可以指定 `fontWeight`, `fontFamily`, `fontSize`, `lineHeight`
  - 需要更細緻的設定可以通過 Styles API 針對特定的 component 進行設定, [參考範例](https://mantine.dev/theming/typography/#headings)
- 使用客製化的字型檔
  - 通過 `<Global>` component 進行設定, `import { Global } from '@mantine/core'`, [參考範例](https://mantine.dev/theming/typography/#load-custom-fonts)
  - 之後則可以在 MantineProvider 的 theme object 中使用

Default props

- 通過 theme object 中的 `components` object 裡的 `defaultProps` 針對個別的 component 設定一些預設的 props 設定, 像是 `size`, `color`
- 直接定義在 component props 上的參數會 override default props
- `defaultProps` 可以傳入 function 取得 `theme` object 來協助定義動態樣式
- Default props for static components
  - 以 `defaultProps` 設定 `Menu`, `Tabs`, `RichTextEditor` 類型的樣式
- Using with TypeScript
  - 客製化時的 Types [參考範例](https://mantine.dev/theming/default-props/#usage-with-typescript)

Theme functions

- 通過 theme object 裡的 `fn` 來定義樣式相關的 function 並且在其他地方使用
- 使用方式有
  - `createStyles` function
  - `sx` prop
  - `styles` component prop
  - `useMantineTheme` hook
- focusStyles
  - Mantine components 都有依據 `:focus-visible` 來定義 focus ring styles
  - 在客製化 component 時, 可以通過 `fn.focusStyles()` 來取得並且統一使用者體驗
- fontStyles
  - 通過 `fn.fontStyles()` 來取得定義在 theme 中的 font-family 和 font-smoothing styles
- smallerThan and largerThan
  - `fn.smallerThan()`, `fn.largerThan()` 來協助撰寫一致的 responsive styles
  - 會生成對應的 media query
- linearGradient and radialGradient
  - 以函數的方式 `fn.linearGradient()`, `fn.radialGradient()` 來協助定義 linear-gradient, radial-gradient styles
- gradient
  - `fn.gradient()` 回傳 `defaultGradient` 設定或者傳遞物件 `{ from, to, deg }` 定義客製化 gradient 樣式
- cover
  - `fn.cover()` 回傳樣式來覆蓋父層元件
  - 生成 position: absolute, 和對應的 inset
- lighten and darken
  - `fn.lighten()`, `fn.darken()`
  - 可以使用在 hex, rgb, rgba 的數值加上 percentage 協助回傳更深或更淺的顏色數值
  - 回傳值都是 rgba 格式
- rgba
  - `fn.rgba()`, 指定 alpha 值協助轉換顏色數值成 rgba 格式
- primaryShade
  - `fn.primaryShade()`, 取得 theme 中定義的 `primaryShade` 數值
  - 可以傳入 `'dark'`, `'light'` 如果有個別定義於 `primaryShade`
- primaryColor
  - `fn.primaryColor()`, 取得 theme 中定義的 `primaryColor` 數值

Emotion cache

- Mantine component 使用 [emotion](https://emotion.sh/docs/introduction) 來設定樣式, Mantine 會自動生成預設的 Emotion cache
- 特定情況可能會需要客製化定義 emotion cache 設定
- [參考文件](https://mantine.dev/theming/emotion-cache/)

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
