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
  vector<vector<int>> par; // par[v][i] := 頂点vから2^i回親をたどった頂点
  vector<X> depth; // depth[v] := 根から見たときの頂点vの深さ
  vector<int> size; // size[v] := 頂点vを根とする部分木の大きさ
  const int M = 20;

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
    par.resize(n, vector<int>(M));
    depth.resize(n);
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

  int DFS_Init(int v, int p, int d) {
    par[v][0] = p;
    depth[v] = d;
    int siz = 1;
    for(auto next: node[v].edge) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      siz += DFS_Init(w, v, d + cost);
    }
    return size[v] = siz;
  }

  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0);
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

  void Solve(int q, vi t, vi x, vi y) {
    auto f = [&](int a, int b) { return a+b; };
    int id = 0;
    SegTree<decltype(f),int> seg(f,id);
    seg.init(2*n);
    EulerTour();
    rep(i,q) {
      if(t[i] == 0) {
	seg.update(de[x[i]], y[i]);
	seg.update(ue[x[i]], -y[i]);
      }
      else {
	cout << seg.query(0, de[x[i]]+1, 0, 0, seg.size) << "\n";
      }
    }
  }
  
};

int main()
{
  int n; cin >> n;
  vi a,b;
  rep(i,n) {
    int c; cin >> c;
    rep(j,c) {
      int d; cin >> d;
      a.push_back(i);
      b.push_back(d);
    }
  }

  int q; cin >> q;
  vi t(q),x(q),y(q);
  rep(i,q) {
    cin >> t[i];
    if(t[i] == 0) cin >> x[i] >> y[i];
    else cin >> x[i];
  }

  Tree<int> tr(n, a, b);
  tr.Solve(q, t, x, y);
  
  return 0;
}
