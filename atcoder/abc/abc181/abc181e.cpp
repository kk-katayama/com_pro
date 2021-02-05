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
  int n,m; cin >> n >> m;
  vl h(n),w(m);
  rep(i,n) cin >> h[i];
  rep(i,m) cin >> w[i];

  sort(h.begin(), h.end());
  vl even(n, 0), odd(n, 0);
  rep(i,n) {
    if(2*i + 1 < n) even[i+1] = even[i] + h[2*i + 1] - h[2*i];
    if(2*i + 2 < n) odd[i+1] = odd[i] + h[2*(i+1)] - h[2*i + 1];
  }
  
  ll res = infll;
  rep(i,m) {
    int lb = -1, ub = n;
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (h[mid] <= w[i] ? lb : ub) = mid;
    }
    ll tmp;
    if(lb % 2 == 0) {
      tmp = w[i] - h[lb] + even[lb / 2] + odd[(n-1)/2] - odd[lb/2];
     chmin(res, tmp);      
    }
    else {
      tmp = h[lb+1] - w[i] + even[(lb+1) / 2] + odd[(n-1)/2] - odd[(lb+1)/2];
      chmin(res, tmp);
    }
  }
  cout << res << "\n";
  
  return 0;
}
