#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll q; cin >> q;
  vector<ll> b(q),c(q);
  rep(i,q) {
    cin >> b[i] >> c[i];
  }

  map<ll,ll> mp;
  ll sum = 0;
  rep(i,n) {
    mp[a[i]]++;
    sum += a[i];
  }

  rep(i,q) {
    ll cnt = mp[b[i]];
    sum -= cnt*b[i];
    sum += cnt*c[i];
    mp[b[i]] = 0;
    mp[c[i]] += cnt;
    cout << sum << "\n";
  }
  
  return 0;
}
