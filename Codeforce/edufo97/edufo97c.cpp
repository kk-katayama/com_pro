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
    vi t(n);
    rep(i,n) cin >> t[i];

    sort(t.begin(), t.end());
    vi dp1(410, inf/2);
    dp1[0] = 0;
    rep(i,n) {
      vi dp2(410, inf/2);
      rep(j,410) {
	rep(k,410) {
	  if(j < k) {
	    chmin(dp2[k], dp1[j] + abs(t[i] - k));
	  }
	}
      }
      swap(dp1, dp2);
    }
    int res = inf;
    rep(i,410) {
      chmin(res, dp1[i]);
    }
    cout << res << "\n";
  }
  return 0;
}
