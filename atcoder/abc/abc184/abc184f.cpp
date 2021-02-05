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
  ll t; cin >> t;
  vl a(n);
  rep(i,n) cin >> a[i];

  vl v1,v2;
  int m1 = n/2;
  int m2 = n - m1;
  rep(i,(1<<m1)) {
    ll sum = 0;
    rep(j,m1) {
      if((i >> j) & 1){
	sum += a[j];
      }
    }
    v1.push_back(sum);
  }

  rep(i,(1<<m2)) {
    ll sum = 0;
    rep(j,m2) {
      if((i >> j) & 1){
	sum += a[j+m1];
      }
    }
    v2.push_back(sum);
  }  

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  // for(auto val : v1) cout << val << "\n";
  // for(auto val : v2) cout << val << "\n";  

  ll res = 0;
  for(auto val : v1) {
    ll x = t - val;
    if(x < 0) continue;
    int lb = -1, ub = sz(v2);
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (v2[mid] <= x ? lb : ub) = mid;
    }
    if(0<=lb && lb < sz(v2))chmax(res, val + v2[lb]);
  }
  cout << res << "\n";
  return 0;
}
