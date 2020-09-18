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

  //ベルマンフォード法。頂点sから全頂点への最短距離。負閉路を見つけるとfalseを返す。
  bool bellmanford(int s){
    d.assign(n,inf);
    d[s] = 0;
    bool flag = true;
    rep(i,n){
      rep(v,n){
	if(d[v] == inf) continue;
	for(auto next: node[v].edge){
	  int w = next.to;
	  X cos = next.cost;
	  if(d[w] > d[v] + cos){
	    d[w] = d[v] + cos;
	    if(i == n-1){
	      flag = false;
	    }
	  }
	}
      }
    }
    return flag;
  }
};

int main()
{
  int n,m,s; cin >> n >> m >> s;
  vi a(m), b(m);
  vl c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
  }

  Graph<ll> gp(n, m, a, b, c);
  if( !gp.bellmanford(s) ) {
    cout << "NEGATIVE CYCLE" << "\n";
  }
  else {
    rep(i,n) {
      if(gp.d[i] == gp.inf) cout << "INF" << "\n";
      else cout << gp.d[i] << "\n";
    }
  }
  
  

  return 0;
}
