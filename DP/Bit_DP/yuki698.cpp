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
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> dp(1<<n);
  rep(S,1<<n){
    for(int i=0;i<n;++i){
      for(int j=i+1;j<n;++j){
	if((!(S&(1<<i)))&&(!(S&(1<<j)))){
	  dp[S|(1<<i)|(1<<j)] = max(dp[S|(1<<i)|(1<<j)],dp[S]+(a[i]^a[j]));
	}
      }
    }
  }
  cout << dp[(1<<n)-1] << "\n";
  return 0;
}
