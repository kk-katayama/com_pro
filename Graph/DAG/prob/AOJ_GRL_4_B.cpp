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

// status of node
template <typename X>
struct Node{ 
  int idx;
  int in;
  int depth;
  
  Node() = default;

  Node(int idx, int in, int depth) : idx(idx), in(in), depth(depth) {}

  void Show() {
    cout << idx  << ":" << in << ":" << depth << "\n";
  }
  
};

// status of edge
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<vector<Edge<X>>> edge; // edge
  vector<Node<X>> node; 
  vector<Node<X>> tsort;
  
public:
  explicit Graph(int n) : n(n) {
    edge.resize(n);
  }

  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    edge.resize(n);
    rep(i,m) {
      add_edge(from[i], to[i]);
      //      add_edge(to[i], from[i]);      
    }
  }
  
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    edge.resize(n);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      //      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    edge[from].emplace_back(from, to, cost);
  }

  void Init_node() {
    rep(i,n) {
      node.emplace_back(i, 0, 0);
    }
  }

  void Tsort() {
    Init_node();

    rep(i,n) for(auto next: edge[i]) node[next.to].in++;

    queue<Node<X>> q;
    rep(i,n) if(node[i].in == 0) {
      q.emplace(i, 0, 0);
    }

    while( !q.empty() ) {
      Node<X> now = q.front(); q.pop();
      int v = now.idx;
      int depth = now.depth;
      tsort.push_back(node[v]);
      for(auto next: edge[v]) {
	int w = next.to;
	node[w].in--;
	node[w].depth = depth + 1;
	if(node[w].in == 0) {
	  q.emplace(w, 0, depth + 1);
	}
      }
    }
  }

  void Show() {
    // rep(i,n) {
    //   tsort[i].Show();
    // }
    rep(i,n) cout << tsort[i].idx << "\n";
  }
  
};

int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
  }

  Graph<int> gp(n, m, a, b);
  gp.Tsort();
  gp.Show();
  
  return 0;
}
