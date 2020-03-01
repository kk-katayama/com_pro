#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m),b(m);
  vector<int> C(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    int S=0;
    rep(j,b[i]){
      int c;cin >> c;c--;
      S |= (1<<c);
    }
    C[i] = S;
  }

  int inf = 1e+9;
  vector<vector<int>> dp(m+1,vector<int>((1<<n),inf));
  dp[0][0] = 0;
  rep(i,m){
    rep(S,(1<<n)){
      dp[i+1][S|C[i]] = min(dp[i+1][S|C[i]],dp[i][S]+a[i]); 
      dp[i+1][S] = min(dp[i+1][S],dp[i][S]);     
    }
  }
  if(dp[m][(1<<n)-1]==inf) cout << -1 << "\n";
  else cout << dp[m][(1<<n)-1] << "\n";
  return 0;
}
