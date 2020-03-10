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
  rep1(i,n){
    double x = (double)1./n;
    int j = i;
    while(j<k){
      j *= 2;
      x /= 2.;
    }
    res += x;
  }
  printf("%.11f\n", res);
  return 0;
}
