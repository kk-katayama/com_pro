#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
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
  int limit;
  int idx;
  
  Edge() = default;

  Edge(int from, int to, X cost, int limit, int idx) : from(from), to(to), cost(cost), limit(limit), idx(idx) {}
};

template <typename X = int>
struct Status{ // entered priority_queue
  int idx;
  X dist;
  int vel;
  int before;
  
  Status() = default;

  Status(int idx, X dist, int vel, int before) : idx(idx), dist(dist), vel(vel), before(before) {}

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

  vector<vector<vector<vector<X>>>> d; // (s, g, velocity) = shortest distance
  const X inf = 1e+15; // initial value of d
  int M = 30;
public:
  explicit Graph(int n) : n(n) {
    edge.resize(n);
  }

  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost, vector<int> limit) : n(n), m(m) {
    edge.resize(n);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i], limit[i], i);
      add_edge(to[i], from[i], cost[i], limit[i], i);      
    }
  }

  void add_edge(int from, int to, X cost, int limit, int index) {
    edge[from].emplace_back(from, to, cost, limit, index);
  }

  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    d.resize(n);
    d[s].resize(n, vector<vector<X>>(M+2, vector<X>(m+1, inf)));
    d[s][s][0][m] = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0, 0, m); // (node, distance, speed, before)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int speed = now.vel; // velocity
      int before = now.before;
      if(d[s][v][speed][before] < dis) continue;
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	int limit = next.limit;
	int idx = next.idx;
	if(idx == before) continue;
	for(int i = -1; i <= 1; ++i) {
	  int nspeed = speed + i;
	  if(nspeed <= 0 || limit < nspeed) continue;
	  if(chmin(d[s][w][nspeed][idx], d[s][v][speed][before] + cos / nspeed)) {
	    pq.emplace(w, d[s][w][nspeed][idx], nspeed, idx);
	  }
	}
      }
    }
  }


  X Get_d(int start, int goal, int speed, int index) {
    //    if(d[start][goal][speed][index] == inf) return -1;
    return d[start][goal][speed][index];
  }

  X Get_inf() { return inf; }
};
int main()
{
  vector<double> ans;
  while(1) {
    int n,m; cin >> n >> m;
    if(n == 0 && m == 0) break;
    int s,g; cin >> s >> g;
    s--; g--;
    vector<int> x(m), y(m), c(m);
    vector<double> d(m);
    rep(i,m) {
      cin >> x[i] >> y[i] >> d[i] >> c[i];
      x[i]--; y[i]--;
    }
    Graph<double> gp(n, m, x, y, d, c);
    gp.dijkstra(s);
    double res = gp.Get_inf();
    rep(i,m) {
      chmin(res, gp.Get_d(s, g, 1, i));
    }
    ans.push_back(res);
  }
  Graph<double> g(1);
  rep(i,ans.size()) {
    if(ans[i] == g.Get_inf()) cout << "unreachable" << "\n";
    else printf("%.7f\n", ans[i]);
  }
  
  return 0;
}
