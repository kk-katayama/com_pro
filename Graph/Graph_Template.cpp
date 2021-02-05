//****************************************
// Graph template
//****************************************

template <typename X>
class Graph{
public:  
// status of edge
  struct Edge{
    int idx;
    int from;
    int to;
    X cost;
    Edge(int idx, int from, int to, X cost) : idx(idx), from(from), to(to), cost(cost) {}
  };

  // status of node
  struct Node{ 
    int idx;
    vector<Edge> edge;
    Node(int idx) : idx(idx) {}
  };
  int n; // number of node
  int m; // number of edge
  vector<Node> node; 

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }

  Graph(int n) : n(n) {
    Init_Node();
  }

  // edges have no-weight 
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(i, from[i], to[i]);
      add_edge(i, to[i], from[i]);      
    }
  }  

  // edges have weight
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(i, from[i], to[i], cost[i]);
      add_edge(i, to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int idx, int from, int to, X cost = 1) {
    node[from].edge.emplace_back(idx, from, to, cost);
  }

};
