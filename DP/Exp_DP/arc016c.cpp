#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const double inf = 1e+9;
int n,m;
int c[4],cost[4];
int idol[4][10];
double p[4][10];
vector<double> dp;
double dfs(int S)
{  
  if(dp[S]>=0) return dp[S];
  double res = inf;
  
  rep(i,m){
    double xx = 0,yy = cost[i];
    rep(j,c[i]){
      if((S>>(idol[i][j]-1))&1){
	xx += p[i][j];
      }
      else{
	yy += p[i][j]/100*dfs(S|(1<<(idol[i][j]-1)));
      }
    }
    if(xx == 100) continue;
    res = min(res,100/(100-xx)*yy);
  }
  return dp[S] = res;
}
int main()
{
  cin >> n >> m;
  rep(i,m){
    cin >> c[i] >> cost[i];
    rep(j,c[i]){
      cin >> idol[i][j] >> p[i][j];
    }
  }

  dp.assign((1<<n),-1);
  dp[(1<<n)-1] = 0;
  
  printf("%.7f\n", dfs(0));
  
  return 0;
}
