#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
class Graph{
private:
  int node;
  int edge_num;
  vector<vector<pair<int,X>>> edge;
  vector<vector<int>> rev;  
  vector<X> d;//distance from start
  vector<vector<X>> d_wf;//distance from i to j at Warshall-Floyd
  vector<bool> visit;//visited flag
  vector<bool> f;//Can node 's' visit 'g' ?
  vector<pair<int,int>> p;
  vector<int> pp;
  
  vector<int> color;
  vector<vector<int>> edge2;
  
  const X inf = 1e+9;//initial value

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
    p.resize(node,{-inf,inf});
    pp.resize(node);
    color.resize(node,0);
    rep(i,edge_num){
      edge2[a[i]].push_back(b[i]);
      edge2[b[i]].push_back(a[i]);//indirection graph
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
  }

  //********************dijkstra********************************  
  void dijkstra(int s,X inf){
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
  
  //*************************************
  
  pair<int,int> simple_dfs(int v){
    visit[v] = true;
    pair<int,int> res = p[v];
    for(auto w:edge2[v]){
      if(visit[w]){
	continue;
      }
      pair<int,int> tmp = simple_dfs(w);
      res.first = max(res.first,tmp.first-1);
      res.second = min(res.second,tmp.second+1);      
    }
    return p[v] = res;
  }

  void run_dfs(int s){
    visit.assign(node,false);
    simple_dfs(s);
  }

  void check_p(){
    rep(i,node){
      cout << i << ":" << p[i].first << ":" << p[i].second << "\n";
    }
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
    rep(i,node){
      if(color[i]==1){
	if(!nibu(i,1)){
	  return false; 
	}
      }
    }
    return true;
  }

  void set_color(int v,int c){
    color[v] = c;
  }
  
  int get_color(int v){
    return color[v];
  }

  void add_p(int v,int _p){
    p[v] = {_p,_p};
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

  X get_d(int x,int y){
    return d_wf[x][y];
  }  
  //**************************************************

  bool dfs(int v){
    visit[v] = true;
    bool fff = true;
    for(auto w:edge2[v]){
      if(visit[w]) continue;
      if(p[w].first<=pp[v]+1&&pp[v]+1<=p[w].second){
	pp[w] = pp[v]+1;
	//	if(!dfs(w)) return false;	
	fff = fff&dfs(w);
      }
      else if(p[w].first<=pp[v]-1&&pp[v]-1<=p[w].second){
	pp[w] = pp[v]-1;
	//	if(!dfs(w)) return false;
	fff = fff&dfs(w);	
      }
      else{
	return false;
      }
    }
    //    return true;
    return fff;
  }
  
  void solve(int s){
    pp[s] = p[s].first;
    visit.assign(node,false);
    if(dfs(s)){
      cout << "Yes" << "\n";
      rep(i,node){
	cout << pp[i] << "\n";
      }
    }
    else{
      cout << "No" << "\n";
    }
  }
  
};


int main()
{
  int n;
  cin >> n;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i];a[i]--;b[i]--;
  }
  int k;
  cin >> k;
  vector<int> v(k),p(k);
  rep(i,k){
    cin >> v[i] >> p[i];
    v[i]--;
  }
  Graph<int> tr(n,n-1,a,b);
  rep(i,k){
    tr.add_p(v[i],p[i]);
    if(p[i]%2==0){
      tr.set_color(v[i],1);
    }
    else{
      tr.set_color(v[i],-1);
    }
  }


  
  if(tr.solve_nibu()){
    tr.run_dfs(v[0]);
    //    tr.check_p();
    tr.solve(v[0]);
  }
  else{
    cout << "No" << "\n";
  }
  
  return 0;
}
