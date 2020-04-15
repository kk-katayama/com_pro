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

//return x's divisor as vector
vector<ll> divisor(ll x){
  vector<ll> res;
  for(ll i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(x/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}



int main()
{
  ll n,k;cin >> n >> k;
  vector<mint> res(k+1);
  mint ans;
  for(ll i = k; i > 0;--i) {
    mint tmp;
    ll x = k / i;
    mint mx = (mint)x;
    tmp += mx.pow(n);
    res[i] += tmp;
    vector<ll> div = divisor(i);
    rep(j,div.size()) {
      if(div[j] == i) continue;
      res[div[j]] -= res[i];
    }
    // rep(j,p.size() ) {
    //   ll y = i * p[j];
    //   if(y > k) break;
    //   ll z = k / y;
    //   mint mz = (mint)z;
    //   tmp -= mz.pow(n);
    // }
    // res += (mint)i * tmp;
    ans += res[i] * (mint)i;
  }

  // rep1(i,k) {
  //   cout << i << ":" << res[i].x << "\n";
  // }
   cout << ans.x << "\n";
  return 0;
}
