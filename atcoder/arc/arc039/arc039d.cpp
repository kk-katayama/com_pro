#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int a,b; cin >> a >> b;

  vector<vector<char>> res(99, vector<char>(99, '.'));
  rep(i,99) {
    rep(j,99) {
      if(i % 4 != 3) {
	if(j % 4 != 3) res[i][j] = '#';
      }
      // else if(i % 4 == 1) {
      // 	if(j % 2 == 0) res[i][j] = '#';
      // }
    }
  }
  
  rep(i,99) {
    res[0][i] = '#';
    res[98][i] = '#';
    res[i][0] = '#';
    res[i][98] = '#';
  }
  
  rep(i,99) {
    rep(j,93) {
      if(i > 3 && i % 4 == 2) res[i][j] = '#';
    }
  }

  
  int x = 1, y = 1;
  while(--a > 0) {
    res[x][y] = '.';
    y += 4;
    if(y >= 99) {
      y = 1;
      x += 4;
    }
  }

  x = 6; y = 91;
  while(--b) {
    res[x][y] = '.';
    y -= 4;
    if(y < 0) {
      y = 91;
      x += 4;
    }    
  }
  
  cout << 99 << " " << 99 << "\n";
  rep(i,99) {
    rep(j,99) {
      cout << res[i][j];
    }
    cout << "\n";
  }
  
  return 0;
}
