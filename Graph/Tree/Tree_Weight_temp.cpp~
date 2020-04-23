class Tree {
private:
  int n; // 頂点数
  vector<vector<int>> edge; // 重み無し有向辺

  map<pair<int,int>,int> index_all; // 辺と全体辺番号(辺全体の通し番号)の対応
  map<pair<int,int>,int> index_local; // 辺と局所辺番号(ある頂点から伸びる辺の通し番号)の対応

  // 根付き木の情報
  const int MAX_LOGN = 20; // n = 10^5 程度のとき、MAX_LOGN = 20
  vector<int> size; // size[i] := iを根とする部分木のサイズ
  vector<vector<int>> par; // par[v][i] := 頂点vから2^i回たどった親
  vector<int> depth; // depth[i] := 頂点iの深さ
  
public:
  // コンストラクタ
  Tree(int _n, vector<int> a, vector<int> b) {
    n = _n;
    edge.resize(n);
    rep(i,n-1) {
      add_edge(a[i], b[i], i);
      add_edge(b[i], a[i], i + n - 1);
    }
  }

  // 辺の追加。from->toの辺。numは全体辺番号。
  void add_edge(int from, int to, int num) {
    edge[from].push_back(to);
    index_all[{from, to}] = num;
  }

  // size, par[i][0], depthを埋める。頂点v, 親p, 深さd
  int dfs_init(int v, int p, int d) {
    par[v][0] = p;
    depth[v] = d;
    int res = 1;
    for(auto w:edge[v]) {
      if(w == p) continue;
      res += dfs(w, v, d + 1);
    }
    return size[w] = res;
  }

  // LCA用のテーブル作成
  void fill_table() {
    rep(i,MAX_LOGN-1) {
      rep(j,n) {
	if(par[j][i] == -1) par[j][i+1] = -1;
	else par[j][i+1] = par[ par[j][i] ][i];
      }
    }
  }

  // 初期化。根sの根付き木。
  void init(int s) {
    par.resize(n, vector<int>(MAX_LOGN));
    depth.resize(n);
    size.resize(n);
    dfs_init(s, -1, 0);
    fill_table(); // LCA用のテーブル
    rep(root,n) rep(i, edge[root].size()){ // 局所辺番号
      index_local[{root, edge[root][i]}] = i;
    }
  }

  // 最小共通祖先(LCA)
  int lca(int u,int v){//Lowest Common Ancestor of u and v
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=max_log_n-1;i>=0;--i){
      if( ((depth[v]-depth[u])>>i)&1 ) v = par[v][i];
    }
    if(u==v) return u;
    for(int i=max_log_n-1;i>=0;--i){
      if(par[u][i]!=par[v][i]){
	u = par[u][i];
	v = par[v][i];
      }
    }
    return par[u][0];
  }

  // 頂点uとvの距離
  int distance(int u, int v) {
    int w = lca(u, v);
    return depth[u] + depth[v] - depth[w]*2;
  }
  
};
