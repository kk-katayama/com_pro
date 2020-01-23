#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph{
  int node;
  int edge_num;
  vector<vector<pair<int,int>>> edge;
  vector<bool> visited_node;
  vector<bool> visiting_node;
  vector<bool> visited_edge;
  vector<bool> loop;
  vector<int> in;
  vector<int> out;
  int start;
  bool loopflag;

  
  Graph(int node_,int edge_num_){
    node = node_;
    edge_num = edge_num_;
    start = -1;
    loopflag = false;
    edge.resize(node);
    loop.assign(node,false);
  }

  void add_edge(int from,int to,int label){
    edge[from].push_back(make_pair(to,label));
  }

  bool dfs_find_loop(int v){
    bool f = true;
    visiting_node[v] = true;
    for(auto p:edge[v]){
      if(loopflag) continue;
      int w = p.first;
      int l = p.second;
      if(visited_node[w]) continue;
      visited_edge[l] = true;
      if(visiting_node[w]){
	//	cout << w << "\n";
	if(start<0) start = w;
	loopflag = true;
	loop[w] = true;
	f = false;
      }
      f = f&&dfs_find_loop(w);
    }
    if(loopflag){
      loop[v] = true;
    }
    if(v == start) loopflag = false;
    visited_node[v] = true;
    return f;
  }

  bool find_loop(){
    bool f = false;
    rep(i,node){
      if(!visited_node[i]){
	if(!dfs_find_loop(i)){
	  f = true;
	  break;
	}
      }
    }
    // if(f){
    //   visiting_node.assign(node,0);
    //   dfs_find_loop(start);
    // }
    return f;
  }

  void count(){
    in.assign(node,0);
    out.assign(node,0);
    rep(i,node){
      if(loop[i]){
	for(auto p:edge[i]){
	  int w = p.first;
	  if(loop[w]){
	    out[i]++;
	    in[w]++;
	  }
	}
      }
    }
    // rep(i,node){
    //   cout << in[i] << ":";
    //   cout << out[i] << "\n";      
    // }
  }

  void add_find_loop(int from,int to){
    visited_node.assign(node,0);
    visiting_node.assign(node,0);
    visiting_node[from] = true;
    loop.assign(node,0);
    loopflag = false;
    start = from;
    dfs_find_loop(to);
  }

  
  void solve(){
    visited_node.assign(node,0);
    visiting_node.assign(node,0);
    visited_edge.assign(edge_num,0);
    if(find_loop()){
      while(1){
	count();
	// cout << "*******************" << "\n";
	// rep(i,node){
	//   cout << visited_node[i] << ":";
	//   cout << visiting_node[i] << ":";
	//   cout << loop[i] << "\n";
	// }	
	bool f = true;	
	rep(i,node){
	  if(loop[i]){
	    if(in[i]>=2){
	      f = false;
	    }
	    if(out[i]>=2){
	      for(auto p:edge[i]){
		int w = p.first;
		int l = p.second;
		if(visited_edge[l]) continue;
		//		cout << i << "::" << w << "\n";
		visited_edge[l] = true;
		add_find_loop(i,w);
		break;
	      }
	      f = false;
	    }
	  }
	}
	if(f){
	  vector<int> res;
	  int cnt = 0;
	  rep(i,node){
	    if(loop[i]){
	      cnt++;
	      res.push_back(i);
	    }
	  }
	  cout << cnt << "\n";
	  rep(i,res.size()){
	    cout << res[i]+1 << "\n";
	  }
	  break;
	}
      }
    }
    else{
      cout << -1 << "\n";
    }
  }
  
  
  
};
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  Graph gp(n,m);
  rep(i,m){
    gp.add_edge(a[i],b[i],i);
  }

  gp.solve();
  
  return 0;
}
