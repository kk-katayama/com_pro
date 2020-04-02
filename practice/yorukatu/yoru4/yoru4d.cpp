#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
const int M = 100010;
mint pow2[M];
void make_pow2() {
  pow2[0].x = 1;
  rep(i,M-1) {
    pow2[i+1] = pow2[i] * (mint)2;
  }
}
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  make_pow2();
  
  if(n % 2 == 0) {
    map<int,int> mp;
    rep(i,n) mp[a[i]]++;
    bool f = true;
    rep(i,n/2) {
      if(mp[ i*2 + 1 ] != 2) f = false;
    }
    if(!f) cout << 0 << "\n";
    else {
      cout << pow2[n/2].x << "\n";
    }
  }
  else {
    map<int,int> mp;
    rep(i,n) mp[a[i]]++;
    bool f = true;
    if(mp[0] != 1) f = false;
    rep1(i,n/2) {
      if(mp[ i*2 ] != 2) f = false;
    }
    if(!f) cout << 0 << "\n";
    else {
      cout << pow2[n/2].x << "\n";
    }
  }  
  return 0;
}
