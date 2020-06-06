#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  double a,b,h,m;cin >> a >>b >> h >> m;
  double PI = 4*atan(1);
  double theta = m/60.*2.*PI - (h/12.+m/60./12.)*2*PI;
  theta = min(theta, 2*PI - theta);
  double res = sqrt(a*a + b*b - 2*a*b*cos(theta));
  printf("%.10f\n", res);
  return 0;
}
