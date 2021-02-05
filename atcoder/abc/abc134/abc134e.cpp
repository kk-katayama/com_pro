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

  vi x(n, -1);
  rep(i,n) {
    int lb = -1, ub = n;
    while(ub - lb > 1) {
      int mid = (ub + lb)/2;
      (x[mid] < a[i] ? lb : ub) = mid;
    }
    x[lb] = a[i];
  }

  int res = 0;
  for (int i = n-1; i >= 0; --i) {
    if(x[i] != -1) res++;
    else break;
  }
  cout << res << "\n";

  
  return 0;
}
