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

系統管理與維護 常用指令

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

文件管理與編輯 常用指令

---

### 第五章 - Linux 下軟件的安裝與管理

---

伺服器搭建篇

---

### 第六章 - Linux 伺服器網路配置

---

### 第七章 - 架設 Linux 服務器

---

### 第八章 - 構建高性能的 MySQL 資料庫

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
