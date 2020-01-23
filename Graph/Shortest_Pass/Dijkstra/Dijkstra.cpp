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
  int node;
  vector<vector<pair<int,X> > > edge;
  vector<X> d;
  const X inf = 1e+9;
  
  Graph(int _n){
    node = _n;
    edge.resize(node);
    d.resize(node);
  }
  
  void add_edge(int from,int to,X cost){
    edge[from].push_back(make_pair(to,cost));
  }

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
	if(d[t] > d[w]+c){
	  d[t] = d[w] + c;
	  q.push(make_pair(d[t],t));
	}
      }
    }
  }
  
};
int main()
{
  
  return 0;
}
