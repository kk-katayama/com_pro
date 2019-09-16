#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n) --a[i];  
  
  map<int,ll> mp;
  rep(i,n) mp[a[i]] = (ll)i;
  set<ll> st;
  st.insert(-1);
  st.insert(n);
  ll res = 0;
  rep(i,n){
    ll x = mp[i];
    ll l,r;
    st.insert(x);
    {
      auto itr = st.find(x);
      l = *(--itr);
    }
    {
      auto itr = st.find(x);
      r = *(++itr);
    }
    ll c = (r-x)*(x-l);
    res += c*((ll)i+1);
  }

  cout << res << "\n";
  return 0;
}
