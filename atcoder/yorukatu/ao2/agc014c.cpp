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
  int h,w,k; cin >> h >> w >> k;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  vvi d(h, vi(w, inf));
  queue<pi> q;
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == 'S') {
	d[i][j] = 0;
	q.push({i, j});
      }
    }
  }


  vi di = {-1, 0, 1, 0};
  vi dj = {0, -1, 0, 1};
  while( !q.empty() ) {
    auto [i, j] = q.front(); q.pop();
    rep(k,4) {
      int ni = i + di[k];
      int nj = j + dj[k];
      if(0 <= ni && ni < h && 0 <= nj && nj < w && s[ni][nj] == '.' && d[ni][nj] == inf) {
	d[ni][nj] = d[i][j] + 1;
	q.push({ni, nj});
      }
    }
  }

  int res = inf;
  rep(i,h) {
    rep(j,w) {
      if(d[i][j] <= k) {
	int mn = min({i, j, h-i-1, w-j-1});
	chmin(res, (mn + k - 1)/k + 1);
      }
    }
  }
  cout << res << "\n";
  return 0;
}
