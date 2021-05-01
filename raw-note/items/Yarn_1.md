## Yarn, official documentation

### [Yarn](https://yarnpkg.com/), Yarn

---

第一章 - Getting started

第二章 - Features

第三章 - CLI

第四章 - Configuration

---

### 第一章 - Getting started

Introduction 簡介

- Share code in `package`,
- configuration or manifest with `package.json`

Installation 安裝

- 先在 global 安裝 yarn, `npm install -g yarn`
- 然後在個別 project 設定 version, `yarn set version`

Usage 常見指令

- `yarn help`, 列出所有指令
- `yarn init`, 初始化 project
- `yarn`, `yarn install`, 依據 package.json 安裝 dependencies
- `yarn add [package]`, 新增 dependency, `--dev` 開發限定, `--peer`
- `yarn up [package]`, 升級 package dependency
- `yarn remove [package]`, 移除 dependency
- `yarn set version`, 升級 yarn 本身版本

Editor SDKs 配合編輯器時的工具

- 在 dependency 含有特定的 package 例如 TypeScript, ESlint, ... 時，配合特定的 editor 需要做額外的設定
- Editor setup 包含 VSCode, VIM, EMACS

Migration Yarn1.0 的升級指南

Questions and Answers

- Why should you upgrade to Yarn Modern? 為什麼要升級到 Yarn 2.0?
  - 新功能
  - 更好的效能, 在速度與容量上都有進步
  - 更容易客製化
  - 更穩定
  - 對於 Yarn 本身的開發採用新架構更好開發未來的功能
- How easy should you expect the migration from Classic to Modern to be? 升級到 Yarn 2.0 的難度？
  - 設定檔從 `.npmrc`, `.yarnrc` 改成 `.yarnrc.yml`
  - 有些第三方的 packages dependency 沒設定好需要額外設定 `packageExtensions`
  - 與 editor 整合使用 SDK 需要額外安裝
  - 某些工具需要降版，例如 `React Native`, `Flow`
  - 大多數問題能在一個下午的時間內解決
- Which files should be gitignored? 哪些檔案應該被加入到 `.gitignore`
  - 該忽略的 yarn 生成檔案與各自的說明
- Should lockfiles be committed to the repository? `yarn.lock` 應該被加入到版本控制中嗎？
  - 是的。
- How to share scripts between workspaces? 如何在使用 workspaces 時共用 yarn script?
  - Yarn Script 中如果包含 `:`, 例如 `g:tsc` 都可以被任何的 workspace 直接呼叫
  - 可以配合 `$INIT_CWD`, `${PROJECT_CWD}` 來設定 Script 想要執行的位置
- Is Yarn operated by Facebook? Yarn 是 Facebook 所管理的嗎？
  - 並不是，Yarn 是屬於社群管理的,
- Why registry.yarnpkg.com? Does Facebook track us? 是否被 Facebook 所追蹤呢？
- Queries to registry.yarnpkg.com return a 404/500/...; is it down?
  - CNAME, 域名以 CNAME 的方式指向真實的域名，協助 DNS 解析
  - Yarn 本身並不存放與管理 packages 實體，而是使用 CNAME 的方式指向 `npm` server
- Is Yarn faster than other package managers? Yarn 是否比其他的管理工具更快速呢？
  - 速度是相對的, Yarn 沒有刻意追求 performance, 重要的是其他價值

---

### 第二章 - Features

#### Constraints

- 尚在實驗性的功能, API 可能會被改變， 尚未穩定
- 用途是解決 monorepo 裡對所有 workspaces 的管理

#### Offline Cache

- 本地端的 Cache, Yarn 率先檢查 cache 的版本並且直接使用，因此可以達到 offline 功能。
- Yarn repository 甚至將 cache 直接加入版本控制中，達到 zero install 的功能
- Cache 預設在 `.yarn/cache` 可以通過 `cacheFolder` 設定其他位置

Disabling the cache

- 本地端可以通過, 啟用 sharing the cache 機制, 去共用 global cache.
- 直接刪除 cache folder 也是沒有問題的，會在下一次 `yarn install` 時再次自動生成
- global cache 也可以通過 `enableMirror` 設定值去關閉， 但是不推薦, 這樣 Yarn 就無法使用 cache 加速 install

Cleaning the cache

- 在 remove 或 upgrade 時，Yarn 會自動移除不必要的 cache
- 也可以通過 `yarn cache clean` 去移除全部的 cache
- global cache 的清除則需要手動觸發 `yarn cache clean --mirror`

Sharing the cache

- 想要關閉 local cache 改採用 global cache 時，可以在 `.yarnrc.yml` 中設定 `enableGlobalCache: true`

Cache integrity 安全性

- Cache 檔案會有 checksum 並且在 yarn install 時會被驗證

#### Plug'n'Play

- Plug'n'Play (PnP) 一個在 Node.js 上新的安裝策略
- 如果是 package 作者想要符合 PnP 安裝, 可以參考 [advanced/PnP API 文件](https://yarnpkg.com/advanced/pnpapi/)

The node_modules problem

- 在 Node.js 上 `node_modules` 的 package 解析是一路向上層依序的搜尋每個 node_modules，是個效率不佳的方式
- node_modules 的問題，大量的 IO 呼叫不管在查詢, 建立, 與使用上, 失敗的結構讓 deduplicate 不容易達成, 造成大量的 disk memory 浪費

Fixing node_modules 嘗試修復 node_modules 的問題

- Plug'n'Play 的想法來自於既然 package manager 已經知道所有的 dependency 並且安裝在 disk 上，為什麼不由 package manager 直接告知 node interpreter 要執行的程式來源
- 在 Yarn 2.0 之後，使用 Plug'n'Play 安裝的話，Yarn 會生成 `.pnp.cjs` 檔來取代 `node_modules`, 一次完成安裝並且標記名稱, 版本與實際位置
- 優點
  - 只要建立單一個 `.pnp.cjs` 檔案就能完成安裝, 因此效能就不會卡無數個 disk I/O
  - 減少了大量的 I/O 因此減少了錯誤產生的機會， 更加穩定
  - 最佳化 dependency tree,
  - `.pnp.cjs` 可以被加入版本控制，作為 Zero Install 的一部分, 取代 `yarn install`
  - 更快速的 node.js application 啟動時間, 因為 node.js 不用在走訪檔案系統中的 node_modules

Initializing PnP 初始化 PnP

- 使用方式 1. 利用 `yarn node` 指令執行 node 直譯器呼叫, 會自動使用 `.pnp.cjs` 作為 runtime dependency
- 使用方式 2. 在無法使用方式 1. 時，可以在最先載入的 script 開頭加上 `require('./.pnp.cjs').setup()`
  - 使用 `NODE_OPTIONS="--require"`去載入初始化用的 script, 參考[文件](https://yarnpkg.com/features/pnp#initializing-pnp)

PnP loose mode, (`pnpFallbackMode`)

- 在 PnP 預設的嚴格模式下有問題時，嚴格模式會禁止沒有明確標示 dependency 的呼叫。
- 可以啟動 loose mode, 會在有問題時執行 fallback mode 從預先生成的 node_modules hoister 中尋找。
- 啟動方式, 在 `.yarnrc.yml` 加上 `pnpMode: loose`
- 缺點: 會 emit warning 取代 throw error，但是不影響 runtime。 參考[說明](https://yarnpkg.com/features/pnp#caveat)

Caveats and work-in-progress

- PnP 要解決的是 Node 原生的 require resolve 低效問題。其他 Node 上運行的工具，有些有自行實作各自版本的 resolve 演算法, 例如 `Webpack`, `Babal`, `Jest`, ...
- [Compatibility table](https://yarnpkg.com/features/pnp#native-support) 標示出原生支援 PnP 的工具列表與支援版本

Frequently Asked Questions

- Why not use import maps?
- Packages are stored inside Zip archives: How can I access their files?
  - `.pnp.cjs` (runtime), 會呼叫 Node `fs` module 去取得 Zip 裡的程式
- Different behaviors based on workspace / not-a-workspace
  - 在過渡時期有 fallback 機制，導致行為可能不同。在未來會被移除，或者手動關閉 `pnpFallbackMode` set to `none`

#### Plugins

- Yarn 本質是不斷進步，實驗性增長的。
- 因此 Yarn 採用 plugins 方式組合所有的功能
- 甚至在 Yarn 2 之後, 核心的 `yarn add` 與 `yarn install` 都是以預先安裝的 plugins 方式存在
- 撰寫 plugins 參考 [advanced/Plugin Tutorial](https://yarnpkg.com/advanced/plugin-tutorial)
- plugin 以 `yarn plugin import ` 語法加入

Plugins 能作到的事情

- 實現新的 resolvers, 用來解析對應版本與實際的程式庫
- 實現新的 fetchers， 改變取得實際函式庫的方式, 例如 remote registry, local cache, ...
- 實現新的 linkers, 實現不同的機制達成 linker 實際呼叫時的函式庫連結方式
- 實現新的 commands, 實現客製化的 Yarn CLI 並且自動整合進 Yarn 例如 `yarn --help` 裡
- 註冊 event, 可以在 package manager 的 lifecycle 中加入 hooks 插入一些客製化的邏輯
- 整合任何的 plugins, 每個 plugins 都會產生 hooks 可以被互相註冊

官方的 plugins,

- 通常是實驗性 feature, 參考[列表](https://yarnpkg.com/features/plugins#official-plugins)

社群的 plugins

#### Protocols

- Dependency 解析的 protocols,
- 使用不同的來源與語法, 包含 Semver, Tag, Npm alias, Git, GitHub, File, Link, Patch, Portal, Workspace, Exec

#### Release Workflow

- 實驗性功能
- 使用需要安裝 `version` plugin, `yarn plugin import version`
- 用來解決 monorepos 裡的 packages 更新問題, Yarn 希望提供一個原生的解決方案

#### Workspaces

- 提供實現 monorepos 的工具
- 相關的詞彙
  - project, 通常是 repository
  - workspace, 一個 package 單位
  - worktree

Workspace

- Yarn 提供良好的管理單獨 workspace 裡的 dependency 而不是產生一個巨大且無法管理的 project level dependency
- workspace dependency 會率先使用在 project level 裡的 package 而不用從 remote registry 拉取。更好的重用，減少不必要的 duplicate

Workspace ranges `workspace:` 與 publishing workspaces

- 跨 workspace 之間的程式碼重用

Lerna

- Lerna 可以與 Yarn workspace 一同使用
- 可以把 Lerna 視為更高階抽象層, Yarn workspace 作為他的底層實現

#### Zero-Installs

- 選用的功能, 相對應於 `yarn install` 指令安裝 dependencies 並且原先的 `yarn install` 流程並沒有打算被移除
- `yarn install` 依據 lock 檔來確保每次安裝都是相同的內容
- 啟動 zero-install, 藉由把 `.yarn/cache` 與 `.pnp.cjs` 加入 repository 都存到版本控制中
- 概念上等同於把 node_modules 直接存入版本控制中以減少每次安裝的時間，但是 yarn zero install 會儲存小很多的內容, 並且可以通過 `yarn install --check-cache` 來檢查 cache package hash 是否相等 (避免安全疑慮)

---

### 第三章 - CLI

- `yarn add [package]`, 新增 dependency
- `yarn bin [name]`, 取得使用的 script 路徑
- `yarn cache clean`, 移除所有 yarn 快取 (package)
- `yarn config get [name]`, 印出 yarn 指定的設定值
- `yarn config set [name] [value]`, 設定指定的 yarn 設定值
- `yarn config unset [name]`, 取消指定的 yarn 設定值
- `yarn config`, 印出 yarn 當前的所有設定值
- `yarn constraints query`, 配合 `constraints` plugin 使用, 查詢
- `yarn constraints source`, 配合 `constraints` plugin 使用, 印出原始碼
- `yarn constraints`, 配合 `constraints` plugin 使用, 檢查與修復 (`--fix`)
- `yarn dedupe`, 移除或檢查 (`--check`) 指定範圍內的重複 dependency, 因為會影響 lock 的狀況，因此需要自行檢查移除的狀況確定是所需要的。
- `yarn dlx [command]`, 暫時執行指定的 package 指令, 使用範例暫時安裝 `create-react-app` 並且執行，但是不加入 dependency
- `yarn exec [commandName]`, 執行 shell script
- `yarn explain peer-requirements [hash]`, 列出一組或所有的 peer requirements
- `yarn info [package]`, 列出指定 package 的資訊, 包含子代資訊, 快取狀態, 版本, ...
- `yarn init`, 初始化 yarn package, 私有 `--private`, workspace 使用 `--workspace`
- `yarn install`, 安裝當前所有的 dependencies, [文件說明](https://yarnpkg.com/cli/install#details) install 時的四步驟, Resolution, Fetch, Link, Build
- `yarn link [destination]`, 客製化 resolutions 指定使用特定的 workspace 或者 project 的 packages
- `yarn node [nodeScript]`, 執行 `node` script 已經設定好 Yarn 相關的 setup, 例如自動支援 `PnP`
- `yarn npm audit`, 印出 packages 是否有已知的漏洞， 安全性報告, 可以通過 flag `--all`, `--recursive` 擴張檢查範圍
- `yarn npm info [package]`, 查詢指定 package 的資訊 (來自 npm registry)
- `yarn npm login`, 登入 npm registry, flag 可以設定: 範圍 `--scope`, 發布的 registry `--publish`
- `yarn npm logout`, 登出 npm registry, 關閉本地端與 npm registry 的授權
- `yarn npm publish`, 發布當前的 workspace 到 npm registry, 預設是發布到 private (需 npm 付費), 可以通過 `--access public` flag 發布到 public
- `yarn npm tag add [package] [tag]`, 為特定版本的 package 加上 tag (在 npm registry 上)
- `yarn npm tag list [package]`, 印出指定 package 所有的 tag (在 npm registry 上)
- `yarn npm tag remove [package] [tag]`, 移除指定 package 的指定 tag (在 npm registry 上)
- `yarn npm whoami`, 印出當前的 username
- `yarn pack`, 自動壓縮打包當前 workspace 以方便 publish 時使用
- `yarn patch-commit [patchFolder]`, 只有在執行過 `yarn patch` 的 folder 下才有作用
- `yarn patch [package]`, 對指定的 package 生成 patch, 給 `patch:` protocol 使用
- `yarn plugin import from source [name]`, 從 Yarn repo 中下載原始碼並且編譯 plugin
- `yarn plugin import [name]`, 下載指定的 plugin 使用
- `yarn plugin list`, 印出所有的 yarn 官方 plugins
- `yarn plugin remove [name]`, 移除指定的 plugin (從 `.yarn/plugins` 中)
- `yarn plugin runtime`, 印出當前使用中的 plugins
- `yarn rebuild`, 重新建置當前 project 中的 packages
- `yarn remove [package]`, 移除指定的 dependency, 可以使用 glob pattern 一次刪除多個
- `yarn run [scriptName]`, 執行定義在 package.json 裡的 yarn script
- `yarn search`, 需額外安裝 `interactive-tools` plugin 使用, 開啟互動視窗, 可以查詢且安裝 npm registry 上的 packages
- `yarn set resolution [descriptor] [resolution]`, 強制指定的 descriptor 解析成指定的 resolution
- `yarn set version from sources`, 從 yarn repository 安裝 yarn, 可以使用 flag 控制, 安裝指定的來源, 分支, 與 plugins
- `yarn set version [version]`, 設定當前 project 的 yarn 版本, 可以使用 `latest`, `classic` 指定版本
- `yarn stage`, 需額外安裝 `stage` plugin 使用, 把 yarn 相關的檔案加到版本控制的 stage 中, 可以配合 flag `--commit`, `--reset`
- `yarn unplug [package]`, 在安裝時指定的 package 會被解壓縮並且放置在指定的資料夾中, 而不是以 archive 的方式 cache, 可以配合 glob 語法, [使用案例 1. 與環境相關的 script 無法以 zip 方式存取時](https://github.com/storybookjs/storybook/issues/13531)
- `yarn up`, 更新 (upgrade) 指定的 dependencies, 可以使用 glob 語法
- `yarn upgrade-interactive`, 需額外安裝 `interactive-tools` plugin 使用, 開啟互動式升級界面
- `yarn version apply`, 需額外安裝 `version` plugin 使用, 一次更新所有過期的版本號
- `yarn version check`, 需額外安裝 `version` plugin 使用, 需要配合 `git`, 檢查相關的 packages 是否需要更新版本號
- `yarn version [strategy]`, 需額外安裝 `version` plugin 使用, 配合關鍵字 (`major`, `minor`, `patch`, ...) 更新版本號
- `yarn why [package]`, 列出指定 package 為什麼被加入 dependency
- `yarn workspace [workspaceName] [commandName]`, 在指定的 workspace 中執行指定的 yarn 指令
- `yarn workspace focus`, 需額外安裝 `workspace-tools` plugin 使用, 安裝指定 workspace 的 dependencies
- `yarn workspace foreach [commandName]`, 需額外安裝 `workspace-tools` plugin 使用, 讓所有的 workspace 都執行指定的 yarn 指令, 使用 flag 去控制順序, 與例外
- `yarn workspace list`, 列出所有 project 中的 workspaces

---

### 第四章 - Configuration

- 設定值說明

Manifests `package.json`

Yarnrc files `.yarnrc.yml`
