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
  int m = 1;
  rep(i,n-1) {
    m *= 2;
  }  
  vi a(2*m);
  rep(i,2*m) {
    cin >> a[i];
  }


  // cout << m << "\n";
  int mx1 = 0, id1;
  rep(i,m) {
    if(chmax(mx1, a[i])) id1 = i;
  }
  int mx2 = 0, id2;
  rep(i,m) {
    if(chmax(mx2, a[m+i])) id2 = m+i;
  }

  if(a[id1] < a[id2]) cout << id1+1 << "\n";
  else cout << id2+1 << "\n";
  
  return 0;
}
