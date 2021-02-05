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
class Graph{
public:  
  // status of edge
  struct Edge{ 
    int from; 
    int to;
    X cost;

    Edge() = default;

    Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
  };

  // status of node
  struct Node{ 
    int idx; // index of node
    X dist; // distance from start node
    vector<Edge> edge;
  
    Node() = default;

    explicit Node(int idx) : idx(idx) {}
  
  };


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

  int n; // number of node
  int m; // number of edge
  vector<Node> node; // node list

  const X inf = 1e+9; // initial value of dist

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }  

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
      //      add_edge(to[i], from[i], cost[i]);      
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
    
    priority_queue<Status> pq;
    pq.emplace(s, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Status now = pq.top(); pq.pop();
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
  int n,m,s;cin >> n >> m >> s;
  vector<int> a(m), b(m), c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
  }

  Graph<int> gp(n, m, a, b, c);
  gp.dijkstra(s);

  rep(i,n) {
    int res = gp.Get_d(i);
    if(res == gp.Get_inf()) cout << "INF" << "\n";
    else cout << res << "\n";
  }
  
  return 0;
}
