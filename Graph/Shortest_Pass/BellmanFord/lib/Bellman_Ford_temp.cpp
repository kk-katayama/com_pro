template<typename X>
class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<pair<int,X>>> edge;// コスト付きの辺 edge[from][index] = {to, cost};
  vector<vector<X>> d; // d[v][w] := 頂点vから頂点wの最短距離
  const X inf = 1e+17;　// dの初期値
  
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){
    n = _n;
    edge.resize(n);
  }
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]のコストc[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b,vector<X> c){
    n = _n;
    m = _m;
    edge.resize(n);
    rep(i,m){
      edge[a[i]].push_back({b[i],c[i]});
      edge[b[i]].push_back({a[i],c[i]}); //有向グラフ
    }
    d.resize(n);
  }  

  // 辺の追加 コストあり
  void add_edge(int from,int to,X cost){ edge[from].push_back({to,cost});}

  // ベルマンフォード法。頂点sから全頂点への最短距離をO(n*m)で求める。負閉路を見つけるとfalseを返す
  bool bellmanford(int s) {
    d[s].resize(n, inf);
    d[s][s] = 0;
    bool flag = true;
    rep(i,n) {
      rep(v,n) {
	if(d[s][v] == inf) continue;
	for(auto w: edge[v]) {
	  if(d[w.first] > d[v] + w.second) {
	    d[w.first] = d[v] + w.second;
	    
	    if(i == n - 1) {
	      flag = false;
	    }
	  }
	}
      }
    }
    return flag;
  }
  
};
