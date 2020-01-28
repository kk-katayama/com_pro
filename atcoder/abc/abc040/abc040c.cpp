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
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  const int inf = 1e+9+10;
  vector<int> dp(n,inf);
  dp[0] = 0;
  rep(i,n){
    if(i+1<n){
      dp[i+1] = min(dp[i+1],dp[i]+abs(a[i]-a[i+1]));
    }
    if(i+2<n){
      dp[i+2] = min(dp[i+2],dp[i]+abs(a[i]-a[i+2]));
    }
  }
    
  cout << dp[n-1] << "\n";
  return 0;
}
