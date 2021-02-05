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
  vi p(n-1);
  rep(i,n-1) {
    cin >> p[i];
    p[i]--;
  }
  vi x(n);
  rep(i,n) cin >> x[i];

  vvi edge(n);
  rep(i,n-1) {
    edge[p[i]].push_back(i+1);
  }

  auto merge = [&](map<int,int> a, map<int,int> b)->map<int,int> {
    map<int,int> res;
    for(auto atmp: a) {
      auto [akey, aval] = atmp;
      for(auto btmp: b) {
        auto [bkey, bval] = btmp;
        if(akey + bkey > 5000) continue;
        res[akey+bkey] = 1;
      }
    }
    return res;
  };

  vi d(n, 0);
  auto dfs = [&](auto self, int v)->map<int,int> {
    map<int,int> mp;
    mp[0] = 1;
    for(auto w: edge[v]) {
      mp = merge(mp, self(self, w));
      d[v] += d[w];
    }
    map<int,int> res;
    int mx = -1;
    for(auto tmp: mp) {
      auto [key, val] = tmp;
      if(key <= x[v]) {
        mx = key;
      }
    }
    if(d[v] - mx < 0 || mx == -1) {
      cout << "IMPOSSIBLE\n";
      exit(0);
    }
    if(d[v] - mx <= 5000) res[d[v] - mx] = 1;
    res[x[v]] = 1;
    d[v] = x[v] + d[v] - mx;
    return res;
  };

  dfs(dfs, 0);
  cout << "POSSIBLE\n";

  return 0;
}
