#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  vector<bool> f(3,true);
  f[0] = false;
  int n,W;
  cin >> n >> W;
  if(n<=30) f[0] = true;
  vector<ll> v(n),w(n);
  rep(i,n){
    cin >> v[i] >> w[i];
    if(v[i]>1000) f[1] = false;
    if(w[i]>1000) f[2] = false;
  }

  if(f[0]){
    vector<pair<ll,ll>> pa,pb;
    int na = n/2;
    int nb = n - n/2;
    rep(S,(1<<na)){
      ll wa=0,va=0;
      rep(j,na){
	if((S>>j)&1){
	  wa += w[j];
	  va += v[j];
	}
      }
      pa.push_back({wa,va});
    }
    rep(S,(1<<nb)){
      ll wb=0,vb=0;
      rep(j,nb){
	if((S>>j)&1){
	  wb += w[na+j];
	  vb += v[na+j];
	}
      }
      pb.push_back({wb,vb});
    }
    sort(pa.begin(), pa.end());
    // rep(i,pa.size()){
    //   cout << i << ":" << pa[i].first << ":" << pa[i].second << "\n";
    // }
    // rep(i,pb.size()){
    //   cout << i << ":" << pb[i].first << ":" << pb[i].second << "\n";
    // }    
    rep(i,pa.size()-1){
      if(pa[i].second>=pa[i+1].second){
	pa.erase(pa.begin()+(i+1));
	i--;
      }
    }
    ll res=0;
    rep(i,pb.size()){
      ll x = W - pb[i].first;
      if(x<0) continue;
      int lb=-1,ub=pa.size();
      while(ub-lb>1){
	int mid=(lb+ub)/2;
	if(pa[mid].first<=x) lb=mid;
	else ub=mid;
      }
      ll tmp = pb[i].second + pa[lb].second;
      res = max(res,tmp);
    }
    cout << res << "\n";
    // rep(i,pa.size()){
    //   cout << i << ":" << pa[i].first << ":" << pa[i].second << "\n";
    // }
    
  }
  else if(f[1]){
    const ll inf = 1LL<<60;
    vector<vector<ll>> dp(n+1,vector<ll>(n*1000+1,inf));
    dp[0][0] = 0;
    rep1(i,n){
      rep(j,n*1000+1){
	if(j-v[i-1]<0){
	  dp[i][j] = min(dp[i-1][j],(ll)w[i-1]);
	}
	else{
	  dp[i][j] = min(dp[i-1][j],dp[i-1][j-v[i-1]]+(ll)w[i-1]);
	}
      }
    }
    int res = 0;
    rep(i,n*1000+1){
      if(dp[n][i]<=W){
	res = i;
      }
    }
    cout << res << "\n";
  }
  else{
    vector<vector<ll>> dp(n+1,vector<ll>(n*1000+1,0));
    rep1(i,n){
      rep(j,n*1000+1){
	if(j-w[i-1]<0){
	  dp[i][j] = dp[i-1][j];
	}
	else{
	  dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+(ll)v[i-1]);
	}
      }
    }
    int ww = min(W,n*1000);
    cout << dp[n][ww] << "\n";
  }
  return 0;
}
