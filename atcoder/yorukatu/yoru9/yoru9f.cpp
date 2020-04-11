#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int dp[45][410][410];
int main()
{
  int n,ma,mb;cin >> n >> ma >> mb;
  vector<int> a(n), b(n), c(n);
  rep(i,n) cin >> a[i] >> b[i] >> c[i];


  rep(i,42) rep(j,405) rep(k,405) dp[i][j][k] = 1e+9;

  dp[0][0][0] = 0;

  rep(i,n) {
    rep(j,401) {
      rep(k,401) {
  	dp[i+1][j + a[i]][k + b[i]] = min(dp[i+1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
  	dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
      }
    }
  }

  int res = 1e+9;
  int aa = ma, bb = mb;
  while(aa <= 400 && bb <= 400) {
    res = min(res, dp[n][aa][bb]);
    aa += ma;
    bb += mb;
  }

  if(res == 1e+9) cout << -1 << "\n";
  else cout << res << "\n";
  return 0;
}
