#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
vector<vector<char>> s;
vector<vector<bool>> f;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
void dfs(int x, int y, char c) {
  f[x][y] = true;
  rep(i,4) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < n && 0 <= ny && ny < n ) {
      if(s[nx][ny] == c && !f[nx][ny] ) dfs(nx, ny, c);
    }
  }
}
int main()
{
  cin >> n;
  s.resize(n, vector<char>(n));
  // red : # , white : .
  int cnt = 0;
  for(int S = 0;S < (1 << n*n);++S) {
    rep(i,n) rep(j,n){
      if( ( S >> (j + n*i ) ) & 1 ) s[i][j] = '#';
      else s[i][j] = '.';
    }
    // rep(i,n){
    //   rep(j,n) cout << s[i][j];
    //   cout << "\n";
    // }
    f.assign(n, vector<bool>(n, false));
    int red = 0, white = 0;
    rep(i,n) rep(j,n){
      if(!f[i][j]) {
	if(s[i][j] == '#') { // red
	  red++;
	  dfs(i, j, '#');
	}
	else { // white
	  white++;
	  dfs(i, j, '.');
	}      
      }
    }
    if(red == white) cnt++;
    //    cout << red << ":" << white << "\n";    
  }
  cout << cnt << "/" << (int)pow(2, n*n) << "\n";
  
  return 0;
}
