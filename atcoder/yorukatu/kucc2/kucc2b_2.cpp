#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
  }

  int M = 30000;
  vector<vector<bool>> dp(n+1, vector<bool>(3*M+1, false));
  dp[0][0] = true;
  rep(i,n) {
    rep(j,3*M+1) {
      if(!dp[i][j]) continue;
      if( j + a[i] <= 3*M) dp[i+1][j+a[i]] = true;
      dp[i+1][ abs(j - a[i]) ] = true;
    }
  }

  int res = 1e+9;
  rep(i,3*M+1) if(dp[n][i]) chmin(res, i);
  cout << res << "\n";
  
  return 0;
}
