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
struct info{
  int m,id;
};
int main()
{
  int q; cin >> q;
  while(q-- > 0) {
    int n,m; cin >> n >> m;
    map<int,int> mp;
    rep(i,m) {
      int a,b; cin >> a >> b;
      if(mp[b] == 0) mp[b] = a;
      else mp[b] = 3;
    }

    vector<info> p;
    for(auto tmp: mp) {
      auto [ky, vl] = tmp;
      p.push_back({ky, vl});
    }

    p.push_back({n, 3});
    bool f = true;
    rep(i,sz(p)) {
      //      cout << p[i].m << " " << p[i].id << "\n";
      if(p[i].id == 3) continue;
      else {
	if(p[i+1].id == 3) f = false;
	else {
	  if(p[i].id == p[i+1].id) {
	    if((p[i+1].m - p[i].m) % 2 == 0) f = false;
	  }
	  else {
	    if((p[i+1].m - p[i].m) % 2 == 1) f = false;
	  }	  
	}
	i++;
      }
    }
    cout << (f ? "Yes" : "No") << "\n";

  }
  return 0;
}
