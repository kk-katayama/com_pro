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
  string s,t; cin >> s >> t;
  int ns = s.size(), nt = t.size();
  vii dp(ns+1, vi(nt+1, 0));
  rep1(i,ns) {
    rep1(j,nt) {
      if(s[i-1] == t[j-1]) {
	dp[i][j] = max({dp[i-1][j-1] + 1, dp[i][j-1], dp[i-1][j]});
      }
      else {
	dp[i][j] = max(dp[i][j-1], dp[i-1][j]);	
      }
    }
  }

  string res = "";
  while(dp[ns][nt] > 0) {
    if(s[ns-1] == t[nt-1]) {
      if(dp[ns-1][nt-1] + 1 == dp[ns][nt]) {
	res.push_back(s[ns-1]);
	ns--; nt--;
	continue;
      }
    }
    if(dp[ns-1][nt] == dp[ns][nt]) {
      ns--;
    }
    else if(dp[ns][nt-1] == dp[ns][nt]) {
      nt--;
    }
  }
  reverse(res.begin(), res.end());
  cout << res << "\n";
  
  return 0;
}
