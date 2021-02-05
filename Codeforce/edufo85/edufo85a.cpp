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
  int q; cin >> q;
  while(q-- > 0) {
    int n; cin >> n;
    vi p(n+1),c(n+1);
    rep1(i,n) cin >> p[i] >> c[i];
    p[0] = c[0] = 0;
    bool f = true;
    rep(i,n) {
      int dp = p[i+1] - p[i];
      int dc = c[i+1] - c[i];
      if(dp < 0 || dc < 0 || dp < dc) {
	f = false;
      }
    }
    cout << (f ? "YES" : "NO") << "\n";

  }
  return 0;
}
