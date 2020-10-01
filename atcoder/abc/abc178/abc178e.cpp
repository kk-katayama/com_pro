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
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int n; cin >> n;
  vi x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];

  vi xx(n),yy(n);
  rep(i,n) {
    xx[i] = x[i] + y[i];
    yy[i] = x[i] - y[i];
  }

  int xmax = -inf, ymax = -inf, xmin = inf, ymin = inf;
  rep(i,n) {
    chmax(xmax, xx[i]);
    chmax(ymax, yy[i]);
    chmin(xmin, xx[i]);
    chmin(ymin, yy[i]);
  }
  
  cout << max(xmax - xmin, ymax - ymin) << "\n";
  
  return 0;
}
