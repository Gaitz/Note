
Working Part GitHub
==

PURPOSE: 熟悉 GitHub 版本控制指令與 opensource 探索
--

## NEXT: Git 

[toc]

*******************************************

可以把玩的檢查清單
==

GitHub

* Branch # 新 idea 時開分支

* Commit # commit a unit of changes

* Pull Request # 開啟討論吧

* Merge # 完成工作合併分支

* GitHub Pages # 個人網頁

* Fork # 參與其他 repository

* Pull Request 至其他人的 repository

* Issues # 討論與追蹤 合作時超好用

* github style Markdown language # github 文件多數可以使用 Markdown 語法並且 github 還有其他擴充語法

* Documents: README, Wikis # 文件系統

Git

* 

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#非完整地圖的簡易入門

https://www.ithome.com.tw/news/95283
simple introduction

功能
wiki # 文件管理
issue # 議題追蹤

動作
fork # 複製別人的 repository
clone # 所有版本的 repository 下載至本地端
pull # 只下載最新版本的 repository 至本地端
commit # 在本地端提交一個新版本
push # 將本地端 repository 傳至網路端
pull request # 要求其他開發者整合，我方的 repository。

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 學習主軸 1. [GitHub official guides](https://guides.github.com/)

學習 GitHub 網站功能

## Understanding the GitHub Flow

* Branch
 Master 與分支，Master 必須是完整可部屬的，
 利用開分支來規劃工作流程，開發新功能、測試等等，都利用分支安全的實作。
 分支的名稱要有足夠的描述，讓共同工作者可以清楚的了解。
 **分支名稱非常重要！**
 
* Commit
 在實作與修改後 commit，每個 commit 都是一個改變單位，紀錄工作的進行，並且設置回復點。描述需要清楚的紀錄下修改與原因。
 從 commit 樹中可以看到進展與執行方向。
 **描述的訊息非常重要！**

* Pull Request
 配合 fork 與 Pull Request 與他人的 repository 共同開發。
 自己的 repository 也可以使用 Pull Request 來執行 merge 前的 code review 與討論。
 Pull Request 的重要目的在於**開啟討論**，討論後仍舊可以持續的 push commit 。
 Pull Request 的描述是使用 Markdown 因此可以更詳盡的描述並且包含圖片等等。
 
* Deploy
 確認這次 branch 的運作良好。
 
* Merge
 確保分支與 Master 運作良好後，把分支合併回 Master。
 Pull Request 保留開發的紀錄。
 
## Hello World

* Create a Repository
* Create a Branch
開個 branch 來工作
* Make and commit changes
 Commit 任何修改單位作為紀錄
* Open a Pull Request
 利用 Pull Request 開啟討論，與版本比較。
* Merge your Pull Request
 Merge Pull Request 至 Master 
 並且完成 Pull Request 和
 關閉 Branch。
 
Messages 可以使用 [emoji] 和 拖拉很多類型的檔案與圖片當成文件的一部分。

[emoji]:(https://www.webpagefx.com/tools/emoji-cheat-sheet/) "emoji-cheat-sheet"

## Getting Started with GitHub Pages

 github 提供的個人網頁
 開一個 repository 並且命名為 *username*.github.io
 github 使用  **Jekyll** 建置

## Getting your project on GitHub

* github desktop
 only for Windows & Mac

## Forking Projects
參與其他人的 repository 。

* Fork
 複製一份其他人的 repository 到自己的 github 中。
 
* Clone
 把 repository 下載至本地端

* Pull Request
 提出 Pull Request 至原 repository 擁有者，開啟討論並且建議對方 Merge 。


## Be Social

* Follow a Friend

* Explore Page
 https://github.com/explore
 探索最受歡迎的專案
 並且可以訂閱 newsletter

* Watch a Project
 收到專案更新的通知。

* Stargazing
 把專案加入我的最愛。


## Making Your Code Citable
 repository 作為學術研究引用時，申請 Digital Object Identifiers (DOI) 。
 
## Mastering Issues

* fork 的 repository 需要從 settings 中把 issues 打開才能使用。

* Issues
 類似於 email，作為開發的追蹤與討論。
 
* Assignees
 安排個負責人。

* Labels
 標籤, 一個 issue 可以擁有多個標籤。

* Milestones
 打包一組 Issues，可能是 feature, project, and time period 相關
 
* Notifications
 issues 也能有追蹤通知

* @Mentions
 通知指定人員或團體 @username
 副件通知
 /cc @username @organization/team
 
* References
 引用其他的 issues
 `#issue_number`
 甚至是其他 repository 的 issues
 `username/repository#issue_number`
 
## Mastering Markdown

 * github extras 
	1. @mentions 
	2. `- [x]` , `- [ ]` # checkbox, task lists
	3. emoji # 表情符號
	4.  `~~line~ ~` # 刪除線 
	5.  `username/repository#issue_number` # issues reference 
	
	6. github 內超連結！ 同個 repository 不同的資料夾亦可利用路徑連結。
	``` Examples:
	連結圖片：![image](../images/picture1.png)
	連結文件：[README](../README.md)
	```

## Documenting your projects on GitHub

README 與 Wikis 都可以使用 Markdown 撰寫。

 * README
 Best to have:
 Project Name
 Description
 Table of Contents
 Installation
 Usage
 Contributing
 Credits 
 License

 * Wikis
  每個 repository 都有一個 Wikis，
  並且也是一個 repository ，
  因此可以使用 git 在本機端實作並且 push。
  
  
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# 學習主軸 2. [git tutorial](https://git-scm.com/book/zh-tw/v1) 
free git tutorial with translations
學習 git 


* 分散式版本控制系統
* 檔案的狀態 untracked, modified, staged, committed

<br>
使用命令列學習操作 git ，可以最完整的學習 git 。
為了方便使用仍有第三方開發的 GUI 。

* 設定
linux 中 git 設定檔存在三種不同的地方，
1. 所有使用者共用 # /etc/gitconfig
2. 使用者個人 # ~/.gitconfig , ~/.config/git/config
3. 單一專案 .git/config
優先權由 3~1


 `--global` 參數為共用，單一專案設定則不需使用。
    * 個人資料：
`git config --global user.name "PHC"`
`git config --global user.email ragnarokcute@gmail.com`

    * 指定編譯器
`git config --global core.editor vim`

    * 查看設定值
`git config --list`


* 取得一個儲存庫 (repository)
    * init # 到本地端專案資料夾中，加入 git 的控制。
    * clone # 抓取其他現有的專案


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
# Open Source

* 從貢獻文件開始
 閱讀文件，並且幫忙除錯。
 同時可以藉此深度的了解。
 
* 

真實文本 
==

* hang around with hello-world repository.



* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
其他資源
==

GitHub:

* https://www.youtube.com/channel/UCP7RrmoueENv9TZts3HXXtw
github training youtube

* https://help.github.com/
official help page

* https://services.github.com/on-demand/
official guides

Open Source:

* https://opensource.guide/how-to-contribute/
contribute to open source
a guide to open source world

* https://github.com/explore
GitHub open-source explore page

Questions
==

* GitHub 與 Git 的差別與關係？
 Ans: 
 GitHub 是一個提供 Git 託管服務的網站。
 Git 一個分散式版本控制工具。
https://zh.wikipedia.org/wiki/Git
https://zh.wikipedia.org/zh-tw/GitHub
 
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE3OTIxMzA5NDddfQ==
-->