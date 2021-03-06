#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;
  int idx;
  X f;
  
  Edge() = default;

  Edge(int from, int to, X cost, int idx, X f) : from(from), to(to), cost(cost), idx(idx), f(f) {}
};

template <typename X>
struct Node{
  int idx;
  int par;
  X depth;
  vector<Edge<X>> edge;
  map<int,int> to_index;
  vector<X> dp;
  vector<X> lsum, rsum;
  int cnt;
  vector<X> dp2;
  vector<X> lsum2, rsum2;
  int cnt2;  
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
    cnt = 0;
  }

  void Init_DP() {
    dp.resize(edge.size(), -1);
    dp2.resize(edge.size(), -1);    
  }
  
  void Make_to_index() {
    rep(i,edge.size()) {
      to_index[edge[i].to] = edge[i].idx;
    }
    to_index[idx] = -1;
    Init_DP();
   }

  void Make_Sum(X id) {
    int n = dp.size();
    lsum.resize(n+1, id);
    rsum.resize(n+1, id);
    rep(i,n) {
      lsum[i+1] = max(lsum[i], dp[i] + edge[i].cost);
    }
    for (int i = n; i > 0; --i) {
      rsum[i-1] = max(rsum[i], dp[i-1] + edge[i-1].cost);
    }
  }

  bool is_full_dp() {
    return cnt == dp.size();
  }

  void Make_Sum2(X id) {
    int n = dp2.size();
    lsum2.resize(n+1, id);
    rsum2.resize(n+1, id);
    rep(i,n) {
      lsum2[i+1] = lsum2[i] + dp2[i] + edge[i].f;
    }
    for (int i = n; i > 0; --i) {
      rsum2[i-1] = rsum2[i] + dp2[i-1] + edge[i-1].f;
    }
  }

  bool is_full_dp2() {
    return cnt2 == dp2.size();
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
      add_edge(a[i], b[i], c[i], 0);
      add_edge(b[i], a[i], c[i], 1);  // indirected edge
    }
  }  

  void add_edge(int from, int to, X cost, X f) {
    node[from].edge.emplace_back(from, to, cost, node[from].edge.size(), f);
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
    rep(i,n) node[i].Make_to_index();
  }
  
  X ReRoot(int p, int v) {
    int index = node[p].to_index[v];
    if(index != -1) if(node[p].dp[index] >= 0) return node[p].dp[index];
    if(node[v].is_full_dp()) {
      if(node[v].cnt == 0) return 0;
      int index2 = node[v].to_index[p];
      if(index2 == -1) {
	return node[v].rsum[0];
      }
      else {
	node[p].dp[index] = max(node[v].lsum[index2], node[v].rsum[index2+1]);
	node[p].cnt++;
	if(node[p].is_full_dp()) {
	  node[p].Make_Sum(0);
	}
	return node[p].dp[index];
      }
    }
    X res = 0;
    for(auto next: node[v].edge) {
      int w = next.to;
      if(w == p) continue;
      res = max(res, (ReRoot(v, w) + next.cost));
    }
    
    if(index == -1) return res;
    node[p].dp[index] = res;
    node[p].cnt++;
    if(node[p].is_full_dp()) {
      node[p].Make_Sum(0);
    }
    return res;
  }

  X ReRoot2(int p, int v) {
    int index = node[p].to_index[v];
    if(index != -1) if(node[p].dp2[index] >= 0) return node[p].dp2[index];
    if(node[v].is_full_dp2()) {
      if(node[v].cnt2 == 0) return 0;
      int index2 = node[v].to_index[p];
      if(index2 == -1) {
	return node[v].rsum2[0];
      }
      else {
	node[p].dp2[index] = node[v].lsum2[index2] + node[v].rsum2[index2+1];
	node[p].cnt2++;
	if(node[p].is_full_dp2()) {
	  node[p].Make_Sum2(0);
	}
	return node[p].dp2[index];
      }
    }
    X res = 0;
    for(auto next: node[v].edge) {
      int w = next.to;
      if(w == p) continue;
      res = res + ReRoot2(v, w) + next.f;
    }
    
    if(index == -1) return res;
    node[p].dp2[index] = res;
    node[p].cnt2++;
    if(node[p].is_full_dp2()) {
      node[p].Make_Sum2(0);
    }
    return res;
  }  
  
};

int main()
{
  int n;cin >> n;
  ll m; cin >> m;
  vector<int> a(n-1), b(n-1);
  vector<ll> c(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  Tree<ll> tr(n, a, b, c);
  tr.Init_Node(0);
  ll res = 1e+9;
  rep(i,n) {
    if(tr.ReRoot(i, i) <= m){
      chmin(res, n - 1 - tr.ReRoot2(i,i));
    }
  }
  if(res == 1e+9) cout << -1 << "\n";
  else cout << res << "\n";
  
  return 0;
}
