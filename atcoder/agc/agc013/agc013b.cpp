#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
  bool visit;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; 

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
      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void solve() {
    rep(i,n) node[i].visit = false;
    int s = 0, t;
    t = node[s].edge[0].to;
    vector<int> res;
    res.push_back(s);
    res.push_back(t);
    node[s].visit = true;
    node[t].visit = true;
    queue<int> q;
    q.push(t);
    while( !q.empty() ) {
      int v = q.front(); q.pop();
      for(auto next: node[v].edge) {
	int w = next.to;	
	if( !node[w].visit ) {
	  node[w].visit = true;
	  res.push_back(w);
	  q.push(w);
	  break;
	}
      }
    }
    reverse(res.begin(), res.end());
    q.push(s);
    while( !q.empty() ) {
      int v = q.front(); q.pop();
      for(auto next: node[v].edge) {
	int w = next.to;
	if( !node[w].visit ) {
	  node[w].visit = true;
	  res.push_back(w);
	  q.push(w);
	  break;
	}
      }
    }
    int ans = res.size();
    cout << ans << "\n";
    rep(i,ans) {
      cout << res[i] + 1 << " ";
    }
    cout << "\n";
  }
  
};


int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Graph<int> gp(n, m, a, b);
  gp.solve();
  return 0;
}
