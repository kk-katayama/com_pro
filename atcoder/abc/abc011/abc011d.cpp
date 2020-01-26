#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,d;
  cin >> n >> d;
  int x,y;
  cin >> x >> y;
  if(x%d!=0||y%d!=0){
    double res = 0.;
    printf("%.9f\n", res);
    return 0;
  }
  else{
    int xx = x/d;
    int yy = y/d;
    vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(2*n+1,vector<double>(2*n+1,0.)));
    dp[0][n-xx][n-yy] = 1.;
    rep(i,n){
      rep(nx,2*n+1){
	rep(ny,2*n+1){
	  if(nx>i){
	    dp[i+1][nx-1][ny] += dp[i][nx][ny]/4;
	  }
	  if(ny>i){
	    dp[i+1][nx][ny-1] += dp[i][nx][ny]/4;
	  }
	  if(nx<2*n-i){
	    dp[i+1][nx+1][ny] += dp[i][nx][ny]/4;
	  }
	  if(ny<2*n-i){
	    dp[i+1][nx][ny+1] += dp[i][nx][ny]/4;
	  }	  
	}
      }
    }
    printf("%.9f\n", dp[n][n][n]);
  }
  
  return 0;
}
