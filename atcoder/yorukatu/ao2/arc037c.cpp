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
  ll n,k; cin >> n >> k;
  vl a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  sort(a.begin(), a.end());
  ll lb = 0, ub = infll/2;
  while(ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    ll cnt = 0;
    rep(i,n) {
      ll c = mid / b[i];
      ll lb2 = -1, ub2 = n;
      while(ub2 - lb2 > 1) {
	ll mid2 = (ub2 + lb2) / 2;
	(a[mid2] <= c ? lb2 : ub2) = mid2;
      }
      cnt += lb2 + 1;
    }
    (cnt >= k ? ub : lb) = mid;
  }
  cout << ub << "\n";
  
  return 0;
}
