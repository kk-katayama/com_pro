#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
  char c;
  bool flag, visit;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {visit = false;}
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

  void Build(string s) {
    rep(i,n) node[i].c = s[i];
    rep(i,n) {
      bool fa = false, fb = false;
      for(auto next: node[i].edge) {
	int w = next.to;
	if(node[w].c == 'A') fa = true;
	else fb = true;
      }
      if(fa && fb) node[i].flag = true;
      else node[i].flag = false;
    }
  }

  bool DFS(int v) {
    node[v].visit = true;
    bool fa = false, fb = false;
    for(auto next: node[v].edge) {
      int w = next.to;
      if(!node[w].flag) continue;
      if(node[w].visit) {
	if(node[w].c == 'A') fa = true;
	else fb = true;
      }
      else {
	if(node[w].c == 'A') fa = fa | DFS(w);
	else fb = fb | DFS(w);	
      }
    }
    return node[v].visit = fa && fb;
  }
  
  void solve() {
    bool fa = false, fb = false;
    rep(i,n) {
      if(node[i].flag) {
	if(node[i].c == 'A') {
	  fa = fa | DFS(i);
	}
	else {
	  fb = fb | DFS(i);	  
	}
      }
      //      cout << fa << ":" << fb << "\n";
    }
    cout << ((fa && fb) ? "Yes" : "No") << "\n";      

  }
  
};


int main()
{
  int n,m; cin >> n >> m;
  string s; cin >> s;
  vector<int> a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Graph<int> gp(n, m, a, b);
  gp.Build(s);
  gp.solve();
  return 0;
}
