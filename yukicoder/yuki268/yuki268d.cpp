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
  vl pow2(60);
  pow2[0] = 1;
  rep(i,59) pow2[i+1] = pow2[i]*2;

  int n,q; cin >> n >> q;
  int mx = 0;
  vi a(n);
  rep(i,n) {
    cin >> a[i];
    chmax(mx, a[i]);
  }
  string s; cin >> s;
  vi t(q);
  rep(i,q) {
    cin >> t[i];
    chmax(mx, t[i]);
  }

  int cnt = 0;
  while(mx > 0) {
    mx /= 2;
    cnt++;
  }
  
  vvl sc(cnt, vl(2, 0));
  vvi num(cnt, vi(2, 0));
  rep(i, cnt) num[i][1] = 1;
  rep(i,n) {
    rep(j,cnt) {
      int x = (a[i] >> j) & 1;
      if(s[i] == '0') { //AND
	if(x == 0) {
	  rep(k,2) {
	    if(num[j][k] == 1) {
	      sc[j][k] += pow2[j];
	      num[j][k] = 0;
	    }
	    else {
	      num[j][k] = 0;
	    }
	  }
	}
	else {
	  rep(k,2) {
	    if(num[j][k] == 1) {
	      num[j][k] = 1;
	    }
	    else {
	      num[j][k] = 0;
	    }
	  }
	}
      }
      else { //OR
	if(x == 0) {
	  rep(k,2) {
	    if(num[j][k] == 1) {
	      num[j][k] = 1;
	    }
	    else {
	      num[j][k] = 0;
	    }	  
	  }
	}
	else {
	  rep(k,2) {
	    if(num[j][k] == 1) {
	      num[j][k] = 1;
	    }
	    else {
	      sc[j][k] += pow2[j];
	      num[j][k] = 1;
	    }	  
	  }	  
	}
      }
    }
  }

  rep(i,q) {
    ll res = 0;
    rep(j,cnt) {
      int x = (t[i] >> j) & 1;
      res += sc[j][x];
    }
    cout << res << "\n";
  }
  
  return 0;
}
