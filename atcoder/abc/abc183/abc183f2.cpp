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
  int n,q; cin >> n >> q;
  vi c(n);
  rep(i,n) cin >> c[i];
  vector<map<int,int>> mp(n);
  rep(i,n) {
    mp[i][c[i]]++;
  }

  vi uf(n);
  vi siz(n, 1);
  rep(i,n) uf[i] = i;

  while(q-- > 0) {
    int t,x,y; cin >> t >> x >> y;
    if(t == 1) {
      x--; y--;
      if(uf[x] == uf[y]) continue;
      if(siz[uf[x]] < siz[uf[y]]) swap(x, y);
      for(auto val: mp[uf[y]]) {
	auto [id, num] = val;
	mp[uf[x]][id] += num;
      }
      uf[y] = uf[x];
      siz[x] += siz[y];
    }
    else {
      x--; 
      cout << mp[uf[x]][y] << "\n";
    }
  }

  return 0;
}
