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
    rep(i,n) chmax(mx, cmp[i]+1);
  }

  void Solve(int n1, int n2, int n3) {
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
    rep(i,n) {
      if(col[i] == 0) {
	if( !(dfs(dfs, i, 1))) {
	  cout << "NO" << "\n";
	  return ;
	}
      }
    }

    vi s(mx, 0), t(mx, 0);
    vvi svec(mx), tvec(mx);
    rep(i,n) {
      if(col[i] == 1) {
	s[cmp[i]]++;
	svec[cmp[i]].push_back(i);
      }
      else {
	t[cmp[i]]++;
	tvec[cmp[i]].push_back(i);
      }
    }

    // rep(i,mx) {
    //   cout << i << "**\n";
    //   for(auto val: tvec[i]) cout << val << " ";
    //   cout << "\n";
    // }
    
    vvl dp(mx+1, vl(n+1, 0));
    dp[0][0] = 1;
    rep(i,mx) {
      rep(j,n+1) {
	if(j + s[i] <= n) dp[i+1][j+s[i]] = dp[i+1][j+s[i]] | dp[i][j];
	if(j + t[i] <= n) dp[i+1][j+t[i]] = dp[i+1][j+t[i]] | dp[i][j];
      }
    }

    if(dp[mx][n2] == 0) {
      cout << "NO" << "\n";
      return ;
    }


    vi v1,v2;
    int nj = n2;
    for (int i = mx; i > 0; --i) {
      if(nj - s[i-1] >= 0 && dp[i-1][nj - s[i-1]] > (ll)0) {
	for(auto val: svec[i-1]) {
	  v2.push_back(val);
	}
	for(auto val: tvec[i-1]) {
	  v1.push_back(val);
	}	
	nj -= s[i-1];
      }
      else if(nj - t[i-1] >= 0 && dp[i-1][nj - t[i-1]] > (ll)0) {
	for(auto val: tvec[i-1]) {
	  v2.push_back(val);
	}
	for(auto val: svec[i-1]) {
	  v1.push_back(val);
	}	
	nj -= t[i-1];
      }      
    }

    cout << "YES" << "\n";
    vi res(n);
    for(auto val: v2) {
      res[val] = 2;
    }
    for(auto val: v1) {
      if(n1 > 0) {
	res[val] = 1;
	n1--;
      }
      else {
	res[val] = 3;
      }
    }
    rep(i,n) cout << res[i];
    cout << "\n";
  }
};

int main()
{
  int n,m; cin >> n >> m;
  int a,b,c; cin >> a >> b >> c;
  vi u(m),v(m);
  rep(i,m) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
  }

  Graph<int> gp(n, m, u, v);
  gp.Solve(a, b, c);
  
  return 0;
}
