#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> m(n);
  rep(i,n) cin >> m[i];
  vector<int> sum(1<<n,0);
  const int inf = 1e+9;
  vector<int> dp(1<<n,inf);
  dp[0] = 0;
  rep(S,1<<n){
    rep(i,n){
      if(!((S>>i)&1)){
	dp[S|(1<<i)] = min(dp[S|(1<<i)],dp[S]+max(0,m[i]-sum[S]%1000));
	if(sum[S|(1<<i)]==0) sum[S|(1<<i)] = sum[S]+m[i];
      }
    }
  }
  cout << dp[(1<<n)-1] << "\n";
  
  return 0;
}
