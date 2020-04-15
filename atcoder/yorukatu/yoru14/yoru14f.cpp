#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  ll n,k;cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) {
    sum[i+1] = sum[i] + a[i];
  }
  rep1(i,n) sum[i]  = (sum[i] - (ll)i) % k;

  map<ll,ll> mp;
  rep(i,min(n+1,k)) {
    mp[ sum[i] ]++;
  }

  ll res = 0;
  for(auto m : mp) {
    res += m.second * (m.second - (ll)1) / (ll)2;
  }

  rep(i,n-k+1) {
    mp[ sum[i] ]--;
    res += mp[ sum[i+k] ];
    mp[ sum[i+k] ]++;
  }
  cout << res << "\n";
  
  return 0;
}
