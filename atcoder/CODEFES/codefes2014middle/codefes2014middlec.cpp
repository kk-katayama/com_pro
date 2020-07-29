#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n;
  double p;
  cin >> p >> n;

  double res = 1;
  double x = 1 - 2*p;
  while(n > 0) {
    if(n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
  res = (1 - res) / 2;
  printf("%.7f\n", res);
  
  return 0;
}
