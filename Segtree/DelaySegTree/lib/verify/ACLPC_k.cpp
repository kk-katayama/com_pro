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


//--------------------------------------
// 抽象化遅延セグ木
// 要素のマージ関数f, 作用素のマージ関数h, 要素に作用素を作用させる関数g, 作用素に区間の長さを作用させる関数p, 要素の初期値id1, 作用素の初期値id2を代入して宣言
//****例******
//  auto f = [&](ll a, ll b){ return min(a, b); };
//  auto h = [&](ll a, ll b){ return b; };
//  auto g = [&](ll a, ll b){ return b; };
//  auto p = [&](ll a, int b){ return a; };  
//  ll id1 = (1LL << 31) - 1;
//  ll id2 = (1LL << 31) - 1;
//  LST<decltype(f), decltype(h), decltype(g), decltype(p), ll, ll> lst(f, h, g, p, id1, id2);
//*********************
//-------------------------------------------------------------------------


template <typename F, typename H, typename G, typename P, typename T, typename E>
struct LST{
  F f; // 要素のマージ関数
  H h; // 作用素のマージ関数
  G g; // 要素に作用素を作用させる関数
  P p; // 作用素と区間の長さの関数
  T id1; // 要素の初期値
  E id2; // 作用素の初期値
  int size;
  vector<T> dat;
  vector<E> lazy;
  
  LST(F f, H h, G g, P p, T id1, E id2)
    :f(f), h(h), g(g), id1(id1), id2(id2), p(p){}

  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1, id1);
    lazy.resize(size*2-1, id2);    
  }

  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }

  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = f(dfs(2*k+1),dfs(2*k+2));
  }

  // 遅延評価
  void eval(int k,int l,int r){
    if(lazy[k].first.x != id2.first.x || lazy[k].second.x != id2.second.x){
      if(k<size-1){
	lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
	lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
      }
      dat[k] = g(dat[k], p(lazy[k], r-l));
      lazy[k] = id2;
    }
  }


  void update(int a,int b,E x,int k,int l,int r){
    eval(k,l,r);
    if(r<=a||b<=l) return ;
    if(a<=l&&r<=b){
      lazy[k] = h(lazy[k], x);
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      dat[k] = f(dat[2*k+1],dat[2*k+2]);
    }
  }

  void update(int a, int b, E x) {
    update(a, b, x, 0, 0, size);
  }
  
  T query(int a,int b,int k,int l,int r){
    eval(k,l,r);
    if(r<=a||b<=l) return id1;

    if(a<=l&&r<=b) return dat[k];
    else return f(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }

  T query(int a, int b) {
    return query(a, b, 0, 0, size);
  }

  void all_eval(){
    rep(i,2*size-1){
      eval(i,0,0);
    }
  }

  T get(int k){ return dat[size-1+k];}
  
  void show(){
    int index = 0;
    int num = 1;
    while(index<size){
      rep(i,num){
	if(dat[i+index]==id1) cout << "e ";
	else cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
    index = 0;
    num = 1;
    while(index<size){
      rep(i,num){
	cout << lazy[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  

  
};

int main()
{
  using pmi = pair<mint,mint>;
  auto f = [&](mint a, mint b){ return a+b; };
  auto h = [&](pmi a, pmi b)-> pmi{
	     return {a.first*b.first, b.first*a.second + b.second};
	   };
  auto g = [&](mint a, pmi b)->mint{
	     return a*b.first + b.second;
	   };
  auto p = [&](pmi a, int b)->pmi{
	     return {a.first, a.second*(mint)b};
	   };  
  mint id1(0);
  pmi id2 = {(mint)1, (mint)0};
  LST<decltype(f), decltype(h), decltype(g), decltype(p), mint, pmi> lst(f, h, g, p, id1, id2);

  int n,q; cin >> n >> q;
  vector<mint> a(n);
  rep(i,n) cin >> a[i].x;
  lst.init(n);
  lst.build(a);

  while(q-- > 0) {
    int t; cin >> t;
    if(t == 0) {
      int l,r; cin >> l >> r;
      mint b,c; cin >> b.x >> c.x;
      lst.update(l, r, {b, c});
    }
    else {
      int l,r; cin >> l >> r;
      cout << lst.query(l, r).x << "\n";
    }
  }
  
  return 0;
}
