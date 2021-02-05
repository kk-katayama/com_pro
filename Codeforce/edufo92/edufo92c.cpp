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
    string s; cin >> s;
    int n = sz(s);
    
    auto func = [&](char a, char b)-> int{
      int res = 0;
      int id = 0;
      while(id < n) {
	while(id < n && s[id] != a) {
	  id++;
	}
	id++;
	while(id < n && s[id] != b) {
	  id++;
	}      
	if(id < n)  res += 2;
	id++;
      }      
      return n - res;
    };

    int res = inf;
    rep(i,10) {
      rep(j,10) {
	char a = '0' + i, b = '0' + j;
	chmin(res, func(a, b));
      }
    }

    vi num(10, 0);
    rep(i,n) {
      num[int(s[i] - '0')]++;
    }
    rep(i,10) chmin(res, n - num[i]);
    
    cout << res << "\n";
  }
  return 0;
}
