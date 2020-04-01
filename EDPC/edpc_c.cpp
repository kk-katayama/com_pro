#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n),b(n),c(n);
  rep(i,n) cin >> a[i] >> b[i] >> c[i];
  vector<vector<int>> v(n,vector<int>(3));
  rep(i,n){
    v[i][0] = a[i];
    v[i][1] = b[i];
    v[i][2] = c[i];
  }
  vector<vector<int>> dp(n+1,vector<int>(3,0));
  rep(i,n){
    rep(j,3){
      dp[i+1][ (j + 1) % 3 ] = max( dp[i+1][ (j + 1) % 3 ] , dp[i][j] + v[i][j] );
      dp[i+1][ (j + 2) % 3 ] = max( dp[i+1][ (j + 2) % 3 ] , dp[i][j] + v[i][j] );      
    }
  }

  cout << max( dp[n][0] , max( dp[n][1] , dp[n][2] ) ) << "\n";
  
  return 0;
}
