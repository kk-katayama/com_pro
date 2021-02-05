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
  vector<X> d;
  const X inf = 1e+15;
  
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // edges have no-weight 
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i]);
      //      add_edge(to[i], from[i]);      
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

  set<int> st;
  //ベルマンフォード法。頂点sから全頂点への最短距離。負閉路を見つけるとfalseを返す。
  bool bellmanford(int s){
    d.assign(n,inf);
    d[s] = 0;
    bool flag = true;
    rep(i,n){
      rep(v,n){
	if(d[v]==inf) continue;
	for(auto next: node[v].edge){
	  int w = next.to;
	  X cos = next.cost;
	  if(d[w]>d[v] + cos){
	    d[w] = d[v] + cos;
	    if(i==n-1){
	      flag = false;
	      st.insert(w);
	    }
	  }
	}
      }
    }
    return flag;
  }
  vi table;
  
  void Reach() {
    table.assign(n, 0);
    auto dfs = [&](auto self, int v, int p) ->void{
      table[v] = 1;
      for(auto next: node[v].edge) {
	int w = next.to;
	if(w == p) continue;
	if(table[w] == 0) self(self, w, v);
      }
    };
    dfs(dfs, n-1, -1);
  }
  
};

int main()
{
  int n,m;
  ll p;
  cin >> n >> m >> p;
  vi a(m),b(m);
  vl c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    c[i] = -(c[i] - p);
  }
  
  Graph<ll> gp(n, m, a, b, c);
  bool f = gp.bellmanford(0);
  if(!f) {
    Graph<ll> gp2(n, m, b, a);
    gp2.Reach();
    for(auto val: gp.st) {
      if(gp2.table[val]) {
	cout << -1 << "\n";
	return 0;
      }
    }
    cout << max((ll)0, -gp.d[n-1]) << "\n";
  }
  else {
    cout << max((ll)0, -gp.d[n-1]) << "\n";
  }
  return 0;
}
