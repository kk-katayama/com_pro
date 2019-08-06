A.Frog1
dp[i] := 足場iにたどり着くまでに支払うコストの総和の最小値
answer = dp[n-1]

・遷移
*配るイメージ
dp[i] + abs( h[i] - h[i+1] ) → dp[i+1] 
dp[i] + abs( h[i] - h[i+2] ) → dp[i+2]
   

B.Frog2
Aと同様
・遷移
dp[i] + abs( h[i] - h[i+k] ) → dp[i+k] {1 <= k <= kmax}

C.Vacation
Frogとほとんど同じ、遷移に条件がつくのみ
条件 := 二日続けて同じ行動ができない　　より、どの行動をしたか、という状態をもつ必要がある

dp[i][j] := 幸福度の総和の最大値 <i日目> <jの行動をした場合>

遷移
配るイメージ
dp[i][a] + a[i] → dp[i+1][a] (!!禁止されている!!)
dp[i][a] + b[i] → dp[i+1][b]
dp[i][a] + c[i] → dp[i+1][c]
