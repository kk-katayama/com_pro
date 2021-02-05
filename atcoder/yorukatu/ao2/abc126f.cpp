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
  int m,k; cin >> m >> k;
  int x = pow(2, m);
  if(k == 0) {
    rep(i,x) {
      cout << i << " " << i << " ";
    }
    cout << "\n";
  }
  else if(m == 1 && k == 1) {
    cout << -1 << "\n";
  }
  else if(k < x) {
    int y = k ^ 1;
    vi a;
    rep(i,x) {
      if(i == 1 || i == y) continue;
      a.push_back(i);
    }
    cout << 1 << " ";
    for(auto val: a) cout << val << " ";
    cout << 1 << " " << y << " ";
    reverse(a.begin(), a.end());
    for(auto val: a) cout << val << " ";
    cout << y << "\n";
  }
  else {
    cout << -1 << "\n";
  }
  return 0;
}
