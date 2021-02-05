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
#define sz(v) (int)v.size()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
    int n,k; cin >> n >> k;
    vi x(n); rep(i,n) scanf("%d", &x[i]);
    int y;
    rep(i,n) {
      scanf("%d", &y);
    }
    sort(x.begin(), x.end());
    vi v(n);
    rep(i,n) {
      int lb = -1, ub = n;
      while(ub - lb > 1) {
	int mid = (ub + lb) / 2;
	(x[mid] > x[i] + k ? ub : lb) = mid;
      }
      v[i] = ub - i;
    }

    vi suf(n+1);
    suf[n] = 0;
    for (int i = n-1; i >= 0; --i) {
      suf[i] = max(suf[i+1], v[i]);
    }
    int res = 0;
    rep(i,n) {
      int tmp = v[i] + suf[v[i]+i];
      chmax(res, tmp);
    }
    cout << res << "\n";
  }
  return 0;
}
