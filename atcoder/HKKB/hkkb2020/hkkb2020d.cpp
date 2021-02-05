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
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// Modint
// modint<MOD> で宣言
template<ll MOD>
struct modint{
  ll x;
  ll mod = MOD;
  modint(ll x=0):x(x%MOD){}
  modint& operator+=(const modint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  modint& operator-=(const modint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  modint& operator*=(const modint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  modint operator+(const modint a) const{
    modint res(*this);
    return res+=a;
  }
  modint operator-(const modint a) const{
    modint res(*this);
    return res-=a;
  }
  modint operator*(const modint a) const{
    modint res(*this);
    return res*=a;
  }
  modint pow(ll t) const{
    if(!t) return 1;
    modint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  modint inv() const{
    return pow(MOD-2);
  }
  modint& operator/=(const modint a){
    return (*this) *= a.inv();
  }
  modint operator/(const modint a) const{
    modint res(*this);
    return res/=a;
  }
};
using mint = modint<1000000007>;

int main()
{
  int t; cin >> t;
  mint inv2 = mint(2).inv();
  while(t-- > 0) {
    mint n,a,b; cin >> n.x >> a.x >> b.x;
    if(n.x < a.x + b.x) {
      cout << 0 << "\n";
      continue;
    }
    mint res;
    res += (n - a + (mint)1) * (n - a + (mint)1);
    res *= (n - b + (mint)1) * (n - b + (mint)1);
    res -= (a + b - (mint)1) * (a + b - (mint)1) * (n - a + (mint)1) * (n - a + (mint)1);
    //    cout << ((a + b - (mint)1) * (a + b - (mint)1) * (n - a + (mint)1) * (n - a + (mint)1)).x << "\n";
    mint x = (n - a + (mint)1) * (a + b - (mint)1) * (b * (b - (mint)1) *inv2) * (mint)4;
    res += x;
//    cout << x.x << "\n";
    res -= (b * (b - (mint)1) * inv2) * (b * (b - (mint)1) * inv2) * (mint)4;
    //    cout << ((b * (b - (mint)1) * inv2) * (b * (b - (mint)1) * inv2) * (mint)4).x << "\n";   
    cout << res.x << "\n";
  }
  return 0;
}
