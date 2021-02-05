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
struct modint{
  ll x;

  modint() : x(0) {}
  modint(ll x):x(x%mod()){}

  static int &mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) {
    mod() = md;
  }
  
  modint& operator+=(const modint a){
    if((x+=a.x)>=mod()) x-=mod();
    return *this;
  }
  modint& operator-=(const modint a){
    if((x += mod()-a.x)>=mod()) x-=mod();
    return *this;
  }
  modint& operator*=(const modint a){
    (x*=a.x)%=mod();
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
    return pow(mod()-2);
  }
  modint& operator/=(const modint a){
    return (*this) *= a.inv();
  }
  modint operator/(const modint a) const{
    modint res(*this);
    return res/=a;
  }
};
//using mint = modint<1000000007>;

int main()
{
  ll n; cin >> n;
  ll m; cin >> m;

  modint::set_mod(m*m);
  modint ten(10);
  ten = ten.pow(n);
  //  cout << ten.x << "\n";
  cout << (ten.x)/m << "\n";

  return 0;
}
