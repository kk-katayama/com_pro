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
  vl a(n);
  rep(i,n) cin >> a[i];

  vl sum(n+1, 0);
  rep(i,n) {
    sum[i+1] = sum[i] + a[i];
  }
  rep(i,n+1) {
    sum[i] = (sum[i] - i) % k;
  }

  map<ll,ll> mp;
  rep(i,min(k,n+1)) {
    mp[sum[i]]++;
  }
  ll res = 0;
  for(auto val: mp) {
    res += val.second * (val.second - 1) / 2;
  }

  rep(i,n+1-k) {
    mp[sum[i]]--;
    res += mp[sum[k+i]];
    mp[sum[k+i]]++;
  }
  cout << res << "\n";
  
  return 0;
}
