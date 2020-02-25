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
  int edge_num2;  
  vector<vector<pair<int,X>>> edge;
  vector<vector<int>> edge2;  
  vector<X> d;//distance from start
  
  const X inf = 1e+9;//initial value

public:
  //***************Constractor****************************
  Graph(int n){
    node = n;
    edge.resize(node);
  }

  Graph(int n,int m,vector<int> a,vector<int> b){
    node = n;
    edge_num2 = m;
    edge.resize(node);    
    edge2.resize(node);
    rep(i,edge_num2){
      edge2[a[i]].push_back(b[i]);
      edge2[b[i]].push_back(a[i]);
    }
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
    //    edge[to].push_back(make_pair(from,cost));    
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

  void bfs(int s)
  {
    queue<int> q;
    d.assign(node,-1);
    d[s] = 0;
    q.push(s);
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto& w:edge2[v]){
	if(d[w]>=0) continue;
	d[w] = d[v] + 1;
	q.push(w);
      }
    }
  }

  void init(vector<int> c,vector<int> r){
    rep(i,node){
      bfs(i);
      rep(j,node){
	if(i==j) continue;
	if(d[j]<=r[i]) add_edge(i,j,c[i]);
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
  int n,k;cin >> n >> k;
  vector<int> c(n),r(n);
  rep(i,n){ cin >> c[i] >> r[i];}
  vector<int> a(k),b(k);
  rep(i,k){ cin >> a[i] >> b[i];a[i]--;b[i]--;}
  Graph<int> gp(n,k,a,b);
  gp.init(c,r);
  gp.dijkstra(0);
  cout << gp.get_d(n-1) << "\n";
  
  return 0;
}
