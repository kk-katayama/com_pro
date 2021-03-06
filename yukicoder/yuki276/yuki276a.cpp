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
#define rep(i,n) for(int i = 0; i < n; ++i)
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
  vi m;
  int cnt = 0;
  while(n > 0) {
    m.push_back(n%2);
    if(n%2 == 1) cnt++;
    n /= 2;
  }
  if(cnt < 2) {
    cout << -1 << " " << -1 << " " << -1 << "\n";
  }
  else {
    ll t = 1;
    ll a = 0, b = 0, c = 0;
    bool f = false;
    for(auto tmp: m) {
      if(tmp == 1) {
	if(f) {
	  a += t;
	  b += t;
	}
	else {
	  a += t;
	  c += t;
	  f = true;
	}
      }
      t *= 2;
    }
    cout << a << " " << b << " " << c << "\n";
  }
  
  return 0;
}
