#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  double p;
  cin >> p;
  double x = 3./2.*log2(2.*p*log(2.))-3./2.*log2(3.);
  x = max(0.,x);
  double res = x + p*pow(2.,-2./3.*x);
  printf("%.9f\n", res);
  return 0;
}
