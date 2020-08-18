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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main()
{
  int h,w; cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  queue<pi> q;
  q.push({0, 0});
  while(!q.empty()) {
    pi p = q.front(); q.pop();
    rep(i,2) {
      int nx = p.F + dx[i+2];
      int ny = p.S + dy[i+2];
      if(0 <= nx && nx < h && 0 <= ny && ny < w) {
	if(s[nx][ny] == '#') {
	  cout << "Impossible" << "\n";
	  return 0;
	}
      }
    }
    bool f = false;
    rep(i,2) {
      int nx = p.F + dx[i];
      int ny = p.S + dy[i];
      if(0 <= nx && nx < h && 0 <= ny && ny < w) {
	if(s[nx][ny] == '#') {
	  if(!f) {
	    q.push({nx, ny});
	    f = true;
	  }
	  else {
	    cout << "Impossible" << "\n";
	    return 0;
	  }
	}
      }      
    }
    s[p.F][p.S] = '.';
  }
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == '#') {
	cout << "Impossible" << "\n";
	return 0;
      }
    }
  }
  cout << "Possible" << "\n";
  
  return 0;
}
