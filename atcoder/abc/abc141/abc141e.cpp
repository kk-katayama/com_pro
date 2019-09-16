#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  string s;
  cin >> n >> s;

  string t = s;
  vector<vector<int>> dp(n+1);
  rep(i,n+1) dp[i].assign(n+1,0);

  rep1(i,n){
    rep1(j,n){
      if(s[i-1]==t[j-1]&&dp[i-1][j-1]<abs(i-j)){
	dp[i][j] = dp[i-1][j-1] + 1;
      }
    }
  }

  int res = 0;
  rep(i,n+1){
    rep(j,n+1){
      res = max(res,dp[i][j]);
    }
  }
  
  cout << res << "\n";
  
  return 0;
}
