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
  ll n,m; cin >> n >> m;
  ll x,k,y; cin >> x >> k >> y;
  vector<ll> a(n+2),b(m+2);
  rep1(i,n) cin >> a[i];
  rep1(i,m) cin >> b[i];

  a[0] = 0; a[n+1] = 0;
  b[0] = 0; b[m+1] = 0;
  int left = 0, right;
  ll res = 0;
  rep1(i,m+1) {
    int idx = left + 1;
    vector<ll> v;
    while(idx < n + 2 && a[idx] != b[i]) {
      v.push_back(a[idx]);
      idx++;
    }
    left = idx;
    if(idx >= n + 2) {
      cout << -1 << "\n";
      return 0;
    }
    ll vs = v.size();

    ll c = max(b[i-1], b[i]);
    if(vs < k) {
      bool f = true;
      rep(j,vs) {
	if(c < v[j]) f = false;
      }
      if(f) {
	res += vs * y;
      }
      else {
	cout << -1 << "\n";
	return 0;
      }
    }
    else {
      if(k * y > x) {
	res += vs / k * x;
	res += (vs % k) * y;
      }
      else {
	bool f = false;	
	rep(j,vs) {
	  if(c < v[j]) f = true;
	}
	if(f) {
	  res += x + y * (vs - k);
	}
	else {
	  res += vs * y;
	}
      }
    }
  }
  cout << res << "\n";
  return 0;
}
