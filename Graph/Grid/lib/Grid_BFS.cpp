//*****************************************************
// grid BFS 
//*****************************************************
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
      rep(i,4) { // 4 direction
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








