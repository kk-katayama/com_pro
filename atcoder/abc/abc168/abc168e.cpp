#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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

ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}

mint pow2[200010];

int main()
{
  int n; cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  pow2[0].x = 1;
  rep(i,200000) {
    pow2[i+1] = pow2[i]*(mint)2;
  }
  
  using pll = pair<ll,ll>;
  map<pll,ll> mp;
  vector<pll> vec(n);
  mint cnt0;
  rep(i,n) {
    if(a[i] == 0 && b[i] == 0) {
      cnt0 += (mint)1;
      continue;
    }    
    ll g = gcd(abs(a[i]), abs(b[i]));
    ll aa = abs(a[i])/g, bb = abs(b[i])/g;
    if((a[i] < 0 && b[i] > 0) || (a[i] > 0 && b[i] < 0) ) {
      vec[i] = {bb, aa};
      mp[{-aa, bb}]++;
    }

    else {
      mp[{aa, bb}]++;      
    }
  }

  mint res(1);
  for(auto m: mp) {
    mint tmp;
    ll aa = m.first.first, bb = m.first.second;
    ll val = m.second;
    if(aa > 0) { // (1,0) もいける
      tmp = pow2[val] + pow2[mp[{-bb, aa}]] - (mint)1;
      mp[{aa, bb}] = 0;
      mp[{-bb, aa}] = 0;
    }
    else if(aa == 0) { // (0,1)
      tmp = pow2[val] + pow2[mp[{bb, aa}]] - (mint)1;
      mp[{aa, bb}] = 0;
      mp[{bb, aa}] = 0;      
    }
    else {
      tmp = pow2[val] + pow2[mp[{bb, -aa}]] - (mint)1;
      mp[{aa, bb}] = 0;
      mp[{bb, -aa}] = 0;            
    }
    res *= tmp;
  }

  res += cnt0 - (mint)1;
  
  cout << res.x << "\n";
  return 0;
}
