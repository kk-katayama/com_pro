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
template<ll MOD = 998244353>
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

using mint4 = mint<998244353>;

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

const int NMAX=100010; // we can calculate nCk until n is equal to NMAX
mint4 fact[NMAX],infac[NMAX];
void Make_Fact(){
  fact[0]=fact[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    fact[i]=fact[i-1]*(mint4)i;
  }
}
void Make_InvFact(){
  infac[0]=infac[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    infac[i]=infac[i-1]/(mint4)i;	
  }
}
mint4 Comb(int n,int k){
  if(n<0||k<0||n-k<0) return 0;
  return fact[n]*infac[k]*infac[n-k];
}

int main()
{
  int n; cin >> n;
  map<int,int> mp;
  rep(i,2*n) {
    int h; scanf("%d", &h);
    mp[h]++;
  }
  vi cnt;
  for(auto val: mp) {
    cnt.push_back(val.second);
  }

  Make_Fact();
  Make_InvFact();
  vector<mint4> fac2(2*n);
  fac2[1].x = 1;
  for (int i = 3; i < 2*n; i += 2) {
    fac2[i] = fac2[i-2]*(mint4)i;
  }
  
  vll a((int)cnt.size());
  priority_queue<pi> q;
  rep(i,(int)cnt.size()) {
    q.push({-cnt[i], i});
    a[i].push_back(1);    
    for(int j = 2; j <= cnt[i]; j += 2) {
      mint4 tmp = Comb(cnt[i], j) * fac2[j-1];      
      a[i].push_back(tmp.x);
    }
  }


  while( q.size() >= 2 ) {
    auto [siz1, id1] = q.top(); q.pop();
    auto [siz2, id2] = q.top(); q.pop();
    vector<ll> b = convolve(a[id1], a[id2], 998244353);
    q.push({-(int)b.size(), (int)a.size()});
    a.push_back(b);
  }

  int m = a.size();
  
  mint4 res(0);
  rep(i,(int)a[m-1].size()) {
    if(i % 2 == 0) {
      res += (mint4)a[m-1][i] * fac2[max(1, 2*n - (2*i + 1))];
    }
    else {
      res -= (mint4)a[m-1][i] * fac2[max(1, 2*n - (2*i + 1))];
    }
  }
  cout << res.x << "\n";
  
  return 0;
}
