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
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int n,m; cin >> n >> m;
  vii edge(n);
  vii rev(n);
  while(m-- > 0) {
    int a,b; cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    rev[b].push_back(a);
  }

  vi used(n, 0);
  used[0] = 1;
  auto dfs = [&](auto f, int v) ->void{
	       used[v] = 1;
	       for(auto w: rev[v]) {
		 if(used[w] == 0) {
		   f(f, w);
		 }
	       }
	     };

  dfs(dfs, 0);
  
  int q; cin >> q;
  while(q-- > 0) {
    int x,y; cin >> x >> y;
    y--;
    if(x == 1) {
      if(used[y] == 0) dfs(dfs, y);
    }
    else {
      if(used[y] == 1) cout << "YES" << "\n";
      else cout << "NO" << "\n";
    }
  }


  return 0;
}
