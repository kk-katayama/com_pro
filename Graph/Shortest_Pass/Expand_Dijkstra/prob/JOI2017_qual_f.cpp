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
  int room;
  
  Node() = default;

  Node(int idx, int room) : idx(idx), room(room) {}
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
  int room;
  int time;
  
  Status() = default;

  Status(int idx, X dist, int room, int time) : idx(idx), dist(dist), room(room), time(time) {}

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

  vector<vector<vector<vector<X>>>> d;
  const X inf = 1e+9; // initial value of d
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
  
  void Init_node(vector<int> room) {
    rep(i,n) {
      node.emplace_back(i, room[i]);
    }
  }
  
  void add_edge(int from, int to, X cost) {
    edge[from].emplace_back(from, to, cost);
  }
  
  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s, int x) { 
    // initalize d
    d.resize(n);
    d[s].resize(n, vector<vector<X>>(201, vector<X>(2, inf)));
    d[s][s][0][0] = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0, 0, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      int room = now.room;
      int time = now.time;
      if(d[s][v][time][room] < dis) continue; 
      for(auto next: edge[v]) {
	int w = next.to;
	X cos = next.cost;
	int nroom = node[w].room;
	if( (room == 0 && nroom == 1) || (room == 1 && nroom == 0) ) {
	  if(time + cos < x) continue;
	}
	if(nroom == 0 || nroom == 1) {
	  if(chmin(d[s][w][0][nroom], d[s][v][time][room] + cos)) {
	    pq.emplace(w, d[s][w][0][nroom], nroom, 0);
	  }	  
	}
	else {
	  if(chmin(d[s][w][min(200, time + cos)][room], d[s][v][time][room] + cos)) {
	    pq.emplace(w, d[s][w][min(200, time + cos)][room], room, min(200, time+cos));
	  }
	}
      }
    }
  }


  X Get_d(int start, int goal, int time, int room) {
    //    if(d[start][goal][time][room] == inf) return -1;
    return d[start][goal][time][room];
  }
  
};

int main()
{
  int n,m,x; cin >> n >> m >> x;
  vector<int> t(n);
  rep(i,n) {
    cin >> t[i];
    if(t[i] == 1) t[i] = 2;
    else if(t[i] == 2) t[i] = 1;
  }
  vector<int> a(m), b(m), d(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> d[i];
    a[i]--; b[i]--;
  }

  Graph<int> gp(n, m, a, b, d);
  gp.Init_node(t);
  gp.dijkstra(0, x);
  
  int res = 1e+9;
  rep(i,201) rep(j,2) {
    chmin(res, gp.Get_d(0, n-1, i, j));
  }
  cout << res << "\n";


  return 0;
}
