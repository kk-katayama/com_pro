#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
const ll inf = 1e+15;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> k(n);
  vector<vector<ll>> x(n), d(n);
  rep(i,n) {
    cin >> k[i];
    x[i].resize(k[i]);
    d[i].resize(k[i]);
    rep(j,k[i]) cin >> x[i][j] >> d[i][j];
  }
  
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(20, vector<ll>(m+1, inf)));
  rep(i,k[0]) dp[0][i][0] = 0;
  rep(i,k[1]) dp[1][i][1] = 0;
  rep(i,n-1) {
    rep(a,k[i]) {
      rep(b,k[i+1]) {
	rep(j,m+1) {
	  chmin(dp[i+1][b][j], dp[i][a][j] + (d[i][a] + d[i+1][b]) * abs(x[i][a] - x[i+1][b]) );
	}
      }
    }
    if(i+2 < n) {
      rep(a,k[i]) {
	rep(b,k[i+2]) {
	  rep(j,m) {
	    chmin(dp[i+2][b][j+1], dp[i][a][j] + (d[i][a] + d[i+2][b]) * abs(x[i][a] - x[i+2][b]) );
	  }
	}
      }      
    }
  }
  
  ll res = inf;
  rep(i,k[n-1]) {
    rep(j,m+1) {
      chmin(res, dp[n-1][i][j]);
    }
  }
  rep(i,k[n-2]) {
    rep(j,m) {
      chmin(res, dp[n-2][i][j]);
    }
  }
  
  cout << res << "\n";
  
  return 0;
}
