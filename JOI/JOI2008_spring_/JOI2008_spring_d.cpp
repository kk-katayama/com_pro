#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
// MLE のため
int dp[370][3010][3];
int main()
{
  int n,d;cin >> n >> d;
  vector<vector<int>> a(d, vector<int>(n));
  rep(i,d) rep(j,n) cin >> a[i][j];

  rep(i,d+1) rep(j,n) rep(k,3) dp[i][j][k] = 1e+9;

  vector<vector<int>> mini(2, vector<int>(4, 1e+9));
  vector<vector<int>> index(2, vector<int>(4, -1));
  rep(i,4) mini[0][i] = 0;
  
  rep1(i,d) {
    rep(j,n) {
      // k = 0
      rep(l,4) {
	if(index[0][l] != j) {
	  chmin(dp[i][j][0], mini[0][l] + a[i-1][j]);
	  // update mini and index
	  rep(m,4) {
	    if(dp[i][j][0] < mini[1][m]) {
	      int tmp1 = dp[i][j][0];
	      int tmp2;
	      int tmpin1 = j;
	      int tmpin2;
	      for(int p = m; p < 4; ++p) {
		tmp2 = mini[1][p];
		mini[1][p] = tmp1;
		tmp1 = tmp2;
		tmpin2 = index[1][p];
		index[1][p] = tmpin1;
		tmpin1 = tmpin2;
	      }
	      break;
	    }
	  }
	  break;
	}
      }
      // k = 1
      if(i <= 1) continue;
      chmin(dp[i][j][1], dp[i-1][j][0] + a[i-1][j] / 10 * 9);
      // update mini and index
      rep(m,4) {
	if(dp[i][j][1] < mini[1][m]) {
	  int tmp1 = dp[i][j][1];
	  int tmp2;
	  int tmpin1 = j;
	  int tmpin2;
	  for(int p = m; p < 4; ++p) {
	    tmp2 = mini[1][p];
	    mini[1][p] = tmp1;
	    tmp1 = tmp2;
	    tmpin2 = index[1][p];
	    index[1][p] = tmpin1;
	    tmpin1 = tmpin2;
	  }
	  break;
	}
      }
      // k = 2
      if(i <= 2) continue;
      chmin(dp[i][j][2], dp[i-1][j][1] + a[i-1][j] / 10 * 7);
      chmin(dp[i][j][2], dp[i-1][j][2] + a[i-1][j] / 10 * 7);      
      // update mini and index
      rep(m,4) {
	if(dp[i][j][2] < mini[1][m]) {
	  int tmp1 = dp[i][j][2];
	  int tmp2;
	  int tmpin1 = j;
	  int tmpin2;
	  for(int p = m; p < 4; ++p) {
	    tmp2 = mini[1][p];
	    mini[1][p] = tmp1;
	    tmp1 = tmp2;
	    tmpin2 = index[1][p];
	    index[1][p] = tmpin1;
	    tmpin1 = tmpin2;
	  }
	  break;
	}
      }
    }
    rep(l,4) {
      mini[0][l] = mini[1][l];
      mini[1][l] = 1e+9;
      index[0][l] = index[1][l];
      index[1][l] = -1;
    }
  }

  int res = 1e+9;
  rep(j,n) {
    rep(k,3) {
      chmin(res, dp[d][j][k]);
    }
  }
  cout << res << "\n";
  return 0;
}

