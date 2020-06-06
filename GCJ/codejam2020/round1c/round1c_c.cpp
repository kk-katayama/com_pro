#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define S second
#define F first
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll t;cin >> t;
  vector<ll> n(t), d(t);
  vector<vector<double>> a(t);
  rep(i,t) {
    cin >> n[i] >> d[i];
    a[i].resize(n[i]);
    rep(j,n[i]) cin >> a[i][j];
  }

  vector<ll> ress(t);
  rep(i,t) {
    vector<pair<double,pair<ll,pair<ll,ll>>>> p;
    rep(j,n[i]) {
      rep1(k,d[i]) {
	p.push_back({a[i][j]/k, {k-1, {k, j}}});
      }
    }
    sort(p.begin(), p.end());
    ll cnt = 0;
    ll ans = 0;
    ll res = d[i] - 1;
    rep(j, p.size()) {
      //      cout << p[j].F << ":" << p[j].S.F << ":" << p[j].S.S.F << "\n";
      if(cnt + p[j].S.S.F == d[i]) {
	chmin(res, ans+p[j].S.F);
	ans = 0;
	cnt = 0;
      }
      else if(cnt + p[j].S.S.F > d[i]) {
	chmin(res, ans+d[i]-cnt);
	ans = 0;
	cnt = 0;
      }
      else {
	if(j == p.size() -1 ) break;
	if(p[j].F == p[j+1].F) {
	  ans += p[j].S.F;
	  cnt += p[j].S.S.F;
	}
	else {
	  rep(k,n[i]) {
	    if(k == p[j].S.S.S) continue;
	    ll y = floor(a[i][k] / p[j].F);
	    if(cnt + y >= d[i]) {
	      chmin(res, ans+d[i]-cnt);
	      break;
	    }
	    else {
	      ans += y;
	      cnt += y;
	    }
	  }
	}
      }
    }
    ress[i] = res;
  }

  rep(i,t) {
    cout << "Case #" << i + 1 << ": ";
    cout << ress[i] << "\n";
  }
  return 0;
}
