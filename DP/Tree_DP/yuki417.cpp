#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

template <typename X>
struct Node{
  int idx;
  int par;
  X depth;
  vector<Edge<X>> edge;
  ll charge;
  ll dp[2001];
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
  }
  
};

template <typename X>
class Tree{
private:
  int n; // number of node
  vector<Node<X>> node;

public:
  Tree() = default;

  Tree(int n) : n(n) {
    rep(i,n) node.emplace_back(i);
  }

  Tree(int n, vector<int> a, vector<int> b) : n(n) {
    rep(i,n) node.emplace_back(i);
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
  }

  Tree(int n, vector<int> a, vector<int> b, vector<X> c) : n(n) {
    rep(i,n) node.emplace_back(i);
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);  // indirected edge
    }
  }  

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void DFS_Init(int v, int p, int d) {
    node[v].par = p;
    node[v].depth = d;
    for(auto next: node[v].edge) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      DFS_Init(w, v, d + cost);
    }
  }

  void Init_Node(int root) {
    DFS_Init(root, -1, 0);
  }






  ll DFS(int v, int time) {
    if(node[v].dp[time] > 0) return node[v].dp[time];
    
  }
  
};
int main()
{
  
  return 0;
}
