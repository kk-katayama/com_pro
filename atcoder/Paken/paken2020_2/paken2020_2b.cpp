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
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  queue<pi> q;
  vvi d(h, vi(w, inf));
  d[0][0] = 0;
  q.push({0,0});
  while( !q.empty() ) {
    auto [x, y] = q.front(); q.pop();
    if(y + 1 < w) {
      if(s[x][y] == 'E') {
	if(chmin(d[x][y+1], d[x][y])) {
	  q.push({x, y+1});
	}
      }
      else {
	if(chmin(d[x][y+1], d[x][y]+1)) {
	  q.push({x, y+1});
	}	
      }
    }
    if(x + 1 < h) {
      if(s[x][y] == 'E') {
	if(chmin(d[x+1][y], d[x][y]+1)) {
	  q.push({x+1, y});
	}
      }
      else {
	if(chmin(d[x+1][y], d[x][y])) {
	  q.push({x+1, y});
	}	
      }
    }    
  }
  if(s[h-1][w-1] == 'E') cout << d[h-1][w-1] << "\n";
  else cout << d[h-1][w-1] + 1 << "\n";
  return 0;
}
