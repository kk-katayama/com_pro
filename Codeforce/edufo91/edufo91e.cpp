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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
//*******************************************************
// Tree
//*******************************************************
const int M = 20;
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
  int par[2*M];
  X depth;
  vector<Edge<X>> edge;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
  }
  
};

// tree
template <typename X>
class Tree{
private:
  int n; // number of node
  vector<Node<X>> node;

  void Init_Node() {
    rep(i,n) node.emplace_back(i);    
  }
  
public:
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

  void DFS_Init(int v, int p, int d) {
    node[v].par[0] = p;
    node[v].depth = d;
    for(auto next: node[v].edge) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      DFS_Init(w, v, d + cost);
    }
  }

  void Fill_Table() {
    rep(i,M-1) {
      rep1(j,n-1) {
	if(node[j].par[i] == -1) node[j].par[i+1] = -1;
	else node[j].par[i+1] = node[node[j].par[i]].par[i];
      }
    }
  }
  
  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0);
    Fill_Table();
  }
  
  int LCA(int u, int v) {
    if(node[u].depth > node[v].depth) swap(u, v);
    for (int i = M-1; i >= 0; --i) {
      if( ( (node[v].depth - node[u].depth) >> i) & 1) {
	v = node[v].par[i];
      }
    }
    if(u == v) return u;

    for (int i = M-1; i >= 0; --i) {
      if(node[u].par[i] != node[v].par[i]) {
	u = node[u].par[i];
	v = node[v].par[i];
      }
    }
    return node[u].par[0];
  }

  void Build(int m, vector<int> a, vector<int> b) {
    vector<int> mp(m+1);
    rep1(i,m) mp[i] = i;
    rep(i,m-1) {
      add_edge(mp[a[i]], m + i + 1);
      add_edge(m + i + 1, mp[a[i]]);       
      add_edge(mp[b[i]], m + i + 1);
      add_edge(m + i + 1, mp[b[i]]);      
      mp[a[i]] = m + i + 1;
    }
    Make_root(2*m - 1);
  }
  
};

int main()
{
  int n,m; cin >> n >> m;
  vector<int> t(n);
  rep(i,n) cin >> t[i];
  vector<int> a(m-1), b(m-1);
  rep(i,m-1) {
    cin >> a[i] >> b[i];
  }

  Tree<int> tr(2*m);
  tr.Build(m, a, b);
  vector<int> cnt(m, 0);
  rep(i,n-1) {
    if(t[i] == t[i+1]) cnt[0]++;
    else {
      int lca = tr.LCA(t[i], t[i+1]);
      cnt[lca - m]++;
    }
  }

  int res = n - 1;
  rep(i,m) {
    res -= cnt[i];
    cout << res << "\n";
  }
  
  
  return 0;
}
