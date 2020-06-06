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
  ll k,q; cin >> k >> q;
  vector<ll> d(k);
  rep(i,k) cin >> d[i];
  vector<ll> n(q),x(q),m(q);
  rep(i,q) {
    cin >> n[i] >> x[i] >> m[i];
  }

  rep(i,q) {
    vector<ll> cnt(k+1);
    vector<ll> sum(k+1);
    sum[0] = 0;
    cnt[0] = 0;
    rep(j,k) {
      sum[j+1] += sum[j] + d[j] % m[i];
      cnt[j+1] += cnt[j] + (d[j] % m[i] == 0 ? 1 : 0);
    }
    ll su = sum[k] * ((n[i] - 1) / k) + sum[(n[i] - 1) % k];
    ll cn = cnt[k] * ((n[i] - 1) / k) + cnt[(n[i] - 1) % k];
    ll res = n[i] - 1 - (x[i] + su) / m[i] + x[i] / m[i] - cn;
    cout << res << "\n";
  }
  
  return 0;
}
