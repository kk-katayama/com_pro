#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> i1(m),i2(m),s(m);
  rep(i,m) cin >> i1[i] >> i2[i] >> s[i];
  vector<vector<int>> mat(n);
  rep(i,n) mat[i].assign(n,0);
  rep(i,m) mat[i1[i]][i2[i]] = s[i];

  vector<int> dp(1<<n);
  rep(S,1<<n){
    rep(i,n){
      if(!((S>>i)&1)){
	int sum = 0;
	rep(j,n){
	  if((S>>j)&1) sum += mat[i][j];
	}
	dp[S|(1<<i)] = max(dp[S|(1<<i)],dp[S]+sum);
      }
    }
  }
  cout << dp[(1<<n)-1] << "\n";
  return 0;
}
