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
  int n,m; cin >> n >> m;
  vvi edge(n, vi(n, 0));
  rep(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    edge[a][b] = 1;
    edge[b][a] = 1;
  }

  vl dp((1<<n), 0);  
  //  vi tab((1<<n), 0);
  dp[0] = 1;
  rep(S, (1<<n)) {
    if(dp[S]) {
      rep(i,n) {
	bool f = true;
	rep(j,n) {
	  if((S>>j)&1) {
	    if(!edge[i][j]) f = false;
	  }
	}
	if(f) dp[S|(1<<i)] = 1;
      }
    }
  }

  //  rep(i,sz(tab)) cout << i << ":" << tab[i] << "\n";
  

  auto rec = [&](auto self, int mask)->int {
    //    cout << bitset<8>(mask) << "\n";
    if(dp[mask] > 0) return dp[mask];
    //    if(tab[mask]) return dp[mask] = 1;
    int res = 50;
    for(int i=mask;i>0;i=(i-1)&mask){
      if(i == mask) continue;
      //      int tmp =  self(self, i) + self(self, mask-i);
      chmin(res, self(self, i) + self(self, mask-i));
    }
    return dp[mask] = res;
  };

  int ans = rec(rec, (1<<n)-1);
  cout << ans << "\n";
  
  return 0;
}
