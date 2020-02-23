#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  ll dp[110][30];
  rep(i,n) rep(j,25) dp[i][j] = 0;
  dp[1][a[0]] = 1;
  rep1(i,n-2){
    rep(j,21){
      if(j+a[i]<=20) dp[i+1][j+a[i]] += dp[i][j];
      if(j-a[i]>=0) dp[i+1][j-a[i]] += dp[i][j];
    }
  }

  cout << dp[n-1][a[n-1]] << "\n";
  return 0;
}
