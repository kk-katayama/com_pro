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
  int q; cin >> q;
  while(q-- > 0) {
    int n,k,z;
    scanf("%d%d%d", &n, &k, &z);
    vi a(n);
    rep(i,n) scanf("%d", &a[i]);
    vector<vvi> dp(n, vvi(z+1, vi(2, 0)));
    dp[0][0][0] = a[0];
    rep(j,z+1) {
      rep(i,n) {
	if(i+1 < n) {
	  if(i+1 + 2*j <= k) {
	    chmax(dp[i+1][j][0], dp[i][j][0] + a[i+1]);
	    chmax(dp[i+1][j][0], dp[i][j][1] + a[i+1]);	    
	  }
	}
	if(i-1 >= 0 && j+1 <= z) {
	  if(i-1 + 2*(j+1) <= k) {
	    chmax(dp[i-1][j+1][1], dp[i][j][0] + a[i-1]);
	  }	  
	}
      }
    }
    int res = 0;
    rep(i,n) {
      rep(j,z+1) {
	if(i + 2*j == k) {
	  chmax(res, dp[i][j][0]);
	  chmax(res, dp[i][j][1]);	  
	}
      }
    }
    cout << res << "\n";
  }
  return 0;
}
