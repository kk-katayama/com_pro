#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n,W;cin >> n >> W;
  vector<ll> w(n), v(n);
  rep(i,n) {
    cin >> w[i] >> v[i];
  }

  ll w0 = w[0];
  rep(i,n) {
    w[i] -= w0;
  }
  
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(3*n+1, vector<ll>(n+1, 0)));

  rep(i,n) {
    rep(j, 3*n+1) {
      rep(k, n) {
	if(j - w[i] >= 0) {
	  chmax(dp[i+1][j][k], dp[i][j][k]);
	  chmax(dp[i+1][j][k+1], dp[i][j - w[i]][k] + v[i]);
	}
	else chmax(dp[i+1][j][k], dp[i][j][k]);
      }
    }
  }


  ll res = 0;
  rep(j,3*n+1) {
    rep(k,n+1) {
      if(j <= W - k*w0) chmax(res, dp[n][j][k]);
    }
  }
    
  cout << res << "\n";
  
  return 0;
}
