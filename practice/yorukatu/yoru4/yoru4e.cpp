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

const int NMAX=100010;
mint fact[NMAX],infac[NMAX];
void Make_Fact(){
  fact[0].x = fact[1].x = 1;
  for(int i =2; i<=NMAX-1;++i){
    fact[i] = fact[i-1] * (mint)i;
  }
}
void Make_InvFact(){
  infac[0].x=infac[1].x=1;
  for(int i=2;i<=NMAX-1;++i){
    infac[i]=infac[i-1]/(mint)i;
  }
}
mint Comb(int n,int k){
  if(n<0||k<0||n-k<0) return (mint)0;
  return fact[n]*infac[k]*infac[n-k];
}

int main()
{
  ll n,k;cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end());
  Make_Fact();
  Make_InvFact();
  mint res;
  rep(i,n) {
    if(i < k - 1) continue;
    res += (mint)a[i] * Comb(i, k - 1);
  }
  rep(i,n) {
    if(n - i - 1 < k - 1) continue;
    res += (mint)(-a[i]) * Comb(n - i - 1, k - 1);
  }
  cout << res.x << "\n";
  return 0;
}
