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
  int n; cin >> n;
  vi a(n);
  rep(i,n) scanf("%d", &a[i]);
  int q; cin >> q;
  vi d(q+1, 0);
  vector<pi> s(n);
  rep(i,n) {
    s[i] = {0, a[i]};
  }
  rep(i,q) {
    int t; scanf("%d", &t);
    if(t == 2) scanf("%d", &d[i+1]);
    else {
      int p,x;
      scanf("%d%d", &p, &x);
      p--;
      s[p] = {i+1, x};
    }
  }

  int mx = 0;
  for (int i = q; i >= 0; --i) {
    chmax(mx, d[i]);
    d[i] = mx;
  }

  rep(i,n) {
    auto [day, money] = s[i];
    int res = max(d[day], money);
    cout << res << " ";
  }
  cout << "\n";

  return 0;
}
