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
//*******************************************************
// Tree
//*******************************************************

// status of edge
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

//status of node
template <typename X>
struct Node{
  int idx;
  vector<Edge<X>> edge;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
  }
  
};

// tree
template <typename X>
class Tree{
public:
  int n; // number of node
  vector<Node<X>> node;
  vector<int> par; // par[v] := 頂点vの親
  vector<int> depth; // depth[v] := 根から見たときの頂点vの深さ
  vector<X> dist; // dist[v] := 根から頂点vへの距離  
  vector<int> size; // size[v] := 頂点vを根とする部分木の大きさ

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
    par.resize(n);
    depth.resize(n);
    dist.resize(n);    
    size.resize(n);    
  }
  
  Tree() = default;

  explicit Tree(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Tree(int n, vector<int> a, vector<int> b) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
  }

  Tree(int n, vector<int> a, vector<int> b, vector<X> c) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);  // indirected edge
    }
  }  

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  int DFS_Init(int v, int p, int dep, int dis) {
    par[v] = p;
    depth[v] = dep;
    dist[v] = dis;
    int siz = 1;
    for(auto next: node[v].edge) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      siz += DFS_Init(w, v, dep + 1, dis + cost);
    }
    return size[v] = siz;
  }

  vector<int> de, ue;
  void EulerTour() {
    de.resize(n);
    ue.resize(n);
    int idx = 0;
    auto dfs = [&](auto self, int v, int p) ->void{
      de[v] = idx++;
      for(auto next: node[v].edge) {
	int w = next.to;
	if(w == p) continue;
	self(self, w, v);
      }
      ue[v] = idx++;
    };

    dfs(dfs, 0, -1);
  }
  
  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0, 0);
  }

  X Diameter() {
    int far;
    X mx = -1;
    Make_root(0);
    rep(i,n) {
      if( chmax(mx, dist[i]) ) {
	far = i;
      }
    }
    X res = 0;
    Make_root(far);
    rep(i,n) {
      chmax(res, dist[i]);
    }
    return res;
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
    if(lazy[k] != id2){
      if(k<size-1){
	lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
	lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
      }
      dat[k] = g(dat[k], p(lazy[k], r-l));
      lazy[k] = id2;
    }
  }


  void update(int a,int b,T x,int k,int l,int r){
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

  void update(int a, int b, T x) {
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
  int n; cin >> n;
  vi a(n-1),b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  Tree<int> tr(n, a, b);
  tr.EulerTour();
  tr.Make_root(0);
  // for(auto tmp: tr.de) cout << tmp << " ";
  // for(auto tmp: tr.ue) cout << tmp << " ";
  // cout << "\n";
  auto f = [&](ll a, ll b){ return a + b; };
  auto h = [&](ll a, ll b){ return a + b; };
  auto g = [&](ll a, ll b){ return a + b; };
  auto p = [&](ll a, int b){ return a; };  
  ll id1 = 0;
  ll id2 = 0;
  LST<decltype(f), decltype(h), decltype(g), decltype(p), ll, ll> lst(f, h, g, p, id1, id2);
  lst.init(2*n);
  int q; cin >> q;
  while(q-- > 0) {
    int t,e;
    ll x;
    cin >> t >> e >> x;
    e--;
    int aa = a[e], bb = b[e];
    if(t == 1) {
      if(tr.par[aa] == bb) {
	lst.update(tr.de[aa], tr.ue[aa]+1, x);
      }
      else {
	lst.update(0, 2*n, x);
	lst.update(tr.de[bb], tr.ue[bb]+1, -x);	
      }
    }
    else {
      if(tr.par[bb] == aa) {
	lst.update(tr.de[bb], tr.ue[bb]+1, x);
      }
      else {
	lst.update(0, 2*n, x);
	lst.update(tr.de[aa], tr.ue[aa]+1, -x);	
      }      
    }
  }

  rep(i,n) {
    ll res = lst.query(tr.de[i], tr.de[i]+1);
    cout << res << "\n";
  }
  
  return 0;
}
