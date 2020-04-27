#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
// Dijkstra
template<typename X>
class Graph {
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<pair<int,pair<X,int>>>> edge; // 重み付き有向辺
  vector<vector<vector<X>>> d;// d[i][j] := 頂点iから頂点jの最短距離
  const X inf = 1e+17; // dの初期値
  vector<pair<X,int>> kk;
public:
  Graph(int _n, int _m, vector<int> a, vector<int> b, vector<X> c, vector<int> d) {
    n = _n;
    m = _m;
    edge.resize(n);
    rep(i,m) {
      add_edge(a[i], b[i], c[i], d[i]);
      add_edge(b[i], a[i], c[i], d[i]); // 無向グラフ
    }
  }

  void add_edge(int from, int to, X cost, int money) {
    edge[from].push_back( {to, {cost, money}} );
  }

  void init(vector<X> c, vector<int> d) {
    kk.resize(n);
    rep(i,n) kk[i] = {c[i], d[i]};
  }

  
  void dijkstra(int s, int g) { // 頂点sから全頂点への最短距離を求める
    d.resize(n);
    d[s].resize(n, vector<X>(2501, inf));
    chmin(g, 2500);
    d[s][s][g] = 0;
    priority_queue< pair<X,pair<int,int>>, vector<pair<X,pair<int,int>>>, greater<pair<X,pair<int,int>>> > pq; // 優先キュー {距離, {頂点, 銀貨}} で距離の小さい順に並ぶ 
    pq.push({0, {s, g}});
    while( !pq.empty() ) {
      pair<X,pair<int,int>> p = pq.top(); pq.pop();
      X dist = p.first; // 
      int v = p.second.first; // 頂点
      int gold = p.second.second; // 銀貨
      if( d[s][v][gold] < dist ) continue;
      int to = min(2500, gold + kk[v].second);
      if(d[s][v][to] > d[s][v][gold] + kk[v].first) {
	d[s][v][to] = d[s][v][gold] + kk[v].first;
	pq.push({d[s][v][to], {v, to}});
      }
      for(auto w : edge[v]) {
	int t = w.first; // 頂点wから頂点tに向かう
	X c = w.second.first; // w -> t のコストがc
	if(w.second.second <= gold) {
	  if(d[s][t][gold - w.second.second] > d[s][v][gold] + c) { // 更新されればキューにぶちこむ
	    d[s][t][gold - w.second.second] = d[s][v][gold] + c;
	    pq.push( {d[s][t][gold - w.second.second], {t, gold - w.second.second}} );
	  }
	}
      }
    }
  }

  X get_d(int u, int v) {
    X res = inf;
    rep(i,2501) {
      chmin(res, d[u][v][i]);
    }
    return res;
  }

};


int main()
{
  int n,m,s;cin >> n >> m >> s;
  vector<int> u(m), v(m), a(m), c(n);
  vector<ll> b(m), d(n);
  rep(i,m) {
    cin >> u[i] >> v[i] >> a[i] >> b[i];
    u[i]--; v[i]--;
  }
  rep(i,n) {
    cin >> c[i] >> d[i];
  }

  Graph<ll> gp(n, m, u, v, b, a);
  gp.init(d, c);
  gp.dijkstra(0, s);
  rep1(i,n-1) {
    cout << gp.get_d(0, i) << "\n";
  }
  
  return 0;
}
