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
  ll x,y,z; cin >> x >> y >> z;
  vl a(n);
  rep(i,n) cin >> a[i];

  rep(i,n) {
    a[i] = (a[i] / 1000 + 1) * 1000;
  }
  
  int id = 0;
  while(id < n && z > 0) {
    if(a[id] >= 10000) {
      int c = min(z, a[id] / 10000);
      a[id] -= 10000 * c;
      z -= c;
    }
    id++;
  }

  sort(a.begin(), a.end(), [](ll a, ll b){
    return a > b;
  });

  rep(i,z) {
    a[i] = 0;
  }

  id = 0;
  while(id < n && y > 0) {
    if(a[id] >= 5000) {
      int c = min(y, a[id] / 5000);
      a[id] -= 5000 * c;
      y -= c;
    }
    id++;
  }

  sort(a.begin(), a.end(), [](ll a, ll b){
    return a > b;
  });

  rep(i,y) {
    a[i] = 0;
  }  

  ll sum = 0;
  rep(i,n) {
    sum += a[i];
  }

  if(sum <= x * 1000) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  
  return 0;
}
