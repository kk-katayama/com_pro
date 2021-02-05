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
  int n,m,Y,Z; cin >> n >> m >> Y >> Z;
  map<char,int> id;
  vi point(m);
  rep(i,m) {
    char c; int p;
    cin >> c >> p;
    id[c] = i;
    point[i] = p;
  }
  string s; cin >> s;
  vi v(n);
  rep(i,n) {
    v[i] = id[s[i]];
  }

  vvi dp1(m+1, vi((1<<m), -inf/2));
  dp1[m][0] = 0;
  rep(i,n) {
    vvi dp2 = dp1;
    int col = v[i];
    rep(S,(1<<m)) {
      chmax(dp2[col][S|(1<<col)], dp1[col][S] + Y + point[col]);
      rep(j,m+1) {
        if(j == col) continue;
        chmax(dp2[col][S|(1<<col)], dp1[j][S] + point[col]);
      }
    }
    swap(dp1, dp2);
  }
  int res = -inf;
  rep(i,m+1) {
    rep(S,(1<<m)) {
      if(S == (1<<m)-1) dp1[i][S] += Z;
      chmax(res, dp1[i][S]);
    }
  }
  cout << res << "\n";

  return 0;
}
