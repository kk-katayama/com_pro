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
    dat.resize(size*2,identity);
  }

  // 配列を渡して0(n)で初期化
  void build(vector<T> vec){
    rep(i,vec.size()) dat[size+i] = vec[i];
    dfs(1);
  }
  
  T dfs(int k){
    if(k>=size) return dat[k];
    else return dat[k] = merge(dfs(2*k),dfs(2*k+1));
  }

  // index kの要素をaに変更
  void update(int k,T a){
    k += size ;
    dat[k] = a;
    while(k > 1){
      k /= 2;
      dat[k] = merge(dat[2*k],dat[2*k+1]);
    }
  }
  
  // index kの要素にaを加算
  void add(int k,T a){
    k += size;
    dat[k] += a;
    while(k > 1){
      k /= 2;
      dat[k] = merge(dat[2*k],dat[2*k+1]);
    }
  }

  // 区間[a,b)に対するクエリに答える。(k,l,r)=(0,0,size)
  T query(int a,int b){
    a += size;
    b += size;
    T res = identity;
    while(a < b) {
      if(a & 1) {
	res = merge(res, dat[a++]);
      }
      if(b & 1) {
	res = merge(res, dat[--b]);
      }
      a /= 2;
      b /= 2;
    }
    return res;
  }

  // セグ木上の二分探索
  // [a, b) 内の要素でx以上であるもののうち、最も左にあるもののindexを返す
  int find(int a, int b, T x, int k, int l, int r) {
    // この区間に答えはないので-1を返す
    if(dat[k] < x || r <= a || b <= l) return -1;
    // 葉まで行って条件を満たすのでこれを返す
    if(k >= size) return (k - size);
    int lv = find(a, b, x, 2*k, l, (l+r)/2);
    if(lv != -1) return lv;
    return find(a, b, x, 2*k+1, (l+r)/2, r);
  }

  int find(int a, int b, T x) {
    return find(a, b, x, 1, 0, size);
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
  auto f = [&](ll a,ll b){ return min(a,b);}; // 二項演算:和
  ll id = 2147483647;
  SegTree<decltype(f),ll> seg(f,id);
  
  int n,q; cin >> n >> q;
  seg.init(n);
  while(q-- > 0) {
    int t,x,y; cin >> t >> x >> y;
    if(t == 0) {
      seg.update(x, y);
    }
    else {
      cout << seg.query(x, y+1) << "\n";
    }
  }
  return 0;
}
