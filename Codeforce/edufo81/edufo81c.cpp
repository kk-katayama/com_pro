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
    string s,t; cin >> s >> t;
    vvi lis(26);
    int n = sz(s);
    rep(i,n) {
      int c = int(s[i] - 'a');
      lis[c].push_back(i);
    }
    int m = sz(t);
    int res = 1;
    int bot = -1;
    bool f = false, ff = true;
    rep(i,m) {
      int c = int(t[i] - 'a');
      int lb = -1, ub = sz(lis[c]);
      while(ub - lb > 1) {
	int mid = (ub + lb) / 2;
	(bot < lis[c][mid] ? ub : lb) = mid;
      }
      if(ub == sz(lis[c])) {
	if(f) {
	  ff = false;
	  break;
	}
	f = true;
	res++;
	bot = -1;
	i--;
      }
      else {
	bot = lis[c][ub];
	f = false;
      }
    }
    if(ff) cout << res << "\n";
    else cout << -1 << "\n";
  }
  return 0;
}
