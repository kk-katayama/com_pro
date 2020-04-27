#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<typename X>
class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<pair<int,X>>> edge;// コスト付きの辺
  vector<vector<int>> d;
  const int inf = 1e+9;
  
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){ n = _n; edge.resize(n);      d.resize(n);}
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]のコストc[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b,vector<X> c){
    n = _n;m = _m;edge.resize(n);

    rep(i,m){
      edge[a[i]].push_back({b[i],c[i]});
      edge[b[i]].push_back({a[i],c[i]}); //有向グラフ
    }
  }  

  // 辺の追加 コストあり
  void add_edge(int from,int to,X cost){ edge[from].push_back({to,cost});}

  void dijkstra(int s) { // 頂点sから全頂点への最短距離を求める
    d[s].resize(n, inf);
    d[s][s] = 0;
    priority_queue< pair<X,int>, vector<pair<X,int>>, greater<pair<X,int>> > pq; // 優先キュー {距離,\
 頂点} で距離の小さい順に並ぶ
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

  vector<int> remake(int g) {
    vector<int> res;    
    if(d[n-2][g] == inf) {
      return res;
    }
    int x = d[n-2][g];
    while(x > 0) {
      res.push_back(g);      
      for(auto w : edge[g]) {
	int v = w.first;
	if(d[n-2][v] == x-1) {
	  g = v;
	  x = d[n-2][v];
	  break;
	}
      }
    }
    res.push_back(n-2);
    reverse(res.begin(), res.end());
    return res;
  }
  
};

int main()
{
  string start, goal; cin >> start >> goal;
  int n;cin >> n;
  vector<string> a(n+2);  
  rep(i,n) cin >> a[i];
  a[n] = start;
  a[n+1] = goal;
  Graph<int> gp(n+2);
  rep(i,n+2) {
    rep(j,n+2) {
      if(i >= j) continue;
      int cnt = 0;
      rep(k,a[i].size()) {
	if(a[i][k] != a[j][k]) cnt++;
      }
      if(cnt <= 1) {
	gp.add_edge(i, j, 1);
	gp.add_edge(j, i, 1);	
      }
    }
  }

  gp.dijkstra(n);
  vector<int> res = gp.remake(n+1);
  if(res.size() == 0) {
    cout << -1 << "\n";
    return 0;
  }
  cout << (int)res.size() - 2 << "\n";
  rep(i,res.size()) cout << a[res[i]] << "\n";
  
  
  return 0;
}
