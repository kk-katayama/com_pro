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
  int n,l; cin >> n >> l;
  vi a(n);
  rep(i,n) cin >> a[i];

  vector<pi> p(n);
  rep(i,n) {
    p[i] = {a[i], i+1};
  }
  sort(p.begin(), p.end(), [](pi a, pi b){
    return a.first > b.first;
  });

  vi b(n+2, 0);
  int res = 0;
  rep(i,n) {
    auto [num, id] = p[i];
    b[id] = max(b[id-1], b[id+1]) + l - num;
    chmax(res, b[id]);
  }
  cout << res << "\n";
  
  return 0;
}
