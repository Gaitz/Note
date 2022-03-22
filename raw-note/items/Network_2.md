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
-

---

### 第六章 - 雲端運送中的網路

---

### 第七章 - 容器技術中的網路

---

### 第八章 - 微服務相關協定

---

### 第九章 - 網路通訊協定知識串購

---
