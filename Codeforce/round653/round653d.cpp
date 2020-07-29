#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a <= b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll t; cin >> t;
  while(t-- > 0) {
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    map<ll,ll> mp;
    rep(i,n) {
      mp[k - (a[i] % k)]++;
    }
    ll val = 1, key = -1;
    for(auto m: mp) {
      if(m.first == k) continue;
      if( chmax(val, m.second) ) key = m.first;
    }
    //    cout << key << ":" << val << "\n";
    cout << k*(val - 1) + key + 1 << "\n";
  }
  return 0;
}
