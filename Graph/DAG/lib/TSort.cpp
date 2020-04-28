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

  Edge(int from, int to, X cost = 1) : from(from), to(to), cost(cost) {}
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

  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    edge.resize(n);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      //      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost) {
    edge[from].emplace_back(from, to, cost);
  }

  void Init_node() {
    rep(i,n) {
      node.emplace_back(i, 0, 0);
    }
  }

  vector<int> Tsort() {
    Init_node();

    rep(i,n) for(auto next: edge[i]) node[next.to]++;

    queue<Node<X>> q;
    rep(i,n) if(node[i].in == 0) {
      q.emplace(i, 0, 0);
    }

    while( !q.empty() ) {
      Node now = q.front(); q.pop();
      int v = now.idx;
      int depth = now.depth;
      res.push_back(node[v]);
      for(auto next: edge[v]) {
	int w = next.to;
	node[w].in--;
	if(node[w].in == 0) {
	  q.emplace(w, 0, depth + 1);
	}
      }
    }
  }

  void Show() {
    rep(i,n) {
      node[i].Show();
    }
  }
  
};
