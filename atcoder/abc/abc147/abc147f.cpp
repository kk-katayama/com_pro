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
struct Rangeset{
  set<pl> st;

  Rangeset() {
    st.insert({-infll,-infll});
    st.insert({infll,infll});    
  }
  
  void insert(ll l, ll r) {
    auto it = prev(st.lower_bound({l+1, l+1}));
    if(it->first <= l && r <= it->second) return ;
    if(it->first <= l && l <= it->second + 1) {
      l = it->first;
      it = st.erase(it);
    }
    else it = next(it);
    while(r > it->second) {
      it = st.erase(it);
    }
    if(it->first - 1 <= r && r <= it->second) {
      r = it->second;
      it = st.erase(it);
    }
    st.insert({l, r});
  }
};
int main()
{
  ll n,x,d; cin >> n >> x >> d;
  if(d == 0) {
    cout << (x == 0 ? 1 : n+1) << "\n";
    return 0;
  }
  if(d < 0) {
    x = x + (n-1)*d;
    d = -d;
  }

  map<ll,Rangeset> mp;
  rep(i,n+1) {
    ll gr = (x*i % d + d) % d;
    ll l = x*i + i*(i-1)/2*d;
    ll r = x*i + (2*n-i-1)*i/2*d;
    mp[gr].insert(l, r);
  }

  ll res = 0;
  for(auto tmp: mp) {
    auto [ky, vl] = tmp;
    for(auto tmp2: vl.st) {
      auto [l, r] = tmp2;
      res += (r-l)/d + 1;
    }
    res -= 2;
  }
  cout << res << "\n";

  return 0;
}
