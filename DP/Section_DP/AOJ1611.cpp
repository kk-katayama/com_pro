#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
vector<int> a;
vector<vector<int>> dp;
int rec(int l, int r) {
  if(dp[l][r] >= 0) return dp[l][r]; // memo
  if(r - l < 2) return dp[l][r] = 0;
  if(abs(a[l] - a[r-1]) <= 1) { // all clear
    if(rec(l+1, r-1) == (r-1) - (l+1)) {
      return dp[l][r] = r - l; 
    }
  }
  int res = 0;
  for (int i = l+1; i < r; ++i) {
    chmax(res, rec(l, i) + rec(i, r));
  }
  return dp[l][r] = res;
}

int main()
{
  vector<int> res;
  while(1) {
    int n; cin >> n;
    if(n == 0) break;
    a.resize(n);
    rep(i,n) cin >> a[i];
    dp.assign(n+1, vector<int>(n+1, -1));
    res.push_back(rec(0, n));
  }
  rep(i,res.size()) cout << res[i] << "\n";
  return 0;
}
