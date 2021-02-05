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
  int n; cin >> n;
  string s; cin >> s;
  ll cnt = 0;
  ll M = 1e+10;
  if(n == 1) {
    if(s[0] == '1') {
      cout << 2*M << "\n";
    }
    else {
      cout << M << "\n";
    }
    return 0;
  }
  if(n == 2 && s[0] == '1' && s[1] == '1') {
    cout << M << "\n";
    return 0;
  }
  if(s[0] == '0') {
    bool f = true;
    rep1(i,n-1) {
      if(i+2 < n) {
	if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0') {
	  cnt++;
	}
	else {
	  f = false;
	}
      }
      else if(i+1<n){
	if(s[i] == '1' && s[i+1] == '1') {
	  cnt++;
	}
	else {
	  f = false;
	}	
      }
      else {
	if(s[i] == '1') {
	  cnt++;
	}
	else {
	  f = false;
	}	
      }      
      i += 2;
    }
    if(f) cout << M - cnt << "\n";
    else cout << 0 << "\n";
  }
  else if(n >= 2 && s[0] == '1' && s[1] == '0') {
    bool f = true;
    for (int i = 2; i < n; ++i) {
      if(i+2 < n) {
	if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0') {
	  cnt++;
	}
	else {
	  f = false;
	}
      }
      else if(i+1<n){
	if(s[i] == '1' && s[i+1] == '1') {
	  cnt++;
	}
	else {
	  f = false;
	}	
      }
      else {
	if(s[i] == '1') {
	  cnt++;
	}
	else {
	  f = false;
	}	
      }      
      i += 2;
    }
    if(f) cout << M - cnt << "\n";
    else cout << 0 << "\n";
  }
  else if(n >= 3 && s[0] == '1' && s[1] == '1' && s[2] == '0') {
    bool f = true;
    for (int i = 3; i < n; ++i) {
      if(i+2 < n) {
	if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0') {
	  cnt++;
	}
	else {
	  f = false;
	}
      }
      else if(i+1<n){
	if(s[i] == '1' && s[i+1] == '1') {
	  cnt++;
	}
	else {
	  f = false;
	}	
      }
      else {
	if(s[i] == '1') {
	  cnt++;
	}
	else {
	  f = false;
	}	
      }      
      i += 2;
    }
    if(f) cout << M - cnt << "\n";
    else cout << 0 << "\n";
  }
  else cout << 0 << "\n";
  return 0;
}
