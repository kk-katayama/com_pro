#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
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

  bool operator != (const Edge& r) const {
    return !(*this == r);
  }

  bool operator < (const Edge& r) const {
    return to < r.to;
  }

  bool operator > (const Edge& r) const {
    return to > r.to;
  }
  
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

  void Solve() {
    rep(v,n) {
      sort(node[v].edge.begin(), node[v].edge.end());
    }
    ll res = 0;
    ll sum = 0;
    for (int v = n - 1; v >= 0; --v) {
      bool f = true;
      ll tmp = sum + 1;
      for(auto next: node[v].edge) {
	int w = next.to;
	if(w > v) {
	  if(f) {
	    tmp += w - v - 1;
	    f = false;
	  }
	  else {
	    tmp -= n - w;
	  }
	}
      }
      if(f) tmp += n - v - 1;
      sum = tmp;
      res += tmp;
    }
    cout << res << "\n";
  }

  
};

int main()
{
  int n; cin >> n;
  vector<int> u(n-1), v(n-1);
  rep(i,n-1) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
  }
  Tree<int> tr(n, u, v);
  tr.Solve();
  
  return 0;
}
