#include <iostream>
#include <algorithm>
#include <vector>
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

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

// status of node
template <typename X>
struct Node{ 
  int idx;
  vector<Edge<X>> edge;
  int col;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; 

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
      add_edge(from[i], to[i]);
      add_edge(to[i], from[i]);      
    }
  }  

  // edges have weight
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void Build(vector<int> c) {
    rep(i,n) node[i].col = c[i];
  }

  void solve(int q, vector<int> s, vector<int> x, vector<int> y) {
    rep(i,q) {
      cout << node[x[i]].col << "\n";
      if(s[i] == 1) {
	for(auto next: node[x[i]].edge) {
	  int w = next.to;
	  node[w].col = node[x[i]].col;
	}
      }
      else {
	node[x[i]].col = y[i];
      }
    }
  }
  
};


int main()
{
  int n,m,q; cin >> n >> m >> q;
  vector<int> u(m), v(m);
  rep(i,m) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
  }
  vector<int> c(n);
  rep(i,n) cin >> c[i];
  vector<int> s(q), x(q), y(q);
  rep(i,q) {
    cin >> s[i];
    if(s[i] == 1) {
      cin >> x[i]; x[i]--;
    }
    else {
      cin >> x[i] >> y[i];
      x[i]--; 
    }
  }

  Graph<int> gp(n, m, u, v);
  gp.Build(c);
  gp.solve(q, s, x, y);
  return 0;
}
