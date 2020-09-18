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
  int n, t; cin >> n >> t;
  vi a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];
  
  vii dp1(n+1, vi(t+1, 0));
  vii dp2(n+1, vi(t+1, 0));

  rep1(i,n) {
    rep(j,t) {
      if(j - a[i-1] >= 0) dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j-a[i-1]] + b[i-1]);
      else dp1[i][j] = dp1[i-1][j];
    }
  }
  
  rev2(i,n-1,0) {
    rep(j,t) {
      if(j - a[i] >= 0) dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j-a[i]] + b[i]);
      else dp2[i][j] = dp2[i+1][j];
    }
  }  

  int res = 0;
  rep(i,n) {
    int tmp = 0;
    rep(j,t) {
      int k = t - j - 1;
      chmax(tmp, dp1[i][j] + dp2[i+1][k]);
    }
    chmax(res, tmp + b[i]);
  }
  cout << res << "\n";
  
  return 0;
}
