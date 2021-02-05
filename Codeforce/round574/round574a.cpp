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
  int n,k; cin >> n >> k;
  vi a(k+1, 0);
  rep(i,n) {
    int tmp; cin >> tmp;
    a[tmp]++;
  }
  int m = (n+1) / 2;
  int res = 0;
  rep1(i,k) {
    while(m > 0 && a[i] >= 2) {
      res += 2;
      a[i] -= 2;
      m--;
    }
  }
  if(m==0) {
    cout << res << "\n";
    return 0;
  }
  rep1(i,k) {
    while(m > 0 && a[i] >= 1) {
      res += 1;
      a[i] -= 1;
      m--;
      if(m == 0) break;      
    }
  }
  cout << res << "\n";
  
  return 0;
}
