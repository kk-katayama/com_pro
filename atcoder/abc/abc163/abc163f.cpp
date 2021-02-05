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
  ll n; // number of node
  vector<Node<X>> node;
  vector<int> par; // par[v] := 頂点vの親
  vector<int> depth; // depth[v] := 根から見たときの頂点vの深さ
  vector<X> dist; // dist[v] := 根から頂点vへの距離  
  vector<ll> size; // size[v] := 頂点vを根とする部分木の大きさ

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
  Tree(ll n, vector<int> a, vector<int> b) : n(n) {
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
    ll siz = 1;
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

  void Solve(vi &c) {
    Make_root(0);
    vl d(n, 0);
    vl res(n, n*(n+1)/2);
    auto dfs = [&](auto self, int v, int p)->void {
      ll t = d[c[v]];
      d[c[v]] = 0;
      for(auto tmp:node[v].edge) {
	int w = tmp.to;
	if(w == p) continue;
	self(self, w, v);
	ll x = size[w] - d[c[v]];
	//	if(c[v] == 0) cout << v << ":" << d[c[v]] << "\n";
	res[c[v]] -= x*(x+1)/2;
	d[c[v]] = 0;
      }
      d[c[v]] = t + size[v];
    };
    dfs(dfs, 0, -1);
    rep(i,n) {
      ll x = n - d[i];
      //      cout << i << ":" << d[i] << "\n";
      res[i] -= x*(x+1)/2;
    }
    for(auto tmp:res) cout << tmp << "\n";
  }
  
};

int main()
{
  ll n; cin >> n;
  vi c(n);
  rep(i,n) {
    cin >> c[i];
    c[i]--;
  }
  vi a(n-1),b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  Tree<int> tr(n, a, b);
  tr.Solve(c);
  return 0;
}
