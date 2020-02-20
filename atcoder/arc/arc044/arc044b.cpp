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
mint pow2[110000];
ll num[110000];
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  if(a[0]!=0){
    cout << 0 << "\n";
    return 0;
  }

  pow2[0].x = 1;
  rep1(i,100000){
    pow2[i] = pow2[i-1]*(mint)2;
  }

  rep(i,n) num[i] = 0;
  int ax=0;
  rep(i,n) {
    num[a[i]]++;
    ax = max(ax,a[i]);
  }
  
  //  rep(i,n) cout << i << ":" << num[i] << "\n";

  if(num[0]!=1){
    cout << 0 << "\n";
    return 0;
  }

  mint two(2);
  mint res(1);
  rep1(i,ax){
    res *= (mint)(pow2[num[i-1]]-(mint)1).pow(num[i])*two.pow(num[i]*(num[i]-1)/2);
  }

  cout << res.x << "\n";
  return 0;
}
