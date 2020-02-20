#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  vector<double> p(n);
  rep(i,n){
    cin >> p[i];
  }

  vector<double> e(n);
  rep(i,n){
    e[i] = (p[i]+1.)*p[i]/2/p[i];
  }
  vector<double> sum(n+1);
  sum[0] = 0.;
  rep(i,n){
    sum[i+1] = sum[i] + e[i];
  }

  double res = 0.;
  for(int i=0;i+k<=n;++i){
    res = max(res,sum[i+k]-sum[i]);
  }

  printf("%.7f\n", res);
  
  return 0;
}
