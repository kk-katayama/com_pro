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
  ll l,a,b; cin >> l >> a >> b;
  ll m; cin >> m;

  vl pred(20), d(19);
  ll x = 9;
  pred[0] = 0;
  rep1(i,18) {
    ll cnt = min(l, max((ll)0, (x-a)/b+1));
    pred[i] = cnt;
    x = x*10+9;
  }
  
  rep(i,18) {
    d[i] = pred[i+1] - pred[i];
  }

  //  rep(i,18) cout << d[i] << "\n";
  a %= m;
  b %= m;
  vl v = {0, a, 1};
  ll h = 10;
  rep(i,18) {
    vvl w =
      {{h, 0, 0},
       {1, 1, 0},
       {0, b, 1}};
    h = 10*h % m;
    if(d[i] == 0) continue;
    vvl z =
      {{1, 0, 0},
       {0, 1, 0},
       {0, 0, 1}};
    while(d[i] > 0) {
      if(d[i] % 2 == 1) {
	vvl tmp(3, vl(3, 0));
	rep(j,3) {
	  rep(k,3) {
	    rep(t,3) {
	      tmp[j][k] = (tmp[j][k] + (z[j][t]*w[t][k]) % m) % m;
	    }
	  }
	}
	swap(z, tmp);
      }
      d[i] /= 2;
      vvl tmp(3, vl(3, 0));
      rep(j,3) {
	rep(k,3) {
	  rep(t,3) {
	    tmp[j][k] = (tmp[j][k] + (w[j][t]*w[t][k]) % m) % m;
	  }
	}
      }
      swap(w, tmp);
    }
    vl tmp(3, 0);
    rep(j,3) {
      rep(k,3) {
	tmp[j] = (tmp[j] + (v[k]*z[k][j])%m) % m;
      }
    }
    swap(v, tmp);
  }
  cout << v[0] << "\n";
  
  return 0;
}
