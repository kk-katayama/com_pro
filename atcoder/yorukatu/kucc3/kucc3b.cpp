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
  int r,c,d;cin >> r >> c >> d;
  vector<vector<int>> a(r, vector<int>(c));
  rep(i,r) rep(j,c) cin >> a[i][j];

  int res = 0;
  rep(i,r) {
    rep(j,c) {
      if(i + j <= d && (d % 2) == ((i + j) % 2)) chmax(res, a[i][j]);
    }
  }

  cout << res << "\n";
  return 0;
}
