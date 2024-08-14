## 循序漸進 Linux 第 2 版

### 循序漸進 Linux 第 2 版 - 高俊峰, ComputerScience/Linux

---

基礎知識篇

第一章 - 學習 Linux 的經驗與技巧

第二章 - Linux 系統的安裝與基礎配置

第三章 - Linux 系統基本結構

第四章 - Linux 常用命令及使用技巧

第五章 - Linux 下軟件的安裝與管理

伺服器搭建篇

第六章 - Linux 伺服器網路配置

第七章 - 架設 Linux 服務器

第八章 - 構建高性能的 MySQL 資料庫

第九章 - Linux 伺服器安全策略

第十章 - Linux 故障排查思路與案例

系統管理篇

第十一章 - Linux 用戶權限管理

第十二章 - Linux 磁盤儲存管理

第十三章 - Linux 文件系統管理

第十四章 - Linux 內存管理

第十五章 - Linux 系統進程管理

性能調優篇

第十六章 - Linux 系統優化思路

第十七章 - Linux 系統性能評估與優化案例

虛擬化與集群應用篇

第十八章 - 虛擬化雲計算平台

第十九章 - 高性能集群軟件 Keepalived

第二十章 - 負載均衡集群 LVS 與 HAProxy

---

基礎知識篇

---

### 第一章 - 學習 Linux 的經驗與技巧

1 Linux 在各領域發展

- Linux 與開源軟體
- Linux 在伺服器領域
- Linux 在桌面領域
- Linux 在移動裝置, 嵌入式領域
- Linux 在雲端計算

2 選擇適合自己的 Linux 發行版

- 常見發行版
  - Red Hat Linux
  - Fedora Core
  - Red Hat Enterprise Linux
  - CentOS
  - SuSE Linux
  - Ubuntu Linux
- 初學者入門 CentOS
  - 使用者多, 資源多, 容易取得, 應用廣泛
- 桌面平台首選 Ubuntu Linux
- 企業應用首選 RHEL/CentOS

  - 付費的 Red Hat 商用版
  - 免費的 CentOS

3 養成良好的 Linux 操作習慣

- 拋開 Windows 的思考方式
- 習慣使用命令列 (command line)
- 理論結合實踐
  - 勤於動手, 實際操作
- 學會使用 Linux 內建文件
  - `man`, 使用說明, FAQ, ...
- 學會獨立思考, 獨立解決問題
- 學習專業英文
  - 查看英文文件
- Linux 學習路線圖
  - 初級階段
    - 了解 Linux 多種安裝方式
    - 掌握常見指令
    - 掌握軟體安裝方法 (from source code / from package managerment)
    - 掌握系統結構及運行原理
    - 掌握 vi, shell, pipeline, I/O redirect, input/output 等基本的 shell programming
    - 網路基本設定
  - 中級階段
    - 熟練搭建常見伺服器軟體
    - 熟悉網路安全與伺服器安全策略 (iptables / Selinux)
    - 掌握儲存系統管理, 使用者權限管理, 記憶體管理, 文件系統管理, 進程管理
    - 掌握系統故障排查方法與熟悉系統優化策略
  - 高級階段
    - 掌握一個 Linux 常用程式語言 (Shell / Python / Perl / PHP)
    - 熟練 Linux 下多種 cluster architecture (LVS / HAProxy / Keepalived / Heartbeat)
    - 熟悉並能閱讀 kernel source code 與客製化 kernel

4 使用虛擬機學習 Linux

- Virtual Machine
- 好處
  - 節省成本
  - 安全便捷
  - 簡單高效
- 虛擬機運行環境和硬體需求
  - 虛擬機軟體 VMware, VirtualBox
  - HostOS, GuestOS
  - 硬體需求
- 虛擬機的安裝與使用

5 Linux 學習資源

- 網路資源, 搜尋引擎, 論壇
- 有本書在身邊
  - 書籍能更有系統性, 循序漸進的學習

---

### 第二章 - Linux 系統的安裝與基礎配置

1 安裝需求

- 依據不同的發行版, 提供不同的硬體配置要求

2 安裝方式

- 硬碟安裝
- USB 安裝
- 網路安裝
  - 工具: Kickstart
- 光碟安裝
- 從網路下載 Linux 發行版 ISO 格式
  - 燒錄成光碟或 USB 進行安裝

3 光碟安裝過程

- 分區命名方案 (partition)
  - Linux 中所有東西都是文件
  - 因此, 硬碟命名也是以文件的方式存在
    - 例如: `/dev/hda1`, `/dev/sdb2`
    - `/dev` 所有設備的存放目錄
    - `hd` 代表 IDE 硬碟, `sd` 代表 SCSI 硬碟
    - 英文字母代表, 哪一個設備 (實體)
    - 數字代表 partition 分區
- 雙系統 Windows + linux 的硬碟分區方案
  - 因為, Windows 與 linux 所使用的文件系統並不相容
  - 因此必須是各自獨立的 partition
  - 推薦先安裝 Windows 再安裝 Linux
- 對於運行服務的 Linux 伺服器, 安裝的內容最好越少越好
  - 只安裝需要用到的, 提昇系統效能與保障系統安全
- Linux 分區
  - `/` 必須的根分區
  - `swap` 必須的 swap 分區
  - 推薦獨立分配的分區
    - `/boot`, 系統引導訊息與 kernel 等資訊
    - `/usr`, 系統應用軟體安裝資訊
    - `/var`, 系統日誌
- 分配方案
  - Standard Partition,
  - Btrfs,
  - LVM,
  - LVM Thin Provisioning
- 文件系統格式
  - xfs,
  - ext2, ext3, ext4, Linux 系統上主流的文件系統
  - VFAT, Windows 上 FAT 文件系統
  - swap, 交換分區格式
  - BIOS boot, 系統啟動設備

---

### 第三章 - Linux 系統基本結構

Linux terminal 模式與圖形界面模式

- 使用 `alt + ctrl + F1~F6` 切換至完全獨立的字元模式
  - 可以實現多用戶, 多工的模式
- 圖形界面模式只是一個應用程式

Linux 硬體資源管理

- 查看 PCI 設備, 查看例如音效卡, 顯示卡, 網路卡, ...
  - `lspci`
  - `-v` 詳細模式
- 查看 CPU 資訊
  - `more /proc/cpuinfo`
  - physical id 代表實體 CPU 的 ID
  - siblings 代表邏輯核心數
  - cpu cores 代表實體核心數
- 查看記憶體資訊
  - `more /proc/meminfo`
- 查看硬碟資訊
  - `fdisk -l`

Linux 外部設備

- 在 Linux 系統中, 所有的硬體設備都是以文件的方式存在
  - 存放在 `/dev` 下
  - `fd` 軟碟 (floppydisk),
  - `sd` SCSI 設備, USB 通常屬於這類
  - `hd` IDE 光碟機, `sr` SCSI 光碟機, 或者 `cdrom` 呈現
  - `st` SCSI 磁帶機 (tape)
- 常見檔案系統類型, 檔案系統類型就是 partition 的格式
  - `msdos`, DOS 系統
  - `vfat`, 支援長文件名稱的 DOS 系統
  - `iso9660`, 光碟格式
  - `ext2/ext3/ext4`, Linux 下常見規格
  - `xfs`, Linux 下常見高性能日誌系統規格
- 設備掛載 (mount)
  - `mount -t 文件系統類型 設備名稱 掛載位置`
  - 系統文件中的掛載位置 `/mnt` 通常用於手動掛載 (mount point), `/media` 通常用於自動掛載
  - **掛載的是軟碟, 光碟, USB, 因此切換時, 需要 unmount 和重新 mount 新的**
  - `umount 卸載位置`

檔案系統結構

- 目錄以樹狀結構呈現, hierarchical file system (HFS)
- 很多 Linux distribution 檔案系統都依據 FSSTND 標準設置
- `/` 根目錄
- `/etc` 系統級別 configurations
- `/usr` 應用程式和文件, 通常安裝的軟體會安裝在這個目錄下
- `/var` 存放系統運行及軟體運行時的 log, 暫存設定
- `/dev` 系統所有的設備
- `/proc` 所有的內容都是 memory 的 mapping, 可以通過這個目錄來跟 memory 的內容互動,
  - 像是修改系統運行中的 kernel 參數
  - 也可以查詢當前的很多運行中的訊息
- `/boot` Linux 啟動時所需的核心文件, 如果毀損會導致系統無法啟動
- `/bin`, `/sbin` 可執行的 binary 檔案, s 即 super user, 因此 `sbin` 下放的是 root 才能執行的
- `/home` 當前 user 的家目錄
- `/lib` 共享的 static library
- `/root` root user 的主目錄
- `/run` 類似 `/media` 都是外部裝置自動掛載的位置
- `/lost+found` 不當操作或者執行錯誤時, 遺失的文件會臨時放置在此
- `/tmp` 暫存文件, 可能且可以隨時刪除的

系統核心組成

- Linux kernel
- 官方網站 *https://www.kernel.org*
- 完整的 kernel 一般由 5 個部份組成
  - Memory 管理, 如何有效的管理實體記憶體
  - Process 管理, process 運行調度, 實現 multitasking 系統, 如何進行 time sharing
  - Process 間的溝通
  - 虛擬文件系統
  - 網路, 實現網路協定與網路設備驅動

運行機制介紹

- 初始化 init 系統
  - 首先從 BIOS 開始, 引導 linux kernel 進入 memory 中進行初始化
  - 首先執行 PID 為 1 的 init process
  - 依據開發順序 init 系統可以分為 `sysvinit`, `upstart`, `systemd`
- 系統運行模式 runlevel 到 target 的改變
  - `sysvinit` 程序下的運行模式放在 `/etc/inittab`, 對應 `runlevel`
    - 每個 distribution 的運行模式定義不同, 但是 `0`, `1`, `6` 是有共識的
    - `0` 關機模式, `1` 單用戶模式 (限制系統管理員模式), `6` 重起模式
  - `systemd` 機制下使用 `target` 取代 `runlevel`
    - `systemctl get-default` 查詢當前的運行模式
    - 相關設定可以在 `/etc/systemd/system` 下找到
- 系統關機過程
  - `shutdown` 指令
    - 可以安全的關閉 Linux 系統
    - 可以進行 power-off, reboot, halt 等功能
  - `halt` 指令
    - 執行時, 會停止所有應用程序, 然後使用 `sync` 把 memory 訊息寫入硬碟中, 然後中止 kernel
  - `init` 指令會調用系統對應的 init 系統工具
- `systemd` 管理機制
  - 可以進行 init 工作, 也可以管理系統與服務, 兼容 sysvinit 與 Linux 標準啟動腳本
  - `systemd` 在系統中是用戶級別的應用程式
  - configurations 在 `/etc/systemd` 目錄下
  - 並且提供了強大的服務管理工具 `systemctl` 等同於 `sysvinit` 底下的 `service` + `chkconfig` 指令
  - `systemctl start [...].service` 啟動服務, `systemctl stop [...].service` 停止服務,
  - `systemctl restart [...].service` 重起或者啟動服務, `systemctl try-restart [...].service` 在運行時嘗試重起, `systemctl reload [...].service` 重新載入設定檔
  - `systemctl enable [...].service` 註冊開機時自動運行, `systemctl disable [...].service` 關閉開機時自動運行
  - `systemctl status [...].service` 查看服務運行狀態
  - 電源管理 `systemctl poweroff` 關機, `systemctl reboot` 重起, `systemctl suspend` 待機, `systemctl hibernate` 休眠, `systemctl hybrid-sleep` 混合休眠

Linux 與 SecureCRT

- VanDyke SecureCRT 是進行 commercial SSH, Telnet client and terminal emulator 用的軟體
- Secure Shell, SSH, 加密過的連線通道, 預設是 Port 22
  - Linux 伺服器遠端連線通常使用 SSH 進行

---

### 第四章 - Linux 常用命令及使用技巧

Shell

- 用來跟 kernel 互動的程式, 有多個選擇, 系統常見的預設是 Bash (Bourne again shell)
  - shell 除了是 command language 之外也是 script language
- 作為 command language
  - shell 程式與內建命令, 會在使用者登入時, 載入 memory 中, 一直持續到使用者登出
  - 其他的可執行檔案, 都會在呼叫後才載入 memory
    - 例如, `/bin/ls`
- 作為 script language
  - 支援程式語言常見的 expression, variable, loop, condition 等等功能
- shell command 語法
  - `command_name [options] [arguments]`
  - options, 會有前綴 `-`
  - 單一命令句裡可以用 `;` 分隔多個命令一同執行, 用 `\` 讓命令進行斷行繼續輸入
  - Wildcard, 每個 shell 可能會有不同的語法
    - bash 常用的有 `*` 任意, `?` 任一, `[]` 集合內元素
  - Redirection
    - 標準輸入: 預設是鍵盤
    - 標準輸出, 標準錯誤輸出: 預設是螢幕
    - 使用 `<`, `<<` 進行標準輸入重定向, `<` 從檔案輸入, `<<` 告知指定的分隔符中間的內容進行輸入
    - 使用 `>`, `>>` 進行標準輸出重定向, `>` 從檔案輸出 (override), `>>` 從檔案輸出但是 append
    - 使用 `2>`, `2>>` 進行標準錯誤輸出重定向
  - Pipelines 管道
    - 使用 `|` 串接命令, 前面命令的輸出為接續命令的輸入
  - Quoting 特殊字元與跳脫字元
    - `\` 跳脫字元
    - `'` 使用單引號包夾的內容, 全部當成一般字元
    - `"` 使用雙引號包夾的內容, 大多數當成一般字元, 但是少數會保留其作用, 例如 `$`, `\`, `\``
  - Autocomplete 語法自動補全
    - 使用 `Tab` 鍵

系統管理與維護 常用命令

- `ls` 顯示指定目錄下的內容
  - `-l` 顯示詳細資訊
- `pwd` 顯示當前目錄位置
- `cd` 改變當前目錄
- `date` 顯示或修改系統時間
- `passwd` 設定使用者密碼
- `su` 改變使用者身份
  - 可以依據 options 設定對應的環境變數
- `clear` 清除螢幕資訊
- `man` 查詢命令說明文件
- `who` 顯示目前登入到系統的用戶們
- `w` 顯示登入到系統的用戶資訊
- `uname` 顯示作業系統資訊
- `uptime` 顯示系統運作資訊 (啟動時間, 用戶數, 系統平衡負載)
- `last` 顯示過去登入系統的用戶資訊, 預設讀取 `/var/log` 下的 `wtmp`
- `dmesg` 顯示開機時資訊, kernel 會將開機時的資訊儲存在 kernel buffer 中
- `free` 顯示當前 memory 狀態資訊
- `ps` 顯示當前系統 process 狀態資訊 (snapshot)
  - `-ef` 顯示所有的 process
- `top` 顯示當前系統處理器監控 (即時更新)
  - 執行後也有可以進行互動的指令, 可以使用 `h` 或 `?` 查詢

文件管理與編輯 常用命令

- `mkdir` 建立一個資料夾, make directory
  - `-p` 如果路徑上不存在的資料夾也一起建立
- `more` 以分頁的方式輸出到螢幕上
- `cat` 輸出文件內容至螢幕
  - 也可以用來建立檔案
  - 或者合併多個文件內容到新建立的檔案中
- `diff` 逐行比較兩個文件內容
- `grep` 文本過濾工具 (text match patterns) 輸出符合的行
- `rm` 移除目錄或文件
  - Linux 中刪除的文件會永久消失, 需小心使用
  - `-i` 以交互模式進行刪除確認
- `touch` 用來修改文件的修改時間或訪問時間或建立文件
- `ln` 建立文件或目錄之間的鏈結 link
  - 分成 Hard Link 和 Symbolic Link
  - 預設是 Hard Link
  - Hard Link
    - 多個路徑指向相同的 inode index (檔案系統內的檔案編號)
  - Symbolic Link
    - 建立捷徑
- `file` 顯示文件類型
- `cp` 複製文件或者目錄
- `find` 在指定目錄下搜尋檔案
  - 有很多 options 可以進行複雜的搜尋, 與執行接續命令
- `split` 分割檔案成多個
- `mv` 移動文件或目錄或改名文件或目錄

壓縮與解壓縮 常用命令

- `zip`, `unzip`, 將文件或目錄進行壓縮或解壓縮, 預設生成 `.zip` 檔案
  - 有 options 可以進行細緻的操作, 例如排除指定檔案, 移除指定檔案, 設定壓縮等級, ...
- `gzip`, `gunzip`, 將文件進行壓縮或解壓縮, 預設生成 `.gz` 檔案
  - `-l` 可以進行查看壓縮檔案資訊
- `bzip2`, `bunzip2`, 將文件進行壓縮或解壓縮, 預設生成 `.bz2` 檔案
- `tar`, 進行打包成一個檔案但是不進行壓縮, 可以打包, 解開, 或查詢
  - 有 options 可以進行指定的壓縮程序
- `dd` 用來轉換, 複製, 或備份檔案
  - 通常用於複製或備份整個 disk
- `cpio` 使用重導向 (`>`, `<`) 進行檔案的打包, 備份, 還原, 恢復, 壓縮等功能
  - 通常配合 `find` 指令一起使用

硬碟管理與維護 常用命令

- `df` 查看系統上硬碟空間使用情況
  - `-h` 人類好讀版
- `du` 顯示指定的路徑或檔案的檔案大小
- `fsck` 檢查或修復檔案系統
- `sync` 強制把 memory 中的資料寫進 disk 中
  - 預設每 3 秒會進行一次 sync
  - 正常關機程序時也會進行 sync
- `eject` 用來退出抽取式設備, 例如光碟機
  - 如果已經 mount, eject 會先進行 unmount
- `mount`, `unmount` 掛載或卸載指定的檔案系統

網路設置與維護 常用命令

- `ifconfig` 查詢或設定當前網路介面狀態
  - 此命令被 `ip` 命令取代, 可以使用 `ip -c a` 取代 `ifconfig` 進行查看全部狀態
  - 使用此命令進行的設定, 會再重開機後被重置
- `scp` secure copy, 建立在 ssh 上的檔案複製
- `netstat` 顯示當前網路連結資訊, 運行接口等等
  - 此命令被 `ss` 命令取代
- `traceroute` 用來查詢網路封包到指定主機的路由資訊
- `telnet` 與目標主機依據 telnet 協定進行通訊
- `wget` 通過網路進行檔案下載

文字編輯器 vi

- 很多時候會自動使用 vim 取代 vi

---

### 第五章 - Linux 下軟件的安裝與管理

Source code 安裝

- 很多軟體都是開源的, 因此可以從原始碼開始編譯安裝
  - 大多數都是 C 或 C++
- 下載與解壓縮, 閱讀 README
- 運行 configure 檔案檢測安裝環境是否合適 (所需的工具都已安裝)
- 編譯與安裝
  - 很多時候使用 `make`, `make install`
  - 熟悉 `make` 與 makefile
  - 預設的安裝路徑是 `/usr/local` 下, 但是可以自訂

RPM 包方式安裝

- 依據不同的 distributions 會採用不同的 package 管理工具 (`rpm`, `dpkg`)
  - 進行安裝, 查詢, 驗證, 更新, 刪除
- 更新管理工具 (`yum`, `apt`)
  - 協助進行安裝與刪除, 會管理 dependency 問題, 允許多個 repository
  - 進行檢查, 更新, 查詢已安裝, 查詢資訊,
- `.rpm` 內容以包好編譯過後的執行檔, 因此可以直接進行安裝
  - 只會執行解壓縮與驗證
- RPM, Red Hat Package Manager 屬於 Red Hat 體系
  - 安裝使用指令 `rpm`,
  - 利用 `yum` 來管理 rpm
- DPKG, 屬於 Debian 體系 (包含 Ubuntu)
  - 安裝使用指令 `dpkg`
  - 利用 `apt` 來管理 dpkg
- _補_ APT, `apt`
  - `update`, 從 source repositories 更新 package information
  - `upgrade`, 更新所有目前已安裝的 packages (大更新), 不會進行任何的刪除 (remove), 如果需要刪除才能更新時會自動中止
  - `full-upgrade`, 等同於 upgrade 進行大更新, 但是如果遇到刪除會繼續執行
  - `install`, `reinstall`, `remove`, `purge`, 安裝與移除
  - `autoremove`, 移除所有沒有需要使用的 packages (沒有被 dependency 的)
  - `search` 使用 regex 搜尋 packages 列表
  - `show` 查詢 package 資訊,
  - `list` 列出清單等同於 `dpkg-query --list`, 可以配合 `--installed`, `--upgradeable`, `--all-versions` options 進行過濾
  - `edit-sources` 進行手動編輯 `sources.list`

二進位軟體安裝方式

- 已經編譯過後可執行檔
- 只需要進行解壓縮與安裝即可

---

伺服器搭建篇

---

### 第六章 - Linux 伺服器網路配置

網路卡驅動安裝

- 相同的驅動程式安裝邏輯, 適用於其他硬體設備
- 如果自動取得的驅動程式不支援時, 需要手動安裝網路卡驅動程式
- 首先檢查網路卡硬體本身是否故障
- 查詢網路卡晶片型號
  - 不是硬體品牌而是網路卡實際的晶片型號
  - 查詢方式 1. 實際查看網路卡硬體, 上面的晶片序號
  - 查詢方式 2. 使用 `lspci` 指令查詢, 尋找 `Ethernet controller`
- 查詢當前 kernel 上所有支援的網路卡驅動程式
  - 通常路徑在 `/lib/modules/..release../kernel/drivers/net` 下, 尋找 ethernet 與對應的晶片品牌
  - 驅動程式以 `.ko` 為副檔名
- 檢查網路卡驅動 module 是否有被加載入 kernel 中
  - Linux kernel 對硬體的操控是通過驅動程式, 而驅動程式是以可以動態載入的模組的形式存在
  - 使用 `lsmod` 指令查看當前載入 kernel 的 modules, 資料來源是 `/proc/modules`
- 如果驅動沒有被加載時, 使用 `modprobe` 進行 module 加載進入 kernel
  - `modprobe` 指令可以對 kernel 進行 modules 的加載或卸載並且會自動處理 dependency
  - 舊的指令 `insmod` 與 `rmmod` 可以完全被 `modprobe` 取代
  - `depmod` 指令可以進行 module 的 dependency 分析
- 需要手動安裝驅動程式時
  - 需要從硬體廠商網站或者 package manager system 中尋找, 然後把驅動程式解壓縮至 `/lib/modules` 對應的位置下, 之後進行手動加載進入 kernel
  - 需要從原始碼編譯時, 可能會需要相依的 kernel source codes 等工具, 需要確認有 kernel-source, kernel, kernel-devel, kernel-headers, gcc, make 等工具已經有安裝

配置 Linux 網路

- 網路設定通常都作為系統 configuration 存在 `/etc` 目錄下, 每家 distributions 會有不同的子路徑
  - 可以查詢或修改 hostname, hosts, dns 設定, IP 設定, ...
- 除了直接手動修改 configuration 文件之外
- 可以通過 `nmtui` 指令協助進行網路配置 (`NetworkManager`)
  - `NetworkManager` 是一個 service 也是一個指令, 可以通過 `systemctl status NetworkManager` 查看啟動狀態

Linux 網路應用

- Linux 下的 IP 別名功能, 虛擬化
  - 讓一個實體網路卡有多個 IP 位置, 例如 `eth0`, `eth0:1`, ... 同個網卡有多個網路設定並且同時都有作用
  - 使用 configuration 設定或者網路設定指令, 會有不同的影響時期, 有的只有暫時的, 有的在重啟後仍會存在
- 開啟 Linux 代理轉發功能, IP forwarding
  - 從系統設定檔案中修改設定並且套用, `/proc/sys/net/ipv4/ip_forward` (重開機會重置)
  - 設定檔 `/etc/sysctl.conf` 中尋找 `ip_forward` (重開機不會重置)
    - 套用系統設定檔需要使用指令 `sysctl -p`
- Network route 與 routing
  - `route` 指令, 目前已經由 `ip route` 指令取代
  - 手動建立靜態路由表 static routing, 使用 `ip route` 命令進行查詢, 新增, 修改, 刪除
  - routing table 由窄排到大, `0.0.0.0` 作為 IP 代表全部, 作為 Gateway 代表本機處理 (以 Ethernet 為例代表使用 MAC address 直接連線)
  - 建立 routing 時, 必須是本機能有辦法連線的 IP 位置
- 以 Linux 系統架設 Router 服務
  - 開啟 IP forwarding 功能, 並且建立對應的 routing 設定
  - 其他的 Router 也需要設定對應的 routing 設定才能正確的連線
  - 與外網連線的 router 需要開啟 NAT 服務

---

### 第七章 - 架設 Linux 服務器

OpenSSH

- 已加密的方式進行數據傳輸
  - 取代 Telnet 的安全性替代品
- Server-side 啟動 `sshd`
- config 一般在 `/etc/ssh/` 目錄下
  - `man ssh_config` 查看說明文件
- 通過指令 `systemctl start ssh`, 啟動
  - `systemctl status ssh` 查看
  - `systemctl stop ssh` 停止
  - `systemctl restart ssh` 重啟

Web Server

- 安裝與設定 Apache (Web Server) + Tomcat (Java/JSP) 的組合
  - Apache 是 Web Server 處理靜態頁面, 靜態資源和 Proxy 到 Tomcat 的工作
  - Tomcat 處理 Java/JSP 的動態頁面
- Apache 上使用 http-proxy 或 proxy-ajp 來連結 Tomcat
- Apache 可以從官網下載 source code 從 build 開始安裝, 或者使用 package manager 安裝

LAMP servers 的建立

- LAMP, 全部 open sources 的 web application 解決方案
  - Linux, Apache, MySQL, PHP
  - Linux, Apache HTTP server, MySQL or MariaDB, Perl or Python
- 範例示範使用 LAMP 建立 WordPress 網站系統
  - MariaDB, phpMyAdmin
- 安裝 Apache, 設定, 啟動 (`systemctl`)
- 安裝 MariaDB, 設定, 啟動 (`systemctl`)
- 安裝 PHP, 設定, 安裝 phpMyAdmin 設定
- 安裝 WordPress 設定, 連結 Apache 與 MariaDB

DNS Server 建立

- DNS, Domain Name System, 用於轉換域名成為 IP address
- DNS Servers
  - Master DNS
  - Slave DNS
  - Cache-only server
- 使用 Bind 軟體實現 DNS server
- 安裝
- 設定
  - 預設 port 為 53
- 啟動 (`systemctl`)
- 測試
  - 使用 `nslookup` 測試

Samba Server 建立

- 讓 Windows 與 Linux 之間可以進行文件共享
  - Linux 與 Linux 之間也可以使用
- SMB, Server Message Block
- CIFS, Common Internet File System
- 使用的是 server/client model
- 安裝 `samba`
- 設定
- 建立共享目錄
- 啟動服務 `systemctl`
- 權限控管

---

### 第八章 - 構建高性能的 MySQL 資料庫

MySQL 與 MariaDB

- MySQL 分成社群版與商業版
- MariaDB 是 MySQL 社群開源版的分支
- MySQL 目錄結構
  - `/var/lib/mysql`,
  - `/var/log/mysqld.log`, 日誌 log
  - `/etc/my.cnf`, 設定文件
  - `/etc/rc.d/init.d/mysqld`, 服務管理腳本
  - `/usr/lib64/mysql`, 相關 library 路徑
  - `/usr/bin/mysql*`, 二進位可執行檔位置

常見的 high availability MySQL 解決方案

- 如何實現資料共享和資料同步
  - 通常以 SAN (Storage Area Network) 實現
  - 以 rsync 或其他 DRBD 技術實現資料同步
- 如何處理故障時的轉移, 如何在發生故障時不影響服務的情況下進行資料庫的切換
- Master-slave 複製解決方案
  - 使用 MySQL 提供的 log 複製, 達到資料同步
  - Master 進行寫入工作, slaves 提供讀取服務, 達到讀寫分離
  - 出現故障時需要通過手動切換 Master 因此只能達成 90% SLA
  - 如果使用故障時自動切換 Master 的其他服務時, 可達 95% SLA
- MMM 高可用解決方案
  - Master-Master Replication Manager (MMM)
  - 使用雙 masters 多 slaves model
  - 雙 masters 互為 master-slave, 實現只能有單一節點進行寫入, 避免寫入衝突
  - 此使用方案可達 99% SLA
- Heartbeat / SAN 高可用解決方案
  - 依靠第三方軟硬體實現
  - 故障處理使用 Heartbeat 軟體實現, clusters 監控與管理
  - 使用 SAN 共享資料
  - 成本較高, 但是可達 99.99% SLA
- Heartbeat / DRBD 高可用解決方案
  - 依靠第三方軟硬體實現
  - 故障處理使用 Heartbeat 軟體實現
  - 資料共享採用 DRBD (Distributed Replicated Block Device)
  - 較複雜, 但是可達 99.9% SLA
- MySQL Cluster 高可用解決方案
  - 官方主推的解決方案, 較複雜, 設定麻煩
  - 但是可達 99.999% SLA

使用 Keepalived 搭配 MySQL 雙 master 模式產生的高可用集群系統 (high availability clusters)

- MySQL 複製, 本身自帶的複製功能, 以 log 日誌為基礎, 複製, 解析, 重建
  - 單向, 非同步的, chainable
- 這種方式實現的模式只能有一台進行寫入 (master), 其他則唯讀 (slaves)
- 優點是
  - 提升可靠度, Master 出問題時可以切換其他 slave 取代
  - 實現讀寫分離, 降低負擔
  - 網路好且負擔不大時, 可以實現 real-time 同步
- 不同的複製模式
  - 依照指令, 複製相同的指令在 slave 機器上執行
  - 依照資料, 把主伺服器上變動的資料複製過去
  - 混合型, 優先以指令複製執行, 如果無法實現則採用資料複製

---

### 第九章 - Linux 伺服器安全策略

---

### 第十章 - Linux 故障排查思路與案例

---

系統管理篇

---

### 第十一章 - Linux 用戶權限管理

---

### 第十二章 - Linux 磁盤儲存管理

---

### 第十三章 - Linux 文件系統管理

---

### 第十四章 - Linux 內存管理

---

### 第十五章 - Linux 系統進程管理

---

性能調優篇

---

### 第十六章 - Linux 系統優化思路

---

### 第十七章 - Linux 系統性能評估與優化案例

---

虛擬化與集群應用篇

---

### 第十八章 - 虛擬化雲計算平台

---

### 第十九章 - 高性能集群軟件 Keepalived

---

### 第二十章 - 負載均衡集群 LVS 與 HAProxy

---

578
