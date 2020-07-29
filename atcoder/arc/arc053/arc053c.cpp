#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n; cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];

  using pll = pair<ll,ll>;
  vector<pll> mi, pl;
  rep(i,n) {
    if(a[i] - b[i] <= 0) mi.push_back({a[i], a[i] - b[i]});
    else pl.push_back({b[i], b[i] - a[i]});
  }

  ll res = 0;
  ll now = 0;
  sort(mi.begin(), mi.end());
  rep(i,mi.size()) {
    chmax(res, mi[i].first + now);
    now += mi[i].second;
  }
  ll x = now;
  now = 0;
  ll tmp = 0;
  sort(pl.begin(), pl.end());
  rep(i,pl.size()) {
    chmax(tmp, pl[i].first + now);
    now += pl[i].second;
  }  

  tmp += x - now;
  cout << max(res, tmp) << "\n";
  
  return 0;
}
