#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
const int INF = 1e+9;
int n,k;
int h[100010];
int dp[100010];
int main()
{
  cin >> n >> k;
  rep(i,n) cin >> h[i];
  rep(i,n) dp[i] = INF;
  dp[0] = 0;
  rep(i,n){
    rep1(j,k){
      if(i+j > n-1) break;
      dp[i+j] = min(dp[i+j],dp[i] + abs(h[i+j]-h[i]) );
    }
  }
  cout << dp[n-1] << "\n";
  return 0;
}
