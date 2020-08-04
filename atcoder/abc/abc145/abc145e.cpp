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
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n; cin >> n;
  int t; cin >> t;
  vector<int> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];

  vector<vector<int>> dp1(n+1, vector<int>(t, 0)), dp2(n+1, vector<int>(t, 0));
  rep(i,n) {
    rep(j,t) {
      if(j - a[i] >= 0) dp1[i+1][j] = max(dp1[i][j], dp1[i][j-a[i]] + b[i]);
      else dp1[i+1][j] = dp1[i][j];
    }
  }
  for (int i = n; i > 0; --i) {
    rep(j,t) {
      if(j - a[i-1] >= 0) dp2[i-1][j] = max(dp2[i][j], dp2[i][j-a[i-1]] + b[i-1]);
      else dp2[i-1][j] = dp2[i][j];
    }
  }

  int res = 0;
  rep(i,n) {
    rep(j,t) {
      int idx = t - 1 - j;
      int tmp = dp1[i][j] + dp2[i+1][idx];
      chmax(res, tmp + b[i]);
    }
  }
  cout << res << "\n";
  
  return 0;
}
