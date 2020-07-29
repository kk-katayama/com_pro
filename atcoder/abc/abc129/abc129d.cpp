#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int h,w; cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  rep(i,h) rep(j,w) cin >> s[i][j];

  vector<vector<int>> L(h, vector<int>(w));
  vector<vector<int>> R(h, vector<int>(w));  
  vector<vector<int>> U(h, vector<int>(w));
  vector<vector<int>> D(h, vector<int>(w));

  rep(i,h) {
    int cnt = 0;
    rep(j,w) {
      if(s[i][j] == '.') cnt++;
      else cnt = 0;
      L[i][j] = cnt;
    }
  }

  rep(i,h) {
    int cnt = 0;
    rep(j,w) {
      if(s[i][w-1-j] == '.') cnt++;
      else cnt = 0;
      R[i][w-1-j] = cnt;
    }
  }  

  rep(j,w) {
    int cnt = 0;
    rep(i,h) {
      if(s[i][j] == '.') cnt++;
      else cnt = 0;
      U[i][j] = cnt;
    }
  }

  rep(j,w) {
    int cnt = 0;
    rep(i,h) {
      if(s[h-1-i][j] == '.') cnt++;
      else cnt = 0;
      D[h-1-i][j] = cnt;
    }
  }  

  int res = 0;
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == '.') {
	chmax(res, L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3);
      }
    }
  }
  cout << res << "\n";
  
  return 0;
}
