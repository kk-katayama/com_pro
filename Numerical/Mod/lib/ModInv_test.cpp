#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
const ll MOD=36;
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


// 拡張ユークリッドの互除法
// ap + bq = gcd(a, b) となる (p, q) を求める.
// 返り値はgcd(a, b)
ll extgcd(ll a, ll b, ll &p, ll &q) {  
  if (b == 0) {
    p = 1; q = 0;
    return a;
  }  
  ll d = extgcd(b, a%b, q, p);  
  q -= a/b * p;  
  return d;  
}

// modが合成数の場合のmodの逆元
// modが合成数のときはFermatの小定理を用いた逆元計算ができない
// aの法modにおける逆元は、aとmodが互いに素であれば
// 拡張ユークリッドの互除法を用いることで行うことができる
ll ModInv(ll a, ll mod) {
  ll x,y;
  ll d = extgcd(a, mod, x, y);
  if(d != 1) {
    return -1;
  }
  x = ( (x%mod) + mod ) % mod;
  return x;
}

int main()
{
  ll a = ModInv(5, 36);
  cout << a << "\n";
  cout << a*5 % 36 << "\n";
  
  mint b = mint(5).inv();
  cout << b.x << "\n";  
  cout << b.x*5 % 36 << "\n";


  
  return 0;
}
