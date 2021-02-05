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
  int q; cin >> q;
  while(q-- > 0) {
    ll n,l,r; cin >> n >> l >> r;
    ll bot = 0;
    ll cnt = 1;
    if(l == n*(n-1) + 1) {
      cout << 1 << "\n";
      continue;
    }
    while(bot + 2*(n-cnt) < l) {
      bot += 2*(n-cnt);
      cnt++;
    }
    ll d = l - bot;
    ll s = (d + 1) / 2;
    ll w = (d + 1) % 2;
    //    cout << cnt << "\n";
    ll id = l;
    rep(i,r-l+1) {
      ll a;
      if(w == 0) {
	a = cnt;
      }
      else {
	a = cnt + s;
	s++;
	if(a == n) {
	  cnt++;
	  s = 1;
	}
      }
      if(id == n*(n-1)+1) a = 1;
      cout<< a << " ";
      w = w^1;
      id++;
    }
    cout << "\n";
  }
  return 0;
}
