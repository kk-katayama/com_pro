#include <iostream>
#include <algorithm>
#include <vector>
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

int main()
{
  vector<vector<mint>> dp(50,vector<mint>(50));
  rep(i,50) dp[1][i].x = 1;
  for(int i=2;i<50;++i){
    for(int j=i;j<50;++j){
      rep1(k,j-i+1){
	dp[i][j] += dp[i-1][j-k];
      }
    }
  }

  int n,x,y,z;
  cin >> n >> x >> y >> z;

  vector<mint> f(50);
  f[3].x = 1;
  for(int i=4;i<=n;++i){
    f[i] = (mint)(20)*f[i-1] + dp[i-2][x] + dp[i-2][y] + dp[i-2][z];
    cout << f[i].x << "\n";
  }

  cout << f[n].x << "\n";
  return 0;
}
