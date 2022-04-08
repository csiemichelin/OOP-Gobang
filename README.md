# OOP-Gobang
## 目錄
 - [設計動機](#設計動機)
 - [玩法歸則](#玩法歸則)
 - [禁手機制](#禁手機制)
## 設計動機
## 玩法歸則
**1.** 由黑棋先行，黑白雙方輪流落子在棋盤的交叉點。  
**2.** 先在棋盤上形成橫、直、或縱的連續五個棋子者（連五）為勝。  
**3.** 棋盤大小有分15、17、19等幾種，目前均以15x15為標準。  
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
