#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
vector<vector<int>> can;
vector<int> sum;
vector<int> c, w;
int rec(int l, int r) {
  if(can[l][r] >= 0) return can[l][r];
  if(r - l < 2) return can[l][r] = 1;
  bool f = false;
  if(rec(l+1, r) == 1 && sum[r] - sum[l+1] <= c[l]) f = true;
  if(rec(l, r-1) == 1 && sum[r-1] - sum[l] <= c[r-1]) f = true;
  if(f) return can[l][r] = 1;
  else return can[l][r] = 0;
}
int main()
{
  int n;cin >> n;
  c.resize(n); w.resize(n);
  rep(i,n) cin >> c[i] >> w[i];

  can.resize(n+1, vector<int>(n+1, -1));
  sum.resize(n+1, 0);
  rep(i,n) sum[i+1] = sum[i] + w[i];
  rec(0, n);

  
  vector<int> dp(n+1, 1e+9);
  dp[0] = 0;
  rep1(i,n) {
    rep(j,i) {
      if(can[j][i] == 1) chmin(dp[i], dp[j] + 1);
    }
  }
  cout << dp[n] << "\n";
  
  return 0;
}
