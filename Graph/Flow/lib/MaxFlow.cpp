//****************************************
// MaxFlow
// Graph<X> gp(n);
// gp.add_edge(from, to, capacity);
// max_flow(s, t);
//****************************************

// status of edge
template <typename X>
struct Edge{
  int from, to;
  int rev;  //逆辺
  X cap; // 容量
  
  Edge() = default;

  Edge(int from, int to, int rev, X cap) : from(from), to(to), rev(rev), cap(cap) {}
};

// status of node
template <typename X>
struct Node{ 
  int idx;
  vector<Edge<X>> edge;
  map<int,int> idtable; // map[to] = val: node[idx]からnode[to]に出るedgeのindexを返す
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; 
  X inf = numeric_limits<X>::max();
  
  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }
public:
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // 容量cap の辺を追加
  void add_edge(int from, int to, X cap) { 
    node[from].edge.emplace_back(from, to, node[to].edge.size(), cap);
    node[from].idtable[to] = node[from].edge.size() - 1;
    node[to].edge.emplace_back(to, from, node[from].edge.size() - 1, 0);
    node[to].idtable[from] = node[to].edge.size() - 1;    
  }

  // from->toの辺(Edge<>)を返す
  Edge<X> get_edge(int from, int to) {
    return node[from].edge[node[from].idtable[to]];
  }

  // s->tの最大流
  X max_flow(int s, int t) {
    vi level(n);
    vi iter(n);
    auto bfs = [&]() {
		 level.assign(n, -1);
		 queue<int> q;
		 level[s] = 0;
		 q.push(s);
		 while( !q.empty() ) {
		   int v = q.front(); q.pop();
		   for(auto next: node[v].edge) {
		     if(next.cap > 0 && level[next.to] < 0) {
		       level[next.to] = level[v] + 1;
		       q.push(next.to);
		     }
		   }
		 }
		 
	       };


    auto dfs = [&](auto func, int v, X f) {
		 if(v == t) return f;
		 for(int &i = iter[v]; i < node[v].edge.size(); ++i) {
		   Edge<X> &e = node[v].edge[i];
		   if(e.cap > 0 && level[v] < level[e.to]) {
		     X d = func(func, e.to, min(f, e.cap));
		     if(d > 0) {
		       e.cap -= d;
		       node[e.to].edge[e.rev].cap += d;
		       return d;
		     }
		   }
		 }
		 return 0;
	       };
    
    // main
    X flow = 0;
    for(;;) {
      bfs();
      if(level[t] < 0) return flow;
      iter.assign(n, 0);
      X f;
      while((f = dfs(dfs, s, inf)) > 0) {
	flow += f;
      }
    }
  }

};
