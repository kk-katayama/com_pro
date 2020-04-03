// Dijkstra
template<typename X>
class Graph {
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<pair<int,X>>> edge; // 重み付き有向辺
  vector<vector<X>> d;// d[i][j] := 頂点iから頂点jの最短距離
  const X inf = 1e+17; // dの初期値
public:
  Graph(int _n, int _m, vector<int> a, vector<int> b, vector<X> c) {
    n = _n;
    m = _m;
    edge.resize(n);
    rep(i,m) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]); // 無向グラフ
    }
    d.resize(n);
  }

  void add_edge(int from, int to, X cost) {
    edge[from].push_back( {to, cost} );
  }

  void dijkstra(int s) { // 頂点sから全頂点への最短距離を求める
    d[s].resize(n, inf);
    d[s][s] = 0;
    priority_queue< pair<X,int>, vector<pair<X,int>>, greater<pair<X,int>> > pq; // 優先キュー {距離, 頂点} で距離の小さい順に並ぶ 
    pq.push( {0, s} );
    while( !pq.empty() ) {
      pair<X,int> p = pq.top(); pq.pop();
      int v = p.second;
      if( d[s][v] < p.first ) continue;
      for(auto w : edge[v]) {
	int t = w.first; // 頂点wから頂点tに向かう
	X c = w.second; // w -> t のコストがc
	if( d[s][t] > d[s][v] + c) { // 更新されればキューにぶちこむ
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
