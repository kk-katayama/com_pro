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
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
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
    int from; 
    int to;
    X cost;

    Edge() = default;

    Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
  };

  // status of node
  struct Node{ 
    int idx; // index of node
    vector<Edge> edge;
  
    Node() = default;

    explicit Node(int idx) : idx(idx) {}
  
  };

  struct Status{ // entered priority_queue
    int idx;
    X dist;
    int t;
  
    Status() = default;

    Status(int idx, X dist, int t) : idx(idx), dist(dist), t(t) {}

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
  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }  

  
  vector<X> c;  
  vector<X> d;
  vector<int> prev;
  const X inf = 1e+9; // initial value of dist
  
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
    c.resize(n);
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }


  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra() { 
    // initalize d
    d = c;
    vi f(n, 0);
    
    priority_queue<Status> pq;
    X mn = infll;
    rep(i,n) {
      pq.emplace(i, c[i], 1); // pq have (node, shortest distance from start to the node)      
    }

    while( !pq.empty() ) {
      Status now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      if(now.t == 1) {
	f[v] = 1;
      }
      if(d[v] < dis) continue; 
      for(auto next: node[v].edge) {
	int w = next.to;
	X cos = next.cost;
	if(f[w]) continue;
	if(chmin(d[w], cos)) {
	  pq.emplace(w, d[w], 1);
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
  int n,m; cin >> n >> m;
  vl c(n);
  rep(i,n) cin >> c[i];
  vi a(m),b(m);
  vl r(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> r[i];
    a[i]--; b[i]--;
  }

  Graph<ll> gp(n, m, a, b, r);
  rep(i,n) gp.c[i] = c[i];
  gp.dijkstra();
  ll res = 0;
  rep(i,n) {
    res += gp.d[i];
    //    cout << i << ":" << gp.d[i] << "\n";
  }
  cout << res << "\n";
  return 0;
}
