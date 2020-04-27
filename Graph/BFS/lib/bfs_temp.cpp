class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<int>> edge;// 辺
  vector<vector<int>> d;
  
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){ n = _n; edge.resize(n);  }
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b){
    n = _n;m = _m;edge.resize(n);
    rep(i,m){
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]); //無向辺
    }
    d.resize(n);
  }  
  
  // 辺の追加 コストなし
  void add_edge(int from,int to){ edge[from].push_back(to);}

  void bfs(int s) {
    d[s].resize(n, -1);
    queue<int> q;
    d[s][s] = 0;
    q.push(s);
    while( !q.empty() ) {
      int v = q.front();
      q.pop();
      for(auto w: edge[v]) {
	if(d[w] >= 0) continue;
	d[w] = d[v] + 1;
	q.push(w);
      }
    }
  }
};
