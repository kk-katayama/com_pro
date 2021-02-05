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
  auto f = [&](pi a,pi b){ return (a.first < b.first ? a : b);}; 
  pi id = {inf,inf}; //単位元:0
  SegTree<decltype(f),pi> segeven(f,id),segodd(f,id);
  int n; cin >> n;
  segeven.init(n);
  segodd.init(n);
  rep(i,n) {
    int p; cin >> p;
    if(i&1) {
      segodd.update(i, {p, i});
      segeven.update(i, {inf, i});
    }
    else {
      segeven.update(i, {p, i});
      segodd.update(i, {inf, i});        
    }
  }

  using ppiv = pair<pi, vector<pi>>;
  priority_queue<ppiv, vector<ppiv>, greater<ppiv>> pq;
  {
    auto [val1, left] = segeven.query(0, n);
    auto [val2, right] = segodd.query(left+1, n);
    vector<pi> sta;
    if(left != 0) sta.push_back({0, left});
    if(right - left > 1) sta.push_back({left+1, right});
    if(n - right > 1) sta.push_back({right+1, n});
    pq.push({{val1,val2}, sta});
  }
  vi res;
  while( !pq.empty() ) {
    auto [p, vec] = pq.top(); pq.pop();
    res.push_back(p.first);
    res.push_back(p.second);
    for(auto tmp: vec) {
      auto [l, r] = tmp;
      if(l&1) {
        auto [val1, left] = segodd.query(l, r);
        auto [val2, right] = segeven.query(left+1, r);
        vector<pi> sta;
        if(left - l > 1) sta.push_back({l, left});
        if(right - left > 1) sta.push_back({left+1, right});
        if(r - right > 1) sta.push_back({right+1, r});
        pq.push({{val1,val2}, sta});
      }
      else {
        auto [val1, left] = segeven.query(l, r);
        auto [val2, right] = segodd.query(left+1, r);
        vector<pi> sta;
        if(left - l > 1) sta.push_back({l, left});
        if(right - left > 1) sta.push_back({left+1, right});
        if(r - right > 1) sta.push_back({right+1, r});
        pq.push({{val1,val2}, sta});
      }
    }
  }
  for(auto tmp: res) cout << tmp << " ";
  cout << "\n";
  return 0;
}
