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
template <typename X>
class DST
{
private:
  int n;
  vector<X> dat,delay;
  const X init = 0;

  void eval(int k,int l,int r)
  {
    if(delay[k] != 0){
      dat[k] += delay[k];
      //      dat[k] = delay[k];      
      if(k < n-1){
	delay[2*k+1] += delay[k]/2;
	delay[2*k+2] += delay[k]/2;
	// delay[2*k+1] = delay[k]; // change update
	// delay[2*k+2] = delay[k];	
      }
      delay[k] = 0;
    }
  }
  

  
public:  
  DST(int _n)
  {
    n = 1;
    while(n < _n) n *= 2;
    dat.assign(2*n-1,init);
    delay.assign(2*n-1,init);
  }

  void update(int a,int b,X x,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return ;
    
    if(a<=l&&r<=b){
      delay[k] += (r-l)*x;
      //      delay[k] = x; // change update
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      dat[k] = dat[2*k+1] + dat[2*k+2];
      // dat[k] = dat[2*k+1]; //change update
      // dat[k] = dat[2*k+2];      
    }
  }

  X query(int a,int b,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return 0;

    if(a<=l&&r<=b) return dat[k];    
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return vl + vr;
    }
  }

  int size(){
    return n;
  }

  int get_dat(int x){
    return dat[n-1+x];
  }    
  
  void all_eval(){
    rep(i,2*n-1){
      eval(i,0,0);
    }
  }
  
  void show(){
    int index = 0;
    int num = 1;
    while(index<n){
      rep(i,num){
	cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
    index = 0;
    num = 1;
    while(index<n){
      rep(i,num){
	cout << delay[i+index] << " ";
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

  //-------------------------------------------
  // 辺に対するオイラーツアー.
  // de[v] := vに降りていく辺のインデックス
  // ue[v] := vから昇る辺のインデックス
  //------------------------------------------
  vector<int> de, ue;  
  void EulerTour(int root) {
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

    dfs(dfs, root, -1);
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

  Tree<int> tr(n, a, b);
  tr.EulerTour(0);
  DST<int> dst(2*n);
  
  int q; cin >> q;
  while(q-- > 0) {
    int t; cin >> t;
    if(t == 0) {
      
    }
  }
  
  return 0;
}
