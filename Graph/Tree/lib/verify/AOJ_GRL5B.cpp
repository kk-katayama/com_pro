#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;
  int idx;
  
  Edge() = default;

  Edge(int from, int to, X cost, int idx) : from(from), to(to), cost(cost), idx(idx) {
  }
};

template <typename X>
struct Node{
  int idx;
  int par;
  X depth;
  vector<Edge<X>> edge;
  vector<X> dp;
  map<int,int> to_index;
  int cnt;
  vector<X> lsum;
  vector<X> rsum;
  bool flag;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
    cnt = 0;
    flag = false;
  }

  void Make_to_index() {
    rep(i,edge.size()) {
      to_index[edge[i].to] = i;
    }
    to_index[idx] = edge.size();
  }

  void Make_Sum(X id) {
    lsum.resize(edge.size() + 1, id);
    rsum.resize(edge.size() + 1, id);    
    rep(i,edge.size()) {
      lsum[i+1] = max(lsum[i], dp[i]);
    }
    for (int i = edge.size(); i > 0; --i) {
      rsum[i-1] = max(rsum[i], dp[i]);
    }
  }

  void Show() {
    rep(i,lsum.size()) cout << lsum[i] << " ";
    cout  << "\n";
    rep(i,rsum.size()) cout << rsum[i] << " ";
    cout  << "\n";    
  }
  
};

template <typename X>
class Tree{
private:
  int n; // number of node
  vector<Node<X>> node;

public:
  Tree() = default;

  Tree(int n) : n(n) {
    rep(i,n) node.emplace_back(i);
  }

  Tree(int n, vector<int> a, vector<int> b) : n(n) {
    rep(i,n) node.emplace_back(i);
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
  }

  Tree(int n, vector<int> a, vector<int> b, vector<X> c) : n(n) {
    rep(i,n) node.emplace_back(i);
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);  // indirected edge
    }
  }  

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost, node[from].edge.size());
  }

  void DFS_Init(int v, int p, int d) {
    node[v].par = p;
    node[v].depth = d;
    for(auto next: node[v].edge) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      DFS_Init(w, v, d + cost);
    }
  }

  void Init_Node(int root) {
    DFS_Init(root, -1, 0);
    rep(i,n) {
      node[i].dp.resize(node[i].edge.size() + 1, -1);
    }
    rep(i,n) node[i].Make_to_index();
  }

  X DFS(int root, int par) {
    int index = node[par].to_index[root];
    if(node[par].dp[index] >= 0) return node[par].dp[index];
    // 累積和が完成している
    if(node[root].flag) {
      if(node[root].cnt == node[root].edge.size()) {
	if(node[root].cnt == 0) return 0;
	int index2 = node[root].to_index[par];
	if(index2 == node[root].edge.size()) { // v == p
	  return node[root].lsum[node[root].cnt+1];
	}
	else {
	  return node[par].dp[index] = max(node[root].lsum[index2], node[root].rsum[index2+1]);
	}
      }
    }
    else {

    }
    X res = 0;
    for(auto next: node[root].edge) {
      int w = next.to;
      if(w == par) continue;
      X cost = next.cost;
      chmax(res, DFS(w, root) + cost);
    }
    node[par].cnt++;
    if(index == node[par].edge.size()) node[par].dp[index] = res;
    else node[par].dp[index] = res + node[par].edge[index].cost;
    if(node[par].cnt == node[par].edge.size()) {
      node[par].Make_Sum(0);
      cout << "***" << par << "\n";
      rep(i,node[par].dp.size()) cout << node[par].dp[i] << " ";
      cout << "\n";
    }    
    return node[par].dp[index];    
  }

  

  
  void Show() {
    rep(i,n) {
      for(auto next: node[i].edge) {
	cout << next.idx << " ";
      }
      cout << "\n";
    }
  }
  
};
int main()
{
  int n;cin >> n;
  vector<int> a(n-1), b(n-1), c(n-1);
  rep(i,n-1) cin >> a[i] >> b[i] >> c[i];

  Tree<int> tr(n, a, b, c);
  tr.Init_Node(0);
  rep(i,n) {
    cout << tr.DFS(i, i) << "\n";
  }
  
  return 0;
}
