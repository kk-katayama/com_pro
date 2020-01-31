#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  vector<vector<int>> w(n,vector<int>(n));
  rep(i,n){
    rep(j,n){
      cin >> w[i][j];
    }
  }
  vector<int> sum((1<<n),0);
  rep(S,(1<<n)){
    rep(i,n){
      rep(j,n){
	if(i>=j) continue;
	if(((S>>i)&1)&&((S>>j)&1)){
	  sum[S] += w[i][j];
	}
      }
    }
  }

  vector<int> dp((1<<n),0);
  rep1(S,(1<<n)-1){
    for(int T=S;T>0;T=(T-1)&S){
      dp[S] = max(dp[S],dp[S-T]+k-(sum[S]-sum[S-T]-sum[T]));
    }
  }

  cout << dp[(1<<n)-1] << "\n";
  
  return 0;
}
