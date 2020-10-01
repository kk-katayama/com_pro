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
  int n; cin >> n;
  using pld = pair<ld,ld>;
  vector<pld> p(n);
  rep(i,n) {
    cin >> p[i].first >> p[i].second;
  }

  sort(p.begin(), p.end(), [](pld a, pld b) {
			     return atan2(a.second, a.first) < atan2(b.second, b.first);
			   });

  ld res = 0;
  rep(i,n) {
    ld xx = 0, yy = 0;
    rep(j,n) {
      int k = (i + j) % n;
      xx += p[k].first; yy += p[k].second;
      chmax(res, sqrt(xx*xx + yy*yy));
    }
  }

  printf("%.10Lf\n", res);
  
  return 0;
}
