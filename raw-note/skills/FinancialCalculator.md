## Financial Calculator

### Investment

---

計算功能

- 數學運算
- 四則運算
- 百分比 %
- 排列數, 組合數
- 平方, 平方根, 倒數
- 階乘, 自然對數
- 隨機數
- 三角函數, 反三角函數, 雙曲函數, 反雙曲函數

`2ND` 第二功能按鍵

記憶功能

- 10 個記憶空間
- `STO` 儲存 (store)
  - 與儲存值進行運算
- `RCL` 讀取 (recall)

常數計算

工作表

- TVM 工作表, `N`, `I/Y`, `PV`, `PMT`, `FV`, `P/Y`
- 分期付款工作表, `AMORT`
- 現金流工作表, `CF`
- 債券工作表, `BOND`
- 折舊工作表, `DEPR`
- 統計工作表, `STAT`
- 變化百分比, 複利工作表, `delta%`
- 利率轉換工作表, `ICONV`
- 日期工作表, `DATE`
- 邊際利潤工作表, `PROFIT`
- 損益平衡工作表, `BRKEVN`
- 儲存記憶體工作表, `MEM`

---

貨幣的時間價值和分期付款工作表

Time-Value-of-Money (TVM) 與 Amortization worksheet

- 分析均勻現金流 (equal and regular cash flows), 並且試算分期付款計劃
  - 單一利率的複利計算, 每期收入支出相同, 計算期間沒有中斷
- 多用於 Annuity 年金

變數

- 用於 Time-Value-of-Money worksheet
  - `N` 期數, Number of periods
  - `I/Y`, 年利率, Interest rate per year
  - `PV`, 現值, Present value
  - `PMT`, 付款額, Payment, 每期付款額
  - `FV`, 終值, Future value
  - `P/Y`, 年付款次數, Numbers of payments per year
  - `C/Y`, 年複利計算次數, Number of compounding periods per year
  - `END`, 期末付款, End-of-period payments
  - `BGN`, 期初付款, Beginning-of-period payments
- 用於 Amortization worksheet
  - `P1`, 第一筆付款所屬期數, Starting payment
  - `P2`, 最後一筆付款所屬期數, Ending payment
  - `BAL`, 餘額, Balance
  - `PRN`, 已付本金, Principal paid
  - `INT`, 已付利息, Interest paid

其他常用按鍵

- `RESET`, 重置工作表, 需要按 `ENTER` 確定執行
- `xP/Y`, 乘上每年付款次數, 協助計算以年為單位的乘算付款次數
- `2ND` `AMORT` 進入分期付款工作表
- 使用 `CPT` 計算 `PMT` 每期付款金額, `N`, `I/Y`, `PV`, `FV`

期末付款, 期初付款

- 判斷方式通常以第 0 期是否需要付款為基準
- `END`, 期末付款, 普通年金, 大多數貸款都屬於普通年金
- `BGN`, 期初付款, 期初年金, 大多數租賃都屬於期初年金

`P1`, `P2`

- 設定下一個付款期間的範圍
- 設定完後按下 `CPT` 計算
- `P1`, `P2` 設定需要配合 `ENTER` 確定設置

現金流

- 收入, 現金流流入, 正值
- 支出, 現金流流出, 負值

---

現金流工作表

---

債券工作表

---

折舊工作表

---

統計工作表

---

其他工作表
