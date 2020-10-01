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
#define sz(v) (int)v.size()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    ll a,b,x,y,n; cin >> a >> b >> x >> y >> n;
    ll c = n - (a - max(a - n, x));
    ll res = max(a - n, x) * max(b - c, y);
    ll d = n - (b - max(b - n, y));
    chmin(res, max(a - d, x) * max(b - n, y));
    cout << res << "\n";
  }
  return 0;
}
