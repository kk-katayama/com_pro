#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using pi = pair<int,int>;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<pi> mov(int x, int y, int n) {
  vector<pi> res;
  rep(j,4) {
    int nx = x + dx[j];
    int ny = y + dy[j];
    if(0 < nx && nx <= n && 0 < ny && ny <= n) {
      res.push_back({nx, ny});
    }
  }
  return res;
}
int main()
{
  int n; cin >> n;
  vector<int> p(n*n);
  rep(i,n*n) {
    cin >> p[i];
  }

  vector<vector<int>> c(n+1, vector<int>(n+1));
  rep1(i,n) rep1(j,n) {
    c[i][j] = min({i-1, n-i, j-1, n-j});
  }

  auto show = [&]()-> void{
		rep1(i,n) {
		  rep1(j,n) cout << c[i][j] << " ";
		  cout << "\n";
		}  
	      };
  
  vector<vector<bool>> f(n+1, vector<bool>(n+1, true));


  int res = 0;
  rep(i,n*n) {
    int x = (p[i] + n - 1)/n;
    int y = (p[i] % n == 0 ? n : p[i] % n);
    res += c[x][y];
    f[x][y] = false;
    queue<pi> q;
    q.push({x, y});
    while( !q.empty() ) {
      pi pp = q.front(); q.pop();
      int xx = pp.first, yy = pp.second;
      vector<pi> buf = mov(xx, yy, n);
      rep(j,buf.size()) {
	int nx = buf[j].first;
	int ny = buf[j].second;	
	if(chmin(c[nx][ny], c[xx][yy] + f[xx][yy])) {
	  q.push({nx, ny});
	}
      }
    }
  }
  cout << res << "\n";
  return 0;
}
