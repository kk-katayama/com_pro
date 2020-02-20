#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b;
  cin >> a >> b;
  int m;
  cin >> m;
  vector<int> x(m),y(m);
  rep(i,m){
    cin >> x[i] >> y[i];
    x[i]--;y[i]--;
  }

  vector<vector<int>> dp(a,vector<int>(b,0));
  rep(i,m){
    dp[x[i]][y[i]]=-1;
  }

  dp[0][0] = 1;
  
  rep(i,a){
    rep(j,b){
      if(dp[i][j]==-1) continue;
      if(i-1>=0){
	if(dp[i-1][j]!=-1){
	  dp[i][j] += dp[i-1][j];
	}
      }
      if(j-1>=0){
	if(dp[i][j-1]!=-1){
	  dp[i][j] += dp[i][j-1];
	}
      }
    }
  }

  
  a--;b--;
  cout << dp[a][b] << "\n";
  
  
  return 0;
}
