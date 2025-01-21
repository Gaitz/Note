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

- 設定顯示位數
  - `2ND` `FORMAT` 設定 `DEC`
- `RESET`, 重置所有工作表, 需要按 `ENTER` 確定執行
- `CLR WORK`, 在指定工作表中使用, 只重置特定工作表
- `CLR TVM`, 重置 Time-Value-of-Money 工作表

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
  - `FV` = `PV` \* (1 + `I/Y`)^`N`
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
- 自動計算取得付款區間的 `BAL`, `PRN`, `INT`

現金流

- 收入, 現金流流入, 正值
- 支出, 現金流流出, 負值

---

現金流工作表

Cash Flow Worksheet

- 用於非均勻現金流問題
  - 時間間隔相同, 但是每次的流入流出金額不同

變數

- `CF0`, 初始現金流, Initial cash flow
- `Cnn`, 第 n 筆現金流, Amount of nth cash flow
- `Fnn`, 第 n 筆現金流頻率, Frequency of nth cash flow
- `I`, 折現率, Discount rate, 每期利率
- `NPV`, 淨現值, Net present value
- `NFV`, 淨終值, Net future value
- `PB`, 回收期, Payback
- `DPB`, 折現回收期, Discounted payback
- `IRR`, 內部報酬率, Internal rate of return
- `RI`, 再投資利率, Reinvestment rate
- `MOD`, 修正內部報酬率, Modified Internal rate of return

常用按鍵

- `CF` 進入 Cash Flow 工作表
- `NPV` 進入查詢計算值 `I`, `NPV`, `NFV`, `PB`, `DPB`
- `IRR` 進入查詢計算值 `IRR`, `RI`, `MOD`
- `INS`, 插入現金流
- `DEL`, 刪除現金流

現金流數量限制

- `C01` - `C32`, 最多 32 個

現金流

- 收入, 現金流流入, 正值
- 支出, 現金流流出, 負值

---

利率轉換工作表

Interest Conversion Worksheet

變數

- `NOM`, 名目利率, Nominal rate
- `EFF`, 年有效利率, Annual effective rate
- `C/Y`, 年複利計算期數, Compounding periods per year

常用按鍵

- `ICONV` 進入工作表

---

債券工作表

Bond worksheet

---

折舊工作表

Depreciation worksheet

---

統計工作表

Statistics worksheet

---

變化百分比/複利工作表

Percent Change / Compound Interest Worksheet

- 用來計算單利或複利變化值

變數

- `OLD`, 原值 / 成本, Old value / cost
- `NEW`, 新值 / 售價, New value / selling price
- `%CH`, 變化百分比 / 加成百分比, Percent change / Percent markup
- `#PD`, 期數, Number of periods

常用按鍵

- `delta%` 進入工作表

---

日期工作表

Date Worksheet

---

邊際利潤工作表

Profit Margin Worksheet

- 計算毛利率

變數

- `CST`, 成本, Cost
- `SEL`, 售價, Selling price
- `MAR`, 邊際利潤, Profit margin

常用按鍵

- `PROFIT` 進入工作表

---

損益平衡工作表

Breakeven worksheet

- 用來計算損益平衡點以及賺取一定利潤的所需的銷售水準
- 損益平衡點, 即總收入 = 總成本時

變數

- `FC`, 固定成本, Fixed cost
- `VC`, 單位可變成本, Variable cost
- `P`, 單價, Unit price
- `PET`, 利潤, Profit
- `Q`, 銷售量, Quantity

常用按鍵

- `BRKEVN` 進入工作表

---

財金知識問題與學習

- 什麼是折現率 discount rate
  - Ans: 在金錢時間價值中, 現在價值與未來價值之間的複利利率
- 什麼是 `PB`, 回收期, Payback period
  - Ans: 投資回本所需的時間, 回報打平投入資金的時間點
- 什麼是 `DPB`, 折現回收期, Discounted payback period
  - Ans: 考慮折現率的回收期
- 什麼是 `IRR`, 內部報酬率, Internal rate of return
  - Ans: 年化報酬率, 衡量現金流的報酬率
  - 淨現值法 (Net Present Value Method), 考量現金流的折現率, 計算所有收入與支出在考量折現率的情況下, 折回現值的和
  - `IRR` 內部報酬率, 是**淨現值法 = 0 時的折現率** (複利報酬率)
  - IRR 計算方法, 假設現金流期間的收入的再投資報酬率等於內在報酬率
- 什麼是 `RI`, 再投資利率, Reinvestment rate
  - Ans: 現金流期間, 每筆收入再投資的投資報酬率
- 什麼是 `MOD`, 修正內部報酬率, Modified Internal rate of return
  - Ans: IRR 計算時增加再投資利率 (RI) 這個變數
  - 允許自行設定再投資報酬率, 這樣算下來的終值比較符合現實, 在由此反推內部報酬率
  - 以股票為例, 分配的現金股利, 不一定每次都能用相同的複利報酬率再進行投資
- 什麼是名目利率 (Nominal rate) 和年有效利率 (Annual effective rate)
  - 名目利率 (Nominal rate), 帳面利率, 以一年為單位的單利
  - 年有效利率 (Annual effective rate), 如果一年內有多次複利反推後的利率
    - `有效利率 = ( 1 + ( 名目利率 ÷ 計息次數 ))^計息次數`
  - 實質利率 (Real Interest Rate), 考量通貨膨脹率之後的利率,
    - `名目利率 - 通貨膨脹率 = 實質利率`
- 通貨膨脹率, 美國年平均值是 `3.3%`
