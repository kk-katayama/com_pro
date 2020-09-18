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
  int n,m; cin >> n >> m;
  vi a(m),b(m);
  vii c(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    c[i].resize(b[i]);
    rep(j,b[i]) {
      cin >> c[i][j];
      c[i][j]--;
    }
  }

  int inf = 1e+9;
  vi dp((1 << n), inf);
  dp[0] = 0;
  rep(i,m) {
    vi ndp((1 << n), inf);
    int S = 0;
    rep(j,b[i]) {
      S += (1 << c[i][j]);
    }
    rep(mask, (1 << n)) {
      chmin(ndp[mask | S], dp[mask] + a[i]);
      chmin(ndp[mask], dp[mask]);
    }
    dp = ndp;
  }

  cout << (dp[(1<<n) - 1] == inf ? -1 : dp[(1<<n) - 1]) << "\n";
  
  return 0;
}
