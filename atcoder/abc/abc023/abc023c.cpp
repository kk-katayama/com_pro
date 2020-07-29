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
  ll R,C,k; cin >> R >> C >> k;
  ll n; cin >> n;
  vector<ll> r(n),c(n);
  vector<ll> rcnt(R, 0), ccnt(C, 0);
  rep(i,n) {
    cin >> r[i] >> c[i];
    r[i]--; c[i]--;
    rcnt[r[i]]++;
    ccnt[c[i]]++;
  }

  ll res = 0;
  rep(i,n) {
    if(rcnt[r[i]] + ccnt[c[i]] - 1 == k) res++;
    if(rcnt[r[i]] + ccnt[c[i]] == k) res--;
  }

  sort(ccnt.begin(), ccnt.end());
  rep(i,R) {
    ll x = k - rcnt[i];
    ll lb = -1, ub = C;
    while(ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      (x <= ccnt[mid] ? ub : lb) = mid;
    }
    ll buf = ub;
    lb = -1;
    ub = C;
    while(ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      (x < ccnt[mid] ? ub : lb) = mid;
    }
    res += ub - buf;
  }
  cout << res << "\n";
  return 0;
}
