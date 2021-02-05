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
  vl x(n),y(n),z(n);
  rep(i,n) {
    cin >> x[i] >> y[i] >> z[i];
  }

  vvl c(n, vl(n, 0));
  rep(i,n) {
    rep(j,n) {
      c[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max((ll)0, z[i] - z[j]);
    }
  }

  vvl dp((1 << n), vl(n, infll));
  dp[0][0] = 0;
  rep(S,(1 << n)) {
    rep(i,n) {
      if(dp[S][i] == infll) continue;
      rep(j,n) {
	chmin(dp[S | (1 << j)][j], dp[S][i] + c[i][j]);
      }
    }
  }

  cout << dp[(1<<n)-1][0] << "\n";
  
  return 0;
}
