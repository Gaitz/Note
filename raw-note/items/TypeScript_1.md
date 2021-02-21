## TypeScript 程式設計, O'Reilly

### BOOK resource, TypeScript

---

第一章 - 簡介

第二章 - TypeScript: 10_000 英尺高的觀點

第三章 - 全部關於型別

第四章 - 函式 (Functions)

第五章 - 類別與介面

第六章 - 進階型別

第七章 - 處理錯誤

第八章 - 非同步程式設計、共時與平行處理

第九章 - 前端與後端框架

第十章 - Namespaces.modules

第十一章 - 與 JavaScript 的交互作業

第十二章 - 建置與執行 TypeScript

第十三章 - 結論

第十四章 - 附錄

---

### 第一章 - 簡介

- TypeScript 會在 build time 做型別檢查, 可以配合編輯器 plugin 讓在編輯時就一同檢查
- 設計時會變成先思考型別, 順帶考慮到更多的 edge cases

---

### 第二章 - TypeScript: 10_000 英尺高的觀點

TypeScript Compiler
- 編譯器把 TypeScript 編譯成 JavaScript 之前, 會先經過 Typechecker 的型別檢查
- TypeScript 的 type 與編譯後的 JavaScript 完全沒有關係

Type Systems
- 不需明確標示型別, 在 Runtime 時推論型別
- 明確指示型別並且在 Compiler time 受到檢查
- TypeScript 同時支援兩者
- TypeScript 指定型別 `value: type`, 型別註解於 `:` 後
- Practice: 讓 TypeScript 盡可能推論型別, 明確指定型別越少越好

TypeScript Type system
- 作為 gradually typed, TypeScript 並不需要知道全部的型別才能運作, 因此可以漸進式的移植舊有的 JavaScript codebase

安裝 TypeScript
- NPM `typescript`, `tslint`
- 建立設定檔 `tsconfig.json`, 手動建立或者使用 TSC cli `--init`
- `tsconfig.json`, 常見設定說明:
  - `include`, 輸入檔案來源
  - `lib`, 包含哪些 JavaScript 語法或環境
  - `module`, 使用的模組系統
  - `outDir`, 輸出檔案位置
  - `strict`, 嚴格檢查與否
  - `target`, 目標 JavaScript 版本
- `tslint.json`, 選用的 linter
- `index.ts`

---

### 第三章 - 全部關於型別

---

### 第四章 - 函式 (Functions)

---

### 第五章 - 類別與介面

---

### 第六章 - 進階型別

---

### 第七章 - 處理錯誤

---

### 第八章 - 非同步程式設計、共時與平行處理

---

### 第九章 - 前端與後端框架

---

### 第十章 - Namespaces.modules

---

### 第十一章 - 與 JavaScript 的交互作業

---

### 第十二章 - 建置與執行 TypeScript

---

### 第十三章 - 結論

---

### 第十四章 - 附錄

---

