#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w;cin >> h >> w;
  int n;cin >> n;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h) rep(j,w) cin >> c[i][j];
  vector<int> x(n),y(n),a(n),b(n);
  rep(i,n) cin >> x[i] >> y[i] >> a[i] >> b[i];
  vector<vector<int>> jsum(h+1,vector<int>(w+1,0));
  vector<vector<int>> osum(h+1,vector<int>(w+1,0));
  vector<vector<int>> isum(h+1,vector<int>(w+1,0));

  rep(i,h) rep(j,w){
    if(c[i][j]=='J'){
      jsum[i+1][j+1] = 1 + jsum[i+1][j] + jsum[i][j+1] - jsum[i][j];
      osum[i+1][j+1] = osum[i+1][j] + osum[i][j+1] - osum[i][j];
      isum[i+1][j+1] = isum[i+1][j] + isum[i][j+1] - isum[i][j];      
    }
    else if(c[i][j]=='O'){
      jsum[i+1][j+1] = jsum[i+1][j] + jsum[i][j+1] - jsum[i][j];
      osum[i+1][j+1] = 1 + osum[i+1][j] + osum[i][j+1] - osum[i][j];
      isum[i+1][j+1] = isum[i+1][j] + isum[i][j+1] - isum[i][j];      
    }
    else if(c[i][j]=='I'){
      jsum[i+1][j+1] = jsum[i+1][j] + jsum[i][j+1] - jsum[i][j];
      osum[i+1][j+1] = osum[i+1][j] + osum[i][j+1] - osum[i][j];
      isum[i+1][j+1] = 1 + isum[i+1][j] + isum[i][j+1] - isum[i][j];      
    }    
  }
  
  rep(i,n){
    int jj = jsum[a[i]][b[i]] - jsum[a[i]][y[i]-1] - jsum[x[i]-1][b[i]] + jsum[x[i]-1][y[i]-1];
    int oo = osum[a[i]][b[i]] - osum[a[i]][y[i]-1] - osum[x[i]-1][b[i]] + osum[x[i]-1][y[i]-1];
    int ii = isum[a[i]][b[i]] - isum[a[i]][y[i]-1] - isum[x[i]-1][b[i]] + isum[x[i]-1][y[i]-1];
    cout << jj << " " << oo << " " << ii << "\n";
  }
  
  return 0;
}
