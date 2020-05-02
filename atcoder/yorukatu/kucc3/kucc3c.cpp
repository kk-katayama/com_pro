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
template <typename X>
struct Node{ // Status of node
  int idx; // index of node
  X dist; // distance from start node
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
  
};

template <typename X>
struct Edge{ // status of edge
  int from; 
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};


template <typename X = int>
struct Status{ // entered priority_queue
  int idx;
  X dist;

  Status() = default;

  Status(int idx, X dist) : idx(idx), dist(dist) {}

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

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<vector<Edge<X>>> edge; // edge list
  vector<Node<X>> node; // node list

  const X inf = 1e+9; // initial value of dist
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

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }

  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    rep(i,n) node[i].dist = inf;
    node[s].dist = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      if(node[v].dist < dis) continue; 
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	if(chmin(node[w].dist, node[v].dist + cos)) {
	  pq.emplace(w, node[w].dist);
	}
      }
    }
  }

  void solve(int s, int t) {
    Init_Node();
    dijkstra(s);
    vector<X> dists(n);
    rep(i,n) dists[i] = node[i].dist;
    dijkstra(t);
    bool f = true;
    rep(i,n) {
      if(dists[i] != inf && node[i].dist != inf && dists[i] == node[i].dist) {
	f = false;
	cout << i + 1 << "\n";
	break;
      }
    }
    if(f) cout << -1 << "\n";
  }

  X Get_d(int v) {
    return node[v].dist;
  }
  
};

int main()
{
  int n,m;cin >> n >> m;
  int s,t;cin >> s >> t;
  s--; t--;
  vector<int> a(m), b(m), c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  Graph<int> gp(n, m, a, b, c);
  gp.solve(s, t);
  
  return 0;
}
