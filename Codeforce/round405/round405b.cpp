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
//*******************************************************
// Tree
//*******************************************************

// status of edge
template <typename X>
struct Edge{
  ll from;
  ll to;
  X cost;

  Edge() = default;

  Edge(ll from, ll to, X cost) : from(from), to(to), cost(cost) {}
};

//status of node
template <typename X>
struct Node{
  ll idx;
  ll par;
  X depth;
  vector<Edge<X>> edge;
  vector<ll> modk;
  
  Node() = default;

  explicit Node(ll idx) : idx(idx) {
  }
  
};

// tree
template <typename X>
class Tree{
private:
  ll n; // number of node
  vector<Node<X>> node;
  ll k;
  
  void Init_Node() {
    rep(i,n) node.emplace_back(i);    
  }
  
public:
  Tree() = default;

  explicit Tree(ll n) : n(n) {
    Init_Node();
  }

  // no-weight
  Tree(ll n, vector<ll> a, vector<ll> b) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
  }

  Tree(ll n, vector<ll> a, vector<ll> b, vector<X> c) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);  // indirected edge
    }
  }  

  void add_edge(ll from, ll to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void DFS_Init(ll v, ll p, ll d) {
    node[v].par = p;
    node[v].depth = d;
    node[v].modk.assign(k+1, 0);
    for(auto next: node[v].edge) {
      ll w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      DFS_Init(w, v, d + cost);
    }
  }

  // make rooted tree
  void Make_root(ll root) {
    DFS_Init(root, -1, 0);
  }

  ll res;

  void DFS(ll v) {
    vector<ll> modk_(k+1, 0);
    for(auto next: node[v].edge) {
      ll w = next.to;
      if(w == node[v].par) continue;
      DFS(w);
      vector<ll> modk_new(k+1, 0);
      modk_new[1 % k] = 1;
      if(k == 1) modk_new[k]++;
      res++;
      rep(i,k+1) {
	res += node[w].modk[i];
	if(i < k) modk_new[(i+1) % k] += node[w].modk[i];
      }
      modk_new[k] += node[w].modk[k] + node[w].modk[k-1];      
      rep(i,k+1) {
	rep(j,k+1) {
	  if(i == 0 && j == 0) continue;
	  if(i == k && j == k) continue;
	  if(i < k && j < k) res += modk_[i] * modk_new[j] * (max(0, i + j - 1) / k + 1);
	  else res += modk_[i] * modk_new[j];
	}
      }
      rep(i,k+1) {
	modk_[i] += modk_new[i];
      }
    }
    rep(i,k+1) {
      node[v].modk[i] = modk_[i];
    }
  }
  
  void Solve(ll _k) {
    k = _k;
    res = 0;
    Make_root(0);
    DFS(0);
    cout << res << "\n";
  }

  void Show(){
    rep(i,n) {
      cout << i << "*************" << "\n";
      for(auto val: node[i].modk) cout << val << "\n";
      }
  }
  
};

int main()
{
  ll n,k; cin >> n >> k;
  vector<ll> a(n-1),b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Tree<ll> tr(n, a, b);
  tr.Solve(k);
  //  tr.Show();
  return 0;
}
