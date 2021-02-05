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
  int x,y; cin >> x >> y;
  int n; cin >> n;
  vi t(n),h(n);
  rep(i,n) {
    cin >> t[i] >> h[i];
  }

  vvi dp1(x+1, vi(y+1, 0));
  rep(i,n) {
    vvi dp2(x+1, vi(y+1, 0));
    rep(j,x+1) {
      rep(k,y+1) {
	chmax(dp2[j][k], dp1[j][k]);
	if(j + k < t[i] || j == 0) continue;
	if(k - (t[i] - 1) >= 0) {
	  chmax(dp2[j - 1][k - (t[i] - 1)], dp1[j][k] + h[i]);
	}
	else {
	  chmax(dp2[j - (t[i] - k)][0], dp1[j][k] + h[i]);
	}
      }
    }
    swap(dp1, dp2);
  }

  int res = 0;
  rep(i,x+1) rep(j,y+1) chmax(res, dp1[i][j]);
  cout << res << "\n";
  
  return 0;
}
