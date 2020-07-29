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
  int res;
  
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

  int DFS(int v, int p, int num) {
    int cnt = num;
    int vn = node[v].edge.size();
    if(vn >= 3) num = 1;
    for(auto next: node[v].edge) {
      int w = next.to;
      if(w == p) continue;
      cnt += DFS(w, v, num);
    }
    res += max(0, vn - 1 - cnt);
    return (vn <= 2 ? 0 : 1);
  }
  
  void Solve() {
    int maxi = 0;
    int root;
    rep(i,n) {
      if(chmax(maxi, (int)node[i].edge.size())) root = i;
    }
    if(maxi <= 2) {
      cout << 1 << "\n";
      return ;
    }
    res = 0;
    DFS(root, -1, 0);
    cout << res << "\n";
  }

  
};

int main()
{
  int n; cin >> n;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
  }
  Tree<int> tr(n, a, b);
  tr.Solve();
  
  return 0;
}
