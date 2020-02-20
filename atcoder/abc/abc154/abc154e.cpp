#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  
  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2,vector<ll>(n+1,0)));
  dp[0][0][0] = 1;
  rep(i,n){
    ll y=s[i]-'1';
    rep(f,2){
      rep(g,k+1){
	if(f==0){
	  if(y==-1){
	    dp[i+1][0][g] += dp[i][f][g];
	  }
	  else {
	    dp[i+1][0][g+1] += dp[i][f][g];
	    dp[i+1][1][g+1] += dp[i][f][g]*y;
	    dp[i+1][1][g] += dp[i][f][g];
	  }
	}
	else{
	  dp[i+1][1][g+1] += dp[i][f][g]*9;
	  dp[i+1][1][g] += dp[i][f][g];
	}
      }
    }
  }

  cout << dp[n][0][k]+dp[n][1][k] << "\n";
  
  return 0;
}
