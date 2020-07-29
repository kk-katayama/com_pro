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
  ll n,k; cin >> n >> k;
  vector<ll> a(n),f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];

  sort(a.begin(), a.end());
  sort(f.begin(), f.end(), [](int x, int y) {
			     return x > y;
			   });

  auto isok = [&](ll x) {
		ll cnt = 0;
		rep(i,n) {
		  cnt += max((ll)0, (a[i] * f[i] - x + f[i] - 1) / f[i]);
		}
		return cnt <= k;
	      };
  
  ll lb = -1, ub = 1e+12;
  while(ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    (isok(mid) ? ub : lb) = mid;
  }
  cout << ub << "\n";

  return 0;
}
