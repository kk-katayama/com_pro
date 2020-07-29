#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n,x; cin >> n >> x;
  vector<ll> t(n),a(n);
  rep(i,n) cin >> t[i];
  rep(i,n) cin >> a[i];
  vector<pair<ll,ll>> p(n);
  rep(i,n) p[i] = {t[i], a[i]};
  sort(p.begin(), p.end());
  
  auto isok = [&](ll k) {
		ll tmp = 0;
		multiset<ll> st;
		ll idx = n - 1;
		for(ll i = k; i >= 1; --i) {
		  if(idx >= 0) {
		    while(p[idx].first >= i) {
		      st.insert(p[idx].second);
		      idx--;
		      if(idx == -1) break;
		    }
		  }
		  if(st.empty()) continue;
		  auto it = st.end(); it--;
		  tmp += *it;
		  st.erase(it);
		}
		return tmp >= x;
	      };
  
  ll lb = -1, ub = n + 1;
  while(ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    (isok(mid) ? ub : lb) = mid;
  }

  cout << (ub != n + 1 ? ub : -1) << "\n";
  
  return 0;
}
