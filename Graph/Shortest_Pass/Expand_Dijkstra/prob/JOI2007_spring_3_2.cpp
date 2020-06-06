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
struct Edge{ // status of edge
  int from; 
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

template <typename X = int>
struct Node{ // Status of node
  int idx; // index of node
  double x,y;
  X dist[110];
  vector<Edge<X>> edge;
  
  Node() = default;

  Node(int idx, double x, double y) : idx(idx), x(x), y(y){}

};

template <typename X = int>
struct Status{ // entered priority_queue
  int idx;
  X dist;
  int before;
  
  Status() = default;

  Status(int idx, X dist, int before) : idx(idx), dist(dist), before(before) {}

  bool operator == (const Status& r) const {
    return (idx == r.idx && dist == r.dist);
  }

  bool operator != (const Status& r) const {
    return !(*this == r);
  }

  bool operator < (const Status& r) const {
    return dist > r.dist;
  }

  bool operator > (const Status& r) const {
    return dist < r.dist;
  }

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
  vector<Node<X>> node; // node list

  vector<vector<vector<X>>> d; // d[i][j] := shortest distance from node "i" to node "j"
  const X inf = 1e+9; // initial value of d

public:
  explicit Graph(int n) : n(n) {
  }

  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost, vector<double> x, vector<double> y) : n(n), m(m) {
    Init_Node(x, y);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void Init_Node(vector<double> x, vector<double> y) {
    rep(i,n) node.emplace_back(i, x[i], y[i]);
  }
  
  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    rep(i,n) rep(j,n) node[i].dist[j] = inf;
    node[s].dist[0] = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0, 0); // pq have (node, shortest distance from start to the node, vector)
    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int bef = now.before;
      if(node[v].dist[bef] < dis) continue;
      Vect vect(node[bef].x - node[v].x, node[bef].y - node[v].y);
      for(auto next: node[v].edge) {
	int w = next.to;
	X cos = next.cost;
	Vect vect2(node[w].x - node[v].x, node[w].y - node[v].y);
	if(eikaku(vect, vect2)) continue;
	if(chmin(node[w].dist[v], node[v].dist[bef] + cos)) {
	  pq.emplace(w, node[w].dist[v], v);
	}
      }
    }
  }


  X Get_d(int index, int before) {
    return node[index].dist[before];
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

  Graph<int> gp(n, m, a, b, c, x, y);
  gp.dijkstra(0);

  int res = 1e+9;
  rep(i,n) {
    chmin(res, gp.Get_d(1, i));
  }
  if(res == 1e+9) cout << -1 << "\n";
  else cout << res << "\n";

  return 0;
}
