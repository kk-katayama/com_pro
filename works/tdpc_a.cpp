#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
int n;
int p[110];
int dp[110][10010];
int main()
{
  cin >> n;
  int a = 0;
  rep(i,n){
    cin >> p[i];
    a = max(a,p[i]);
  }
  int m = a*n;
  
  rep(i,n) rep(j,m) dp[i][j] = 0;

  dp[0][0] = 1;

  rep(i,n){
    rep(j,m+1){
      dp[i+1][j+p[i]] = dp[i][j];
      dp[i+1][j] = dp[i][j];
    }
  }

  int res = 0;
  rep(j,m+1) res += dp[n][j];
  cout << res << "\n";
  return 0;
}
