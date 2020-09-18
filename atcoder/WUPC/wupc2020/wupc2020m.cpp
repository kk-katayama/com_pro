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
//*******************************************************
// Rerooting tree
//*******************************************************

//status of tree
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;
  int idx; // edge id
  
  Edge() = default;

  Edge(int from, int to, X cost, int idx) : from(from), to(to), cost(cost), idx(idx) {}
};

// status of node
template <typename X>
struct Node{
  int idx;
  int par;
  X depth;
  vector<Edge<X>> edge; 
  map<int,int> to_index; // key: edge.to, value: edge.idx
  vector<X> dp, dp2; 
  vector<X> lsum, rsum, lsum2, rsum2;
  int cnt; // number of filled dp table
  X l;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
    cnt = 0;
  }

  void Init_DP() {
    dp.resize(edge.size(), -1);
    dp2.resize(edge.size(), -1);    
  }

  // if edges are filled, carry out
  void Make_to_index() {
    rep(i,edge.size()) {
      to_index[edge[i].to] = edge[i].idx;
    }
    to_index[idx] = -1;
    Init_DP();
  }

  // if is_full_dp == true, carry out
  void Make_Sum(X id) {
    int n = dp.size();
    lsum.resize(n+1, id);
    rsum.resize(n+1, id);
    lsum2.resize(n+1, id);
    rsum2.resize(n+1, id);    
    rep(i,n) {
      lsum[i+1] = lsum[i] + dp[i];
      lsum2[i+1] = lsum2[i] + dp2[i];      
    }
    for (int i = n; i > 0; --i) {
      rsum[i-1] = rsum[i] + dp[i-1];
      rsum2[i-1] = rsum2[i] + dp2[i-1];      
    }
  }

  bool is_full_dp() {
    return cnt == dp.size();
  }
  
};

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

  Tree(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Tree(int n, vector<int> a, vector<int> b) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
    rep(i,n) node[i].Make_to_index();    
  }

  Tree(int n, vector<int> a, vector<int> b, vector<X> c) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);  // indirected edge
    }
    rep(i,n) node[i].Make_to_index();
  }  

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost, node[from].edge.size());
  }

  void Build(vector<X> l) {
    rep(i,n) node[i].l = l[i];
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

  void Make_root(int root) {
    DFS_Init(root, -1, 0);
  }
  
  pair<X,X> ReRoot(int p, int v) {
    int index = node[p].to_index[v];
    // すでにp->vは計算した場合
    if(index != -1) if(node[p].dp[index] >= 0) return {node[p].dp[index], node[p].dp2[index]};
    if(node[v].is_full_dp()) {
      if(node[v].cnt == 0) return {0,0};
      int index2 = node[v].to_index[p];
      if(index2 == -1) {
	return {node[v].rsum[0], node[v].rsum2[0]};
      }
      else {
	node[p].dp2[index] = node[v].lsum2[index2] + node[v].rsum2[index2+1] + node[v].l;
	node[p].dp[index] = node[v].lsum[index2] + node[v].rsum[index2+1] + node[p].dp2[index];
	node[p].cnt++;
	if(node[p].is_full_dp()) {
	  node[p].Make_Sum(0);
	}
	return {node[p].dp[index], node[p].dp2[index]};
      }
    }
    X res = 0, res2 = 0;
    if(index != -1) {
      res += node[v].l;
      res2 += node[v].l;
    }
    for(auto next: node[v].edge) {
      int w = next.to;
      if(w == p) continue;
      pair<X,X> p = ReRoot(v, w);
      res += p.first + (index == -1 ? 0 : p.second);
      res2 += p.second;
    }
    
    if(index == -1) return {res, res2};
    node[p].dp[index] = res;
    node[p].dp2[index] = res2;    
    node[p].cnt++;
    if(node[p].is_full_dp()) {
      node[p].Make_Sum(0);
    }
    return {res, res2};
  }
  
};



int main()
{
  int n; cin >> n;
  vector<ll> l(n);
  rep(i,n) {
    scanf("%lld", &l[i]);	
  }

  vector<int> a(n-1), b(n-1);
  rep(i,n-1) {
    scanf("%d %d", &a[i], &b[i]);
    a[i]--; b[i]--;
  }

  Tree<ll> tr(n, a, b);
  tr.Build(l);
  tr.Make_root(0);
  rep(i,n) {
    cout << tr.ReRoot(i, i).first << "\n";
  }
  
  return 0;
}
