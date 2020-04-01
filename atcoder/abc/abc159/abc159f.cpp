#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=998244353;
struct mint{
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const{
    if(!t) return 1;
    mint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const{
    mint res(*this);
    return res/=a;
  }
};
mint dp[3100][3100];
int main()
{
  int n,s;cin >> n >> s;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  // vector<vector<mint>> dp(n+1,vector<mint>(s+1));
  // dp[0][0].x = 1;

  // mint res;
  // rep(st,n){
  //   rep(i,n+1) rep(j,s+1) dp[i][j].x = 0;
  //   dp[st][0].x = 1;
  //   for( int i = st;i < n;++i){
  //     rep(j,s+1){
  // 	if(j - a[i] >= 0) dp[i+1][j] = dp[i][j - a[i]] + dp[i][j];
  // 	else dp[i+1][j] = dp[i][j];
  //     }
  //   }
  //   for( int i = st;i <= n;++i) res += dp[i][s];
  // }
  // cout << res.x << "\n";


  mint res;
  rep(i,n+1) rep(j,s+1) dp[i][j].x = 0;
  rep(i,n+1){
    rep(j,s+1){
      if(j - a[i] >= 0) dp[i+1][j] = dp[i][j - a[i]] + dp[i][j];
      else dp[i+1][j] = dp[i][j];
    }
    dp[i+1][0] += (mint)1;
    dp[i+1][a[i]] += (mint)1;
  }

  // rep(i,n+1){
  //   rep(j,s+1) cout << dp[i][j].x << " ";
  //   cout  << "\n";
  // }

  rep(i,n+1) res += dp[i][s];
  cout << res.x << "\n";
  return 0;
}
