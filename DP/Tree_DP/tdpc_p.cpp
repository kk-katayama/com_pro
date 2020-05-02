#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template <typename X>
struct Node{
  int idx;
  
  Node() = default;

  Node(int idx) : idx(idx) {}
};
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};
template <typename X>
class Tree{
private:
  int n; // number of node
  vector<vector<Edge<X>>> edge; 

  vector<vector<int>> parent; // parent[i][j] := node followed parent at 2^j times from node[i]
  vector<vector<X>> depth; // depth[i][j] := depth of the node[j] when root is node[i]
  const int MAXLOGN = 20;
  
public:
  Tree() = default;

  Tree(int n) : n(n) {
    edge.resize(n);
  }

  Tree(int n, vector<int> a, vector<int> b) : n(n) {
    edge.resize(n);
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
  }

  Tree(int n, vector<int> a, vector<int> b, vector<X> c) : n(n) {
    edge.resize(n);
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);  // indirected edge
    }
  }  

  void add_edge(int from, int to, X cost = 1) {
    edge[from].emplace_back(from, to, cost);
  }

  void DFS(int v, int p, X d, int root) {
    parent[v][0] = p;
    depth[root][v] = d;
    for(auto next: edge[v]) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      DFS(w, v, d + cost, root);
    }
  }

  void Init(int root) {
    parent.resize(n, vector<int>(MAXLOGN));
    depth.resize(n);
    depth[root].resize(n);
    DFS(root, -1, 0, root);
  }
  
};

int main()
{

  return 0;
}
