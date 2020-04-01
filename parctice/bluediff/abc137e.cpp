#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<typename X>
class Graph {
private:
  int n;
  int m;
  vector<vector<pair<int,X>>> edge;
  
  vector<X> d;
  const X inf = 1e+9;

  set<int> node;
  vector<vector<int>> rev;
  vector<bool> visit;
  bool f;
public:
  Graph(int _n, int _m, vector<int> a, vector<int> b, vector<X> c) {
    n = _n;
    m = _m;
    edge.resize(n);
    rev.resize(n);
    rep(i, m) {
      add_edge(a[i], b[i], c[i]);
      add_rev(b[i], a[i]);
    }
  }

  void add_rev( int from, int to) {
    rev[from].push_back(to);
  }  
  
  void add_edge( int from, int to, X cost ) {
    edge[from].push_back( { to, cost } );
  }

  //ベルマンフォード法。頂点sから全頂点への最短距離。負閉路を見つけるとfalseを返す。
  bool bellmanford(int s){
    d.assign( n, inf );
    d[s] = 0;
    bool flag = true;
    rep( i, n ) {
      rep( v, n ) {
	if( d[v] == inf ) continue;
	for( auto w : edge[v] ) {
	  if( d[w.first] > d[v] + w.second ) {
	    d[w.first] = d[v] + w.second;
	    if( i == n - 1 ) {
	      flag = false;
	      node.insert(w.first);
	    }
	  }
	}
      }
    }
    return flag;
  }

  void dfs(int v) {
    visit[v] = true;
    if(node.find(v) != node.end()) f = true;
    for(auto w : rev[v]) {
      if(!visit[w]) dfs(w);
    }
  }
  
  bool check_connect() {
    f = false;
    visit.resize(n, false);
    dfs(n - 1);
    return f;
  }
  
  X get_d(int v) { return d[v]; }
  
  
};
int main()
{
  int n,m;cin >> n >> m;
  ll p;cin >> p;
  vector<int> a(m), b(m);
  vector<ll> c(m);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    c[i] = - c[i] + p;
  }    

  Graph<ll> gp(n, m, a, b, c);
  if( !gp.bellmanford(0) ) {
    if(gp.check_connect()) cout << -1 << "\n";
    else cout << max (-gp.get_d(n - 1), (ll)0) << "\n";
  }
  else cout << max (-gp.get_d(n - 1), (ll)0) << "\n";
  
  return 0;
}
