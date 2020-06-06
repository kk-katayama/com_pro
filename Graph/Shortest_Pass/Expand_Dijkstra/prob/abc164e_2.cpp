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
struct Edge{ // status of edge
  int from; 
  int to;
  X cost;
  int charge;
  
  Edge() = default;

  Edge(int from, int to, X cost, int charge) : from(from), to(to), cost(cost), charge(charge) {}
};

template <typename X = int>
struct Node{ // Status of node
  int idx; // index of node
  X dist[2501]; // distance from start node
  vector<Edge<X>> edge;
  int rate;
  X time;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
  
  Node(int idx, int rate, X time) : idx(idx), rate(rate), time(time) {}

};

template <typename X>
struct Status{
  int idx;
  X dist;
  int coin;

  Status() = default;

  Status(int idx, X dist, int coin) : idx(idx), dist(dist), coin(coin) {}
  
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
  vector<Node<X>> node; // node list

  const X inf = 1e+17; // initial value of d
  int M = 2500;
  
public:
  explicit Graph(int n) : n(n) {
  }

  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost, vector<int> charge, vector<int> rate, vector<X> time) : n(n), m(m) {
    Init_Node(rate, time);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i], charge[i]);
      add_edge(to[i], from[i], cost[i], charge[i]);      
    }
  }

  void add_edge(int from, int to, X cost, int charge) {
    node[from].edge.emplace_back(from, to, cost, charge);
  }

  void Init_Node(vector<int> rate, vector<X> time) {
    rep(i,n) node.emplace_back(i, rate[i], time[i]);
  }
  
  
  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s, int g) { 
    rep(i,n) rep(j,M+1) node[i].dist[j] = inf;
    chmin(g, M);
    node[s].dist[g] = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0, g); // (node, distance, coin)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int coin = now.coin;
      
      // exchange coin
      int rate = node[v].rate;
      X time = node[v].time;
      if(chmin(node[v].dist[min(M, coin + rate)], node[v].dist[coin] + time)) {
	pq.emplace(v, node[v].dist[min(M, coin + rate)], min(M, coin + rate));
      }
      
      if(node[v].dist[coin] < dis) continue; 
      for(auto next: node[v].edge) {
	int w = next.to;
	X cos = next.cost;
	int charge = next.charge;
	if(coin < charge) continue;
	if(chmin(node[w].dist[coin - charge], node[v].dist[coin] + cos)) {
	  pq.emplace(w, node[w].dist[coin - charge], coin - charge);
	}
      }
    }
  }


  X Get_d(int v, int coin) {
    //    if(d[start][goal] == inf) return -1
    return node[v].dist[coin];
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
  
  Graph<ll> gp(n, m, u, v, b, a, c, d);
  gp.dijkstra(0, s);

  rep1(i,n-1) {
    ll res = 1e+17;
    rep(j,2501) {
      chmin(res, gp.Get_d(i, j));
    }
    cout << res << "\n";
  }
  
  return 0;
}
