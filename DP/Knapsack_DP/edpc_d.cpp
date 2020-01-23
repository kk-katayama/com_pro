#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
int n,wmax;
int w[110];
ll v[110];
ll dp[110][100010];
int main()
{
  cin >> n >> wmax;
  rep(i,n) cin >> w[i] >> v[i];

  rep(i,n+1){
    rep(j,wmax+1){
      dp[i][j] = 0;
    }
  }

  rep(i,n){
    rep(j,wmax+1){
      if(j-w[i]<0) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = max( dp[i][j] , dp[i][j-w[i]] + v[i] );
    }
  }
  
  cout << dp[n][wmax] << "\n";
  return 0;
}


