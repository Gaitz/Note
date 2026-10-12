## ChatGPT Docs

### [ChatGPT Docs](https://learn.chatgpt.com/docs), Computer Science/AI

---

## 目標:

學習如何深度使用 AI 工具

---

ChatGPT Docs

- Overview
  - Get started
  - Foundations
  - Explore
  - Available on
  - Releases
- Features
  - Workflows
  - Capabilities
  - Reference
- Configuration
  - Customization
  - Config file
  - Agent configuration
  - Extend ChatGPT and Codex
  - Linux
  - Windows
- Developers
  - Overview
  - Development workflows
  - Extend and automate
  - Environments
  - Build with Codex
  - Third-party integrations
  - Reference
- Security
  - Overview
  - Permissions
  - Codex Security
  - Cyber safety
- Administration
  - Getting started
  - ChatGPT Work
  - Identity and authentication
  - Workspace access, policy, and models
  - Plugin and connector controls
  - Usage, governance, and compliance
  - Deployment and model providers

---

Overview

---

### Prompting

- 如何有效的給 AI 下指令
- 幾個關鍵
- **Goal**, ChapGPT 應該做什麼
- **Context**, 有哪些資訊或是資料來源
- **Output**, 輸出結果的格式和型態要求
- **Boundaries**, 防禦型邊界, 明確告知哪些是不能改變的或者不能做的

Context

- 主動告知 ChatGPT 如何取得 context
  - 直接提供參考檔案
  - 提供 screenshot, 圖片
  - 要求進行 web search
  - 使用 Project
  - 使用 Plugins, 連接其他軟體服務

個人化的 AI

Boundaries

- 明確告知邊界和不允許事項, 和在某些階段必須請求 review 結果後才執行

Output

- 明確告知輸出格式與要求
- 更重要的是 !! 在**使用** AI 生成的結果**前**, 需要**人工檢視**其成果 !!

如何產生更好的結果, Follow up messages

- 1 Follow up messages, 針對已生成的結果再次進行調整
- Codex 在運行時, 可以不必等結果完成, 即可調整
  - `Steer`, Codex `Enter`, 直接新增指令來調整當前的執行
  - `Queue`, Codex `Tab`, 為完成的結果提供 follow up messages, 然後自動執行

Prompting Codex

- `/plan`
- `/goal`
- `/review`
- `@`
- Examples
  - [Explain a codebase](https://learn.chatgpt.com/docs/prompting#explain-a-codebase)
  - [Fix a bug](https://learn.chatgpt.com/docs/prompting#fix-a-bug)
  - [Write a test](https://learn.chatgpt.com/docs/prompting#write-a-test)
  - [Prototype from a screenshot](https://learn.chatgpt.com/docs/prompting#prototype-from-a-screenshot)
  - [Iterate on UI with live updates](https://learn.chatgpt.com/docs/prompting#iterate-on-ui-with-live-updates)
  - [Delegate refactor to the cloud](https://learn.chatgpt.com/docs/prompting#delegate-refactor-to-the-cloud)
  - [Do a local code review](https://learn.chatgpt.com/docs/prompting#do-a-local-code-review)
  - [Review a GitHub pull request](https://learn.chatgpt.com/docs/prompting#review-a-github-pull-request)
  - [Update documentation](https://learn.chatgpt.com/docs/prompting#update-documentation)

---

### Personalize ChatGPT

ChatGPT 的 settings 分別在 web app 和 desktop app, 並且選項不同

- ChatGPT 的對話風格, a personality
  - 內建的選項
- Custom instructions
  - 1 客製化 ChatGPT 的對話風格
  - 2 添加會作用於所有 Chats 中的指令
  - Codex 中可以分成 global `AGENTS.md` 和 Projects / repositories `AGENTS.md`
- Match your writing style in Work
  - 當需要使用 AI 生成的內容時, 客製化讓生成的內容符合自身的寫作風格
- 使用 `Memories`
  - 讓 ChatGPT 可以使用過往的 chats 紀錄, 作為 context 來生成未來的內容
- MacOS desktop 專屬功能 `Computer History`
  - 讓 ChatGPT 可以讀取電腦的操作歷史 Computer History 來作為 context

---

### Skills & Plugins

重用 (Reusable) 與連接外部工具

- `Skill`, 為了完成特定任務或工作流程的, 指令集合
- `Plugin`, 可安裝的工具, 用來連接外部 MCP server, 來實現通過 MCP 調用外部工具

Skill

- 已知有效能達成特定任務, 可重用的指令, 可以打包成 Skill 來提供
  - 重用, 保持結果的一致性, 提高可靠度, 並且可以被分享
- 語法:
  - ChatGPT, `@`
  - Codex, `$`
- [建立 Skill](https://learn.chatgpt.com/docs/build-skills)
- [Record and Replay](https://learn.chatgpt.com/docs/extend/record-and-replay)
  - 以 Record 和 Replay 建立可重用的 workflow, 轉換成可重用的 Skill

Plugin

- Plugin 包含了 MCP 工具和 Skills
- 可被安裝和分享

---

### Permissions

權限控制

- AI 對 local files 的權限, 執行指令的權限, 使用網路的權限
- Sandbox
- Approvals

---

### ChatGPT Models

- Reasoning 越強的模型, 通常處理複雜問題的品質更高, 代價是花費的時間與 tokens 數量也更高

ChatGPT models

- Astra, 提供最高的品質, 適合用於需要跨多步驟且多工具的任務
  - 執行複雜的 end-to-end 任務, 可長時間運行
- Sol, 提供更高的品質
  - 執行複雜的 open-ended work, 執行複雜的探索與分析
- Terra, 日常需求入門
  - 當不需要使用到 Sol 級別的能力時的日常選擇
- Luna, 用來執行簡單且重複的任務
  - 最便宜且推理能力最差, 適合執行精確, 可驗證的大量重複工作

Reasoning effort

- Light, 適合需要快速且任務明確的
- Medium, 平衡速度與思考深度的中間選擇
- High / Extra High, 思考深度最深, 適合用於複雜任務

特殊設定, 需要額外在 settings 中開啟

- Max, 為單一任務提供最高效能, 更多的 reasoning, 通常用於最困難的問題, 且思考深度比速度更為重要的場景
- Ultra mode, 啟動 subagents, 並非只在 single-agent 模式
  - 用來加速執行, 代價也是更高的消耗
  - 讓 agent 進行平行化運行

---

Features

---

### Features - Workflows

Projects

- 把可持續進行且相關的 Chat 放在同一個 Project 下可以提供 model 更多且關聯的 context
- Desktop 版本, project 可以關聯本地的資料夾, 並且使用該資料夾下的資料作為 context
  - Edit Project 來加入 sources
  - 資料夾可以被指定為 primary 作為主要的 git 操作與 AI 設定檔存放位置, 其他資料夾則作為參考資料使用
- Quick chat
  - Mac 的 desktop 版本使用, `Option + space`, 啟動 quick chat, 使用獨立的空間進行 chat, 用於快速回答問題
- Setting 中 `Popout Window`, 也可以設定快捷鍵, 呈現彈出 chat 視窗並且可以設定是否為獨立空間

---

### Features - Sites

- Sites, 建立一個可發佈的網站, 由 ChatGPT 管理 production 部署問題 (hosting)

Get started with Sites

- 對話中使用 `@sites` 或者直接點擊 Sites 功能
- Describe the Site
- Review the Site
- Refine the Site
- Manage and share the Site

Review Site analytics

Add Sign in with ChatGPT

Understand projects, versions, and deployments

- 連結資料庫
- `d1`, relational SQL databases
- `r2`, Object storage

Choose a supported site shape

Control access and secrets

- 權限控管, 可看到, 可編輯, ...

Collaborate on a Site

- 需要在同一個 workspace 下才能分享編輯 sites 的權限

Configure runtime environment values

- 控制環境變數獨立於 prompting 與程式碼之外

Change a Site URL

Connect a custom domain

Review before you share

- 公開分享之前, 需要親自 review
- 內容, 測試網站, 確定沒有敏感資料外洩, ...

Take down or delete a Site

Understand limits and unsupported uses

- 支援 HTTP, HTTPS, WebSockets
- 儲存空間限制
  - D1, 10GB
  - R2, 沒有固定上限
- 禁止生成違法網站和與健康資料, 財務扣款相關的網站
- 如果是包含註冊功能的網站, 需要符合 General Data Protection Regulation (GDPR) 規則

---

### Features - Visualizations

- 生成圖表, 地圖, 模擬, ... 等等視覺化的結果, 來協助理解或作為產出結果
- 對話中加上 `@Visualize`
  - diagram
  - chart
  - map
  - interactive visualization
  - Site

Prompt with an outcome and controls

- 要求生成想要控制的變量控制項, 產生可操作的結果

Refine and continue

- 更多的 follow up 來調整結果
- 文件中有一些 tuning 的建議

Share or reuse a result

- 分享成果

---

### Features - Scheduled tasks

- 設定重複執行或者依據 event 執行的工作
- 並且 scheduled tasks 是背景執行的

Manage scheduled tasks

- 通過 Scheduled 目錄, 管理所有的 scheduled tasks
- 客製化的執行區間語法 RFC 5545 recurrence rule (RRULE)
- 分成在 Cloud 執行還是在 Local 執行
- 推薦搭配 Skill 使用, 來維持執行的一致性, 在語法中使用 `$skill-name` 來指定

Ask ChatGPT to create or update scheduled tasks

- 通過 prompting 讓 AI 去建立和更新 scheduled tasks

Schedule a task inside a chat

- 針對一個 chat 運行 scheduled task, 維持 context
- 一般的 scheduled task 是獨立運作的

Test scheduled tasks

- 在丟給 scheduled tasks 執行之前
- 應該先自己手動執行一次, 來確認結果是否符合預期

Worktree cleanup for scheduled tasks

- 對定期任務產生的結果進行清理, 只保留有需要的,
- 尤其是運行在 git worktree 的情形, 會產生過多不再需要的 worktree

Permissions and security model

- Scheduled tasks 是運作在當前預設的 sandbox 設定下
  - 會影響是否能使用網路, 修改文件, 調用其他 APPs
- 因此取決於當前的 sandbox 設定
  - read-only
  - workspace-write
  - full access

---

### Features - Long-running work

- 為需要多步驟長時間運行的 Work, 與 Chat 不同會有產出或有 side-effect 的行為
- 設定 Goal, `/goal`
  - 讓 AI agent 能驗證並且持續引導
- 一開始不知道 Goal 時, 可以使用 Plan `/plan` 來與 AI 討論, 直到明確知道 Goal
- Goal 建議同時包含
  - Outcome, 詳細描述結果的型態與期望
  - Constraints, 執行時的限制
  - Verification, 如何驗證正確與否, 是否算是正確完成
- Goal 的設定與否, 與權限設定無關, 依然符合 sandbox 設定與權限控制

Steer a running goal

- 執行中, 也可以暫停然後調整 Goal 的設定
  - 1 可以直接修改 Goal
  - 2 可以提供 follow-up

Run goals in parallel

- 通過 `worktrees` 控制, 避免讓多個 agent 同時修改相同的文件 (race condition)

---

Features - Notifications

Features - Pets

Features - Codex Micro

- 小的硬體裝置, 來啟用 Codex 功能

---

### Capabilities - Browser

- 讓 AI 可以操作 browser, Web 版與 Desktop 版本都可以使用
  - 是獨立的 profile 而非原本使用者使用的瀏覽器與設定
- 在瀏覽器中安裝 extension 的方式, 可以讓 AI 操作現有的瀏覽器與 tabs
- `@Browser`, 開啟瀏覽器功能
- 讓 AI 一起在瀏覽器中運作, 包含 UI 除錯改進, ...

Preview a page

Comment on the page

Styling feedback

Keep browser tasks scoped

Developer mode

- 讓 GPT 參與 Chrome DevTools Protocol (CDP)
- 需要在設定中授權 Settings > Browser and, under Developer mode, turn on Enable full CDP access.

---

Capabilities - Computer Use

- 讓 ChatGPT 可以看見且操作本地端的電腦環境

Capabilities - ChatGPT Voice

- 通過聲音與 ChatGPT 互動

Capabilities - Plugins

- ChatGPT 通過安裝 Plugins 來操作各種 Apps

---

### Capabilities - Sign in with ChatGPT

- 使用 ChatGPT 帳號登入支援的第三方服務
- 可以用來建立或者連結第三方服務的帳號
- 登入本身只分享基本 profile 資訊
  - name
  - email
  - profile picture
- 並不代表直接授權 Plugin 存取資料
  - Plugin 所要求的 permissions 依然需要另外確認與授權

---

### Capabilities - Web search

- 讓 ChatGPT 可以搜尋 Web 取得最新資訊
- 適合使用在需要 current / up-to-date information 的問題
- Web search 與 Browser 不同
  - Web search, 搜尋與取得網路資訊
  - Browser, 實際操作網站與網頁 UI

---

### Capabilities - Image generation

- 通過 prompting 生成或者修改圖片
- 可以在 Chat 中持續使用 follow-up messages 調整圖片
- 生成後的圖片可以繼續針對特定區域進行修改

---

### Capabilities - Image inputs

- 可以提供圖片作為 prompt 的 context
- 讓 ChatGPT 分析圖片內容
- 可以搭配文字 prompt 說明希望 AI 關注的部分
- 適合
  - screenshot
  - diagram
  - UI
  - photo
  - whiteboard 等視覺資訊

---

### Capabilities - Appshots

- Desktop app 功能
- 將目前其他 App 的視窗內容提供給 ChatGPT 作為 context
  - screenshot
  - 可以取得的文字內容
- 不需要手動 screenshot、copy / paste 或描述目前正在操作的 App
- 適合讓 AI 協助處理其他 App 中正在進行的工作

---

### Capabilities - Browser extension

- 將 ChatGPT 連接到目前使用的 Browser
- 與 ChatGPT 內建的獨立 Browser 不同
  - Browser extension 可以使用現有 Browser 的 tabs
- 可以
  - `@` mention 已經開啟的 tabs
  - 將選取的網頁內容加入 context
  - 讓 ChatGPT 操作 Browser
- 支援的 Browser 包含 Chrome、Edge、Brave、Opera、Vivaldi
  - 部分功能依 Browser 不同

---

### Capabilities - Work with files

- 可以提供 files 作為 ChatGPT 的 context
- 支援 documents、presentations、spreadsheets、PDF、images、data exports 等
- 可以要求 AI
  - summarize / compare
  - 尋找 patterns / inconsistencies
  - extract / clean / reorganize data
  - 使用檔案內容產生新的 artifacts
- ChatGPT 生成 file 後, 可以配合 `annotations`
  - 可以 preview
  - review 結果
  - 通過 follow-up messages 繼續修改

---

## ChatGPT dots

- 建立一個可以持續執行工作的 AI
- 與一般單次 Chat 不同, dot 可以持續維持自己的工作與 context

文件

- Getting started
- Messaging
- Tasks and memory
- Computers and apps
- Controls

---

## ChatGPT Space

- 用來進行 shared / collaborative work
- 使用 Pages 與 ChatGPT 和其他 collaborators 一起工作

文件

- Space overview
- Getting started
- Pages
- Work with the agent
- Collaboration

---

## Reference

### Commands

- ChatGPT Desktop app 的 commands reference
- 提供操作 ChatGPT / Codex 的各種 command 和 shortcuts

### Slash commands

- 使用 `/` 執行特定操作
  - 可以作為快捷鍵使用, 具備自動補完功能
- 例如前面使用過的
  - `/plan`
  - `/goal`
  - `/review`

### Settings

- ChatGPT Desktop app 的設定 reference
- 控制不同 features, permissions 與 app behavior

### Troubleshooting

---

Configuration

---

### Configuration - Customization

- 客製化 ChatGPT / Codex 的行為
- 可以使用 instructions 告訴 AI 在特定環境下應該如何工作
- Codex 可以使用 `AGENTS.md`
  - 提供持續性的 instructions
  - 可以針對不同 Project / repository 設定不同 instructions
- 適合放置
  - coding conventions
  - project structure
  - testing requirements
  - workflow
  - AI 執行任務時需要遵守的規則

---

### Configuration - Config file

- 使用 config file 設定 Codex 的預設行為
- 主要設定檔
  - `config.toml`
- 用來設定例如
  - model
  - reasoning
  - permissions / sandbox
  - tools
  - features
  - MCP servers
- 將常用的設定持久化
  - 不需要每次 conversation 都重新設定

---

### Configuration - Agent configuration

- 設定 AI agent 執行工作的環境與行為
- 可以控制
  - agent 使用什麼 model
  - reasoning effort
  - tools
  - permissions
  - execution environment
- 不同種類的工作可以設定不同 agent configuration

---

### Configuration - Extend ChatGPT and Codex

- 擴充 ChatGPT / Codex 原本具有的能力

主要方式

- Skills
  - 加入可重複使用的 instructions / workflows
- Plugins
  - 連接外部 Apps / tools
- MCP
  - 使用 Model Context Protocol 連接外部 tools / services
- 可以將常用 workflow 封裝後重複使用

概念上

    Instructions
        ↓
      Skills
        ↓
    ChatGPT / Codex
        ↓
      Plugins
        ↓
    MCP servers
        ↓
    External tools / services

---

### Configuration - Linux

- ChatGPT / Codex 在 Linux 環境中的設定
- 主要包含
  - installation
  - permissions
  - sandbox
  - filesystem access
  - command execution
- Linux 的權限與 sandbox 設定會影響 AI 可以操作哪些系統資源

---

### Configuration - Windows

- ChatGPT / Codex 在 Windows 環境中的設定
- Windows 有與 Linux / macOS 不同的 execution environment 與 sandbox 設定
- 主要包含
  - installation
  - permissions
  - filesystem access
  - command execution
  - Windows-specific configuration
