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

  //------------------------------------------
  // 橋を見つけるアルゴリズム
  // 橋：取り除くとグラフが非連結になる辺
  //------------------------------------------
  vector<pi> Bridge() {
    vector<int> pre(n, -1), low(n);
    int cnt = 0;
    vector<pi> res;
    auto dfs = [&](auto self, int v, int p) ->int{
		 pre[v] = cnt++;
		 low[v] = pre[v];
		 for(auto next: node[v].edge) {
		   int w = next.to;
		   if(w == p) continue;
		   if(pre[w] == -1) {
		     low[v] = min(low[v], self(self, w, v));
		     if(pre[w] == low[w]) {
		       if(v < w) res.push_back({v, w});
		       else res.push_back({w, v});
		     }
		   }
		   else {
		     low[v] = min(low[v], pre[w]);
		   }
		 }
		 return low[v];
	       };

    dfs(dfs, 0, -1);
    return res;
    
  }
  
};

int main()
{
  int n,m; cin >> n >> m;
  vi a(m),b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Graph<int> gp(n,m,a,b);
  vector<pi> res = gp.Bridge();
  cout << (int)res.size() << "\n";
  return 0;
}
