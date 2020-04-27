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
ll inf = 1ll << 60;
int main()
{
  int n;cin >> n;
  vector<ll> s(n), c(n);
  rep(i,n) cin >> s[i] >> c[i];

  set<pair<ll,ll>> st;
  st.insert({-2, -1});
  st.insert({inf, inf+1});
  rep(i,n) {
    ll start;
    auto it = st.upper_bound({s[i], 0});
    it--;
    ll x = it->first, y = it->second;
    if(y < s[i]) {
      start = s[i];
      it++;
    }
    else {
      start = x;
      s[i] = y;
      it++;
      st.erase({x, y});
    }
    while(1) {
      ll a = it->first, b = it->second;
      if(s[i] + c[i] < a) {
	st.insert({start, s[i] + c[i]} );
	cout << s[i] + c[i] - 1 << "\n";
	break;
      }
      else if(s[i] + c[i] == a) {
	st.insert({start, b} );
	st.erase({a, b});
	cout << s[i] + c[i] - 1 << "\n";
	break;
      }
      else {
	c[i] -= a - s[i];
	s[i] = b;
	it++;
	st.erase({a, b});
      }
    }
  }


  
  return 0;
}
