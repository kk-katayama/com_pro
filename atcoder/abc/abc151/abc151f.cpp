#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

double R(double x,double y,double z,double w){
  return sqrt((x-z)*(x-z)+(y-w)*(y-w));
}

int main()
{
  int n;
  cin >> n;
  vector<double> x(n),y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }

  double res = 100000.;
  rep(i,n){
    rep(j,n){
      if(i==j) continue;
      double p = (x[i]+x[j])/2;
      double q = (y[i]+y[j])/2;
      double r = R(x[i],y[i],x[j],y[j])/2;
      bool f = true;
      rep(k,n){
	if(R(p,q,x[k],y[k])>r){
	  f = false;
	  break;
	}
      }
      if(f){
	res = min(res,r);
      }
    }
  }

  rep(i,n){
    rep(j,n){
      if(i==j) continue;
      rep(k,n){
	if(i==k||j==k) continue;
	double p = ((y[k]-y[i])*(x[j]*x[j]+y[j]*y[j]-x[i]*x[i]-y[i]*y[i])-(y[j]-y[i])*(x[k]*x[k]+y[k]*y[k]-x[i]*x[i]-y[i]*y[i]))/(2*((y[k]-y[i])*(x[j]-x[i])-(y[j]-y[i])*(x[k]-x[i])));
	double q = ((x[k]-x[i])*(x[j]*x[j]+y[j]*y[j]-x[i]*x[i]-y[i]*y[i])-(x[j]-x[i])*(x[k]*x[k]+y[k]*y[k]-x[i]*x[i]-y[i]*y[i]))/(2*((x[k]-x[i])*(y[j]-y[i])-(x[j]-x[i])*(y[k]-y[i])));
	double r = sqrt((x[i]-p)*(x[i]-p)+(y[i]-q)*(y[i]-q));
	bool f = true;
	rep(k,n){
	  if(R(p,q,x[k],y[k])>r){
	    f = false;
	    break;
	  }
	}
	if(f){
	  res = min(res,r);
	}
      }
    }
  }

  printf("%.7f\n",res);
  
  return 0;
}
