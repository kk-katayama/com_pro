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
  vector<int> d(n);
  rep(i,n) cin >> d[i];
  vector<int> hp(1<<n,100);
  vector<int> dp(1<<n,-1);

  dp[0] = 100;

  rep(S,1<<n){
    if(dp[S]<=0) continue;
    rep(i,n){
      if(!((S>>i)&1)){
	if(d[i]>=0){
	  dp[S|(1<<i)] = max(dp[S|(1<<i)],min(dp[S]+d[i],hp[S]));
	}
	else{
	  dp[S|(1<<i)] = max(dp[S|(1<<i)],dp[S]+d[i]);
	  hp[S|(1<<i)] = hp[S] + 100;
	}
      }
    }
  }
  cout << max(0,dp[(1<<n)-1]) << "\n";
  return 0;
}
