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
  int n; cin >> n;
  vector<ll> a(n+1);
  rep(i,n+1) cin >> a[i];
  if(n == 0) {
    if(a[0] == 1) cout << 1 << "\n";
    else cout << -1 << "\n";
    return 0;
  }

  if(a[0] != 0) {
    cout << -1 << "\n";
    return 0;
  }
  
  vector<ll> sum(n+1);
  sum[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    sum[i] = sum[i+1] + a[i+1];
  }
  
  ll x = 1;
  ll res = 1;
  rep(i,n) {
    ll e = min(2*x - a[i+1], sum[i+1]);
    if(e < 0) {
      cout << -1 << "\n";
      return 0;
    }
    res += e + a[i+1];
    x = e;
  }
  cout << res << "\n";
  return 0;
}
