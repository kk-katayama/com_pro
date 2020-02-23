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
	  if(c[nx][ny]!='X'&&d[nx][ny]<0){
	    d[nx][ny] = d[x][y]+1;
	    q.push({nx,ny});
	  }
	}
      }
    }
  }

  void solve(int N){
    vector<pair<int,int>> point(N+1);
    rep(i,h) rep(j,w){
      if(c[i][j]!='X'&&c[i][j]!='.'){
	if(c[i][j]=='S') point[0] = {i,j};
	else point[(int)c[i][j]-'0'] = {i,j};
      }
    }
    int res = 0;
    rep(i,N){
      bfs(point[i].first,point[i].second);
      res += d[point[i+1].first][point[i+1].second];
    }
    cout << res << "\n";
    //    show();
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
  int h,w,N;
  cin >> h >> w >> N;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h) rep(j,w) cin >> c[i][j];

  Grid gr(h,w,c);
  gr.solve(N);
  
  return 0;
}
