#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int h,w,k;cin >> h >> w >> k;
  vector<vector<char>> a(h, vector<char>(w));
  int sx, sy;
  rep(i,h) rep(j,w) {
    cin >> a[i][j];
    if(a[i][j] == 'S') {
      sx = i; sy = j;
    }
  }

  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};

  const int inf = 1e+9;
  vector<vector<int>> d(h, vector<int>(w, inf));
  d[sx][sy] = 0;
  using pi = pair<int,int>;
  queue<pi> q;
  q.push({sx, sy});
  while( !q.empty() ) {
    pi p = q.front(); q.pop();
    int x = p.first, y = p.second;
    rep(i,4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(0 <= nx && nx < h && 0 <= ny && ny < w) {
	if(a[nx][ny] == '#' || d[nx][ny] != inf) continue;
	d[nx][ny] = d[x][y] + 1;
	q.push({nx, ny});
      }
    }
  }
  int res = 1e+9;

  auto Ceil = [](int a, int b)-> int{
		if(a%b == 0) return a/b;
		else return (a+b-a%b)/b;
	      };
  
  rep(i,h) rep(j,w) {
    if(d[i][j] <= k) {
      int dis = min({i, h-i-1, j, w-j-1});
      chmin(res, Ceil(dis,k) + 1);
    }
  }
  cout << res << "\n";
  
  return 0;
}
