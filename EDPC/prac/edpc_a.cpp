#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  vector<int> dp(n,2e+9);
  dp[0] = 0;
  rep(i,n){
    if(i-2>=0) dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    else if(i-1>=0) dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
  }
  cout << dp[n-1] << "\n";
  return 0;
}
