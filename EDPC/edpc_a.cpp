#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  vector<int> dp(n,1e+9);
  dp[0] = 0;
  rep(i,n){
    if( i + 2 < n ) dp[i+2] = min( dp[i+2] , dp[i] + abs(h[i] - h[i+2]) );
    if( i + 1 < n ) dp[i+1] = min( dp[i+1] , dp[i] + abs(h[i] - h[i+1]) );    
  }
  cout << dp[n-1] << "\n";
  return 0;
}
