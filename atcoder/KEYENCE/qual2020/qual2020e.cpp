#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
//****************************************
// Graph template
//****************************************

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

// status of node
template <typename X>
struct Node{ 
  int idx;
  vector<Edge<X>> edge;
  int color;
  int d;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; 
  vector<bool> used;
  
  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }
public:
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // edges have no-weight 
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i], i);
      add_edge(to[i], from[i], i);      
    }
  }  

  // edges have weight
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i], i, cost[i]);
      add_edge(to[i], from[i], i, cost[i]);      
    }
  }

  void add_edge(int from, int to, int idx, X cost = 1) {
    node[from].edge.emplace_back(from, to, idx, cost);
  }

  void Build(vector<int> a) {
    rep(i,n) {
      node[i].d = a[i];
      node[i].color = 0;
    }
  }

  void DFS(int v, int c) {
    if(node[v].color != 0) return ;
    node[v].color = c;
    for(auto next: node[v].edge) {
      int w = next.to;
      if(used[next.idx]) DFS(w, -c);
    }
  }
  
  void solve() {
    vector<int> res(m, 1e+9);
    used.assign(m, false);
    rep(v,n) {
      int mini = 1e+9+10;
      int idx;
      for(auto next: node[v].edge) {
	int w = next.to;
	if(chmin(mini, node[w].d)) {
	  idx = next.idx;
	}
      }
      if(node[v].d < mini) {
	cout << -1 << "\n";
	return ;
      }
      res[idx] = node[v].d;
      used[idx] = true;
    }

    rep(i,n) {
      DFS(i, 1);
    }

    rep(i,n) {
      cout << (node[i].color == 1 ? "W" : "B");
    }
    cout << "\n";
    rep(i,m) cout << res[i] << "\n";
  }
  
};


int main()
{
  int n,m; cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> u(m),v(m);
  rep(i,m) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
  }
  
  Graph<int> gp(n, m, u, v);
  gp.Build(a);
  gp.solve();
  
  return 0;
}
