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
  vector<int> depth; // depth[v] := 根から見たときの頂点vの深さ
  vector<X> dist; // dist[v] := 根から頂点vへの距離
  vector<int> size; // size[v] := 頂点vを根とする部分木の大きさ
  const int M = 20; // ダブリングの最大深さ. 2^Mまでいける

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
    par.resize(n, vector<int>(M));
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

  int DFS_Init(int v, int p, int dep, X dis) {
    par[v][0] = p;
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

  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0, 0);
  }

  void fill_par() {
    rep(i,M-1){
      rep(j,n){
	if(par[j][i] == -1) par[j][i+1] = -1;
	else par[j][i+1] = par[par[j][i]][i];
      }
    }
  }

  //-------------------------------------------------------
  // u,vの最小共通祖先を求める
  //!!!!先にMake_rootとfill_parをしておくように!!!!!!!!
  //--------------------------------------------------------
  int LCA(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=M-1;i>=0;--i){
      if( ((depth[v]-depth[u])>>i)&1 ){
	v = par[v][i];
      }
    }
    if(u==v){
      return u;
    }

    for(int i=M-1;i>=0;--i){
      if(par[u][i]!=par[v][i]){
	u = par[u][i];
	v = par[v][i];
      }
    }
    return par[u][0];
  }

  int distance(int u,int v){//shortest distance of u and v
    int w = LCA(u,v);
    return dist[u]+dist[v]-dist[w]*2;
  }

  vector<int> get_pass(int u,int v){
    int w = LCA(u,v);
    vector<int> res;
    int x = depth[u]-depth[w];
    int y = depth[v]-depth[w];
    rep(i,x){
      res.push_back(u);
      u = par[u][0];
    }
    res.push_back(w);
    vector<int> rev;
    rep(i,y){
      rev.push_back(v);
      v = par[v][0];
    }
    for(int i=rev.size()-1;i>=0;--i){
      res.push_back(rev[i]);
    }
    return res;
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
  tr.Make_root(0);
  tr.fill_par();
  int q; cin >> q;
  while(q-- > 0) {
    int u,v; cin >> u >> v;
    u--; v--;
    cout << tr.distance(u, v) + 1 << "\n";
  }
  
  return 0;
}
