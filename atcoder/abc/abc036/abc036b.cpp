#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<vector<char>> s(n,vector<char>(n));
  rep(i,n){
    rep(j,n){
      cin >> s[i][j];
    }
  }

  vector<vector<char>> res(n,vector<char>(n));
  rep(i,n){
    rep(j,n){
      res[j][n-1-i] = s[i][j];
    }
  }

  rep(i,n){
    rep(j,n){
      cout << res[i][j];
    }
    cout  << "\n";
  }
  return 0;
}
