#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n,t; cin >> n >> t;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll res = n*t;
  rep(i,n-1) {
    ll x = max(0LL, t - (a[i+1] - a[i]));
    res -= x;
  }
  cout << res << "\n";
  return 0;
}
