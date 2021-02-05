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
  vl a(n);
  rep(i,n) cin >> a[i];
  vi x(m),y(m);
  rep(i,m) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  vvi edge(n);
  rep(i,m) {
    edge[x[i]].push_back(y[i]);
  }
  vl dp(n, infll/2);
  vi f(n, 0);
  rep(i,n) {
    if(f[i]) continue;
    queue<pl> q;
    q.push({i, infll/2});
    while( !q.empty() ) {
      auto [id, cos] = q.front(); q.pop();
      f[id] = 1;
      for(auto tmp: edge[id]) {
	if(chmin(dp[tmp], min(cos, a[id]))) {
	  q.push({tmp, dp[tmp]});
	}
      }
    }
  }
  ll res = -infll;
  rep(i,n) {
    chmax(res, a[i] - dp[i]);
  }
  cout << res << "\n";
  
  return 0;
}
