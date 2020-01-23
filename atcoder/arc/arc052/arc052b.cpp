#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
double pow3(double x){
  return x*x*x;
}
int main()
{
  const double pi = 4*atan(1);
  int n,q;
  cin >> n >> q;
  vector<double> x(n),r(n),h(n);
  rep(i,n){
    cin >> x[i];
    cin >> r[i];
    cin >> h[i];
  }
  vector<int> a(q),b(q);
  rep(i,q){
    cin >> a[i];
    cin >> b[i];
  }

  int xmax=10000;
  vector<double> vol(xmax,0.);
  
  rep(i,xmax){
    double z=i;
    rep(j,n){
      if(x[j]+h[j]<=z||z+1.<=x[j]) continue;
      double c=min(h[j]+x[j]-z,h[j]);
      double d=max(h[j]+x[j]-z-1.,0.);
      double res=pi*r[j]*r[j]*h[j]/3*(pow3(c/h[j])-pow3(d/h[j]));
      vol[i] += res;
    }
  }

  vector<double> cum(xmax+1);
  cum[0]=0.;
  rep(i,xmax){
    cum[i+1]=cum[i]+vol[i];
  }

  rep(i,q){
    printf("%.5f\n", cum[b[i]]-cum[a[i]]);
  }
  
  return 0;
}
