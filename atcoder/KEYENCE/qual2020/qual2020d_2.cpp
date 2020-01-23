#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  
  const int inf = 1e+9;

  vector<vector<int>> dp((1<<n),vector<int>(51,inf));
  dp[0][1] = 0;
  
  rep(S,(1<<n)){
    int cnt = __builtin_popcount(S);
    rep1(i,50){
      if(dp[S][i]==inf){
	continue;
      }
      int cnt2=0;
      rep(j,n){
	if((S>>j)&1){
	  cnt2++;
	}
	else{
	  if(cnt%2==j%2){
	    if(i<=a[j]){
	      dp[S|(1<<j)][a[j]] = min(dp[S|(1<<j)][a[j]],dp[S][i]+(cnt-cnt2));
	    }
	  }
	  else{
	    if(i<=b[j]){
	      dp[S|(1<<j)][b[j]] = min(dp[S|(1<<j)][b[j]],dp[S][i]+(cnt-cnt2));
	    }
	  }	  
	}
      }
    }
  }

  int res = inf;
  rep1(i,50){
    res = min(res,dp[(1<<n)-1][i]);
  }
  if(res==inf) cout << -1 << "\n";
  else cout << res << "\n";
  
  return 0;
}
