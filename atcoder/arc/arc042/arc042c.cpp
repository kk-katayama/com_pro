#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,p; cin >> n >> p;
  using pi = pair<int,int>;
  vector<pi> v(n);
  rep(i,n) {
    int a,b; cin >> a >> b;
    v[i] = {a, b};
  }

  sort(v.begin(), v.end(), [](pi x, pi y) {
			     return x.first > y.first;
			   });
  vector<int> sum(n+1);
  sum[0] = 0;
  rep(i,n) {
    int b = v[n - 1 - i].second;
    sum[i+1] = max(sum[i], b);
  }

  int res = 0;
  vector<vector<int>> dp(n+1, vector<int>(p+1, 0));
  rep(i,n) {
    int a = v[i].first, b = v[i].second;
    rep(j,p+1) {
      if(j - a >= 0) dp[i+1][j] = max(dp[i][j], dp[i][j-a] + b);
      else dp[i+1][j] = dp[i][j];
    }
    chmax(res, dp[i+1][p] + sum[n - i - 1]);
  }
  cout << res << "\n";
  
  return 0;
}
