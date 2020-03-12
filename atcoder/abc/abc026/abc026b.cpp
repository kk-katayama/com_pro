#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
double pi = 4*atan(1);
int main()
{
  int n;cin >> n;
  vector<double> r(n);
  rep(i,n){
    cin >> r[i];
    r[i] = -r[i];
  }
  sort(r.begin(), r.end());
  double res = 0;
  rep(i,n){
    if(i%2==0) res += pi*r[i]*r[i];
    else res -= pi*r[i]*r[i];
  }
  printf("%.10f\n", res);
  return 0;
}
