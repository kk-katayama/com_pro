#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
const ll INFLL = 1e+15;
int n;
ll wmax;
int v[110];
ll w[110];
ll dp[110][100010];
int main()
{
  cin >> n >> wmax;
  rep(i,n) cin >> w[i] >> v[i];
  
  rep(i,n+1){
    rep(j,100010){
      dp[i][j] = INFLL;
    }
  }
  dp[0][0] = 0;

  rep(i,n){
    rep(j,100010){
      if(j-v[i] < 0) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = min( dp[i][j] , dp[i][j-v[i]] + w[i] );
    }
  }

  int res = 0;
  rep(j,100010){
    if(dp[n][j] <= wmax) res = j;
  }
  cout << res << "\n";
  return 0;
}
