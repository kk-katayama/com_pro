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
    int n,k; cin >> n >> k;
    vi h(n);
    rep(i,n) cin >> h[i];

    int mn = h[0] + 1, mx = h[0] + 1;
    bool f = false;
    rep1(i,n-2) {
      mx = min(h[i] + k, mx + k - 1);
      mn = max(h[i] + 1, mn - k + 1);
      if(mx < mn) {
	f = true;
      }
    }
    if(f) {
      cout << "NO" << "\n";
      continue;
    }
    if(mx + k - 1 < h[n-1] + 1 || h[n-1] + k < mn) {
      cout << "NO" << "\n";
    }
    else cout << "YES" << "\n";
  }
  return 0;
}
