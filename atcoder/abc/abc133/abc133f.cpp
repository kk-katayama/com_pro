#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
//*******************************************************
// Tree
//*******************************************************
const int M = 20;
// status of edge
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;
  int idx;
  
  Edge() = default;

  Edge(int from, int to, int idx, X cost) : from(from), to(to), idx(idx), cost(cost) {}
};

//status of node
template <typename X>
struct Node{
  using pi = pair<int,X>;
  using pii = pair<pi,int>;
  int idx;
  int par[M+1];
  int depth;
  X dist; 
  vector<Edge<X>> edge;
  vector<pii> fro;
  vector<pii> bac;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
  }
  
};

// tree
template <typename X>
class Tree{
private:
  int n; // number of node
  vector<Node<X>> node;

  void Init_Node() {
    rep(i,n) node.emplace_back(i);    
  }
  
public:
  Tree() = default;

  explicit Tree(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Tree(int n, vector<int> a, vector<int> b) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
  }

  Tree(int n, vector<int> a, vector<int> b, vector<int> c, vector<X> d) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i], d[i]);
      add_edge(b[i], a[i], c[i], d[i]);  // indirected edge
    }
  }  

  void add_edge(int from, int to, int idx, X cost) {
    node[from].edge.emplace_back(from, to, idx, cost);
  }

  void DFS_Init(int v, int p, X dis, int dep) {
    node[v].par[0] = p;
    node[v].depth = dep;
    node[v].dist = dis;
    for(auto next: node[v].edge) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      DFS_Init(w, v, dis + cost, dep + 1);
    }
  }

  void Fill_Table() {
    rep(i,M-1) {
      rep(j,n) {
	if(node[j].par[i] == -1) node[j].par[i+1] = -1;
	else node[j].par[i+1] = node[node[j].par[i]].par[i];
      }
    }
  }
  
  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0, 0);
    Fill_Table();
  }
  
  int LCA(int u, int v) {
    if(node[u].depth > node[v].depth) swap(u, v);
    for (int i = M-1; i >= 0; --i) {
      if( ( (node[v].depth - node[u].depth) >> i) & 1) {
	v = node[v].par[i];
      }
    }
    if(u == v) return u;
    
    for (int i = M-1; i >= 0; --i) {
      if(node[u].par[i] != node[v].par[i]) {
	u = node[u].par[i];
	v = node[v].par[i];
      }
    }
    return node[u].par[0];
  }

  X Distance(int u, int v) {
    int w = LCA(u, v);
    return node[u].dist + node[v].dist - node[w].dist*2;
  }

  // abc133f
  vector<X> sum;
  vector<X> num;
  vector<X> res;
  
  void Show() {
    rep(i,n) cout << sum[i] << " ";
    cout  << "\n";
  }
  
  void DFS(int v, int p, int idx, X cost) {
    sum[idx] += cost;
    num[idx]++;
    for(auto next: node[v].edge) {
      int nv = next.to;
      int nidx = next.idx;
      X ncost = next.cost;
      if(nv == p) continue;
      DFS(nv, v, nidx, ncost);
    }
    for(auto w: node[v].bac) {
      int color = w.first.first;
      X ny = w.first.second;
      int qidx = w.second;      
      res[qidx] += -sum[color] + num[color]*ny;
    }
    for(auto w: node[v].fro) {
      int color = w.first.first;
      X ny = w.first.second;
      int qidx = w.second;      
      res[qidx] -= 2*( -sum[color] + num[color]*ny);
    }    
    sum[idx] -= cost;
    num[idx]--;
  }
  
  void Solve(vector<int> x, vector<X> y, vector<int> u, vector<int> v) {
    rep(i,x.size()) {
      node[u[i]].bac.push_back({{x[i], y[i]}, i});
      node[v[i]].bac.push_back({{x[i], y[i]}, i});      
      node[LCA(u[i], v[i])].fro.push_back({{x[i], y[i]}, i});      
    }
    sum.assign(n, 0);
    num.assign(n, 0);
    res.assign(x.size(), 0);
    DFS(0, -1, n-1, 0);
    rep(i,u.size()) {
      res[i] += Distance(u[i], v[i]);
      cout << res[i] << "\n";
      //           cout << Distance(u[i], v[i]) << "\n";
      //      cout << LCA(u[i], v[i]) << "\n";
      //      node[LCA(u[i], v[i])].idx = 1;
    }
  }

};

int main()
{
  int n,q; cin >> n >> q;
  vector<int> a(n-1), b(n-1), c(n-1);
  vector<ll> d(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--; c[i]--;
  }
  vector<int> x(q), u(q), v(q);
  vector<ll> y(q);
  rep(i,q) {
    cin >> x[i] >> y[i] >> u[i] >> v[i];
    x[i]--; u[i]--; v[i]--;
  }
  
  Tree<ll> tr(n, a, b, c, d);
  tr.Make_root(0);
  tr.Solve(x, y, u, v);
  return 0;
}
