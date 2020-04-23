#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m), b(m), x(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> x[i];
    a[i]--; b[i]--;
  }

  vector<vector<int>> dp(n, vector<int>(n, -1));
  rep(i,m) {
    dp[a[i]][b[i]] = x[i];
  }

  int res = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j <= i; ++j) {
      if(dp[i][j] >= 0) {
	res++;
	if(i != n - 1) {
	  chmax(dp[i+1][j], dp[i][j] - 1);
	  chmax(dp[i+1][j+1], dp[i][j] - 1);	  
	}
      }
    }
  }

  cout << res << "\n";

  
  return 0;
}
