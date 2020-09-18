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
  int n; cin >> n;
  vi p(n);
  rep(i,n) cin >> p[i];

  int M = 10000;
  vi dp(M+1, 0);
  dp[0] = 1;
  rep(i,n) {
    vi ndp(M+1, 0);
    rep(j,M+1) {
      if(dp[j] == 1) {
	ndp[j] = 1;
	ndp[j + p[i]] = 1;
      }
    }
    dp = ndp;
  }
  int res = 0;
  rep(i,M+1) res += dp[i];
  cout << res << "\n";
  return 0;
}
