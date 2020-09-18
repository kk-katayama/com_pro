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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
struct UFT{
  vector<int> par;//親
  vector<int> rank;//木の深さ
  vector<int> size;//木の大きさ
  int n;
  
  UFT(int _n)
  {
    n = _n;
    par.resize(n);
    rank.assign(n,0);
    size.assign(n,0);
    rep(i,n){
      par[i] = i;
    }
  }
  
  //xの根を返す
  int find(int x)
  {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  //x,yを併合
  void unite(int x,int y)
  {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank[x] < rank[y]){
      par[x] = y;
      size[y] += size[x];
    }
    else{
      par[y] = x;
      size[x] += size[y];
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  //x,yが同じグループにいるかどうかを返す
  bool same(int x,int y)
  {
    return find(x) == find(y);
  }

  //xの属する木のサイズを探す
  int usize(int x)
  {
    return size[find(x)];
  }
};
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

//***********************************************************
// Dijkstra. You should include queue lib.
//***********************************************************

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
  int idx; // index of node
  X dist; // distance from start node
  vector<Edge<X>> edge;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
  
};


template <typename X = int>
struct Status{ // entered priority_queue
  int idx;
  X dist;

  Status() = default;

  Status(int idx, X dist) : idx(idx), dist(dist) {}

  bool operator == (const Status& r) const {
    return (idx == r.idx && dist == r.dist);
  }

  bool operator != (const Status& r) const {
    return !(*this == r);
  }

  bool operator < (const Status& r) const {
    return dist > r.dist;
  }

  bool operator > (const Status& r) const {
    return dist < r.dist;
  }

};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; // node list

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }  
public:
  const X inf = 1e+9; // initial value of dist
  
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i]);
      add_edge(to[i], from[i]);      
    }
  }
  
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

  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    rep(i,n) node[i].dist = inf;
    node[s].dist = 0;
    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      if(node[v].dist < dis) continue; 
      for(auto next: node[v].edge) {
	int w = next.to;
	X cos = next.cost;
	if(chmin(node[w].dist, node[v].dist + cos)) {
	  pq.emplace(w, node[w].dist);
	}
      }
    }
  }

  void Bfs01(int s) {
    rep(i,n) node[i].dist = -1;
    node[s].dist = 0;

    deque<int> dq;
    dq.push_back(s);
    while(!dq.empty()){
      int v = dq.front();
      dq.pop_front();
      for(auto next:node[v].edge){
	int w = next.to;
	if(node[w].dist >= 0) continue;
	node[w].dist = node[v].dist + next.cost;
	if(next.cost == 0) dq.push_front(w);
	else dq.push_back(w);
      }
    }
  }
  
  

  X Get_d(int v) { return node[v].dist; }
  X Get_inf() { return inf; }
  
};

int main()
{
  int h,w; cin >> h >> w;
  int sx,sy; cin >> sx >> sy;
  sx--;sy--;
  int gx,gy; cin >> gx >> gy;
  gx--;gy--;
  vector<string> s(h);
  rep(i,h) cin >> s[i];


  Graph<int> gp(h*w);  
  UFT uf(h*w);
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == '#') continue;
      rep(k,4) {
	int ni = i + dx[k], nj = j + dy[k];
	if(0 <= ni && ni < h && 0 <= nj && nj < w) {
	  if(s[ni][nj] == '.') {
	    uf.unite(i*w + j, ni*w + nj);
	    gp.add_edge(i*w + j, ni*w + nj, 0);
	    gp.add_edge(ni*w + nj, i*w + j, 0);	    
	  }
	}
      }
    }
  }
  
  rep(i,h){
    rep(j,w) {
      if(s[i][j] == '#') continue;
      rep(di,5) {
	rep(dj,5) {
	  int ni = i + di - 2 , nj = j + dj - 2;
	  if(0 <= ni && ni < h && 0 <= nj && nj < w) {	  
	    if(uf.same(i*w + j, ni*w + nj)) continue;
	    if(s[ni][nj] == '.') {
	      gp.add_edge(i*w + j, ni*w + nj, 1);
	      gp.add_edge(ni*w + nj, i*w + j, 1);	    
	    }
	  }
	}
      }
    }
  }


  gp.Bfs01(sx*w + sy);
  int res = gp.Get_d(gx*w + gy);
  if(res == -1) cout << -1 << "\n";
  else cout << res << "\n";

  gp.dijkstra(sx*w + sy);
  res = gp.Get_d(gx*w + gy);
  if(res == gp.inf) cout << -1 << "\n";
  else cout << res << "\n";  
  return 0;
}
