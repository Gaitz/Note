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
  - `commit`
  - `tag`

The index

---

### 第九章 - Submodules

---

### 第十章 - Low-level Git operations

---

### 第十一章 - Hacking Git

---

### 第十二章 - Git Glossary

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
