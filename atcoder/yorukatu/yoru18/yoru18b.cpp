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
  vector<vector<char>> c(h, vector<char>(w));
  rep(i,h) rep(j,w) cin >> c[i][j];

  vector<vector<bool>> f(h, vector<bool>(w, true));
  rep(i,h) {
    bool ff = true;
    rep(j,w) {
      if(c[i][j] == '#') ff = false;
    }
    if(ff){
      rep(j,w) {
	f[i][j] = false;
      }
    }
  }

  rep(j,w) {
    bool ff = true;
    rep(i,h) {
      if(c[i][j] == '#') ff = false;
    }
    if(ff){
      rep(i,h) {
	f[i][j] = false;
      }
    }
  }

  rep(i,h) {
    bool fff = false;
    rep(j,w) {
      if(f[i][j]) {
	cout << c[i][j];
	fff = true;
      }
    }
    if(fff) cout << "\n";
  }
  
  return 0;
}
