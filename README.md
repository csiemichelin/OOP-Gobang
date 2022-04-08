# OOP-Gobang
## 目錄
 - [環境配置](#環境配置)
 - [設計動機](#設計動機)
 - [玩法歸則](#玩法歸則)
 - [開始與結束界面](#開始與結束界面)
 - [禁手機制](#禁手機制)
## 環境配置
windows平臺下面安裝codeblock程序：   
&emsp;* **codeblock 官網：http://www.codeblocks.org/**   
&emsp;&emsp;點擊Downloads, 推薦下載自帶 TDM-GCC 編譯器的 codeblocks-17.12mingw-setup.exe 安裝包。   
&emsp;&emsp;運行安裝包 .exe 即可進入安裝界面。按照界面的提示信息一步一步操作。    
&emsp;* **執行 五子棋.cbp 類似於linux的makefile，可以同時編譯多個檔案。**   
## 設計動機
因為小時候很喜歡跟媽媽下棋，現在身為一個工程背景的學生，想說用oop去實現它，並且完成禁手相關的限制，讓專案變得更完整。
## 玩法歸則
**1.** 由黑棋先行，黑白雙方輪流落子在棋盤的交叉點。  
**2.** 先在棋盤上形成橫、直、或縱的連續五個棋子者（連五）為勝。  
**3.** 棋盤大小有分15、17、19等幾種，目前均以15x15為標準。 
## 開始與結束界面   
**1.** 開始界面     
&emsp;&emsp;&emsp;<img src="https://github.com/csiemichelin/OOP-Gobang/blob/main/res_image/s1.png" width="200" height="200">   
&emsp;由黑棋先手      
&emsp;&emsp;&emsp;<img src="https://github.com/csiemichelin/OOP-Gobang/blob/main/res_image/s2.png" width="200" height="200">  
**2.** 結束界面    
&emsp;&emsp;&emsp;<img src="https://github.com/csiemichelin/OOP-Gobang/blob/main/res_image/s3.png" width="200" height="200">    
## 禁手機制   
黑棋的禁手包含長連、雙四、雙活三，以下簡單介紹：    
**1.** 原則：    
&emsp;(1) 只有黑棋有禁手，下出禁手判黑敗，白棋沒有限制。    
&emsp;(2) 黑棋下出五同時出現禁手，則不算禁，五最大，判黑勝。   
&emsp;(3) 三個三、三個四、四三三、四四三、同樣為黑棋禁手。   
**1.** 長連：只要黑棋連線超過五子，即為禁手，白棋沒禁手，白長連也算勝。   
&emsp;&emsp;&emsp;<img src="https://github.com/csiemichelin/OOP-Gobang/blob/main/res_image/v1.png" width="200" height="200">     
**2.** 四四：黑子一子形成二個四，無論是活四或死四。   
&emsp;&emsp;&emsp;<img src="https://github.com/csiemichelin/OOP-Gobang/blob/main/res_image/v2.png" width="200" height="200">    
**3.** 雙活三：黑子一子形成**二個活三**的著手，此子為兩個活三的交點。     
&emsp;(1) 活四：次一子於兩端皆可形成五的四子連線。     
&emsp;(2) 活三：**次一子可形成活四**的三子連線，**且形成活四的點不可同時形成五或禁手**。    
&emsp;&emsp;&emsp;<img src="https://github.com/csiemichelin/OOP-Gobang/blob/main/res_image/v3.png" width="200" height="200">&emsp;<img src="https://github.com/csiemichelin/OOP-Gobang/blob/main/res_image/v4.png" width="200" height="200">      
