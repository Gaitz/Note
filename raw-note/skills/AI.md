## AI

### Computer Science

---

第一章 - Terminology

第二章 - Questions

---

### 第一章 - Terminology

---

OpenAI, 提供生成式 AI 服務的公司

- Models: GPT series
  - latest version GPT‑5.6 Sol, 2026.6.26
- 服務:
  - ChatGPT 始於 2022
  - ChatGPT Deep Research
  - ChatGPT Search
  - ChatGPT Atlas
  - OpenAI Codex
  - Sora (text-to-video model)
  - Whisper (speech recognition system)

---

two types of tokens

- Input tokens, 輸入給 model 的 token 數量, 包含所有的後續資料 context history
  - cached input tokens
  - uncached input tokens
- Output tokens, model 思考和輸出的 token 數量
  - reasoning tokens: model 與自己進行對話, 思考, 以提供更高品質的輸出
  - output tokens
- 使用 AI 時如何計價, 和執行運算所需的衡量標準
- AI model 以 token 為單位進行處理
- Context management, 對 AI 如何使用 tokens 進行優化

### Input tokens

Compactions

- 讓 AI 對 context history 進行壓縮, 讓未來再次使用時, 不需要重複執行
- 壞處是會遺失細節, 因為細節屬於當時的 context

Caching

- 對過去完整的歷史進行 caching

### Output tokens

Reasoning tokens

- AI 自己與自己對話, 以提供更高品質的輸出
- 壞處是可能會十分昂貴, 消耗大量的 tokens
- Reasoning efficiency, 比較各家 AI 對於 reasoning 時所使用的 tokens 數量
- 一種 model 的優化是 reasoning 階段與 output 階段使用不同的說話方式
  - 讓 reasoning 階段可以在語言上降低費用, 盡可能精簡
- AI model 實際的 reasoning traces 通常是不公開的, 防止其他競爭對手使用

[ref: Why is OpenAI so much more efficient?](https://www.youtube.com/watch?v=ypO0q_8zhWw)

---

### 第二章 - Questions

---

對我有意義的 AI model 使用情境 ?

- 在看 Youtube 影片時, 在 Youtuber 沒有提供目錄的情況下, 可以讓 AI 幫忙整理成章節
  - Prompt: `bullet points the content into chapter titles`

---

AI model 如何進行 tokenization ?
