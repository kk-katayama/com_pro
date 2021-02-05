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
#include <limits>
#define rep(i,n) for(ll i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  ll n; cin >> n;
  ll a; cin >> a;
  string s; cin >> s;

  ll r = 0, l = 0;
  ll res = -a;
  ll mn = inf;
  ll mx = 0;
  rep(i,n) {
    if(s[i] == '#') {
      if(i+1 < a) {
	l++;
	res -= 2*(i+1);
	chmin(mn, i+1);
      }
      else {
	r++;
	res += 2*(i+1);
	chmax(mx, i+1);
      }
    }
  }
  if(r <= l) {
    res += mn;
    res += (l-r)*2*(n+1);
  }
  else {
    res -= mx;
  }
  cout << res << "\n";
  
  return 0;
}
