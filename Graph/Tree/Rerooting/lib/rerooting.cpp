#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<typename X>
class Tree {
private:
  int n; // 頂点数
  vector<vector<int>> edge; // 重み無し有向辺
  vector<vector<pair<int,X>>> wedge; // 重み付き有向辺
  vector<vector<X>> dist; // dist[i][j] := 頂点iから頂点jまでの距離
  
public:
  // コンストラクタ n頂点木  
  Tree(int _n) { 
    n = _n;
    edge.resize(n);
    wedge.resize(n);
  }
  
  // コンストラクタ　重み無し
  Tree(int _n, vector<int> a, vector<int> b) { 
    n = _n;
    edge.resize(n);
    rep(i,n-1) add_edge(a[i],b[i]);
  }

  // コンストラクタ　重みあり  
  Tree(int _n, vector<int> a, vector<int> b, vector<X> c) {
    n = _n;
    wedge.resize(n);
    rep(i,n-1) add_wedge(a[i], b[i], c[i]);
  }  

  void add_edge(int from, int to){
    edge[from].push_back(to);
    edge[to].push_back(from); // 無向辺の場合
  }
  
  void add_wedge(int from, int to, X cost){
    wedge[from].push_back( {to, cost} );
    wedge[to].push_back( {from, cost} ); // 無向辺の場合
  }

  X dfs(int v, int par, int s) {
    X res = 0;
    for(auto w:wedge[v]){
      if(w.first == par) continue;
       dfs(w.first, v, s) + w.second;
    }
    return dist[s][v] = res;
  }

  void fill_dist(int s) {
    dist.resize(n);
    dist[s].resize(n);
    dfs(s,-1,s);
    rep(i,n) cout << i << ":" << dist[0][i] << "\n";
  }
  
  
};
int main()
{
  int n;cin >> n;
  vector<int> a(n-1),b(n-1),c(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i] >> c[i];
  }
  Tree<int> tr(n, a, b, c);
  tr.fill_dist(0);
  return 0;
}
