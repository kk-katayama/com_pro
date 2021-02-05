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
  vi x(n),s(n);
  rep(i,n) {
    cin >> x[i] >> s[i];
  }

  vi l(n),r(n);
  rep(i,n) {
    l[i] = max(1, x[i] - s[i]);
    r[i] = min(m, x[i] + s[i]);
  }
  
  vi dp(m+1, inf);
  dp[0] = 0;
  rep1(i,m) {
    dp[i] = i;
    rep(j,n) {
      if(i < l[j]) continue;
      if(l[j] <= i && i <= r[j]) {
	chmin(dp[i], dp[i-1]);
      }
      else {
	int x = i - r[j];
	chmin(dp[i], dp[max(0, l[j] - x - 1)] + x);
      }
    }
    //    cout << i << ":" << dp[i] << "\n";
  }
  cout << dp[m] << "\n";
  
  return 0;
}
