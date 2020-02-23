#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Grid
{
private:
  int h,w;
  vector<vector<char>> c;
  vector<vector<int>> d;
  vector<int> dx={1,0,-1,0};
  vector<int> dy={0,1,0,-1};  
public:  
  Grid(int _h,int _w,vector<vector<char>> _c):h(_h),w(_w),c(_c){}

  void bfs(int sx,int sy)
  {
    d.assign(h,vector<int>(w,-1));
    queue<pair<int,int>> q;
    d[sx][sy] = 0;
    q.push({sx,sy});
    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      rep(i,4){
	int nx=x+dx[i],ny=y+dy[i];
	if(nx>=0&&nx<h&&ny>=0&&ny<w){
	  if(c[nx][ny]!='#'&&d[nx][ny]<0){
	    d[nx][ny] = d[x][y]+1;
	    q.push({nx,ny});
	  }
	}
      }
    }
  }

  void solve(){
    
  }

  void show(){
    rep(i,h){
      rep(j,w) cout << d[i][j] << " ";
      cout  << "\n";
    }
  }
  
  
};

int main()
{
  int h,w;
  cin >> h >> w;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h) rep(j,w) cin >> c[i][j];
  return 0;
}
