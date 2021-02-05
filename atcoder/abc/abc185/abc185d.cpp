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
  vi a(m);
  rep(i,m) cin >> a[i];
  sort(a.begin(), a.end());
  vi b;
  int left = 0;
  rep(i,m) {
    int wid = a[i] - left - 1;
    if(wid > 0) b.push_back(wid);
    left = a[i];
  }
  {
    int wid = n - left;
    if(wid > 0) b.push_back(wid);
  }

  if(sz(b) == 0) {
    cout << 0 << "\n";
    return 0;
  }
  sort(b.begin(), b.end());
  int mn = b[0];
  int res = 0;
  for(auto tmp:b) {
    res += (tmp + mn - 1) / mn;
  }
  cout << res << "\n";

  
  return 0;
}
