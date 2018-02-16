
Anki 使用心得
==

Purpose: 紀錄偏好設定與卡片製作心得
--

使用 anki 環境分別為 windows 和 Ubuntu 。
在此紀錄所需要的偏好設定和遇到的問題，
以及紀錄 anki 卡片的製作及使用心得。
 

[TOC]

* * *

Anki 個人偏好設定
==

附加元件
--

* **Night Mode** 夜晚模式 改變 anki 視窗顏色。
*  **AwesomeTTS** 字卡中的聲音檔來源
	Ubuntu: 需要安裝 MPlayer by command :
	$ sudo apt-get install mplayer
* **Replay buttons on card** 聲音檔重複播放按鈕

牌組設定
-- 

牌組設定 / 複習卡 / 每天最大複習量 : 999
在卡片被累積的時候，不受最大複習量影響，仍可以一次性的復習完。
 
 * * *

Anki 心得
==

新增字卡
--

使用 Anki 記憶英文單字，由於使用僅半個月左右 （2017.4.8 為止），
 因此卡片的製作與使用，稱不上非常熟練，卡片製作上大量參考了[Anki 加入英文單字範例][]中的內容。

新增卡片流程:

1. 點選**進入**想要增加的**牌組**
2. 按 **新增** 或使用快捷鍵 **A**
3. 卡片類型使用: Basic (and reversed card)
4. 加入卡片內容: 
	Front:
	 英文單字+用法
	 英文例句
	 英文例句的聲音檔
	Back:
	中文解釋
	英文例句的中文翻譯

	重點用別的顏色標示。
	
	**聲音檔**的加入方法:
	在要加入的地方 **按最右邊的喇叭按鈕** 或按快捷鍵 **CTRL+T**
	我的聲音檔設定: 使用 AwesomeTTS 中的 NeoSpeech / Paul (male en-US)
 
範例:
![名詞範例](https://lh3.googleusercontent.com/-seFCbJh46P4/WOndFv_OtnI/AAAAAAAAAh0/0i2YB0NvCEYAkEfNOy9ZI3FQoUntiQIhQCLcB/s0/%25E5%2590%258D%25E8%25A9%259E.png "名詞.png")

 卡片內容可增加的資訊:
 條列:
 
 * 加入介係詞
 * 名詞可加入圖片  
 * 名詞加上特定動詞
 * 片語
 * 需要注意的發音音標
 * 特殊的動詞變化
   
範例:

* 加入介係詞
![介係詞][]

* 名詞可加入圖片  
![名詞圖片][]

* 名詞加上特定動詞
![名詞用法][]

* 片語
  ![片語][]
  
* 需要注意的發音音標
![音標][]

* 特殊的動詞變化
![動詞變化][]

常用的網路字典，用來搜尋翻譯與例句:

* [Yahoo 奇摩字典][]
* [Oxford Dictionary][] 
* [Longman Dictionary][]
* [Google 翻譯][]

練習字卡方法
--

* **讀出**例句並且確認**發音正確**，可利用重複播放鈕。
* 英文題目，應該翻譯出**整個例句**的意思，並且觀察用法。

* 由於是使用 Basic (and reversed card) 所以會出現中文題目，
  我會用**手寫**下英文的**拼字**，用來確定拼寫是正確的，
  在**拼寫有誤**的時候，我也會選擇**再一次**。

範例:
 
 ![中文題目][]
 ![拼寫][]



* * * 

[Longman Dictionary]: http://www.ldoceonline.com/
[Google 翻譯]: https://translate.google.com.tw/?hl=zh-TW
[Oxford Dictionary]: https://en.oxforddictionaries.com/
[Yahoo 奇摩字典]: https://tw.dictionary.yahoo.com/
[Anki 加入英文單字範例]: https://www.youtube.com/watch?v=qDrCGID6wSk
[片語]:https://lh3.googleusercontent.com/-IpHYA40r_EE/WOne9kJSHGI/AAAAAAAAAiE/VMwUAs0aF78QM_O6D0bmSBQMGOF2TuhmQCLcB/s0/%25E7%2589%2587%25E8%25AA%259E.png
[名詞圖片]: https://lh3.googleusercontent.com/-CBj9y_ucV-c/WOngL8GcgJI/AAAAAAAAAiQ/GIgnT1eGuboyjrsB8s49RWgHX3v6BykjgCLcB/s0/%25E5%2590%258D%25E8%25A9%259E%25E5%259C%2596%25E7%2589%2587.png 
[音標]: https://lh3.googleusercontent.com/-kKgo_ixHUbw/WOng8-quduI/AAAAAAAAAig/QICDrztwPhkjY4Foj6G7TdlwoZHpB-xbwCLcB/s0/%25E9%259F%25B3%25E6%25A8%2599.png 
[介係詞]: https://lh3.googleusercontent.com/-iH8-xOR6bwc/WOnhm3iq2jI/AAAAAAAAAiw/Ns5DFyk540k7qeiPvNymbJ6pag-nLDdiACLcB/s0/%25E4%25BB%258B%25E4%25BF%2582%25E8%25A9%259E.png 
[動詞變化]: https://lh3.googleusercontent.com/-8IzF7yvuCAM/WOniJtg6DnI/AAAAAAAAAjE/WEXeLSz4pYg5vYP88YUrHTQsK9YLyyqfACLcB/s0/%25E5%258B%2595%25E8%25A9%259E%25E8%25AE%258A%25E5%258C%2596.png 
[名詞用法]: https://lh3.googleusercontent.com/-8xFbExxHuWo/WOni7y2n9sI/AAAAAAAAAjU/TU7mDX_R1FQg0XQHAl54G3tAYASDGYf3wCLcB/s0/%25E5%2590%258D%25E8%25A9%259E%25E7%2594%25A8%25E6%25B3%2595.png 
[中文題目]: https://lh3.googleusercontent.com/-_SDMulO9xBM/WOnj9cf8rRI/AAAAAAAAAjo/9WLKbDXmvgYdOp4skUB_5Z5qaf-O00u8wCLcB/s0/%25E4%25B8%25AD%25E6%2596%2587%25E9%25A1%258C%25E7%259B%25AE.png 
[拼寫]: https://lh3.googleusercontent.com/-7-50Aq1PtEU/WOnmm60jQNI/AAAAAAAAAkQ/i0yzAdcn3y4o8WmZ2gFjjv_SEhXsTh0vACLcB/s0/%25E6%258B%25BC%25E5%25AF%25AB.png 

* * * 
working part 整合進 list 結構 
list 
list subject 
detail 
working part

List - English / Anki

detail Anki 個人使用心得 (2)