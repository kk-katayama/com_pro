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
  vector<vector<pair<int,X>>> edge;
  vector<vector<pair<int,X>>> rev2;  
  vector<vector<int>> rev;  
  vector<X> d;//distance from start
  vector<X> d_rev;//distance from start  
  vector<vector<X>> d_wf;//distance from i to j at Warshall-Floyd
  vector<bool> visit;//visited flag
  vector<bool> f;//Can node 's' visit 'g' ?

  vector<int> color;
  vector<vector<int>> edge2;
  
  const X inf = 1LL<<60;//initial value

public:
  //***************Constractor****************************
  Graph(int n){
    node = n;
    edge.resize(node);
    //    rev.resize(node);
  }

  Graph(int n,int m,vector<int> a,vector<int> b){
    node = n;
    edge_num = m;
    edge2.resize(node);
    rep(i,edge_num){
      edge2[a[i]].push_back(b[i]);
      edge2[b[i]].push_back(a[i]);//indirection graph
    }
  }

  Graph(int n,int m,vector<int> a,vector<int> b,vector<X> c){
    node = n;
    edge_num = m;
    edge.resize(node);
    rev2.resize(node);
    rep(i,edge_num){
      edge[a[i]].push_back(make_pair(b[i],c[i]));
      //      edge[b[i]].push_back(make_pair(a[i],c[i]));//indirection graph
    }
  }
  //***********************************************
  
  void add_edge(int from,int to,X cost){
    edge[from].push_back(make_pair(to,cost));
  }

  void add_rev2(int from,int to,X cost){
    rev2[to].push_back(make_pair(from,cost));
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


  void dijkstra_rev(int s){
    priority_queue<pair<X,int>,vector<pair<X,int>>,greater<pair<X,int>>> pq;
    d_rev.assign(node,inf);
    d_rev[s] = 0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
      pair<X,int> p = pq.top();pq.pop();
      int v = p.second;
      if(d_rev[v]<p.first) continue;
      for(auto &w:rev2[v]){
	if(d_rev[w.first]>d_rev[v]+w.second){
	  d_rev[w.first] = d_rev[v] + w.second;
	  pq.push(make_pair(d_rev[w.first],w.first));
	}
      }
    }
  }    
  //*****************************************************************

  //**********************bellmanford********************************
  //if graph have negative-loop, return false
  bool bellmanford(int s){
    d.assign(node,inf);
    d[s] = 0;
    bool flag = true;
    rep(i,node){
      rep(v,node){
	if(d[v]==inf) continue;
	for(auto w:edge[v]){
	  if(d[w.first]>d[v] + w.second){
	    d[w.first] = d[v] + w.second;
	    if(i==node-1){
	      //**********need in abc061d and abc137e**************	    
	      //	      if(f[w.first]){
	      //		flag = false;
	      //	      }
	      flag = false;
	    }
	  }
	}
      }
    }
    return flag;
  }

  //*****************************************************************

  //********************Warshall-Floyd******************************
  void wf(){
    d_wf.resize(node,vector<X>(node,inf));
    rep(v,node){
      for(auto w:edge[v]){
	d_wf[v][w.first] = w.second;
	d_wf[w.first][v] = w.second;
      }
    }
    rep(k,node){
      rep(i,node){
	rep(j,node){
	  d_wf[i][j]=min(d_wf[i][j],d_wf[i][k]+d_wf[k][j]);
	}
      }
    }
  }
  
  //**********need in abc061d and abc137e**************	      
  void add_rev(int from,int to){
    rev[from].push_back(to);
  }

  void simple_dfs(int v){
    visit[v] = true;
    f[v] = true;
    for(auto w:rev[v]){
      if(visit[w]){
	continue;
      }
      simple_dfs(w);
    }
  }

  void run_dfs(int g){//check each node can reach goal
    visit.assign(node,false);
    f.assign(node,false);
    f[g] = true;
    simple_dfs(g);
  }


  //****************nibu-graph*****************
  bool nibu(int v,int c){
    color[v] = c;
    for(auto w:edge2[v]){
      if(color[w] == c) return false;
      if(color[w] == 0 && !nibu(w,-c)) return false;
    }
    return true;
  }

  bool solve_nibu(){//if graph is nibu-graph, return true.
    color.assign(node,0);
    rep(i,node){
      if(color[i]==0){
	if(!nibu(i,1)){
	  return false; 
	}
      }
    }
    return true;
  }

  int get_color(int v){
    return color[v];
  }
  
  //*************************************************
  void check_f(){
    rep(i,node){
      cout << i << ":" << f[i] << "\n";
    }
  }

  X get_d(int v){
    return d[v];
  }
  
  X get_rev(int v){
    return d_rev[v];
  }  

  X get_d(int x,int y){
    return d_wf[x][y];
  }  
  //**************************************************
};


int main()
{
  int n,m,t;
  cin >> n >> m >> t;
  vector<ll> A(n);
  rep(i,n){
    cin >> A[i];
  }
  vector<int> a(m),b(m);
  vector<ll> c(m);
  rep(i,m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }
  Graph<ll> gp(n,m,a,b,c);
  rep(i,m){
    gp.add_rev2(a[i],b[i],c[i]);
  }  
  gp.dijkstra(0);
  gp.dijkstra_rev(0);  
  ll res = 0;
  rep(i,n){
    ll dt = t - gp.get_d(i)-gp.get_rev(i);
    if(dt<=0) continue;
    res = max(res,dt*A[i]);
  }
  cout << res << "\n";

  
  return 0;
}
