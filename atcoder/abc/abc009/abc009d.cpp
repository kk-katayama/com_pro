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
  ll k,m; cin >> k >> m;
  vl a(k),c(k);
  rep(i,k) cin >> a[i];
  rep(i,k) cin >> c[i];

  vvl mat(k, vl(k, 0));
  rep(i,k) mat[0][i] = c[i];
  rep1(i,k-1) {
    mat[i][i-1] = (1LL << 32) - 1;
  }
  if(m <= k) {
    cout << a[m-1] << "\n";
  }
  else {
    auto calc = [&](vvl a, vvl b)->vvl {
      vvl c(k, vl(k, 0));
      rep(i,k) {
	rep(j,k) {
	  rep(l,k) {
	    c[i][j] = c[i][j] ^ (a[i][l] & b[l][j]);
	  }
	}
      }
      return c;
    };
    vvl E(k, vl(k, 0));
    rep(i,k) E[i][i] = (1LL << 32) - 1;
    m -= k;
    while(m > 0) {
      if(m % 2 == 1) {
	E = calc(mat, E);
      }
      m /= 2;
      mat = calc(mat, mat);
    }
    // rep(i,k) {
    //   rep(j,k) {
    // 	cout << E[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    ll res = 0;
    rep(i,k) {
      res = res ^ (E[0][i] & a[k-1-i]);
    }
    cout << res << "\n";
  }
  
  return 0;
}
