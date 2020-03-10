#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<typename X>
class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  //  vector<vector<pair<int,X>>> edge;// コスト付きの辺
  vector<vector<int>> edge; // コストなしの辺
  vector<bool> f;
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){ n = _n; edge.resize(n);  }
  //辺コストなしのグラフ作成、_n頂点、_m辺、a[i]->b[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b){
    n = _n;m = _m;edge.resize(n);
    rep(i,m){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]); // 有向グラフ
    }
  }
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]のコストc[i]の辺がある。
  // Graph(int _n,int _m,vector<int> a,vector<int> b,vector<X> c){
  //   n = _n;m = _m;edge.resize(n);
  //   rep(i,m){
  //     edge[a[i]].push_back({b[i],c[i]});
  //     edge[b[i]].push_back({a[i],c[i]}); //有向グラフ
  //   }
  // }  

  // 辺の追加 コストなし
  //  void add_edge(int from,int to){ edge[from].push_back(to);}
  // 辺の追加 コストあり
  //  void add_edge(int from,int to,X cost){ edge[from].push_back({to,cost});}

  void dfs(int v){
    if(f[v]) return ;
    f[v] = true;
    for(auto w:edge[v]) dfs(w);
  }

  void solve(){
    int res = 0;
    f.assign(n,0);
    rep(i,n){
      if(!f[i]){
	res++;
	dfs(i);
      }
    }
    cout << res << "\n";
  }
  
};

int main()
{
  int n,m;cin >> n >> m;
  vector<int> x(m),y(m),z(m);
  rep(i,m){ cin >> x[i] >> y[i] >> z[i];x[i]--;y[i]--;}
  Graph<int> gp(n,m,x,y);
  gp.solve();
  
  return 0;
}
