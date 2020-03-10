#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,p; cin >> n >> p;
  string s;cin >> s;
  if(p==2||p==5){
    vector<vector<ll>> dp(n+1,vector<ll>(p,0));
    ll res = 0;
    rep(i,n){
      int c = s[i] - '0';
      dp[i+1][c%p]++;
      rep(j,p){
	if(j==0) res += dp[i][j];
	dp[i+1][(j*10+c)%p] += dp[i][j];
      }
    }
    cout << res+dp[n][0] << "\n";
  }
  else{
    ll x = 1;
    map<ll,ll> mp;
    ll sum = 0;
    mp[0]++;
    for(int i=n-1;i>=0;i--){
      ll c = s[i] - '0';
      sum = (sum+(c*x)%p)%p;
      mp[sum]++;
      x = (x*10)%p;
    }
    ll res = 0;
    for(auto m:mp){
      res += (m.second-1)*m.second/2;
    }
    cout << res << "\n";
  }
  return 0;
}
