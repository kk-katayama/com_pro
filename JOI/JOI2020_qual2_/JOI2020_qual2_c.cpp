#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int g(int x) {
  int res = x;
  while(x > 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}
int main()
{
  int n;cin >> n;
  vector<bool> f(n+1, false);
  vector<int> dp(n+1, 1);
  rep1(i,n) {
    if(f[i]) continue;
    int j = g(i);
    if(j <= n) dp[j] += dp[i];
  }
  //  rep1(i,n) cout << i << ":" << dp[i] << "\n";
  cout << dp[n] << "\n";
  return 0;
}
