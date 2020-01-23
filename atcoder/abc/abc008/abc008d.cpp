#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int w,h;
  cin >> w >> h;
  if(w>80||h>80) return 0;
  int n;
  cin >> n;
  if(n>8) return 0;
  vector<int> x(n),y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }

  vector<int> vec(n);
  rep(i,n){
    vec[i] = i;
  }

  int res = 0;
  
  do{
    vector<vector<bool>> grid(w,vector<bool>(h,true));
    rep(i,n){
      int v = vec[i];
      int nx = x[v];
      int ny = y[v];
      grid[nx][ny] = false;
      nx++;
      while(nx<w){
	if(grid[nx][ny]) grid[nx][ny] = false;
	else break;
	nx++;
      }
      nx = x[v];
      ny = y[v];
      nx--;
      while(0<=nx){
	if(grid[nx][ny]) grid[nx][ny] = false;
	else break;
	nx--;
      }
      nx = x[v];
      ny = y[v];
      ny++;
      while(ny<h){
	if(grid[nx][ny]) grid[nx][ny] = false;
	else break;
	ny++;
      }
      nx = x[v];
      ny = y[v];
      ny--;
      while(0<=ny){
	if(grid[nx][ny]) grid[nx][ny] = false;
	else break;
	ny--;
      }            
    }
    int cnt=0;
    rep(i,w){
      rep(j,h){
	if(!grid[i][j]) cnt++;
      }
    }
    res = max(res,cnt);
  } while(next_permutation(vec.begin(), vec.end()));
  
  cout << res << "\n";
  return 0;
}
