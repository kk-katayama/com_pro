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
  int h,w; cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  rep(i,h) rep(j,w) cin >> s[i][j];

  vector<int> dx = {1, 0};
  vector<int> dy = {0, 1};
  vector<vector<int>> d(h, vector<int>(w, 1e+9));
  if(s[0][0] == '#') d[0][0] = 1;
  else d[0][0] = 0;

  rep(i,h) rep(j,w) {
    if(i+1 < h) {
      if(s[i][j] == '.' && s[i+1][j] == '#') chmin(d[i+1][j], d[i][j]+1);
      else chmin(d[i+1][j], d[i][j]);
    }
    if(j+1 < w) {
      if(s[i][j] == '.' && s[i][j+1] == '#') chmin(d[i][j+1], d[i][j]+1);
      else chmin(d[i][j+1], d[i][j]);
    }      
  }

  cout << d[h-1][w-1] << "\n";
  
  return 0;
}
