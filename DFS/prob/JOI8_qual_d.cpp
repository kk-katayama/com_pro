#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Grid{
private:
  int h,w;
  vector<vector<int>> c;
  vector<int> dx={1,0,-1,0};
  vector<int> dy={0,1,0,-1};
  int ax;
  vector<vector<bool>> visit;
public:
  //***************Constractor****************************
  Grid(int _h,int _w,vector<vector<int>> _c){
    w = _w;h = _h;c = _c;
  }

  //***********************************************
  
  void simple_dfs(int x,int y,int cnt){
    visit[x][y] = true;
    rep(i,4){
      int nx = x + dx[i],ny = y + dy[i];
      if(nx>=0&&nx<h&&ny>=0&&ny<w){
	if(c[nx][ny]==1&&!visit[nx][ny]) simple_dfs(nx,ny,cnt+1);
      }
    }
    visit[x][y] = false;
    ax = max(cnt,ax);
  }

  void run_dfs(){
    ax = 0;
    visit.assign(h,vector<bool>(w,false));
    rep(x,h) rep(y,w){
      if(c[x][y]==1){
	visit.assign(h,vector<bool>(w,false));
	simple_dfs(x,y,1);
	//	show();
      }
    }
    cout << ax << "\n";
  }

  void show(){
    cout << "***************************" << "\n";
    rep(i,h){
      rep(j,w) cout << visit[i][j] << " ";
      cout  << "\n";
    }
  }
  
};


int main()
{
  int w,h;
  cin >> w >> h;
  vector<vector<int>> c(h,vector<int>(w));
  rep(i,h) rep(j,w) cin >> c[i][j];
  Grid gr(h,w,c);
  gr.run_dfs();

  return 0;
}
