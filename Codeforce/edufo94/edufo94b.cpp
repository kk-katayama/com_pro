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
    ll p,f; cin >> p >> f;
    ll cs,cw; cin >> cs >> cw;
    ll s,w; cin >> s >> w;

    if(s > w) {
      swap(s,w);
      swap(cs, cw);
    }
    ll res = 0;
    rep(x,cs+1) {
      if(s*x > p) continue;
      ll y = min((p - s*x)/w, cw);
      ll a = cs - x;
      if(s*a > f) {
	chmax(res, x+y+f/s);	
      }
      else {
	ll b = min((f - s*a)/w, cw-y);
	chmax(res, x+y+a+b);
      }
    }
    cout << res << "\n";
  }
  return 0;
}
