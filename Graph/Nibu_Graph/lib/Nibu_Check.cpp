//****************************************
// Graph template
//****************************************

// status of node
template <typename X>
struct Node{ 
  int idx;
  int color;
  
  Node() = default;

  Node(int idx, int color = 0) : idx(idx), color(color) {}
};

// status of edge
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost = 1) : from(from), to(to), cost(cost) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<vector<Edge<X>>> edge; // edge
  vector<Node<X>> node; 

public:
  explicit Graph(int n) : n(n) {
    edge.resize(n);
  }

  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    edge.resize(n);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      add_edge(to[i], from[i], cost[i]);      
    }
  }
  
  void add_edge(int from, int to, X cost) {
    edge[from].emplace_back(from, to, cost);
  }

  void Init_node() {
    // paint all nodes 0
    rep(i,n) {
      node.emplace_back(i, 0);
    }
  }
  
  bool paint_dfs(int v, int c) {
    node[v].color = c; // paint node[v] c
    for(auto next: edge[v]) {
      int w = next.to;
      if(node[w].color == c) return false;
      if(node[w].color == 0 && !dfs(w, -c)) return false;
    }
    return true;
  }

  bool paint() {
    Init_node();
    
    rep(i,n) {
      if(node[i].color == 0) {
	if( !paint_dfs(i, 1) ) return false;
      }
    }
    return true;
  }
  
};
