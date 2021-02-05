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

  vvi dp(n+1, vi(m+1, -1));
  auto rec = [&](auto self, int x, int y)->int{
    if(dp[x][y] >= 0) return dp[x][y];
    if(x == n && y == m) return dp[x][y] = 0;
    if((x + y) % 2 == 0) {
      int res = -inf;
      if(x != n) chmax(res, self(self, x+1, y) + a[x]);
      if(y != m) chmax(res, self(self, x, y+1) + b[y]);
      return dp[x][y] = res;
    }
    else {
      int res = inf;
      if(x != n) chmin(res, self(self, x+1, y));
      if(y != m) chmin(res, self(self, x, y+1));
      return dp[x][y] = res;      
    }
  };
  cout << rec(rec, 0, 0) << "\n";
  return 0;
}
