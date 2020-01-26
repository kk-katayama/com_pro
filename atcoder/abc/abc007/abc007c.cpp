#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Grid{
  int h,w;
  vector<vector<bool>> grid;
  vector<vector<int>> d;
  vector<int> dx = {1,0,-1,0};
  vector<int> dy = {0,1,0,-1};
  
  Grid(int h_,int w_){
    h = h_;
    w = w_;
    grid.resize(h,vector<bool>(w));
  }

  Grid(int h_,int w_,vector<vector<bool>> grid_){
    h = h_;
    w = w_;
    grid = grid_;
  }
  
  void make_grid(int x,int y,bool c){
    grid[x][y] = c;
  }

  void grid_bfs(int sx,int sy){
    d.assign(h,vector<int>(w,-1));
    queue<pair<int,int>> q;
    d[sx][sy] = 0;
    q.push(make_pair(sx,sy));
    while(!q.empty()){
      pair<int,int> p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;
      for(int i=0;i<4;++i){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(nx>=0&&nx<h&&ny>=0&&ny<w){
	  if(grid[nx][ny]&&d[nx][ny]<0){
	    d[nx][ny] = d[x][y] + 1;
	    q.push(make_pair(nx,ny));
	  }
	}
      }
    }
  }

  int get_d(int x,int y){
    return d[x][y];
  }
  
};

int main()
{
  int r,c;
  cin >> r >> c;
  int sx,sy;
  cin >> sx >> sy;
  sx--;
  sy--;
  int gx,gy;
  cin >> gx >> gy;
  gx--;
  gy--;
  vector<vector<bool>> grid(r,vector<bool>(c));
  rep(i,r){
    rep(j,c){
      char c;
      cin >> c;
      if(c=='#'){
	grid[i][j] = false;
      }
      else{
	grid[i][j] = true;
      }
    }
  }

  Grid gd(r,c,grid);
  gd.grid_bfs(sx,sy);
  cout << gd.get_d(gx,gy) << "\n";
  

  
  return 0;
}
