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
  vector<double> x(n),y(n),z(n);
  rep(i,n) cin >> x[i] >> y[i] >> z[i];

  double ax = 0;
  rep(i,n) rep(j,n){
    if(i==j) continue;
    double kk = z[i]*z[j]/(z[i]+z[j])*fabs(x[i]-x[j]);
    double yy = z[i]*z[j]/(z[i]+z[j])*fabs(y[i]-y[j]);    
    ax = max(ax,max(kk,yy));
  }

  printf("%.5f\n", ax);
  return 0;
}
