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

  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0, 0);
  }

  pi Diameter() {
    int far;
    X mx = -1;
    Make_root(0);
    rep(i,n) {
      if( chmax(mx, dist[i]) ) {
	far = i;
      }
    }
    pi ans;
    X res = 0;
    ans.first = far;
    Make_root(far);
    rep(i,n) {
      if(chmax(res, dist[i])) {
	ans.second = i;
      }
    }
    return ans;
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
  pi p = tr.Diameter();
  cout << p.first+1 << " " << p.second+1 << "\n";
  
  return 0;
}
