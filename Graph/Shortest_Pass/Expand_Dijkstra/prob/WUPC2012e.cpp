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
  int mod4;
  int mod7;
  
  Status() = default;

  Status(int idx, X dist, int mod4, int mod7) : idx(idx), dist(dist), mod4(mod4), mod7(mod7) {}

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

  vector<vector<vector<vector<X>>>> d; // (s, g, mod4, mod7)
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
    d[s].resize(n, vector<vector<X>>(4, vector<X>(7, inf)));
    d[s][s][0][0] = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0, 0, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int mod4 = now.mod4;
      int mod7 = now.mod7;
      if(d[s][v][mod4][mod7] < dis) continue; 
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	int nmod4 = (mod4 + cos) % 4;
	int nmod7 = (mod7 + cos) % 7;
	if(w == n - 1 && nmod4 != 0 && nmod7 != 0) continue;
	if(chmin(d[s][w][nmod4][nmod7], d[s][v][mod4][mod7] + cos)) {
	  pq.emplace(w, d[s][w][nmod4][nmod7], nmod4, nmod7);
	}
      }
    }
  }


  X Get_d(int start, int goal, int mod4, int mod7) {
    //    if(d[start][goal] == inf) return -1;
    return d[start][goal][mod4][mod7];
  }
  
};

int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m), b(m);
  vector<ll> c(m);
  rep(i,m) cin >> a[i] >> b[i] >> c[i];

  Graph<ll> gp(n, m, a, b, c);
  gp.dijkstra(0);
  ll res = 1e+17;
  rep(i,7) chmin(res, gp.Get_d(0, n-1, 0, i));
  rep(i,4) chmin(res, gp.Get_d(0, n-1, i, 0));
  cout << res << "\n";
  return 0;
}
