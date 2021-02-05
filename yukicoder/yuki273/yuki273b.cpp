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
  ll n,m,c; cin >> n >> m >> c;
  vl a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  sort(b.begin(), b.end());
  ll sum = 0;
  rep(i,n) {
    ll lb = -1, ub = m;
    while(ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      (c / a[i] < b[mid] ? ub : lb) = mid;
    }
    sum += m - ub;
  }
  ld res = (ld)sum / (ld)(n*m);
  printf("%.10Lf\n", res);
  
  return 0;
}
