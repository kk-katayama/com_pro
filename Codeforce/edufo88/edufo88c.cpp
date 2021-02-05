#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int q; cin >> q;
  while(q-- > 0) {
    ld h,c,t; cin >> h >> c >> t;
    ld d = h + c - 2*t;
    ld x = h - t;
    int lb = 0, ub = 1e+6+1;
    while(ub - lb > 2) {
      int m1 = (lb *2 + ub) / 3;
      int m2 = (lb + ub*2) / 3;
      if(abs(x + d * (m1 - 1)) / (m1 * 2 - 1) > abs(x + d * (m2 - 1)) / (m2 * 2 - 1) ) lb = m1;
      else ub = m2;
    }
    int m = (lb + ub) / 2;
    ld y = abs((h+c)/2 - t);
    if(y < abs(x + d * (m - 1)) / (m*2 - 1)) cout << 2 << "\n";
    else cout << 2*m - 1<< "\n";
  }
  return 0;
}
