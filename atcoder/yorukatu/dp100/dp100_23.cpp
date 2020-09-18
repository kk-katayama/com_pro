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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
int main()
{
  int n,m; cin >> n >> m;
  vi x(m), y(m);
  rep(i,m) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  vii tab(n);
  rep(i,m) {
    tab[x[i]].push_back(y[i]);
  }
  
  vector<ll> dp((1 << n), 0);
  dp[0] = 1;
  rep(mask,(1 << n)) {
    rep(i,n) {
      bool f = false;
      for(auto val: tab[i]) {
	if((mask >> val) & 1) f = true;
      }
      if(f) continue;
      if(!((mask >> i) & 1)) {
	dp[mask | (1 << i)] += dp[mask];
      }
    }
  }
  cout << dp[(1 << n) - 1] << "\n";
  return 0;
}
