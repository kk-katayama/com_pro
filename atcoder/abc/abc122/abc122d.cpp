#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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


int main()
{
  int n; cin >> n;
  mint dp[110][4][4][4];

  rep(i,n+1) rep(j,4) rep(k,4) rep(l,4) dp[i][j][k][l].x = 0;
  dp[0][3][3][3].x = 1;

  // dp[i][j][k][l]
  rep(i,n) rep(j,4) rep(k,4) rep(l,4) rep(m,4) {
    if(m == 2) {
      if((k == 0 && l == 1) || (k == 1 && l == 0) || (j == 0 && k == 1) || (j == 0 && l == 1)) continue;
    }
    else if(m == 1) {
      if(k == 0 && l == 2) continue;
    }
    dp[i+1][k][l][m] += dp[i][j][k][l];
  }

  mint res;
  rep(j,4) rep(k,4) rep(l,4) res += dp[n][j][k][l];
  cout << res.x << "\n";
  
  return 0;
}
