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
  int n,k; cin >> n >> k;
  int r,s,p; cin >> r >> s >> p;
  string t; cin >> t;
  int res = 0;
  rep(i,k) {
    vi dp(3, 0);
    int x = i;
    while(x < n) {
      vi ndp(3, 0);
      if(t[x] == 'r') {
	ndp[0] = max(dp[1], dp[2]);
	ndp[1] = max(dp[0], dp[2]);	
	ndp[2] = max(dp[0], dp[1]) + p;
      }
      if(t[x] == 's') {
	ndp[0] = max(dp[1], dp[2]) + r;
	ndp[1] = max(dp[0], dp[2]);	
	ndp[2] = max(dp[0], dp[1]);
      }
      if(t[x] == 'p') {
	ndp[0] = max(dp[1], dp[2]);
	ndp[1] = max(dp[0], dp[2]) + s;	
	ndp[2] = max(dp[0], dp[1]);
      }
      dp = ndp;
      x += k;
    }
    res += max({dp[0], dp[1], dp[2]});
  }
  cout << res << "\n";
    
  return 0;
}
