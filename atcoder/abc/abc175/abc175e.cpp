#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int R, C, K; cin >> R >> C >> K;
  using vl = vector<ll>;
  using vll = vector<vl>;
  vll mass(R, vl(C, 0));
  while(K-- > 0) {
    ll r, c, v; cin >> r >> c >> v;
    r--; c--;
    mass[r][c] = v;
  }

  ll inf = (1LL << 60);
  using vlll = vector<vll>;
  vlll dp(R, vll(C, vl(4, -inf)));
  dp[0][0][0] = 0;
  dp[0][0][1] = mass[0][0];
  rep(i,R) {
    rep(j,C) {
      rep(k,4) {
	if(i + 1 < R) {
	  chmax(dp[i+1][j][0], dp[i][j][k]);	  
	  chmax(dp[i+1][j][1], dp[i][j][k] + mass[i+1][j]);
	}
	if(j + 1 < C) {
	  chmax(dp[i][j+1][k], dp[i][j][k]);
	  if(k + 1 < 4) {
	    chmax(dp[i][j+1][k+1], dp[i][j][k] + mass[i][j+1]);
	  }
	}
      }
    }
  }
  ll res = 0;
  rep(i, 4) chmax(res, dp[R-1][C-1][i]);
  cout << res << "\n";

  
  return 0;
}
