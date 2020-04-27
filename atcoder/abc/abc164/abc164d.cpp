#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  string s;cin >> s;
  int n = s.size();
  vector<vector<ll>> dp(2, vector<ll>(2019,0));
  ll res = 0;
  rep(i,n) {
    int x = s[i] - '0';
    rep(j,2019) {
      dp[1][(j*10+x)%2019] += dp[0][j];
    }
    res += dp[1][0];
    dp[1][x]++;
    dp[0] = dp[1];
    dp[1].assign(2019,0);
  }

  cout << res << "\n";

  return 0;
}
