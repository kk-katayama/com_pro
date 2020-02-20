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
  int t;
  cin >> t;
  vector<int> a(t);
  rep(i,t){
    cin >> a[i];
  }

  vector<vector<mint>> dp(t+1,vector<mint>(601));
  rep(i,t){
    rep(j,a[i]+1){
      dp[i][j].x = 1;
    }
  }

  rep1(i,t-1){
    rep1(j,601){
      rep(k,a[i]+1){
	if(j%2==0){
	  dp[i][j/2+k] += dp[i-1][j];
	}
      }
    }
  }

  mint res;
  rep(i,t){
    res += dp[i][1];
  }

  int x = 2;
  while(x<=600){
    res += dp[t-1][x];
    x *= 2;
  }

  cout << res.x << "\n";
  
  return 0;
}
