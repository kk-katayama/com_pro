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
  rep(i,h) {
    cin >> s[i];
  }

  vi dx = {-1, 0, 1, 0};
  vi dy = {0, -1, 0, 1};

  vvi d(h, vi(w, inf));
  using ppi = pair<int,pi>;
  priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == '#') {
	d[i][j] = 0;
	pq.push({0, {i, j}});
      }
    }
  }

  while( !pq.empty() ) {
    auto [dis, xy] = pq.top(); pq.pop();
    auto [x, y] = xy;
    rep(i,4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(0 <= nx && nx < h && 0 <= ny && ny < w) {
	if(chmin(d[nx][ny], dis + 1)) {
	  pq.push({dis + 1, {nx, ny}});
	}
      }
    }
  }

  int res = 0;
  rep(i,h) {
    rep(j,w) {
      chmax(res, d[i][j]);
    }
  }
  cout << res << "\n";
  return 0;
}
