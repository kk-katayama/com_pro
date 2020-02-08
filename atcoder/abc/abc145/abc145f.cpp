#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll inf = 1LL<<60;
int main()
{
  int n,k;
  cin >> n >> k;
  vector<ll> h(n+1);
  h[0] = 0;
  rep1(i,n){
    cin >> h[i];
  }

  vector<vector<ll>> dp(n+1,vector<ll>(n+1,inf));
  // rep(i,n+1){
  //   dp[i][0] = 0;
  // }
  dp[0][0] = 0;
  rep1(i,n){
    rep1(j,n){
      rep(l,i){
	dp[i][j] = min(dp[i][j],dp[l][j-1]+max((ll)0,h[i]-h[l]));
      }
    }
  }

  ll res = inf;
  rep(i,n+1){
    res = min(res,dp[i][n-k]);
  }
  cout << res << "\n";


  // rep(i,n+1){
  //   rep(j,n+1){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  
  return 0;
}
