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
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// xの約数を列挙する.返り値はvector.O(sqrt(x))
vector<int> divisor(int x){
  vector<int> res;
  for(int i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(x/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}


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
  vector<Edge<X>> edge, rev;
  
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
      add_rev(to[i], from[i]);      
    }
  }  

  // edges have weight
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
      //      add_edge(to[i], from[i], cost[i]);
      add_rev(to[i], from[i], cost[i]);            
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void add_rev(int from, int to, X cost = 1) {
    node[from].rev.emplace_back(from, to, cost);
  }
  
  vi cmp; // 属する強連結成分のトポロジカル順序 cmp[v] = x なら頂点v はx 番目
  vi siz;
  void scc() {
    vector<bool> used(n, false);
    vi vs; // 帰りがけ順の並び
    auto dfs = [&](auto self, int v) ->void{
      used[v] = true;
      for(auto next: node[v].edge) {
	int w = next.to;
	if( !used[w] ) self(self, w);
      }
      vs.push_back(v);
    };

    rep(v, n) {
      if( !used[v] ) dfs(dfs, v);
    }
    used.assign(n, false);
    cmp.resize(n);
    int mx = -1;
    auto rdfs = [&](auto self, int v, int k) ->void{
      used[v] = true;
      cmp[v] = k;
      chmax(mx, k);
      for(auto next: node[v].rev) {
	int w = next.to;
	if( !used[w] ) self(self, w, k);
      }
    };    

    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
      if( !used[vs[i]] ) rdfs(rdfs, vs[i], j++);
    }
    
    // sccを使って何かしたいならここに書いたらいいよ
    siz.resize(mx+1, 0);
    rep(i,n) {
      siz[cmp[i]]++;
    }
  }

  void Solve(vi c) {
    scc();
    vi f(n, 0);
    int res = inf;
    rep(i,n) {
      if(f[i]) continue;
      f[i] = 1;
      int ss = siz[cmp[i]];
      chmin(res, ss);
      vi div = divisor(ss);
      vvi tab(sz(div));
      rep(j,sz(div)) {
	tab[j].resize(div[j], -1);
      }
      int id = i;
      rep(j,ss) {
	rep(k,sz(div)) {
	  if(tab[k][j%div[k]] == -1 || tab[k][j%div[k]] == c[id]) {
	    tab[k][j%div[k]] = c[id];
	  }
	  else {
	    tab[k][j%div[k]] = -100;
	  }
	}
	id = node[id].edge[0].to;
	f[id] = 1;
      }
      rep(j,sz(div)) {
	rep(k,div[j]) {
	  if(tab[j][k] > 0) {
	    chmin(res, div[j]);
	  }
	}
      }
    }
    cout << res << "\n";
  }
  
};

int main()
{
  int q; cin >> q;
  while(q-- > 0) {
    int n; cin >> n;
    vi a(n),b(n);
    rep(i,n) {
      int p; cin >> p;
      p--;
      a[i] = i;
      b[i] = p;
    }
    vi c(n);
    rep(i,n) {
      cin >> c[i]; 
    }
    Graph<int> gp(n, n, a, b);
    gp.Solve(c);
  }
  return 0;
}
