## 深入淺出網路管理

### BOOK resource, ComputerScience/Network

---

第一章 - 修理實體網路

第二章 - 規劃網路布局

第三章 - 工具與問題排除

第四章 - 封包分析

第五章 - 網路裝置與流量

第六章 - 使用選徑器連接不同的網路

第七章 - 選徑協定

第八章 - 網路名稱系統

第九章 - 監測與排除問題

第十章 - 無線網路

第十一章 - 網路安全防護

第十二章 - 設計網路

第十三章 - 遺珠與附錄

---

### 第一章 - 修理實體網路

- CAT-5 網路線, Ethernet Category 5
  - 8 條線, 絞成 4 對
  - 無遮蔽 unshielded 雙絞線 twisted pair, UTP
  - 橙色: 上傳, 綠色: 下載
  - 有白色: 正極, 原色: 負極
  - 藍色與棕色暫無功能, 未來擴充使用
- RJ45 接頭 = 8P8C 接頭 (8 positions, 8 contacts)
  - 顏色順序標準, 都是白色+原色
  - 568A 標準, 順序為: 綠 橙 藍 棕
  - 568B 標準, 順序為: 橙 綠 藍 棕
  - 重點是網路線的兩頭必須使用相同的標準
- 實體網路線外皮會有顯示規格
- 頻寬 Bandwidth, 一次傳輸的量
- 網路速度 Speed, 單位時間內傳輸的量 (速度)
- 網路線各標準有不同的長度上限
- 同軸纜線
  - 一股銅線
  - 使用 BNC 接頭 (Bayonet Neil Concelman)
  - T 型接頭, 終端接頭, 末端接頭, 耦合接頭
- 同軸網路 RG-62
  - 單一匯流排 (bus) 與多個節點 (node) 組成
  - 逐漸被淘汰的網路方式
- 網路拓樸 (network topology) 結構圖
- 網路訊號使用電子傳遞
- toner-tracer 儀器, 來檢測同軸網路線是否正常, 尋找斷路點
  - toner 發出訊號
  - tracer 檢查訊號
- 光纖, 通過光線來傳送資訊而非電子
  - 擁有不只一種規格的接頭與對應的插座, ST straight tip, SC subscriber connector, LC lucent connector
  - 過度彎曲會造成光纖纜線產生裂縫導致資料無法傳輸
  - 需使用熔接器 (fusion splicer) 維修光纖網路線
  - 接頭連接方式有 pre-built 或 環氧樹脂連接磨平
- 光纖形式
  - 單模 single mode, 只能使用雷射光源, 單條路徑, 價格高性能佳, 距離 10-100km, 速度 14 Tbit/s
  - 多模 multi mode, 使用雷射或 LED 光源, 多條路徑, 價格相對低, 距離 2000m+, 速度 10 Gbit/s

---

### 第二章 - 規劃網路布局

1. 列出需求 (設備與位置)
2. 取得地區平面圖避開障礙物或干擾物
   - 避開水, 熱, 震動, 其他電線
3. 設計時可以適當的預留
4. 列出所需的網路設備與其他理線硬體
5. 放置網路線

- 理線硬體
  - J 形掛勾 J-Hook
  - 纜線保護蓋 Cable protector
  - 纜線架 Cable tray
  - 纜線槽 Raceway
  - 纜線束帶 Cable tie
  - 塑膠浪管 Smurf tube
- 各種不同的設備線路貼上標籤
- 使用束帶理線
- 使用配線板 patch panel 理線
- 沖壓工具 打線

---

### 第三章 - 工具與問題排除

- toner-tracer 無法檢視連線品質
- 除了線路本身之外也有接頭或接錯線路等問題
- 多用電錶 multimeter 可以檢查到電壓與電阻等數值, 有分成數位與類比兩種類型
  - AC voltage 交流電電壓 伏特
  - DC voltage 直流電電壓 伏特
  - current 電流速度
- 電阻 resistance (ohm)
- 示波器 oscilloscope 可以檢查即時的電壓 voltage 伏特變化
  - 用來檢查訊號是否有雜訊
  - 纜線中是否有對絞對於雜訊移除是至關重要的, 必須確保
  - 訊號是以高壓 1 及低壓 0 組成
  - 交流電會以固定的頻率 (Hz) 切換
- 邏輯分析儀 logic analyzer
  - 會轉譯訊號成為邏輯訊號 0, 1
  - 電壓變化不夠大時, 不會成為邏輯訊號
- 區域網路分析儀 LAN analyzer
  - 等同於示波器 -> 邏輯分析儀 -> 顯示 frame 封包欄位

---

### 第四章 - 封包分析

- 電壓訊號 -> 邏輯訊號 0, 1
- 電壓訊號配合時序 clocking 讀取出邏輯訊號
- Manchester 相位編碼法
- Non-Return Zero, NRZ 編碼
- Network Interface Card 網路卡負責編碼工作
  - MAC address 被寫入在網路卡的 ROM 裡
- Ethernet 協定使用 Manchester 編碼法
  1. 訊號使用 Non-Return Zero 編碼 + clocking 訊號 = Manchester 編碼
  2. 通過使用 Ethernet 協定的纜線傳輸
  3. 到達另一台電腦的網路卡解碼
- 資料編碼法有很多種, 擁有不同的特性
- 網路協定只是用特定的幾種編碼法, 例如 Manchester 與 NRZ
- Ethernet 協定是由 IEEE 協會制定
  - 不同的設備擁有的編碼速度不同, 越新的速度越快
  - 10 mbps, 100 mbps, 1000 mbps, 10 Gbps, ...
  - 不同速度的設備使用的編碼系統有所不同從 4B5B 到 8B10B 電纜線中的四條都使用到
  - 編碼語解碼機制直接實作在網路卡硬體上, 而不需要電腦本身介入
- American Standard Code for Information Interchange, ASCII code 把字母編碼成數字
- Unicode 是另外一種字母編碼成數字的標準
- bit 與 byte
  - 8 bit = 1 byte = 2 nibble 可以以兩個 16 進制表示
  - 4 bit = 0.5 byte = 1 nibble
- 16 進制, 由於 2 進制可以快速地換成 16 進制
  - 而 16 進制更接近 10 進制, 可以協助人類判別
  - 1 byte 分成 2 個 nibble 分別轉換成 16 進位 concat 時也等同於原本的 16 進制表示
- package (資料包) 與 frame 中的 packet (封包)
- frame 所包含的資料為
  - Preamble 同步訊號, 7 bytes
  - Start of Frame, 1 byte
  - Destination MAC address, 目的地 6 bytes
  - Source MAC address, 來源 6 bytes
  - Ethertype, 標明封包類型 2 bytes
  - Payload (packet, 封包), 內容
  - Cyclic Redundant Check, CRC, 校正碼 4 bytes
- MAC address 在電腦上可以通過 `ipconfig/all`, `sudo sbin/ifconfig -a` 查詢得到
- MAC address 是燒錄在網路卡的 ROM 上, 偽造 MAC address 需要額外的設備並且多數時是有法律限制的
- MAC address 目前總數上限為 24^8 個
- frame 是 nested structure 針對不同的協定進行 pack 與 unpack
  - 例如 UDP 封包, ICMP 封包, TCP 封包
  - 目前 IP 協定的封包種類大約 139 種
- 一個 Ethernet 的 frame 一次所可以傳送的長度上限是固定的, 因此過多的資料會被分割成多個 frame 傳送
  - 因此 IP 協定中分成 UDP 與 TCP
  - 效能與可靠度
  - TCP 可以保證封包順序與不遺失, 重送等等, 依據 sequence number
  - 依據封包中的 port number 決定接收的應用程式為誰

---

### 第五章 - 網路裝置與流量

- 除了電腦網路卡擁有 MAC address 之外, 其他路徑上的網路設備也都會擁有 MAC address
  - 例如 switcher, router
- local area network, LAN, intranet 內部網路
- wide area network, WAN, internet 外部網路
- Internet 網際網路, internet 互聯網 (至少兩個 intranet 連接形成), intranet 內部網路
- hub 集線器又稱為 repeater, 無智能, 僅用於廣播訊號, 轉發至所有的 port, 不會改寫任何的內容
- switcher 交換器, 具有智能 (CPU, RAM, ...), 只會轉發到指定的 port, 會記錄 MAC address 對應到的 port 產生 port address table 來傳送到指定的位置
  - 可以通過電腦連進 switcher 中以指令的方式顯示出 port address table
- 使用軟體監聽封包, 例如 Wireshark 即 protocol analyzer
  - 監聽 inbound 與 outbound 訊息
  - 在電腦中安裝 Wireshark 並且連一條纜線至 switcher 就可以利用 Wireshark 監聽 switcher 上的封包
- Router 選徑器
  - 也會有自己的 MAC address
  - Router 裡的所有設備可以形成 IP 子網路
  - 具有智能可以解析 IP
  - 通常的 port 數量較少, 大多時候負責只負責連接 hub 或 switcher

---

### 第六章 - 使用選徑器連接不同的網路

- 以 Router 連接兩個不同的網路, 例如 LAN 與 WAN
  1. 以實體連線
  2. 以邏輯連線, 即設定 config
  - 可以藉由訪問 router 管理介面取得有用的資訊與 configuration
- MAC address 與 IP address
  - Ethernet, MAC address 每個設備擁有一個專屬的
  - TCP/IP, IP address, IPv4 由 4 個 bytes 組成, 包含了網路位置與主機位置 (由 subnet mask 子網路遮罩決定), 在相同網路 (例如 LAN) 中傳輸 IP 只有主機位置不同
  - subnet mask 子網路遮罩, 由 255 與 0 組成, 255 的部分為網路位置, 0 的部分為主機位置, IP 位置與子網路遮罩以邏輯 AND 計算出網路位置
  - 範例: `192.168.100.0/24`, 24 代表前 24 個 bits 為網路位置, 即前 3 bytes 為網路位置後 1 byte 為主機位置
  - 為了提供更大的網路 IP 數量, 所有的設備慢慢從 IPv4 標準移動到 IPv6 標準
- Ethernet 網路每個接收發送裝置都必須有 MAC address
  - 從 Ethernet 的角度只要有 MAC address 就能傳送 frame
- 對於 TCP/IP 協定來說必須擁有 IP 才能傳送 packet
  - Internet 而言必須擁有 IP 才能傳輸, 但是有分成 public IP (routable) 與 private IP
  - private IP 是外部 router 無法涉及的網路
  - TCP/IP 中以 RFC 1918 標準說明可以設置 private address 的範圍
  - public IP 需要由 ISP 給予
  - 而 ISP 所擁有的 IP 是由全球五個組織分別負責不同的區域 region,
  - ARIN 北美, RIPE NCC 歐洲, APNIC 亞洲+大洋洲, LACNIC 拉丁美洲, AfriNIC 非洲
- 以 Wireshark 或其他 packet sniffer program 查看封包紀錄
- switcher 只會處理 MAC address, router 才能處理 IP
  - switcher 只辨認 MAC address 來傳輸, 因此只能作用於單一的網路內
  - router 會解開 frame 取得 packet 來取得 IP 傳輸
- Address Resolution Protocol, ARP 協定
  - TCP/IP 網路上需要查詢 IP 位址裝置的 MAC address
  1. 電腦通過 ARP 協定詢問 switcher 指定 IP address 的 MAC address
  2. switcher 以廣播的方式轉發 ARP 請求
  3. 指定的 IP address 裝置回傳 MAC address 給 switcher
  4. switcher 回傳 MAC address 給請求的電腦
- 為了要讓 frame 可以在不同的網路中傳送必須設定 router 來協助跨網路傳輸
  - 設定 default gateway 即指定的 router IP
  - TCP/IP 跨網路傳送由 ARP 請求開始從 IP address 取得 MAC address (可處理對外連接的 router)
  - 帶著資料傳送到 MAC address (router) 時, router 會依據 IP 以 ARP 去查詢 MAC address 然後轉發至指定的 MAC address
  - 即依據 TCP/IP 的封包傳送是藉由多個 router 協助轉發的並且 router 在傳送時會修改 frame 的 MAC address

---

### 第七章 - 選徑協定

- router 除了可以協助連接兩個以實體連接的網路之外
- router 可以通過指令查詢 ip route table
  - 告知我們目的地 IP 與如何連線經過其他的介面 IP 或者直接連線得到, 以及使用到的 router 介面 (router 上的實體連線) 為誰
  - 路徑表的開頭代號代表這個目的地 IP 連線紀錄是如何新增到表裡的, 例如 C 直接連線取得, S 手動新增靜態路徑
  - 除了可以直接連接的 IP 區塊之外, router 要設置目的地 IP 連線到其他實體連線的 router 上來協助轉發
- 排除不良路徑
- `ping` 指令, 直接測試連線到指定 IP, 實際是以 ICMP 協定完成
  - 會被防火牆阻擋
  - 可以稍微了解常見的延遲時間, 來判斷連線是否正常
- `traceroute` 指令, 追蹤封包移動到指定 IP 上所有的路徑
  - router 可以設定成不回應 ICMP 請求
  - `*` 代表沒有回應
- Nmap 軟體用來定期掃描 (ping) 網路位置 (IP), 例如 port scan, 作業系統偵測, 等等功能
- router 上設定的 static route 靜態路徑是不會自動更新的
- 動態路徑協定 Routing Information Protocol, RIP
  - router 之間會固定時間自動發送 RIP 請求來查看是否更新
  - 設定方式是在 router 對註冊的 router 開啟 RIP
  - 大規模的變動路由變動會需要長時間才能達到所有的 router 都更新完成 (收斂較慢)
  - RIP 協定可能有資安問題要注意, 例如惡意的 router 傳送惡意的更新
  - RIP 路徑是以最少所需跳躍點數量 (hop-count) 來決定, 但是不考量路徑速度, 並且跳躍點數量有上限超過則無法連線
  - 因此 RIP 僅適合用於小型網路
- 路徑協定還有其他的標準, 例如 OSPF (open shortest path first), IGRP, EIGRP, BGP (border gateway protocol)
  - 如果 router 都是 CISCO 時可以使用 EIGRP
  - 需要跨牌支援時推薦使用 OSPF
  - 不會變化的網路可以使用靜態路徑表 static route
- EIGRP 協定,
  - HELLO 封包,
  - Diffusing Update Algorithm, DUAL
  - Reliable Transport Protocol, RTP

---

### 第八章 - 網路名稱系統

- domain name, 網域名稱, _yahoo.com_
- hostname, 主機名稱, 範例: _www_
- fully qualified domain name, FQDN
- domain 管理機構為 ICANN
- 向頂層網域註冊商購買 domain
- Domain Name System, DNS, 網域名稱系統
  - 提供網域名稱與機器位置 IP 的對應服務
  - 階層式解析, 由 top level domain 開始轉導到特定的 DNS server (domain name 的最右側開始解析)
- 除了使用網域註冊商提供的 DNS 外, 也可以自行架設 DNS server 來管理自己的 domain name
  - 自架優點: 自由度高, 可立即修復; 缺點: 額外的管理與成本
- DNS server, 範例 _BIND_
  - 以 `dig` 指令查詢 DNS 紀錄資料
  - 可以在 DNS level 實現 load balancing
  - zone file, DNS 區域檔案, 記錄檔閱讀方式應該從底部往上看
- Reverse DNS, 反向 DNS, 以 IP 查詢 domain name
  - 可以作為電子郵件伺服器作為垃圾信來源過濾的工具, 只允許來自認可來源的信
  - 以 `dig -x` 指令查詢
  - 為了讓我們的 DNS server 可以回應 reverse DNS 詢問, 需要在 zone file 裡設定

---

### 第九章 - 監測與排除問題

- `ping` 預設閘道 IP (router) 檢查連線問題
- `ssh` 進 router, 以 `show` 指令檢查 router 上的紀錄
- 以 `ping` 指令檢查任何具有 ip 位置的網路設備, 可以有效的檢查連通性問題 (connection)
  - ping 成功, 可以查看延遲時間是否正常
  - ping 失敗, 可以縮小範圍到能連得到的位置
  - ping 失敗, 開始檢查實體線路與接頭
  - ping 遇到關閉 ICMP 協定的設備時會顯示 timeout
- `show interface` 指令, 適用於各個網路設備, 提供綜合資料協助檢查
  - `show` 其他相關用法, `show ip traffic`, `show ip route`, ...
- 無法使用 `ssh` 或 `telnet` 時
- Simple Network Management Protocol, SNMP, 簡單網路管理協定, 具有多個 version
  - Management Information Base, MIB, 寫死在硬體裡的資訊
  - 需要對各網路設備開啟與設定 SNMP
  - 開源軟體 _Nagios_, _MRTG_, 可以協助管理
  - 需要配合協定標準來查看所需的值
- _syslogd_, (tcp _514_ port), daemon, 設置在每個網路設備上, 讓錯誤資訊的 log 回傳到統一的伺服器上
- 在 _syslogd_ 伺服器上做 monitoring 與 alert
- 事件優先等級順序,
  - 電壓問題, 溫度過高, 記憶體錯誤, 介面更動重啟, 網路錯誤率過高
  - 流量過高
  - 溫度過低, 無法連線至某一個網站, 流量過低

---

### 第十章 - 無線網路

- access point, AP, 連接基地
  - wireless hotspot 無線熱點
- 通過無線電波而非 Ethernet 纜線
  - 因此要注意無線電波可能受到的干擾與阻擋, 以及活動範圍
- Network Attached Storage, NAS, 網路附接儲存裝置
  - 以網路連線來存取的儲存裝置
- 為所有無線連網設備設置動態 IP 才可以正常地連線
- Dynamic Host Configuration Protocol, DHCP
  - 自動配置 IP
  - `DHCP Discovery` packet -> DHCP server -> `DHCP Offer` packet
  - `DHCP Request` packet -> DHCP server -> `DHCP Acknowledgement` DHCPACK packet
- client-side 用戶端設備在 TCP/IP 網路設定上把 IP 獲取選用自動即啟用 DHCP
- server-side 即無線 AP 上啟用 DHCP 服務或者自行設置 (起點 IP, 終點 IP, 存續時間)
- Network Address Translation, NAT, 網路位置轉譯服務
  - 以 Proxy 解決, public IP 不夠分配的問題
  - 有些 AP 會預設啟動 NAT 服務
- 所有網路相關的標準都找得到 RFC 文件來查詢
- 無線網路協定有多個版本, 但是彼此之間不一定相容, 因此需要確保用戶端與伺服器端都能提供相同的標準
  - 標準之間差異在於連線速度與連線範圍, 一般來說越新的標準能提供更快的速度與更大的使用範圍
  - 802.11n - Wifi 4, 802.11ac - Wifi 5, 802.11ax - Wifi 6
- port mapping 讓外部網路可以連結到內部無線設備
  - 類似反向代理 reverse proxy
  - 需要在 AP 上設定 port mapping, 以 NAT 方式設定 UTP 與 TCP 對應的 port mapping 和 service
- 無線設備連線安全問題
  - 以註冊 MAC address 來限制連線設備
  - 以 WEP, WPA, RADIUS 協定以密碼方式驗證

---

### 第十一章 - 網路安全防護

- 強化 switcher, 避免 MAC address 假冒, ARP 下毒
- 強化 router, 啟用 Access Control List 與 Port Security
- 安裝防火牆 firewall
- 撰寫與執行安全政策, 降低社交工程的成功率
- Cracker 假冒 MAC address 來騙取網路設備的信任
  - 防禦: 重新設計網路拓樸, 把重要的伺服器的 switcher 設置在單一個 router 後面, 單一閘道受信任的實體設備
  - switcher 處理的是 MAC address 因此容易受到假冒 MAC address 攻擊, router 則是使用 IP 因此不受影響
- Address Resolution Protocol, ARP 下毒,
  - 以不存在或假的 MAC address 發送一個帶有 IP 的封包, 然後感染 ARP table
  - 可以用來實現 DoS, Man in the middle, MAC flooding 攻擊
  - 防禦: 針對 router 設置綁定實體 port 與固定的 MAC address, 以 MAC address 限制
  - 防禦: 以 intrusion detection system, IDS 偵測網路中不正常的 ARP request
- Router 是區隔 WAN 與 LAN 的位置, public vs private
  - 讓外部網路任意地通過 router 就代表攻擊者直接可以出現在內網中
  - 防禦: 在 router 上開啟權限管理, 使用 Access Control List, ACL, 控制指定的 IP 才能通過, 以 IP 限制
- 硬體型防火牆與軟體型防火牆 firewall
  - 以 packet 限制, 分別限制 inbound 與 outbound
  - static packet-filtering 靜態封包過濾, 依據 packet header
  - stateful packet-filtering 狀態式封包過濾, 依據 packet header 與過去的紀錄 (狀態表)
- Social Engineering 社交工程, (騙子)
  - 防禦: 建立實際的安全政策與執行, 人員的權限管理

---

### 第十二章 - 設計網路

1. 網路需求探索, 訪談與需求收集
2. 繪製實體網路布局
3. 查看建築物藍圖並且依據藍圖修改實體網路布局
4. 列出所需的網路設備清單
5. 繪製邏輯網路圖, 配置 IP 到各個設備
   - 如果需要可以使用 router 做子網路切割
6. 建立執行計畫: 網路設備採買, 安裝人員, 安裝時間, 安裝順序
7. 執行計畫

---

### 第十三章 - 遺珠與附錄

- TCP/IP stack
- Virtual Local Area Network, VLAN
  - 配合 router 區隔網路的方式之一, 提高安全 (權限管理) 與效能 (廣播範圍)
- CISCO Router 模擬軟體與證照認證
  - CCNA 初級網路認證
  - CCNP 進階網路認證
- Border Gateway Protocol, BGP, 建立大型網路的 routing protocol 之一
- Virtual Private Network, VPN,
  - 虛擬的內部網路, 通過加解密資料來保護安全性
- Intrusion Detection System, IDS, 入侵偵測系統
- 安裝 BIND

---

487
