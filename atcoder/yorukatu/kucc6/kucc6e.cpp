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
  ll n;cin >> n;
  using pi = pair<ll,ll>;
  vector<pi> p(n);
  rep(i,n) {
    ll a; cin >> a;
    p[i] = {a, i};
  }

  sort(p.begin(), p.end(), [](pi a, pi b) {
			     return a.first > b.first;
			   });

  multiset<ll> st;
  st.insert(-1);
  st.insert(-1);
  st.insert(n);
  st.insert(n);

  ll res = 0;
  rep(i,n) {
    ll val = p[i].first;
    ll idx = p[i].second;
    st.insert(idx);
    auto it = st.find(idx);
    auto it3 = it; it--;
    auto it2 = it; it--;
    auto it1 = it; it++; it++; it++;
    auto it4 = it; it++;
    auto it5 = it;

    ll cnt = (*it5 - *it4)*(*it3 - *it2) + (*it4 - *it3)*(*it2 - *it1);
    res += cnt*val;
  }
  cout << res << "\n";
  
  return 0;
}
