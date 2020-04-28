#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
struct Node{
  int x;
  int y;

  Node() = default;

  Node(int x, int y) : x(x), y(y) {}
};
class Grid{
private:
  int row; // height 
  int col; // width
  vector<vector<bool>> grid;
  vector<vector<int>> d; // d[i][j] := shortest distance from start to (i,j)
  int init = -1; // initial value of d
  
  vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1}; // front 4 
  vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};

  void Init_d() {
    d.resize(row, vector<int>(col, init));
  }
  
public:
  Grid() = default;

  Grid(int row, int col) : row(row), col(col) {}

  Grid(int row, int col, vector<vector<bool>> grid) : row(row), col(col), grid(grid) {}

  void BFS(int sx, int sy) {
    Init_d();

    d[sx][sy] = 0;
    queue<Node> q;
    q.emplace(sx, sy);
    while( !q.empty() ) {
      Node p = q.front();
      q.pop();
      int x = p.x, y = p.y;
      rep(i,4) {
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(0 <= nx && nx < row && 0 <= ny && ny < col) {
	  if(grid[nx][ny] && d[nx][ny] < 0) {
	    d[nx][ny] = d[x][y] + 1;
	    q.emplace(nx, ny);
	  }
	}
      }
    }
  }

  int Get_d(int x, int y) {
    return d[x][y];
  }

  void Show() {
    rep(i,row) {
      rep(j,col) {
	cout << d[i][j] << " ";
      }
      cout << "\n";
    }
  }
  
};
int main()
{
  int r,c; cin >> r >> c;
  int sy, sx; cin >> sy >> sx;
  sy--; sx--;
  int gy, gx; cin >> gy >> gx;
  gy--; gx--;
  vector<vector<char>> s(r, vector<char>(c));
  rep(i,r) rep(j,c) cin >> s[i][j];

  vector<vector<bool>> grid(r, vector<bool>(c));
  rep(i,r) rep(j,c) {
    if(s[i][j] == '.') grid[i][j] = true;
    else grid[i][j] = false;    
  }

  Grid gd(r, c, grid);
  gd.BFS(sy, sx);
  cout << gd.Get_d(gy, gx) << "\n";
  //  gd.Show();
  return 0;
}
