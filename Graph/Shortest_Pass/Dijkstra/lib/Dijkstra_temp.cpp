//***********************************************************
// Dijkstra
//***********************************************************
template <typename X>
struct Node{ // Status of node
  int idx; // index of node
  X dist; // distance from start node
  
  Node() = default;

  Node(int idx, X dist) : idx(idx), dist(dist) {}

  bool operator == (const Node& r) const {
    return (idx == r.idx && dist == r.dist);
  }

  bool operator != (const Node& r) const {
    return !(*this == r);
  }

  bool operator < (const Node& r) const { 
    return dist > r.dist;
  }

  bool operator > (const Node& r) const {
    return dist < r.dist;
  }  
};

template <typename X>
struct Edge{ // status of edge
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
  vector<vector<Edge<X>>> edge; // edge list
  vector<Node<X>> node; // node list

  vector<vector<X>> d; // d[i][j] := shortest distance from node "i" to node "j"
  const X inf = 1e+9; // initial value of d
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

  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    d.resize(n);
    d[s].resize(n, inf);
    d[s][s] = 0;
    
    priority_queue<Node<X>> pq;
    pq.emplace(s, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Node<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      if(d[s][v] < dis) continue; 
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	if(chmin(d[s][w], d[s][v] + cos)) {
	  pq.emplace(w, d[s][w]);
	}
      }
    }
  }


  X Get_d(int start, int goal) {
    if(d[start][goal] == inf) return -1;
    return d[start][goal];
  }
  
};
