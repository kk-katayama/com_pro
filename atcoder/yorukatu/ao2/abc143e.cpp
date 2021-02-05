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
  vector<vector<X>> d;
  const X infX = numeric_limits<X>::max();
  
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


  bool wf(){
    d.assign(n, vector<X>(n, infX));
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
	  if(d[i][k] == infX || d[k][j] == infX) continue;
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
  int n,m;
  ll l;
  cin >> n >> m >> l;
  vi a(m),b(m);
  vl c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  Graph<ll> gp1(n, m, a, b, c);
  gp1.wf();

  Graph<int> gp2(n);
  rep(i,n) {
    rep(j,n) {
      if(i >= j) continue;
      if(gp1.d[i][j] <= l) {
	gp2.add_edge(i, j, 1);
	gp2.add_edge(j, i, 1);
      }
    }
  }

  gp2.wf();
  int q; cin >> q;
  while(q-- > 0) {
    int s,t; cin >> s >> t;
    int res = gp2.d[s-1][t-1];
    cout << (res == inf ? -1 : res-1) << "\n";
  }
  
  return 0;
}
