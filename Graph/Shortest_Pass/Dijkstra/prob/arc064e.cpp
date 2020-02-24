#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const double EPS = 1e-6;
template<typename X>
struct Graph
{
  int node;
  vector<vector<pair<int,X>>> edge;
  vector<X> d;

  Graph(int _node)
  {
    node = _node;
    edge.resize(node);
    d.resize(node);
  }

  void add(int from,int to,X cost)
  {
    edge[from].push_back(make_pair(to,cost));
  }

  void dijkstra(int s,X inf)
  {
    priority_queue<pair<X,int>,vector<pair<X,int>>,greater<pair<X,int>>> pq;
    rep(i,node) d[i] = inf;
    d[s] = 0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
      pair<X,int> p = pq.top();pq.pop();
      int v = p.second;
      if(d[v]<p.first) continue;
      for(auto &w:edge[v]){
	if(d[w.first]>d[v]+w.second){
	  d[w.first] = d[v] + w.second;
	  pq.push(make_pair(d[w.first],w.first));
	}
      }
    }
  }

};

int main()
{
  double xs,ys,xt,yt;
  cin >> xs >> ys >> xt >> yt;
  int n;
  cin >> n;
  vector<double> x(n),y(n),r(n);
  rep(i,n) cin >> x[i] >> y[i] >> r[i];

  Graph<double> gp(n+2);

  rep(i,n) rep(j,n){
    if(i==j) continue;
    gp.add(i,j,max(0.,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j]));
  }
  
  rep(i,n){
    gp.add(n,i,max(0.,sqrt((xs-x[i])*(xs-x[i])+(ys-y[i])*(ys-y[i]))-r[i]));
    gp.add(i,n+1,max(0.,sqrt((xt-x[i])*(xt-x[i])+(yt-y[i])*(yt-y[i]))-r[i]));    
  }

  gp.add(n,n+1,max(0.,sqrt((xs-xt)*(xs-xt)+(ys-yt)*(ys-yt))));

  const double inf = 1e+15;

  gp.dijkstra(n,inf);

  printf("%.10f\n", gp.d[n+1]);


  return 0;
}
