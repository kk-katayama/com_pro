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

  // セグ木上の二分探索
  // [a, b) 内の要素でx以上であるもののうち、最も左にあるもののindexを返す
  int find(int a, int b, T x, int k, int l, int r) {
    // この区間に答えはないので-1を返す
    if(dat[k] < x || r <= a || b <= l) return -1;
    // 葉まで行って条件を満たすのでこれを返す
    if(k >= size - 1) return (k - (size - 1));
    int lv = find(a, b, x, 2*k+1, l, (l+r)/2);
    if(lv != -1) return lv;
    return find(a, b, x - dat[2*k+1], 2*k+2, (l+r)/2, r);
  }

  int find(int a, int b, T x) {
    return find(a, b, x, 0, 0, size);
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
  auto f = [&](int a,int b){ return a+b;}; // 二項演算:和
  int id = 0; //単位元:0
  SegTree<decltype(f),int> seg(f,id);
  int M = 1e6+10;
  int n,q; cin >> n >> q;
  seg.init(M);
  rep(i,n) {
    int a; scanf("%d", &a);
    seg.add(a, 1);
  }
  rep(i,q) {
    int b; scanf("%d", &b);
    if(b > 0) seg.add(b, 1);
    else {
      b = -b;
      int ub = seg.find(0, M+1, b);
      // int lb = 0, ub = M+1;
      // while(ub - lb > 1) {
      // 	int mid = (ub + lb) / 2;
      // 	int sum = seg.query(0, mid+1);
      // 	(sum >= b ? ub : lb) = mid;
      // }
      seg.add(ub, -1);
    }
  }
  
  // int lb = 0, ub = M+1;
  // while(ub - lb > 1) {
  //   int mid = (ub + lb) / 2;
  //   int sum = seg.query(0, mid+1);
  //   (sum >= 1 ? ub : lb) = mid;
  // }
  int ub = seg.find(0, M+1, 1);  
  cout << (ub == -1 ? 0 : ub) << "\n";
  
  return 0;
}
