#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int dp[60][11000][60];
int main()
{
  int w;
  int n,k;
  cin >> w >> n >> k;
  vector<int> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];


  rep(i,n+1) rep(j,w+1) rep(l,k+1) dp[i][j][l] = 0;
  rep1(i,n){
    rep(j,w+1){
      rep1(l,k){
  	if(j-a[i-1]>=0) dp[i][j][l] = max(dp[i-1][j][l],dp[i-1][j-a[i-1]][l-1]+b[i-1]);
  	else dp[i][j][l] = dp[i-1][j][l];
      }
    }
  }

  int res=0;
  rep(l,k+1){
    res = max(res,dp[n][w][l]);
  }

  cout << res << "\n";
  
  return 0;
}
