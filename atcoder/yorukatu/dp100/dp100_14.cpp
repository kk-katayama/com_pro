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
  string s; cin >> s;

  auto LCS = [](string s, string t) -> int{
	       int ns = s.size(), nt = t.size();
	       vii dp(ns+1, vi(nt+1, 0));
	       rep1(i,ns) {
		 rep1(j,nt) {
		   if(s[i-1] == t[j-1]) dp[i][j] = max({dp[i-1][j-1]+1, dp[i][j-1], dp[i-1][j]});
		   else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		 }
	       }
	       return dp[ns][nt];
	     };

  int res = n;
  rep1(i,n-1) {
    string ss = s.substr(0, i);
    string tt = s.substr(i, n-i);
    int l = LCS(ss, tt);
    chmin(res, n - 2*l);
  }
  cout << res << "\n";

  
  return 0;
}
