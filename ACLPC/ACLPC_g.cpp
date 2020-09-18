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
vi table;
vii group;

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
public:  
  //private:
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

  Graph<X> scc() {
    Graph<X> gp(n);
    table.resize(n);
    group.resize(n);
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
	gp.add_edge(nv, w);
      }
    }

    rep(i,n) {
      group[table[i]].push_back(i);
    }
    
    return gp;
  }

  // トポロジカルソート
  vector<int> t_sort() {
    vector<int> in; //入次数
    vector<int> depth; // トポロジカルソートしたときの深さ

    in.resize(n,0);
    depth.resize(n);
    rep(v,n) for(auto next : node[v].edge) {
      int w = next.to;
      if(w != table[w]) continue;      
      in[w]++; // 全ての頂点の入次数をカウント
    }

    queue<int> q;
    rep(i,n) {
      if(i != table[i]) continue;
      if(in[i] == 0) { // 入次数が0の頂点はスタート地点になる
	q.push(i);
	depth[i] = 0;
      }
    }

    vector<int> res;
    while(!q.empty()) {
      int v = q.front(); q.pop();
      res.push_back(v);
      for(auto next : node[v].edge) {
	int w = next.to;
	in[w]--; // 入次数が0の頂点から伸びた先の頂点の入次数を1減らす
	if(in[w] == 0) {
	  q.push(w);
	  depth[w] = depth[v] + 1;
	}
      }
    }

    return res;
  }
  
  
};


int main()
{
  int n,m; cin >> n >> m;
  vector<int> a, b;
  rep(i,m) {
    int aa, bb;
    scanf("%d %d", &aa, &bb);
    if(aa == bb) {
      continue;
    }
    a.push_back(aa);
    b.push_back(bb);
  }

  Graph<int> gp(n, a.size(), a, b);
  Graph<int> gp2 = gp.scc();
  vi ts = gp2.t_sort();

  rep(i,n) {
    cout << i << "\n";
    cout << table[i] << "\n";
    for(auto next: gp2.node[i].edge) {
      cout << next.to << " ";
    }
    cout << "*****" << "\n";
  }
  
  cout << ts.size() << "\n";
  rep(i,ts.size()) {
    cout << group[ts[i]].size() << " ";
    for(auto val: group[ts[i]]) cout << val << " ";
    cout << "\n";
  }
  return 0;
}
