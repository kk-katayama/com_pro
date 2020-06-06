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
  int n,l; cin >> n >> l;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  vector<int> t(3);
  rep(i,3) cin >> t[i];

  vector<bool> line(l+1, false);
  rep(i,n) line[x[i]] = true;

  int inf = 1e+9;
  vector<int> dp(l+1, inf);
  dp[0] = 0;
  rep(i,l) {
    // 1
    chmin(dp[i+1], dp[i] + t[0] + (line[i+1] ? t[2] : 0));
    // 2
    if(i+2 > l) chmin(dp[l], dp[i] + t[0]/2 + t[1]/2);
    else chmin(dp[i+2], dp[i] + t[0] + t[1] + (line[i+2] ? t[2] : 0));
    // 3
    if(i+4 > l) chmin(dp[l], dp[i] + t[0]/2 + t[1]/2*(2*(l-i) - 1));
    else chmin(dp[i+4], dp[i] + t[0] + 3*t[1] + (line[i+4] ? t[2] : 0));
  }
  cout << dp[l] << "\n";
  return 0;
}
