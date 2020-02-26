#include <iostream>
#include <algorithm>
#include <vector>
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

int main()
{
  string s;cin >> s;
  int n=s.size();
  vector<vector<mint>> dp(n+1,vector<mint>(2));
  dp[0][0].x = 1;
  rep(i,n){
    if(s[i]=='0'){
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][1]*(mint)3;
    }
    else{
      dp[i+1][0] += dp[i][0]*(mint)2;
      dp[i+1][1] += dp[i][0]+dp[i][1]*(mint)3;
    }
  }

  mint res = dp[n][0]+dp[n][1];
  cout << res.x << "\n";
  
  return 0;
}
