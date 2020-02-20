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
  int n;
  cin >> n;
  vector<ll> t(n),a(n);
  rep(i,n) cin >> t[i];
  rep(i,n) cin >> a[i];

  vector<ll> ax(n,0),in(n,1e+9+10);
  ll tax=0,tin=1e+9+10;
  rep(i,n){
    if(tax<t[i]){
      ax[i] = in[i] = t[i];
      tax = t[i];
    }
    else if(tax==t[i]){
      ax[i] = tax;in[i] = 1;
    }
  }

  ll aax = 0;
  for(int i=n-1;i>=0;--i){
    if(aax<a[i]){
      if(a[i]<in[i]||ax[i]<a[i]){
	cout << 0 << "\n";
	return 0;
      }
      else{
	ax[i] = in[i] = a[i];
	aax = a[i];
      }
    }
    else if(aax==a[i]){
      in[i] = max(in[i],1LL);
      ax[i] = min(ax[i],a[i]);
    }
  }

  mint res(1);
  rep(i,n){
    if(in[i]>ax[i]){
      cout << 0 << "\n";
      return 0;
    }
    else{
      res *= (mint)(ax[i]-in[i]+1);
    }
  }

  cout << res.x << "\n";
  
  return 0;
}
