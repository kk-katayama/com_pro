#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll w,h;
ll n;
ll x[40],y[40];
ll dp[31][31][31][31];
ll cox[],coy[];


ll dfs(ll i,ll j,ll k,ll l){
  if(k<i||l<j) return 0;
  if(dp[i][j][k][l]>=0) return dp[i][j][k][l];
  ll res = 0;
  rep(a,n){
    ll tmp = 0;
    ll nx = x[a];
    ll ny = y[a];
    if(i<=nx && nx<=k && j<=ny && ny<=l){
      tmp += k-i+l-j+1;
      tmp += dfs(i,j,nx-1,ny-1)+dfs(i,ny+1,nx-1,l)+dfs(nx+1,j,k,ny-1)+dfs(nx+1,ny+1,k,l);
      res = max(res,tmp);
    }
  }
  //  return res;
  return dp[i][j][k][l] = res;
}

int main()
{
  cin >> w >> h;
  if(w>80||h>80) return 0;
  cin >> n;
  rep(i,n){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  
  rep(i,w) rep(j,h) rep(k,w) rep(l,h) dp[i][j][k][l] = -1;
  cout << dfs(0,0,w-1,h-1) << "\n";

  return 0;
}
