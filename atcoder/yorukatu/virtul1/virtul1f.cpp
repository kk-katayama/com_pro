#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int l;cin >> l;
  vector<ll> a(l);
  rep(i,l) cin >> a[i];
  
  vector<vector<ll>> dp(l+1, vector<ll>(5, 1e+15));
  dp[0][0] = 0;
  rep1(i,l) {
    rep(j,5) {
      rep(k,j+1) {
	if(j == 0 || j == 4) {
	  chmin(dp[i][j], dp[i-1][k] + a[i-1]);
	}
	else if(j == 1 || j == 3) {
	  if(a[i-1] == 0) chmin(dp[i][j], dp[i-1][k] + 2);
	  else if(a[i-1] % 2) chmin(dp[i][j], dp[i-1][k] + 1);
	  else chmin(dp[i][j], dp[i-1][k]);
	}
	else if(j == 2) {
	  if(a[i-1] % 2) chmin(dp[i][j], dp[i-1][k]);
	  else chmin(dp[i][j], dp[i-1][k] + 1);
	}
      }
    }
  }

  ll res = 1e+15;
  rep(i,5) chmin(res, dp[l][i]);
  cout << res << "\n";
  
  return 0;
}
