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
// 一次元座圧.
// 同じ値は同じ値に圧縮される
template <typename T>
class Compress{
public:
  vector<T> a; // 元の配列
  vector<int> data; // 座圧後の配列
  map<T, int> mp; // key->元の配列の値, val->座圧後の値
  int mx;
  
  void add(T val) {
    a.emplace_back(val);
  }

  void build() {
    vector<T> vals = a;
    
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    mx = sz(vals);
    
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
    dat.resize(size*2-1,identity);
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


int main()
{
  ll M = 100010 + 64;
  ll n,m; cin >> n >> m;
  vl w(n);
  rep(i,n) cin >> w[i];
  vl l(m),v(m);
  ll mn = infll;
  rep(i,m) {
    cin >> l[i] >> v[i];
    chmin(mn, v[i]);
  }

  rep(i,n) {
    if(mn < w[i]) {
      cout << -1 << "\n";
      return 0;
    }
  }
  Compress<ll> cp;

  rep(i,m) {
    cp.add(v[i]);
  }
  cp.add(infll);
  cp.add(-1);
  // rep(i,n) {
  //   rep(j,n) {
  //     if(i >= j) continue;
  //     cp.add(w[i] + w[j]);
  //   }
  // }

  cp.build();
  
  auto f = [&](ll a,ll b){ return max(a, b);}; // 二項演算:和
  ll id = 0; //単位元:0
  SegTree<decltype(f),ll> seg(f,id);
  seg.init(cp.mx);
  rep(i,m) {
    int id = cp.data[i];
    ll x = max(l[i], seg.query(id, id+1));
    seg.update(id, x);
  }

  vector<int> vec(n);
  rep(i,n) vec[i] = i;
  ll res = infll;
  // vectorの全並び替えを全探索
  do{
    vl ww(n);
    rep(i,n) ww[i] = w[vec[i]];
    vl sum(n+1, 0);
    rep(i,n) sum[i+1] = sum[i] + ww[i];
    vvl dp(n, vl(n, 0));
    rep1(wid, n) {
      rep(l,n) {
	int r = l + wid;
	if(r >= n) break;
	ll mx = 0;
	for(int k = l+1; k <= r-1; ++k) {
	  chmax(mx, dp[l][k] + dp[k][r]);
	}
	ll wei = sum[r+1] - sum[l];
	int id = cp.a2data(wei);
	ll mxl = seg.query(0, id);
	chmax(mx, mxl);
	dp[l][r] = mx;
      }
    }
    chmin(res, dp[0][n-1]);
    
  } while(next_permutation(vec.begin(), vec.end()));
  cout << res << "\n";
  
  return 0;
}
