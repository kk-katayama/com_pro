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
  int n,m;cin >> n >> m;
  vector<int> f(n);
  rep(i,n) cin >> f[i];
  vector<int> a(m+1,0);
  vector<int> b(n+1);
  rep(i,n) {
    b[i+1] = a[f[i]];
    a[f[i]] = i+1;
  }
  //  rep(i,n+1) cout << i << ":" << b[i] << "\n";
  vector<mint> dp(n+1);
  vector<mint> sum(n+2);
  int left = 0;
  dp[0].x = 1;
  sum[0].x = 0;sum[1].x = 1;
  rep1(i,n){
    left = max( left , b[i] );
    dp[i] = sum[i] - sum[left];
    sum[i+1] = dp[i] + sum[i];
  }

  cout << dp[n].x << "\n";
  
  
  return 0;
}
