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
  int n; cin >> n;
  vi ng(3);
  rep(i,3) cin >> ng[i];

  auto isok = [&](int x) ->bool{
		bool f = true;
		rep(i,3) if(x == ng[i]) f = false;
		if(x < 0) f = false;
		return f;
	      };
  vii dp(101, vi(n+1, 0));
  dp[0][n] = (isok(n) ? 1 : 0);
  rep(i, 100) {
    rep(j,n+1) {
      if(isok(j-1)) {
	if(dp[i][j] == 1) dp[i+1][j-1] = 1;
      }
      if(isok(j-2)) {
	if(dp[i][j] == 1) dp[i+1][j-2] = 1;
      }
      if(isok(j-3)) {
	if(dp[i][j] == 1) dp[i+1][j-3] = 1;
      }      
    }
  }

  bool res = false;
  rep(i,101) {
    if(dp[i][0] == 1) res = true;
  }
  cout << (res ? "YES" : "NO") << "\n";
  
  return 0;
}
