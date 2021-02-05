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
  int sum = 0;
  vvi b(2, vi(3));
  vvi c(3, vi(2));
  rep(i,2) {
    rep(j,3) {
      cin >> b[i][j];
      sum += b[i][j];
    }
  }
  rep(i,3) {
    rep(j,2) {
      cin >> c[i][j];
      sum += c[i][j];
    }
  }

  map<vi,int> dp;
  
  vi v;
  auto rec = [&](auto self, int cnt)->int{
    if(dp.find(v) != dp.end()) return dp[v];
    // for(auto val: v) cout << val << " ";
    // cout << "\n";
    if(cnt == 9) {
      int res = 0;
      vvi tab(3, vi(3));
      rep(i,9) {
	int x = v[i] / 3, y = v[i] % 3;
	tab[x][y] = (i % 2);
      }
      rep(i,2) {
	rep(j,3) {
	  if(tab[i][j] == tab[i+1][j]) res += b[i][j];
	}
      }
      rep(i,3) {
	rep(j,2) {
	  if(tab[i][j] == tab[i][j+1]) res += c[i][j];
	}
      }
      return dp[v] = res;
    }
    int res = (cnt % 2 == 0 ? -inf : inf);
    rep(i,9) {
      if(find(v.begin(), v.end(), i) == v.end()) {
	v.push_back(i);
	if(cnt % 2 == 0) chmax(res,self(self, cnt+1));
	else chmin(res,self(self, cnt+1));	
	v.pop_back();
      }
    }
    return dp[v] = res;
  };

  int ans = rec(rec, 0);
  cout << ans << "\n";
  cout << sum - ans << "\n";
  
  return 0;
}
