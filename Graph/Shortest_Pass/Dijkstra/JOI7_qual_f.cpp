#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
//include <utility>,<queue>
template <typename X>
class Graph{
private:
  int node;
  int edge_num;
  vector<vector<pair<int,X>>> edge;
  vector<X> d;//distance from start
  
  const X inf = 1e+9;//initial value

public:
  //***************Constractor****************************
  Graph(int n){
    node = n;
    edge.resize(node);
  }

  Graph(int n,int m,vector<int> a,vector<int> b,vector<X> c){
    node = n;
    edge_num = m;
    edge.resize(node);
    rep(i,edge_num){
      edge[a[i]].push_back(make_pair(b[i],c[i]));
      edge[b[i]].push_back(make_pair(a[i],c[i]));//indirection graph
    }
  }
  //***********************************************
  
  void add_edge(int from,int to,X cost){
    edge[from].push_back(make_pair(to,cost));
    edge[to].push_back(make_pair(from,cost));    
  }

  //********************dijkstra********************************  
  void dijkstra(int s){
    priority_queue<pair<X,int>,vector<pair<X,int>>,greater<pair<X,int>>> pq;
    d.assign(node,inf);
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
  //*****************************************************************
  X get_inf(){ return inf;}
  X get_d(int v){ return d[v];  }

  //**************************************************
};


int main()
{
  int n,k;
  cin >> n >> k;
  Graph<int> gp(n);
  vector<int> res;
  rep(i,k){
    int s;cin >> s;
    if(s){
      int a,b,c;cin >> a >> b >> c;a--;b--;
      gp.add_edge(a,b,c);
    }
    else{
      int a,b;cin >> a >> b;a--;b--;
      gp.dijkstra(a);
      int kk = gp.get_d(b);
      if(kk==gp.get_inf()) res.push_back(-1);
      else res.push_back(kk);
    }
  }

  rep(i,res.size()) cout << res[i] << "\n";
  
  return 0;
}
