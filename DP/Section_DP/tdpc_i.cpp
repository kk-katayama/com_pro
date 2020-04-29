#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
string s;
vector<vector<int>> dp;
int rec(int l, int r) {
  if(dp[l][r] >= 0) return dp[l][r];
  if(r - l < 3) return dp[l][r] = 0;
  if(s[l] == 'i' && s[r-1] == 'i') {
    for (int i = l+1; i < r-1; ++i) {
      if(s[i] == 'w' && rec(l+1, i) == i - (l+1) && rec(i+1, r-1) == (r-1) - (i+1)) {
	return r - l;
      }
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
  cin >> s;
  int n = s.size();

  dp.resize(n+1, vector<int>(n+1, -1));

  cout << rec(0, n) / 3 << "\n";
  
  return 0;
}
