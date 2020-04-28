#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
//***********************************************************
// Dijkstra
//***********************************************************
template <typename X = int>
struct Node{ // Status of node
  int idx; // index of node
  double x,y;
  X dist;
  int before;
  
  Node() = default;

  Node(int idx, X dist, int before) : idx(idx), dist(dist), before(before) {}

  void Set(int idxx, double xx, double yy) {
    idx = idxx;
    x = xx;
    y = yy;
  }

  
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

template <typename X = int>
struct Edge{ // status of edge
  int from; 
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

struct Vect{
  double x,y;

  Vect(double x, double y) : x(x), y(y) {}

  double dot(Vect r) {
    return x*r.x + y*r.y;
  }
};

bool eikaku(Vect a, Vect b) {
  double cos = a.dot(b);
  return cos > 0.;
}

template <typename X = int>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<vector<Edge<X>>> edge; // edge list
  vector<Node<X>> node; // node list

  vector<vector<vector<X>>> d; // d[i][j] := shortest distance from node "i" to node "j"
  const X inf = 1e+9; // initial value of d
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

  void Init_node(vector<double> x, vector<double> y) {
    node.resize(n);
    rep(i,n) {
      node[i].Set(i, x[i], y[i]);
    }    
  }
  
  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    d.resize(n);
    d[s].resize(n, vector<X>(n, inf));
    d[s][s][0] = 0;
    
    priority_queue<Node<X>> pq;
    pq.emplace(s, 0, 0); // pq have (node, shortest distance from start to the node, vector)
    while( !pq.empty() ) {
      Node<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int bef = now.before;
      if(d[s][v][bef] < dis) continue;
      Vect vect(node[bef].x - node[v].x, node[bef].y - node[v].y);
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	Vect vect2(node[w].x - node[v].x, node[w].y - node[v].y);
	if(eikaku(vect, vect2)) continue;
	if(chmin(d[s][w][v], d[s][v][bef] + cos)) {
	  pq.emplace(w, d[s][w][v], v);
	}
      }
    }
  }


  X Get_d(int start, int goal, int index) {
    //    if(d[start][goal] == inf) return -1;
    return d[start][goal][index];
  }
  
};

int main()
{
  int n,m;cin >> n >> m;
  vector<double> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  vector<int> a(m), b(m), c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  Graph<int> gp(n, m, a, b, c);
  gp.Init_node(x, y);
  gp.dijkstra(0);

  int res = 1e+9;
  rep(i,n) {
    chmin(res, gp.Get_d(0, 1, i));
  }
  if(res == 1e+9) cout << -1 << "\n";
  else cout << res << "\n";

  return 0;
}
