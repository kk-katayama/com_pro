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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n; cin >> n;
  ll x; cin >> x;
  vector<ll> w(n);
  rep(i,n) cin >> w[i];

  vector<ll> a,b;
  int m = n/2;
  rep(mask,(1 << m)) {
    ll sum = 0;
    rep(i,m) {
      if((mask >> i) & 1) sum += w[i];
    }
    a.push_back(sum);
  }

  int r = n - m;
  rep(mask,(1 << r)) {
    ll sum = 0;
    rep(i,r) {
      if((mask >> i) & 1) sum += w[i + m];
    }
    b.push_back(sum);
  }  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll res = 0;
  rep(i,a.size()) {
    ll k = x - a[i];
    if(k < 0) continue;
    ll lb = -1, ub = b.size();
    while(ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      (b[mid] > k ? ub : lb) = mid;
    }
    ll tmp = ub;
    lb = -1;
    ub = b.size();
    while(ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      (b[mid] >= k ? ub : lb) = mid;
    }
    res += tmp - ub;
  }

  cout << res << "\n";
  
  return 0;
}
