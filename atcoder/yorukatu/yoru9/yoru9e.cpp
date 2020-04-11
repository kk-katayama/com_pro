#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m), b(m);
  vector<vector<int>> c(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    c[i].resize(b[i]);
    rep(j,b[i]) {
      cin >> c[i][j];
      c[i][j]--;
    }
  }

  vector<vector<int>> dp(m+1, vector<int>( (1<<n), 1e+9));

  dp[0][0] = 0;
  rep(i,m) {
    int tmp = 0;
    rep(j,b[i]) tmp += (1<<c[i][j]);
    rep(mask, (1<<n) ) {
      dp[i+1][mask] = min(dp[i+1][mask], dp[i][mask]);
      dp[i+1][mask|tmp] = min(dp[i+1][mask|tmp], dp[i][mask] + a[i]);
    }
  }

  
  if(dp[m][(1<<n)-1] == 1e+9) cout << -1 << "\n";
  else cout << dp[m][(1<<n)-1] << "\n";
  
  return 0;
}
