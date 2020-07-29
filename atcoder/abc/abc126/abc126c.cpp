#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdio>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,k; cin >> n >> k;
  vector<int> c(n+1);
  rep1(i,n) {
    int cnt = 0;
    int x = 1;
    while(x * i < k) {
      x *= 2;
      cnt++;
    }
    c[i] = cnt;
  }

  vector<double> p(c[1]+1);
  p[0] = 1;
  rep(i,c[1]) p[i+1] = p[i] / 2.;
  
  double res = 0;
  rep1(i,n) {
    res += p[c[i]] / n;
  }
  printf("%.9f\n", res);
  
  return 0;
}
