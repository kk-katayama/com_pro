#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  int m = pow(2,n);
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  
  vector<vector<int>> dp(m);
  rep(i,m) dp[i].resize(n+1);
  rep(i,m) dp[i][0] = a[i];

  rep(j,n){
    rep(i,m){
      if(i&(1<<j)){
	dp[i][j+1] = dp[i&~(1<<j)][j] + dp[i][j];
      }
      else{
	dp[i][j+1] = dp[i][j];
      }
    }
  }

  rep(i,m){
    rep(j,n+1){
      cout << dp[i][j] << " ";
    }
    cout <<  "\n";
  }
  
  rep(i,m){
    cout << dp[i][n] << "\n";
  }
  
  return 0;
}
