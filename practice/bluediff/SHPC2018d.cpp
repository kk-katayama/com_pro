#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<typename X>
class Graph {
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<pair<int,X>>> edge; // 重み付き有向辺
  vector<vector<X>> d;// d[i][j] := 頂点iから頂点jの最短距離
  const X inf = 1e+17;
public:
  Graph(int _n, int _m, vector<int> a, vector<int> b, vector<X> c) {
    n = _n;
    m = _m;
    edge.resize(n);
    rep(i,m) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);      
    }
    d.resize(n);
  }

  void add_edge(int from, int to, X cost) {
    edge[from].push_back( {to, cost} );
  }

  void dijkstra(int s) {
    d[s].resize(n, inf);
    d[s][s] = 0;
    priority_queue< pair<X,int>, vector<pair<X,int>>, greater<pair<X,int>> > pq;
    pq.push( {0, s} );
    while( !pq.empty() ) {
      pair<X,int> p = pq.top(); pq.pop();
      int v = p.second;
      if( d[s][v] < p.first ) continue;
      for(auto w : edge[v]) {
	int t = w.first; // 頂点wから頂点tに向かう
	X c = w.second; // w -> t のコストがc
	if( d[s][t] > d[s][v] + c) {
	  d[s][t] = d[s][v] + c;
	  pq.push( {d[s][t], t} );
	}
      }
    }
  }

  X get_d(int u, int v) {
    return d[u][v];
  }
  
};
int main()
{
  int n,m,s,t;cin >> n >> m >> s >> t;
  s--; t--;
  vector<int> u(m), v(m);
  vector<ll> a(m), b(m);
  rep(i,m) {
    cin >> u[i] >> v[i] >> a[i] >> b[i];
    u[i]--; v[i]--;
  }
  
  Graph<ll> gpen(n, m, u, v, a);
  Graph<ll> gpsn(n, m, u, v, b);

  gpen.dijkstra(s);
  gpsn.dijkstra(t);

  vector<ll> res(n);
  rep(i,n) {
    res[i] = gpen.get_d(s, i) + gpsn.get_d(t, i);
  }

  ll M = 1e+15;
  ll tmp = M;
  vector<ll> ans(n);
  for(int i = n - 1;i >= 0;--i) {
    tmp = min(tmp, res[i]);
    ans[i] = M - tmp;
  }

  rep(i,n) cout << ans[i] << "\n";
  
  return 0;
}
