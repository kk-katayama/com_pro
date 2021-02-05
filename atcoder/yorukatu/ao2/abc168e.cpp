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
// ユークリッドの互除法で最大公約数を求める
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}
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
  vl a(n),b(n);
  rep(i,n) {
    scanf("%lld %lld", &a[i], &b[i]);
    //    cin >> a[i] >> b[i];
  }

  map<pair<int,pl>, ll> mp;
  mint cnt;
  rep(i,n) {
    if(a[i] == 0 && b[i] == 0) {
      cnt += (mint)1;
      continue;
    }
    if(a[i] == 0 && b[i] != 0) {
      mp[{0, {0, 1}}]++;
    }
    if(a[i] != 0 && b[i] == 0) {
      mp[{0, {1, 0}}]++;
    }

    if(a[i] == 0 || b[i] == 0) continue;
    if((a[i] < 0 && b[i] < 0) || (a[i] > 0 && b[i] > 0)) {
      ll g = gcd(a[i], b[i]);
      mp[{1, {a[i]/g, b[i]/g}}]++;
    }
    else {
      ll g = gcd(abs(a[i]), abs(b[i]));
      mp[{-1, {abs(a[i])/g, abs(b[i])/g}}]++;
    }
  }

  mint res(1);
  for(auto val: mp) {
    auto [pil, cnt] = val;
    if(cnt == 0) continue;
    auto [c, p] = pil;
    auto [aa, bb] = p;
    if(aa == 0) {
      res *= mint(2).pow(cnt) + mint(2).pow(mp[{0,{1, 0}}]) - (mint)1;
      mp[{0,{1,0}}] = 0;
    }
    else if(bb == 0) {
      res *= mint(2).pow(cnt) + mint(2).pow(mp[{0,{0, 1}}]) - (mint)1;
      mp[{0,{0,1}}] = 0;      
    }
    else {
      res *= mint(2).pow(cnt) + mint(2).pow(mp[{-c,{bb, aa}}]) - (mint)1;
      mp[{-c, {bb, aa}}] = 0;
    }
  }
  res += cnt - (mint)1;
  cout << res.x << "\n";
  return 0;
}
