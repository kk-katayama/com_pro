# Digit_DP  

桁DP  

## ABC138 F  
大変な桁DPであった    
* y-x == y xor x ならいけそう(というかこれしかダメ)
* y-x == y%x となるにはy > 2*x → つまり、yの立っている最上位bitと同じ桁でxのbitも立っている必要がある。
* 二進数表示でy,xを上の位から見ていくと、、どの位でも(0,1)はだめ→(1,1),(1,0),(0,0)のいずれか
* yの未満フラグが必要と同時にxの以上フラグも必要(y<=R,x>=Lである必要がある)

#### 変数
dp[i][j][k][l][m][n] := 上からi桁目、yのbitはj、xのbitはk、yの未満フラグはl、xの以上フラグはm、y > 2*xのフラグがn  

#### 遷移  
(j,k)は(1,1),(1,0),(0,0)の三種類  
R,Lの二進数表記で上からi桁目のbitの組み合わせによって遷移が変わる{R(i),L(i)}を上からi桁目のbitの組とする  

#### フラグ関係  
* yの未満フラグが0のとき、R(i)=0だとj=1に遷移できない((0,0)にのみ遷移可能)  
* yの未満フラグが0のとき、R(i)=1でj=0に遷移するとフラグが立つ  
* xの以上フラグが0のとき、L(i)=1だとk=0に遷移できない((1,1)にのみ遷移可能)  
* xの以上フラグが0のとき、L(i)=0でk=1に遷移するとフラグが立つ  
* nのフラグが0のとき、(j,k)=(1,0)に遷移できない  
* nのフラグが0のとき、(j,k)=(1,1)に遷移するとフラグが立つ  

 
 
