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
template<typename T>
class CumSum2D{
public:
  vector<vector<T>> a;
  vector<vector<T>> sum;
  int n,m;
  CumSum2D() {};

  // vectorを追加
  void add(vector<T> &v) {
    a.push_back(v);
  }

  void build() {
    n = sz(a);
    m = sz(a[0]);
    sum.resize(n+1, vector<T>(m+1, 0));
    rep(i,n) {
      rep(j,m) {
	sum[i+1][j+1] = a[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
      }
    }
  }

  // [(l, d), (r, u)) の範囲の累積和を返す. [l, r), [d, u)
  T range(int l, int r, int d, int u) {
    return sum[r][u] - sum[r][d] - sum[l][u] + sum[l][d];
  }
  
};
int main()
{
  int m,n; cin >> m >> n;
  int a,b; cin >> a >> b;
  CumSum2D<ll> cs;
  rep(i,n) {
    vl v(m);
    rep(j,m) {
      cin >> v[j];
      if(v[j] == -1) v[j] = inf;
    }
    cs.add(v);
  }

  cs.build();
  ll res = inf;
  for(int i = b; i <= n; ++i) {
    for(int j = a; j <= m; ++j) {
      chmin(res, cs.range(i - b, i, j - a, j));
    }
  }
  cout << res << "\n";
  return 0;
}
