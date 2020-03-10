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
  string s;cin >> s;
  int n = s.size();
  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(20,vector<ll>(2,0)));
  dp[0][0][0] = 1;
  rep(i,n){
    int x = s[i] - '0';
    rep(k,10){
      rep(ff,2){
	if(ff==0) rep(j,x+1) dp[i+1][k+(j==1)][ff||j<x] += dp[i][k][ff];
	else rep(j,10) dp[i+1][k+(j==1)][ff] += dp[i][k][ff];
      }
    }
  }
  ll res = 0;
  rep(i,10) res += (dp[n][i][0]+dp[n][i][1])*(ll)i;
  cout << res << "\n";

  return 0;
}
