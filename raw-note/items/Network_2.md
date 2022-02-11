## 網際協定全書 - 劉超

### BOOK resource, ComputerScience/Network

---

第一章 - 通訊協定概述

第二章 - 從二層到三層

第三章 - 最重要的傳輸層

第四章 - 最常見的應用層

第五章 - 陌生的資料中心

第六章 - 雲端運送中的網路

第七章 - 容器技術中的網路

第八章 - 微服務相關協定

第九章 - 網路通訊協定知識串購

---

### 第一章 - 通訊協定概述

1 為什麼要學習網路通訊協定

- 應用中涉及很多層的網路協定並且各種新技術 (雲端運算, 容器, 微服務) 都會有相關的網路協定或串接方式

2 網路分層的真正含意

- 只分開討論各層網路協定是沒有意義的, 因為運作中不會只有單一層的網路協定在運作, 而是互相交互影響
- 需要學習將到的各網路協定的基礎概念串接起來
- 封包的思考, 如何接收, 如何處理, 如何發送

3 ifconfig

- Classless Inter-Domain Routing, CIDR, 子網路分割
- linux 系統下的 `ifconfig` (net-tools), `ip addr` (iproute2)
- 網路卡 public 與 host, IP 分成 v4 與 v6, 含有 MAC address (網路卡的身份證字號)
- 子網域中可以使用廣播 (broadcast) 確認 MAC address 的位置 (所屬的機器)
- 外網需要使用 IP address 做定位
- public IP 與 private IP 和子網路遮罩 (網路位置與機器位置)
- 網路裝置的狀態標示
  - BROADCAST, 可以發送廣播
  - MULTICAST,
  - UP, 啟動中
  - LOWER_UP, 線路連線中
  - MTU, Maximum Transmission Unit, 最大傳輸單元, Ethernet 上限為 1500 bytes
  - qdisc, queueing discipline, 排隊規則, pfifo_fast, 先進先出但是擁有三個 band, 分別有各自的優先順序 band 0 > band 1 > band 2, 依據 type of service, TOS 決定

4 DHCP 與 PXE

- 手動設定 IP address, 使用 `ifconfig` 或 `ip addr`, `ip link`
- IP 設定可以通過網管人員手動設定, 如果 IP address 不會時常更改時
- linux 系統封包判定,
  1. 以 IP 判斷是否在同個子網域 (如果是則發送 ARP 請求確認目標 MAC address)
  2. 如果不是同個子網域則發送到 DEFAULT GATEWAY 準備轉發到外部網路
- _Dynamic Host Configuration Protocol_, _DHCP_, 通過協定自動配發 IP
- 新機器帶著 MAC address 發送廣播 (Boot request)
  - 帶著自己的 MAC address
  - 來源 IP 為 `0.0.0.0`, 目標 IP 為 `255.255.255.255` (廣播位置)
  - 以 UDP 封裝
  - 使用 BOOTP 協定 Boot request
- DHCP 伺服器會回傳 DHCP Offer 給新機器, 由新機器來決定是否接受 (新機器發送 DHCP Request 確認租用)
- DHCP 流程是 Boot request (to server) -> DHCP Offer (from server) -> DHCP Request (to server) -> DHCP ACK (from server)
  - 以上流程都是以廣播方式實現
- DHCP IP 租約回收與續租, 在租約時間達 50% 時會再次使用 DHCP 協定與伺服器互動來更新租約時間 (延長)
- DHCP IP 衝突時, 有人手動設定已被租用的 IP 導致衝突,
  - 客戶端可以使用 ARP 請求來判斷 IP 是否已經被使用來避免衝突
  - 伺服器端可以使用 ping IP address 來避免衝突
- _Preboot Execution Environment_, _PXE_, 利用 DHCP 伺服器協助提供 PXE 伺服器位置與開機檔案名稱
  - 以 DHCP + PXE 讓客戶端安裝作業系統
  - BIOS 讀取 PXE 來發送 DHCP 相關請求與互動
  - 取得 PXE 伺服器位置與開機檔案名稱
  - 以 _Trivial File Transfer Protocol_, _TFTP_ 來下載開機檔案並且執行安裝作業系統

---

### 第二章 - 從二層到三層

1 從實體層到 MAC 層

- 實體層組合成 Local Area Network, LAN
- MAC 層 (Medium Access Control)
- 使用 ARP 協定以廣播的方式取得目標 IP 的 MAC address
- RARP 反向的協定以 MAC address 尋找 IP 位置
- Hub 無腦的廣播, Switcher 有腦的紀錄與更新 MAC address 與 IP 對應

2 交換機 switcher 與 VLAN

-

---

### 第三章 - 最重要的傳輸層

---

### 第四章 - 最常見的應用層

---

### 第五章 - 陌生的資料中心

---

### 第六章 - 雲端運送中的網路

---

### 第七章 - 容器技術中的網路

---

### 第八章 - 微服務相關協定

---

### 第九章 - 網路通訊協定知識串購

---
