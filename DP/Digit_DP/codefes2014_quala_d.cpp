#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll inf = 1e+15;
string a;
int k;
ll dp[20][2500][3];

int main()
{
  cin >> a >> k;

  int as = a.size();

  rep(i,as+1) rep(j,(1<<10)) rep(l,3) dp[i][j][l] = inf;
  dp[0][0][0] = 0;
  
  rep(i,as){
    ll ai = a[i] - '0';
    rep(j,(1<<10)) rep(l,3){

      if(dp[i][j][l]==inf) continue;
      
      int cnt = 0;
      rep(jj,10) cnt += (j>>jj)&1;
      if(cnt>k) continue;
      else if(cnt==k){
	if(l==1){
	  ll x = 0;
	  while(!((j>>x)&1)) x++;
	  dp[i+1][j][l] = min(dp[i+1][j][l],dp[i][j][l]*10+x-ai);
	}
	else if(l==2){
	  ll x = 9;
	  while(!((j>>x)&1)) x--;
	  dp[i+1][j][l] = min(dp[i+1][j][l],dp[i][j][l]*10+ai-x);
	}
	else{
	  if((j>>ai)&1) dp[i+1][j][l] = 0;
	  ll x = ai + 1,y = ai - 1;
	  if(x<=9){
	    while(!((j>>x)&1)) x++;
	    dp[i+1][j][1] = min(dp[i+1][j][1],x-ai);
	  }
	  if(y>=0){
	    while(!((j>>y)&1)) y--;
	    dp[i+1][j][2] = min(dp[i+1][j][2],ai-y);	    
	  }
	}
      }
      else{
	if(l==1){
	  dp[i+1][j|(1<<0)][l] = min(dp[i+1][j|1][l],dp[i][j][l]*10-ai);
	}
	else if(l==2){
	  dp[i+1][j|(1<<9)][l] = min(dp[i+1][j|(1<<9)][l],dp[i][j][l]*10+ai-9);
	}
	else{
	  dp[i+1][j|(1<<ai)][l] = 0;
	  if(ai<9) dp[i+1][j|(1<<(ai+1))][1] = 1;
	  if(i==0&&ai==1) dp[i+1][j][2] = 1;
	  else if(ai>0) dp[i+1][j|(1<<(ai-1))][2] = 1;
	}
      }
    }
  }

  ll res = inf;
  rep(j,(1<<10)) rep(l,3) res = min(res,dp[as][j][l]);

  cout << res << "\n";
  
  return 0;
}
