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
  int n = 19;
  vector<string> s(n);
  rep(i,n) {
    cin >> s[i];
  }

  int b = 0, w = 0;
  rep(i,n) {
    rep(j,n) {
      if(s[i][j] == 'o') b++;
      if(s[i][j] == 'x') w++;      
    }
  }

  if(b == w) {
    bool ff = false;
    if(b == 0) ff = true;
    rep(i,n) {
      rep(j,n) {
	if(s[i][j] == 'x') {
	  s[i][j] = '.';
	  bool f = true;
	  rep(k,n) {
	    rep(l,n) {
	      if(s[k][l] == '.') continue;
	      if(l+4 < n) {
		if(s[k][l] == s[k][l+1] && s[k][l] == s[k][l+2] && s[k][l] == s[k][l+3] && s[k][l] == s[k][l+4]) {
		  f = false;
		}
	      }
	      if(k+4 < n) {
		if(s[k][l] == s[k+1][l] && s[k][l] == s[k+2][l] && s[k][l] == s[k+3][l] && s[k][l] == s[k+4][l]) {
		  f = false;
		}
	      }
	      if(k+4 < n && l+4 < n) {
		if(s[k][l] == s[k+1][l+1] && s[k][l] == s[k+2][l+2] && s[k][l] == s[k+3][l+3] && s[k][l] == s[k+4][l+4]) {
		  f = false;
		}
	      }
	      if(0<=k-4  && l+4 < n) {
		if(s[k][l] == s[k-1][l+1] && s[k][l] == s[k-2][l+2] && s[k][l] == s[k-3][l+3] && s[k][l] == s[k-4][l+4]) {
		  f = false;
		}
	      }	      	      	      
	    }
	  }
	  if(f) ff = true;
	  s[i][j] = 'x';
	}
      }
    }
    if(ff) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
  else if(b == w+1) {
    bool ff = false;
    rep(i,n) {
      rep(j,n) {
	if(s[i][j] == 'o') {
	  s[i][j] = '.';
	  bool f = true;
	  rep(k,n) {
	    rep(l,n) {
	      if(s[k][l] == '.') continue;
	      if(l+4 < n) {
		if(s[k][l] == s[k][l+1] && s[k][l] == s[k][l+2] && s[k][l] == s[k][l+3] && s[k][l] == s[k][l+4]) {
		  f = false;
		}
	      }
	      if(k+4 < n) {
		if(s[k][l] == s[k+1][l] && s[k][l] == s[k+2][l] && s[k][l] == s[k+3][l] && s[k][l] == s[k+4][l]) {
		  f = false;
		}
	      }
	      if(k+4 < n && l+4 < n) {
		if(s[k][l] == s[k+1][l+1] && s[k][l] == s[k+2][l+2] && s[k][l] == s[k+3][l+3] && s[k][l] == s[k+4][l+4]) {
		  f = false;
		}
	      }
	      if(0<=k-4  && l+4 < n) {
		if(s[k][l] == s[k-1][l+1] && s[k][l] == s[k-2][l+2] && s[k][l] == s[k-3][l+3] && s[k][l] == s[k-4][l+4]) {
		  f = false;
		}
	      }	      	      	      
	    }
	  }
	  if(f) ff = true;
	  s[i][j] = 'o';
	}
      }
    }
    if(ff) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }  
  else cout << "NO" << "\n";
  return 0;
}
