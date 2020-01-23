#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
// template<typename X>
// struct Graph{
//   int node;
//   int nedge;
//   //  vector<vector<int>> edge;
//   vector<vector<pair<int,X>>> edge;
//   vector<vector<X>> d;
//   // int liq;
//   // vector<vector<int>> edge2;
//   const int inf = 1e+9+10;
  
//   // Graph(int n,int l){
//   //   node = n;
//   //   liq = l;
//   //   edge.resize(node,vector<int>(node,inf));
//   //   edge2.resize(node,vector<int>(node,inf));    
//   // }

//   Graph(int n,int m,vector<int> a,vector<int> b,vector<X> c){
//     node = n;
//     nedge = m;
//     edge.resize(node);
//     rep(i,nedge){
//       edge[a[i]].push_back(make_pair(b[i],c[i]));
//     }
//   }
  
//   // void add(int from,int to,int cost){
//   //   edge[from][to]=cost;
//   // }

//   void wf(){
//     d.resize(node,vector<X>(node,inf));
//     rep(v,node){
//       for(auto w:edge[v]){
// 	d[v][w.first] = w.second;
// 	d[w.first][v] = w.second;	
//       }
//     }
//     rep(k,node){
//       rep(i,node){
//   	rep(j,node){
// 	  d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
// 	}
//       }
//     }
//   }

//   X get_d(int x,int y){
//     return d[x][y];
//   }

//   void show_d(){
//     rep(i,node){
//       rep(j,node){
// 	cout << i << ":" << j << ":" << d[i][j] << "\n";
//       }
//     }
//   }
  
//   // void add2(){
//   //   rep(i,node){
//   //     rep(j,node){
//   // 	if(i==j) continue;
//   // 	if(edge[i][j]<=liq) edge2[i][j]=1;
//   //     }
//   //   }
//   // }
  
//   // void wf2(){
//   //   rep(k,node){
//   //     rep(i,node){
//   // 	rep(j,node){
//   // 	  edge2[i][j]=min(edge2[i][j],edge2[i][k]+edge2[k][j]);
//   // 	}
//   //     }
//   //   }
//   // }

  
  

// };

//include <utility>,<queue>
template <typename X>
struct Graph{
  int node;
  int edge_num;
  vector<vector<pair<int,X>>> edge;
  vector<vector<int>> rev;  
  vector<X> d;//distance from start
  vector<vector<X>> d_wf;//distance from i to j at Warshall-Floyd
  vector<bool> visit;//visited flag
  vector<bool> f;//Can node 's' visit 'g' ?

  const X inf = 1e+9+10;//initial value
  
  //***************Constractor****************************
  Graph(int n){
    node = n;
    edge.resize(node);
    //    rev.resize(node);
  }

  Graph(int n,int m,vector<int> a,vector<int> b,vector<X> c){
    node = n;
    edge.resize(n);
    edge_num = m;
    rep(i,edge_num){
      edge[a[i]].push_back(make_pair(b[i],c[i]));
      edge[b[i]].push_back(make_pair(a[i],c[i]));//indirection graph
    }
  }
  //***********************************************
  
  void add_edge(int from,int to,X cost){
    edge[from].push_back(make_pair(to,cost));
    edge[to].push_back(make_pair(from,cost));//indirection graph    
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
	//	d_wf[w.first][v] = w.second;
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
};




int main()
{
  int n,m,l;
  cin >> n >> m >> l;
  vector<int> a(m),b(m),c(m);
  rep(i,m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }
  int q;
  cin >> q;
  vector<int> s(q),t(q);
  rep(i,q) {
    cin >> s[i] >> t[i];
    s[i]--;
    t[i]--;
  }

  Graph<int> gp(n,m,a,b,c);

  gp.wf();

  Graph<int> gp2(n);
  
  rep(i,n){
    rep(j,n){
      if(i==j) continue;
      if(gp.get_d(i,j)<=l){
  	gp2.add_edge(i,j,1);
      }
    }
  }

  gp2.wf();
  
  rep(i,q){
    int res = gp2.get_d(s[i],t[i]);
    if(res==gp2.inf){
      cout << -1 << "\n";
    }
    else{
      cout << res-1 << "\n";
    }
  }
  
  return 0;
}
