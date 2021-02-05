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

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
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
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      //      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }



  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    d.assign(2*n, inf);
    d[s] = 0;
    prev.assign(n, -1);
    
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
  ll n,m; cin >> n >> m;
  vl h(m),w(m);
  vl c(m);
  vvl cost(n, vl(n, 0));
  rep(i,m) {
    cin >> h[i] >> w[i] >> c[i];
    h[i]--; w[i]--;
    cost[w[i]][h[i]] = c[i];
  }

  vl dx = {-1, 0, 1, 0};
  vl dy = {0, -1, 0, 1};
  
  vector<vvl> d(n, vvl(n, vl(2, infll/2)));
  d[0][0][0] = 0;
  priority_queue<pl, vector<pl>, greater<pl>> pq;
  pq.emplace(0, 0);
  while( !pq.empty() ) {
    auto [nd, id] = pq.top(); pq.pop();
    //    cout << nd << ":" << id << "\n";
    ll x, y, z;
    if(id >= n*n + 1) {
      x = (id - n*n - 1) % n;
      y = (id - n*n - 1) / n;
      z = 1;
    }
    else {
      x = id % n;
      y = id / n;
      z = 0;
    }
    if(d[x][y][z] < nd) continue;
    rep(i,4) {
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < n) {
	//	if(id == 11) cout << nx << ":" << ny << ":" << cost[nx][ny] << "\n";
	if(z == 0) {
	  if(chmin(d[nx][ny][1], d[x][y][z] + 1)) {
	    pq.emplace(d[nx][ny][1], nx + ny*n + n*n + 1);
	  }
	  if(chmin(d[nx][ny][0], d[x][y][z] + 1 + cost[nx][ny])) {
	    pq.emplace(d[nx][ny][0], nx + ny*n);
	  }
	}
	else {
	  if(chmin(d[nx][ny][1], d[x][y][z] + 1 + cost[nx][ny])) {
	    pq.emplace(d[nx][ny][1], nx + ny*n + n*n + 1);
	  }	  
	}
      }
    }
  }
  // rep(j,n) {
  //   rep(i,n) cout << d[i][j][0] << " ";
  //   cout << "\n";
  // }
  // rep(j,n) {
  //   rep(i,n) cout << d[i][j][1] << " ";
  //   cout << "\n";
  // }  
  
  cout << d[n-1][n-1][1] << "\n";
  
  return 0;
}
