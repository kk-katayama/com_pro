#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
//***********************************************************
// Dijkstra
//***********************************************************
template <typename X = int>
struct Node{ // Status of node
  int idx; // index of node
  int flower;
  X money;
  
  Node() = default;

  Node(int idx, int flower, X money) : idx(idx), flower(flower), money(money) {}
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
  int flower;
  
  Status() = default;

  Status(int idx, X dist, int flower) : idx(idx), dist(dist), flower(flower) {}

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

  vector<vector<vector<X>>> d; // (s, g, flower)
  const X inf = 1e+17; // initial value of d
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

  void Init_node(vector<int> flower, vector<X> money) {
    rep(i,n) {
      node.emplace_back(i, flower[i], money[i]);
    }
  }

  void add_edge(int from, int to, X cost) {
    edge[from].emplace_back(from, to, cost);
  }

  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s, int k) { 
    // initalize d
    d.resize(n);
    d[s].resize(n, vector<X>(k+1, inf));
    d[s][s][0] = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0, 0); // (node, dist, flower)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int num = now.flower;
      int flo = node[v].flower;
      X money = node[v].money;
      if(chmin(d[s][v][min(k, num + flo)], d[s][v][num] + money)) {
	pq.emplace(v, d[s][v][min(k, num + flo)], min(k, num + flo));
      }
      if(d[s][v][num] < dis) continue; 
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	if(chmin(d[s][w][num], d[s][v][num] + cos)) {
	  pq.emplace(w, d[s][w][num], num);
	}
      }
    }
  }


  X Get_d(int start, int goal, int flower) {
    if(d[start][goal][flower] == inf) return -1;
    return d[start][goal][flower];
  }
  
};

int main()
{
  int n,m,k;cin >> n >> m >> k;
  vector<int> a(m), b(m);
  vector<ll> c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }
  vector<int> x(n);
  vector<ll> y(n);
  rep(i,n) cin >> x[i] >> y[i];

  Graph<ll> gp(n, m, a, b, c);
  gp.Init_node(x, y);
  gp.dijkstra(0, k);
  cout << gp.Get_d(0, n-1, k) << "\n";
  return 0;
}
