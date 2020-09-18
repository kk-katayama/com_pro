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
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
//****************************************
// Graph template
//****************************************

// status of edge
template <typename X>
struct Edge{
  int from;
  int to;
  int rev;
  X cap;
  X cost;

  Edge() = default;

  Edge(int from, int to, int rev, X cap, X cost) : from(from), to(to), rev(rev), cap(cap), cost(cost) {}
};

// status of node
template <typename X>
struct Node{ 
  int idx;
  vector<Edge<X>> edge;
  map<X, int> idtable;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node;

  X inf = numeric_limits<X>::max();
  
  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }
public:
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  void add_edge(int from, int to, X cap, X cost) {
    node[from].edge.emplace_back(from, to, node[to].edge.size(), cap, cost);
    node[from].idtable[to] = node[from].edge.size() - 1;
    node[to].edge.emplace_back(to, from, node[from].edge.size()-1, 0, -cost);
    node[to].idtable[from] = node[to].edge.size() - 1;    
  }

  // from->toの辺(Edge<>)を返す
  Edge<X> get_edge(int from, int to) {
    return node[from].edge[node[from].idtable[to]];
  }

  X min_cost_flow(int s, int t, X f) {
    vector<X> h(n, 0), dist;
    vi prev(n);
    X res = 0;
    using pxi = pair<X, int>;
    while(f > 0) {
      priority_queue<pxi, vector<pxi>, greater<pxi>> pq;
      dist.assign(n, inf);
      dist[s] = 0;
      pq.push({0, s});
      while( !pq.empty() ) {
	pxi p = pq.top(); pq.pop();
	int v = p.second;
	if(dist[v] < p.first) continue;
	for(auto next: node[v].edge) {
	  if( next.cap > 0 && dist[next.to] > dist[v] + next.cost + h[v] - h[next.to]) {
	    dist[next.to] = dist[v] + next.cost + h[v] - h[next.to];
	    prev[next.to] = v;
	    pq.push({dist[next.to], next.to});
	  }
	}
      }
      if(dist[t] == inf) {
	return -1;
      }
      rep(i,n) h[i] += dist[i];
      X d = f;
      for (int i = t; i != s; i = prev[i]) {
	int idx = node[prev[i]].idtable[i];
	d = min(d, node[prev[i]].edge[idx].cap);
      }
      f -= d;
      res += d * h[t];
      for (int i = t; i != s; i = prev[i]) {
	int idx = node[prev[i]].idtable[i];
	Edge<X> &e = node[prev[i]].edge[idx];
	e.cap -= d;
	node[i].edge[e.rev].cap += d;
      }
    }
    return res;
  }
  
};





int main()
{
  ll n,k; cin >> n >> k;
  using vl = vector<ll>;
  using vll = vector<vl>;
  vll a(n, vl(n));
  rep(i,n) {
    rep(j,n) {
      cin >> a[i][j];
    }
  }

  Graph<ll> gp(2*n + 2);
  rep(i,n) {
    rep(j,n) {
      gp.add_edge(i, j+n, (ll)1, -a[i][j]);
    }
  }

  rep(i,n) {
    gp.add_edge(2*n, i, k, 0);
    gp.add_edge(i+n, 2*n+1, k, 0);
  }

  gp.add_edge(2*n, 2*n+1, n*k, 0);
  
  cout << -gp.min_cost_flow(2*n, 2*n+1, k*n) << "\n";

  vector<vector<char>> s(n, vector<char>(n, '.'));
  rep(i,n) {
    rep(j,n) {
      Edge<ll> e = gp.get_edge(i, j+n);
      if(e.cap == 0) {
	s[i][j] = 'X';
      }
    }
  }

  rep(i,n) {
    rep(j,n) {
      cout <<  s[i][j];
    }
    cout << "\n";
  }
  
  return 0;
}
