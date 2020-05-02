#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
  int dp[2];
  vector<Edge<X>> edge;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
    rep(i,2) dp[i] = 0;
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

  int DFS(int v, int color) {
    if(node[v].dp[color] > 0) return node[v].dp[color];
    int res;
    if(color == 0) res = 0;
    else res = 1;
    for(auto next: node[v].edge) {
      int w = next.to;
      if(w == node[v].par) continue;
      if(color == 0) {
	res += max(DFS(w, 0), DFS(w, 1));
      }
      else {
	res += DFS(w, 0);
      }
    }
    return node[v].dp[color] = res;
  }
  
};


int main()
{
  int n;cin >> n;
  vector<int> a(n-1), b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Tree<int> tr(n, a, b);
  tr.Init_Node(0);
  cout << max(tr.DFS(0, 0), tr.DFS(0, 1)) << "\n";
  
  return 0;
}
