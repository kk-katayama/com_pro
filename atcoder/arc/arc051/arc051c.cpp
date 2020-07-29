#include <iostream>
#include <algorithm>
#include <vector>
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


int main()
{
  int n; cin >> n;
  ll A,B; cin >> A >> B;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  if(A == 1) {
    rep(i,n) {
      cout << a[i] % MOD << "\n";
    }
    return 0;
  }
  while(B > 0 && a[0] * A < a[n-1]) {
    a[0] *= A;
    B--;
    sort(a.begin(), a.end());
  }

  if(B == 0) {
    rep(i,n) {
      cout << a[i] % MOD << "\n";
    }
    return 0;
  }
  
  vector<mint> res(n);
  rep(i,n) {
    res[i] = (mint)a[i];
  }
  rep(i,n) {
    mint tmp(A);
    res[i] *= tmp.pow(B/n);
  }
  rep(i,B%n) {
    res[i] *= (mint)A;
  }
  for (ll i = B%n; i < B%n + n; ++i) {
    cout << res[i % n].x << "\n";
  }

  return 0;
}
