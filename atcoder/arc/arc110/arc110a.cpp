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
using mint = modint<998244353>;

// 拡張ユークリッドの互除法
// ap + bq = gcd(a, b) となる (p, q) を求める.
// 返り値はgcd(a, b)
ll ExtGcd(ll a, ll b, ll &p, ll &q) {
  if (b == 0) {
    p = 1; q = 0;
    return a;
  }
  ll d = ExtGcd(b, a%b, q, p);
  q -= a/b * p;
  return d;
}

// modが合成数の場合のmodの逆元
// modが合成数のときはFermatの小定理を用いた逆元計算ができない
// aの法modにおける逆元は、aとmodが互いに素であれば
// 拡張ユークリッドの互除法を用いることで行うことができる
ll ModInv(ll a, ll mod) {
  ll x,y;
  ll d = ExtGcd(a, mod, x, y);
  if(d != 1) {
    return -1;
  }
  x = ( (x%mod) + mod ) % mod;
  return x;
}

// Garnerのアルゴリズム
ll Garner(vector<ll> r, vector<ll> m, ll mod) {
  r.push_back(0);
  m.push_back(mod);
  int n = r.size();
  vector<ll> mprod(n, 1); // mprodにはm[i]の積を入れていく
  vector<ll> x(n, 0); // xは答え
  rep(i,n-1) {
    ll t = ((r[i] - x[i]) * ModInv(mprod[i], m[i])) % m[i];
    if(t < 0) t += m[i];
    for (int j = i + 1; j < n; j++) {
      (x[j] += mprod[j] * t) %= m[j];
      (mprod[j] *= m[i]) %= m[j];
    }
  }
  return x[n-1];
}

// 数論変換(NTT)
// 特殊なmod上で行う高速フーリエ変換
template<typename T>
vector<T> ntt(vector<T> a,bool inverse = false){
  int n = a.size();
  int h = 0;
  for(int i=0;(1<<i)<n;++i) ++h;
  
  rep(i,n){
    int j =0;
    rep(k,h) j |= (i>>k&1) << (h-1-k);
    if(i<j) swap(a[i],a[j]);
  }

  ll mod = T(1).mod;
  
  T g = T(3).pow((mod-1)/n);
  for(int b=1;b<n;b*=2){
    T w(1);
    T base = g.pow(n/(2*b));
    if(inverse) base = base.inv();
    rep(j,b){
      for(int k=0;k<n;k+=b*2){
	T s = a[j+k];
	T t = a[j+k+b]*w;
	a[j+k] = s+t;
	a[j+k+b] = s-t;
      }
      w *= base;
    }
  }
  T ninv = T(n).inv();
  if(inverse) rep(i,n) a[i] *= ninv;;
  
  return a;
}

// NTTを用いた高速畳み込み
// テンプレート引数にはmodをいれる
// modは2^n * m + 1 を満たす整数でなければならない
// ex.) 998244353
template<typename T>
vector<ll> naive_convolve(vector<ll> a,vector<ll> b){
  vector<T> aa,bb;
  rep(i,sz(a)) {
    aa.push_back(T(a[i]));
  }
  rep(i,sz(b)) {
    bb.push_back(T(b[i]));
  }      
  int s = a.size() + b.size() - 1;
  int t = 1;
  while(t<s) t*=2;
  aa.resize(t);
  bb.resize(t);
  vector<T> A = ntt(aa);
  vector<T> B = ntt(bb);
  rep(i,t){
    A[i] *= B[i];
  }
  A = ntt(A,true);
  a.resize(s);
  rep(i,s) a[i] = A[i].x;
  return a;
}

// 任意mod での畳み込み
// NTTは特殊なmod上でしか行えないが、畳み込みはできる、すごい！
// 第三引数にmodをいれてね
vector<ll> convolve(vector<ll> a, vector<ll> b, ll mod) {
  using mint1 = modint<167772161>;
  using mint2 = modint<469762049>;
  using mint3 = modint<1224736769>;
  int n = a.size();
  int m = b.size();
  
  vector<ll> c1 = naive_convolve<mint1>(a, b);
  vector<ll> c2 = naive_convolve<mint2>(a, b);
  vector<ll> c3 = naive_convolve<mint3>(a, b);

  vector<ll> res;
  
  vl vm = {mint1(0).mod, mint2(0).mod, mint3(0).mod};
  rep(i,(int)c1.size()) {
    vl r;
    r.push_back(c1[i]);
    r.push_back(c2[i]);
    r.push_back(c3[i]);
    res.push_back(Garner(r, vm, mod));
  }
  return res;
}

// Garnerをちょっと高速化したバージョン
vector<ll> fast_convolve(vector<ll> a, vector<ll> b, ll mod) {
  using mint1 = modint<167772161>;
  using mint2 = modint<469762049>;
  using mint3 = modint<1224736769>;
  int n = a.size();
  int m = b.size();
  
  vector<ll> c1 = naive_convolve<mint1>(a, b);
  vector<ll> c2 = naive_convolve<mint2>(a, b);
  vector<ll> c3 = naive_convolve<mint3>(a, b);

  vector<ll> res(sz(c1));
  
  ll m1 = mint1(0).mod, m2 = mint2(0).mod, m3 = mint3(0).mod;
  const ll m1_inv_m2 = ModInv(m1, m2);
  const ll m12_inv_m3 = ModInv(m1 * m2, m3);
  const ll m12_mod = m1 * m2 % mod;  
  rep(i,sz(c1)) {
    ll v1 = (c2[i] - c1[i]) *  m1_inv_m2 % m2;
    if (v1 < 0) v1 += m2;
    ll v2 = (c3[i] - (c1[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
    if (v2 < 0) v2 += m3;
    ll constants3 = (c1[i] + m1 * v1 + m12_mod * v2) % mod;
    if (constants3 < 0) constants3 += mod;
    res[i] = constants3;
  }
  return res;
}

// ユークリッドの互除法で最大公約数を求める
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}


int main()
{
  ll n; cin >> n;
  ll g = 1;
  for (ll i = 2; i <= n; ++i) {
    g = lcm(g, i);
  }
  
  cout << g+1 << "\n";

  
  return 0;
}
