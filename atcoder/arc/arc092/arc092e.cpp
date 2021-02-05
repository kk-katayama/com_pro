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
  vl a(n);
  rep(i,n) cin >> a[i];
  vl sumeven(n+1, 0);
  vl sumodd(n+1, 0);

  rep(i,n) {
    if(i&1) {
      sumodd[i+1] = sumodd[i] + a[i];
      sumeven[i+1] = sumeven[i];
    }
    else {
      sumeven[i+1] = sumeven[i] + a[i];
      sumodd[i+1] = sumodd[i];
    }
  }

  int left,right;
  ll mx = -inf;
  rep(l, n) {
    for (int r = l+1; r < n+1; r++) {
      if(l%2 == 0) {
        if(r%2 == 1) {
          if(chmax(mx, sumeven[r] - sumeven[l])) {
            left = l; right = r;
          }
        }
      }
      if(l%2 == 1) {
        if(r%2 == 0) {
          if(chmax(mx, sumodd[r] - sumodd[l])) {
            left = l; right = r;
          }
        }
      }
    }
  }

  cout << mx << "\n";
//  cout << left << ":" << right << "\n";
  vi res;
  for (int i = n; i > right; i--) {
    res.push_back(i);
  }
  rep(i,left) res.push_back(1);
  rep(i,(right-left)/2) res.push_back(2);
  cout << sz(res) << "\n";
  for (auto &&tmp : res)
  {
    cout << tmp << "\n";
  }
  

  return 0;
}
