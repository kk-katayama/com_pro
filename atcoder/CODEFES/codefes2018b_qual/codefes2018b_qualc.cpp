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
  int n; cin >> n;
  vector<vector<char>> res(n, vector<char>(n, '.'));
  rep(i,n) {
    rep(j,n) {
      if(i % 5 == 0 && j % 5 == 0) res[i][j] = 'X';
      else if(i % 5 == 1 && j % 5 == 3) res[i][j] = 'X';
      else if(i % 5 == 2 && j % 5 == 1) res[i][j] = 'X';
      else if(i % 5 == 3 && j % 5 == 4) res[i][j] = 'X';
      else if(i % 5 == 4 && j % 5 == 2) res[i][j] = 'X';      
    }
  }

  res[n-1][n-1] = 'X';
  
  rep(i,n) {
    if(i % 3 == 0) {
      res[i][0] = 'X';
      res[i][n-1] = 'X';
    }
  }

  rep(j,n) {
    if(j % 3 == 0) {
      res[0][j] = 'X';
      res[n-1][j] = 'X';
    }
  }  

  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};
  
  // int cnt = 0;
  // rep(i,n) {
  //   rep(j,n) {
  //     if(res[i][j] == 'X') {
  // 	cnt++;
  // 	rep(k,4) {
  // 	  int nx = i + dx[k];
  // 	  int ny = j + dy[k];
  // 	  if(0 <= nx && nx < n && 0 <= ny && ny < n) {
  // 	    if(res[nx][ny] == '.')  res[nx][ny] = 'x';
  // 	  }
  // 	}
  //     }
  //   }
  // }

  rep(i,n) {
    rep(j,n) {
      cout << res[i][j];
    }
    cout << "\n";
  }
  
  return 0;
}
