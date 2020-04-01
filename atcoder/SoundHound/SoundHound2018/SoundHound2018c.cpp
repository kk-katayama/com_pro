#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long double ld;
typedef long long ll;
int main()
{
  ll n,m,d;cin >> n >> m >> d;
  ll x;
  if(d == 0) x = n;
  else x = ( ( n / d - 1 ) * d + n % d ) * 2;
  ld res = (ld) x / n / n * (m - 1);
  printf("%.7Lf\n", res);
 
  return 0;
}
