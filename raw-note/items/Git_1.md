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

---

### 第四章 - Developing with Git

---

### 第五章 - Sharing development with others

---

### 第六章 - Rewriting history and maintaining patch series

---

### 第七章 - Advanced branch management

---

### 第八章 - Git concepts

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
