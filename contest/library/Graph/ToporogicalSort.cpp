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
      //      add_edge(to[i], from[i]);      
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

  // トポロジカルソートした頂点の配列を返す
  vector<int> Tsort() {
    // 入次数のカウント
    vector<int> in(n, 0);
    rep(i,n) {
      for(auto next: node[i].edge) {
	int w = next.to;
	in[w]++;
      }
    }

    queue<int> q; // 頂点を入れるキュー
    rep(i,n) {
      if(in[i] == 0) q.push(i);
    }

    vector<int> res;
    
    while( !q.empty() ) {
      int v = q.front(); q.pop();
      res.push_back(v);
      for(auto next: node[v].edge) {
	int w = next.to;
	in[w]--;
	if(in[w] == 0) {
	  q.push(w);
	}
      }
    }
    return res;
  }
  
};
