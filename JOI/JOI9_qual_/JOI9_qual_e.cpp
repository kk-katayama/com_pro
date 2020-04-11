#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=100000;
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


int main()
{
  int h,w; cin >> h >> w;
  mint dp[110][110][2][2];
  rep(i,h) rep(j,w) rep(k,2) rep(l,2) dp[i][j][k][l].x = 0;
  dp[0][1][1][1].x = 1;
  dp[1][0][0][0].x = 1;  
  rep(i,h) {
    rep(j,w) {
      if(i == 0 && j == 0) continue;
      if(i+1 < h) {
	rep(l,2) dp[i+1][j][0][0] += dp[i][j][0][l];
	dp[i+1][j][0][1] += dp[i][j][1][1];
      }
      if(j+1 < w) {
	rep(l,2) dp[i][j+1][1][1] += dp[i][j][1][l];
	dp[i][j+1][1][0] += dp[i][j][0][0];
      }      
    }
  }

  mint res;
  rep(k,2) rep(l,2) res += dp[h-1][w-1][k][l];
  cout << res.x << "\n";
  return 0;
}
