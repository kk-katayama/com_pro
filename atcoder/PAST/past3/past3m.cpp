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

  void solve(int s, int k, vector<int> t) {
    vector<vector<X>> c(k+1, vector<X>(k+1));
    dijkstra(s);
    rep(i,k) {
      c[0][i+1] = node[t[i]].dist;
      c[i+1][0] = node[t[i]].dist;
    }
    rep(i,k) {
      dijkstra(t[i]);
      rep(j,k) {
	c[i+1][j+1] = node[t[j]].dist;
	c[j+1][i+1] = node[t[j]].dist;	
      }
    }
    // rep(i,k+1) {
    //   rep(j,k+1) cout << c[i][j] << " ";
    //   cout << "\n";
    // }
    vector<vector<X>> dp(k+1, vector<int>((1 << (k+1)), inf));
    dp[0][1] = 0;
    rep1(mask,(1 << (k+1)) - 1) {
      rep(i,k+1) {
	if((mask >> i) & 1) {
	  rep1(j,k) {
	    chmin(dp[j][mask | (1 << j)], dp[i][mask] + c[i][j]);
	  }
	}
      }
    }
    X res = inf;
    rep(i,k+1) chmin(res, dp[i][(1 << (k+1))-1]);
    cout << res << "\n";
  }

  
};

int main()
{
  int n,m; cin >> n >> m;
  vector<int> u(m), v(m);
  rep(i,m) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
  }
  int s,k; cin >> s >> k;
  s--;
  vector<int> t(k);
  rep(i,k) {
    cin >> t[i];
    t[i]--;
  }
  Graph<int> gp(n, m, u, v);
  gp.solve(s, k, t);
  return 0;
}
