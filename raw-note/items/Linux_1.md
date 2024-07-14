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

---

### 第四章 - Linux 常用命令及使用技巧

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
