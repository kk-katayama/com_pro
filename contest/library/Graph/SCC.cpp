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
  vector<Edge<X>> edge, rev;
  
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
      add_rev(to[i], from[i]);      
    }
  }  

  // edges have weight
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      //      add_edge(to[i], from[i], cost[i]);
      add_rev(to[i], from[i], cost[i]);            
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void add_rev(int from, int to, X cost = 1) {
    node[from].rev.emplace_back(from, to, cost);
  }
  
  vi cmp; // 属する強連結成分のトポロジカル順序 cmp[v] = x なら頂点v はx 番目
  void scc() {
    vector<bool> used(n, false);
    vi vs; // 帰りがけ順の並び
    auto dfs = [&](auto self, int v) ->void{
		 used[v] = true;
		 for(auto next: node[v].edge) {
		   int w = next.to;
		   if( !used[w] ) self(self, w);
		 }
		 vs.push_back(v);
	       };

    rep(v, n) {
      if( !used[v] ) dfs(dfs, v);
    }
    
    used.assign(n, false);
    cmp.resize(n);
    auto rdfs = [&](auto self, int v, int k) ->void{
		 used[v] = true;
		 cmp[v] = k;
		 for(auto next: node[v].rev) {
		   int w = next.to;
		   if( !used[w] ) self(self, w, k);
		 }
		};    

    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
      if( !used[vs[i]] ) rdfs(rdfs, vs[i], j++);
    }
    
    // sccを使って何かしたいならここに書いたらいいよ
  }
  
};