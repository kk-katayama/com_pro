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
  ll sx,sy,tx,ty,T,V;
  cin >> sx >> sy >> tx >> ty >> T >> V;
  int n; cin >> n;
  vl x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];

  bool f = false;
  rep(i,n) {
    ll a = (x[i] - sx)*(x[i] - sx) + (y[i] - sy)*(y[i] - sy);
    ll b = (x[i] - tx)*(x[i] - tx) + (y[i] - ty)*(y[i] - ty);
    if(4*a*b <= (T*T*V*V - a - b)*(T*T*V*V - a - b)) f = true;
  }
  cout << (f ? "YES" : "NO") << "\n";

  
  return 0;
}
