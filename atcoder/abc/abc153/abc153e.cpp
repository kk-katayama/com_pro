#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,n;
  cin >> h >> n;
  vector<int> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  const int inf = 1e+9+10;

  vector<vector<int>> dp(n+1,vector<int>(h+1,inf));
  dp[0][h] = 0;
  rep1(i,n){
    for(int j=h;j>=0;--j){
      if(j+a[i-1]>h){
	dp[i][j] = min(dp[i-1][j],b[i-1]);
      }
      else{
	dp[i][j] = min(dp[i-1][j],dp[i][j+a[i-1]]+b[i-1]);
      }
    }
  }

  cout << dp[n][0] << "\n";
  
  
  return 0;
}
