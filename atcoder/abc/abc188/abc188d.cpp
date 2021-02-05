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
struct info{
  ll d, cos, id;
};
int main()
{
  int n; cin >> n;
  ll C; cin >> C;
  vl a(n),b(n),c(n);
  rep(i,n) {
    cin >> a[i] >> b[i] >> c[i];
    b[i]++;
  }
  vector<info> p;
  rep(i,n) {
    p.push_back({a[i], c[i], 1});
    p.push_back({b[i], c[i], -1});
  }

  sort(p.begin(), p.end(), [](info x, info y){
    return x.d < y.d;
  });


  ll res = 0;
  ll sum = 0;
  int m = sz(p);
  int id = 0;
  while(id < m) {
    int nd = p[id].d;
    while(id < m && p[id].d == nd) {
      sum += p[id].id*p[id].cos;
      id++;
    }
    if(id < m) {
      res += min(sum, C) * (p[id].d - nd);
    }
  }
  
  cout << res << "\n";
  
  return 0;
}
