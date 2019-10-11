#紀錄 Ubuntu 安裝狀況與遇到的問題

1. 使用 UEFI USB 安裝 Ubuntu 16.04 desktop 版，bootable USB from windows 參考Ubuntu官方教學 [ClickForWebsite][website1]
2. 磁碟分割: UTF 1GB, SWAP 10GB, / 100GB, /home others = total 1TB
3. 安裝 chrome from web
4. 由於設定時語言選擇英文，因此要安裝中文注音輸入法 參考這篇部落格文章的教學 [ClickForWebsite][website2]：

	Terminal 輸入以下指令:
		
		sudo apt-get install ibus-chewing
		ibus restart
	
	從 System Settings -> Text Entry 中
	點選 input sources to use 下方的 + 號
	找到 Chinese (Chewing) (IBus) 加入後即可使用酷注音輸入。

5. 安裝 spotify for linux from web [ClickForWebsite][website4]
System Settings -> Security&Privacy -> Files&Applications add in Exclude.
6. 安裝 unrar

	sudo apt-get install unrar

7. 安裝 minecraft [ClickForWebsite][website5]
8. 安裝 Anki [ClickForWebsite][website3]

9. 安裝 Unity Tweak Tool 與 [ubuntu themes : paper][website6] 下載

		 sudo apt-get install unity-tweak-tool

	[wallpapers website](https://wallpaperscraft.com/)
		 


 * * *
Used commands 

* apt-get install
* tar xjf
* make


* * * 
[website1]: https://www.ubuntu.com/download/desktop/create-a-usb-stick-on-windows
[website2]: http://it.livekn.com/2016/05/ubuntu-1604-ibus.html
[website3]: https://apps.ankiweb.net/
[website4]: https://www.spotify.com/tw/download/linux/
[website5]: https://www.howtogeek.com/198476/how-to-install-minecraft-on-ubuntu-or-any-other-linux-distribution/
[website6]: https://snwh.org/paper/download
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTgzMzA4OTY0MV19
-->