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
  vector<pair<char, int>> p(2*n);
  rep(i,2*n) {
    char c; int a;
    cin >> c >> a;
    p[i] = {c, a};
  }

  int res = 0;
  vvi sum(2*n, vi(n+1, 0));
  rep(i,2*n) {
    auto [c, a] = p[i];
    rep(j,2*n) {
      if(i >= j) continue;
      auto [nc, na] = p[j];
      if(c == nc && a > na) res++;
      if(c != nc) {
	int id = (nc == 'B' ? 0 : n) + na - 1;
	sum[id][0]++;
	sum[id][a]--;
      }
    }
  }

  rep(i,2*n) {
    rep(j,n) {
      sum[i][j+1] += sum[i][j];
    }
  }
  
  vvi dp(n+1, vi(n+1, inf));
  dp[0][0] = 0;
  rep(i,n+1) {
    rep(j,n+1) {
      if(i + 1 <= n) {
	chmin(dp[i+1][j], dp[i][j] + sum[i][j]);
      }
      if(j + 1 <= n) {
	chmin(dp[i][j+1], dp[i][j] + sum[n+j][i]);
      }
    }
  }
  
  cout << res + dp[n][n] << "\n";
  
  return 0;
}
