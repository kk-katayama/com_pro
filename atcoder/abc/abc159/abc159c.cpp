#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  double l;cin >> l;
  double res = (l/3.) * (l/3.) * (l/3.);
  printf("%.7f\n", res);
  return 0;
}
