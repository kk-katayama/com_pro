#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll h,w;cin >> h >> w;
  ll x,y;cin >> x >> y;
  bool f = false;
  if(2*x==h&&2*y==w) f = true;
  double res = (double)h*w/2;
  printf("%.7f ", res); cout << f << "\n";
  
  return 0;
}
