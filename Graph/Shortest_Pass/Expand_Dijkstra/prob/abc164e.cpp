#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
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
  X dist; // distance from start node
  int coin;
  int rate;
  X time;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
  
  Node(int idx, X dist, int coin) : idx(idx), dist(dist), coin(coin) {}

  void Set(int ratee, X timee) {
    rate = ratee;
    time = timee;
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
  int charge;
  
  Edge() = default;

  Edge(int from, int to, X cost, int charge) : from(from), to(to), cost(cost), charge(charge) {}
};

template <typename X = int>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<vector<Edge<X>>> edge; // edge list
  vector<Node<X>> node; // node list

  vector<vector<vector<X>>> d;
  const X inf = 1e+17; // initial value of d
  int M = 2500;
  
public:
  explicit Graph(int n) : n(n) {
    edge.resize(n);
  }

  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost, vector<int> charge) : n(n), m(m) {
    edge.resize(n);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i], charge[i]);
      add_edge(to[i], from[i], cost[i], charge[i]);      
    }
  }

  void add_edge(int from, int to, X cost, int charge) {
    edge[from].emplace_back(from, to, cost, charge);
  }

  void Init_node(vector<int> rate, vector<X> time) {
    rep(i,n) node.emplace_back(i);
    rep(i,n) node[i].Set(rate[i], time[i]);
  }

  
  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s, int g) { 
    // initalize d
    d.resize(n);
    d[s].resize(n, vector<X>(M+1, inf));
    chmin(g, M);
    d[s][s][g] = 0;
    
    priority_queue<Node<X>> pq;
    pq.emplace(s, 0, g); // (node, distance, coin)

    while( !pq.empty() ) {
      Node<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int coin = now.coin;
      
      // exchange coin
      int rate = node[v].rate;
      X time = node[v].time;
      if(chmin(d[s][v][min(M, coin + rate)], d[s][v][coin] + time)) {
	pq.emplace(v, d[s][v][min(M, coin + rate)], min(M, coin + rate));
      }
      
      if(d[s][v][coin] < dis) continue; 
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	int charge = next.charge;
	if(coin < charge) continue;
	if(chmin(d[s][w][coin - charge], d[s][v][coin] + cos)) {
	  pq.emplace(w, d[s][w][coin - charge], coin - charge);
	}
      }
    }
  }


  X Get_d(int start, int goal, int coin) {
    //    if(d[start][goal] == inf) return -1
    return d[start][goal][coin];
  }
  
};


int main()
{
  int n,m,s; cin >> n >> m >> s;
  vector<int> u(m), v(m), a(m), c(n);
  vector<ll> b(m), d(n);
  rep(i,m) {
    cin >> u[i] >> v[i] >> a[i] >> b[i];
    u[i]--; v[i]--;
  }
  rep(i,n) cin >> c[i] >> d[i];
  
  Graph<ll> gp(n, m, u, v, b, a);
  gp.Init_node(c, d);
  gp.dijkstra(0, s);

  rep1(i,n-1) {
    ll res = 1e+17;
    rep(j,2501) {
      chmin(res, gp.Get_d(0, i, j));
    }
    cout << res << "\n";
  }
  
  return 0;
}
