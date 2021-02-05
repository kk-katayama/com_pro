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

// status of edge
template <typename X>
struct Edge{ 
  int from; 
  int to;
  X cost;
  X kon;
  
  Edge() = default;

  Edge(int from, int to, X cost, X kon) : from(from), to(to), cost(cost), kon(kon) {}
};

// status of node
template <typename X>
struct Node{ 
  int idx; // index of node
  vector<Edge<X>> edge;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
  
};


template <typename X = int>
struct Status{ // entered priority_queue
  int idx;
  X dist;

  Status() = default;

  Status(int idx, X dist) : idx(idx), dist(dist) {}

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

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; // node list

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }  
public:
  vector<X> d;
  vector<int> prev;
  
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      // add_edge(from[i], to[i]);
      // add_edge(to[i], from[i]);      
    }
  }
  
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost, vector<X> kon) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i], cost[i], kon[i]);
      add_edge(to[i], from[i], cost[i], kon[i]);      
    }
  }

  void add_edge(int from, int to, X cost, X kon) {
    node[from].edge.emplace_back(from, to, cost, kon);
  }



  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s, ll k, ll t) { 
    // initalize d
    d.assign(n, infll);
    d[s] = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      if(d[v] < dis) continue; 
      for(auto next: node[v].edge) {
	int w = next.to;
	X cos = next.cost;
	X kon = next.kon;
	if(d[v] + cos <= k - kon + t) {
	  if(chmin(d[w], d[v] + cos)) {
	    pq.emplace(w, d[w]);
	  }
	}
	else {
	  ll x = kon + t - k;
	  if(x <= t) {
	    if(chmin(d[w], d[v] + cos)) {
	      pq.emplace(w, d[w]);
	    }
	  }
	  else {
	    if(chmin(d[w], max(d[v],x) + cos)) {
	      pq.emplace(w, d[w]);
	    }	    
	  }
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
  int n,m;
  cin >> n >> m;
  ll t,k; cin >> t >> k;
  vi a(m),b(m);
  vl c(m),d(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--;
  }

  Graph<ll> gp(n, m, a, b, c, d);
  gp.dijkstra(0, k, t);
  cout << (gp.d[n-1] == infll ? -1 : gp.d[n-1]) << "\n";

  
  return 0;
}
