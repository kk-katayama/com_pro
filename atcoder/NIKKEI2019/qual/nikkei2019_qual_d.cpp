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
using pi = pair<int,int>;
//****************************************
// Graph template
//****************************************

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
  int idx;
  vector<Edge<X>> edge;
  X dist;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; 

  X inf = 1e+15;
  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }
public:
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // edges have no-weight 
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i]);
      add_edge(to[i], from[i]);      
    }
  }  

  // edges have weight
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

  void Dijkstra(int s) {
    rep(i,n) node[i].dist = inf;
    node[s].dist = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, s});
    while( !q.empty() ) {
      pi p = q.top(); q.pop();
      int nd = p.first, v = p.second;
      if(node[v].dist < nd) continue;
      for(auto next: node[v].edge) {
	int w = next.to;
	X cost = next.cost;
	if(chmin(node[w].dist, node[v].dist + cost)) {
	  q.push({node[w].dist, w});
	}
      }
    }
  }

  void Solve() {
    rep(i,n-1) add_edge(i+1, i, (X)0);
    Dijkstra(0);
    cout << (node[n-1].dist == inf ? -1 : node[n-1].dist) << "\n";
  }
  
};


int main()
{
  int n,m; cin >> n >> m;
  vector<int> a(m), b(m);
  vector<ll> c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  Graph<ll> gp(n, m, a, b, c);
  gp.Solve();
  
  return 0;
}
