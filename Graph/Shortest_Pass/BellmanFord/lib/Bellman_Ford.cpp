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
  vector<X> d;
  const X inf = 1e+15;
  vector<int> prev;
  
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

  //ベルマンフォード法。頂点sから全頂点への最短距離。負閉路を見つけるとfalseを返す。
  bool bellmanford(int s){
    d.assign(n,inf);
    d[s] = 0;
    prev.assign(n,-1);
    bool flag = true;
    rep(i,n){
      rep(v,n){
	if(d[v]==inf) continue;
	for(auto next: node[v].edge){
	  int w = next.to;
	  X cos = next.cost;
	  if(d[w]>d[v] + cos){
	    d[w] = d[v] + cos;
	    prev[w] = v;
	    if(i==n-1){
	      flag = false;
	    }
	  }
	}
      }
    }
    return flag;
  }
  

  // s->t の最短経路復元
  vector<int> getpath(int t) {
    vector<int> res;
    for(; t != -1; t = prev[t]) {
      res.push_back(t);
    }
    reverse(res.begin(), res.end());
    return res;
  }

  
};


