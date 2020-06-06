#include <iostream>
#include <algorithm>
#include <vector>
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
  int idx;
  
  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
  Edge(int from, int to, X cost, int idx) : from(from), to(to), cost(cost), idx(idx) {}  
};

// status of node
template <typename X>
struct Node{ 
  int idx;
  vector<Edge<X>> edge;
  int d;
  
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
      add_edge(from[i], to[i], 0, i);
      add_edge(to[i], from[i], 0, i);      
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

  void add_edge(int from, int to, X cost, int idx) {
    node[from].edge.emplace_back(from, to, cost, idx);
  }


  

  void Build(vector<int> d) {
    rep(i,n) node[i].d = d[i];
  }

  void Solve() {
    int mini = 1e+9+10;
    int start;
    rep(i,n) {
      if(chmin(mini, node[i].d)) start = i;
    }
    vector<int> res(m);
    vector<int> d(n, -1);
    d[start] = 0;
    queue<int> q;
    q.push(start);
    while( !q.empty() ) {
      int v = q.front(); q.pop();
      for(auto next: node[v].edge) {
	int w = next.to;
	int idx = next.idx;
	if(d[w] != -1) res[idx] = 1e+9;
	
      }
    }
  }
  
};


int main()
{

  return 0;
}
