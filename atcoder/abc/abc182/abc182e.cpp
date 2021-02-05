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
  int h,w,n,m; cin >> h >> w >> n >> m;
  vvi s(h, vi(w, 0));
  rep(i,n) {
    int a,b; cin >> a >> b;
    s[a-1][b-1] = 1;
  }
  rep(i,m) {
    int c,d; cin >> c >> d;
    s[c-1][d-1] = 2;
  }

  vvi f(h, vi(w, 0));
  rep(i,h) {
    int flag = 0;
    rep(j,w) {
      if(s[i][j] == 1) flag = 1;
      else if(s[i][j] == 2) flag = 0;
      if(flag) f[i][j] = 1;
    }
  }

  rep(i,h) {
    int flag = 0;
    for (int j = w-1; j >= 0; --j) {
      if(s[i][j] == 1) flag = 1;
      else if(s[i][j] == 2) flag = 0;
      if(flag) f[i][j] = 1;
    }
  }

  rep(j,w) {
    int flag = 0;
    rep(i,h) {
      if(s[i][j] == 1) flag = 1;
      else if(s[i][j] == 2) flag = 0;
      if(flag) f[i][j] = 1;
    }
  }

  rep(j,w) {
    int flag = 0;
    for (int i = h-1; i >= 0; --i) {
      if(s[i][j] == 1) flag = 1;
      else if(s[i][j] == 2) flag = 0;
      if(flag) f[i][j] = 1;
    }
  }    

  int res = 0;
      
  rep(i,h) {
    rep(j,w) {
      res += f[i][j];
    }
  }

  cout << res << "\n";
  
  
  return 0;
}
