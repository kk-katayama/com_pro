#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct DFS{
  int n;
  int m;
  vector<string> s;

  DFS(int _n,int _m,vector<string> _s){
    n=_n;
    m=_m;
    s=_s;
  }
  
  void dfs(int x,int y){
    s[x][y]='.';
    for(int i=-1;i<=1;++i){
      for(int j=-1;j<=1;++j){
	int nx=x+i;
	int ny=y+j;
	if(nx>=0&&nx<n&&ny>=0&&ny<m){
	  if(s[nx][ny]=='W') dfs(nx,ny);
	}
      }
    }
  }

  void solve(){
    int cnt=0;
    rep(i,n){
      rep(j,m){
	if(s[i][j]=='W'){
	  cnt++;
	  dfs(i,j);
	}
      }
    }
    cout << cnt << "\n";
  }
  
};


int main()
{
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  DFS df(n,m,s);

  df.solve();

  
  return 0;
}
