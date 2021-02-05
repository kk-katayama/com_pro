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
  int n; cin >> n;
  ll k; cin >> k;
  vl a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  ll res = -1;
  ll c = 1;
  for (int i = n/2; i < n-1; ++i) {
    if(k <= c * (a[i+1] - a[i])) {
      res = a[i] + k / c;
      break;
    }
    else {
      k -= c * (a[i+1] - a[i]);
      c++;
    }
  }
  if(res == -1) {
    res = a[n-1] + k / c;
  }
  cout << res << "\n";
  return 0;
}
