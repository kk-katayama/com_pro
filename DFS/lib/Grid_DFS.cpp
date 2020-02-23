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
  vector<int> dx={1,0,-1,1,-1,1,0,-1};
  vector<int> dy={1,1,1,0,0,-1,-1,-1};
public:
  //***************Constractor****************************
  Grid(int _h,int _w,vector<vector<int>> _c){
    w = _w;h = _h;c = _c;
  }

  //***********************************************
  
  void simple_dfs(int x,int y){
    c[x][y] = 0;
    rep(i,8){
      int nx = x + dx[i],ny = y + dy[i];
      if(nx>=0&&nx<h&&ny>=0&&ny<w) if(c[nx][ny]==1) simple_dfs(nx,ny);
    }
  }

  int run_dfs(){
    int res=0;
    rep(x,h) rep(y,w){
      if(c[x][y]==1){
	res++;
	simple_dfs(x,y);
      }
    }
    return res;
  }

  void show(){
    rep(i,h){
      rep(j,w) cout << c[i][j] << " ";
      cout  << "\n";
    }
  }
  
};


int main()
{
  int w,h;
  vector<int> res;
  while(1){
    cin >> w >> h;
    if(w==0&&h==0) break;
    vector<vector<int>> c(h,vector<int>(w));
    rep(i,h) rep(j,w) cin >> c[i][j];
    Grid gr(h,w,c);
    res.push_back(gr.run_dfs());
  }
  rep(i,res.size()) cout << res[i] << "\n";
  return 0;
}
