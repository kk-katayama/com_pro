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
  int t; cin >> t;
  while(t-- > 0) {
    int n,m; cin >> n >> m;
    vi a(n);
    rep(i,n) cin >> a[i];

    if(n > m) {
      cout << -1 << "\n";
    }
    else if(n == 2) {
      cout << -1 << "\n";
    }
    else {
      int res = 0;
      rep(i,n) res += a[i];
      res *= 2;
      vector<pi> p(n);
      rep(i,n) p[i] = {a[i], i};
      sort(p.begin(), p.end());
      res += (m - n) * (p[0].first + p[1].first);
      cout << res << "\n";
      rep1(i,n-1) {
	cout << i << " ";
	cout << i+1 << "\n";
      }
      cout << 1 << " ";
      cout << n << "\n";
      rep(i,m-n) {
	cout << p[0].second + 1 << " ";
	cout << p[1].second + 1 << "\n";	
      }
    }
  }
  return 0;
}
