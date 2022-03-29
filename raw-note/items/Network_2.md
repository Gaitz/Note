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
- 相關於 OS kernel
- socket 是作為讓 client 與 server 能夠互相溝通 (read, write)
- TCP socket 因為需要建立連線因此需要 server-side: `bind() -> listen() -> accept()`, client-side: `connect()`
- socket 在 linux kernel 中是以檔案方式存在 (file)
- UDP socket 因為不需要交握因此，只需要使用 `bind()`
- 討論單機 socket 所能允許的數量上限與各種處理方式
- 理論最大連接數為 {本機 IP, 本機 port, 客戶方 IP, 客戶方 port},
  - 不可能達到, 理由是受 OS kernel 實體限制包含記憶體限制與檔案個數上限
- 以 multiple process 處理 (OS `fork()`)
- 以 multiple thread 處理 (OS `pthread_create`)
- 受到 process 與 thread 數量上限會遇到單機器 **C10K** 問題
- 以**更有效的 I/O** 方式解決 process 與 thread 數量上限問題
  - **polling**, 單個 thread or process 監控與執行多個 socket
  - **epoll**, 以 callback 方式實現 event based, 實際監控的 sockets 以 red-black tree 儲存, 因此搜尋 callback 的時間是 O(log(n))
- 因此最終方法, **epoll** 方式下的數量上限為 OS 所能允許的開啟檔案數量上限

---

### 第四章 - 最常見的應用層

1 HTTP

- **URL**, Uniform Resource Locator, 包含協定名稱, domain name, path to resource
- HTTP 傳輸層是以 TCP 為基礎
- _HTTP 1.1_ 中預設開啟 **keepAlive** 盡可能重用同一個 TCP 連結
  - 配合 **KeepAliveTimeOut** 時間來決定何時關閉 TCP
- Request 包含 method, URL, HTTP version, headers, body
- 常用 Methods, **GET**, **POST**, **PUT**, **DELETE**
- 常用 Request headers, **Accept-Charset**, **Content-Type**, **Cache-Control**, **If-Modified-Since**
- HTTP 應用層把資料視為 Stream, 傳輸層仍然是 TCP 封包
- Response 包含 HTTP version, status code, headers, body
- _HTTP 2.0_, 仍然使用 TCP 為基礎, 但是優化傳輸容量與應用層多工處理
  - Header 壓縮
  - 應用層實現多個 stream 並且共用同一個 TCP
  - 切割資料成更小的 frame
- HTTP 2.0 以應用層多工改善 HTTP 1.1 的單個 stream 傳輸, 但是底層仍然是 TCP 會受限於 TCP 的傳輸順序
- Quick UDP Internet Connection, _QUIC_, 傳輸層以客製化的 UDP 為基礎實現 HTTP 協定的功能
  - 自訂連接, 連接不以 IP 為基礎, 而是使用自定義的 64 bits ID
  - 自訂重傳, 與 TCP 不同的是封包順序與封包內容不使用同一個序號, 封包順序採用遞增的序號, 封包內容採用 offset 做辨認
  - 採用 UDP 後無需受到 TCP 傳輸順序影響導致阻塞
  - 自訂流量控制與壅塞控制, 利用與 TCP 類似的概念與演算法實現

2 HTTPS

- _HTTPS_ 讓 HTTP 建立在安全通道 (secure) 上
- 同時使用對稱加密與非對稱加密, 並且通過數位權證 (certification) 來驗證可信度
- 作為驗證與發證的機構 **Certification Authority, CA**
  - 以階層式建立的 CA 通過層層背書的方式來提供可信度
  - Self-Signed Certification, 自行認證的, 可信度無法背書
- HTTPS 先以非對稱式加密與數位權證的方式驗證與傳遞未來實際使用的對稱式加密金鑰 (key)
- 首先使用明文的 **Transport Layer Security, TLS** 做傳遞通道
- Client Hello (內包含一組亂數)
- Server Hello (內包含一組亂數), Server Certificate, Server Hello Done,
- Client 驗證 certification 並且產生亂數 pre-master
- Client Key Exchange, Change Cipher Spet, Encrypted Handshake Message
- Change Cipher Spec, Encrypted Handshake Message
- 對稱式加密執行較快, 但是 key 無法安全的傳遞
- 非對稱式加密執行較慢, 但是沒有 key 傳遞的問題
- 因此 HTTPS 最終資料傳遞使用對稱式加密, 只有在驗證與傳遞亂數的時候使用非對稱式加密和數位簽章

3 Stream 串流資訊

- 視訊, 即一連串的圖片資訊, 圖片即像素組成,
- 完整的資料太過巨大, 因此不管是圖片還是視訊都會需要經過壓縮與編碼
- 視訊編碼兩大機構,
  1. **International Telecommunications Union, ITU**, **Video Coding Experts Group, VCEG**, 例如 _H.264_
  2. **International Standards Organization, ISO**, **Moving Picture Experts Group, MPEG**, 例如 _MPEG-4_
- 視訊編碼被統一, 由兩大機構一起制定了 _H.264/MPEG-4 AVC_ 標準
- 視訊服務架構: 生產方 -> 分散式 servers -> 消費者
- 視訊資料以 frame 為單位, 分成三種類型 **I-frame**, **P-frame**, **B-frame** 有不同的容量與壓縮率, I 最完整, B 壓縮率最高
- 每個 frame 會被分成多個 slice, 每個 slice 又分成巨集塊, 每個巨集塊裡又有多個子塊
- 傳輸的封包單位為 **Network Abstraction Layer Unit, NALU**, 資料為一個 slice 一個 NALU
  - 包含 header 與 payload
- **NALU** 資料傳輸使用 _Real-Time Messaging Protocol, RTMP_ 協定,
  - 此協定建立在 TCP 上,
  - 有額外的 connect() 通道, 來傳遞版本編號與時間戳記

4 P2P 協定

- 傳輸資料以 HTTP 或 FTP 傳輸大容量的資料都會常有效能問題
- _File Transfer Protocol, FTP_ 協定
  - 使用 2 個 TCP 連接,
  - 一個固定為 **21 Port** 做為控制使用
  - 另一個與客戶端建立用來傳輸資料
  - FTP 分成 主動模式 (PORT) 與 被動模式 (PASV) 來與客戶端建立資料通道
- **Peer-to-Peer, P2P**
- **.torrent** 內儲存 tracker URL 與檔案資料 (info, Name, 每段容量, 資料 HASH)
- 把大容量資料分成小段, 並且每段資料都有 HASH 值, 來協助判定傳輸的資料正確性
- P2P 分成兩種方式實現
  1. **tracker**, 固定有一個中心來提供其他使用者的位置與所持有的資源, 壞處是會產生 single point failure
  2. **Distributed Hash Table, DHT** 來實現去中心化網路, 每個節點儲存**部分**資源與其他成員聯繫方式
- DHT 常以 _Kademlia_ protocol 實作,
  - 以 1 個 TCP 來傳輸資料, 1 個 UDP 來溝通
  - 以檔案片段的 Hash Value 來對應 DHT ID, 來決定資料的儲存
  - 使用 DHT ID 以 XOR 為節點距離計算, 並且計算與產生 **k-bucket**
  - 節點搜尋演算法複雜度為 O(logN)
  - 分成四個指令, PING (測試節點存活), STORE (要求儲存資料), FIND_NODE (尋找節點位置), FIND_VALUE (尋找資料)
- 遇到 private IP 時的解法,
  1. NAT 穿透, 通過共用一台公網 proxy 作為轉發
  2. UDP 打洞, 通過一台公網 server 作為協調者

---

### 第五章 - 陌生的資料中心

1 DNS

- **Domain Name System, DNS**, 以 domain name 解析成 IP 的服務
- 必須是高可用性, 高平行處理, 分散式的
- DNS 採用樹狀結構, Root DNS, 頂級 DNS, 權威 DNS
- 並且擁有 cache 機制, 1. 本地端 (`/etc/hosts`), 2. IPS 提供的 DNS server
- DNS 另一個主要功能是作為 **load balancer** 的實現, 可以包含多層的 DNS load balancer 來實現區域性與服務內部的 load balance

2 HTTPDNS

- **HTTPDNS**
  - 不使用傳統的 DNS 服務, 而是以 HTTP 為基礎自定義一套 DNS 服務
  - 客戶端必須使用專用的 SDK 並且可以 fallback 回傳統的 DNS
  - 通常使用在手機網路與移動端 mobile
- 用來解決傳統 DNS 的快取問題與不精準的位置解析
- Cache 模式分成同步與非同步取用和更新
- 同步的 **Cache-Aside** 機制, 客戶端直接讀取資料庫然後才更新快取
- 非同步的 **Refresh-Ahead** 機制, 以 **Guava Cache** 為例包含 **RefreshAfterWrite** 機制
  - **多個**無快取 request 也**只會產生一次** request 到資料庫

3 CDN

- 就近配送的概念,
- 世界各地都部屬快取形成 cluster
- 以分層的概念布置快取的容量與內容
- **Content Delivery Network, CDN**
- 以 CNAME 在 DNS 階層設定, 讓請求指向 CDN 的 DNS server
- 依據請求的 IP 位置, ISP, URL 路徑, 伺服器附載情況來決定處理的伺服器
- CDN 快取的內容以靜態不常變動的資料類型為主, 例如靜態頁面, 圖片, 還有串流資訊 (stream) 等等
- 快取建立的方式有 **pull** (被動拉取) 或 **push** (主動推送), 依據內容的不同而選用
- CDN 除了快取之外, 還可以提供資料前處理, 防盜功能設置 (referer header 或時間戳記)
- 對於動態資料 CDN 也能提供不同的模式來加速,
  - 邊緣計算模式 (edge computing), 在 CDN 節點即提供計算與紀錄, 後續再同步資料
  - 路徑最佳化模式, **Dynamic Site Accelerator, DSA**, 依據路徑來最佳化 TCP 連線

4 資料中心 data center

- 資料中心是一大群的伺服器所組成
- 每個伺服器被放置在 rack (機櫃上)
- 資料中心對外出入口是邊界交換機 Border Router
- 為了實現高可用性 high availability 所有的設備都是以多數個存在
- 路由使用 _BGP_ 協定
- 多個機器需要透過交換機 (Switcher) 連接, 交換機通常被放置在機櫃的最上層 top of rack, TOR
- 機器與交換機所屬的階層被稱為連線層 (Access Layer)
- 每個機器至少擁有兩張以上的網路卡並寫以 bond 的機制綁定, 並且配合 _Link Aggregation Control Protocol_ 實現多個網路卡整合成一個網路卡
- 多個機櫃也需要通過交換機連接, 被稱為匯聚交換機, 形成匯聚層, 多個匯聚層形成二層互通的 Point Of Delivery, POD, Available Zone
- 多個可用區 Available Zone 以核心交換機連接, 形成核心層, 內部以 _OSPF_ 路由協定
- 大二層網路中使用 _Transparent Interconnection of Lots of Link_, _TRILL_ 實現無環溝通
  - 其中的交換機成為 RBridge 以類似 IP 路由的原理實現轉發封包
- 資料儲存, 傳統上使用 **Storage Area Network, SAN** 或 **Network Attached Storage, NAS**
  - 現在多以軟體定義儲存, 實現計算節點融合儲存網路在同一個機櫃上, 提升效率
- 傳統的三層式架構, 連線層, 匯聚層, 核心層是以南北流量, 上下層流動
- 現在更多的數據計算需要在水平流動, 東西流量, 以新架構 Leaf-Spine 網路實現
  - Leaf Switch 與 Spine Switch 更扁平的架構來提升水平擴充與流動能力

5 VPN

- **Virtual Private Network, VPN**
- VPN 為了安全的連結兩地傳訊, 模擬點到點連線
- 包含三種協定類型:
  - 乘載協定, 外部網路通訊時
  - 隧道協定, 外部網路通訊時, 內部資料
  - 乘客協定, 到達目的地後的傳輸
- 以 IP 協定為基礎的 VPN 協定群, _IPsec VPN_
- 為了達成:
  - 私密性 (資料加密)
  - 完整性 (保證資料完整)
  - 真實性 (傳輸身份認證)
- _Authentication Header, AH_ 協定
  - Security Parameter Index,
  - 共通的加密演算法, 雜湊演算法, 封裝模式
  - 生命週期, 存續時間
- _Encapsulating Security Payload, ESP_ 協定
- 通過 **Diffie-Hellman** 演算法交換出 symmetric key
- IPsec VPN 因為是依據 IP 協定, 這種非連線並且每次皆需路徑演算, 因此傳訊速度較慢
- 與 IP 協定同層的 _Asynchronous Transfer Mode, ATM_ 協定
  - 讓封包都走相同路徑, 但是是不完整的協定, 無法正確應對節點失聯時
- _Multi-Protocol Label Switching, MPLS_ 協定, 改善 ATM 協定的弱點
  - 通過標籤的方式, 達到相同路徑
  - 需要配合路由器支援
- 依據 _MPLS_ 實現的 VPN, MPLS VPN
  - 需要與 ISP 申請
  - 配合特殊的 _Multi Protocol BGP, MP-BGP_ 路由協定

6 行動網路

- 由基地台 Mobile Station, MS 接收無線訊號, 然後進行後續的有線處理
- 行動網路粗略流程
  1. 基地台接收無線訊號, 對內發送
  2. 核心元件 (Core Network) 驗證使用者, 流量計價, 協助建立對外部網路通道
  3. 連通手機端到外部網路
- 2G 網路
  - 使用類比訊號網路 **Public Switched Telephone Network, PSTN**, 而非 IP 網路
  - 2.5G 網路, 外部網路擴充支援 IP 網路
- 3G 網路
  - 接收無線訊號 (NodeB) 與轉發內部控制 (RNC) 的系統, 更進步速度更快
- 4G 網路
  - 架構大躍進
  - 接收無線網路與轉發內部控制系統整合成 (eNodeB) 並且速度更快
  - Core Network 把工作分成控制與資料傳輸由不同的元件控制
  - 控制元件 **Mobility Management Entity, MME**
  - 資料元件 **Serving GateWay, SGW** 與 **PDN GateWay, PGW**
  - 對外網路僅剩 IP 網路
  - eNodeB 與 MME 控制層的溝通是建立在 IP 網路, 但是使用非 UDP, TCP 的傳輸層協定 _Stream Control Transmission Protocol, SCTP_
  - _SCTP_ 很多特性更適合用在行動網路上
  - 建立傳輸通道的溝通則是建立在客製化的 UDP 上, _GTP-C_
  - 行動網路溝通是以類似 VPN 的建立概念來協助連線, 因此會有多層協定與通道 (tunnel) 建立
  - **SGW** 屬於接收地的電信業者, **PGW** 屬於提供手機服務的電信業者
  - 由於對外網路是由 **PGW** 所控制, 因此對網際網路連線控制還是由手機服務電信業者提供

---

### 第六章 - 雲端運送中的網路

1 雲端網路

- 應用不需要擁有自己的實體機, 而是更有彈性的虛擬化
- 虛擬化上的網路建立
- 虛擬網卡, 使用 linux 上的 **TUN/TAP** 技術
  - 把網路封包變成字串存入檔案 `/dev/net/tun` 然後再由核心讀取轉發
- 虛擬化網路需要提供的功能
  - 共用, 多個虛擬機共用實體網路卡
  - 隔離, 安全隔離 (無法互相存取), 流量隔離 (流量不互相影響)
  - 互通, 相同使用者所屬的虛擬機應該可以互相溝通
  - 靈活, 靈活的設定提供虛擬機
- 共用與互通,
  - 需要建立虛擬交換機 (switcher)
  - 以 linux 指令 `brctl` 建立橋接器, 實現虛擬交換機
  - 對外連接可以把實體網路卡也接到橋接器 (`brctl`) 上
- 相同區域網路設定會遇到廣播問題與隔離問題
- 因此對外應該使用 **Network Address Translation, NAT** 技術, 轉譯實體網卡與虛擬網卡的 IP
- 並且配合**虛擬 DHCP** 伺服器動態分配 IP
- 隔離問題
  - 以 VLAN 實現, 因此需要支援 VLAN 的實體交換機
  - 配合 `vconfig` 讓虛擬網卡的封包也能帶上各自的 VLAN tag
  - 然而使用 VLAN 有數量上限 **4096** 對於大型虛擬網路來說不夠使用
- 雲端實現通常使用 OpenStack 軟體

2 軟體定義網路 SDN

- **Software Defined Network, SDN** 軟體定義網路
- 以軟體的方式定義中央控制器, 例如 **OpenDaylight**
  - 提供北面介面給應用方
  - 提供南面介面給所有網路設備
- 實現方式 _OpenFlow_, _Open vSwitch_
  - 提供協定與標準, 需要所有的網路設備支援
- **Open vSwitch** 提供虛擬交換機, 內容會包含路由表 route table
  - 以軟體的方式取代實體支援 VLAN 的交換機
  - `ovs-vsctl` 命令介面
  - 對於虛擬交換機而言, 接到所有的封包都可以進行改寫
  - 可以處理 TCP/IP 多個層級, 從實體層 (switcher port), MAC 層 (MAC address), 網路層 (IP address), 傳輸層 (tcp port)
- 利用 **Open vSwitch** 實現 VLAN 的兩種方式
  - access port, 根據 port 綁定特定的 tag
  - truck port, 不綁定, 但是會過濾設定的 VLAN id
- 利用 **Open vSwitch** 實現模擬網路卡綁定交換機, 並且允許 load balancing
- **Open vSwitch** 包含兩個主要處理程序 **OVSDB** 處理虛擬交換機設定資訊, **vswitchd** 處理路由表
  - 與 linux OS kernel 通過 Netlink 與核心路由表互動
- 雲端運算中隔離與管理
  - 傳統的 VLAN 作法是需要配合實體 VLAN 交換機, 並且設定 VLAN 需要綁定虛擬橋接器 (bridge), 實體綁定虛擬沒有彈性不好管理
  - 使用 **Open vSwitch** 全部使用軟體定義模擬, 等同於在實體交換機上面建立一個虛擬交換機的軟體中間層, 解除實體 VLAN 設定與虛擬機的綁定

3 雲端網路安全

- 設定好 **Access Control List, ACL** 關閉無用的 port, 設定特定 IP, ...
  - 特定的設定形成安全組, 可以直接把虛擬機加入安全組來採用預先的設定
  - 最常用的方式是使用 `iptables` 實現
- `iptables` 是 linux 的使用者介面, 與核心的 `ip_tables` 模組對應
  - 內容包含 raw 表, mangle 表, nat 表, filter 表
- 處理 TCP/UDP 層的內容, 實現 **conntrack** (連線追蹤紀錄), **mangle** (修改封包), **nat** (IP 轉址), **filter** (過濾)
- 向下 IP 層, linux 核心通過 **Netfilter** 架構
  - 對於 IP 層的處理分成五個狀態 **PREROUTING**, **INPUT**, **FORWARD**, **OUTPUT**, **POSTROUTING**
  - 每個狀態都可以通過 Netfilter 植入 hook function 進行決策 **ACCEPT**, **DROP**, **QUEUE** (丟給其他使用者自訂處理程序客製化處理, 例如實現 load balance)
- 通過以上功能讓 `iptables` 擁有強大的設定過濾能力 (**filter 表**)
  - 關閉所有 IP
  - 開放特定 IP 連結特定 port 號
- 基於 `iptables` 使用 NAT 功能, (**nat 表**)
  - 對應虛擬 IP 與公網 IP, 讓封包能轉發到正確的虛擬機上
  - 底層以 C++ 實現 hash linked list 結構儲存連結與對應

4 雲端網路的 QoS 流量隔離

- **Quality of Service, QoS** 服務品質
- 控制網路兩個方向
  - **Ingress** 入口的 **Policy** 過濾政策
  - **Egress** 出口的 **Shaping** 流量控制
- linux 下的 **traffic control, TC** 工具, `tc`
- 出口流量控制的兩種方式
  1. 無類別排隊規則 **Classless Queuing Discipline**
  2. 有類別排隊規則 **Classful Queuing Discipline**
- 無類別排隊規則有三種方式
- 不分類的 3 個先進先出 queue, **3 Band FIFO queue**
  - 依據 TOS 的類別排進 3 個 queue 之中, 3 個 queue 有優先順序之分
- 依據 hash 值的隨機公平序列 (**Stochastic Fairness Queuing**)
  - 依據 hash 值放入平等的 queue 中再以 polling 的方式取出發送
- **Token Bucket Filter**
  - 單一 queue 但是必須持有 token 者才發送
  - 以控制 token 數量與生產速度來控制流量
- 有類別排對規則
- 最常見的 **Hierarchical Token Bucket, HTB**, 以樹狀結構分支 class 的流量控制方式
  - HTB 的特性是分支的流量控制, 可以借用讓沒有流量的分支能把流量借出給其他分支, 因此可以時時刻刻達到最大流量
- 雲端可以配合 **Open vSwitch** `ovs-vsctl` 在虛擬交換機上建立 **HTB** 來控制各個來源的出口流量

5 雲端網路的隔離 GRE, VXLAN

- 當 VLAN 因為數量上限而不夠使用時, 應該如何處理隔離問題呢,
  - 希望分離實體網路與雲端網路
  - VLAN 只有 12 bits 上限為 4096 個
  - 以隧道技術實現包裹協定來解決問題
- 以實體網路組成的網路稱為 **Underlay 網路**, 虛擬機氣與雲端技術組成的網路稱為 **Overlay 網路**
- **Generic Routing Encapsulation, GRE** 通用網路封裝
  - 一種 IP-over-IP 的隧道技術支援 key 32 bits 欄位
  - 點到點建立隧道, 因此在廣播時會讓隧道數量以指數上漲
- VXLAN
  - 在第三層加上 VXLAN header ID 為 24 bits 欄位
  - 每個實體機上都有 **VXLAN Tunnel Endpoint, VTEP** 進行管理
  - 支援多點傳輸, 如同一般的路由器行為, 只是建立在虛擬層上
- 雲端網路上以 **Open vSwitch** 實現, 支援 **GRE**, **VXLAN**, **IPsec_GRE**
  - 透過虛擬路由器建立 tunnel 管理, 提供虛擬機器與實體機器之間網路的轉換

---

### 第七章 - 容器技術中的網路

1 容器網路

- Container 容器
- 雲端運算解決了基礎資源層的虛擬化 (IaaS)
- PaaS 層的批次處理與快速部屬問題則由 container 技術虛擬化實現, 相比雲端基礎設施隔離性沒有這麼好
- 把容器視為貨櫃需要兩樣東西 1. 如何包裝 2. 標準是什麼
- 包裝方式使用
  - namespace (名稱空間)
  - cgroup (資源限制)
- 標準則是容器映像檔 (image) 是儲存狀態並且可以完整的搬運到各個平台
- **namespace**
  - 以 namespace 隔離網路設定, 建立出多個網路設定如同多個網路設備一般
  - 在 linux 系統網路設定的 namespace 可以由 `ip netns` 指令實現
  - 以網路 namespace 建立虛擬路由器, 包含開啟 forward, 設定 iptables, 開啟 NAT, 建立網路卡, 分配 IP, 建立路由表
- **cgroup**
  - **Control Group, cgroup** 是 linux kernel 提供用來限制, 隔離使用程序的資源
  - 能夠控制 **CPU**, **cpuset** (多核心), **memory** (記憶體), **blkio** (區塊裝置), **net_cls** (網路)
  - 以 cgroup - net_cls 配合 `tc` 使用
  - 以掛載檔案系統的方式建立
- Docker 網路, 執行 Docker 每個 container 會產生一個虛擬的網路卡
  - 並且整體 Docker 會共用一個 bridge
- linux 系統下以建立 **veth pair** 網路卡的方式來連動 Docker 內的虛擬網路卡
- Docker 啟動時會產生對應的 **namespace** (預設是 **pid**)
- 對外連線 Docker 預設使用 NAT 模式, 分別使用 SNAT 與 DNAT 來對應存取方向
  - **iptables** 會有 NAT 規則
- Docker 實現實體機與容器內的 port 對應方式
  1. 通過 **docker-proxy** 直接轉發
  2. 通過 DNAT 在實體機 iptables 設定上加上把實體機 port DNAT 對應到 docker 內部網卡

2 容器網路上的跨實體解決方案 Flannel

- Docker 每台實體機啟動後會預設分配 IP **172.17.0.0/16** 每個容器都會被分配到一個
  - 並且所有的容器會共用 docker0 作為 bridge, 因此單台實體機內的所有容器能任意互相溝通
  - 遇到分散式平行處理問題, 單台機器有能力上限, 因此需要分散式架構
- **Kubernetes** 提供管理多台實體機多個容器的服務
- 遇到跨實體機的通訊問題
  1. 容器之間如何知道對方在哪
  2. 跨實體機的容器之間要如何溝通
- 以中央管理, 每個實體機與容器進行註冊的方式讓容器之間能知道對方在哪
- 跨實體機容器的溝通解決方案之一 **Flannel**
  - **Flannel** 會分配給各實體機不同的網段來避免 IP 衝突, 以 **172.17.0.0/16** 下做切割
  - 方法一, 以 UDP 實現 Overlay 網路機制
  - 方法二, 利用虛擬機器的經驗, 使用 **VXLAN** 在 flannel 虛擬網卡上建立 **VTEP**
  - **VXLAN** 方法效能較好

3 容器網路上的跨實體解決方案 Calico

- 由於 Flannel 讓各實體上的容器仍有不同的 IP 位置, 因此可以直接設定路由規則來通訊
- 概念上直接使用實體 switcher 做連接, 不使用虛擬化的 Overlay 網路, 而是實體層路由
- 取消使用 **docker0 bridge** 而是使用 veth pair 進行連動實體網卡, 在實體機上產生路由器能力 as router
- Calico 架構元件
  - **Felix**, 在每個實體機上使用 Felix 作為 agent 自動處理路由設定
  - **BGP Speaker**, Calico 使用 BGP 作為路由設定
  - **BGP Route Reflector**, 由於是一對一路由設定, 因此在節點變多時會過多路由資訊, 因此以 Route Reflector 中間管理
  - 安全性管理 Network Policy, 一樣使用 **iptables**
- 然而 Calico 原先概念是建立在 switcher 上, 即同個區域網路上, 如果要跨網域連接則會出現問題
  - 以隧道模式解決, **Calico IPIP 模式**

4 RPC 服務間的遠端呼叫

- **Remote Procedure Call, RPC** 遠端服務間的呼叫
  - 實現如同呼叫本地端 function 一般的使用遠端服務
- 分散式系統中服務之間互相呼叫, 底層都是使用 socket 標準
- 然而跨網路間的呼叫與標準需要面對多個問題
  1. 遠端呼叫的語法標準
  2. 如何傳遞參數
  3. 表示資料的標準
  4. 網路錯誤時的處理
  5. 如何讓其他遠端服務知道
- 1 遠端呼叫語法, 2 如何傳遞參數, 3 資料表示標準, 問題集合稱為協定約定問題
- 4 網路錯誤時的處理, 稱為傳輸協定問題
- 5 如何知道遠端提供服務, 稱為服務發現問題
- 依據 Implementing Remote Procedure Calls, Bruce Jay Nelson 的論文標準化的 RPC 架構
  - Client side 與 Server side 都分別擁有 **Stub** (解決問題 1,2,3) 與 **RPCRuntime** (解決問題 4)
- 最早期的 RPC 實作為 Sun 的 **ONC RPC** 並且被使用在 **Network File System, NFS** 上, 跨網路的存取檔案系統
- 問題 4 的網路傳輸協定問題中,
  - 如同 TCP 的設計會以 queue, 壅塞視窗的方式解決, 連接失敗, 重試, 發送失敗, 逾時等問題
  - 並且會實現非同步執行, 因此會由複雜的狀態機來記錄狀態
- 問題 5 的服務發現問題,
  - 在 **ONC PRC** 中以 **portmapper** 解決, 即註冊服務管理

---

### 第八章 - 微服務相關協定

1 SOAP 協定

---

### 第九章 - 網路通訊協定知識串購

---
