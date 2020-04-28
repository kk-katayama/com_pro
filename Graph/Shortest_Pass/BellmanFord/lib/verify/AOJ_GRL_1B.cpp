#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
//***********************************************************
// Bellmanford
//***********************************************************
template <typename X>
struct Node{ // Status of node
  int idx; // index of node
  X dist; // distance from start node
  
  Node() = default;

  Node(int idx, X dist) : idx(idx), dist(dist) {}

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

template <typename X>
struct Edge{ // status of edge
  int from; 
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<vector<Edge<X>>> edge; // edge list
  vector<Node<X>> node; // node list

  vector<vector<X>> d; // d[i][j] := shortest distance from node "i" to node "j"
  const X inf = 1e+9; // initial value of d
public:
  explicit Graph(int n) : n(n) {
    edge.resize(n);
  }

  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    edge.resize(n);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      //      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost) {
    edge[from].emplace_back(from, to, cost);
  }

  //***********************************
  // Bellmanford
  //***********************************
  bool Bellmanford(int s) {
    d.resize(n);
    d[s].resize(n, inf);
    d[s][s] = 0;
    
    bool flag = true;
    rep(i,n) {
      rep(v,n) {
	if(d[s][v] == inf) continue;
	for(auto next: edge[v]) {
	  int w = next.to;
	  X cost = next.cost;
	  if(d[s][w] > d[s][v] + cost) {
	    d[s][w] = d[s][v] + cost;
	    if(i == n - 1) flag = false;
	  }
	}
      }
    }
    return flag;
  }
  
  X Get_d(int start, int goal) {
    //    if(d[start][goal] == inf) return -1;
    return d[start][goal];
  }

  X Get_inf() { return inf; }
  
};

int main()
{
  int n,m;cin >> n >> m;
  int r; cin >> r;
  vector<int> a(m), b(m), c(m);
  rep(i,m) cin >> a[i] >> b[i] >> c[i];

  Graph<int> gp(n, m, a, b, c);
  if(gp.Bellmanford(r)) {
    rep(i,n) {
      if(gp.Get_d(r, i) == gp.Get_inf()) cout << "INF" << "\n";
      else cout << gp.Get_d(r, i) << "\n";
    }
  }
  else cout << "NEGATIVE CYCLE" << "\n";
  
  return 0;
}
