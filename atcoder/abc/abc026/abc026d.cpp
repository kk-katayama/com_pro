#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
double eps = 1e-7;
double pi = 4*atan(1);
double a,b,c;
double f(double t){ return a*t+b*sin(c*pi*t)-100.; }
double ff(double t){ return a+b*c*pi*cos(c*pi*t); }
int main()
{
  
  cin >> a >> b >> c;
  double st;
  double ax = 1000000;
  for(double i = 0;i<=20000;++i){
    double t = 0.01*i;
    if(fabs(f(t))<=ax){
      ax = fabs(f(t));
      st = t;
    }
  }

  double nt = st - f(st)/ff(st);
  rep(i,100000){
    if(fabs(f(nt))<eps) break;
    nt = nt - f(nt)/ff(nt);
  }

  printf("%.10f\n", nt);

  return 0;
}
