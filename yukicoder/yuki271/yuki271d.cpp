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
  ll v; cin >> v;
  vl a(n);
  rep(i,n) cin >> a[i];

  ll sum = 0;
  rep(i,n) sum += a[i];
  if(sum <= v) {
    cout << "Draw" << "\n";
    return 0;
  }
  
  vi dp((1 << n), -1);
  auto rec = [&](auto self, int S, ll w)-> int{
    if(dp[S] >= 0) return dp[S];
    ll mn = infll, mx = 0;
    rep(i,n) {
      if((S >> i) & 1) {
	//
      }
      else {
	chmin(mn, a[i]);
	if(a[i] <= w) chmax(mx, a[i]);
      }
    }
    if(w < mn) return dp[S] = 0;
    if(mx == 0) return dp[S] = 0;
    int res = 0;
    if(w - mx < mn) {
      return dp[S] = 1;
    }
    else {
      rep(i,n) {
	if((S >> i) & 1) {
	  //
	}
	else {
	  if(w - a[i] >= 0) {
	    if(self(self, S | (1 << i), w - a[i]) == 0) res = 1;
	  }
	}
      }
    }
    return dp[S] = res;
  };
  
  int x = rec(rec, 0, v);
  if(x == 1) cout << "First" << "\n";
  else cout << "Second" << "\n";

  
  return 0;
}
