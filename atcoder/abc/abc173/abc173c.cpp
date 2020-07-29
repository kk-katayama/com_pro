#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int h,w,k; cin >> h >> w >> k;
  vector<vector<char>> c(h, vector<char>(w));
  rep(i,h) rep(j,w) cin >> c[i][j];

  int res = 0;
  rep(hmask,(1 << h)) {
    rep(wmask, (1 << w)) {
      int cnt = 0;
      rep(i,h) {
	rep(j,w) {
	  if((hmask >> i) & 1) continue;
	  if((wmask >> j) & 1) continue;
	  if(c[i][j] == '#') cnt++;
	}
      }
      if(k == cnt) res++;
    }
  }
  cout << res << "\n";
  return 0;
}
