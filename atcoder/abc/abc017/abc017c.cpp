#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> l(n),r(n),s(n);
  rep(i,n) cin >> l[i] >> r[i] >> s[i];
  // vector<vector<int>> dp(n+1,vector<int>((1<<m),-1));
  // dp[0][0] = 0;
  // rep(i,n){
  //   int M = 0;
  //   for(int j = l[i];j <= r[i];++j){
  //     M += (1<<(j-1));
  //   }
  //   rep(S,(1<<m)){
  //     if(dp[i][S] == -1) continue;
  //     dp[i+1][S|M] = max(dp[i+1][S|M] , dp[i][S] + s[i]);
  //     dp[i+1][S] = max(dp[i+1][S] , dp[i][S]);      
  //   }
  // }

  // int res = 0;
  // rep(i,(1<<m)-1){
  //   res = max(res,dp[n][i]);
  // }
  // cout << res << "\n";

  vector<pair<pair<int,int>,int>> p;
  int sum = 0;
  rep(i,n){
    sum += s[i];
    l[i]--;
    p.push_back({{l[i],0},s[i]});
    p.push_back({{r[i],1},s[i]});    
  }
  rep(i,m){
    p.push_back({{i,2},0});
  }

  sort(p.begin(), p.end());
  int MIN = 1e+9;
  int x = 0;
  rep(i,p.size()){
    if(p[i].first.second == 0) x += p[i].second; 
    else if(p[i].first.second == 1) x -= p[i].second;
    else MIN = min(MIN,x);
  }

  cout << sum - MIN << "\n";
  
  return 0;
}
