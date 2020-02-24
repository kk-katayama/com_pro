#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
//include <utility>,<queue>
template <typename X>
class Graph{
private:
  int node;
  int edge_num;
  vector<vector<int>> edge;
  vector<X> d;//distance from start
  
  const X inf = 1LL<<60;//initial value

  vector<X> cost;
  
public:
  //***************Constractor****************************
  Graph(int n){
    node = n;
    edge.resize(node);
  }

  Graph(int n,int m,vector<int> a,vector<int> b){
    node = n;
    edge_num = m;
    edge.resize(node);
    rep(i,edge_num){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);
    }
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
	if(cost[w]==inf) continue;
	if(d[w]>d[v]+cost[w]){
	  d[w] = d[v] + cost[w];
	  pq.push(make_pair(d[w],w));
	}
      }
    }
  }

  void bfs(vector<int> vec,ll s,ll P,ll Q)
  {
    d.assign(node,-1);
    queue<int> q;
    rep(i,vec.size()){
      d[vec[i]] = 0;
      q.push(vec[i]);
    }
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto &w:edge[v]){
	if(d[w]>=0) continue;
	d[w] = d[v] + 1;
	q.push(w);
      }
    }

    cost.resize(node,0);
    rep1(i,node-2){
      if(d[i]==0) cost[i] = inf;
      else if(d[i]<=s) cost[i] = Q;
      else cost[i] = P;
    }
  }

  
  //*****************************************************************
  X get_inf(){ return inf;}
  X get_d(int v){ return d[v];  }

  void check_cost(){
    rep(i,node) cout << i << ":" << cost[i] << "\n";
  }
  //**************************************************
};

int main()
{
  int n,m,k;ll s;cin >> n >> m >> k >> s;
  ll p,q;cin >> p >> q;
  vector<int> c(k);
  rep(i,k){
    cin >> c[i];c[i]--;    
  }
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];a[i]--;b[i]--;
  }

  Graph<ll> gp(n,m,a,b);
  gp.bfs(c,s,p,q);
  gp.dijkstra(0);
  cout << gp.get_d(n-1) << "\n";
  
  return 0;
}
