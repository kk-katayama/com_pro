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
  int n; cin >> n;
  vi a(n);
  rep(i,n) {
    cin >> a[i];
  }

  vector<mint> ten(51);
  ten[0].x = 1;
  rep(i,50) ten[i+1] = ten[i] * (mint)10;
  
  int sum = 0;
  mint res(1);
  mint tmp(0);
  vector<mint> b;
  int cnt = 0;
  rep(i,n) {
    sum += a[i];
    sum /= 10;
    if(sum >= 1) {
      tmp += (mint)a[i] * ten[cnt];
      cnt++;
    }
    else {
      if(tmp.x == 0) {
	b.push_back((mint)a[i] + 1);
      }
      else {
	tmp += (mint)a[i] * ten[cnt];
	b.push_back(tmp + (mint)1);
	tmp.x = 0;
	cnt = 0;
      }
    }
  }
  if(tmp.x != 0) b.push_back(tmp + (mint)1);
  
  for(auto val: b) {
    res *= val;
  }
  
  res -= (mint)1;  
  cout << res.x << "\n";
  return 0;
}
