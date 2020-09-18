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
  vector<Edge<X>> revedge;  
  bool used, ing;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; 
  vi table;
  
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
    }
  }  

  // edges have weight
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      add_edge(to[i], from[i], cost[i]);
      add_revedge(from[i], to[i], cost[i]);
      add_revedge(to[i], from[i], cost[i]);            
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void add_revedge(int from, int to, X cost = 1) {
    node[from].revedge.emplace_back(from, to, cost);
  }  

  set<int> S;
  
  void build(int q, vi x, vi y) {
    table.resize(n);
    rep(i,n) table[i] = i;
    rep(i,n) node[i].used = false;
    rep(i,n) node[i].ing = false;    

    auto loop = [&](auto fl, int v, int start, int goal) {
		  table[v] = start;
		  node[v].ing = false;
		  if(v == goal) return ;
		  for(auto next: node[v].edge) {
		    int w = next.to;
		    if(node[w].ing) {
		      node[w].ing = false;
		      fl(fl, w, start, goal);
		    }
		  }
		  node[v].used = true;
		};

    
    
    auto dfs = [&](auto f, int v) ->void{
		 node[v].ing = true;
		 for(auto next: node[v].edge) {
		   int w = next.to;
		   if(node[w].used) {
		     continue;
		   }		   
		   if(node[w].ing) {
		     loop(loop, w, w, v);
		     continue;
		   }
		   f(f, w);
		 }
		 node[v].used = true;
		 node[v].ing = false;
	       };
    
    rep(i,n) {
      if(!node[i].used) {
	dfs(dfs, i);
      }
    }

    rep(v,n) {
      for(auto next: node[v].edge) {
	int w = next.to;
	int nv = table[v];
	w = table[w];
	if(nv == w) continue;
	add_revedge(w, nv);
      }
    }
    auto dfs2 = [&](auto f2, int v) ->void{
		  v = table[v];
		  if(S.find(v) != S.end()) return ;
		  S.insert(v);
		 for(auto next: node[v].revedge) {
		   int w = next.to;
		   if(table[w] == v) continue;
		   f2(f2, w);
		 }
		};

    dfs2(dfs2, 0);
    
    rep(i,q) {
      if(x[i] == 1) {
	dfs2(dfs2, y[i]);
      }
      else {
	if(S.find(table[y[i]]) != S.end()) cout << "YES" << "\n";
	else cout << "NO" << "\n";
      }
    }
  }


  
};


int main()
{
  int n,m; cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i,m) {
    scanf("%d %d", &a[i], &b[i]);
    a[i]--; b[i]--;
  }
  int q; cin >> q;
  vector<int> x(q), y(q);
  rep(i,q) {
    scanf("%d %d", &x[i], &y[i]);
    y[i]--;
  }
  
  Graph<int> gp(n, m, a, b);
  gp.build(q, x, y);
  
  return 0;
}
