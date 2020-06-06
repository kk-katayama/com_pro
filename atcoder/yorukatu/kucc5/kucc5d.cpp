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
// Dijkstra. You should include queue lib.
//***********************************************************

template <typename X>
struct Edge{ // status of edge
  int from; 
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

template <typename X>
struct Node{ // Status of node
  int idx; // index of node
  X dist; // distance from start node
  vector<Edge<X>> edge;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
  
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
  vector<Node<X>> node; // node list

  const X inf = 1e+9; // initial value of dist

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }  
public:
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i]);
      add_edge(to[i], from[i]);      
    }
  }
  
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
      for(auto next: node[v].edge) {
	int w = next.to;
	X cos = next.cost;
	if(chmin(node[w].dist, node[v].dist + cos)) {
	  pq.emplace(w, node[w].dist);
	}
      }
    }
  }

  
  X Get_d(int v) { return node[v].dist; }
  X Get_inf() { return inf; }
  
};

int main()
{
  int n,m,r;
  cin >> n >> m >> r;
  vector<int> x(r);
  rep(i,r) {
    cin >> x[i];
    x[i]--;
  }

  vector<int> a(m), b(m), c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--; 
  }

  Graph<int> gp(n, m, a, b, c);
  vector<vector<int>> cost(r, vector<int>(r));
  rep(i,r) {
    gp.dijkstra(x[i]);
    rep(j,r) {
      cost[i][j] = gp.Get_d(x[j]);
    }
  }

  int inf = 1e+9;
  vector<vector<int>> dp(r, vector<int>((1<<r), inf));
  rep(i,r) {
    dp[i][(1<<i)] = 0;
  }
  rep1(mask, (1<<r)-1) {
    rep(i,r) {
      if(!((mask >> i) & 1)) continue;
      rep(j,r) {
	if(!((mask >> j) & 1)) {
	  chmin(dp[j][mask | (1 << j)], dp[i][mask] + cost[i][j]);
	}
      }
    }
  }
  
  int res = 1e+9;
  rep(i,r) chmin(res, dp[i][(1<<r)-1]);
  cout << res << "\n";
  
  return 0;
}
