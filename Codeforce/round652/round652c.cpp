#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    int n,k; cin >> n >> k;
    vector<ll> a(n);
    vector<int> w(k);
    rep(i,n) cin >> a[i];
    rep(i,k) cin >> w[i];

    vector<set<ll>> st(k);
    sort(w.begin(), w.end());
    sort(a.begin(), a.end(), [](ll x, ll y) {
			       return x > y;
			     });
    rep(i,k) {
      st[i].insert(a[i]);
      w[i]--;
    }
    int idx = k;
    rep(i,k) {
      rep(j,w[i]) {
	st[i].insert(a[idx++]);
      }
    }
    ll res = 0;
    rep(i,k) {
      res += *st[i].begin();
      auto it = st[i].end();
      it--;
      res += *it;
    }
    cout << res << "\n";
  }
  return 0;
}
