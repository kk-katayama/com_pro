#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int q;
  cin >> q;
  vector<int> h(q),n(q);
  vector<vector<int>> p(q);
  rep(i,q){
    cin >> h[i] >> n[i];
    p[i].resize(n[i]);
    rep(j,n[i]) cin >> p[i][j];
  }
  
  const int inf = 1e+7;
  rep(i,q){
    vector<int> dp(n[i]+1,inf);
    dp[0] = 0;
    p[i].push_back(0);
    rep(j,n[i]){
      if(j+2<=n[i]){
	if(p[i][j]-p[i][j+2]==2) dp[j+2] = min(dp[j+2],dp[j]);
      }
      dp[j+1] = min(dp[j+1],dp[j]+1);
    }
    cout << dp[n[i]] << "\n";
    cout << "***********" << "\n";
    rep(j,n[i]+1) cout << dp[j] << "\n";
  }
  
  return 0;
}
