#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,x,y; cin >> n >> x >> y;
  x += 201;
  y += 201;
  vector<int> a(n), b(n);
  rep(i,n) {
    cin >> a[i] >> b[i];
    a[i] += 201;
    b[i] += 201;
  }

  int M = 403;
  vector<vector<bool>> grid(M, vector<bool>(M, true));
  rep(i,n) grid[a[i]][b[i]] = false;

  vector<vector<int>> dp(M, vector<int>(M, -1));
  dp[201][201] = 0;
  using pi = pair<int,int>;
  queue<pi> q;
  q.push({201, 201});
  vector<int> dx = {1, 1, 0, 0, -1, -1};
  vector<int> dy = {1, 0, 1, -1, 1, 0};  
  while(!q.empty()) {
    pi p = q.front(); q.pop();
    int xx = p.first, yy = p.second;
    rep(i,6) {
      int nx = xx + dx[i];
      int ny = yy + dy[i];
      if(0 <= nx && nx < M && 0 <= ny && ny < M) {
	if(dp[nx][ny] >= 0 || !grid[nx][ny]) continue;
	dp[nx][ny] = dp[xx][yy] + 1;
	q.push({nx, ny});
      }
    }
  }

  cout << dp[x][y] << "\n";
  
  return 0;
}
