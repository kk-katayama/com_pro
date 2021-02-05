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
    int n;cin >> n;
    vl t(n),x(n);
    rep(i,n) scanf("%lld%lld", &t[i], &x[i]);
    t.push_back(1e+15);
    ll res = 0, fin = 0, lim = 0;
    ll a,b;
    rep(i,n) {
      if(t[i] >= fin) {
	if(lim <= x[i]) {
	  a = 1;
	  b = -t[i] + lim;
	  lim = x[i];
	  fin = a*(lim - b);
	}
	else {
	  a = -1;
	  b = t[i] + lim;
	  lim = x[i];
	  fin = a*(lim - b);	  
	}
      }
      if(i < n) {
	if(a > 0) {
	  ll lb = a*t[i] + b, ub = min(a*t[i+1]+b, lim);
	  if(lb <= x[i] && x[i] <= ub) {
	    res++;
	  }
	}
	else {
	  ll lb = max(a*t[i+1] + b, lim), ub = a*t[i]+b;
	  if(lb <= x[i] && x[i] <= ub) {
	    res++;
	  }
	}
      }	
    }
    cout << res << "\n";
  }
  return 0;
}
