#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=998244353;
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
  int k,n;
  cin >> k >> n;
  Make_Fact();
  Make_InvFact();
  mint s = Comb(n+k-1,n);
  for(int i=2;i<=2*k;++i){
    int l = i/2;
    if(i-k-1>0){
      l -= (i-k-1);
    }
    //    cout << i << ":" << l << "\n";
    mint tmp;
    for(int m=1;m<=l;++m){
      if(m%2==1){
	tmp += Comb(l,m)*Comb(k+n-2*m-1,n-2*m);
      }
      else{
	tmp -= Comb(l,m)*Comb(k+n-2*m-1,n-2*m);
      }
    }
    cout << (s-tmp).x << "\n";
  }

  return 0;
}
