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
template<ll MOD = 1000000007>
struct mint{
  ll x;
  ll mod = MOD;
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

template<typename T>
vector<T> fft(vector<T> a,bool inverse = false){
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

template<typename T>
vector<T> convolve(vector<T> a,vector<T> b){
  int s = a.size() + b.size() - 1;
  int t = 1;
  while(t<s) t*=2;
  a.resize(t);
  b.resize(t);
  vector<T> A = fft(a);
  vector<T> B = fft(b);
  rep(i,t){
    A[i] *= B[i];
  }
  A = fft(A,true);
  a.resize(s);
  rep(i,s) a[i] = A[i];
  return a;
}

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

// 任意mod での畳み込み
vector<ll> convolve(vector<ll> a, vector<ll> b, ll mod) {
  using mint1 = mint<167772161>;
  using mint2 = mint<469762049>;
  using mint3 = mint<1224736769>;
  int n = a.size();
  int m = b.size();
  vector<mint1> a1,b1;
  vector<mint2> a2,b2;
  vector<mint3> a3,b3;
  
  rep(i,n) {
    a1.push_back(mint1(a[i]));
    a2.push_back(mint2(a[i]));
    a3.push_back(mint3(a[i]));		 
  }

  rep(i,m) {
    b1.push_back(mint1(b[i]));
    b2.push_back(mint2(b[i]));
    b3.push_back(mint3(b[i]));		 
  }		 
  
  vector<mint1> c1 = convolve<mint1>(a1, b1);
  vector<mint2> c2 = convolve<mint2>(a2, b2);	
  vector<mint3> c3 = convolve<mint3>(a3, b3);

  vector<ll> res;
  
  vl vm = {c1[0].mod, c2[0].mod, c3[0].mod};
  rep(i,(int)c1.size()) {
    vl r;
    r.push_back(c1[i].x);
    r.push_back(c2[i].x);
    r.push_back(c3[i].x);
    res.push_back(Garner(r, vm, mod));
  }
  return res;
}

int main()
{
  int n,m; cin >> n >> m;
  vector<ll> a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  vector<ll> c = convolve(a, b, 998244353);
  for(auto val: c) cout << val << " ";
  cout << "\n";
  return 0;
}
