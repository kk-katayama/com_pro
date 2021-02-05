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
  int n; cin >> n;
  ll x; cin >> x;
  vl a(n);
  rep(i,n) cin >> a[i];

  map<pair<ll,int>,ll> dp;
  auto rec = [&](auto self, ll d, int i)->ll {
    if(i == n - 1) return dp[{d, i}] = ll(1);
    if(dp.find({d, i}) != dp.end() ) return dp[{d, i}];
    if(d % a[i+1] == 0) {
      return dp[{d, i}] = self(self, d, i+1);
    }
    else {
      ll res = self(self, d - d%a[i+1], i+1) + self(self, d + a[i+1] - d%a[i+1], i+1);
      return dp[{d, i}] = res;
    }
  };

  cout << rec(rec, x, 0) << "\n";
  
  return 0;
}
