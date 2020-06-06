#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
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
mint dp[10010][100][2];
int main()
{
  string k;
  int d;
  cin >> k >> d;
  
  dp[0][0][0].x = 1;

  int n = k.size();
  
  rep(i,n) rep(j,d) rep(f,2){
    int x = k[i] - '0';
    int lim = (f ? 10 : x+1);　
    rep(dj, lim){
      int nj = (j + dj) % d;
      int nf = f || dj < x;
      dp[i+1][nj][nf] += dp[i][j][f];
    }
  }

  mint res = dp[n][0][0] + dp[n][0][1] - 1;

  cout << res.x << "\n";
  
  return 0;
}
