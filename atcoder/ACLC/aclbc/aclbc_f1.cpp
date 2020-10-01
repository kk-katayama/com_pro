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
const ll MOD=998244353;
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

const int NMAX=100010; // we can calculate nCk until n is equal to NMAX
mint fact[NMAX],infac[NMAX];
void Make_Fact(){
  fact[0]=fact[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    fact[i]=fact[i-1]*(mint)i;
  }
}
void Make_InvFact(){
  infac[0]=infac[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    infac[i]=infac[i-1]/(mint)i;	
  }
}
mint Comb(int n,int k){
  if(n<0||k<0||n-k<0) return 0;
  return fact[n]*infac[k]*infac[n-k];
}

vector<mint> fft(vector<mint> a,bool inverse = false){
  int n = a.size();
  int h = 0;
  for(int i=0;(1<<i)<n;++i) ++h;

  rep(i,n){
    int j =0;
    rep(k,h) j |= (i>>k&1) << (h-1-k);
    if(i<j) swap(a[i],a[j]);
  }

  mint g = mint(3).pow((MOD-1)/n);
  for(int b=1;b<n;b*=2){
    mint w(1);
    mint base = g.pow(n/(2*b));
    if(inverse) base = base.inv();
    rep(j,b){
      for(int k=0;k<n;k+=b*2){
	mint s = a[j+k];
	mint t = a[j+k+b]*w;
	a[j+k] = s+t;
	a[j+k+b] = s-t;
      }
      w *= base;
    }
  }
  mint ninv = mint(n).inv();
  if(inverse) rep(i,n) a[i] *= ninv;;

  return a;
}

vector<mint> convolve(vector<mint> a,vector<mint> b){
  int s = a.size() + b.size() - 1;
  int t = 1;
  while(t<s) t*=2;
  a.resize(t);
  b.resize(t);
  vector<mint> A = fft(a);
  vector<mint> B = fft(b);
  rep(i,t){
    A[i] *= B[i];
  }
  A = fft(A,true);
  a.resize(s);
  rep(i,s) a[i] = A[i];
  return a;
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
  vector<mint> fac2(2*n);
  fac2[1].x = 1;
  for (int i = 3; i < 2*n; i += 2) {
    fac2[i] = fac2[i-2]*(mint)i;
  }
  
  vector<vector<mint>> a((int)cnt.size());
  priority_queue<pi> q;
  rep(i,(int)cnt.size()) {
    q.push({-cnt[i], i});
    a[i].push_back(mint(1));    
    for(int j = 2; j <= cnt[i]; j += 2) {
      mint tmp = Comb(cnt[i], j) * fac2[j-1];      
      a[i].push_back(tmp);
    }
  }


  while( q.size() >= 2 ) {
    auto [siz1, id1] = q.top(); q.pop();
    auto [siz2, id2] = q.top(); q.pop();
    vector<mint> b = convolve(a[id1], a[id2]);
    q.push({-(int)b.size(), (int)a.size()});
    a.push_back(b);
  }

  int m = a.size();
  
  mint res(0);
  rep(i,(int)a[m-1].size()) {
    if(i % 2 == 0) {
      res += (mint)a[m-1][i] * fac2[max(1, 2*n - (2*i + 1))];
    }
    else {
      res -= (mint)a[m-1][i] * fac2[max(1, 2*n - (2*i + 1))];
    }
  }
  cout << res.x << "\n";
  
  return 0;
}
