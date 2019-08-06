#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
string s,t;
int dp[3010][3010];
int main()
{
  cin >> s >> t;
  int ss = s.size(),ts = t.size();

  rep(i,ss+1){
    rep(j,ts+1){
      dp[i][j] = 0;
    }
  }
  
  rep(i,ss){
    rep(j,ts){
      if(s[i]==t[j]){
	dp[i+1][j+1] = max( dp[i][j]+1 , max( dp[i][j+1] , dp[i+1][j] ) ); 
      }
      else{
	dp[i+1][j+1] = max( dp[i][j+1] , dp[i+1][j] );
      }
    }
  }
  
  cout << dp[ss][ts] << "\n";

  return 0;
}
