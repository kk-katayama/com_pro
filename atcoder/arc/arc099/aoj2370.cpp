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
      add_edge(to[i], from[i]);
      add_rev(to[i], from[i]);
      add_rev(from[i], to[i]);            
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
  int mx;
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
    auto rdfs = [&](auto self, int v, int k) ->void{
      used[v] = true;
      cmp[v] = k;
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
    mx = 0;
    rep(i,n) {
      chmax(mx, cmp[i]);
    }
  }

  void Solve() {
    scc();

    vi col(n, 0);
    auto dfs = [&](auto self, int v, int c)-> bool{
      bool res = true;
      col[v] = c;
      for(auto next: node[v].edge) {
	int w = next.to;
	if(col[w] == 0) res = self(self, w, -c) & res;
	if(col[w] == c) res = false;
      }
      return res;
    };

    bool f = false;
    rep(i,n) {
      if(col[i] == 0) {
	if(! (dfs(dfs, i, 1)) ) {
	  f = true;
	}
      }
    }

    if(f) {
      cout << -1 << "\n";
      return ;
    }

    vvl ss(mx+1, vl(2, 0));
    rep(i,n) {
      if(col[i] == 1) ss[cmp[i]][0]++;
      else ss[cmp[i]][1]++;
    }

    map<ll,ll> mp;
    rep(i,mx+1) {
      mp[abs(ss[i][0] - ss[i][1])]++;
    }
    
    vl dp1(2*n+1, 0);
    dp1[0] = 1;
    for(auto val: mp) {
      auto [a, b] = val;
      //      cout << a << " " << b << "\n";
      vl dp2(2*n+1, 0);
      rep(i,2*n+1) {
	if(a == 0) {
	  dp2 = dp1;
	  break;
	}
	if(i - 2*a >= 0) {
	  dp2[i] = dp2[i-2*a] + dp1[abs(i+b*a)] - dp1[abs(i-(b+2)*a)];
	}
	else {
	  rep(j, b+1) {
	    dp2[i] += dp1[abs(i+a*(b-2*j))];
	  }
	}
      }
      swap(dp1, dp2);
    }
    
    // map<ll,int> dp1;
    // dp1[0] = 1;
    // rep(i,mx+1) {
    //   map<ll,int> dp2;
    //   for(auto val: dp1) {
    // 	auto [a, b] = val;
    // 	dp2[a + ss[i][0]] = 1;
    // 	dp2[a + ss[i][1]] = 1;
    //   }
    //   swap(dp1, dp2);
    // }

    ll res = 0;
    ll nn = n;
    rep(i,2*n+1) {
      //      cout << i << ":" << dp1[i] << "\n";
      if(dp1[i]) {
	ll ii = i;
	chmax(res, (nn*nn - ii*ii)/4 - m);
      }
    }
    cout << res << "\n";
  }
  
};

int main()
{
  int n,m; cin >> n >> m;
  vi a(m),b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Graph<int> gp(n, m, a, b);
  gp.Solve();
  
  return 0;
}
