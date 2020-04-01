#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll m;
class Tree {
private:
  int n; // 頂点数
  vector<vector<int>> edge; // 重み無し有向辺

  map<pair<int,int>,int> index_all; // 辺と全体辺番号(辺全体の通し番号)の対応
  map<pair<int,int>,int> index_local; // 辺と局所辺番号(ある頂点から伸びる辺の通し番号)の対応

  // 根付き木の情報
  const int MAX_LOGN = 1; // n = 10^5 程度のとき、MAX_LOGN = 20
  vector<int> size; // size[i] := iを根とする部分木のサイズ
  vector<vector<int>> par; // par[v][i] := 頂点vから2^i回たどった親
  vector<int> depth; // depth[i] := 頂点iの深さ

  vector<vector<ll>> rsum, lsum, arr;
  vector<ll> dp;
  vector<bool> f, ff;
  
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
      res += dfs_init(w, v, d + 1);
    }
    return size[v] = res;
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
    //    fill_table(); // LCA用のテーブル
    rep(root,n) rep(i, edge[root].size()){ // 局所辺番号
      index_local[{root, edge[root][i]}] = i;
    }
  }

  // 最小共通祖先(LCA)
  int lca(int u,int v){//Lowest Common Ancestor of u and v
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=MAX_LOGN - 1;i >= 0;--i){
      if( ((depth[v]-depth[u])>>i)&1 ) v = par[v][i];
    }
    if(u==v) return u;
    for(int i = MAX_LOGN - 1;i >= 0;--i){
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

  ll dfs(int p, int root) {
    int index;
    if(p != -1){
      index = index_all[{p, root}];
      if(f[index]) return dp[index];
      f[index] = true;
    }
    ll res = 1;
    if(ff[root]) {
      int inlo = index_local[{root, p}];
      res = (res * lsum[root][inlo]) % m;
      res = (res * rsum[root][inlo + 1]) % m;
      return res;
    }
    rep(i,edge[root].size()) {
      int v = edge[root][i];
      if(v == p) continue;
      ll x = (dfs(root, v) + (ll)1) % m;
      res = ( res * x ) % m;
      if(p == -1) arr[root][i] = x;
    }
    if(p == -1) {
      rep(i,edge[root].size()) lsum[root][i+1] = ( lsum[root][i] * arr[root][i]) % m;
      for(int i = edge[root].size();i > 0;--i){
	rsum[root][i-1] = ( rsum[root][i] * arr[root][i-1] ) % m;
      }
    }
    
    if(p == -1) {
      ff[root] = true;
      return res;
    }
    return dp[index] = res;
  }

  void init_sum(){
    arr.resize(n);
    lsum.resize(n);
    rsum.resize(n);
    rep(i,n) {
      arr[i].resize(edge[i].size());
      lsum[i].resize(edge[i].size() + 1);
      lsum[i][0] = 1;
      rsum[i].resize(edge[i].size() + 1);
      rsum[i][(int)edge[i].size()] = 1;
    }
  }
  void solve(){
    dp.resize(2 * ( n - 1 ));
    f.resize(n, false);
    ff.resize(n, false);    
    init_sum();
    vector<ll> res(n);
    vector<int> perm(n);
    rep(i,n) perm[i] = i;
    sort(perm.begin(), perm.end(),
    	 [&](int a,int b){
    	   return edge[a].size() > edge[b].size();
    	 });
    rep(i,n) res[perm[i]] = dfs(-1, perm[i]);
    rep(i,n) cout << res[i] << "\n";
  }
  
};

int main()
{
  int n;cin >> n >> m;
  vector<int> x(n-1),y(n-1);
  rep(i,n-1){
    cin >> x[i] >> y[i];
    x[i]--;y[i]--;
  }
  
  Tree tr(n,x,y);
  tr.init(0);
  tr.solve();
  
  return 0;
}
