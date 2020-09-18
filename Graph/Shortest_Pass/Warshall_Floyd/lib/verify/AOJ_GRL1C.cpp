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
  vector<vector<X>> d;
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


  bool wf(){
    d.assign(n, vector<X>(n, inf));
    rep(i,n) d[i][i] = 0;
    rep(v,n) {
      for(auto next: node[v].edge) {
	int w = next.to;
	int cost = next.cost;
	d[v][w] = cost;
      }
    }
    // rep(i,n) {
    //   rep(j,n) cout << d[i][j] << " ";
    //   cout << "\n";
    // }
    
    rep(k,n){
      rep(i,n){
	rep(j,n){
	  if(d[i][k] == inf || d[k][j] == inf) continue;
	  d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	}
      }
    }

    // 負閉路探索. d[i][j] < 0 なら負閉路がある.
    bool flag = true;
    rep(i,n) {
      if(d[i][i] < 0) flag = false;
    }
    return flag;
  }

  
};


int main()
{
  int n,m; cin >> n >> m;
  vi a(m), b(m);
  vl c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
  }


  
  Graph<ll> gp(n, m, a, b, c);

  if(gp.wf()) {
    rep(i,n) {
      rep(j,n) {
	if(gp.d[i][j] == gp.inf) cout << "INF";
	else cout << gp.d[i][j];
	if(j == n-1) cout << "\n";
	else cout  << " ";
      }
    }
  }
  else {
    cout << "NEGATIVE CYCLE" << "\n";
  }
  

  
  return 0;
}
