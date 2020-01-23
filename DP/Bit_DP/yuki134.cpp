#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int x0,y0;
  cin >> x0 >> y0;
  int n;
  cin >> n;
  vector<int> x(n+1),y(n+1);
  vector<double> w(n+1);
  rep(i,n) cin >> x[i] >> y[i] >> w[i];
  x[n] = x0;
  y[n] = y0;
  w[n] = 0;

  double inf = 1000000000;
  vector<vector<double>> dp(1<<(n+1));
  rep(i,(1<<(n+1))) dp[i].assign(n+1,inf);
  dp[0][0] = 0;
  rep(S,(1<<(n+1))){
    rep(v,)
  }

  return 0;
}
