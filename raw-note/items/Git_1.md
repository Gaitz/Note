## Git official documentation

### [User manual](https://git-scm.com/docs/user-manual), [Git documentation](https://git-scm.com/doc), ComputerScience/Git

---

User Manual

第一章 - Introduction

第二章 - Repositories and Branches

第三章 - Exploring Git History

第四章 - Developing with Git

第五章 - Sharing development with others

第六章 - Rewriting history and maintaining patch series

第七章 - Advanced branch management

第八章 - Git concepts

第九章 - Submodules

第十章 - Low-level Git operations

第十一章 - Hacking Git

第十二章 - Git Glossary

第十三章 - Git Quick Reference

Reference

第十四章 - Setup and Config

第十五章 - Getting and Creating Projects

第十六章 - Basic Snapshotting

第十七章 - Branching and Merging

第十八章 - Sharing and Updating Projects

第十九章 - Inspection and Comparison

第二十章 - Patching

第二一章 - Debugging

第二二章 - Guides

第二三章 - Email

第二四章 - External Systems

第二五章 - Administration

第二六章 - Server Admin

第二七章 - Plumbing Commands

---

User Manual

---

### 第一章 - Introduction

- Git 是一個快速的分散式的修改控制系統
- 可以從 `man` 或 `git help` 取得指令文件

---

### 第二章 - Repositories and Branches

How to get a Git repository

- `git clone` 複製 project 到本地端
- working tree
- `.git` 儲存所有版本資訊

How to check out a different version of a project

- Git 是一個用來儲存檔案歷史的工具, 藉由壓縮過後的檔案內容差異的 snapshot
- 在 Git 裡版本被稱作是 **commit**
- Snapshots 並不是單純一直線從舊到新的歷史紀錄, 而是可以平行數條歷史的開發紀錄, 被稱作 **branch**
- 藉由追蹤 **heads** 清單來實現 branch
- `git branch` 指令可以取得所有的 branch heads
- 大多數專案還會使用 **tags** 是類似 heads 的 reference 指向特定的歷史紀錄
- `git tag` 指令可以取得 tags 資訊
- `git switch -c <new-branch> [<start-point>]` 指令可以建立新的 branch
- `git reset --hard [<commit>]` 回復到同一個 branch 中指定的歷史紀錄 (commit) 並且之後的消除歷史紀錄, 須小心使用

Understanding History: Commits

- `git show` 可以查看當前最新的 commit 所有的資訊
- 每個 commit 都會有一個 40 位元的 16 進制作為 id, 又被稱為 object name 或 SHA-1 id, 最重要的是這個 id 是全域唯一 (globally unique)

Understanding History: History diagrams

- Git history 通常可以用圖來呈現

Understanding History: What is a branch?

- branch 代表開發過程中的一條線, 同時使用 branch head 來表示指向該 branch 最新的 commit

Manipulating branches

- `git branch`, 印出所有的 branches
- `git branch <branch>`, 以當前 branch 作為起點建立新的 branch
- `git branch <branch> <start-point>`, 建立新的 branch 並且指定起點
- `git branch -d <branch>`, 刪除指定的 branch, 如果該 branch 沒有被合併或包含在當前 branch 中則會刪除失敗
- `git branch -D <branch>`, 強制刪除指定的 branch
- `git switch <branch>`, 切換到指定的 branch 意味著更新 working directory 來反映該 branch 的歷史資訊
- `git switch -c <new> <start-point>`, 以指定的起點建立 branch 並且轉移過去查看
- `.git/HEAD` 檔案儲存目前 branch 的 ref

Examining an old version without creating a new branch

- 藉由 `git switch --detach [<start-point>]` 來建立一個暫時性的 working directory, 此時 `.git/HEAD` 指向的不是一個 branch 而是一個 commit id

Examining branches from a remote repository

- `git branch -r` 可以取查看 remote-tracking branches
  - 預設的名稱 `origin` 代表的就是 remote, 指向 `git clone` 的來源
- 通常所有的 remote tracking branches 不會顯示在 `git branch` 中
- 可以藉由 `git fetch` 來取得最新的 remote 資訊, 並且以 `git pull`, `git push` 與 remote 互動
- 通過 `git switch -c` 以指定的 remote tracking branch 建立新的 branch

Naming branches, tags, and other references

- Branches, remote-tracking branches, tags 都是 commits 的 reference
  - 都是一個以 `refs` 開頭的路徑, 分別對應 `refs/heads`, `refs/remote`, `refs/tags`, 儲存在 `.git/refs/` 之下

Updating a repository with git fetch

- `git fetch` 用來更新所有的 remote tracking branches 並且不影響任何本地的 branches

Fetching branches from other repositories

- `git remote add <name> <URL>` 新增另一個 remote 的位置
- 以 `git fetch [<repository>]` 指定想要 fetch 的 remote repository
- `.git/config` 中儲存相關的 remote 資訊

---

### 第三章 - Exploring Git History

- Git 儲存歷史紀錄, 藉由儲存壓縮過的 snapshots,
  - commit 表達每個 snapshots 之間的關係

How to use bisect to find a regression

- 使用 `git bisect` 暴力二元 s 搜尋 commit, debug 尋找出錯的 commit
  - `git bisect` 會建立在 detached commit 上, 而不是新建一個 branch
  - `git bisect start`, `git bisect good`, `git bisect bad`, `git bisect reset`

Naming commits

- 40-hexdigit object name
- branch name
- tag name
- **HEAD**
- `^`, `~` 指向往回的 commit
- `git fetch` 的 **FETCH_HEAD**
- `git rev-parse` 底層工具, 可以用來協助轉譯以上任何型別的 commit 名稱到他的 object name

Creating tags

- 使用 tag 標記任何的 commit 並且命名和留下訊息
- `git tag <tagname> [commit]`

Browsing revisions

- `git log` 印出 commits 清單
  - 可以以參數的形式指定搜尋的區間, 時間, 特定的檔案, 資料夾, 字串
  - `git log -p` 顯示出 commit 差異

Generating diffs

- 使用 `git diff` 生成不同版本的差異
- 使用 `git format-patch` 生成版本差異的檔案

Viewing old file versions

- Ex. `git show v2.5:fs/locks.c` 查看特定版本的特定檔案

Examples:

- 計算一個 branch 上的 commit 數量
  - `git log --pretty=oneline origin..mybranch | wc -l`
  - `git rev-list origin..mybranch | wc -l`
- 檢查兩個 branch 是否是一樣的內容
  - `git diff origin..master`, 比較檔案內容
  - `git rev-list origin`, `git rev-list master`, 比較 commit hash
  - `git log origin...master`
- 尋找包含特定 commit 的第一個 tag
  - `gitk`, `git name-rev --tags`, `git describe`, `git merge-base`
- 尋找只存在單一 branch 上的 commits
  - `git show-ref --heads`
  - ...
- 建立 release 的 changelog
  - `git archive`
- 尋找包含指定檔案和內容的 commit
  - `git log`, `git diff tree`, `git hash object`

---

### 第四章 - Developing with Git

Telling Git your name

- `git config`
  - `git config --global user.name`, `git config --global user.email`
- config 被存放在 `.gitconfig` 中

Creating a new repository

- 建立資料夾並且在資料夾目錄下, `git init`

How to make a commit

- 三個步驟,
  - 在 working directory 下進行一些改變
  - 告知 Git 你做的改變
  - 依據 2, 建立一個 commit 包含這些改變
- `git diff --cached`, 可以查看目前 git 追蹤到與 HEAD 的差異
- `git add`, 讓修改的內容被 git index
- `git rm`, 從 git index 中移除
- `git diff`, 取得 working tree 與 index file 的差異
- `git commit`, 進行 commit
- `git show`, 查看當前 commit 狀態, 可以檢查是否符合預期
- `git commit -a`, 自動 index (`git add`) 同時 `commit`

Creating good commit messages

- 撰寫良好的 commit message, 第一行用小於 50 字元的內容作為 title (summary), 空白一行後的內容作為 description

Ignoring files

- 在 `.gitignore` 檔案中增加不想被 git 所記錄的檔案路徑或檔案名稱

How to merge

- `git merge [branch name]`, 把指定的分支合併到當前分支
- 必須要在當前分支沒有任何尚未 commit 的改變時才能進行
  - 因此必須先 `git commit` 現有的變動或者 `git stash` 把變動儲存在暫存空間
- git 首先會自動合併改變, 如果遇到修改 conflicts 則會告知需要手動處理這些差異

Resolving a merge

- 遇到 conflicts 時
- `git commit` 可以查看需要解決 conflicts 的檔案
- `git status` 可以查看 conflicts
- 當手動解決完 conflicts 後, 需要依照之前的流程 `git add`, `git commit` 把這次修改變成一個 commit
- 可以使用 `git diff` 與 `git show` 查看差異之處協助你解決 conflicts
  - `git show :1:`, `git show :2:`, `git show :3:`
  - `git diff -1`, `git diff --base`, `git diff -2`, `git diff --ours`, `git diff -3`, `git diff --theirs`
- `git log --merge`, `gitk --merge`, `git mergetool` 協助你進行修改 conflicts

Undoing a merge

- 放棄解決這次的 merge conflicts
- `git merge --abort`

Fast-forward merges

- 如果是直接的父代與子代的關係, 則會使用 **fast-forward** 以移動 HEAD 的 ref 取代建立一個新的 merge commit.
- 讓結果更直觀簡潔

Fixing mistakes

- `git restore --staged --worktree :/`
- 以新 commit 來修復錯誤
  - `git revert HEAD`, 以新 commit 的方式取消前一次 commit 的改變
- 以修改歷史的方式修復錯誤
  - `git reset`
  - `git commit --amend`
- 查看舊版的檔案內容
  - `git restore --source=HEAD^ path/to/file`, 調整 working directory 到舊檔案
  - `git show HEAD^:path/to/file`, 僅僅查看舊檔案
- 暫存現在進行中的內容
  - `git stash push -m "message"`, 暫存
  - `git stash pop`, 取出暫存

Ensuring good performance

- 多數指令會自動進行 `git gc`, 但是也可以明確的主動使用

Ensuring reliability

- `git fsck` 以 git object 為單位進行檢查和取得
  - `dangling` 檔案會在 `gc` 後移除
- 回復遺失的改變內容
  - `git reflog` 取得 git 暫存的操作歷史紀錄, `reflog` 儲存的操作記錄只存在於 local 端並不會被同步
  - 在 `reflog` 紀錄也不存在的時候, 並且在還沒 `gc` 之前, 仍然可以通過 `git fsck` 找回舊的檔案歷史

---

### 第五章 - Sharing development with others

Getting updates with git pull

- 使用 `git pull` 取代 `git fetch` + `git merge` 來更新到 remote 的最新版
  - `git pull` 也可以指定合併特定的 remote branch, `git pull . branch`, `.` 代表 remote

Submitting patches to a project

- `git format-patch` 製作更新檔, 可以使用 email 交換更新檔給其他用戶

Importing patches to a project

- `git am`, (am, apply mailbox), 使用更新檔
  - 更新時也有可能會遇到 conflict, 如同 merge 一樣進行 conflict 處理

Public Git repositories

- 存在一個對應的 public git repository, 供其他開發者使用 (git pull)
- Setting up a public repository
  - 建立一個 public 版本的 clone, `git clone --bare`
- Exporting a Git repository via the Git protocol (推薦的)
  - 使用 Git 協定進行檔案傳輸, `git://`
  - 使用 `git daemon` 建立 public git server
- Exporting a git repository via HTTP
  - 直接使用 HTTP server 作為接口取得對應資料夾
  - 使用 `git --bare update-server-info` 建立更多資訊
  - 其他使用者可以通過 `git clone` 指定的 http 位置
  - 更詳細的設定方式可以參考 [setup-git-server-over-http](https://github.com/git/git/blob/master/Documentation/howto/setup-git-server-over-http.txt)
- Pushing changes to a public repository
  - 通過 ssh 直接 `git push` 到 public repository
  - `git config`, `receive.denyCurrentBranch` option
- What to do when a push fails
  - 在 `git push` 無法 fast-forward 時, 會需要處理
  - 或者使用 force push `git push -f` 會直接修改掉線上版本 (修改歷史)
  - 最好在每次進行 `git push` 前先更新到最新版
- Setting up a shared repository
  - 使用 `gitcvs-migration`, `git cvsimport *`
  - 中央管理式的管理, 但是不是推薦的方案
- Allowing web browsing of a repository
  - 啟用 web 瀏覽 git repository 的功能
  - 使用 `git instaweb` 和參考 `gitweb`
- How to get a Git repository with minimal history
  - shallow clone 使用 `git clone --depth` 指定 clone 的範圍
  - 取代取得所有的歷史紀錄
  - 可在之後使用 `--unshallow` 再次取得完整的歷史紀錄

Examples

- Maintaining topic branches for a linux subsystem maintainer
  - 範例, 使用 Git 來維護 IA64 架構的 linux kernel
  - Tips:
  - 在 git config 中設定 remote 一次 push 多個目標 branch
  - 利用 `git log` 和 `git shortlog` 來檢視 branch 間的差異
  - `git request-pull`

---

### 第六章 - Rewriting history and maintaining patch series

- Git 預設 commit 被建立後是不會被移除或取代的, 預設不會修改歷史
- 但是仍有一些使用案例, 建立在修改歷史上

Creating the perfect patch series

- 建立有意義的 commit 序列
  - 每個 commit 保持一定的順序
  - 每個 commit 只包含單一概念的改變, 並且具有說明性的 commit message
  - 所有的 commit 都應該是可以 build 過並且運行過測試的
- Keeping a patch series up to date using git rebase
  - 利用 `rebase` 調整 commit 建立有意義的序列
  - 在 upstream 有新更新時, 避免 merge commit 產生可以先使用 `rebase` 修改歷史建立線性的 commit
- Rewriting a single commit
  - `git commit --amend` 調整最後一筆 commit
  - 如果需要調整更多筆 commit 應該使用 `rebase -i` 互動模式去調整
- Reordering or selecting from a patch series
  - 調整多筆 commit 的順序
  - 使用 `git format-patch` 和 `git am *.patch`
- Using interactive rebases
  - 使用 rebase 互動模式調整多筆 commits, `rebase -i`

Problems with rewriting history

- 對於修改歷史, 最麻煩的問題在於其他使用者已經使用了舊的 commits, 對於 git 來說會產生多份內容, 而不是以新的取代所有舊的內容
- 因此最好的辦法是不要修改可能會被其他人使用到的 commits, 僅僅修改自己還在進行中的 commits
- 已經公開的 commits 應該不再被更改

Why bisecting merge commits can be harder than bisecting linear history

- 每次利用 merge 產生時, git 都會分別記憶分支, 但是在使用 `git bisect` 搜尋時, 每次的 merge 分支都必須個別處理, 沒辦法一次性地搜索
- 因此, 應該盡可能地讓 git history 是線性的, 善用 `rebase` 取代 `merge`

---

### 第七章 - Advanced branch management

Fetching individual branches

- 只 fetch 單一 branch 並且在 local rename
- `git fetch origin todo:my-todo-work`, fetch from origin
- `git fetch git://example.com/proj.git master:example-master`, fetch from git protocal

git fetch and fast-forwards

Forcing git fetch to do non-fast-forward updates

- 強制清除 conflict commit 直接更新最新版
- `git fetch -f origin`
- 要小心這種方式會讓一些 commit 直接消失

Configuring remote-tracking branches

- `git config -l` 查看所有設定檔案
- 使用 `git remote add` 註冊其他 remote 的位置並且命名

---

### 第八章 - Git concepts

The Object Database

- 所有的 commit 都會以 40-digit 作為 object name 儲存
- 這些名稱是由 SHA-1 hash 而來的
- 通過 hash 的方式對於 git 有很多好處
  - 可以快速地比較兩個 object
  - 由於使用相同的 hash 演算法, 因此在任何地方相同的內容可以取得相同的名稱
  - 也因此 git 可以偵測檔案內容是否錯誤
- Git 有四種不同類型的 object
  - `blob`, 儲存檔案資料
  - `tree`, 包含多個 blob 形成檔案資料架構
  - `commit`, 以 directed acyclic graph 儲存, 檔案修改的歷史順序, 每個 commit 會包含指向 parent 的資訊
  - `tag`, 象徵性的指向其他的 object 作為命名的捷徑
- Commit object
  - 連結到檔案結構形成的樹狀結構實際的節點上, 描述那些節點是從何而來
  - 使用 `--pretty=raw` 在 `git log` 或 `git show` 指令上可以查看 commit 詳細的訊息
  - 包含以下資訊
  - `tree`, 該 tree object 的 SHA-1
  - `parents`, 該父層 commit 的 SHA-1
  - `author`, 造成檔案改變的人
  - `committer`, 實際進行 commit 的人
  - `comment`, 註解描述
  - commit object 本身不儲存檔案的改變
- Tree object
  - 使用 `git show` 或 `git ls-tree` 可以查看 tree object 的細節訊息
  - 儲存檔案相關的 SHA-1 names
- Blob Objects
  - 使用 `git show` 查看 blob object 的細節
  - 單純的檔案 binary
  - 檔案的 renaming 並不會影響 blob object
- Trust
  - 可以安心地對待其他來源的 blob object 因為 SHA-1 保證了資料的正確性
- Tag object
  - 可以使用 `git cat-file tag` 查看 tag 細節
  - 包含一個 object, 註明 object type, tag 名稱, tagger, 有時候會包含一個 signature
  - 可以使用 `git tag` 建立 tag object, 並且 `git tag` 也可以建立單純只是 reference 而沒有 tag object 的輕量化 tag
- How Git stores objects efficiently: pack files
  - `git count-objects` 取得整個專案裡的 loose objects (未打包的) 數量和大小
  - 可以通過 git pack 來壓縮檔案大小
  - 通常來說 git gc 會自動進行清除 loose objects 的工作
  - 也可以手動通過 `git repack` + `git prune` 進行
- Dangling objects
  - `git fsck` 查看, git 處理中的檔案, ( 候選清除但尚未清除的 )
  - 像是進行 `git rebase` 後的舊的節點們, 或 `git add` 並且修改過的過期檔案
  - 換句話說, dangling objects 在 git gc 之前仍然是可以找回來的檔案內容
  - `gitk <dangling-commit-sha-goes-here> --not --all`
  - `git branch recovered-branch <dangling-commit-sha-goes-here>`
  - `git show <dangling-blob/tree-sha-goes-here>`
  - 當你確定 dangling objects 不會在被使用, 可以通過手動觸發 `git prune` 進行清除
- Recovering from repository corruption
  - 儘管 git 本身不容易出錯, 但是檔案系統仍然可能因為 OS 層或 hardward 層的錯誤而毀損
  - 最好的保護還是備份
  - 範例示範, 修復遺失 blob object 的情形
  - 使用 `git fsck --full --no-dangling` 掃描調查遺失或錯誤的 blob object
  - 如果有其他的備份, 可以直接把遺失的 blob 放到對應的 git folder 底下即可
  - 如果無法可以通過, `git ls-tree`, 查詢遺失的檔案名稱
  - 如果可以找到遺失的檔案, 可以利用 `git hash-object -w somedirectory/myfile` 去建立 blob object 並且檢視是否是我們需要的
  - 如果不是正確的版本, 導致生成出來的 SHA-1 與遺失的 blob object 不合時, 使用 `git log --raw --all --full-history -- somedirectory/myfile` 去察看檔案版本紀錄, 嘗試修復

The index

- Index 是單純的 binary file, 通常存放在 `.git/index` 目錄下
- 內容是一個依據檔案路應排序過後的 blob objects SHA-1 names
- 可以通過 `git ls-files --stage` 查看 index 細節
- Index 包含所有建立一個 tree object 所需的資訊
  - 在 `git commit` 的時候就是通過使用 index 的資訊, 建立當前的 tree object 儲存在 git object database 裡
- Index 包含一些資訊可以用來快速比較 working tree 跟現存的 tree object 之間是否有改變
- Index 資訊也用來偵測 merge conflict 的位置
- 簡單來說 index 就是當前暫存的狀態, 並且這些狀態能夠建立一個當前暫存的 tree object 來給 git 進行工作

---

### 第九章 - Submodules

- Git submodules 可以讓一個 git 專案下有其他獨立的 subdirectory, 換句話說, 可以讓外部的 git 專案帶著完整的 git history 整合進來
- `git submodule` 是在 Git 1.5.3 以後推出的
- 在 supermodule 上可以使用 `git submodule add <repo> <path>` 去加入 submodules
- 通過 `git submodule status` 查看狀態
- `git submodule init`
- `git submodule update`
- `git submodule update` 跟 `git submodule add` 的差別在於 `git submodule update` 可以查看特殊的 commit 時間點並且建立 detached branch, 來工作
  - 在 submodule 下更改內容需要從 detached branch 建立一個 branch 來儲存改變
  - 並且使用 git commit 和 git push 實現更新 submodule
  - git supermodule 則是通過 `git pull` 和 `git submodule update` 進行更新

Pitfalls with submodules

- submodule 必須優先於 supermodule 更新, 並且必須要 `git push` 進行發布, 如果沒有發佈的話, supermodule 在更新時會報錯
- Git 1.7.0 之後在 supermodule 中使用 `git status` 和 `git diff` 都會有 submodules 的狀態, 來提示應該先在 submodule 進行 commit 和更新
- 如果在 submodule 進行改並且 commit 並且沒有在 submodule 進行生成新的 branch 時, 在 supermodule 中使用 `git submodule update` 的話, 這些在 submodule 下新 commit 變動會遺失. **必須小心**, 這些遺失的改變仍然可以在 submodule 下使用 reflog 找回
- 如果在 submodule 下變動並且尚未 commit 時, 在 supermodule 下 `git submodule update` 時, 如同平常一樣會提供錯誤訊息, 提示有變動尚未 commit

---

### 第十章 - Low-level Git operations

- 大多數的 git 高階指令都是 low level git operations 的打包 script

Object access and manipulation

- `git cat-file`, 可以查看 git 任何型別的 object 的資訊
- `git show`, 則是看高抽象層的東西
- `git commit-tree`, 可以手動建立 commit object 在任何指定的 parent 和 trees 上
- `git write-tree`, 可以手動建立 tree object
- `git ls-tree`, 可以查看 tree object 的內容
- `git diff-tree`, 比較兩個 tree object 的內容
- `git mktag`, 手動建立 tag object
- `git verify-tag`, 檢查 tag object 的簽名
- `git tag`, 提供高階的通用指令, 來處理 tag 相關的工作, 包含建立, 刪除, 驗證

The Workflow

- 高階的 `git commit` 與 `git restore` 處理資料在 working tree, the index, 和 object database 之間的轉換
- 細部的工作皆有專用的指令可以執行
- working directory 到 index
  - 這個行為的高階指令是 `git add`, 也是高階的封裝 `git update-index` 指令
  - `git update-index`, 以 working directory 的資訊更新到 index
  - 該指令預設不處理 new files 和 removed files, 換句話說他只處理更新現有的 cache, 要處理額外的資訊需要主動提供 `--add` 或 `--remove`
- index 到 object database
  - `git write-tree`, 把 index 資訊建立成 tree object
- object database 到 index
  - `git read-tree <SHA-1 of tree>`, 讀取 tree object 建立成 index 並且取代當前的 index
- index 到 working directory
  - 通常會直接改變 index 上面的檔案, 而不需要刻意的把 index 切換到 working directory
  - `git checkout-index filename` 用來把 index 特定的檔案切換到 working directory, 或者使用 `-a` option 切換全部

Examining the data

- 查看 objects 資料
- `git cat-file -t <objectname>`
- `git cat-file blob|tree|commit|tag <objectname>`
- `git ls-tree`
- `git cat-file commit HEAD`

Merging multiple trees

- 常見的 Merge 是整合 2 個 tree objects 並且建立一個 commit 去達成 (two parents)
- 然而, git 也允許實現更多個 tree objects (branches) 的 merge
- `git merge-base <commit1> <commit2>`, 去尋找兩個 commit 最近的 shared parent, 作為之後的 merge base
  - 查看該 commit 的資訊 `git cat-file commit <commitname> | head -1`
- 執行 3 個 tree objects 的 merge 並且建立在 index 上, `git read-tree -m -u <origtree> <yourtree> <targettree>`
  - 配合 `git write-tree`, 把 merge 後的 index 建立成新的 tree object 儲存起來
- 當 merge 的 tree objects 出現 merge clashes 該處理時
  - `git ls-files --unmerged` 查看是哪些檔案需要處理
  - 查詢到檔案後需要手動進行處理, 使用 `git cat-file blob` 建立各個檔案的 blob objects
  - 使用像是 `diff3` 或 `merge` commands, `git merge-file`
  - 執行 `git update-index` 更新到 index 確認 resolved
  - 通常不會使用 `git cat-file blob` 處理這樣的問題
  - 而是使用 `git merge-index` 達成整合三個版本的檔案成單一個

---

### 第十一章 - Hacking Git

- Git 開發者需要知道的 Git 實作細節

Object storage format

- git object types, `blob`, `tree`, `commit`, `tag`
- 所有的 object 都使用 zlib, 進行檔案壓縮, 並且擁有 header 提供 type 和 size 資訊
- object name 則是 SHA-1 該 object 的內容
- 除了驗證 SHA-1 之外, 也可以使用 `git fsck` 去檢驗 object 在 database 的情況

A birds-eye view of Git’s source code

- 從 initial commit 來學習 `git switch --detach e83c5163`
  - 常用的名稱在這個版本後改變
  - changeset -> commit
  - cache -> index
- step 1. 先查看 `read-cache-ll.h`, `object.h`, `commit.h`
  - 關於 index, object, commit
- step 2. 查看 `sha1_name.c`, 關於 object name
- 學習 `git log`, 來理解 the revision walker, `git rev-list`
  - 初始版本的 git log, 只是一個 script, `git-rev-list --pretty $(git-rev-parse --default HEAD "$@") | \LESS=-S ${PAGER:-less}`
  - 後來使用 buildin 版本的 `git log`, 實作在 `builtin/log.c`
- step 3. 在理解 git 基本概念後, 應該就是研讀程式碼
  - 可以來自一些自己感興趣的問題來追蹤程式碼, 像是我如何僅僅透過 object name 來查詢 blob object 的內容
  - 起點可能是 `git show` 或 `git cat-file` command
- Tips: 通過 `git log` 作為工具來搜尋 git source code 來查詢想看的內容

---

### 第十二章 - Git Glossary

名詞解釋

- alternate object database
- bare repository
- blob object
- branch
- cache
- chain
- changeset
- checkout
- cherry-picking
- clean
- commit
- commit graph concept, representations and usage
- commit-graph file
- commit object
- commit-ish (also committish)
- core Git
- DAG
- dangling object
- dereference
- detached HEAD
- directory
- dirty
- evil merge
- fast-forward
- fetch
- file system
- Git archive
- gitfile
- grafts
- hash
- head
- HEAD
- head ref
- hook
- index
- index entry
- master
- merge
- object
- object database
- object identifier (oid)
- object name
- object type
- octopus
- origin
- overlay
- pack
- pack index
- pathspec
- top
- literal
- icase
- glob
- attr
- exclude
- parent
- peel
- pickaxe
- plumbing
- porcelain
- per-worktree ref
- pseudoref
- pull
- push
- reachable
- reachability bitmaps
- rebase
- ref
- reflog
- refspec
- remote repository
- remote-tracking branch
- repository
- resolve
- revision
- rewind
- SCM
- SHA-1
- shallow clone
- shallow repository
- stash entry
- submodule
- superproject
- symref
- tag
- tag object
- topic branch
- tree
- tree object
- tree-ish (also treeish)
- unmerged index
- unreachable object
- upstream branch
- working tree
- worktree

---

### 第十三章 - Git Quick Reference

---

Reference

---

### 第十四章 - Setup and Config

---

### 第十五章 - Getting and Creating Projects

---

### 第十六章 - Basic Snapshotting

---

### 第十七章 - Branching and Merging

---

### 第十八章 - Sharing and Updating Projects

---

### 第十九章 - Inspection and Comparison

---

### 第二十章 - Patching

---

### 第二一章 - Debugging

---

### 第二二章 - Guides

---

### 第二三章 - Email

---

### 第二四章 - External Systems

---

### 第二五章 - Administration

---

### 第二六章 - Server Admin

---

### 第二七章 - Plumbing Commands
