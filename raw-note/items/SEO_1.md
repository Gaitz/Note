## Google Developers SEO Documentation

### [Google Search Central](https://developers.google.com/search/docs), SEO

---

Introduction

第一章 - Introduction

第二章 - Get your website on Google

第三章 - SEO Starter Guide

第四章 - How Google Search works

第五章 - Do you need and SEO?

第六章 - Maintaining your site's SEO

第七章 - Developer's guide to Search

Guidelines

第八章 - Overview of guidelines

第九章 - Webmaster guidelines

第十章 - General guidelines

第十一章 - Content-specific guidelines

第十二章 - Quality guidelines

Control crawling and indexing

第十三章 - Overview

第十四章 - Sitemaps

第十五章 - robots.txt

第十六章 - Meta tags

第十七章 - Crawler management

第十八章 - Removals

第十九章 - Canonical URLs

第二十一章 - Site moves and changes

第二十二章 - International and multilingual sites

第二十三章 - JavaScript content

Change your Search appearance

第二十二章 - Overview of Search appearance

第二十三章 - Control your title links

第二十四章 - Control your snippets

第二十五章 - Enable Search result features for your site

第二十六章 - Featured snippets and your website

第二十七章 - Sitelinks

第二十八章 - Provide a publication date to Google Search

第二十九章 - Define a favicon to show in search results

第三十章 - Translated results

第三十一章 - Enabling your ad network to work with translation-related Google Search features

第三十二章 - Using structured data

第三十三章 - Enriched search results

第三十四章 - Flexible Sampling general guidance

第三十五章 - Enable Top Places List

第三十六章 - Opt out of display in local search results and other Google properties

第三十七章 - Use Image Rights Metadata in Google images

第三十八章 - Debug with search operators

第三十九章 - Web Stories

第四十章 - Early Adopters Program

Optimize your page experience

第四十一章 - Understanding page experience

第四十二章 - Get started with signed exchanges on Google Search

第四十三章 - Mobile

第四十四章 - Security

第四十五章 - AMP

Monitor your site performance

第四十六章 - Get started with Search Console

第四十七章 - Using reports in Search Console

---

Introduction

---

### 第一章 - Introduction

- Search engine optimization, SEO
  - 讓網站更 search-friendly 的過程

---

### 第二章 - Get your website on Google

- 一般來說 Google 會自動爬到你的網站, 但是可以用一些方式檢查並且加強

基本檢查

- Google 尚未建立 indexed 的可能原因
  - 你的網站沒有被其他網站連結
  - Google 爬蟲通常需要 "數週" 的時間才爬得到
  - 網站設計的讓 Google 爬蟲無法理解, 例如使用圖片與影片取代文字
  - Google 爬蟲遇到錯誤, 網站可能需要授權等等原因

1. 檢查網站是否被 Google Indexed
   - 在 Google 搜尋 `site:` 加上你的網站位置
2. 你的網站對於使用者是否是高品質的
   - 網站最優先的事情是如何讓使用者有最佳的體驗
   - 獨特, 有價值, 吸引人的
3. 如果是 Google 商業用戶 (Business) 有另外的入口可以設定
4. 網站內容是否能快速且容易地在任何平台上載入
   - 現在很多的搜尋來自於 mobile, 請確認網站是 mobile-friendly
5. 網站是否安全 (secure)
   - 採用 HTTPS
6. [取決於網站的內容類型, Google 有其他相關服務可以一同使用](https://developers.google.com/search/docs/basics/get-on-google#is-your-content-about-a-specialized-topic), 分類如下
   - 商業或個人
   - 數位內容 (數位書籍, 數位新聞, ...)
   - 地區資訊 (地圖資訊, 街景, ...)
   - 多媒體內容 (影片, Podcast)

- 進階的幫助, 雇用一個 SEO 專家來協助
- _補_: 總體來說 SEO 應該要關注的點是
  - 高品質的網站內容
  - 在任何平台都容易使用的網站 (Responsive, Performance)
  - 網站是安全的

---

### 第三章 - SEO Starter Guide

- SEO 的重點在於幫助搜尋引擎了解網站內容

Getting started

- 確認是否網站有被 Google 抓到, Google search with `site:`
- 可以註冊使用 Google Search Console
- 關於 SEO 基礎的幾個問題
  - 網站是否被 Google 抓到
  - 是否提供高品質的內容給使用者
  - 我的商店是否有在 Google 上
  - 我的內容能否在所以的裝置上快速且容易的載入
  - 我的網站安全嗎？

Help Google find your content

- 最簡單讓 Google 取得網站內容的方式是 submit a **sitemap**
- Google 通常透過 "其他網站連結" 來爬到網站

Tell Google which pages you don't want crawled

- 使用 **robots.txt** 來告知 Google 不要爬取特定的路徑
  - **robots.txt** 是用來告知爬蟲哪裡應該被爬取
  - 檔案必須命名成 **robots.txt** 並且放置在網站根目錄下
  - **機密性的內容需要用更安全的方式阻擋爬蟲**
- **避免**網站內部的搜尋結果頁被 Google 爬到並放在搜尋引擎上
- 機密性內容防止爬蟲
  - 並非所有的爬蟲都會遵守 **robots.txt**
  - 可以在 meta data 加上 `noindex` 防止 Google Search index 這頁
  - 更安全的作法是使用 authorization 方式阻止爬蟲使用或者直接拿掉該路徑

Help Google (and users) understand your content

- Google 爬蟲應該要體驗到等同於一般使用者的內容
  - 記得讓 JavaScript, CSS, images 都是爬蟲讀取得到的, (不要被 **robots.txt** 阻擋)
  - 使用 [URL Inspection](https://support.google.com/webmasters/answer/9012289) 工具, 檢查 Google 爬蟲所取得的網站內容
- 使用獨特且精準的 `title`
  - `<title>` in `<head>`
- `title` 會變成 Google search result 的連結文字, 因此十分重要
- `<title>` 應該精準的描述網站內容
  - **避免**與網站內容無關的標題, 預設的標題, 模糊的標題
- `<title>` 應該是獨特的 (unique), 幫助 Google 了解每個頁面是有區別的, 獨立的內容, 儘管是 mobile 版, 也應該在標題中寫出與 PC 版的區別
  - **避免**整個網域內使用單一個標題
- `<title>` 應該是簡短, 且有描述性的
  - **避免**過長的標題
  - **避免**添加無意義的關鍵字
- 使用 `<meta name="description" content />` 標籤描述網站內容
  - 一個句子到一個段落的文字描述網站內容
  - 對於 SEO 十分重要, Google 可能會選用 description 作為搜尋結果的摘要
- `description` 撰寫精準的 summary, 讓使用者讀到時能收到訊息並且感興趣
  - `description` 沒有任何長度限制, 推薦用任何足夠長的文字描述應該被描述的
  - **避免**無關的內容, 不準確, 太空泛的, 僅放置關鍵字而非句子, 複製網頁中全部的內容
- `description` 應該每一頁都是獨特的
  - 在有大量的頁面時, 應該利用網站內容自動生成 description
  - **避免**整個網域內使用單一個 description
- 使用 heading tags 來強化網頁內容結構與文字
  -

Manage your appearance in Google Search results

Organize your site hierarchy

Optimize your content

Optimize your images

Make your site mobile-friendly

Promote your website

Analyze your search performance and user behavior

Additional Resources

---

### 第四章 - How Google Search works

---

### 第五章 - Do you need and SEO?

---

### 第六章 - Maintaining your site's SEO

---

### 第七章 - Developer's guide to Search

---

Guidelines

---

### 第八章 - Overview of guidelines

---

### 第九章 - Webmaster guidelines

---

### 第十章 - General guidelines

---

### 第十一章 - Content-specific guidelines

---

### 第十二章 - Quality guidelines

---

Control crawling and indexing

---

### 第十三章 - Overview

---

### 第十四章 - Sitemaps

---

### 第十五章 - robots.txt

---

### 第十六章 - Meta tags

---

### 第十七章 - Crawler management

---

### 第十八章 - Removals

---

### 第十九章 - Canonical URLs

---

### 第二十一章 - Site moves and changes

---

### 第二十二章 - International and multilingual sites

---

### 第二十三章 - JavaScript content

---

Change your Search appearance

---

### 第二十二章 - Overview of Search appearance

---

### 第二十三章 - Control your title links

---

### 第二十四章 - Control your snippets

---

### 第二十五章 - Enable Search result features for your site

---

### 第二十六章 - Featured snippets and your website

---

### 第二十七章 - Sitelinks

---

### 第二十八章 - Provide a publication date to Google Search

---

### 第二十九章 - Define a favicon to show in search results

---

### 第三十章 - Translated results

---

### 第三十一章 - Enabling your ad network to work with translation-related Google Search features

---

### 第三十二章 - Using structured data

---

### 第三十三章 - Enriched search results

---

### 第三十四章 - Flexible Sampling general guidance

---

### 第三十五章 - Enable Top Places List

---

### 第三十六章 - Opt out of display in local search results and other Google properties

---

### 第三十七章 - Use Image Rights Metadata in Google images

---

### 第三十八章 - Debug with search operators

---

### 第三十九章 - Web Stories

---

### 第四十章 - Early Adopters Program

---

Optimize your page experience

---

### 第四十一章 - Understanding page experience

---

### 第四十二章 - Get started with signed exchanges on Google Search

---

### 第四十三章 - Mobile

---

### 第四十四章 - Security

---

### 第四十五章 - AMP

---

Monitor your site performance

---

### 第四十六章 - Get started with Search Console

---

### 第四十七章 - Using reports in Search Console

---
