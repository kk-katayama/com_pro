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
  int c; cin >> c;
  string t = "atcoder";
  while(c-- > 0) {
    string s; cin >> s;
    int res = inf;
    rep(i,min(7,sz(s))) {
      if(t[i] < s[i]) {
	res = 0;
      }
      else {
	bool ff = true;
	for (int j = i+1; j < sz(s); ++j) {
	  if(t[i] < s[j]) {
	    chmin(res, j -i);
	    ff = false;
	    break;
	  }
	}
	if(t[i] != s[i]) break;
      }
    }
    bool f = true;
    rep(i,7) {
      if(s[i] != t[i]) f = false;
    }
    if(f) {
      if(sz(s) > 7) cout << 0 << "\n";
      else cout << 1 << "\n";
    }
    else cout << (res == inf ? -1 : res) << "\n";
  }
  return 0;
}
