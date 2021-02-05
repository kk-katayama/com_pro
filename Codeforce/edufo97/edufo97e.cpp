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
  vi a(n+2);
  rep1(i,n) cin >> a[i];
  a[0] = -inf/2;
  a[n+1] = inf/2;
  vi b(k+2);
  rep1(i,k) {
    cin >> b[i];
    b[i];
  }

  b[0] = 0;
  b[k+1] = n+1;
  vi c(n+2);
  rep(i,n+2) {
    c[i] = a[i] - i;
  }
  
  rep(i,k+1) {
    if(c[b[i]] > c[b[i+1]]) {
      cout << -1 << "\n";
      return 0;
    }
  }

  int res = 0;
  // if(k != 0) {
  //   vi v(b[0]+1, inf);
  //   rep(i,b[0]+1) {
  //     if(c[i] > c[b[0]]) continue;
  //     int lb = -1, ub = sz(v);
  //     while(ub - lb > 1) {
  // 	int mid = (ub + lb) / 2;
  // 	(v[mid] > c[i] ? ub : lb) = mid;
  //     }
  //     v[ub] = c[i];
  //   }
  //   int cnt = b[0] + 1;
  //   rep(i,b[0]+1) {
  //     if(v[i] == inf) {
  // 	cnt = i;
  // 	break;
  //     }
  //   }
  //   res += b[0] + 1 - cnt;
  // }

  rep(i,k+1) {
    int m = b[i+1] - b[i] + 1;
    vi v(m, inf);
    for (int j = b[i]; j < b[i]+m; ++j) {
      if(c[j] > c[b[i+1]] || c[j] < c[b[i]]) continue;
      int lb = -1, ub = m;
      while(ub - lb > 1) {
	int mid = (ub + lb) / 2;
	(v[mid] > c[j] ? ub : lb) = mid;
      }
      v[ub] = c[j];
    }
    int cnt = m;
    rep(j,m) {
      //      cout << v[j] << " ";
      if(v[j] == inf) {
	cnt = j;
	break;
      }
    }
    res += m - cnt;
    //    cout << m << ":" << cnt << ":" << m - cnt << "\n";
  }
  
  // if(k != 0) {
  //   int m = n - b[k-1];
  //   vi v(m, inf);
  //   for (int i = b[k-1]; i < n; ++i) {
  //     if(c[i] < c[b[k-1]]) continue;
  //     int lb = -1, ub = sz(v);
  //     while(ub - lb > 1) {
  // 	int mid = (ub + lb) / 2;
  // 	(v[mid] > c[i] ? ub : lb) = mid;
  //     }
  //     v[ub] = c[i];
  //   }
  //   int cnt = m;
  //   rep(i,m) {
  //     if(v[i] == inf) {
  // 	cnt = i;
  // 	break;
  //     }
  //   }
  //   res += m - cnt;
  // }

  cout << res << "\n";
  
  return 0;
}
