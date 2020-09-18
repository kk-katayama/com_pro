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
  int n,p; cin >> n >> p;
  vector<pi> ab(n);
  rep(i,n) cin >> ab[i].F >> ab[i].S;

  sort(ab.begin(), ab.end(), [](pi a, pi b) {
			       if(a.F == b.F) return a.S > b.S;
			       else return a.F > b.F;
			     });
  vii dp(n+1, vi(p+1, 0));
  int res = 0;
  rep1(i,n) {
    chmax(res, ab[i-1].S + dp[i-1][p]);
    rep(j,p+1) {
      if(j - ab[i-1].F >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-ab[i-1].F] + ab[i-1].S);
      else dp[i][j] = dp[i-1][j];
    }
  }
  cout << res << "\n";
  
  return 0;
}
