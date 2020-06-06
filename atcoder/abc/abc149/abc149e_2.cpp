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
  ll n,m; cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());

  auto bins = [&](auto isok, ll x, ll maxi)-> ll{
		ll lb = -1, ub = maxi;
		while(ub - lb > 1) {
		  ll mid = (ub + lb) / 2;
		  (isok(mid, x) ? ub : lb) = mid;
		}
		return ub;
	      };

  auto comp1 = [&](ll mid, ll x)-> bool{
		 return x <= a[mid];
	       };

  auto comp2 = [&](ll mid, ll x)-> bool{
		 ll cnt = 0;
		 rep(i,n) {
		   cnt += bins(comp1, mid - a[i], n);
		 }
		 return n*n - m <= cnt;
	       };

  ll bor = bins(comp2, 0, 1e+10+1);

  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];
  
  ll cnt = 0;
  ll res = 0;
  rep(i,n) {
    ll tmp = bins(comp1, bor - a[i], n);
    cnt += n - tmp;
    res += (sum[n] - sum[tmp]) + a[i] * (n - tmp);
  }

  res += (m - cnt) * (bor - 1);
  cout << res << "\n";
  
  return 0;
}
