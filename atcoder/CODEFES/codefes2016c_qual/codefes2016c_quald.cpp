#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w;
  cin >> h >> w;
  //  if(w>3) return 0;
  char c[310][310];
  rep(i,h) rep(j,w) cin >> c[i][j];

  int res=0;
  rep(a,w-1){
    vector<vector<int>> dp(h+2,vector<int>(h+2,1e+9));    
    vector<vector<int>> cn(h+1,vector<int>(h+1,0));
    rep(i,h+1) rep(j,h+1){
      int cnt = 0;
      for(int k=0;k<(int)min(h-i,h-j);++k){
	if(c[k+i][a]==c[k+j][a+1]) cnt++;
      }
      cn[i][j] = cnt;
    }

    // rep(i,h){
    //   rep(j,h){
    //     cout << cn[i][j] << " ";
    //   }
    //   cout  << "\n";
    // }

    dp[0][0] = 0;
    rep(i,h+1){
      rep(j,h+1){
	dp[i+1][j] = min(dp[i+1][j],dp[i][j]+cn[i][j]);
	dp[i][j+1] = min(dp[i][j+1],dp[i][j]+cn[i][j]);      
      }
    }

    //    cout << dp[h][h] << "\n";
    res += dp[h][h];
    cout << a << ":" << dp[h][h] << "\n";
  }
  cout << res << "\n";
  return 0;
}
