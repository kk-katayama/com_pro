#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int n;
ll k;
ll a[100010];
ll dp[50][2][2];
vector<ll> b,onecnt;
int main()
{
  cin >> n >> k;
  rep(i,n) cin >> a[i];

  while(k != 0){
    b.push_back(k%2);
    k /= 2;
  }
  
  while(1){
    ll cnt = 0;
    bool f = true;
    rep(i,n){
      if(a[i]!=0) f = false;
      cnt += a[i]%2;
      a[i] /= 2;
    }
    if(f) break;
    onecnt.push_back(cnt);
  }
  
  int bs = b.size(),os = onecnt.size();
  
  if(bs<os) rep(i,os-bs) b.push_back(0);
  else rep(i,bs-os) onecnt.push_back(0);

  reverse(onecnt.begin(),onecnt.end());
  reverse(b.begin(),b.end());

  
  bs = b.size();

  ll bit[50];
  ll x = 1;
  rep(i,bs){
    bit[bs-1-i] = x;
    x *= 2;
  }
  
  rep(i,bs+1) rep(j,2) rep(l,2) dp[i][j][l] = 0;
  dp[0][0][0] = 1;
  
  rep(i,bs) rep(j,2) rep(l,2){
    int bi = *(b.begin()+i);
    ll ol = *(onecnt.begin()+i);
    rep(jj,(l?2:bi+1)){
      if(dp[i][j][l]>0) dp[i+1][jj][l||jj<bi] = max(dp[i+1][jj][l||jj<bi],dp[i][j][l]+bit[i]*(jj?(ll)n-ol:ol));
    }
  }

  ll res = 0;
  rep(j,2) rep(l,2) res = max(res,dp[bs][j][l]);

  cout << res-1 << "\n";
  
  return 0;
}
