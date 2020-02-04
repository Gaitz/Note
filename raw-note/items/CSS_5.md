## CSS 重構
### BOOK resource, CSS 

------------

第一章 - 重構與架構
第二章 - 了解串接
第三章 - 編寫較佳的 CSS
第四章 - 為不同類型的樣式分類
第五章 - 測試
第六章 - 樣式碼置放與重構策略

------------


### 第一章 - 重構與架構
  * 重構是為了更簡單與更容易重用 (reusable)

#### 好的軟體架構
  * 可預期 (predictable), 容易在可以預期的地方找到正確的程式碼。
  * 程式碼重用性高 (reusable), 不需要複製類似的程式碼。
  * 容易擴充 (extensibility), 新功能容易增加, 不需要修改其他程式碼。
  * 好維護 (maintainability), 因應需求的變化, 調整程式碼容易。

#### 重構的時機
  * 修正錯誤時
  * 建置新功能時
  * 在進行小任務時固定重構
  * 相依性小的時候重構
  * 專門執行的大型重構

#### Tips
  * 持續跟上最佳實務 (Best Practice)
  * 趁早訂好程式碼標準 (coding standards)，避免編碼風格的重構
  * 測試 (testing)


------------------------------


### 第二章 - 了解串接 (cascade)

#### CSS 選擇器的特定度 (specificity)
  * 特定度(specificity)
    1. `!important` > 
    1. 行內樣式 (inline) > 
    1. ID 數量 > 
    1. 類別/屬性/擬類別 數量 (class/attributes/pseudo-class) > 
    1. 元素類型/擬元素 數量 (type/pseudo-elements)
  * 特定度相等時，最晚出現的優先。
  * media query 不影響特定度。


------------------------------


### 第三章 - 編寫較佳的 CSS