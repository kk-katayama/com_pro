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
  int n; cin >> n;
  vl a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  vl dp1(2, 0);
  rep(i,n) {
    vl dp2 = dp1;
    chmax(dp2[1], dp1[0] + b[i]);
    chmax(dp2[0], dp1[1] + a[i]);
    swap(dp1, dp2);
  }

  cout << max(dp1[0], dp1[1]) << "\n";
  
  return 0;
}
