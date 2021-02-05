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
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int n,m; cin >> n >> m;
  vi a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  vvi dp(n+1, vi(m+1, inf/2));
  dp[0][0] = 0;
  rep(i,n+1) {
    rep(j,m+1) {
      if(i-1 >= 0 && j-1 >= 0) chmin(dp[i][j], dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1));
      if(i-1 >= 0) chmin(dp[i][j], dp[i-1][j] + 1);
      if(j-1 >= 0) chmin(dp[i][j], dp[i][j-1] + 1);      
    }
  }
  cout << dp[n][m] << "\n";
  return 0;
}
