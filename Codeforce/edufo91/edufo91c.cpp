#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    ll n,x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end(), [](ll a, ll b) {
			       return a > b;
			     });

    ll cnt = 1;
    ll res = 0;
    rep(i,n) {
      if(cnt * a[i] >= x) {
	res++;
	cnt = 1;
      }
      else {
	cnt++;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
