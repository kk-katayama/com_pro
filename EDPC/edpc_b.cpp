#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  vector<int> dp(n,1e+9);
  dp[0] = 0;
  rep(i,n){
    rep1(j,k){
      if( i + j >= n) break;
      dp[i+j] = min( dp[i+j] , dp[i] + abs(h[i] - h[i+j]) );
    }
  }
  cout << dp[n-1] << "\n";
  return 0;
}
