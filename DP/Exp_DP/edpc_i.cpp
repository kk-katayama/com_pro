#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
double dp[3010][3010];
int main()
{
  int n;cin >> n;
  vector<double> p(n);
  rep(i,n) cin >> p[i];


  rep(i,n+1) rep(j,n+1) dp[i][j] = 0;
  dp[0][0] = 1;

  rep(i,n) {
    rep(j,n+1) {
      dp[i+1][j] += dp[i][j]*(1 - p[i]);
      if(j != n) dp[i+1][j+1] += dp[i][j]*p[i];
    }
  }
  
  double res = 0;
  for (int i = (n+1)/2; i <= n; ++i) {
    res += dp[n][i];
  }

  printf("%.9f\n", res);
  
  return 0;
}
