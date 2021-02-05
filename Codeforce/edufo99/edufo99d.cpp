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
    int n,x; cin >> n >> x;
    vi a(n);
    rep(i,n) cin >> a[i];

    vvi dp1(510, vi(510, inf/2));
    dp1[0][x] = 0;
    rep(i,n) {
      vvi dp2(510, vi(510, inf/2));
      rep(j,510) {
	rep(k,510) {
	  if(j <= a[i]) {
	    chmin(dp2[a[i]][k], dp1[j][k]);
	  }
	  if(j <= k && a[i] > k) {
	    chmin(dp2[k][a[i]], dp1[j][k]+1);
	  }	  
	}
      }
      swap(dp1, dp2);
    }
    int res = inf/2;
    rep(i,510) {
      rep(j,510) {
	chmin(res, dp1[i][j]);
      }
    }
    cout << (res == inf/2 ? -1 : res) << "\n";
  }
  return 0;
}
