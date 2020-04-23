class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<int>> edge;// 辺

  vector<bool> visited;
  vector<bool> visiting;
  vector<int> top;
  vector<bool> used;
  
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){ n = _n; edge.resize(n);  }
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b){
    n = _n;m = _m;edge.resize(n);
    rep(i,m){
      add_edge(a[i], b[i]);
      //      add_edge(b[i], a[i]); //無向辺
    }
  }  

  // 辺の追加 コストなし
  void add_edge(int from,int to){ edge[from].push_back(to);}

  void top_dfs(int v) {
    if(used[v]) return ;
    used[v] = true;
    for(auto w: edge[v]) {
      top_dfs(w);
    }
    top.push_back(v);
  }
  
  // トポロジカルソート
  vois t_sort() {
    used.resize(n, false);
    rep(i,n) { top_dfs(i); }
    reverse(top.begin(), top.end());
  }

  int GetDepth(int v) { return depth[v]; }
  
};
