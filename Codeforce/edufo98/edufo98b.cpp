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
    ll n; cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];

    ll mx = 0;
    ll sum = 0;
    rep(i,n) {
      chmax(mx, a[i]);
      sum += a[i];
    }
    ll m = n-1 - (sum%(n-1));
    if(sum % (n-1) == 0) m = 0;
    if(mx <= (sum+m) / (n-1)) cout << m << "\n";
    else cout << m + (mx - (sum+m)/(n-1))*(n-1) << "\n";

  }
  return 0;
}
