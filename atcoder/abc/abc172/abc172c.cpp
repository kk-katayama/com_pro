#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n,m; cin >> n >> m;
  ll k; cin >> k;
  vector<ll> a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  vector<ll> asum(n+1);
  asum[0] = 0;
  rep(i,n) asum[i+1] = asum[i] + a[i];
  vector<ll> bsum(m+1);
  bsum[0] = 0;
  rep(i,m) bsum[i+1] = bsum[i] + b[i];

  ll res = 0;
  rep(i,n+1) {
    ll x = k - asum[i];
    if(x < 0) continue;
    ll lb = -1, ub = m + 1;
    while(ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      (bsum[mid] <= x ? lb : ub) = mid;
    }
    chmax(res, i + lb);
  }
  cout << res << "\n";
  
  return 0;
}
