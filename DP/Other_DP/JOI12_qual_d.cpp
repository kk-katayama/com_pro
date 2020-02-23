#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int main()
{
  int d,n;
  cin >> d >> n;
  vector<int> t(d),a(n),b(n),c(n);
  rep(i,d) cin >> t[i];
  rep(i,n) cin >> a[i] >> b[i] >> c[i];

  vector<vector<int>> dp(d+1,vector<int>(n,-1));
  dp[0][0] = 0;
  rep(i,d){
    rep(j,n){
      rep(k,n){
	if(a[k]<=t[i]&&t[i]<=b[k]&&dp[i][j]>=0){
	  if(i==0) dp[i+1][k] = max(dp[i+1][k],dp[i][j]);
	  else dp[i+1][k] = max(dp[i+1][k],dp[i][j]+abs(c[k]-c[j]));
	}
      }
    }
  }
  
  // rep(i,d+1){
  //   rep(j,n) cout << dp[i][j] << " ";
  //   cout << "\n";
  // }
  
  int res = 0;
  rep(i,n) res = max(res,dp[d][i]);
  cout << res << "\n";
  
  return 0;
}
