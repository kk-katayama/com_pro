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
#include <bitset>
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
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  vvi flag(n, vi(n, 0));
  rep(i,n) {
    rep(j,n) {
      int f = 1;
      rep(k,m) {
	if(s[i][k] != '*' && s[j][k] != '*' && s[i][k] != s[j][k]) f = 0;
      }
      flag[i][j] = f;
    }
  }

  vi tab((1 << n), 0);
  rep(S, (1 << n)) {
    vi v;
    rep(i,n) {
      if((S >> i) & 1) v.push_back(i);
    }
    int f = 1;
    rep(i,sz(v)) {
      rep(j,sz(v)) {
	if(!flag[v[i]][v[j]]) f = 0;
      }
    }
    tab[S] = f;
  }

  vi dp((1<<n), inf);
  auto rec = [&](auto self, int S) ->int{
	       if(S == 0) return 0;
	       if(dp[S] != inf) return dp[S];
	       int res = inf;
	       for(int i=S;i>0;i=(i-1)&S){
		 if(tab[i]) {
		   chmin(res, self(self, S - i) + 1);
		 }
	       }
	       return dp[S] = res; 
	     };

  cout << rec(rec, (1<<n)-1) << "\n";
  
  return 0;
}
