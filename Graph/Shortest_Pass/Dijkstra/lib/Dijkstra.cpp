#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct Graph{
  int n;
  int m;
  vector<vector<pair<int,X>>> edge;
  vector<X> d;
  const X inf = 1e+9;
  
  Graph(int _n){
    n = _n;
    edge.resize(n);
    d.resize(n);
  }

  Graph(int _n,int _m,vector<int> a,vector<int> b,vector<X> c){
    n = _n;m = _m;edge.resize(n);d.resize(n);
    rep(i,m){
      edge[a[i]].push_back({b[i],c[i]});
      edge[b[i]].push_back({a[i],c[i]});　//無向グラフ
    }
  }
  
  void add_edge(int from,int to,X cost){
    edge[from].push_back(make_pair(to,cost));
  }

  // ダイクストラ法 頂点sから全頂点への最短距離。qは{その頂点までの最短距離,頂点}を入れる。
  void dijkstra(int s){
    priority_queue<pair<X,int>,vector<pair<X,int> >,greater<pair<X,int> > > q;
    rep(i,node) d[i] = inf;
    d[s] = 0;
    q.push(make_pair(0,s));
    while(!q.empty()){
      pair<X,int> p = q.top();
      q.pop();
      int w = p.second;
      if(d[w] < p.first) continue;
      rep(i,edge[w].size()){
	int t = edge[w][i].first;
	X c = edge[w][i].second;
	if(d[t] > d[w]+c){ // 頂点tへはwから向かったものの方が最短である。
	  d[t] = d[w] + c;
	  q.push(make_pair(d[t],t));
	}
          }
  }
  
};
int main()
{
  
  return 0;
}
