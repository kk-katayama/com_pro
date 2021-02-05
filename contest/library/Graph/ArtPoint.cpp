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

  //------------------------------------------
  // 関節点を見つけるアルゴリズム
  // 関節点：取り除くとグラフが非連結になる頂点
  // Articulation Point
  // DFSは頂点0から始めてね
  //------------------------------------------
  vector<int> ArtPoint() {
    vector<int> pre(n, -1), low(n), child(n, 0);
    int cnt = 0;
    vector<int> res;
    auto dfs = [&](auto self, int v, int p) ->int{
		 pre[v] = cnt++;
		 low[v] = pre[v];
		 bool flag = false;
		 for(auto next: node[v].edge) {
		   int w = next.to;
		   if(w == p) continue;
		   if(pre[w] == -1) {
		     low[v] = min(low[v], self(self, w, v));
		     if(pre[v] <= low[w]) flag = true;
		     child[v]++;
		   }
		   else {
		     low[v] = min(low[v], pre[w]);
		   }
		 }
		 if(flag && v != 0) res.push_back(v);
		 return low[v];
	       };
    
    dfs(dfs, 0, -1);
    if(child[0] >= 2) res.push_back(0);
    return res;    
    
  }
  
};