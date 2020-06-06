#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  double n; cin >> n;
  double res = 1;
  double x = 1;
  rep1(i,(int)n) {
    x *= (n - i) / n;
    res += x;
  }

  res /= n;
  res *= (n + 1) * n / 2;
  printf("%.9f\n", res);
  
  return 0;
}
