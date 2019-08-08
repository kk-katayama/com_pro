#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
int n;
int a[100010],b[100010],c[100010];
int dp[100010][3];
int main()
{
  cin >> n;
  rep(i,n) cin >> a[i] >> b[i] >> c[i];
  rep(i,n+1){
    rep(j,3){
      dp[i][j] = 0;
    }
  }
  
  rep(i,n){
    rep(j,3){
      if(j==0){
	dp[i+1][1] = max( dp[i+1][1] , dp[i][j]+b[i] );
	dp[i+1][2] = max( dp[i+1][2] , dp[i][j]+c[i] );	  
      }
      else if(j==1){
	dp[i+1][0] = max( dp[i+1][0] , dp[i][j]+a[i] );
	dp[i+1][2] = max( dp[i+1][2] , dp[i][j]+c[i] );	  
      }
      else {
	dp[i+1][0] = max( dp[i+1][0] , dp[i][j]+a[i] );
	dp[i+1][1] = max( dp[i+1][1] , dp[i][j]+b[i] );	  
      }      
    }
  }
  cout << max( max( dp[n][0] , dp[n][1] ) , dp[n][2]) << "\n";
  return 0;
}
