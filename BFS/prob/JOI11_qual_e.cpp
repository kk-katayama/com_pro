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
  vector<vector<int>> c;
  vector<vector<int>> d;
  vector<int> dx={-1,-1,0,0,1,1};
  vector<int> dy={0,1,-1,1,0,1};
  vector<int> dx2={-1,-1,0,0,1,1};
  vector<int> dy2={-1,0,-1,1,-1,0};  
public:  
  Grid(int _h,int _w,vector<vector<int>> _c):h(_h),w(_w),c(_c){}

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
      rep(i,6){
	int nx=x+dx[i],ny=y+dy[i];
	if(x%2==0){
	  nx=x+dx2[i];
	  ny=y+dy2[i];
	}
	if(nx>=0&&nx<h&&ny>=0&&ny<w){
	  if(c[nx][ny]==0&&d[nx][ny]<0){
	    d[nx][ny] = d[x][y]+1;
	    q.push({nx,ny});
	  }
	}
      }
    }
  }

  void solve(){
    bfs(0,0);
    rep(i,h) rep(j,w) if(d[i][j]<0) c[i][j]=1;

    int res=0;
    rep(x,h) rep(y,w){
      if(c[x][y]==0) continue;
      int cnt=6;
      rep(i,6){
	int nx,ny;
	if(x%2==0){
	  nx = x + dx2[i];ny = y + dy2[i];
	}
	else{
	  nx = x + dx[i];ny = y + dy[i];
	}
	if(nx>=0&&nx<h&&ny>=0&&ny<w){
	  if(c[nx][ny]==1) cnt--;
	}
      }
      res += cnt;
    }
    cout << res << "\n";
  }

  void show(){
    cout << "*********************" << "\n";
    rep(i,h){
      rep(j,w) cout << c[i][j] << " ";
      cout  << "\n";
    }
  }
  
  
};

int main()
{
  int w,h;
  cin >> w >> h;
  vector<vector<int>> c(h+2,vector<int>(w+2,0));
  rep1(i,h) rep1(j,w) cin >> c[i][j];
  
  Grid gr(h+2,w+2,c);
  gr.solve();
  
  return 0;
}
