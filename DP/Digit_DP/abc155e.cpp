#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  string s; cin >> s;
  reverse(s.begin(), s.end());
  s.push_back('0');
  int n = s.size();
  
  int inf = 1e+9;
  int dp[1000010][2];
  rep(i,n+1) rep(j,2) dp[i][j] = inf;
  dp[0][0] = 0;
  
  rep(i,n+1) {
    int x = s[i] - '0';
    rep(j,2) {
      rep(d,10) {
	if(d > x) { // i+1桁目にs[i]より真に大きい数字を選ぶ場合
	  chmin(dp[i+1][0], dp[i][j] + 2*d - x + (j ? -1 : 0) );
	}
	else if(d < x) {
	  chmin(dp[i+1][1], dp[i][j] + 2*d - x + (j ? 9 : 10) );
	}
	else {
	  chmin(dp[i+1][j], dp[i][j] + 2*d - x + (j ? 9 : 0) );
	}
      }
    }
  }

  cout << dp[n][0] << "\n";
  
  
  return 0;
}
