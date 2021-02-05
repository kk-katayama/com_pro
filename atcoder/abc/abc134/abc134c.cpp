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
  vi a(n);
  rep(i,n) cin >> a[i];

  vi lowmx(n),highmx(n);
  rep(i,n) {
    if(i == 0) {
      lowmx[i] = a[i];
    }
    else {
      lowmx[i] = max(a[i], lowmx[i-1]);
    }
  }

  for (int i = n-1; i >= 0; --i) {
    if(i == n-1) {
      highmx[i] = a[i];
    }
    else {
      highmx[i] = max(a[i], highmx[i+1]);
    }
  }

  rep(i,n) {
    if(i == 0) {
      cout << highmx[i+1] << "\n";
    }
    else if(i == n-1) {
      cout << lowmx[i-1] << "\n";
    }
    else {
      cout << max(highmx[i+1], lowmx[i-1]) << "\n";
    }
  }
  
  return 0;
}
