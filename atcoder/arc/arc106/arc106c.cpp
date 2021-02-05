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
  int n,m; cin >> n >> m;
  if(n == 1 && m == 0) {
    cout << 1 << " " << 2 << "\n";
  }
  else if(m < 0 || n - 1 <= m) cout << -1 << "\n";
  else {
    cout << 1 << " " << 2*(m+2) << "\n";
    int id = 2;
    rep(i,m+1) {
      cout << id++ << " ";
      cout << id++ << "\n";
    }
    id = 2*(m+2) + 1;
    rep(i,n - (m+2)) {
      cout << id++ << " ";
      cout << id++ << "\n";
    }
  }
  return 0;
}
