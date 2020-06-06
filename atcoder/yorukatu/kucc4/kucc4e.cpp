#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int x,y;cin >> x >> y;
  int n;cin >> n;
  vector<int> t(n), h(n);
  rep(i,n) cin >> t[i] >> h[i];

  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(301, vector<int>(301, -1)));
  dp[0][x][y] = 0;
  
  rep(i,n) {
    rep(j,301) {
      rep(k,301) {
	if(dp[i][j][k] < 0) continue;
	chmax(dp[i+1][j][k], dp[i][j][k]);
	int nk = k - (t[i] - 1);
	if(nk >= 0 && j >= 1) {
	  chmax(dp[i+1][j-1][nk], dp[i][j][k] + h[i]);
	}
	else if(nk < 0) {
	  int nj = j - 1 + nk;
	  if(nj >= 0) {
	    chmax(dp[i+1][nj][0], dp[i][j][k] + h[i]);	    
	  }
	}
      }
    }
  }
  
  int res = 0;
  rep(j,301) rep(k,301) {
    chmax(res, dp[n][j][k]);
  }
  cout << res << "\n";
  return 0;
}
