## HTML

### Computer Science

---

第一章 - Common Questions

---

### 第一章 - Common Questions

- Browser kernel

  - 分成 **JavaScript engine** 與 **layout engine**, **rendering engine**
  - Chrome 使用 **webkit** as browser kernel, **V8** as JavaScript engine

- 跨 tab 的通訊

  - **cookies** 與 **localStorage** 都是 **origin** shared
  - **Websocket** 與 **SharedWorker**
  - 記得 same-origin-policy

- `Document.visibilityState` 確定頁面是否被看見

- inline 標籤的語意

  - 樣式相關 physical style 沒有特定語意, `b`, `i`, `u`, `s`, `pre`
  - 語意相關 semantic, `strong`, `em`, `ins`, `del`, `code`

- `window`, `document` 的差別

  - `window` 為瀏覽器視窗資訊
  - `document` 為當前的 DOM, 也是 `window.document` 的別稱, 因為 `window` 是瀏覽器的 global reference

- `defer`, `async`, default 的差別
  - default, **parser** -> **fetch** -> **execution**, 三個階段是同步順序的執行
  - `defer`, parser 與 fetch 可以非同步的一起執行, 但是 **execution** 仍然會等待 parser 全部完成後才執行
  - `async`, parser 與 fetch 如同 `defer` 一樣可以非同步執行, 並且 **execution** 會搶先 **parser**, 即 **fetch** 結束後立即 **execution** 同時 **parser** 會暫停
  - 因此與 DOM 無關的 library 才適合使用 `async`, 例如 tracking 相關
  - 與 DOM 有關的需要使用 `defer` 來加速 **fetch** 階段
