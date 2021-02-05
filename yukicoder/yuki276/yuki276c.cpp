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

//----------------------------
// 抽象化セグ木
// 二項演算と単位元を渡して使ってね
///****例****************************
//  auto f = [&](int a,int b){ return a+b;}; // 二項演算:和
//  int id = 0; //単位元:0
//  SegTree<decltype(f),int> seg(f,id);
//************************************
//----------------------------

template <typename F,typename T>
struct SegTree{
  // 二項演算merge,単位元identify
  T identity;
  F merge; 
  int size;
  vector<T> dat;
  
  // 二項演算fと単位元idを渡して宣言する
  SegTree(F f,T id):merge(f),identity(id){}

  // データの要素の数nを渡して初期化、sizeはnより大きい2の冪乗
  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.assign(size*2-1,identity);
  }

  // 配列を渡して0(n)で初期化
  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }
  
  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = merge(dfs(2*k+1),dfs(2*k+2));
  }

  // index kの要素をaに変更
  void update(int k,T a){
    k += size - 1;
    dat[k] = a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }
  
  // index kの要素にaを加算
  void add(int k,T a){
    k += size - 1;
    dat[k] += a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }

  // 区間[a,b)に対するクエリに答える。(k,l,r)=(0,0,size)
  T query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return identity;
    
    if(a<=l&&r<=b) return dat[k]; 
    else return merge(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }

  T query(int a,int b){
    return query(a, b, 0, 0, size);
  }

  // デバッグ用
  void show(){
    int index = 0;
    int num = 1;
    while(index<size){
      rep(i,num){
	if(dat[i+index]==identity) cout << "e ";
	else cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  
  
};

// 一次元座圧.
// 同じ値は同じ値に圧縮される
template <typename T>
class Compress{
public:
  vector<T> a; // 元の配列
  vector<int> data; // 座圧後の配列
  map<T, int> mp; // key->元の配列の値, val->座圧後の値

  void add(T val) {
    a.emplace_back(val);
  }

  void build() {
    vector<T> vals = a;

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    rep(i,sz(a)) {
      int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
      // id + 1にすれば1-indexedになる
      mp[a[i]] = id;
      data.push_back(id);
    }
  }

  int a2data(T val) {
    return mp.lower_bound(val)->second;
  }

  void test() {
    vector<T> v = {3, 3, 1, 6, 1};
    for(auto val: v) add(val);
    build();

    for(auto val: data) cout << val << " ";
    cout << "\n";
    // 1 1 0 2 0

    cout << a2data(2) << "\n";
    // 1
  }

};


int main()
{
  auto f = [&](mint a,mint b){ return a+b;}; // 二項演算:和
  mint id(0); //単位元:0
  SegTree<decltype(f),mint> seg(f,id), seg2(f,id);
  
  int n; cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];
  Compress<ll> cp;
  rep(i,n) {
    cp.add(a[i]);
  }
  cp.build();

  seg.init(n);
  seg2.init(n);
  vector<mint> cntl(n),cntr(n),suml(n),sumr(n);
  rep(i,n) {
    cntl[i] = seg.query(cp.data[i]+1, n);
    seg.add(cp.data[i], mint(1));
    suml[i] = seg2.query(cp.data[i]+1, n);
    seg2.add(cp.data[i], a[i]);
  }

  seg.init(n);
  seg2.init(n);
  for (int i = n-1; i >= 0; --i) {
    cntr[i] = seg.query(0, cp.data[i]);
    seg.add(cp.data[i], mint(1));
    sumr[i] = seg2.query(0, cp.data[i]);
    seg2.add(cp.data[i], a[i]);
  }

  mint res;
  rep(i,n) {
    res += suml[i] * cntr[i];
    res += sumr[i] * cntl[i];
    res += mint(a[i]) * cntr[i] * cntl[i];
  }
  cout << res.x << "\n";
  
  return 0;
}
