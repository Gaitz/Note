## CSS

### Computer Science

---

第一章 - Common Questions

---

### 第一章 - Common Questions

- Box model,

  - Content -> Padding -> Border -> Margin

- CSS selector

  - id `#`, class `.`, element, relational `+`, ` `, `>`, `~`, wildcard `*`, attribute `[]`, Pseudo class `:`, element `::`

- CSS selector weight

  - 越多組合的權重越高 more specific
  - 同級時最後載入的優先
  - in element > in page > external
  - `!important` > id > class > element

- CSS 置中技巧

  - `margin: auto`,
  - `display: flex; align-items: center; justify-content: center;`
  - `relative` + `absolute` + `transform: translate(-50%, -50%);`
  - `display: grid; height: 100%` + `margin: auto;`

- `display` values

- `position` values

- CSS 圖形, triangle 三角形製作

  - 當 `width: 0; height: 0;` 利用 **border** 配合 `border-color: transparent` 來隱藏不需要的其他三角形

- CSS normalize 與 CSS reset

- CSS margin collapsing

- 以 `clear` 清除 `float` 元素的影響, 高度消失

- `@media` query

- 圖片格式的差別?

  - **png**, **jpg**, **gif**, **webp**

- **reflow** and **repaint**

  - DOM + CSSOM -> Rendering Tree -> Layout -> Paint -> Compositing
  - reflow 計算, 大小, 位置, 是否可見, 也是依據 frame 來進行批次處理
  - repaint 畫面需要更新的地方進行重繪製
  - 可以參考網站 [CSS Triggers](https://csstriggers.com/) 得知, 不同屬性的影響
  - 效能優化:
    - 避免使用 reflow 的屬性改用其他的
    - 減少 reflow 所影響的範圍, 例如分圖層
    - 盡可能批次處理
    - 減小 DOM 與 CSSOM 的層數, 並且避免重複呼叫 API

- **frame**, 偵數
  - `window.requestAnimationFrame()`
  - 畫面更新的頻率, 大多數是 **60fps**, 因此 1second / 60 flames = 16.66ms, 即每個 frame 的處理時間
  - 當處理時間超過時, browser 會自動降低更新頻率, 讓每一偵有更多的處理時間, 但是在肉眼可見就會變得不流暢
