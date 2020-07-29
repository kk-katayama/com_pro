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
  ll d; cin >> d;
  vector<ll> c(26);
  rep(i,26) cin >> c[i];
  vector<vector<ll>> s(d, vector<ll>(26));
  rep(i,d) {
    rep(j,26) {
      cin >> s[i][j];
    }
  }
  vector<ll> t(d);
  rep(i,d) {
    cin >> t[i];
    t[i]--;
  }

  ll res = 0;
  vector<ll> last(26, -1);
  rep(i,d) {
    res += s[i][t[i]];
    last[t[i]] = i;
    rep(j,26) {
      res -= c[j] * (i - last[j]);
    }
    cout << res << "\n";
  }
  return 0;
}
