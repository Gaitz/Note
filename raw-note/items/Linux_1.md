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
- MySQL 複製的實現原理
  - 從 master server 複製到一或多個 slaves server 的非同步過程
  - 在 master server 上要開啟 Binary Log 功能
  - 會有三個 threads 參與
    - Master server, IO thread
    - Slave server, IO thread 與 SQL thread
  - 由 slave server IO thread 發出請求, 請求指定 log 的位置或內容
  - Master server IO thread 讀取後, 返回給 slave server IO thread
  - Slave server IO thread 讀取後, 寫入對應的中繼 log 文件 (relay-log) 中, 並且儲存讀取到的相關資訊到 master-info 文件中
  - Slaver server SQL thread 讀取中繼 Log 文件, 解析, 並且執行對應的 SQL 命令
  - 以此來達到與 Master server 資料同步
- MySQL 複製的常用架構
  - 1 master, 1 slave
  - 1 master, 多 slaves, 適用於有大量讀取需求
  - 2 masters, 雙主互為備援, 適用於寫入要求較高, 並且避免 single point failure
  - 2 masters, 多 slaves, 雙主, 同時加上多個 slaves
- 架構的通用準則
  - 同一時間只能有一個 master 進行寫入工作
  - 一個 master 可以有多個 slaves
  - Server ID 要確保 unique
  - Slave server 從 master 傳遞來的資料, 可以再次傳遞給其他 slaves
- MM 模式架構, 雙 masters
  - 兩台 masters 資料互相同步, 互相將對方設定為 slave
  - 通過 Keepalived 軟體, 處理錯誤監控和切換, 並且作為 reverse proxy 協助對外 IP 切換
  - 一次只有一台 master 可以進行寫入 (對外)
  - 配合 Keepalived 使用產生故障處理能力

MMM 模式建立 MySQL 高可用集群系統

- 通過第三方軟體達成雙 Master 多 Slaves 的架構, 具有讀寫分離且具有故障處理能力的多伺服器架構
- 此架構在讀寫壓力很大時並不是很穩定, 可能會產生複製 delay, 切換失效等問題
- 存在一個 monitor 進行個別伺服器之間的監控與調整
- 使用 agent 的方式存在每個伺服器, 來與 monitor 進行溝通

MySQL 讀寫分離解決方案

- 對於新系統來說, 在應用端一開始就設計成讀寫分離的模式, 分別留有對應不同伺服器 IP 的空間
- 對於舊系統而言, 可以使用 Proxy 模式, 增加一個虛擬中間層負責處理轉發業務
  - 例如通過 Amoeba 或 MySQL-Proxy 軟體實現
- 通過 Amoeba 實現 MySQL 讀寫分離
  - 需要整合 MMM 解決方案一起使用, 才能保證錯誤處理
  - 就是在 MMM 架構的方案下, 在對外的地方使用 Amoeba 進行讀寫分離的呼叫
  - Amoeba 是以 Java 撰寫的

---

### 第九章 - Linux 伺服器安全策略

網路安全

- 伺服器在網路安全中是最重要的一環
- Linux 作為開源的軟體, 時常受到來自底層的攻擊
- 需要有很強的系統安全防範意識, 理解和應對常見的攻擊種類和防範策略
- 常見攻擊類型
  - 密碼暴力破解攻擊
  - 拒絕服務攻擊 (DoS)
  - 應用程式漏洞攻擊
    - 先使用掃描工具, 掃描目標主機的資訊, 掃出存在的漏洞, 進行有效的攻擊
- 防範攻擊策略
  - 安全防禦, 是來自一系列網路安全設備和軟體安全規則共同完成
  - 網路傳輸安全, 作業系統安全, 應用軟體安全, ...
  - 網路傳輸安全
    - 由實體與軟體網路設備組成
    - 硬體防火牆, IDS 入侵偵測系統, Router, Switch, ...
  - 作業系統安全
    - 進行安全設定和優化
    - 軟體防火牆 iptables, 定期更新, 關閉不需要的服務和 Port, 密碼安全管理
  - 應用軟體安全
    - 進行安全設定和優化
    - 防禦 SQL injection, ...

作業系統常用安全策略

- 軟體的升級
  - 定期更新, 升級, 讓軟體始終處於最新狀態
  - 通過 package manager 實現自動更新或手動更新
- Port 與服務
  - Linux 系統下定義了 65535 (2^16 -1) 個 port
  - 以 1024 作為區分, 之下為 root 用戶才能啟動的 port, 以上為客戶端使用的 port
  - 通過查詢 `/etc/services` 可以查到 port 與服務的對應文件
  - 查看 port 狀態
    - 使用指令 `netstat` 或者新版的 `ss` (socket statistics)
  - 服務與 port 的關係
    - 1 對 1 對應的關係
    - 因此關閉 port 就代表關閉不必要的對應服務
  - Port 與系統安全
    - 真正影響安全的不是 port 而是後面對應的軟體服務
  - 關閉系統不必要的服務
    - 舊版使用 `/etc/init.d` 進行服務的關閉與開啟
    - 新版使用 `systemctl` 進行服務的關閉與開啟
  - 查詢特定的服務狀態
    - 舊版 `/etc/init.d` 時, 使用 `chkconfig --list`
    - 新版 `systemctl` 時, 使用 `systemctl status`
  - 系統運行必要的服務 (_補_, 需要查詢當前版本的 distribution 來得知相關的服務名稱)
    - `acpid`, 電源管理
    - `Apmd`, 監視系統電源狀態
    - `Kudzu`, 檢測硬體是否有變化
    - `crond`, `cron`, cron job 運行服務
    - `atd`, 類似 `crond` 指定時間運行指定事情的服務
    - `iptables`, 防火牆服務
    - `network`, 網路服務
    - `sshd`, `ssh`, ssh 服務
    - `syslog`, 系統日誌服務
- 密碼登錄安全
  - 密碼暴力破解
    - 過短的 (6 位以下) 純數字密碼, 會被在幾分鐘內被破解
  - 推薦放棄密碼的驗證方式
  - 例如金鑰認證方式 (ssh), _補_ 實體金鑰
- 其他安全設定
  - 禁止系統回應 ping request (關閉 icmp 功能)
    - `echo "1" > /proc/sys/net/ipv4/icmp_echo_ignore_all`
    - 或寫入系統開機時自動運行的指令設定檔中
  - 限制 shell history 的數量
    - `.bashrc` `HISTSIZE` 預設是 1000
    - 重設限制在 30 以下, 0 代表不開啟紀錄功能
  - 刪除系統預設中不必要的用戶 (user) 與群組 (group)
    - 列出所有的用戶與群組 `getent passwd`, `getent group`, 或者 `/etc/passwd`, `/etc/group` 文件裡的值
    - 刪除指令 `userdel`, `groupdel`
  - 設定 tcp_wrappers 防火牆
    - 相關設定依據 `/etc/hosts.allow` 與 `/etc/hosts.deny` 兩個文件
    - 設定允許或阻擋的服務, IP, 域名之間的關係

Linux 軟體防火牆 iptables

- 防火牆可以分成兩種類型
  - Packet Filter, 封包過濾式防火牆
  - Application-Level Gateway, Proxy 防火牆
- `iptables` Linux 常見的軟體防火牆, 屬於封包過濾式
  - 設定封包過濾規則, 定義哪些應該接收, 哪些應該剔除
  - 操作 Linux kernel 中的 `Netfilter` 防火牆機制
  - `iptables` 具有 extension 可以擴充其能力｀
- `iptables` 在架構上,
  - 可以保護本身主機之外,
  - 也能架設在 router server (gateway) 上進行區域型過濾, 可以達成在內網區域有多層的防火牆
  - 對 DMZ (Demilitarized Zone) 進行安全保護
- `iptables`
  - 由各自獨立不同的 table 所組成,
  - 每個 table 中都有多個 chains 可以進行設定
  - 每個 chain 裡有 rules 與 policy
- filter table
  - INPUT chain, 外部進入系統的過濾
  - OUTPUT chain, 內部往外發送的過濾
  - FORWARD chain, 外部來傳遞到內部的過濾
- nat table, NAT (Network Address Translation)
  - PREROUTING chain, 進入系統需要轉換目的地地址的 (DNAT)
  - POSTROUTING chain, 離開系統要改變來源地址的 (SNAT)
  - OUTPUT chain, 改變本地產生 packet 的目的地地址
- mangle table, 用來修改不同的 packet 與 head
  - PREROUTING chain, POSTROUTING chain, OUTPUT chain, INPUT chain, FORWARD chain
- raw table
- security table
- `iptables` 規則執行順序
  - 規則是依照順序執行的, 因此順序會非常重要, 限制越嚴格的順序要在前才有作用
- `iptables` 指令
  - `-t`, 指定 table, 預設是 filter table
  - `-L` `--list`, 列出所有的規則
  - `-v`, 顯示更多內容
  - `-n`, 以 IP 表示
  - `-F` `--flush`,
  - `-X` `--delete-chain`,
  - `-Z` `--zero`,
  - `-P` `--policy`, 針對哪個 chain 進行設定
  - `-A` `--append`, 把新規則加在最後 (tail)
  - `-I` `--insert`, 把新規則插入在指定位置, 如果沒有指定位置時, 預設會在 head
  - `-i` `--in-interface`, 進入的網路介面
  - `-o` `--out-interface`, 出去的網路介面
  - `-p` `--protocol`, 指定協定
  - `-s` `--source`, 來源 IP
  - `-d` `--destination`, 目的地 IP
  - `-j` 指定 target
- 制定防火牆規則
  - 可以針對不同方面進行設定, IP address, 網路介面, 網路協定, Port 號, 連線狀態 (state), MAC address
- 行為 (target), 分成終止與非終止型, 參考 iptables extension 賦予更多種的 targets
  - `ACCEPT` (終止型), 通過
  - `REJECT` (終止型), 拒絕, 但是會回應
  - `DROP` (終止型), 丟棄, 不回應
  - `REDIRECT`, 用於 NAT 轉發到其他的 port, 再比對其他規則

Linux 系統的備份

- 系統管理人員, 職責不是要保障系統永遠不會出現問題
  - 而是在問題出現時, 能以最快的速度, 最短的時間內恢復系統運行, 並且保證資料安全, 將故障影響降到最低
- 以硬碟為基礎的備份, 對於 linux 來說, 可能是不必要的
  - 而是取代以設定檔為備份對象
- 系統等級設定文件
  - 備份如 `/etc/`, `/home/`, `/boot/`, `/root/` 下的完整資料
- 使用者等級設定文件
  - 備份如 `/usr/local/`, `/var/www/`, `/etc/` 下的完整資料
- 儲存體, 要考量存取速度, 儲存安全, 儲存容量
- 儲存在磁帶上, 使用 `mt` 指令進行磁帶操作, `tar` 指令打包寫入與讀取
  - 推薦不要儲存時不需要進行壓縮, 避免資料有部分毀損時, 造成無法解壓縮, 反而損害資料安全
- 本地備份與異地備份
- 備份策略
  - 完全備份
  - 差異備份 (增量備份)
  - 取決於不同的性質, 每日新增資料不多的系統, 應該使用完全備份, 反之則應該使用差異備份
  - 取捨於備份容量, 復原速度與難易度
- 自動備份可以使用 script 腳本配合 cron job 進行
- 使用 `rsync` 進行遠端的備份
  - `rsync` 使用 server-client model 進行遠端的資料複製
  - 支援差異備份, 加密, 保留權限設定等功能
  - 比 `cp`, `scp` 之類的複製功能更適合進行備份使用
- 使用 `inotify` 文件系統監控與 `rsync` 實現 realtime 備份

---

### 第十章 - Linux 故障排查思路與案例

處理 Linux 系統故障的思路

- 重視報錯提示
- 查閱日誌文件, 系統日誌 `/var/log`, 與應用程式的日誌 (log files)
- 分析, 定位問題
- 解決問題

忘記 Linux root 密碼

- 重啟 Linux 系統, 並且進入單用戶模式 (init 1), 在不必使用密碼的情況下, 進行 root 密碼的修改
- 實作方式, 開機登入時從 `grub` 操作介面修改 (`e`) 載入 kernel 時的指令
  - 載入單用戶模式後, 使用 `passwd` 進行密碼修改
- 在 `systemd` 模式下會有不同的指令, 進行類似的行為

Linux 系統無法啟動的解決方法

- 系統設定文件遺失或設置錯誤, `/etc/` 下的重要設定
  - `/etc/fstab` 遺失, 需要配合其他 Linux 開機進入救援模式
  - 進入救援模式後,
  - 進行調查 `fdisk -l` (查詢硬體設備) , `tune2fs -l` (查詢過去掛載點)
  - 與 `/etc/fstab` 文件的重建, 依據調查到的結果自行重建 `fstab` 文件並且寫入原本的系統目錄下
- 不正常關機導致, `/` 目錄分區毀損
  - root `/` 下文件系統出現故障,
  - 小錯誤可以通過 ext3, ext4 本身的修復機制進行自動修復
  - 無法自動復原時的手動修復, 先 `unmount` 要修復的分區位置, 然後使用指令 `fsck` 進行修復
- Linux kernel 毀損, 無法正常啟動
- 系統開機程式出現問題, 例如 `grub` 遺失或毀損
- 硬體零件故障
- 系統無法響應時的問題分析
  - 關注螢幕上的輸出訊息提示
  - 硬體問題導致故障
  - 軟體問題導致故障
    - kernel bug, driver bug, application bug, ...
  - 系統設定不當出現問題
    - 恢復到 default 設定, 關閉錯誤設定的防火牆等等

Linux 下常見的網路故障處理

- 解決網路問題的順序, 從底層開始向上尋找
- 檢查硬體設備是否有問題, 網路線, 網路卡, hub, switch, router
- 檢查網路卡是否正常運作, 檢查網路卡是否載入, IP 設定是否正確
  - 檢查網路卡, `lsmod`, `ifconfig`, `ip link`
  - 檢查 ip 設定
  - 檢查 route table, `route`, `ip route`
- 檢查 DNS 設定是否正確, 檢查 `/etc/hosts` 與 `/etc/resolv.conf`, `/etc/nsswitch.conf`
- 檢查 service 是否有開啟, `netstat`, `ss`, `ssh`, `telnet`
  - 檢查 port 開啟的狀況, 是否有對應的服務啟動
  - 檢查該服務的設定檔
- 檢查防火牆設定與權限設定, `iptables -L`, SELinux
- 檢查區域網路內的主機連線, `ping`

Read-only file system 錯誤與解決案例

- 當檔案系統遇到嚴重問題時 (文件系統本身無法自行修復), 讓檔案系統變成 read-only 鎖定來避免資料安全與一致性
- 通常需要找到出問題的分區, `unmount` 後進行手動修復 `fsck`
  - 無法 `unmount` 時, 使用 `fuser` 指令查詢佔用檔案或 sockets 的程序

通過 `su` 指令切換使用者帶來的困擾

- 檢查要切換對象的 `/home/` 目錄是否存在並且有正確的權限設定
- 檢查 `su` 指令的權限設定是否正確
- 檢查 SELinux 設定是否正確
- 檢查檔案系統分區容量是否足夠
- 檢查權限除了通過 `ls` 之外可以使用 `stat` 指令來查詢
  - 尤其是檢查根目錄的權限 `stat /`

因 NAS 故障引起的 Linux 系統恢復案例

- `df -h` 檢查硬碟容量與掛載情形
- `fdisk -l` 檢查硬碟分區情形
- `du -sh` 檢查指定目錄下的容量情況 (`-s` summarize, `-h` human readable)

---

系統管理篇

---

### 第十一章 - Linux 用戶權限管理

用戶 (user) 與用戶組 (group) 管理

- Linux 是多用戶多任務作業系統
- 用戶分類
  - super user, 擁有最高權限 `root` user
  - 普通用戶, 擁有自己的目錄, 並且擁有登入系統的權限
  - 虛擬用戶, 不能登入系統 (nologin), 作為系統管理上權限控管需求而存在, 例如 `bin`, `adm`, `nobody`
- 用戶組 group
  - 通過定義權限在群組上, 讓權限管理更方便管理
- user 與 group 的關係, 多對多關係

相關設定文件

- `/etc/passwd` 文件, 所有人都有權限讀取
  - 描述每個用戶的 username, 加密過的密碼, User ID (UID), User's group ID (GID), 使用者資訊 (GECOS), User home directory 家目錄, Login shell 預設登入使用的 shell
- `/etc/shadow` 加密後的密碼會存放在這個文件中, 只有 root 用戶可以讀取
  - 用戶名稱, 加密後的密碼, 最後一次修改時間 (天數), 修改時間最小時間間隔, 修改時間最長時間間隔, 警告密碼失效時間 (天數), 不活動時間, 失效時間, 保留使用
- `/etc/group` 存放群組資訊
  - 群組名稱, 加密後的密碼, group ID (GID), 組內用戶 users
  - 加密後的密碼被分存在 `/etc/gshadow`
- `/etc/login.defs` 存放一些預設值的設定
  - 例如密碼最長有效天數, 密碼最小長度, UID 最小最大值, 是否要建立家目錄等等
- `/etc/default/useradd` 使用指令 `useradd` 時的預設值設定檔案
  - 例如預設的 shell 路徑, 預設群組, 是否會自動失效, 與自動失效的天數
  - 指令 `useradd -D` 會列出當前預設值
  - 可以通過直接修改文件或者使用 `useradd -D` 指令進行修改
- `/etc/skel` 目錄下存放在新建使用者時, 自動預設存在的設定檔
  - 例如 `.bashrc`, `.profile` 等等

管理工具介紹

- `groupadd`, `newgrp`, `groupdel`
- `groupadd` 新增群組
- `newgrp` 使用者切換代表群組
  - 使用者本身可以有多個群組, 但是代表群組只會是其中之一
  - 在生成檔案時會指定生成群組, 因此可以依據需求切換代表群組
- `groupdel` 刪除群組
  - 群組中有使用者時, 需要先移除使用者才能刪除
- `useradd`, `usermod`, `userdel`
- `useradd` 建立使用者
  - 預設值會參考 `/etc/login.defs`, `/etc/default/useradd` 兩個文件下的內容
  - 會生成紀錄在 `/etc/passwd`, `/etc/group`, `/etc/shadow`, `/etc/gshadow`
  - 然後複製一份 `/etc/skel` 以下的預設檔案在新使用者目錄下
- `usermod` 修改使用者設定
  - 例如 uid, 名稱, 群組, 使用者描述, ...
- `userdel` 刪除使用者
  - `-r` `--remove`, 參數代表刪除使用者的同時也刪除該使用者對應的家目錄
- `passwd` 修改使用者密碼
  - 使用者可以修改自己的密碼, 除非密碼被設為鎖定
  - 系統管理員 super user, 可以用此指令修改其他使用者包含 `root` 的密碼

檔案與權限設定

- 每個檔案都有讀, 寫, 刪除, 執行等不同的權限設定
- 查看檔案權限
  - `ls -al`, `ll` 指令
  - 顯示檔案類型與權限, 鏈結數 (有多少鏈結指向同個 inode), 所屬用戶與所屬群組, 檔案大小, 最後修改日期, 檔案名稱
- 檔案類型與權限 (file mode bits), 10 個字元組成, 分成四個部分
  - 第一個字元代表檔案類型, `d` 目錄, `l` soft link, `-` 文件, `c` 設備, `b` 可儲存的區塊
  - 之後每三個字元為一組, `r` 可讀取, `w` 可寫入, `x` 可執行, `-` 沒有權限
  - 各組依照順序分別為 user, group, others
    - user 代表檔案所有者的權限
    - group 代表檔案所屬群組的權限
    - others 代表以上之外使用者的權限
- `chown` (change owner) 修改檔案所屬使用者或群組
  - `-R`, `--recursive` 參數代表遞迴套用在以下的目錄與檔案
- `chmod` 指令進行檔案權限修改, 有兩種表示法
  - 字元表示法,
    - 作用對象 `u` user, `g` group, `o` others, `a` all
    - 作用方式 `+` 新增, `-` 移除, `=` 覆蓋
    - mode, `r` 可讀, `w` 可寫, `x` 可執行, `-` 沒有權限
  - 數字表示法
    - 每個權限使用 3 個 bit 表示,
    - 因此對照回十進位時, 變成 `0` 代表沒有權限, `1` (001) 代表可執行, `2` (010) 代表可寫入, `4` (100) 代表可讀取
    - 因此混合組合後對照成十進位就會有 `[0-7]` 代表不同的權限組合, 例如 `7` 代表可讀可寫可執行, `5` 代表可讀可執行, `6` 代表可讀可寫

---

### 第十二章 - Linux 磁盤儲存管理

硬碟管理的基本概念

- Linux 中所有的硬體都是以文件的方式存在, 設備文件, 存在 `/dev/` 目錄下
- 檔案類型 `c` (character device file) 字元設備文件 與 `b` 塊狀設備文件 (block file)
- 硬碟設備在 Linux 中的表示方式, 依據實體設備接口的不同, 對應不同的名稱
  - IDE 硬碟, `hd` + 設備序號 + 分區編號
  - SCSI 硬碟, `sd` + 設備序號 + 分區編號
- 設備掛載 (mount) 與使用
- 掛載需要知道
  - 掛載磁碟分區的文件系統類型 (例如, ext2/ext3/ext4 )
  - 掛載分區對應的設備文件
  - 建立一個目錄作為掛載點
- 預設掛載點在 `/mnt`, `/media` 但是不是強制使用, 可以自行建立
  - 掛載時可以用 `pwd` 確認自己是否已經離開掛載點, 否則掛載時會遇到 device busy 錯誤
- 退出設備要使用 `unmount` 卸載掛載點
- `df -h` 命令查詢當前檔案系統使用狀況, 不需要管理者權限
- 單一硬碟內的分區劃分 (_補_: 此種限制與劃分來自於 MBR partition table 標準, 新版的 GPT 則沒有這種限制)
  - 分成主分區 (primary partition), 擴展分區 (extended partition), 邏輯分區 (logical partition)
  - Primary partition 數量限制是 `4`, 並且有大小限制, 是可以用來啟動的區塊 (bootable)
  - Extended partition 佔用 Primary partition 其一數量限制, 作為 Logical partition 的容器
  - Logical partition 必須隸屬於 Extended partition 下
- 指令顯示當前所有硬碟設備的分區情況, 需要管理者權限才能讀取
  - `fdisk -l`
  - `parted -l`

使用 `fdisk` 工具進行硬碟分區劃分

- 硬碟劃分工具有 `fdisk`, `cfdisk`, `parted` 等等
- `-l` 參數作為查詢工具
- `fdisk` 指定 device 進入互動式硬碟分割
  - `m` 查詢所有指令
  - `n` 建立新分區
  - `t` 修改分區類型
  - `p` 查看當前分區 table
  - `w` 儲存並且進行分割
  - `q` 離開並且放棄改變
- 分割完之後還需要進行不同文件模式的格式化才能使用
- _補_: `fdisk` 工具, 比較新的版本也支援 `GPT` 分區規格分割

利用 `parted` 工具規劃硬碟分區

- `parted` 擁有比 `fdisk` 更豐富的功能
- 可以使用互動模式和命令模式 (可撰寫成腳本執行)
- 兩種 partition table
  - `MBR` (master boot record) 舊的規格, 對於 Windows 有很好的相容性, 甚至是 DOS
  - `GPT` (GUID Partition Table) 新的規格, 沒有 MBR 的限制 (例如: 主分區數量限制為 4, 單個分區 2TB 容量上限)
    - GPT 分區數量是沒有限制的, 但是 windows 系統具有辨識上限 128 個
    - GPT 分區沒有 primary, extended, logical partition 的設定區別
- 需要考量硬體支援度 UEFI 與 GPT
  - 開機韌體分成 BIOS (舊), UEFI (新)
- 使用指令 `parted` 進入互動模式
  - `help` 查詢所有指令
  - `mklabel` 建立 partition table
  - `mkpart` 建立新分區
  - `print` 印出相關訊息
  - `rm` 刪除分區
  - `select` 選擇其他設備

檔案類型格式化

- 在硬碟切分完分區後, 需要針對不同的分區進行檔案類型格式化
- 使用指令 `mkfs` 進行檔案類型格式化

LVM

- 在分區大小設定後, 如果發現不合需求, 常見的解決方案是重新進行分區分割, 或者使用 soft link 連結分區
- LVM (Logical Volume Manager) 是 Linux 下針對硬碟分區進行管理的一種機制
  - 一種抽象的中間層, 介於硬碟分區與檔案系統之間
  - 讓不需要重新設定硬碟分區的情況下, 讓檔案系統可以使用
- Physical media, 物理儲存設備, 例如: 系統上的硬碟
- Physical Volume, PV, 實際上的硬體分區
- Volume Group, VG, 由多個 Physical Volume 組成, 形成類似虛擬的硬碟
- Logical Volume, LV, 在一個 Volume Group 中, 進行虛擬的分區
- Physical Extent, PE, 在硬碟實體分區上最小的儲存單位, 預設是 `4MB`
- Logical Extent, LE, 在虛擬分區上 (Logical Volume) 最小的儲存單位, 單位容量需要與 Physical Extent 做一對一對應
- 因此掛載 (mount) 時, 掛載的不是實體分區, 而是虛擬的邏輯分區 (Logical Volume, LV)
- 需要安裝專用的工具包
- LVM 建立與管理
  - 在使用 LVM 之前, 實體硬碟分區, 要指定成 LVM 所能識別的種類 (`Linux LVM`)
  - 分割完成後不需要進行格式化
  - 使用指令 `pvcreate` 選定想要使用 LVM 的實體分區 (PV) 在未來組成 VG 使用
  - 使用指令 `vgcreate` 選擇 PVs 組成不同的 Volume Group (VG)
  - 使用指令 `vgchange` 啟動建立完成的 Volume Group
  - 查詢相關資訊 `vgdisplay`, `pvdisplay`
  - 使用指令 `lvcreate` 在指定的 VG (Volume Group) 上建立虛擬分區 (LV, Logical Volume)
  - 使用檔案類型格式化命令 (例如: `mkfs`) 格式化虛擬分區 (LV) 來使用
  - 一樣需要掛載 (mount) 虛擬分區後才能使用
  - 使用指令 `vgextend` 後續新增新的 PV 進入 VG 中
  - 使用指令 `lvextend` 或 `lvreduce` 動態調整虛擬分區 (LV) 的容量大小
    - 並且依據不同的檔案類型選用不同工具實現大小擴充
    - 指令 `xfs_growfs` 對應 `xfs` 檔案系統
    - 指令 `resize2fs` 對應 `ext2/ext3/ext4` 系列檔案系統
  - 使用指令 `pvremove`, `vgreduce`, `vgremove`, `lvremove` 進行 PV, VG, LV 的刪除或調整
    - 執行順序要對應建立順序的反向

---

### 第十三章 - Linux 文件系統管理

檔案系統

- 檔案系統是基於作業系統的
- 是用來管理, 組織保全在硬碟驅動上資料的軟體
  - 資料儲存佈局, 空間管理, 文件命名, 安全控制等管理
  - 解決如何有效的儲存資料
  - 實現資料完整性, 保證寫入與讀取是一致的
  - 建立 metadata
- 實現對資料存取的簡單化, 抽象化
  - 檔案系統作為作業系統與硬碟之間的中間抽象層
- 使用流程
  - 選擇儲存實體介質
  - 硬碟分區 (partition)
    - `fdisk`, `cfdisk`, `parted`
  - 檔案系統建立 (檔案系統格式化)
    - `mkfs` (make file system)
  - 掛載 (mount)
    - `mount`
- _補_: 檢視各個 partition 檔案系統的指令
  - `lsblk -f` (`-f` `--fs`) 列出系統偵測到的所有 block devices
  - `df -T` (`-T` `--print-type`) 當前掛載的檔案系統

Linux 下常見檔案系統介紹

- Virtual File System, VFS, 抽象化檔案系統, 讓作業系統可以用統一的介面操作不同類型的檔案系統
- DOS 文件系統, `msdos`
- Windows 下的 FAT 系列, `FAT16`, `FAT32`, `NTFS`
- 光碟檔案系統, `ISO-9660`
- 單一檔案系統, `ext2`, 日誌檔案系統 `ext3`,
- 集群檔案系統 `gfs` (Red Hat Global File System), `OCFS2` (Oracle Cluster File System)
- 加密檔案系統 `CFS`, 虛擬檔案系統 `/proc`, 網路檔案系統 `NFS`
- `ext3`, `ext4` 檔案系統
  - Linux 檔案系統演進, VFS -> ext -> ext2 -> ext3
- `ext2` 由超級塊 (superblock), 塊組 (block group), 塊組描述符 (group descriptor) 組成
  - 一個 block size 可以是 `1KB`, `2KB`, `4KB`, `8KB`, 可以在檔案系統建立時指定
  - 最開始的 1024 bits 為 boot block 存放啟動程序
  - 接下來的 1024 bits 為 superblock 存放整個檔案系統全域的資訊 (非常重要), 在檔案系統被 mount 時, 會被讀取近 memory
    - superblock 在後續的 block group 中會存有備份
  - `ext2` 使用 inode 來記錄檔案訊息, 每個檔案對應一個 inode (一對一對應)
  - `ext2` 的容錯在於有多份 superblock 關鍵資料的備份和 `ext2` 系統在重啟時會通過 `fsck` 嘗試修復損壞的部分, 然而這樣產生了一定程度的效能問題
- 為了硬碟大量讀寫造成的效能問題, 檔案系統通常使用非同步的方式進行, 修改當下只會存在 memory 中, 不會馬上寫入硬碟, 而是後續通過一個 daemon 在適當的時機進行寫入
  - 相應的會產生資料不同步的問題, 例如寫入時系統崩潰, 導致資料同時有部分舊版部分新版, 或者在寫入 metadata 時出錯, 導致實際資料與 metadata 不一致
- `ext3` 是一種日誌檔案系統 (Journaling file system)
  - 直接建立在 `ext2` 新增一個特殊的 inode (Journal), `ext2` 可以直接升級使用
  - Journal 模式, 所有的資料 (data) 與 metadata 改變都紀錄進日誌中, 減少資料遺失的機率, 但是需要更多的讀寫資源, 最慢但是最安全
  - Ordered 模式, 只有 metadata 改變被紀錄在日誌中, 只有在資料寫入硬碟後才把 metadata 寫入日誌, 保障了資料完整性, 但是不保證資料遺失, `ext3` 的預設模式
  - Writeback 模式, 只紀錄 metadata 改變, 但是不保證是在資料被寫入硬碟之後, (換句話說, 可能會有 metadata 已改變, 但是資料遺失的情況), 最快但是最沒保障, 類似於 `ext2`
- `ext4` 擁有比 `ext3` 更多的新功能
  - 支援無限制的子目錄數量, 更大的檔案系統, 更大的檔案
  - 支援日誌校驗功能
  - 支援快速 fsck
  - 支援線上硬碟整理, 減少碎片化的問題
- `ReiserFS` 高性能日誌檔案系統, 優於 `ext2`, `ext3`
  - 對小檔案 (< 4KB) 進行效能優化 (比較於 `ext2`, `ext3`)
  - 日誌管理系統, 保證資料寫入前, 先有日誌完成紀錄
  - 更快速的搜尋速度, 建立在使用 B\+-tree 資料結構上
  - 適合用於大量小檔案, 需要快速讀寫的使用場景
  - _補_: (此檔案系統缺乏維護, 新版不會再被納入 Linux kernel 中)
- `XFS` 日誌檔案系統
  - 另外處理的日誌系統, 提升安全性與效能
  - 對大檔案, 大數量支援優秀
  - 快速的寫入速度
  - 適合用於大量大檔案的使用案例上
  - 相關指令
    - 使用 `mkfs` 進行格式化
    - 把檔案系統掛載加到 `/etc/fstab` 中, 允許系統啟動後自動加載
    - `xfs_bmap`, 查看檔案 block 狀況
    - `xfs_db`, 查看檔案系統碎片化狀況
    - `xfs_fsr`, 整理檔案系統碎片
    - `xfs_repair`, 檢查或嘗試修復受損的 xfs 檔案系統

選擇檔案系統的標準

- 取決於應用場景
- 需要頻繁讀取, 小檔案眾多的應用
  - 適合 `ext4`
- 需要頻繁寫入的應用
  - 適合 `XFS`, 相對於 `ext4` 有更優異的 CPU 使用表現
- 性能要求不高, 安全性要求也不高的場景
  - 適合 `ext3` 或 `ext2` 節省了很多硬碟性能
  - 例如 `/tmp` 目錄

NFS 的使用

- `NFS`, Network FileSystem, 網路檔案系統
  - 讓網路上不同的作業系統可以共享資料
  - Server-client model
  - NFS server 共享檔案目錄
  - NFS client 不同的遠端作業系統, 可以掛載 (mount) 遠端的檔案系統, 使用上如同讀取自己本地端的檔案一樣
- NFS 的實現原理
  - NFS server 啟動後, 都會開啟一個任意在 1 ~ 1024 port 給 client 連接使用
  - 因為每次的 port 都不同, 因此會使用 Remote Procedure Call, RPC 協議來協助連接
  - 因此, 在啟動 NFS server 服務之前, 需要先啟動 RPC 服務 (`rpc.nfsd`, `rpc.mountd`), _補_: 服務名稱在各作業系統版本可能不同
  - NFS server 啟動相關的服務, `portmap`, `nfs-utils`
- NFS 安裝
- NFS server 設定
- NFS client 安裝與設定
- NFS server 安全設定
  - 因為 NFS 沒有用戶認證機制, 因此權限設定會非常重要
  - 需要依循 NFS 的 best practice, 盡可能避免安全漏洞
    - 例如: 使用最新版, 設定正確的防火牆, ...
  - 對於共享出去的目錄, 提供 client 最低的權限,
  - `anonuid` (指定 client uid), `anongid` (指定 client group id)
  - 不應該開啟 `no_root_squash` 來自 NFS client 永遠不讓他拿到 root 權限
  - 依據可能的 client 數量設定適當的 NFSD COPY 數
- 另外一款類似的跨作業系統遠端資料共享服務 `SMB`
  - Windows 原生, 對於 Windows 支援度更佳, 比 NFS 具有更多的功能

Linux 下常用的資料恢復工具

- 應該以備份作為核心, 資料恢復工具只是輔助, 來避免資料遺失
- 如何使用 `rm -rf` 指令
  - Linux 下沒有類似 Windows 資源回收桶的功能
  - 因此使用 `rm` 時需要特別小心
  - 推薦的解決方案是使用 `mv` 到 `/tmp` 下, 配合腳本設定定期清除, 取代使用 `rm`
  - 避免資料遺失最重要的方式還是**備份**
- 開源的資料恢復工具們
  - `debugfs`, `R-Linux`, `ext3grep`, `extundelete`, ...
  - `ext3grep` 與 `extundelete` 具有相似的資料恢復原理, `extundelete` 功能更強大
- `extundelete` 基於 Linux 的資料恢復工具, 通過分析檔案系統中的日誌 (jounrel), 解析所有檔案的 inode 資訊
  - 適用於 `ext3`, `ext4` 檔案系統
- `extundelete` 資料恢復原理
  - 通過 inode 資訊, 配合日誌查詢, 找到遺失資料所在的 block 區域, 使用 `dd` 將資料複製出來後重建
  - 使用 `ls -i` 可以查詢檔案或目錄的 inode 資訊
- 安裝 `extundelete`
  - 從原始碼開始 build 或使用 package manager 安裝
- `extundetele` 用法詳解
  - 查詢 superblock 資訊, 日誌資訊, inode 資訊, block 資訊,
  - 以時間搜尋被刪除的檔案
  - 復原檔案 (restore)
- 實戰
  - 誤刪後, **第一時間**要做的是 `unmount` 被刪除的數據分區 (partition)
  - 如果是根目錄 (`/`) 遭誤刪, 需要讓系統進入單用戶模式, 並讓根目錄以 read-only 模式 mount
  - **避免被誤刪的資料區塊被系統重新使用**
  - 第二步, 使用 `extundelete` 針對 partition 指定 `inode` `2`, 根目錄進行查詢
  - 找到資料後, 使用 restore 相關指令, 復原單檔或目錄 `--retore-file`, `--restore-files`, `--retore-directory`
  - 使用復原全部被刪除的資料 `--retore-all`, 可以配合 `--after`, `--before` 進行時間區間篩選, 配合 `date +%s` 取得時間秒數來計算

---

### 第十四章 - Linux 內存管理

物理內存與虛擬內存

- Physical RAM and virtual RAM
  - 物理記憶體代表硬體實際提供的記憶體
  - 虛擬記憶體則是由 Linux 模擬出的記憶體抽象層, 實質存取上可能不是硬體記憶體, 而是硬碟模擬的, 即 SWAP 空間
  - 主因在於物理記憶體很快速, 但是容量不足時
- Linux 的記憶體管理, 使用 paging 技術, kernel 在物理記憶體不足時, 會把沒有用到的資料暫存到 SWAP 空間中
  - 不定時的使用 paging 技術調整物理記憶體的空間與資料
  - 使用 LRU (Least recently used) 最近最少使用演算法來選擇
- 當實體記憶體與虛擬記憶體不足以切換所需要使用的資料容量時, 會造成當機或服務異常

內存的監控

- `free` 指令查看記憶體空間佔用狀況, 資訊來自於 `/proc/meminfo`
  - _補_, 資訊表示方式與代表意義會依據版本不同而不同, 需要再次查詢文件才能確認
  - `total` 物理記憶體容量
  - `used` 已使用的物理記憶體大小, (total - free - buffers - cache)
  - `free` 完全沒用到的物理記憶體大小
  - `buffers` kernel buffers 所使用的暫存大小
  - `cache` page cache 與 slabs 所使用的暫存大小
  - `shared` 多個 process 共享的物理記憶體空間大小
  - `available` 大約會是 free + cache + buffers
- `buffers` 緩衝與 `cache` 快取的差異
  - `buffers`, 只紀錄檔案系統中的 metadata 和 tracking in-flight pages, 主要記住檔案結構的資訊, 有哪些檔案和對應的權限
  - `cache`, 快取實際的資料

交換空間 (swap) 的使用

- swap area 可以是一個專用的 partition 或者一個特殊建立的檔案 (a file)
- 使用 `dd` 指令建立 swap 用的 file
  - 範例: `dd if=/dev/zero of=/data/swapfile bs=1024 count=65536`
  - `bs` 一次讀寫 (r, w) 所使用的 bytes 數, 會覆蓋 `ibs` (輸入, 讀取), `obs` (輸出, 寫入) 設定值
  - `if` 讀取的檔案
  - `of` 輸出的檔案
  - `count` 複製的 block 數量
  - `/dev/zero` 特殊的偽設備, 輸出都是 0, 常用於初始化
- 使用 `mkswap` 指令設定 file 或 partition 為 swap (建立 swap, 但是還未使用)
- 使用 `swapon` 指令啟用 swap
  - 可以使用 `/etc/fstab` 讓重啟後可以自動掛載
  - `swapon -a` 會啟用所有被寫在 `/etc/fstab` 裡的 swap
- 使用 `swapoff` 指令可以移除 swap (停用)
  - `swapoff -a` 會停用所有寫在 `/etc/fstab` 裡的 swap

查看進程 (process) 佔用內存 (memory)

- `top`
- `ps`
- `/proc`
- `/proc/../status`
- 使用以上相關指令與資訊, 可以建立客製化的 script 來取得想要的資訊

---

### 第十五章 - Linux 系統進程管理

- 使用 time-sharing 技術, 讓不同的使用者不同的程式, 可以一起進行處理 (多工)
  - 對於單核心的系統, 每個時間片斷只能進行一項工作 (單個 process)
  - 對於多核心的系統, 每個時間片段就能執行多個任務 (多個 process)
- Process, 一個在自身的虛擬地址空間中運行的獨立程式
  - 對於作業系統來說, 所有在系統上運行的東西都是一個 process
- 分類
  - 系統進程 (system process, kernel mode), 可以進行記憶體資源分配, process 切換等管理工作, 不受 user 控制 (包含 root user)
  - 使用者進程 (user process, user mode), 受使用者控制下運行或關閉的
    - 交互進程, 由 shell 啟動的 process, 執行過程中與使用者交互操作
    - 批次處理進程, 由多個 process 集合而成的 process, 會依序啟動執行
    - 守護進程 (daemon), 一直運行的 process, 獨立於 terminial, 通常週期性的執行某些任務或者等待處理某些事件
- 屬性, 狀態
  - 可運行狀態, 運行中或正準備運行
  - 可中斷的等待狀態, block 中的等待狀態, 可以接受訊號 (signal) 進入執行狀態
  - 不可中斷的等待狀態, block 中的等待狀態, 但是不會接收或反應訊號
  - 僵死狀態 (zombie), 每個 process 執行完成後都會進入終止狀態, 但是 parent process 尚未釋放其系統資源
  - 暫停狀態
- Process 之間的關係
  - Linux 系統中以 PID (process ID), 區分不同的 process, 是有數量上限的, 預設上限是 32768, 但是是可以改動的, 依據系統為 32-bit 或 64-bit 有所不同
  - 所有的 process 都是 `PID 1` process (啟動程序, `init` 或 `systemd`) 的後代
  - 查詢指令 `ps -ef`, PPID 為 parent PID
  - 每個 child process 必有其 parent process
  - child process 關閉不會影響到 parent process
  - 如果 parent process 在 child process 之前退出 (exit status), 會讓 child process 變成 orphan (孤兒) 進入僵死狀態, 資源無法被釋放
  - defunct process 解決方案是由其他 process 作為其 parent process 協助資源釋放

進程的監控與管理

- `ps` 指令
  - 配合 `grep` 使用捕捉想要查詢的 process
  - `UID` 使用者 ID, `PID` process ID, `PPID` parent process ID, `TTY` 所屬的 terminal
  - `STIME` start time, `TIME` 所使用的 CPU time, `CMD` 執行的指令
- `ps -ef` 全部 process 標準輸出
- `ps auxf`全部 process 使用 BSD 輸出, `f` 代表 forest, 顯示 process hierarchy
  - `%CPU` CPU 佔比, `%MEM` 記憶體佔比,
  - `VSZ` 虛擬記憶體大小 (in KB), `RSS` 非 swap 的實際記憶體佔用數 (in KB)
  - `STAT` 當前狀態,
    - `R` 運行中, `S` 可中斷的休眠, `Z` 僵死 (zombie, defunct),
    - `<` high-priority, `N` low-priority
    - `s` session leader, `l` multi-threaded, `+` 背景執行
- `pstree` 指令, 監控系統 process
  - 以樹狀結構呈現 process 之間的關係
  - `-a` 顯示完整指令, `-n` 依據 pid 排序, `-p` 顯示 PID, `-u` 顯示 user
  - 可以指定 PID 或指定 user
- `top` 指令, 監控系統 process
  - 動態 (dynamic), 即時的 (real-time) 顯示當前 process 狀態, 並且是交互模式
  - `RES` 實際佔用的記憶體, `SHR` 共享的記憶體, `S` 狀態
  - 交互模式指令詢問 `?`, `h`
- `lsof` 指令, 監控系統 process
  - `lsof`, list open files, 列出所有已開啟的檔案
    - 由於任何東西在 Linux 都是已檔案的形式存在, 因此 `lsof` 的功用更為強大
  - `lsof` + 檔案名稱, 可以查詢某個特定檔案由哪個 process 在使用中
  - `lsof -c` 查詢指定 command 相關的 open files
  - `lsof -g` 查詢指定 process group Id (PGID) 下所開啟的檔案
  - `lsof -p` 查詢指定 PID 開啟的檔案
  - `lsof -i` 查詢與 Internet 相關的開啟檔案, 可以依據 IP version, protocol, hostname, hostaddr, service, port 做篩選
  - `FD` File Descriptor, 數字, 或有 `r`, `w`, `u` (r + w) 作為檔案開啟模式
- `pgrep` 指令, 查詢 process ID
  - 通過名稱, PPID, PGID, GID, SID, tty 等等篩選 process
  - `pgrep` 查詢 (look up), `pkill` 發送訊號 (signal), `pidwait` 等待 (wait)
  - `-l` `--list-name` 輸出 PID + process name
  - `-a` `--list-full` 輸出所有訊息

任務調度 crond 的使用

- `crond` 在 Linux 下週期性執行某種任務或等待處理事件的一個 daemon
  - _補_: systemd 版本使用 `systemctl status cron` 可以查詢
- 分成兩類
  - 系統週期性任務, 系統任務相關路徑在 `/etc/crontab`
  - 使用者週期性任務, 每個使用者可以有自己的 crontab, 相關路徑在 `/var/spool/cron/crontabs`
- `crontab` 指令, 進行管理
  - 指定 file 代表把檔案加入 crontab
  - `-u` 指定使用者, 預設是當前使用者
  - `-e` 編輯 crontab
  - `-l` 顯示 crontab
  - `-r` 移除 crontab
  - `-i` 配合 `-r` 使用會提供二次提示 `y/Y` 才確認刪除
- `crontab` 檔案內容
  - 每一行都代表一項任務
  - 每個任務分成 6 個區塊
  - `minute hour day month week command`
  - `minute`: [0-59], `hour`: [0-23], `day`: [1-31], `month`: [1-12], `week`: [0-7] (0 與 7 都代表星期日)
  - 特殊字元: `*` 任意值, `,` 分隔列出, `-` 範圍, `/` 頻率
  - command 要執行的命令
- 注意事項
  - 注意環境變數問題, `cron` 任務執行時的環境變數與使用者當前的不同, 因此需要在腳本裡設定正確的環境變數
  - 注意 `cron` 任務執行後的結果會通過 email 給任務所有者 (owner), 參考 `MAILTO` 環境變數, 可以查詢 `man cron` 說明文件查看說明
  - 系統級任務與用戶級任務, 有些行為必需要使用系統級 crontab 才能執行, 例如: 定時重啟系統

使用 `kill` 和 `killall` 指令終止 process

- 用來關閉某些服務或者處理 zombie process
- `kill` 指令, 依據 PID 發送訊號 (signal) 給 process
  - 呼叫 kernel 對指定的 process (pid) 發送指定的訊號 (signal) 來實現終結 process 運行
  - `-l` `--list` 查詢所有的 signal 選項
  - 指定發送的訊號 `-<signal>`, `-s`, `--signal`
  - 特殊 pid, `-1` 代表全部 process (除了 init 和 kill process 本身)
- 常用訊號
  - SIGKILL `9`, 強制結束, 強制性不正常結束時, kill parent process 會讓 child process 變成 orphan process, 被 pid 1 收養
  - SIGINT `2`, 結束 process, 但是不是強制性, 一般使用 `Ctrl+c` 就是發送此訊號
  - SIGTERM `15`, 表示正常結束 process, 預設值, 一般正常結束的情況下, kill parent process 會自動釋放 child process
- `killall` 指令, 等同於 `kill` 但是使用的是 process name 去搜尋, 搜尋的目錄是 `/proc`
  - `-r` `--regexp` 以 regex 方式搜尋名稱
  - `-u` `--user` 指定使用者
  - `-v` `--verbose` 顯示更多結果報告
  - `-w` `--wait` 等待 process 終結
  - `-o` `--older-than`, `-y` `--younger-than` 依據時間

---

性能調優篇

---

### 第十六章 - Linux 系統優化思路

- 對於性能最重要的是 Linux 作業系統與應用程式的最佳結合
- 完成任務的有效性, 穩定性, 回應速度
- 影響性能的因素有很多, 需要一一排查, 找出出現瓶頸的地方

影響 Linux 性能的因素

系統硬體資源

- CPU
  - 考慮到 CPU 數量, 頻率, 運行 symmetric multi-processing (SMP) 的核心
  - 常受到 CPU 限制的應用: 郵件伺服器, 動態 Web 伺服器, ...
- Memory
  - 考慮到容量大小, 與作業系統限制
  - 容量太小會影響速度, 容量太大則浪費資源
  - 32 bits 作業系統對於 memory 有上限, 64 bits 作業系統幾乎沒有上限
  - 常受到 memory 影響的應用: 列印表機服務器, 資料庫伺服器, 靜態 Web 服務器, ...
- 硬碟 I/O
  - 在有頻繁讀寫的應用上, 硬碟 I/O 性能至關重要
  - RAID (Redundant Array of Independent Disk), 依據不同的 RAID 規格, 能提升不同程度的性能與安全性
  - 常見的 RAID
    - RAID 0, 需要 2 個硬碟以上, 單純的組成容量更大的硬碟組, 沒有容錯與修復能力, 但是提升硬碟性能與 throughput
    - RAID 1, Mirror, 兩個硬碟完全相同, 擁有最高的安全性, 但是硬碟利用率只有 50%, 成本最高, 適合保存重要資料的場合
    - RAID 5, 至少需要 3 個硬碟以上, 採用奇偶校驗, 允許一個硬碟故障, 提升可用性, 安全性, 讀取速度
    - RAID 0+1, 至少需要有 4 個硬碟以上, 即 RAID 0 + RAID 1 的實現, 每個硬碟都有自己的 mirror
- 網路頻寬

作業系統相關資源

- 系統安裝優化
  - 從硬碟劃分 (partition) 與 swap 設定, 都會影響效能
  - 依據不同的應用需求, 採用在不同的分區實現不同的 RAID 種類來進行最佳化
    - 寫入頻繁, 安全要求不高, RAID 0
    - 安全性要求高, 讀寫沒有要求, RAID 1
    - 讀取要求高, 寫入沒有要求, 提供一定程度的安全性, RAID 5
    - 讀寫要求都高, 對資料安全也有高度要求, RAID 0+1
  - swap 設定
    - 在過去較小的 memory (< 4 GB) 時, 通常設定 swap 為 memory 兩倍容量, 中等大小 (8GB - 16GB) swap 設定與 memory 相等
    - 在更大的 memory 的現在, swap 的設定就不需要過大
- Kernel 參數優化, 網路設定優化
  - 取決於應用程式, _補_: 應該查詢所使用的應用程式相關的文件資訊
  - 例如: 資料庫應用程式, 所需的設定優化; Web 應用, 所需的網路設定優化
- 檔案系統優化
  - 根據不同的應用選擇不同的檔案系統
  - 例如依據讀寫的需求不同選擇 `ext4` 或 `XFS`

應用程式的優化

- 應用程式本身的優化, 更是至關重要
- 影響效能的 bug 或者不好的軟體架構設計

分析系統性能的相關人員

- Linux 維運人員 (DevOps, PE)
  - 要瞭解和掌握系統當下的運行狀態 (CPU 使用率, Memory 使用率, Process 狀態, 網路連線狀態, 開啟檔案狀態, ...)
  - 掌握系統相關的硬體資訊和設定 (硬碟 I/O, CPU 型號, Memory 實體大小, 網路卡型號與頻寬大小)
  - Monitoring 與 Observability 很重要, 設定即時的檢測與通知
- 系統架構設計人員 (architect)
  - 了解瓶頸是否來自於架構設計
- 軟體開發人員 (developer)
  - 了解與改進相關程式設計
  - 例如: 改進效能不良的 SQL 語法, 演算法優化

系統性能分析工具

- `vmstat` 指令, Virtual Memory Statistics
  - 一次查看關於 processes, memory, paging, block IO, traps, disks, cpu 運作的報告
- `iostat` 指令, I/O statistics
  - 主要顯示硬碟讀寫的操作統計數據 (device report), 會額外提供 CPU 使用情況 (cpu report)
- `sar` 指令, 搜集與報告系統運作資訊, 非常強大好用
  - _補_: 需要啟動服務, `systemctl start sysstat`

系統性能分析標準

- 沒有固定的標準, 只有經驗性的評判
- CPU: %usr + %sys, 使用者與系統運行佔用百分比
- Memory: 查看 swap 使用量
- 硬碟: CPU 的 %iowait, 等待 IO 的運行百分比
- 好: CPU < 70%, 沒有 swap 運作, %iowait < 20%
- 壞: CPU <= 85%, swap 運作, 每個 CPU 10 page/s, %iowait = 35%
- 糟糕: CPU >= 90%, 更糟糕的 swap 量, %iowait >= 50%

總結

- 更多相關工具, 來查看系統不同面向
  - `uptime`
  - `free`
  - `ps`, `top`
  - `netstat`, `ss`
- 遇到問題與性能瓶頸時, 需要有一個順序一一排查
  - 例如: Network -> Memory -> CPU -> IO

---

### 第十七章 - Linux 系統性能評估與優化案例

CPU 性能評估

- `vmstat` 指令
  - 可以通過 options 設定產生報告的時間間隔與次數
  - Process
    - `r` 運行數量
      - 如果長期 > CPU 個數, 則代表 CPU 不足
    - `b` block 數量 (等待 IO 的 process)
  - Memory
    - `swpd`, swap 使用量
    - `free`, idle 量
    - `buff`, 作為 buffers 的使用量 (對 block device 讀寫)
    - `cache`, 作為 cache 的使用量
    - `inact`, inactive memory
    - `active`, active memory
  - Swap
    - `si`, swapped in from disk, (從硬碟到記憶體)
    - `so`, swapped to disk (從記憶體到硬碟)
    - 應該時常為 `0`, 否則代表 memory 不足
  - IO
    - `bi`, 接收來自於 block device 的速度 (read)
    - `bo`, 輸出至 block device 的速度 (write)
  - System
    - `in`, interrupts 數量 per second
    - `cs`, context switches 數量 per second
  - CPU, 百分比
    - `us`, user time, 使用於 non-kernel code
      - 如果長期 > 50%, 則代表需要優化演算法或程式
    - `sy`, system time, 使用於 kernel code
    - `id`, idle time
    - `wa`, waiting for IO, IO 等待時間
      - 參考值是 20%, 如果長期 > 20% 則代表有硬碟讀寫的效能瓶頸
    - `st`, 被虛擬機佔用的時間 (虛擬機偷取時間), time stolen from a virtual machine
    - `gu`, 運行 KVM guest code
    - us + sy 的參考值在 80%, 長時間 > 80% 則代表 CPU 資源可能不足
- `sar` 指令
  - 可以針對系統的各個部分做檢測, 開啟 `sar` 相關服務是會消耗效能的, 但是通常是可接受的
  - `sar -u 3 5`, 檢測 cpu 報告間隔 3 秒進行 5 次, 最後會呈現 average 的統計數據
  - CPU 佔用百分比
    - `%user`, user time 佔比
    - `%nice`, 正常運行的 process 佔比
    - `%system`, system time 佔比
    - `%iowait`, IO 等待時間佔比
    - `%steal`,
    - `%idle`, 處於空閒的時間佔比
  - `sar -P ALL 3 5` 針對個別的 CPU 進行檢測, 避免遇到單執行緒程式佔用單獨核心過高的運算資源
- `iostat` 指令
  - 除了檢測硬碟 IO 之外, 可以通過 `iostat -c` 只檢測附帶的 CPU 百分比平均值
- `uptime` 指令
  - 輸出內容為當前時間, 系統已經運行多久, 當前登入使用者數量, 系統平均負載過去 1 分鐘, 過去 5 分鐘, 過去 15 分鐘
- 以上四個指令只能看出 CPU 是否繁忙, 負擔過重, 無法查出原因
  - 需要配合 `ps`, `top` 等指令查詢實際消耗的 process 試圖找出原因

Memory 性能評估

- `free` 指令
  - `free -w`
  - 主要觀察 `free`, `cache`, `available` 值, 看看 memory 的可使用量是否有不足的情況
  - 可以搭配 `-s` 和 `-c` options 進行連續的檢測
- `free` + `watch` 結合動態檢測 memory
  - `watch` 指令可以用於定期執行某些指令, 然後輸出在全螢幕上, 並且可以通過 `-d` option 顯示差異之處
  - 配合 `free` 指令變成能動態檢測 memory 狀態
- `vmstat` 指令
  - 通過 `vmstat` 指令可以很全面的看到 memory 是否不足
  - 尤其觀察 `swpd`, `si`, `so` 查看 swap 的使用情形, 並且配合 CPU `wa` 查看 IO 等待時間佔比是否過高
- `sar -r` 指令
  - 使用 `sar -r` 指令單獨檢測 memory 的使用情形
  - `sar` 指令比 `free` 指令更詳細的產生使用率佔比 `%`
- 目前 memory 價格越來越低, 很少遇到單純是 memory 資源不足的問題
  - 很高的使用佔比更可能的是應用程式本身有問題, 需要查明 (例如: memory leak)

硬碟 IO 性能評估

- 熟悉 RAID 各種不同的儲存方式, 可以因應不同需求選擇適當的 RAID 類型
- 盡可能使用 memory 取代 disk IO, 速度快非常多
- 將資料依據使用情況進行分類, 分別放在不同的硬碟中提供最佳化
  - 長期不變的, 需要大量讀取的, 需要頻繁讀寫的
- 在特殊需求下 (需要頻繁的寫入) 可以考慮使用 raw device 取代使用檔案系統格式化的硬碟
  - 優點: 減少作為中間層的檔案系統運行的消耗
  - 缺點: 不易管理, 需要更專業的操作
- `sar -d` 指令
  - 使用 `sar -d` 檢測硬碟資訊
  - `DEV`, 設備名稱
  - `tps`, 每秒 IO 流量
  - `rkB/s`, 每秒讀取 kB 數 (read)
  - `wkB/s`, 每秒寫入 kB 數 (write)
  - `dkB/s`, discarded
  - `areq-sz`, 平均 IO request 的大小 (size)
  - `aqu-sz`, 平均 queue 的長度大小 (queue size)
  - `await`, 平均 IO request 等待時間
  - `%util`, 單位時間內 IO 操作的時間佔比
  - 特別關注於 `areq-sz`, `aqu-sz`, `await`, `%util` 數值, 查看 IO 使用是否有瓶頸
- `iostat -d` 指令
  - 檢測硬碟使用資訊
  - 速率相關的數值是統計於啟動時間到現在, 可以用來評估 IO 性能
  - 主要查看 `kB_read/s` 與 `kB_wrtn/s` 數值大小, 評估是讀取使用還是寫入使用頻繁
  - 長時間超大量的硬碟讀寫肯定會造成性能問題
  - 通過指令 `iostat -x` 可以查看更多統計數據
    - _補_: 可以配合 `man iostat` 查看文件, 只列出所需的統計數據
- `vmstat -d` 指令
  - 使用 `vmstat -d` 單獨檢測硬碟使用資訊
  - 會分別列出 reads, writes, IO
- 對於 block device 的性能影響, 要來自多方面的評估與調整
  - 首先, 進行應用程式對硬碟讀取的優化, 能使用 memory 就不要使用 block device
  - 對於硬碟存取的方式進行優化, 選擇適合的 RAID 方案
  - 更深入研究是否需要使用 raw device 取代檔案系統操作

網路性能評估

- 網路直接影響服務的穩定度和可靠度
- `ping` 指令
  - 檢測網路的連通性
  - 檢視兩台主機之間的連線, 是否可連, 連線速度 (time), 連線品質 (packet loss) 如何
- `netstat` 指令 (舊版 net-tools), _補_: 新版本使用 `ss`, `ip` 指令取代
  - `netstat -i` 依據 interface 檢視流量
  - `netstat -r` 檢查路由表
  - `ss` 檢查當前連線
  - `ip route` 查詢路由表
- `sar -n` 指令查詢網路相關資訊
  - `sar -n DEV`, `DEV` 網路接口資訊, `EDEV` 網路錯誤資訊, `SOCK` 網路 socket 連線資訊,
  - _補_: `sar -n` 功能非常強大, 還有很多不同的關鍵字與統計數據可以查詢, 需要配合 `man sar` 查看文件
- 可以搭配 `traceroute` (路由檢測), `nslookup` (DNS 檢測) 排查網路問題

優化案例分析

- 書中以兩個案例進行分析與優化
  - 動態內容的 Web 網站伺服器, 使用 LAMP 架構
  - 動態與靜態內容的 Web 網站伺服器, 使用 Java + Tomcat + MySQL 架構
- _補_:
  - 從遇到問題的狀況 (incident, issues) 開始分析
  - 從系統各個面向查詢性能使用狀況, CPU, Memory, IO, Networking, Process, ...
  - 進而調整應用程式相關的設定檔, 例如: Apache config, Tomcat config, ...
  - 繼續觀察然後發現有應用程式優化的機會, 例如: 修改 PHP 程式內容, 優化演算法等等
  - 最後發現需要調整系統架構, 以支持更好的服務品質, 例如: 導入 Tomcat + Apache 分別處理靜態與動態回應, 資料庫分到別的伺服器上並且實現讀寫分離架構, ...

---

虛擬化與集應用篇

---

### 第十八章 - 虛擬化雲計算平台

OpenVZ

- 開源的, Linux 平台作業系統虛擬化解決方案
- host OS 與 guest OS 都必須是 Linux
- host OS 與 guest OS 共用同一個 Linux kernel, 因此不能單獨升級版本

KVM

- KVM, Kernel-based Virtual Machine
- 開源的, 需要硬體支援的, 硬體虛擬化技術
- 支援所有 x86 CPU
- 基於 Linux kernel (host)

Proxmox VE

- Proxmox VE, Proxmox Virtual Environment
- 開源的虛擬化平台, 允許使用 OpenVZ, KVM 等虛擬化技術
- 基於 Debian Etch 版本的虛擬化環境
  - 因此安裝需要有 Debian OS
- 提供 Web 管理介面

安裝 Proxmox VE

Proxmox VE 的使用

- 建立 OpenVZ 虛擬機
- 建立 KVM

---

### 第十九章 - 高性能集群軟件 Keepalived

- 建立有彈性, 高可用的服務, 以 cluster 的方式建立提供單一伺服器做不到的性能

集群的定義 (cluster)

---

### 第二十章 - 負載均衡集群 LVS 與 HAProxy

---

578
