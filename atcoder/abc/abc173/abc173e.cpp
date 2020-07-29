#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
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
  int n,k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end(), [](ll x, ll y) {
			     return abs(x) > abs(y);
			   });

  int cnt = 0;
  mint sum(1);
  int emin = -1, omin = -1, emax = -1, omax = -1;
  rep(i,k) {
    sum *= (mint)abs(a[i]);
    if(a[i] > 0) {
      emin = i;
    }
    else if(a[i] < 0) {
      omin = i;
      cnt++;
    }
  }

  if(cnt % 2 == 0) {
    cout << sum.x << "\n";
    return 0;
  }
  
  for (int i = k; i < n; ++i) {
    if(a[i] > 0 && emax == -1) emax = i;
    else if(a[i] < 0 && omax == -1) omax = i;
  }
  bool fx = ((emin == -1) || (omax == -1));
  bool fy = ((omin == -1) || (emax == -1));
  if(fx && fy) {
    mint tmp(1);
    rep(i,k) {
      tmp *= (mint)abs(a[n - 1 - i]);
    }
    mint res;
    res -= tmp;
    cout << res.x << "\n";
  }
  else if(fx) {
    sum /= (mint)abs(a[omin]);
    sum *= (mint)abs(a[emax]);
    cout << sum.x << "\n";
  }
  else if(fy) {
    sum /= (mint)abs(a[emin]);
    sum *= (mint)abs(a[omax]);
    cout << sum.x << "\n";
  }
  else {
    if(a[omin] * a[omax] < a[emin] * a[emax]) {
      sum /= (mint)abs(a[omin]);
      sum *= (mint)abs(a[emax]);
    }
    else {
      sum /= (mint)abs(a[emin]);
      sum *= (mint)abs(a[omax]);
    }
    cout << sum.x << "\n";
  }

  return 0;
}
