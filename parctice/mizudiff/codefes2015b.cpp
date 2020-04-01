#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  string s;cin >> s;
  int res = 1e+9;
  if(n == 1) res = 1;
  rep1(i, n-1) {
    int j = n - i;
    string left = s.substr(0, i);
    string right = s.substr(i, j);
    vector<vector<int>> dp(i+1, vector<int>(j+1, 0));
    rep(x, i) {
      rep(y, j) {
	if(left[x] == right[y]) dp[x+1][y+1] = max(dp[x][y] + 1, max(dp[x][y+1], dp[x+1][y]) );
	else dp[x+1][y+1] = max(dp[x][y+1], dp[x+1][y]);	
      }
    }
    int tmp = i + j - 2*dp[i][j];
    res = min(res, tmp);
  }
  cout << res << "\n";
  return 0;
}
