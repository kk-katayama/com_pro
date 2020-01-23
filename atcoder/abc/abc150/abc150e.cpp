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
const int NMAX=200010;
mint fact[NMAX],infac[NMAX];
void Make_Fact(){
  fact[0]=fact[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    fact[i]=fact[i-1]*(mint)i;
  }
}
void Make_InvFact(){
  infac[0]=infac[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    infac[i]=infac[i-1]/(mint)i;	
  }
}
mint Comb(int n,int k){
  if(n<0||k<0||n-k<0) return 0;
  return fact[n]*infac[k]*infac[n-k];
}

int main()
{
  int n;
  cin >> n;
  vector<ll> c(n);
  rep(i,n){
    cin >> c[i];
  }
  sort(c.begin(), c.end());

  vector<mint> pow2(n+1);
  pow2[0].x = 1;
  rep1(i,n){
    pow2[i] = pow2[i-1]*(mint)2;
  }

  Make_Fact();
  Make_InvFact();
  
  vector<mint> cof(n);
  // rep(i,n){
  //   rep(j,i+1){
  //     cof[i] += (mint)(j+1)*Comb(i,j);
  //   }
  // }
  cof[0].x = 1;
  rep1(i,n-1){
    cof[i] = (mint)(i+2)*pow2[i-1];
  }

  
  // rep(i,n){
  //   cout << cof[i].x << "\n";
  // }


  mint res;
  rep(i,n){
    res += (mint)c[i]*pow2[i]*cof[n-1-i];
  }

  res *= pow2[n];
  
  cout << res.x << "\n";
  
  return 0;
}
