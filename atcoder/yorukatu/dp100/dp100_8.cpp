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
  string s; cin >> s;
  int n = s.size();
  
  vii dp(n+1, vi(2, 0));
  dp[0][1] = 1;
  rep(i,n) {
    if(s[i-1] != s[i]) {
      chmax(dp[i+1][0], dp[i][0]+1);
    }
    if(i+2 <= n) {
      chmax(dp[i+2][1], dp[i][0]+1);
    }
    chmax(dp[i+1][0], dp[i][1]+1);
  }
  cout << max(dp[n][0], dp[n][1]) << "\n";
  
  return 0;
}
