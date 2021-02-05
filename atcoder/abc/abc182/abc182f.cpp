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
  ll x; cin >> x;
  vl a(n);
  rep(i,n) cin >> a[i];

  map<ll,ll> dp1;
  dp1[-x] = 1;
  for (int i = n-1; i >= 0; --i) {
    map<ll,ll> dp2;
    for(auto val: dp1) {
      auto [d, num] = val;
      if(abs(d) % a[i] != 0) {
	ll x1 = abs(d) / a[i];
	ll x2 = x1 + 1;
	ll c = - abs(d) / d;
	if(i != n - 1) {
	  if(x1 < a[i+1] / a[i]) dp2[d + c * x1 * a[i]] += num;
	  if(x2 < a[i+1] / a[i]) dp2[d + c * x2 * a[i]] += num;	  
	}
	else {
	  dp2[d + c * x1 * a[i]] += num;
	  dp2[d + c * x2 * a[i]] += num;	  	  
	}
      }
      else {
	dp2[0] += num;
      }
    }
    swap(dp1, dp2);
  }
  cout << dp1[0] << "\n";

  
  return 0;
}
