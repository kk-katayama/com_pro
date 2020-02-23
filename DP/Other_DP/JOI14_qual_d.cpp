#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> d(n),c(m);
  rep(i,n) cin >> d[i];
  rep(j,m) cin >> c[j];

  vector<vector<int>> dp(n+1,vector<int>(m+1,2e+9));
  dp[0][0] = 0;
  rep(i,n){
    rep(j,m){
      dp[i][j+1] = min(dp[i][j+1],dp[i][j]);
      dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+d[i]*c[j]);
    }
  }

  int res = 2e+9;
  rep(j,m+1) res = min(res,dp[n][j]);
  cout << res << "\n";

  
  return 0;
}
