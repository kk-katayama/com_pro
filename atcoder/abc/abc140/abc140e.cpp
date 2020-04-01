#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n;cin >> n;
  vector<ll> p(n);
  rep(i,n) cin >> p[i];
  vector<pair<ll,ll>> pv(n);
  rep(i,n) pv[i] = { - p[i] , i };
  sort(pv.begin(), pv.end());
  multiset<ll> st;
  st.insert((ll)-1);
  st.insert((ll)-1);
  st.insert(n);
  st.insert(n);  

  ll res = 0;
  rep(i,n){
    ll x = pv[i].second;
    ll y = - pv[i].first;
    st.insert(x);
    auto it1 = st.find(x);
    auto it2 = st.find(x);
    ll c = *it1; it1++;
    ll d = *it1; it1++;
    ll e = *it1; it2--;
    ll b = *it2; it2--;
    ll a = *it2;
    res += y * ( ( c - b ) * ( e - d ) + ( d - c ) * ( b - a ) );
  }
  cout << res << "\n";
  
  return 0;
}
