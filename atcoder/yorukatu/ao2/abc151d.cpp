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

  int res = 0;
  vi dx = {-1, 0, 1, 0};
  vi dy = {0, -1, 0, 1};
  rep(si,h) {
    rep(sj,w) {
      if(s[si][sj] == '#') continue;
      queue<pi> q;
      vvi d(h, vi(w, inf));
      q.push({si, sj});
      d[si][sj] = 0;
      while( !q.empty() ) {
	auto [x, y] = q.front(); q.pop();
	rep(k,4) {
	  int nx = x + dx[k];
	  int ny = y + dy[k];
	  if(0 <= nx && nx < h && 0 <= ny && ny < w && s[nx][ny] == '.') {
	    if(chmin(d[nx][ny], d[x][y] + 1)) {
	      q.push({nx, ny});
	    }
	  }
	}
      }
      int mx = 0;
      rep(i,h) {
	rep(j,w) {
	  if(s[i][j] == '.') chmax(mx, d[i][j]);
	}
      }
      chmax(res, mx);
    }
  }
  cout << res << "\n";
  return 0;
}
