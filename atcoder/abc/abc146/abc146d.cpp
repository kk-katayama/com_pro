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
  int idx;
  
  Edge() = default;

  Edge(int from, int to, int idx, X cost) : from(from), to(to), idx(idx), cost(cost) {}
};

//status of node
template <typename X>
struct Node{
  int idx;
  int par;
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
  vector<int> res;
  
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
      add_edge(a[i], b[i], i);
      add_edge(b[i], a[i], i);  // indirected edge
    }
  }

  Tree(int n, vector<int> a, vector<int> b, vector<X> c) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i], i, c[i]);
      add_edge(b[i], a[i], i, c[i]);  // indirected edge
    }
  }  

  void add_edge(int from, int to, int idx, X cost = 1) {
    node[from].edge.emplace_back(from, to, idx, cost);
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

  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0);
  }

  void DFS(int v, int p, int num) {
    int cnt = 1;
    for(auto next: node[v].edge) {
      int w = next.to;
      int id = next.idx;
      if(w == p) continue;
      if(cnt == num) cnt++;
      res[id] = cnt;
      DFS(w, v, cnt);
      cnt++;
    }
  }

  void Solve() {
    res.resize(n-1);
    DFS(0, -1, 0);
    int maxi = 0;
    rep(i,n-1) chmax(maxi, res[i]);
    cout << maxi << "\n";
    rep(i,n-1) {
      cout << res[i] << "\n";
    }
  }
  
};

int main()
{
  int n; cin >> n;
  vector<int> a(n-1), b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  Tree<int> tr(n, a, b);
  tr.Solve();

  
  return 0;
}
