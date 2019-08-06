D.Knapsack 1
ナップサックDP
dp[i][j] := 価値の総和の最大値 <i番目の品物までチェック> <重さの総和がj以下>  (1 <= i <= n , 0<= j <= wmax)
answer = dp[n][wmax]

・遷移
貰うイメージ
dp[i+1][j] = max( dp[i][j] , dp[i][j-w[i]] + v[i] ) 

E.Knapsack 2
Dと同じようにするとwmaxが大きすぎてTLE
変数を変える
dp[i][j] := 重さの総和の最小値 <i番目の品物までチェック> <価値の総和がj> 

answer = max{ j ; dp[n][j] <= wmax , 0 <= j <= vmax }

・遷移
dp[i+1][j] = min( dp[i][j] , dp[i][j-v[i]] + w[i] }
