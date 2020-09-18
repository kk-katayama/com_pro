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
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
int main()
{
  int x,y; cin >> x >> y;
  int n; cin >> n;
  vi t(n), h(n);
  rep(i,n) cin >> t[i] >> h[i];

  using viii = vector<vii>;
  viii dp(n+1, vii(x+1, vi(y+1, 0)));
  int res = 0;
  rep(i,n) {
    rev2(j,x,0) {
      rev2(k,y,0) {
	if(k - (t[i] - 1) >= 0 && j - 1 >= 0) {
	  chmax(dp[i+1][j-1][k - (t[i] - 1)], dp[i][j][k] + h[i]);
	}
	else if(j - (t[i] - k) >= 0 && j - 1 >= 0) {
	  chmax(dp[i+1][j - (t[i] - k)][0], dp[i][j][k] + h[i]);
	}
	chmax(dp[i+1][j][k], dp[i][j][k]);
	if(i == n-1) {
	  chmax(res, dp[n][j][k]);
	}
      }
    }
  }
  cout << res << "\n";
  
  return 0;
}
