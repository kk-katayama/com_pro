# TDPC E 数  

* Nが整数型に収まらないので文字列として読み込む  
* dp[i][j][k] i桁目までの各桁の数字の和の mod D が jであるものの数。kは未満フラグ。  

## 遷移
for(int jj = 0 ; jj < (k?10:N[i]+1) ; ++jj){  
   dp[i+1][(jj+j)%D][k||jj<N[i]] += dp[i][j][k];  
}  

   
