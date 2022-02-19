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

### 第二章 - 從二層到三層 (data link layer, network layer)

1 從實體層到 MAC 層

- 實體層組合成 Local Area Network, LAN
- MAC 層 (Medium Access Control)
- 使用 _ARP_ 協定以廣播的方式取得目標 IP 的 MAC address
- _RARP_ 反向的協定以 MAC address 尋找 IP 位置
- Hub 無腦的廣播, Switcher 有腦的紀錄與更新 MAC address 與 IP 對應

2 交換機 switcher 與 VLAN

- 多個交換機, 要解決 cycle 問題, 來避免廣播風暴
- 使用 Spanning Tree Protocol, _STP_ 產生交換機的階層來避免 cycle 產生的廣播風暴
  - Root Bridge, Designated Bridge, Bridge Protocol Data Units (BPDUs), Priority Vector
- 以 switcher 設置 _VLAN_ 來提高效能與安全性
  - 設置 VLAN tag 讓支援 VLAN 的 switcher 辨識

3 ICMP 與 ping

- Internet Control Message Protocol, _ICMP_
- 屬於 IP 封包, 用來偵查傳輸狀況的協定, 裡面有各種類型的封包
- 查詢探查封包 (type 8), `ping` 是依據 ICMP 格式再增加一些欄位所成的
  - ICMP ECHO REQUEST 與 ICMP ECHO REPLY (type 0)
- 差錯封包, 當例外情況發生時所發送的封包, 例如: 不可到達, timeout, 路由重新導向
- 在可以控制範圍內發生網路不通時, 可以使用 ping 來偵測不同的網路設備查詢問題可能發生的地方
- 遇到關閉回應 ping 協定的設備時, 要通過其他協定來探測, 例如 telnet
- `traceroute` 使用特定的設定 (例如指定的 TTL) 配合 UDP 來觸發 ICMP 差錯封包

4 想出閘道, 前往外網

- 在路由器 Router 上一筆一筆手動輸入的靜態路由 Static Route
- MAC address 與 IP address
- 在不知道位置時需要訪問 DEFAULT GATEWAY (通常就是該區域網路內的 Router) 來協助處理轉發
- 在內網裡的路由不需要使用到外網 IP (封包傳送不會修改 IP)
- 需要到外網時的路由則需要 Network Address Translation (_NAT_) 來協助轉換內外網 IP
  - 修改 source IP 的 Source Network Address Translation, SNAT
  - 修改 destination IP 的 Destination Network Address Translation, DNAT
- 對於 server-side 而言, 只需要對外的入口使用 public IP 即可, 對內的機器仍然可以使用 private IP 來傳輸

5 路由式通訊協定

- `route` 與 `ip route` 指令查詢與設定靜態路由
- 靜態路由 (static routing) 指定, 目標網路, 出口裝置 (實體 port), 下個路由器位置
- 靜態策略路由, 除了指定目標網路而定之外, 可以通過設定 `ip rule` 做更複雜的判定
  - 可以有多層的 route table 規則
- 動態路由 (dynamic routing) 依據規則自動計算下一個路徑
  - Graph 與最短路徑演算法 Bellman-Ford Algorithm, Dijkstra Algorithm
- Distance Vector Routing 距離向量路由,
  - 依據 Bellman-Ford algorithm 每個路由器紀錄目標網路與距離資訊
  - 每個路由器都知道全域路由資訊並且每次傳遞資訊都是全域路由資訊
  - 壞處是傳播路由資訊的速度較慢, 不適合用在大型網路上 (節點 > 15)
  - 實現範例: Routing Information Protocol, _RIP_
- Link State Routing 鏈路狀態路由, 依據 Dijkstra algorithm
  - 只廣播更新與自己相連的路由器資訊
- 以 Link State Routing 為基礎的 Open Shortest Path First, _OSPF_ 協定
  - 主要用於資料中心內部, 因此又稱為 Interior Gateway Protocol, IGP
  - 在有相等路由時, 可以藉由 load balancer 平衡流量
- 以 Distance Vector Routing 為基礎的 Border Gateway Protocol, _BGP_ 協定
  - 使用於外部網路
  - 自治系統 Autonomous System
  - Stub AS, 對外只有一個接口, 個人或小公司網路
  - Multihomed AS, 多介面, 大公司網路
  - Transit AS, 協助轉發的
  - 分成 external Border Gateway Protocol, _eBGP_ 與 internal Border Gateway Protocol, _iBGP_
  - 以升級版的 _Path Vector Protocol_ 來減低傳播速度慢的問題

---

### 第三章 - 最重要的傳輸層 (transport layer)

1 _UDP_

- Transmission Control Protocol, _TCP_ 與 User Datagram Protocol, _UDP_
  - TCP 需要建立連線, UDP 不需要建立連線
- UDP 與 TCP 都建立在 IP 層上並且通過 port 號來對照應用程式
- UDP header 很簡單, 只需要包含 source port, target port, UDP length, UDP checksum
- UDP 溝通簡單, 不需要提前建立連線, 但是不保證是否遺失或者資料順序等等
- 通常適用場景: 1. 需要廣播, 2. 環境簡單, 3. 應用層自行管理連線與重送問題
- 以 UDP 為基礎客製化的協定或應用場景, 例如:
  - _DHCP_, 動態配置 IP 的協定
  - Quick UDP Internet Connection, _QUIC_ 用來取代 TCP 為基礎的 HTTP 協定
  - Stream 類型資料影音應用, 通常以客製化的 UDP 實現
  - 線上遊戲, 需要快速的反應也通常以客製化的 UDP 實現
  - 物聯網, 終端能力較小, 不適合使用 TCP 的情況
  - 行動通訊領域, 例如 4G 網路

2 _TCP_ 上

- TCP 協定, 在傳輸層就保證了傳輸的品質, 實現重送, 資料順序, 不遺失等保證
- TCP 的狀態是雙方共同維護的並且資料允許雙方傳遞與回覆
- TCP header, 包含
  - source 與 target port,
  - 封包序號,
  - 確認序號,
  - 視窗大小 **AdvertisedWindow**, (能處理的量)
  - 狀態 flag, Synchronize Sequence Number, **SYN**, Acknowledgement, **ACK**, Reset, **RST**, Finish, **FIN**
- TCP 主要維護, 順序問題, 封包遺失問題, 連線維護, 流量控制, 壅塞控制
- 建立連線需要 **3** 次驗證,
  - 客戶端有以下狀態 CLOSED, SYN_SENT, ESTABLISHED,
  - 伺服器端有 CLOSED, LISTEN, SYN_RCVD, ESTABLISHED
- 結束連線需要 **4** 次驗證,
  - 發起方狀態有 ESTABLISHED, FIN_WAIT_1, FIN_WAIT_2, TIME_WAIT (2MSL), CLOSED
  - 接收方狀態有 ESTABLISHED, CLOSED_WAIT, LAST_ACK, CLOSED
- Maximum Segment Lifetime, 最長存活時間, **MSL**, 配合 IP Header 的 Time to live, **TTL**, 常見選項有 30 秒, 1 分鐘, 2 分鐘

3 _TCP_ 下

- 實現 TCP 可靠度的關鍵與演算法
- 利用 cache 與 **advertisedWindow** 來控制封包順序, 封包遺失, 流量控制
- TCP cache, 儲存應用層尚未讀取, 但是已經收到的封包並且依順序排列, 受到 advertisedWindow 控制
- 通過動態的演算法調整逾時重傳的時間 **Adaptive Retransmission Algorithm**
- 通過連續發送 3 個前一序號封包的 ACK 使得服務端立即重傳遺失的內容 (快速重傳) 不需等待 timeout
- 利用演算法與 congestion window, **cwnd** 來控制壅塞狀況, 目標是達到高頻寬並且低延遲
  - 壅塞會產生的現象, 封包遺失 (loss) 和逾時重傳 (timeout)
  - TCP **BBR** 壅塞演算法, 達到佔滿頻寬, 但是不影響快取

4 socket

- 以 UDP 與 TCP 為基礎的 socket 實現

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
