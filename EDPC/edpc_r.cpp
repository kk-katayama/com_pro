#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e+9+7;
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

int n;
ll k;
mint a[2][60][60];
mint dp[2][60][60];
int main()
{
  cin >> n >> k;
  rep(i,n) rep(j,n) cin >> a[0][i][j].x;

  rep(i,n) rep(j,n){
    a[1][i][j] = 0;
    dp[0][i][j] = ( i==j ? 1 : 0);
    dp[1][i][j] = 0;
  }
  
  
  while(k > 0){
    if(k&1){
      rep(i,n) rep(j,n) rep(l,n) dp[1][i][j] += dp[0][i][l]*a[0][l][j];
      rep(i,n) rep(j,n){
	dp[0][i][j] = dp[1][i][j];
	dp[1][i][j] = 0;
      }
    }
    rep(i,n) rep(j,n) rep(l,n) a[1][i][j] += a[0][i][l]*a[0][l][j];
    rep(i,n) rep(j,n){
      a[0][i][j] = a[1][i][j];
      a[1][i][j] = 0;
    }
    k /= 2;
  }

  mint res = 0;
  rep(i,n) rep(j,n) res += dp[0][i][j];
  cout << res.x << "\n";
  
  return 0;
}
