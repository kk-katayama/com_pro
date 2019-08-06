#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
const ll MOD = 1e+9+7;
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

int h,w;
char a[1010][1010];
mint dp[1010][1010];
int main()
{
  cin >> h >> w;
  rep(i,h) rep(j,w) cin >> a[i][j];
  dp[0][0].x = 1;
  rep(i,h){
    rep(j,w){
      if( a[i][j] == '#') continue;
      else{
	if( i > 0 && j > 0) {
	  dp[i][j] = dp[i-1][j] + dp[i][j-1];
	}
	else if( i > 0 ) {
	  dp[i][j] = dp[i-1][j];
	}
	else if( j > 0 ) {
	  dp[i][j] = dp[i][j-1];
	}
      }
    }
  }
  cout << dp[h-1][w-1].x << "\n";
  
  return 0;
}
