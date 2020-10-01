#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;

int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    int n,k; cin >> n;
    k = 5;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    sort(a.begin(), a.end(), [](ll x, ll y) {
			       return abs(x) > abs(y);
			     });

    ll cnt = 0;
    ll sum = 1;
    ll emin = -1, omin = -1, emax = -1, omax = -1;
    rep(i,k) {
      sum *= abs(a[i]);
      if(a[i] > 0) {
	emin = i;
      }
      else if(a[i] < 0) {
	omin = i;
	cnt++;
      }
    }

    if(cnt % 2 == 0) {
      cout << sum << "\n";
      continue;
    }
    
    for (ll i = k; i < n; ++i) {
      if(a[i] > 0 && emax == -1) emax = i;
      else if(a[i] < 0 && omax == -1) omax = i;
    }
    bool fx = ((emin == -1) || (omax == -1));
    bool fy = ((omin == -1) || (emax == -1));
    if(fx && fy) {
      ll tmp = 1;
      rep(i,k) {
	tmp *= (ll)abs(a[n - 1 - i]);
      }
      ll res = 0;
      res -= tmp;
      cout << res << "\n";
    }
    else if(fx) {
      sum /= (ll)abs(a[omin]);
      sum *= (ll)abs(a[emax]);
      cout << sum << "\n";
    }
    else if(fy) {
      sum /= (ll)abs(a[emin]);
      sum *= (ll)abs(a[omax]);
      cout << sum << "\n";
    }
    else {
      if(a[omin] * a[omax] < a[emin] * a[emax]) {
	sum /= (ll)abs(a[omin]);
	sum *= (ll)abs(a[emax]);
      }
      else {
	sum /= (ll)abs(a[emin]);
	sum *= (ll)abs(a[omax]);
      }
      cout << sum << "\n";
    }
  }
  return 0;
}
