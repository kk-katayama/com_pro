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
  ll n; cin >> n;
  vector<ll> a(n),b(n),c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];

  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  ll res = 0;
  rep(i,n) {
    ll lb = -1, ub = n;
    while(ub - lb > 1) {
      ll mid = (lb + ub) / 2;
      (a[mid] < b[i] ? lb : ub) = mid;
    }
    ll tmp = lb + 1;
    lb = -1; ub = n;
    while(ub - lb > 1) {
      ll mid = (lb + ub) / 2;
      (c[mid] > b[i] ? ub : lb) = mid;
    }
    res += tmp * (n - ub);
  }
  cout << res << "\n";
  
  return 0;
}
