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
#define sz(v) (int)v.size()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  // トポロジカルソートした頂点の配列を返す
  int Tsort() {
    // 入次数のカウント
    vector<int> in(n, 0);
    rep(i,n) {
      for(auto next: node[i].edge) {
	int w = next.to;
	in[w]++;
      }
    }

    queue<pi> q; // 頂点を入れるキュー
    rep(i,n) {
      if(in[i] == 0) q.push({i,0});
    }

    vector<int> res;
    int cnt = 0;
    
    while( !q.empty() ) {
      auto [v, c] = q.front(); q.pop();
      res.push_back(v);
      chmax(cnt, c);
      for(auto next: node[v].edge) {
	int w = next.to;
	in[w]--;
	if(in[w] == 0) {
	  q.push({w,c+1});
	}
      }
    }

    rep(i,n) {
      if(in[i] != 0) {
	// DAGでなかった
	return -2;
      }
    }
    
    return cnt;
  }
  
};

int main()
{
  int n; cin >> n;
  map<pi,int> mp;
  int id = 0;
  rep1(i,n-1) {
    for(int j = i+1; j <= n; ++j) {
      mp[{i, j}] = id++;
    }
  }

  Graph<int> gp(id);
  
  rep1(i,n) {
    vi a(n-1);
    rep(j,n-1) {
      cin >> a[j];
      if(j > 0) {
	gp.add_edge(mp[{min(i, a[j-1]), max(i, a[j-1])}], mp[{min(i, a[j]), max(i, a[j])}]);
      }
    }
  }

  int c = gp.Tsort();
  cout << c+1 << "\n";
  
  return 0;
}
