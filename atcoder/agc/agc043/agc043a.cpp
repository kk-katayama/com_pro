#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w;cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w));
  rep(i,h) rep(j,w) cin >> s[i][j];

  vector<vector<int>> dp(h,vector<int>(w,1e+9));
  if(s[0][0] == '#') dp[0][0] = 1;
  else dp[0][0] = 0;
  rep(i,h) rep(j,w){
    if(i+1<h){
      if(s[i][j] == '.' && s[i+1][j] == '#') dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1);
      else dp[i+1][j] = min(dp[i+1][j],dp[i][j]);      
    }
    if(j+1<w){
       if(s[i][j] == '.' && s[i][j+1] == '#') dp[i][j+1] = min(dp[i][j+1],dp[i][j]+1);
      else dp[i][j+1] = min(dp[i][j+1],dp[i][j]);      
    }    
  }

  cout << dp[h-1][w-1] << "\n";
  
  return 0;
}
