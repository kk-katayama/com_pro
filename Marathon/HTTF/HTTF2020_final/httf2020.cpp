#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int c; cin >> c;
  int M = 50;
  vvi p(M, vi(M));
  rep(i,M) {
    rep(j,M) {
      cin >> p[i][j];
    }
  }

  int N = 100;
  vvi f(M,vi(M,0));
  int x = 0, y = 0;
  vi resx(1), resy(1);
  resx[0] = 0, resy[0] = 0;
  vi dx = {-1, 0, 1, 0};
  vi dy = {0, -1, 0, 1};
  rep1(i,N-1) {
    int mx = -1;
    int xx = -1,yy = -1;
    rep(j,4) {
      int nx = x + dx[j];
      int ny = y + dy[j];
      if(0 <= nx && nx < M && 0 <= ny && ny < M) {
	if(chmax(mx, p[nx][ny])) {
	  xx = nx; yy = ny;
	}
      }
    }
    if(xx == -1) break;
    resx.push_back(xx);
    resy.push_back(yy);
    p[xx][yy] = 0;
    x = xx;
    y = yy;
  }
  cout << sz(resx) << "\n";
  rep(i,sz(resx)) {
    cout << resx[i] << " ";
    cout << resy[i] << "\n";
  }
  return 0;
}
