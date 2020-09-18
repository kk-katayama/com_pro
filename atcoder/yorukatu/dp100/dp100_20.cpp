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
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
int main()
{
  int n,t,s; cin >> n >> t >> s;
  vi a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  vii dp(n+1, vi(t+1, 0));
  rep(i,n) {
    rep(j,t+1) {
      if(j + b[i] <= t) {
	if(j < s && s < j + b[i]) {
	  //
	}
	else {
	  chmax(dp[i+1][j+b[i]], dp[i][j] + a[i]);
	}
      }
      chmax(dp[i+1][j], dp[i][j]);
      if(j + 1 <= t) chmax(dp[i][j+1], dp[i][j]);      
    }
  }

  // rep(i,n+1) {
  //   rep(j,t+1) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  
  cout << dp[n][t] << "\n";
  
  return 0;
}
