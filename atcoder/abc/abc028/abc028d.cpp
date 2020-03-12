#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  double res = 0;
  res += ((double)1/n)*((double)(k-1)/n)*((double)(n-k)/n)*6.;
  res += ((double)1/n)*((double)1/n)*((double)(k-1)/n)*3.;
  res += ((double)1/n)*((double)1/n)*((double)(n-k)/n)*3.;
  res += ((double)1/n)*((double)1/n)*((double)1/n);
  
  printf("%.12f\n", res);
  return 0;
}
