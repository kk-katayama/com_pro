#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
int n;
double p[3010];
double dp[3010][3010];
int main()
{
  cin >> n;
  rep(i,n) cin >> p[i];

  rep(i,n+1) rep(j,n+1) dp[i][j] = 0;
  dp[0][0] = 1;

  rep(i,n){
    rep(j,i+1){
      dp[i+1][j] += dp[i][j] * p[i];
      dp[i+1][j+1] +=  dp[i][j] * ( 1 - p[i] );
    }
  }

  double res = 0;
  rep(j,(n+1)/2) res += dp[n][j];
  printf("%.9f\n", res);
  
  
  return 0;
}
