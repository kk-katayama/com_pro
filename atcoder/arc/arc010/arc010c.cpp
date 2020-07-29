#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,m; cin >> n >> m;
  int Y,Z; cin >> Y >> Z;
  vector<char> c(m);
  vector<int> p(m);
  rep(i,m) cin >> c[i] >> p[i];
  vector<char> b(n);
  rep(i,n) cin >> b[i];

  map<char,int> mp;
  rep(i,m) {
    mp[c[i]] = i;
  }
  vector<int> B(n);
  rep(i,n) {
    B[i] = mp[b[i]];
  }
  
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>((1<<m), -1e+9)));
  dp[0][m][0] = 0;
  rep(i,n) {
    rep(j,m+1) {
      rep(mask,(1<<m)) {
	if(B[i] == j) {
	  chmax(dp[i+1][B[i]][mask | (1 << B[i])], dp[i][j][mask] + p[B[i]] + Y);
	}
	else {
	  chmax(dp[i+1][B[i]][mask | (1 << B[i])], dp[i][j][mask] + p[B[i]]);
	  chmax(dp[i+1][j][mask], dp[i][j][mask]);
	}
      }
    }
  }

  int res = 0;
  rep(j,m) {
    rep(mask, (1<<m)) {
      if(mask == (1<<m) - 1) {
	chmax(res, dp[n][j][mask] + Z);
      }
      else {
	chmax(res, dp[n][j][mask]);
      }
    }
  }
  cout << res << "\n";
  return 0;
}
