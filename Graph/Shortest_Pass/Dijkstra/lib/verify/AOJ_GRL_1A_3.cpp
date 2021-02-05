#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
//***********************************************************
// Dijkstra. You should include queue lib.
//***********************************************************

template <typename X>
class Graph{
public:  
  // status of edge
  struct Edge{
    int idx;
    int from; 
    int to;
    X cost;
    Edge(int idx, int from, int to, X cost) : idx(idx), from(from), to(to), cost(cost) {}
  };

  // status of node
  struct Node{ 
    int idx; // index of node
    vector<Edge> edge;
    Node(int idx) : idx(idx) {}
  };

  struct Status{ // entered priority_queue
    int idx;
    X dist;

    Status() = default;

    Status(int idx, X dist) : idx(idx), dist(dist) {}

    // bool operator == (const Status& r) const {
    //   return (idx == r.idx && dist == r.dist);
    // }

    // bool operator != (const Status& r) const {
    //   return !(*this == r);
    // }

    bool operator < (const Status& r) const {
      return dist > r.dist;
    }

    // bool operator > (const Status& r) const {
    //   return dist < r.dist;
    // }

  };
  
  int n; // number of node
  int m; // number of edge
  vector<Node> node; // node list
  vector<X> d;
  vector<int> prev;

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }  
  
  Graph(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(i, from[i], to[i]);
      add_edge(i, to[i], from[i]);      
    }
  }
  
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(i, from[i], to[i], cost[i]);
      //      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int idx, int from, int to, X cost = 1) {
    node[from].edge.emplace_back(idx, from, to, cost);
  }

  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    d.assign(n, inf);
    d[s] = 0;
    prev.assign(n, -1);
    
    priority_queue<Status> pq;
    pq.emplace(s, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Status now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      if(d[v] < dis) continue; 
      for(auto next: node[v].edge) {
	int w = next.to;
	X cos = next.cost;
	if(chmin(d[w], d[v] + cos)) {
	  pq.emplace(w, d[w]);
	  prev[w] = v;
	}
      }
    }
  }

  // s->t の最短経路復元
  vector<int> getpath(int t) {
    vector<int> res;
    for(; t != -1; t = prev[t]) {
      res.push_back(t);
    }
    reverse(res.begin(), res.end());
    return res;
  }
  
};


int main()
{
  int n,m,s; cin >> n >> m >> s;
  vi a(m),b(m);
  vl c(m);
  rep(i,m) cin >> a[i] >> b[i] >> c[i];

  Graph<ll> gp(n, m, a, b, c);
  gp.dijkstra(s);
  for(auto val: gp.d) {
    if(val == inf) cout << "INF" << "\n";
    else cout << val << "\n";
  }
  // vi path = gp.getpath(3);
  // for(auto val: path) cout << val << "\n";
  return 0;
}
