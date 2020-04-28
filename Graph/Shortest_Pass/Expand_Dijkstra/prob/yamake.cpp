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

  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X = int>
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
  int mask;
  int money;
  
  Status() = default;

  Status(int idx, X dist, int mask, int money) : idx(idx), dist(dist), mask(mask), money(money) {}

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

template <typename X = int>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<vector<Edge<X>>> edge; // edge list
  vector<Node<X>> node; // node list

  vector<vector<vector<vector<X>>>> d; // (s, g, mask, money)
  const X inf = 1e+9; // initial value of d
  int M = 9;
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

  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    d.resize(n);
    d[s].resize(n, vector<vector<X>>((1<<n), vector<X>(M+1, inf)));
    d[s][s][0][0] = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0, 0, 0); // (node, dist, mask, money)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int mask = now.mask;
      int money = now.money;
      if(money == M) continue;
      if(d[s][v][mask][money] < dis) continue; 
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	if(chmin(d[s][w][mask | (1<<w)][money+1], d[s][v][mask][money] + cos)) {
	  pq.emplace(w, d[s][w][mask | (1 << w)][money+1], (mask|(1<<w)), money+1);
	}
      }
    }
  }


  X Get_d(int start, int goal, int mask, int money) {
    //    if(d[start][goal][mask][money] == inf) return -1;
    return d[start][goal][mask][money];
  }
  
};

int main()
{
  int n,m; cin >> n >> m;
  vector<int> a(m), b(m), c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
  }

  Graph<int> gp(n, m, a, b, c);
  gp.dijkstra(0);
  int res = 1e+9;
  rep(i,10) {
    chmin(res, gp.Get_d(0, 0, (1<<n) - 1, i));
  }
  cout << res << "\n";
  
  return 0;
}
