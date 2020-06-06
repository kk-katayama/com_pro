#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n;cin >> n;
  vector<vector<ll>> a(n, vector<ll>(n));
  rep(i,n) rep(j,n) cin >> a[i][j];

  vector<ll> cost((1 << n), 0);
  rep1(mask, (1<<n)-1) {
    rep(i, n) {
      rep(j, n) {
	if(i >= j) continue;
	if( ((mask >> i) & 1) && ((mask >> j) & 1) ) cost[mask] += a[i][j];
      }
    }
  }

  const ll inf = 1e+15;
  vector<ll> dp((1 << n), -inf);
  dp[(1<<n) - 1] = 0;
  for(int mask = (1<<n) - 1; mask > 0; --mask) {
    for(int i = mask; i > 0; i = (i-1)&mask) {
      chmax(dp[mask - i], dp[mask] + cost[i]);
    }
  }

  cout << dp[0] << "\n";
  
  return 0;
}
