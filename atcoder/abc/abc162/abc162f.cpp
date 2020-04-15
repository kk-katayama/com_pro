#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b){ if(a < b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(a > b) { a=b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  if(n % 2 == 0) {
    vector<vector<ll>> dp(n/2 + 1, vector<ll>(2, -1e+15));
    dp[0][0] = 0;
    rep(i,n/2) {
      chmax(dp[i+1][0], dp[i][0] + a[i*2]);
      chmax(dp[i+1][1], dp[i][0] + a[i*2 + 1]);
      chmax(dp[i+1][1], dp[i][1] + a[i*2 + 1]);            
    }
    cout << max(dp[n/2][0], dp[n/2][1]) << "\n";
  }
  else {
    vector<vector<ll>> dp(n/2 + 1, vector<ll>(3, -1e+15));
    dp[0][0] = 0;
    rep(i,n/2) {
      chmax(dp[i+1][0], dp[i][0] + a[i*2]);
      chmax(dp[i+1][1], dp[i][0] + a[i*2 + 1]);
      chmax(dp[i+1][1], dp[i][1] + a[i*2 + 1]);
      chmax(dp[i+1][2], dp[i][0] + a[i*2 + 2]);      
      chmax(dp[i+1][2], dp[i][1] + a[i*2 + 2]);
      chmax(dp[i+1][2], dp[i][2] + a[i*2 + 2]);      
    }
    cout << max(dp[n/2][0], max(dp[n/2][1], dp[n/2][2])) << "\n";
  }
  
  
  return 0;
}
