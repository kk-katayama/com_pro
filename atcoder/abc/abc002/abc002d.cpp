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
  vi x(m),y(m);
  rep(i,m) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }
  vvi f(n, vi(n, 0));
  rep(i,m) {
    f[x[i]][y[i]] = 1;
    f[y[i]][x[i]] = 1;
  }
  rep(i,n) f[i][i] = 1;
  
  int res = 0;
  rep(S,(1<<n)) {
    bool ff = true;
    rep(i,n) {
      rep(j,n) {
	if(( (S>>i) & 1) && ( (S>>j) & 1)) {
	  if(!f[i][j]) ff = false;
	}
      }
    }
    if(ff) {
      int x = __builtin_popcount(S);
      chmax(res, x);
    }
  }
  cout << res << "\n";
  
  return 0;
}
