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
  ll w,h; cin >> w >> h;
  int n; cin >> n;
  vl x(n),y(n);
  rep(i,n) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  using ppl = pair<pl,pl>;
  map<ppl,ll> dp;
  map<ppl,ll> tab;
  auto rec = [&](auto self, pl a, pl b)->ll {
    if(tab[{a,b}] > 0) return dp[{a,b}];
    auto [lx, ly] = a;
    auto [hx, hy] = b;
    if(lx > hx || ly > hy) {
      tab[{a,b}] = 1;
      return dp[{a,b}] = 0;
    }
    //    cout << lx << ":" << ly << ":" << hx << ":" << hy << "\n";
    ll mx = 0;
    rep(i,n) {
      if(lx <= x[i] && x[i] <= hx && ly <= y[i] && y[i] <= hy) {
	ll sum = self(self, a, {x[i]-1, y[i]-1}) + self(self, {x[i]+1, ly}, {hx, y[i]-1}) + self(self, {lx, y[i]+1}, {x[i]-1, hy}) + self(self, {x[i]+1,y[i]+1}, b) + hx-lx+1 + hy-ly+1 - 1;
	chmax(mx, sum);	
      }
    }
    tab[{a,b}] = 1;
    return dp[{a,b}] = mx;
  };
  ll res = rec(rec, {0,0}, {w-1, h-1});
  for(auto tmp: dp) {
    auto [key, val] = tmp;
  }
  cout << res << "\n";
  
  return 0;
}
