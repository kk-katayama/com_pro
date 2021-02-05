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
  int h,w; cin >> h >> w;
  vvi s(h, vi(w));
  rep(i,h) rep(j,w) cin >> s[i][j];

  vvl yoko(h, vl(3, 0)), tate(w, vl(3, 0));
  rep(i,h) {
    rep(j,w) {
      yoko[i][s[i][j]]++;
      tate[j][s[i][j]]++;
    }
  }

  ll res = 0;
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == 0) {
	res += yoko[i][1] * tate[j][2];
	res += yoko[i][2] * tate[j][1];	
      }
      if(s[i][j] == 1) {
	res += yoko[i][0] * tate[j][2];
	res += yoko[i][2] * tate[j][0];	
      }
      if(s[i][j] == 2) {
	res += yoko[i][1] * tate[j][0];
	res += yoko[i][0] * tate[j][1];	
      }      
    }
  }

  cout << res/2 << "\n";

  return 0;
}
