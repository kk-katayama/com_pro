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
  ll d; cin >> d;
  auto f = [](ll x, ll k)->ll {
    ll res = 0;
    rep(i,k) {
      res += x;
      x /= 2;
    }
    return res;
  };

  ll res = infll;
  rep1(k,70) {
    ll lb = 0, ub = infll/2;
    while(ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      (f(mid, k) >= d ? ub : lb) = mid;
    }
    if(f(ub, k) == d) chmin(res, ub);
  }
  cout << res << "\n";
  return 0;
}
