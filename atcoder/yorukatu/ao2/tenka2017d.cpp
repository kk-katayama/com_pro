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
#define rep(i,n) for(ll i = 0; i < n; ++i)
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
  vl a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  ll res = 0;
  rep(i,31) {
    if( (k >> i) & 1) {
      ll sum = 0;
      rep(j,n) {
	if( (a[j] >> i) & 1) continue;
	bool f = true;
	for (int l = i+1; l < 31; ++l) {
	  if( ((k >> l) & 1) == 0 && ((a[j] >> l) & 1) == 1) f = false;
	}
	if(f) sum += b[j];
      }
      chmax(res, sum);
    }
  }
  {
    ll sum = 0;
    rep(j,n) {
      bool f = true;
      for (int l = 0; l < 31; ++l) {
	if( ((k >> l) & 1) == 0 && ((a[j] >> l) & 1) == 1) f = false;
      }
      if(f) sum += b[j];
    }
    chmax(res, sum);
  }

  cout << res << "\n";
  return 0;
}
