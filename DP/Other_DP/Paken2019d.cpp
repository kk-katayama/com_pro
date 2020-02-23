#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<string> s(5);
  rep(i,5) cin >> s[i];
  vector<vector<int>> cost(n,vector<int>(3,0));
  rep(i,n){
    rep(j,5){
      if(s[j][i]!='R') cost[i][0]++;
      if(s[j][i]!='B') cost[i][1]++;
      if(s[j][i]!='W') cost[i][2]++;
    }
  }

  
  vector<vector<int>> dp(n+1,vector<int>(3,1e+9));
  dp[1] = cost[0];
  rep1(i,n-1){
    rep(j,3){
      if(j==0){
	dp[i+1][1] = min(dp[i+1][1],dp[i][j]+cost[i][1]);
	dp[i+1][2] = min(dp[i+1][2],dp[i][j]+cost[i][2]);	
      }
      else if(j==1){
	dp[i+1][0] = min(dp[i+1][0],dp[i][j]+cost[i][0]);
	dp[i+1][2] = min(dp[i+1][2],dp[i][j]+cost[i][2]);	
      }
      else{
	dp[i+1][0] = min(dp[i+1][0],dp[i][j]+cost[i][0]);
	dp[i+1][1] = min(dp[i+1][1],dp[i][j]+cost[i][1]);	
      }            
    }
  }

  
  cout << (int)min(dp[n][0],min(dp[n][1],dp[n][2])) << "\n";
  
  return 0;
}
