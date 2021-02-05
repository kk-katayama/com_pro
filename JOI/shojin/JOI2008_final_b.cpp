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
  string s,t; cin >> s >> t;
  int n = sz(s), m = sz(t);
  int res = 0;
  rep(i,n) {
    int cnt = 0;
    rep(j,m) {
      if(i + j >= n) break;
      if(s[i+j] == t[j]) cnt++;
      else cnt = 0;
      chmax(res, cnt);
    }
  }
  rep(j,m) {
    int cnt = 0;
    rep(i,n) {
      if(i + j >= m) break;
      if(s[i] == t[i+j]) cnt++;
      else cnt = 0;
      chmax(res, cnt);
    }
  }  
  cout << res << "\n";
  return 0;
}