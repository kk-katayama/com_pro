#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
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
  int a;
  X b;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; 
  X x;
  bool f, flag;
  
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

  void DFS(int v, int na, X nb) {
    node[v].a = na;
    node[v].b = nb;
    for(auto next: node[v].edge) {
      int w = next.to;
      X c = next.cost;
      if(node[w].a == 0) DFS(w, -na, c - nb);
      else if(node[w].a == na) {
	if((c - node[v].b - node[w].b) % 2 == 1) f = false;
	else {
	  if(na == 1) {
	    X y = (c - node[v].b - node[w].b) / 2;
	    if(flag && x != y) f = false;
	    else x = y;
	  }
	  else {
	    X y = -(c - node[v].b - node[w].b) / 2;
	    if(flag && x != y) f = false;
	    else x = y;
	  }
	}
	flag = true;
      }
      else {
	if(node[v].b + node[w].b != c) f = false;
      }
    }
  }

  void Solve() {
    rep(i,n) node[i].a = 0;
    f = true;
    flag = false;
    DFS(0, 1, 0);
    //    rep(i,n) cout << i << ":" << node[i].a << ":" << node[i].b << "\n";
    if(f) {
      ll pmin = 2e+9+10, mmin = 2e+9+10;
      rep(i,n) {
	if(node[i].a == 1) chmin(pmin, (ll)node[i].b);
	else chmin(mmin, (ll)node[i].b);
      }
      //      cout << pmin << ":" << mmin << "\n";
      if(flag) {
	if(max((ll)1, 1 - pmin) <= x && x <= mmin - 1) cout << 1 << "\n";
	else cout << 0 << "\n";
      }
      else {
	int res = max((ll)0, mmin - max((ll)1, 1 - pmin));
	cout << res << "\n";
      }
    }
    else {
      cout << 0 << "\n";
    }
  }
  
};


int main()
{
  int n,m; cin >> n >> m;
  vector<int> u(m), v(m);
  vector<ll> s(m);
  rep(i,m) {
    cin >> u[i] >> v[i] >> s[i];
    u[i]--; v[i]--;
  }

  Graph<ll> gp(n, m, u, v, s);
  gp.Solve();
  return 0;
}
