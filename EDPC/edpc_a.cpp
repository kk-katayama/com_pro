#include <iostream>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
const int INF = 1e+9;
int n;
int h[100010];
int dp[100010];
int main()
{
  cin >> n;
  rep(i,n) cin >> h[i];
  rep(i,n) dp[i]=INF;
  dp[0]=0;
  rep(i,n-1){
    if(i==n-2) dp[i+1] = min(dp[i+1],dp[i]+abs(h[i]-h[i+1]));
    else{
      dp[i+2] = min(dp[i+2],dp[i]+abs(h[i+2]-h[i]));
      dp[i+1] = min(dp[i+1],dp[i]+abs(h[i+1]-h[i]));
    }
  }
  cout << dp[n-1] << "\n";
  return 0;
}
