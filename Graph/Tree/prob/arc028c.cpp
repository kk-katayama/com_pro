#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
  int par;
  X depth;
  int size;
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

  int DFS_Init(int v, int p, int d) {
    node[v].par = p;
    node[v].depth = d;
    int size = 1;
    for(auto next: node[v].edge) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      size += DFS_Init(w, v, d + cost);
    }
    return node[v].size = size;
  }

  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0);
  }

  void solve() {
    Make_root(0);
    rep(v,n) {
      int sum = 0;
      int maxi = 0;
      for(auto next:node[v].edge) {
	int w = next.to;
	if(w == node[v].par) continue;
	chmax(maxi, node[w].size);
	sum += node[w].size;
      }
      chmax(maxi, n - sum - 1);
      cout << maxi << "\n";
    }
  }
  
  void Show() {
    rep(i,n) {
      cout << i << ":" << node[i].size << "\n";
    }
  }
  
};

int main()
{
  int n;cin >> n;
  vector<int> p(n-1);
  rep(i,n-1) cin >> p[i];

  Tree<int> tr(n);
  rep(i,n-1) {
    tr.add_edge(i+1, p[i]);
    tr.add_edge(p[i], i+1);    
  }
  tr.solve();
  
  //  tr.Show();
  return 0;
}
