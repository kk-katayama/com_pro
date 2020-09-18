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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
int MOD = 10000;
int main()
{
  int n,k; cin >> n >> k;
  vi a(k), b(k);
  rep(i,k) {
    cin >> a[i] >> b[i];
  }
  vi x(n+1, 0);
  rep(i,k) x[a[i]] = b[i];
  viii dp(n+1, vii(5, vi(5, 0)));
  dp[0][4][4] = 1;
  rep(i,n) {
    rep1(j,(i <= 1 ? 4 : 3)) {
      rep1(l,(i <= 0 ? 4 : 3)) {
	if(x[i+1] > 0) {
	  if(x[i+1] != j || x[i+1] != l) {
	    dp[i+1][l][x[i+1]] = (dp[i+1][l][x[i+1]] + dp[i][j][l]) % MOD;
	  }
	}
	else {
	  rep1(m,3) {
	    if(j != m || l != m) {
	      dp[i+1][l][m] = (dp[i+1][l][m] + dp[i][j][l]) % MOD;	      
	    }
	  }
	}
      }
    }
  }
  
  int res = 0;
  rep1(j,3) {
    rep1(l,3) {
      res = (res + dp[n][j][l]) % MOD;
    }
  }
  cout << res << "\n";
  
  
  return 0;
}
