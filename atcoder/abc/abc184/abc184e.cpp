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

  int sx, sy;
  int gx, gy;
  vector<vector<pi>> edge(26);
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == 'S') { sx = i; sy = j;}
      else if(s[i][j] == 'G') { gx = i; gy = j;}
      else if(s[i][j] != '.' && s[i][j] != '#') {
	int c = s[i][j] - 'a';
	edge[c].push_back({i, j});
      }
    }
  }

  vi dx = {-1, 0, 1, 0};
  vi dy = {0, -1, 0, 1};
  
  vector<bool> f(26, false);
  vvi d(h, vi(w, -1));
  deque<pi> dq;
  dq.push_back({sx, sy});
  d[sx][sy] = 0;
  while(!dq.empty()) {
    auto [x, y] = dq.front();
    //    cout << x << ":" << y << "\n";
    dq.pop_front();
    if(s[x][y] != '.' && s[x][y] != 'S' && s[x][y] != 'G') {
      int c = s[x][y] - 'a';
      if(!f[c]) {
	for(auto val: edge[c]) {
	  auto [nx, ny] = val;
	  if(x == nx && y == ny) continue;
	  if(d[nx][ny] >= 0) continue;	
	  d[nx][ny] = d[x][y] + 1;
	  dq.push_back({nx, ny});	
	}
	f[c] = true;
      }
    }
    rep(i,4) {
      int nx = x + dx[i], ny = y + dy[i];
      if(0 <= nx && nx < h && 0 <= ny && ny < w && s[nx][ny] != '#') {
	if(d[nx][ny] >= 0) continue;
	d[nx][ny] = d[x][y] + 1;
	dq.push_back({nx, ny});
      }
    }
  }

  // rep(i,h) {
  //   rep(j,w) {
  //     cout << d[i][j] << " ";
  //   }
  //   cout  << "\n";
  // }
  
  cout << d[gx][gy] << "\n";
  return 0;
}
