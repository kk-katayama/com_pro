#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<pair<ll,int>> p(n);
  rep(i,n) p[i] = {-a[i], i};
  sort(p.begin(), p.end());
  vector<vector<ll>> dp(n+1, vector<ll>(n+1,0));
  rep(i,n) {
    rep(j,n) {
      if(i + j >= n) continue;
      chmax(dp[i+1][j], dp[i][j] - p[i+j].first * (ll)abs(p[i+j].second - i));
      chmax(dp[i][j+1], dp[i][j] - p[i+j].first * (ll)abs(n - 1 - j - p[i+j].second) );
    }
  }

  ll res = 0;
  rep(i,n) {
    rep(j,n) {
      if(i + j > n) continue;
      if(i + j == n) {
	chmax(res, dp[i][j]);
      }
    }
  }
  cout << res << "\n";
  
  return 0;
}
